#pragma once

#include <playfab/PlayFabError.h>
#include <playfab/PlayFabCallRequestContainerBase.h>

namespace PlayFab
{
    /// <summary>
    /// Internal PlayFabHttp container for each API call
    /// </summary>
    class CallRequestContainer : public CallRequestContainerBase
    {
    public:
        CallRequestContainer(const std::string& url,
            const std::unordered_map<std::string, std::string>& headers,
            const std::string& requestBody,
            CallRequestContainerCallback callback,
            std::shared_ptr<PlayFabApiSettings> apiSettings,
            std::shared_ptr<PlayFabAuthenticationContext> context,
            void* customData);

        virtual ~CallRequestContainer() override;
        std::string GetFullUrl() const;
        virtual bool ValidateSettings() override;

        // TODO: clean up these public variables with setters/getters when you have the chance.

        bool finished;
        std::string responseString;
        Json::Value responseJson = Json::Value::null;
        PlayFabError errorWrapper;
        std::shared_ptr<void> successCallback;
        ErrorCallback errorCallback;
    };
}
