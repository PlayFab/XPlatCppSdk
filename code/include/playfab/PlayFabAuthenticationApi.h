#pragma once

#ifndef DISABLE_PLAYFABENTITY_API
#ifndef PLAYFAB_DISABLE_STATIC_API

#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabAuthenticationDataModels.h>

namespace PlayFab
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Authentication APIs
    /// </summary>
    class PlayFabAuthenticationAPI
    {
    public:
        static size_t Update();
        static void ForgetAllCredentials();


        // ------------ Generated API calls
        static void GetEntityToken(AuthenticationModels::GetEntityTokenRequest& request, const ProcessApiCallback<AuthenticationModels::GetEntityTokenResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ValidateEntityToken(AuthenticationModels::ValidateEntityTokenRequest& request, const ProcessApiCallback<AuthenticationModels::ValidateEntityTokenResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        PlayFabAuthenticationAPI(); // Private constructor, static class should never have an instance
        PlayFabAuthenticationAPI(const PlayFabAuthenticationAPI& other); // Private copy-constructor, static class should never have an instance

        // ------------ Generated result handlers
        static void OnGetEntityTokenResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnValidateEntityTokenResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);

        static bool ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container);
    };
}

#endif // PLAYFAB_DISABLE_STATIC_API
#endif // #ifndef DISABLE_PLAYFABENTITY_API
