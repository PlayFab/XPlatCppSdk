#include <stdafx.h>

    #include <playfab/PlayFabCallRequestContainer.h>
    #include <playfab/PlayFabSettings.h>
    
    namespace PlayFab
    {
        CallRequestContainer::CallRequestContainer(const std::string& url,
            const std::unordered_map<std::string, std::string>& headers,
            const std::string& requestBody,
            CallRequestContainerCallback callback,
            std::shared_ptr<PlayFabApiSettings> settings,
            std::shared_ptr<PlayFabAuthenticationContext> context,
            void* customData) :
            CallRequestContainerBase(url, headers, requestBody, callback, customData),
            finished(false),
            responseString(""),
            responseJson(Json::Value::null),
            errorWrapper(),
            successCallback(nullptr),
            errorCallback(nullptr),
            m_settings(settings),
            m_context(context)
        {
            errorWrapper.UrlPath = url;
    
            Json::Value request;
            std::string errs;
            Json::CharReaderBuilder builder;
            std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
    
            const char* reqBod = requestBody.c_str();
            size_t reqBodLength = requestBody.length();
    
            try {
                bool parsingSuccessful = reader->parse(reqBod, reqBod + reqBodLength, &request, &errs);
                if (parsingSuccessful)
                {
                    errorWrapper.Request = request;
                }
            }
            catch (const std::exception&)
            {
                // We can't parse the request back into a JSON::Value, so the caller won't receive it back...?
            }
        }
    
        CallRequestContainer::~CallRequestContainer()
        {
        }
    
        std::string CallRequestContainer::GetFullUrl() const
        {
            return m_settings->GetUrl(this->GetUrl());
        }
    
        std::shared_ptr<PlayFabApiSettings> CallRequestContainer::GetApiSettings() const
        {
            return this->m_settings;
        }
    
        std::shared_ptr<PlayFabAuthenticationContext> CallRequestContainer::GetContext() const
        {
            return this->m_context;
        }
    
        std::string CallRequestContainer::GetRequestId() const
        {
            return this->requestId;
        }
    
        void CallRequestContainer::SetRequestId(const std::string& newRequestId)
        {
            this->requestId = newRequestId;
            this->errorWrapper.RequestId = newRequestId;
        }
    
        void CallRequestContainer::ThrowIfSettingsInvalid()
        {
            if (m_settings->titleId.empty())
            {
                throw new PlayFabException(PlayFabExceptionCode::TitleNotSet, "PlayFabSettings::staticSettings->titleId has not been set properly. It must not be empty.");
            }
        }
    }
    