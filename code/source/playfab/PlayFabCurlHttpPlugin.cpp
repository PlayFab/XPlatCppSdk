#include <stdafx.h>

#include <playfab/PlayFabCurlHttpPlugin.h>
#include <playfab/PlayFabSettings.h>

#include <stdexcept>

#ifndef _countof
template <typename _CountofType, size_t _SizeOfArray>
char(*__countof_helper(_CountofType(&_Array)[_SizeOfArray]))[_SizeOfArray];

#define _countof(_Array) (sizeof(*__countof_helper(_Array)) + 0)
#endif

#define strncasecmp(x,y,z) _strnicmp(x,y,z)

namespace PlayFab
{
    PlayFabCurlHttpPlugin::PlayFabCurlHttpPlugin()
    {
        activeRequestCount = 0;
        threadRunning = true;
        workerThread = std::thread(&PlayFabCurlHttpPlugin::WorkerThread, this);
        
#if defined(PLAYFAB_PLATFORM_GDK)
        // BUG: This will not be required after the next GDK update 
        // (curl_easy_perform or easy_init should call this global function with appropriate flags upon the first time called)
        curl_global_init(CURL_GLOBAL_DEFAULT);
#endif
    };

    PlayFabCurlHttpPlugin::~PlayFabCurlHttpPlugin()
    {
        threadRunning = false;
        try
        {
            workerThread.join();
        }
        catch (...)
        {
        }
    }

