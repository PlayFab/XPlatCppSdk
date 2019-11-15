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

        bool parsingSuccessful = reader->parse(reqBod, reqBod + reqBodLength, &request, &errs);

        if (parsingSuccessful)
        {
            errorWrapper.Request = request;
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

    bool CallRequestContainer::HandleInvalidSettings()
    {
        bool isValid = true;
        if (m_settings->titleId.empty())
        {
            errorWrapper.HttpCode = 0;
            errorWrapper.HttpStatus = "Client-side validation failure";
            errorWrapper.ErrorCode = PlayFabErrorCode::PlayFabErrorInvalidParams;
            errorWrapper.ErrorName = errorWrapper.HttpStatus;
            errorWrapper.ErrorMessage = "PlayFabSettings::staticSettings->titleId has not been set properly. It must not be empty.";
            isValid = false;
        }

        if (!isValid)
        {
            if (PlayFabSettings::globalErrorHandler != nullptr)
            {
                PlayFabSettings::globalErrorHandler(errorWrapper, GetCustomData());
            }
            if (errorCallback != nullptr)
            {
                errorCallback(errorWrapper, GetCustomData());
            }
        }

        return isValid;
    }
}
