#pragma once

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabApiSettings.h>
#include <playfab/PlayFabAuthenticationContext.h>
#include <playfab/PlayFabProfilesDataModels.h>
#include <memory>

namespace PlayFab
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Profiles APIs
    /// </summary>
    class PlayFabProfilesInstanceAPI
    {
    private:
        std::shared_ptr<PlayFabApiSettings> m_settings{ nullptr };
        std::shared_ptr<PlayFabAuthenticationContext> m_context{ nullptr };

    public:
        explicit PlayFabProfilesInstanceAPI(std::shared_ptr<PlayFabAuthenticationContext> authenticationContext);
        PlayFabProfilesInstanceAPI(std::shared_ptr<PlayFabApiSettings> apiSettings, std::shared_ptr<PlayFabAuthenticationContext> authenticationContext);

        ~PlayFabProfilesInstanceAPI();
        PlayFabProfilesInstanceAPI(const PlayFabProfilesInstanceAPI& source) = delete; // disable copy
        PlayFabProfilesInstanceAPI(PlayFabProfilesInstanceAPI&&) = delete; // disable move
        PlayFabProfilesInstanceAPI& operator=(const PlayFabProfilesInstanceAPI& source) = delete; // disable assignment
        PlayFabProfilesInstanceAPI& operator=(PlayFabProfilesInstanceAPI&& other) = delete; // disable move assignment

        std::shared_ptr<PlayFabApiSettings> GetSettings() const;
        void SetSettings(std::shared_ptr<PlayFabApiSettings> apiSettings);
        std::shared_ptr<PlayFabAuthenticationContext> GetAuthenticationContext() const;
        void SetAuthenticationContext(std::shared_ptr<PlayFabAuthenticationContext> authenticationContext);
        size_t Update();
        void ForgetAllCredentials();

        // ------------ Generated API calls
        void GetGlobalPolicy(ProfilesModels::GetGlobalPolicyRequest& request, const ProcessApiCallback<ProfilesModels::GetGlobalPolicyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetProfile(ProfilesModels::GetEntityProfileRequest& request, const ProcessApiCallback<ProfilesModels::GetEntityProfileResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetProfiles(ProfilesModels::GetEntityProfilesRequest& request, const ProcessApiCallback<ProfilesModels::GetEntityProfilesResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetTitlePlayersFromMasterPlayerAccountIds(ProfilesModels::GetTitlePlayersFromMasterPlayerAccountIdsRequest& request, const ProcessApiCallback<ProfilesModels::GetTitlePlayersFromMasterPlayerAccountIdsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SetGlobalPolicy(ProfilesModels::SetGlobalPolicyRequest& request, const ProcessApiCallback<ProfilesModels::SetGlobalPolicyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SetProfileLanguage(ProfilesModels::SetProfileLanguageRequest& request, const ProcessApiCallback<ProfilesModels::SetProfileLanguageResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SetProfilePolicy(ProfilesModels::SetEntityProfilePolicyRequest& request, const ProcessApiCallback<ProfilesModels::SetEntityProfilePolicyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);

        // ------------ Generated result handlers
        void OnGetGlobalPolicyResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetProfileResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetProfilesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetTitlePlayersFromMasterPlayerAccountIdsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnSetGlobalPolicyResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnSetProfileLanguageResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnSetProfilePolicyResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        bool ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container);
    };
}

#endif
