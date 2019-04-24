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
        std::shared_ptr<PlayFabApiSettings> settings;
        std::shared_ptr<PlayFabAuthenticationContext> authContext;

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
        void ActivateKey(AuthenticationModels::ActivateAPIKeyRequest& request, ProcessApiCallback<AuthenticationModels::ActivateAPIKeyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateKey(AuthenticationModels::CreateAPIKeyRequest& request, ProcessApiCallback<AuthenticationModels::CreateAPIKeyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeactivateKey(AuthenticationModels::DeactivateAPIKeyRequest& request, ProcessApiCallback<AuthenticationModels::DeactivateAPIKeyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteKey(AuthenticationModels::DeleteAPIKeyRequest& request, ProcessApiCallback<AuthenticationModels::DeleteAPIKeyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetEntityToken(AuthenticationModels::GetEntityTokenRequest& request, ProcessApiCallback<AuthenticationModels::GetEntityTokenResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetKeys(AuthenticationModels::GetAPIKeysRequest& request, ProcessApiCallback<AuthenticationModels::GetAPIKeysResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

        // ------------ Generated result handlers
        void OnActivateKeyResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnCreateKeyResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnDeactivateKeyResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnDeleteKeyResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetEntityTokenResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetKeysResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        bool ValidateResult(PlayFabResultCommon& resultCommon, CallRequestContainer& container);
    private:
        std::shared_ptr<PlayFabAuthenticationContext> GetOrCreateAuthenticationContext();
    };
}

#endif
