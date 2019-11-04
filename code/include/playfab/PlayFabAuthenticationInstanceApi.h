#pragma once

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabApiSettings.h>
#include <playfab/PlayFabAuthenticationContext.h>
#include <playfab/PlayFabAuthenticationDataModels.h>
#include <memory>

namespace PlayFab
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Authentication APIs
    /// </summary>
    class PlayFabAuthenticationInstanceAPI
    {
    private:
        std::shared_ptr<PlayFabApiSettings> settings{ nullptr };
        std::shared_ptr<PlayFabAuthenticationContext> authContext{ nullptr };

    public:
        PlayFabAuthenticationInstanceAPI();
        explicit PlayFabAuthenticationInstanceAPI(std::shared_ptr<PlayFabApiSettings> apiSettings);
        explicit PlayFabAuthenticationInstanceAPI(std::shared_ptr<PlayFabAuthenticationContext> authenticationContext);
        PlayFabAuthenticationInstanceAPI(std::shared_ptr<PlayFabApiSettings> apiSettings, std::shared_ptr<PlayFabAuthenticationContext> authenticationContext);

        ~PlayFabAuthenticationInstanceAPI();
        PlayFabAuthenticationInstanceAPI(const PlayFabAuthenticationInstanceAPI& source) = delete; // disable copy
        PlayFabAuthenticationInstanceAPI(PlayFabAuthenticationInstanceAPI&&) = delete; // disable move
        PlayFabAuthenticationInstanceAPI& operator=(const PlayFabAuthenticationInstanceAPI& source) = delete; // disable assignment
        PlayFabAuthenticationInstanceAPI& operator=(PlayFabAuthenticationInstanceAPI&& other) = delete; // disable move assignment

        std::shared_ptr<PlayFabApiSettings> GetSettings() const;
        void SetSettings(std::shared_ptr<PlayFabApiSettings> apiSettings);
        std::shared_ptr<PlayFabAuthenticationContext> GetAuthenticationContext() const;
        void SetAuthenticationContext(std::shared_ptr<PlayFabAuthenticationContext> authenticationContext);
        size_t Update();
        void ForgetAllCredentials();

        // ------------ Generated API calls
        void GetEntityToken(AuthenticationModels::GetEntityTokenRequest& request, const ProcessApiCallback<AuthenticationModels::GetEntityTokenResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ValidateEntityToken(AuthenticationModels::ValidateEntityTokenRequest& request, const ProcessApiCallback<AuthenticationModels::ValidateEntityTokenResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);

        // ------------ Generated result handlers
        void OnGetEntityTokenResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnValidateEntityTokenResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        bool ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container);
    private:
        std::shared_ptr<PlayFabAuthenticationContext> GetOrCreateAuthenticationContext();
    };
}

#endif
