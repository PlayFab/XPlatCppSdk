#pragma once

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabHttp.h>
#include <playfab/PlayFabProfilesDataModels.h>

namespace PlayFab
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Profiles APIs
    /// </summary>
    class PlayFabProfilesAPI
    {
    public:
        static size_t Update();
        static void ForgetAllCredentials();


        // ------------ Generated API calls
        static void GetGlobalPolicy(ProfilesModels::GetGlobalPolicyRequest& request, ProcessApiCallback<ProfilesModels::GetGlobalPolicyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetProfile(ProfilesModels::GetEntityProfileRequest& request, ProcessApiCallback<ProfilesModels::GetEntityProfileResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetProfiles(ProfilesModels::GetEntityProfilesRequest& request, ProcessApiCallback<ProfilesModels::GetEntityProfilesResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetGlobalPolicy(ProfilesModels::SetGlobalPolicyRequest& request, ProcessApiCallback<ProfilesModels::SetGlobalPolicyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetProfileLanguage(ProfilesModels::SetProfileLanguageRequest& request, ProcessApiCallback<ProfilesModels::SetProfileLanguageResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetProfilePolicy(ProfilesModels::SetEntityProfilePolicyRequest& request, ProcessApiCallback<ProfilesModels::SetEntityProfilePolicyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        PlayFabProfilesAPI(); // Private constructor, static class should never have an instance
        PlayFabProfilesAPI(const PlayFabProfilesAPI& other); // Private copy-constructor, static class should never have an instance

        // ------------ Generated result handlers
        static void OnGetGlobalPolicyResult(CallRequestContainerBase& request);
        static void OnGetProfileResult(CallRequestContainerBase& request);
        static void OnGetProfilesResult(CallRequestContainerBase& request);
        static void OnSetGlobalPolicyResult(CallRequestContainerBase& request);
        static void OnSetProfileLanguageResult(CallRequestContainerBase& request);
        static void OnSetProfilePolicyResult(CallRequestContainerBase& request);

    };
}

#endif
