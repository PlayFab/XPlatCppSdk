#pragma once

#ifdef ENABLE_PLAYFABSERVER_API

#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabApiSettings.h>
#include <playfab/PlayFabAuthenticationContext.h>
#include <playfab/PlayFabMatchmakerDataModels.h>
#include <memory>

namespace PlayFab
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Matchmaker APIs
    /// </summary>
    class PlayFabMatchmakerInstanceAPI
    {
    private:
        std::shared_ptr<PlayFabApiSettings> m_settings{ nullptr };
        std::shared_ptr<PlayFabAuthenticationContext> m_authContext{ nullptr };

    public:
        explicit PlayFabMatchmakerInstanceAPI(std::shared_ptr<PlayFabAuthenticationContext> authenticationContext);
        PlayFabMatchmakerInstanceAPI(std::shared_ptr<PlayFabApiSettings> apiSettings, std::shared_ptr<PlayFabAuthenticationContext> authenticationContext);

        ~PlayFabMatchmakerInstanceAPI();
        PlayFabMatchmakerInstanceAPI(const PlayFabMatchmakerInstanceAPI& source) = delete; // disable copy
        PlayFabMatchmakerInstanceAPI(PlayFabMatchmakerInstanceAPI&&) = delete; // disable move
        PlayFabMatchmakerInstanceAPI& operator=(const PlayFabMatchmakerInstanceAPI& source) = delete; // disable assignment
        PlayFabMatchmakerInstanceAPI& operator=(PlayFabMatchmakerInstanceAPI&& other) = delete; // disable move assignment

        std::shared_ptr<PlayFabApiSettings> GetSettings() const;
        void SetSettings(std::shared_ptr<PlayFabApiSettings> apiSettings);
        std::shared_ptr<PlayFabAuthenticationContext> GetAuthenticationContext() const;
        void SetAuthenticationContext(std::shared_ptr<PlayFabAuthenticationContext> authenticationContext);
        size_t Update();
        void ForgetAllCredentials();

        // ------------ Generated API calls
        void AuthUser(MatchmakerModels::AuthUserRequest& request, const ProcessApiCallback<MatchmakerModels::AuthUserResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void PlayerJoined(MatchmakerModels::PlayerJoinedRequest& request, const ProcessApiCallback<MatchmakerModels::PlayerJoinedResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void PlayerLeft(MatchmakerModels::PlayerLeftRequest& request, const ProcessApiCallback<MatchmakerModels::PlayerLeftResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void StartGame(MatchmakerModels::StartGameRequest& request, const ProcessApiCallback<MatchmakerModels::StartGameResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UserInfo(MatchmakerModels::UserInfoRequest& request, const ProcessApiCallback<MatchmakerModels::UserInfoResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);

        // ------------ Generated result handlers
        void OnAuthUserResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnPlayerJoinedResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnPlayerLeftResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnStartGameResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnUserInfoResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        bool ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container);
    private:
        std::shared_ptr<PlayFabAuthenticationContext> GetOrCreateAuthenticationContext();
    };
}

#endif