    void PlayFabCurlHttpPlugin::WorkerThread()
    {
        size_t queueSize;

        while (this->threadRunning)
        {
            try
            {
                std::unique_ptr<CallRequestContainerBase> requestContainer = nullptr;

                { // LOCK httpRequestMutex
                    std::unique_lock<std::mutex> lock(this->httpRequestMutex);

                    queueSize = this->pendingRequests.size();
                    if (queueSize != 0)
                    {
                        requestContainer = std::move(this->pendingRequests[0]);
                        this->pendingRequests.pop_front();
                    }
                } // UNLOCK httpRequestMutex

                if (queueSize == 0)
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(10));
                    continue;
                }

                if (requestContainer != nullptr)
                {
                    CallRequestContainer* requestContainerPtr = dynamic_cast<CallRequestContainer*>(requestContainer.get());
                    if (requestContainerPtr != nullptr)
                    {
                        requestContainer.release();
                        ExecuteRequest(std::unique_ptr<CallRequestContainer>(requestContainerPtr));
                    }
                }
            }
            catch (const std::exception& ex)
            {
                PlayFabPluginManager::GetInstance().HandleException(ex);
            }
            catch (...)
            {

            }
        }
    }

    void PlayFabCurlHttpPlugin::HandleCallback(std::unique_ptr<CallRequestContainer> requestContainer)
    {
        CallRequestContainer& reqContainer = *requestContainer;
        reqContainer.finished = true;
        if (PlayFabSettings::threadedCallbacks)
        {
            HandleResults(std::move(requestContainer));
        }

        if (!PlayFabSettings::threadedCallbacks)
        {
            { // LOCK httpRequestMutex
                std::unique_lock<std::mutex> lock(httpRequestMutex);
                pendingResults.push_back(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(requestContainer.release())));
            } // UNLOCK httpRequestMutex
        }
    }

    size_t PlayFabCurlHttpPlugin::CurlReceiveData(char* buffer, size_t blockSize, size_t blockCount, void* userData)
    {
        CallRequestContainer* reqContainer = reinterpret_cast<CallRequestContainer*>(userData);
        reqContainer->responseString.append(buffer, blockSize * blockCount);

        return (blockSize * blockCount);
    }

    void PlayFabCurlHttpPlugin::MakePostRequest(std::unique_ptr<CallRequestContainerBase> requestContainer)
    {
        CallRequestContainer* container = dynamic_cast<CallRequestContainer*>(requestContainer.get());
        if (container != nullptr)
        {
            container->ThrowIfSettingsInvalid();
             // LOCK httpRequestMutex
            std::unique_lock<std::mutex> lock(httpRequestMutex);
            pendingRequests.push_back(std::move(requestContainer));
            activeRequestCount++;
        } // UNLOCK httpRequestMutex
    }

    constexpr char requestIdHeaderKey[] = "X-RequestId:";
    constexpr size_t requestIdheaderKeyLen = _countof(requestIdHeaderKey) - 1;
    constexpr char whitespace[] = "\t\n\v\f\r ";

    size_t HeaderCallback(char* buffer, size_t size, size_t nitems, void* userdata)
    {
        CallRequestContainer& reqContainer = *static_cast<CallRequestContainer*>(userdata);
        if (!reqContainer.errorWrapper.RequestId.empty())
        {
            // For now, we only care about the RequestId header
            return nitems * size; // The return expected by curl for this callback
        }

        // If this header-line is long enough, and the header starts with the key we expect
        if ((nitems > requestIdheaderKeyLen) && (strncasecmp(buffer, requestIdHeaderKey, requestIdheaderKeyLen) == 0))
        {
            // The value is the requestId
            std::string requestId = std::string(buffer + requestIdheaderKeyLen, nitems - requestIdheaderKeyLen);
            size_t offset = requestId.find_first_not_of(whitespace);
            if (offset != std::string::npos)
            {
                // Trim any whitespace
                requestId.erase(requestId.find_last_not_of(whitespace) + 1);
                requestId.erase(0, offset);
                // Save it
                reqContainer.SetRequestId(requestId);
                reqContainer.errorWrapper.RequestId = requestId;
            }
        }
        return nitems * size; // The return expected by curl for this callback
    }

    void PlayFabCurlHttpPlugin::ExecuteRequest(std::unique_ptr<CallRequestContainer> requestContainer)
    {
        CallRequestContainer& reqContainer = *requestContainer;

        // Set up curl handle
        CURL* curlHandle = curl_easy_init();
        curl_easy_reset(curlHandle);
        curl_easy_setopt(curlHandle, CURLOPT_NOSIGNAL, true);
        std::string urlString = reqContainer.GetFullUrl();
        curl_easy_setopt(curlHandle, CURLOPT_URL, urlString.c_str());

        // Set up headers
        curl_slist* curlHttpHeaders = SetPredefinedHeaders(reqContainer);

        if(curlHttpHeaders == NULL)
        {
            HandleCallback(std::move(requestContainer));
            return;
        }

        const std::unordered_map<std::string, std::string> headers = reqContainer.GetRequestHeaders();

        if (headers.size() > 0)
        {
            for (auto const& obj : headers)
            {
                if (obj.first.length() != 0 && obj.second.length() != 0) // no empty keys or values in headers
                {
                    std::string header = obj.first + ": " + obj.second;

                    curlHttpHeaders = TryCurlAddHeader(reqContainer, curlHttpHeaders, header.c_str());
                    if (curlHttpHeaders == NULL)
                    {
                        HandleCallback(std::move(requestContainer));
                        return;
                    }
                }
            }
        }

        curl_easy_setopt(curlHandle, CURLOPT_HTTPHEADER, curlHttpHeaders);

        // Set up post & payload
        std::string payload = reqContainer.GetRequestBody();
        curl_easy_setopt(curlHandle, CURLOPT_POST, nullptr);
        curl_easy_setopt(curlHandle, CURLOPT_POSTFIELDS, payload.c_str());

        // Process result
        // TODO: CURLOPT_ERRORBUFFER ?
        curl_easy_setopt(curlHandle, CURLOPT_TIMEOUT_MS, 10000L);
        curl_easy_setopt(curlHandle, CURLOPT_WRITEDATA, &reqContainer);
        curl_easy_setopt(curlHandle, CURLOPT_WRITEFUNCTION, CurlReceiveData);

        curl_easy_setopt(curlHandle, CURLOPT_HEADERDATA, &reqContainer);
        curl_easy_setopt(curlHandle, CURLOPT_HEADERFUNCTION, HeaderCallback);

        // Send
        curl_easy_setopt(curlHandle, CURLOPT_SSL_VERIFYPEER, true);
        CURLcode res = curl_easy_perform(curlHandle);
        long curlHttpResponseCode = 0;
        curl_easy_getinfo(curlHandle, CURLINFO_RESPONSE_CODE, &curlHttpResponseCode);

        reqContainer.errorWrapper.RequestId = reqContainer.GetRequestId();

        if (res != CURLE_OK)
        {
            reqContainer.errorWrapper.HttpCode = curlHttpResponseCode != 0 ? curlHttpResponseCode : 408;
            reqContainer.errorWrapper.HttpStatus = "Failed to contact server";
            reqContainer.errorWrapper.ErrorCode = PlayFabErrorCode::PlayFabErrorConnectionTimeout;
            reqContainer.errorWrapper.ErrorName = "Failed to contact server";
            reqContainer.errorWrapper.ErrorMessage = "Failed to contact server, curl error: " + std::to_string(res);
        }
        else
        {
            Json::CharReaderBuilder jsonReaderFactory;
            std::unique_ptr<Json::CharReader> jsonReader(jsonReaderFactory.newCharReader());
            JSONCPP_STRING jsonParseErrors;
            const bool parsedSuccessfully = jsonReader->parse(reqContainer.responseString.c_str(), reqContainer.responseString.c_str() + reqContainer.responseString.length(), &reqContainer.responseJson, &jsonParseErrors);

            if (parsedSuccessfully)
            {
                reqContainer.errorWrapper.HttpCode = reqContainer.responseJson.get("code", Json::Value::null).asInt();
                reqContainer.errorWrapper.HttpStatus = reqContainer.responseJson.get("status", Json::Value::null).asString();
                reqContainer.errorWrapper.Data = reqContainer.responseJson.get("data", Json::Value::null);
                reqContainer.errorWrapper.ErrorName = reqContainer.responseJson.get("error", Json::Value::null).asString();
                reqContainer.errorWrapper.ErrorCode = static_cast<PlayFabErrorCode>(reqContainer.responseJson.get("errorCode", Json::Value::null).asInt());
                reqContainer.errorWrapper.ErrorMessage = reqContainer.responseJson.get("errorMessage", Json::Value::null).asString();
                reqContainer.errorWrapper.ErrorDetails = reqContainer.responseJson.get("errorDetails", Json::Value::null);
                reqContainer.errorWrapper.RetryAfterSeconds = reqContainer.responseJson.get("retryAfterSeconds", Json::Value::null);
            }
            else
            {
                reqContainer.errorWrapper.HttpCode = curlHttpResponseCode != 0 ? curlHttpResponseCode : 408;
                reqContainer.errorWrapper.HttpStatus = reqContainer.responseString;
                reqContainer.errorWrapper.ErrorCode = PlayFabErrorCode::PlayFabErrorConnectionTimeout;
                reqContainer.errorWrapper.ErrorName = "Failed to parse PlayFab response";
                reqContainer.errorWrapper.ErrorMessage = jsonParseErrors;
            }
        }

        HandleCallback(std::move(requestContainer));

        curl_slist_free_all(curlHttpHeaders);
        curlHttpHeaders = nullptr;
        curl_easy_cleanup(curlHandle);
    }

    void PlayFabCurlHttpPlugin::HandleResults(std::unique_ptr<CallRequestContainer> requestContainer)
    {
        CallRequestContainer& reqContainer = *requestContainer;
        CallRequestContainerCallback callback = reqContainer.GetCallback();
        if (callback != nullptr)
        {
            callback(
                reqContainer.responseJson.get("code", Json::Value::null).asInt(),
                reqContainer.responseString,
                std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(requestContainer.release())));
        }
    }

    size_t PlayFabCurlHttpPlugin::Update()
    {
        if (PlayFabSettings::threadedCallbacks)
        {
            throw PlayFabException(PlayFabExceptionCode::ThreadMisuse, "You should not call Update() when PlayFabSettings::threadedCallbacks == true");
        }

        std::unique_ptr<CallRequestContainerBase> requestContainer = nullptr;
        { // LOCK httpRequestMutex
            std::unique_lock<std::mutex> lock(httpRequestMutex);
            if (pendingResults.empty())
            {
                return activeRequestCount;
            }

            requestContainer = std::move(this->pendingResults[0]);
            this->pendingResults.pop_front();
            activeRequestCount--;
        } // UNLOCK httpRequestMutex

        HandleResults(std::unique_ptr<CallRequestContainer>(static_cast<CallRequestContainer*>(requestContainer.release())));

        // activeRequestCount can be altered by HandleResults, so we have to re-lock and return an updated value
        { // LOCK httpRequestMutex
            std::unique_lock<std::mutex> lock(httpRequestMutex);
            return activeRequestCount;
        }
    }

    curl_slist* PlayFabCurlHttpPlugin::SetPredefinedHeaders(CallRequestContainer& reqContainer)
    {
        curl_slist* curlHttpHeaders = nullptr;

        curlHttpHeaders = TryCurlAddHeader(reqContainer, curlHttpHeaders, "Accept: application/json");
        curlHttpHeaders = TryCurlAddHeader(reqContainer, curlHttpHeaders, "Content-Type: application/json; charset=utf-8");
        curlHttpHeaders = TryCurlAddHeader(reqContainer, curlHttpHeaders, ("X-PlayFabSDK: " + PlayFabSettings::versionString).c_str());
        curlHttpHeaders = TryCurlAddHeader(reqContainer, curlHttpHeaders, "X-ReportErrorAsSuccess: true");

        return curlHttpHeaders;
    }

    void PlayFabCurlHttpPlugin::CurlHeaderFailed(CallRequestContainer& requestContainer, const char* failedHeader)
    {
        std::string message = "Request failed initializing the header before sending the request. Failing out early. The Problematic Header: ";
        requestContainer.errorWrapper.HttpStatus = "Failed to create Headers list";
        requestContainer.errorWrapper.ErrorCode = PlayFabErrorCode::PlayFabErrorUnkownError;
        requestContainer.errorWrapper.ErrorName = "Header Creation Failed";
        requestContainer.errorWrapper.ErrorMessage = message + failedHeader;
    }

    curl_slist* PlayFabCurlHttpPlugin::TryCurlAddHeader(CallRequestContainer& requestContainer, curl_slist* list, const char* headerToAppend)
    {
        list = curl_slist_append(list, headerToAppend);
        if(list == NULL)
        {
            CurlHeaderFailed(requestContainer, headerToAppend);
        }
        return list;
    }
}
