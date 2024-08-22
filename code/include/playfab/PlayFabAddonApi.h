#pragma once

#if !defined(DISABLE_PLAYFABENTITY_API)

#include <playfab/PlayFabAddonDataModels.h>
#include <playfab/PlayFabError.h>

namespace PlayFab
{
    class CallRequestContainerBase;
    class CallRequestContainer;

    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Addon APIs
    /// </summary>
    class PlayFabAddonAPI
    {
    public:
        /// <summary>
        /// Calls the Update function on your implementation of the IHttpPlugin to check for responses to HTTP requests.
        /// All api's (Client, Server, Admin etc.) share the same IHttpPlugin. 
        /// This means that you only need to call Update() on one API to retrieve the responses for all APIs.
        /// Additional calls to Update (on any API) during the same tick are unlikely to retrieve additional responses.
        /// Call Update when your game ticks as follows:
        ///     Addon.Update();
        /// </summary>
        static size_t Update();
        static void ForgetAllCredentials();


        // ------------ Generated API calls
        static void CreateOrUpdateApple(AddonModels::CreateOrUpdateAppleRequest& request, const ProcessApiCallback<AddonModels::CreateOrUpdateAppleResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateOrUpdateFacebook(AddonModels::CreateOrUpdateFacebookRequest& request, const ProcessApiCallback<AddonModels::CreateOrUpdateFacebookResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateOrUpdateFacebookInstantGames(AddonModels::CreateOrUpdateFacebookInstantGamesRequest& request, const ProcessApiCallback<AddonModels::CreateOrUpdateFacebookInstantGamesResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateOrUpdateGoogle(AddonModels::CreateOrUpdateGoogleRequest& request, const ProcessApiCallback<AddonModels::CreateOrUpdateGoogleResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateOrUpdateKongregate(AddonModels::CreateOrUpdateKongregateRequest& request, const ProcessApiCallback<AddonModels::CreateOrUpdateKongregateResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateOrUpdateNintendo(AddonModels::CreateOrUpdateNintendoRequest& request, const ProcessApiCallback<AddonModels::CreateOrUpdateNintendoResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateOrUpdatePSN(AddonModels::CreateOrUpdatePSNRequest& request, const ProcessApiCallback<AddonModels::CreateOrUpdatePSNResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateOrUpdateSteam(AddonModels::CreateOrUpdateSteamRequest& request, const ProcessApiCallback<AddonModels::CreateOrUpdateSteamResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateOrUpdateTwitch(AddonModels::CreateOrUpdateTwitchRequest& request, const ProcessApiCallback<AddonModels::CreateOrUpdateTwitchResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteApple(AddonModels::DeleteAppleRequest& request, const ProcessApiCallback<AddonModels::DeleteAppleResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteFacebook(AddonModels::DeleteFacebookRequest& request, const ProcessApiCallback<AddonModels::DeleteFacebookResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteFacebookInstantGames(AddonModels::DeleteFacebookInstantGamesRequest& request, const ProcessApiCallback<AddonModels::DeleteFacebookInstantGamesResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteGoogle(AddonModels::DeleteGoogleRequest& request, const ProcessApiCallback<AddonModels::DeleteGoogleResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteKongregate(AddonModels::DeleteKongregateRequest& request, const ProcessApiCallback<AddonModels::DeleteKongregateResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteNintendo(AddonModels::DeleteNintendoRequest& request, const ProcessApiCallback<AddonModels::DeleteNintendoResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeletePSN(AddonModels::DeletePSNRequest& request, const ProcessApiCallback<AddonModels::DeletePSNResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteSteam(AddonModels::DeleteSteamRequest& request, const ProcessApiCallback<AddonModels::DeleteSteamResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteTwitch(AddonModels::DeleteTwitchRequest& request, const ProcessApiCallback<AddonModels::DeleteTwitchResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetApple(AddonModels::GetAppleRequest& request, const ProcessApiCallback<AddonModels::GetAppleResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetFacebook(AddonModels::GetFacebookRequest& request, const ProcessApiCallback<AddonModels::GetFacebookResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetFacebookInstantGames(AddonModels::GetFacebookInstantGamesRequest& request, const ProcessApiCallback<AddonModels::GetFacebookInstantGamesResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetGoogle(AddonModels::GetGoogleRequest& request, const ProcessApiCallback<AddonModels::GetGoogleResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetKongregate(AddonModels::GetKongregateRequest& request, const ProcessApiCallback<AddonModels::GetKongregateResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetNintendo(AddonModels::GetNintendoRequest& request, const ProcessApiCallback<AddonModels::GetNintendoResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPSN(AddonModels::GetPSNRequest& request, const ProcessApiCallback<AddonModels::GetPSNResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetSteam(AddonModels::GetSteamRequest& request, const ProcessApiCallback<AddonModels::GetSteamResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetTwitch(AddonModels::GetTwitchRequest& request, const ProcessApiCallback<AddonModels::GetTwitchResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        PlayFabAddonAPI(); // Private constructor, static class should never have an instance
        PlayFabAddonAPI(const PlayFabAddonAPI& other); // Private copy-constructor, static class should never have an instance

        // ------------ Generated result handlers
        static void OnCreateOrUpdateAppleResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnCreateOrUpdateFacebookResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnCreateOrUpdateFacebookInstantGamesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnCreateOrUpdateGoogleResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnCreateOrUpdateKongregateResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnCreateOrUpdateNintendoResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnCreateOrUpdatePSNResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnCreateOrUpdateSteamResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnCreateOrUpdateTwitchResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteAppleResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteFacebookResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteFacebookInstantGamesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteGoogleResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteKongregateResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteNintendoResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeletePSNResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteSteamResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteTwitchResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetAppleResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetFacebookResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetFacebookInstantGamesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetGoogleResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetKongregateResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetNintendoResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetPSNResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetSteamResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetTwitchResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);

        static bool ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container);
    };
}

#endif // #if !defined(DISABLE_PLAYFABENTITY_API)
