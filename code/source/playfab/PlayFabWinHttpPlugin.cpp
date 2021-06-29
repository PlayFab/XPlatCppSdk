#include <stdafx.h>

#if defined(PLAYFAB_PLATFORM_WINDOWS)

#include <playfab/PlayFabWinHttpPlugin.h>
#include <playfab/PlayFabSettings.h>
#include <stdexcept>
#include <vector>
#include <windows.h>

#pragma warning (disable: 4245) // Some DWORD arguments of WinHTTP API can accept -1, according to documentation

namespace PlayFab
{
    PlayFabWinHttpPlugin::PlayFabWinHttpPlugin()
    {
        activeRequestCount = 0;
        threadRunning = true;
        setPredefinedHeadersResult = S_OK;
        workerThread = std::thread(&PlayFabWinHttpPlugin::WorkerThread, this);
    };

    PlayFabWinHttpPlugin::~PlayFabWinHttpPlugin()
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

    void PlayFabWinHttpPlugin::WorkerThread()
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

    void PlayFabWinHttpPlugin::HandleCallback(std::unique_ptr<CallRequestContainer> requestContainer)
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

    void PlayFabWinHttpPlugin::MakePostRequest(std::unique_ptr<CallRequestContainerBase> requestContainer)
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

    void PlayFabWinHttpPlugin::ExecuteRequest(std::unique_ptr<CallRequestContainer> requestContainer)
    {
        CallRequestContainer& reqContainer = *requestContainer;

        // Set up variables
        DWORD dwStatusCode = 0;
        DWORD dwSize = 0;
        DWORD dwDownloaded = 0;
        BOOL bResults = FALSE;
        HINTERNET hSession = NULL, hConnect = NULL, hRequest = NULL;
        constexpr size_t MaxUrlLength = 2048;
        constexpr size_t MaxSchemeLength = 6; // HTTP, HTTPS (plus zero terminator)

        // WinHTTP requires HOST and PATH parts of URL separately, we need to crack it (there is special API to do it)
        const std::string& urlStr = GetUrl(reqContainer);
        std::wstring urlWideStr(urlStr.begin(), urlStr.end());
        const wchar_t* url = urlWideStr.c_str();
        wchar_t urlHost[MaxUrlLength]; // we need to reserve a buffer to store HOST. If it doesn't fit we simply get an error.
        wchar_t urlScheme[MaxSchemeLength]; // we need to reserve a buffer to store SCHEME. If it doesn't fit we simply get an error.
        DWORD winHttpOpenRequestFlags = NULL;

        // please read docs on URL_COMPONENTS and WinHttpCrackUrl to understand these parameters:
        URL_COMPONENTS urlComponents;
        urlComponents.lpszExtraInfo = nullptr;
        urlComponents.dwExtraInfoLength = 0;
        urlComponents.lpszHostName = urlHost;
        urlComponents.dwHostNameLength = MaxUrlLength;
        urlComponents.lpszPassword = nullptr;
        urlComponents.dwPasswordLength = 0;
        urlComponents.lpszScheme = urlScheme;
        urlComponents.dwSchemeLength = MaxSchemeLength;
        urlComponents.lpszUrlPath = nullptr;
        urlComponents.dwUrlPathLength = 1;
        urlComponents.lpszUserName = nullptr;
        urlComponents.dwUserNameLength = 0;
        urlComponents.dwStructSize = sizeof(urlComponents);

        bResults = WinHttpCrackUrl(url, 0, 0, &urlComponents); // parse the URL
        if (!bResults)
        {
            SetErrorInfo(reqContainer, "Error in WinHttpCrackUrl, failed to parse the URL string");
        }
        else
        {
            if (urlComponents.nPort == INTERNET_DEFAULT_HTTPS_PORT)
            {
                winHttpOpenRequestFlags = WINHTTP_FLAG_SECURE;
            }

            // Use WinHttpOpen to obtain a session handle
            hSession = WinHttpOpen(L"PlayFab Agent",
#ifdef PLAYFAB_WIN7
                // WINHTTP_ACCESS_TYPE_DEFAULT_PROXY is deprecated on Windows 8.1 and newer
                WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
#else
                // WINHTTP_ACCESS_TYPE_AUTOMATIC_PROXY is supported in Windows 8.1 and newer
                WINHTTP_ACCESS_TYPE_AUTOMATIC_PROXY,
#endif // PLAYFAB_WIN7
                WINHTTP_NO_PROXY_NAME,
                WINHTTP_NO_PROXY_BYPASS, 0);
            if (!hSession)
            {
                SetErrorInfo(reqContainer, "Error in WinHttpOpen, failed to open an HTTP session");
            }
            else
            {
                // Specify an HTTP server
                hConnect = WinHttpConnect(hSession, urlComponents.lpszHostName, urlComponents.nPort, 0);
                if (!hConnect)
                {
                    SetErrorInfo(reqContainer, "Error in WinHttpConnect, failed to connect to host");
                }
                else
                {
                    // Create an HTTP request handle
                    hRequest = WinHttpOpenRequest(hConnect, L"POST", urlComponents.lpszUrlPath, NULL, WINHTTP_NO_REFERER, NULL, winHttpOpenRequestFlags);
                    if (!hRequest)
                    {
                        SetErrorInfo(reqContainer, "Error in WinHttpOpenRequest, failed to open an HTTP request");
                    }
                    else
                    {
                        // Add HTTP headers
                        SetPredefinedHeaders(reqContainer, hRequest);
                        HRESULT hr = setPredefinedHeadersResult.exchange(S_OK);
                        if(FAILED(hr))
                        {
                            SetErrorInfo(reqContainer, "Error in attempting to add Default Headers with HRESULT: " + std::to_string(hr));
                            CompleteRequest(std::move(requestContainer), hRequest, hConnect, hSession);
                            setPredefinedHeadersResult = S_OK;
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
                                    hr = TryAddHeader(hRequest, std::wstring(header.begin(), header.end()).c_str());
                                    if(FAILED(hr))
                                    {
                                        SetErrorInfo(reqContainer, "Error in WinHttpAddRequestHeaders attempting to add parameters with HRESULT: " + std::to_string(hr));
                                        CompleteRequest(std::move(requestContainer), hRequest, hConnect, hSession);
                                        return;
                                    }
                                }
                            }
                        }

                        // Send a request
                        DWORD payloadSize = 0;
                        LPVOID payload = NULL;
                        std::string requestBody;
                        if (!GetBinaryPayload(reqContainer, payload, payloadSize))
                        {
                            // set string payload if binary wasn't provided
                            requestBody = reqContainer.GetRequestBody();
                            payloadSize = (DWORD)requestBody.size();
                            payload = const_cast<char*>(requestBody.c_str());
                        }

                        bResults = WinHttpSendRequest(hRequest, WINHTTP_NO_ADDITIONAL_HEADERS, 0, payload, payloadSize, payloadSize, 0);
                        if (!bResults)
                        {
                            SetErrorInfo(reqContainer, "Error in WinHttpSendRequest, failed to send an HTTP request");
                        }
                        else
                        {
                            // End the request
                            bResults = WinHttpReceiveResponse(hRequest, NULL);
                            if (!bResults)
                            {
                                SetErrorInfo(reqContainer, "Error in WinHttpReceiveResponse, failed to receive an HTTP response");
                            }
                            else
                            {
                                // Get HTTP response code
                                dwSize = sizeof(dwStatusCode);
                                bResults = WinHttpQueryHeaders(hRequest,
                                    WINHTTP_QUERY_STATUS_CODE | WINHTTP_QUERY_FLAG_NUMBER,
                                    WINHTTP_HEADER_NAME_BY_INDEX,
                                    &dwStatusCode, &dwSize, WINHTTP_NO_HEADER_INDEX);
                                if (!bResults)
                                {
                                    SetErrorInfo(reqContainer, "Error in WinHttpQueryHeaders, failed to read HTTP response code");
                                }
                                else
                                {
                                    // Keep checking for data until there is nothing left
                                    do
                                    {
                                        // Check for available data block
                                        dwSize = 0;
                                        if (!WinHttpQueryDataAvailable(hRequest, &dwSize))
                                        {
                                            SetErrorInfo(reqContainer, "Error in WinHttpQueryDataAvailable, failed to check for an available data block in HTTP response");
                                            bResults = FALSE;
                                            break;
                                        }

                                        // Allocate space for the buffer
                                        auto outBuffer = std::unique_ptr<char[]>(new char[dwSize + 1]);
                                        if (!outBuffer)
                                        {
                                            SetErrorInfo(reqContainer, "Out of memory, failed to allocate a buffer to read a data block in HTTP response");
                                            bResults = FALSE;
                                            break;
                                        }
                                        else
                                        {
                                            // Read the data block
                                            ZeroMemory(outBuffer.get(), dwSize + 1);
                                            if (!WinHttpReadData(hRequest, (LPVOID)outBuffer.get(), dwSize, &dwDownloaded))
                                            {
                                                SetErrorInfo(reqContainer, "Error in WinHttpReadData, failed to read a data block in HTTP response");
                                                bResults = FALSE;
                                                break;
                                            }
                                            else
                                            {
                                                // successfully received a block of data
                                                reqContainer.responseString.append(outBuffer.get());
                                            }

                                            // Free the memory allocated to the buffer
                                            outBuffer = nullptr;
                                        }

                                    } while (dwSize > 0);

                                    std::string requestId;
                                    if (bResults)
                                    {
                                        constexpr wchar_t requestIdHeaderName[] = L"X-RequestId";

                                        DWORD wideRequestIdByteCount;
                                        bResults = WinHttpQueryHeaders(
                                            hRequest,
                                            WINHTTP_QUERY_CUSTOM,
                                            requestIdHeaderName,
                                            WINHTTP_NO_OUTPUT_BUFFER,
                                            &wideRequestIdByteCount,
                                            WINHTTP_NO_HEADER_INDEX);

                                        std::unique_ptr<wchar_t[]> wideRequestIdBuffer;
                                        DWORD queryError = GetLastError();
                                        if (queryError == ERROR_INSUFFICIENT_BUFFER)
                                        {
                                            // WinHttpQueryHeaders excludes the null terminator from the length
                                            DWORD wideRequestIdLength = wideRequestIdByteCount / sizeof(wideRequestIdBuffer[0]);
                                            wideRequestIdBuffer = std::make_unique<wchar_t[]>(wideRequestIdLength + 1);
                                            bResults = WinHttpQueryHeaders(
                                                hRequest,
                                                WINHTTP_QUERY_CUSTOM,
                                                requestIdHeaderName,
                                                wideRequestIdBuffer.get(),
                                                &wideRequestIdByteCount,
                                                WINHTTP_NO_HEADER_INDEX);
                                            if (bResults)
                                            {
                                                requestId = std::string(wideRequestIdBuffer.get(), wideRequestIdBuffer.get() + wideRequestIdLength - 1);
                                            }
                                            else
                                            {
                                                SetErrorInfo(
                                                    reqContainer,
                                                    "Error querying for X-RequestId response header: " + std::to_string(GetLastError()));
                                            }
                                        }
                                        else
                                        {
                                            SetErrorInfo(
                                                reqContainer,
                                                "Error querying for X-RequestId response header size: " + std::to_string(queryError));
                                        }
                                    }

                                    if (bResults)
                                    {
                                        ProcessResponse(reqContainer, dwStatusCode, std::move(requestId));
                                    }
                                } // WinHttpQueryHeaders
                            } // WinHttpReceiveResponse
                        } // WinHttpSendRequest
                    } // WinHttpOpenRequest
                } // WinHttpConnect
            } // WinHttpOpen
        } // WinHttpCrackUrl

        CompleteRequest(std::move(requestContainer), hRequest, hConnect, hSession);
    }

    std::string PlayFabWinHttpPlugin::GetUrl(const CallRequestContainer& reqContainer) const
    {
        return reqContainer.GetFullUrl();
    }

    void PlayFabWinHttpPlugin::SetPredefinedHeaders(const CallRequestContainer& requestContainer, HINTERNET hRequest)
    {
        UNREFERENCED_PARAMETER(requestContainer);

        HRESULT hr = S_OK;

        hr = TryAddHeader(hRequest, L"Accept: application/json");
        if (SUCCEEDED(hr))
        {
            hr = TryAddHeader(hRequest, L"Content-Type: application/json; charset=utf-8");
            if (SUCCEEDED(hr))
            {
                std::string versionHeader = "X-PlayFabSDK: " + PlayFabSettings::versionString;
                std::wstring versionWideHeader(versionHeader.begin(), versionHeader.end());
                hr = TryAddHeader(hRequest, versionWideHeader.c_str());
                if (SUCCEEDED(hr))
                {
                    hr = TryAddHeader(hRequest, L"X-ReportErrorAsSuccess: true");
                }
            }
        }

        setPredefinedHeadersResult = hr;
    }

    HRESULT PlayFabWinHttpPlugin::TryAddHeader(HINTERNET hRequest, LPCWSTR lpszHeaders)
    {
        bool succeeded = WinHttpAddRequestHeaders(hRequest, lpszHeaders, -1, 0);
        if (!succeeded)
        {
            return HRESULT_FROM_WIN32(GetLastError());
        }
        return S_OK;
    }

    bool PlayFabWinHttpPlugin::GetBinaryPayload(CallRequestContainer& reqContainer, LPVOID& payload, DWORD& payloadSize) const
    {
        UNREFERENCED_PARAMETER(reqContainer);
        UNREFERENCED_PARAMETER(payload);
        UNREFERENCED_PARAMETER(payloadSize);
        return false;
    }

    void PlayFabWinHttpPlugin::ProcessResponse(CallRequestContainer& reqContainer, const int httpCode, std::string&& requestId)
    {
        Json::CharReaderBuilder jsonReaderFactory;
        std::unique_ptr<Json::CharReader> jsonReader(jsonReaderFactory.newCharReader());
        JSONCPP_STRING jsonParseErrors;
        const bool parsedSuccessfully = jsonReader->parse(reqContainer.responseString.c_str(), reqContainer.responseString.c_str() + reqContainer.responseString.length(), &reqContainer.responseJson, &jsonParseErrors);

        if (parsedSuccessfully)
        {
            // fully successful response
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
            reqContainer.errorWrapper.HttpCode = httpCode;
            reqContainer.errorWrapper.HttpStatus = reqContainer.responseString;
            reqContainer.errorWrapper.ErrorCode = PlayFabErrorCode::PlayFabErrorPartialFailure;
            reqContainer.errorWrapper.ErrorName = "Failed to parse PlayFab response";
            reqContainer.errorWrapper.ErrorMessage = jsonParseErrors;
        }

        reqContainer.errorWrapper.RequestId = std::move(requestId);
    }

    void PlayFabWinHttpPlugin::SetErrorInfo(CallRequestContainer& requestContainer, const std::string& errorMessage, const int httpCode) const
    {
        requestContainer.errorWrapper.HttpCode = httpCode;
        requestContainer.errorWrapper.HttpStatus = errorMessage;
        requestContainer.errorWrapper.ErrorCode = PlayFabErrorCode::PlayFabErrorUnknownError;
        requestContainer.errorWrapper.ErrorName = errorMessage;
        requestContainer.errorWrapper.ErrorMessage = "Error: " + std::to_string(GetLastError());
    }

    void PlayFabWinHttpPlugin::HandleResults(std::unique_ptr<CallRequestContainer> requestContainer)
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

    size_t PlayFabWinHttpPlugin::Update()
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

    void PlayFabWinHttpPlugin::CompleteRequest(std::unique_ptr<CallRequestContainer> requestContainer, HINTERNET hRequest, HINTERNET hConnect, HINTERNET hSession)
    {
        HandleCallback(std::move(requestContainer));

        // Close any open handles
        if (hRequest)
        {
            WinHttpCloseHandle(hRequest);
        }

        if (hConnect)
        {
            WinHttpCloseHandle(hConnect);
        }

        if (hSession)
        {
            WinHttpCloseHandle(hSession);
        }
    }
}

#endif // defined(PLAYFAB_PLATFORM_WINDOWS)
