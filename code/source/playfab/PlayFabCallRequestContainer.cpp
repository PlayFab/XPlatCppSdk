#include <stdafx.h>

#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabSettings.h>

namespace PlayFab
{
    CallRequestContainer::CallRequestContainer(const std::string& url,
        const std::unordered_map<std::string, std::string>& headers,
        const std::string& requestBody,
        CallRequestContainerCallback callback,
        void* customData,
        std::shared_ptr<PlayFabApiSettings> settings,
        std::shared_ptr<PlayFabAuthenticationContext> context) :
        CallRequestContainerBase(url, headers, requestBody, callback, customData, settings, context),
        finished(false),
        responseString(""),
        responseJson(Json::Value::null),
        errorWrapper(),
        successCallback(nullptr),
        errorCallback(nullptr)
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
        if (m_settings == nullptr)
        {
            return PlayFabSettings::GetUrl(this->GetUrl(), PlayFabSettings::staticSettings->requestGetParams);
        }
        else
        {
            return m_settings->GetUrl(this->GetUrl(), PlayFabSettings::staticSettings->requestGetParams);
        }
    }
}
