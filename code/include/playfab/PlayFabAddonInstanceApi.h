#pragma once

#if !defined(DISABLE_PLAYFABENTITY_API)

#include <playfab/PlayFabAddonDataModels.h>
#include <playfab/PlayFabError.h>

namespace PlayFab
{
    class CallRequestContainerBase;
    class CallRequestContainer;
    class PlayFabApiSettings;
    class PlayFabAuthenticationContext;

    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Addon APIs
    /// </summary>
    class PlayFabAddonInstanceAPI
    {
    private:
        std::shared_ptr<PlayFabApiSettings> m_settings;
        std::shared_ptr<PlayFabAuthenticationContext> m_context;

    public:
        PlayFabAddonInstanceAPI(const std::shared_ptr<PlayFabAuthenticationContext>& authenticationContext);
        PlayFabAddonInstanceAPI(const std::shared_ptr<PlayFabApiSettings>& apiSettings, const std::shared_ptr<PlayFabAuthenticationContext>& authenticationContext);

        ~PlayFabAddonInstanceAPI() = default;
        PlayFabAddonInstanceAPI(const PlayFabAddonInstanceAPI& source) = delete; // disable copy
        PlayFabAddonInstanceAPI(PlayFabAddonInstanceAPI&&) = delete; // disable move
        PlayFabAddonInstanceAPI& operator=(const PlayFabAddonInstanceAPI& source) = delete; // disable assignment
        PlayFabAddonInstanceAPI& operator=(PlayFabAddonInstanceAPI&& other) = delete; // disable move assignment

        std::shared_ptr<PlayFabApiSettings> GetSettings() const;
        std::shared_ptr<PlayFabAuthenticationContext> GetAuthenticationContext() const;
        /// <summary>
        /// Calls the Update function on your implementation of the IHttpPlugin to check for responses to HTTP requests.
        /// All api's (Client, Server, Admin etc.) share the same IHttpPlugin. 
        /// This means that you only need to call Update() on one API to retrieve the responses for all APIs.
        /// Additional calls to Update (on any API) during the same tick are unlikely to retrieve additional responses.
        /// Call Update when your game ticks as follows:
        ///     Addon.Update();
        /// </summary>
        size_t Update();
        void ForgetAllCredentials();

        // ------------ Generated API calls
        void CreateOrUpdateApple(AddonModels::CreateOrUpdateAppleRequest& request, const ProcessApiCallback<AddonModels::CreateOrUpdateAppleResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateOrUpdateFacebook(AddonModels::CreateOrUpdateFacebookRequest& request, const ProcessApiCallback<AddonModels::CreateOrUpdateFacebookResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateOrUpdateFacebookInstantGames(AddonModels::CreateOrUpdateFacebookInstantGamesRequest& request, const ProcessApiCallback<AddonModels::CreateOrUpdateFacebookInstantGamesResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateOrUpdateGoogle(AddonModels::CreateOrUpdateGoogleRequest& request, const ProcessApiCallback<AddonModels::CreateOrUpdateGoogleResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateOrUpdateKongregate(AddonModels::CreateOrUpdateKongregateRequest& request, const ProcessApiCallback<AddonModels::CreateOrUpdateKongregateResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateOrUpdateNintendo(AddonModels::CreateOrUpdateNintendoRequest& request, const ProcessApiCallback<AddonModels::CreateOrUpdateNintendoResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateOrUpdatePSN(AddonModels::CreateOrUpdatePSNRequest& request, const ProcessApiCallback<AddonModels::CreateOrUpdatePSNResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateOrUpdateSteam(AddonModels::CreateOrUpdateSteamRequest& request, const ProcessApiCallback<AddonModels::CreateOrUpdateSteamResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateOrUpdateToxMod(AddonModels::CreateOrUpdateToxModRequest& request, const ProcessApiCallback<AddonModels::CreateOrUpdateToxModResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateOrUpdateTwitch(AddonModels::CreateOrUpdateTwitchRequest& request, const ProcessApiCallback<AddonModels::CreateOrUpdateTwitchResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteApple(AddonModels::DeleteAppleRequest& request, const ProcessApiCallback<AddonModels::DeleteAppleResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteFacebook(AddonModels::DeleteFacebookRequest& request, const ProcessApiCallback<AddonModels::DeleteFacebookResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteFacebookInstantGames(AddonModels::DeleteFacebookInstantGamesRequest& request, const ProcessApiCallback<AddonModels::DeleteFacebookInstantGamesResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteGoogle(AddonModels::DeleteGoogleRequest& request, const ProcessApiCallback<AddonModels::DeleteGoogleResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteKongregate(AddonModels::DeleteKongregateRequest& request, const ProcessApiCallback<AddonModels::DeleteKongregateResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteNintendo(AddonModels::DeleteNintendoRequest& request, const ProcessApiCallback<AddonModels::DeleteNintendoResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeletePSN(AddonModels::DeletePSNRequest& request, const ProcessApiCallback<AddonModels::DeletePSNResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteSteam(AddonModels::DeleteSteamRequest& request, const ProcessApiCallback<AddonModels::DeleteSteamResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteToxMod(AddonModels::DeleteToxModRequest& request, const ProcessApiCallback<AddonModels::DeleteToxModResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteTwitch(AddonModels::DeleteTwitchRequest& request, const ProcessApiCallback<AddonModels::DeleteTwitchResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetApple(AddonModels::GetAppleRequest& request, const ProcessApiCallback<AddonModels::GetAppleResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetFacebook(AddonModels::GetFacebookRequest& request, const ProcessApiCallback<AddonModels::GetFacebookResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetFacebookInstantGames(AddonModels::GetFacebookInstantGamesRequest& request, const ProcessApiCallback<AddonModels::GetFacebookInstantGamesResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetGoogle(AddonModels::GetGoogleRequest& request, const ProcessApiCallback<AddonModels::GetGoogleResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetKongregate(AddonModels::GetKongregateRequest& request, const ProcessApiCallback<AddonModels::GetKongregateResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetNintendo(AddonModels::GetNintendoRequest& request, const ProcessApiCallback<AddonModels::GetNintendoResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPSN(AddonModels::GetPSNRequest& request, const ProcessApiCallback<AddonModels::GetPSNResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetSteam(AddonModels::GetSteamRequest& request, const ProcessApiCallback<AddonModels::GetSteamResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetToxMod(AddonModels::GetToxModRequest& request, const ProcessApiCallback<AddonModels::GetToxModResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetTwitch(AddonModels::GetTwitchRequest& request, const ProcessApiCallback<AddonModels::GetTwitchResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);

        // ------------ Generated result handlers
        void OnCreateOrUpdateAppleResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnCreateOrUpdateFacebookResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnCreateOrUpdateFacebookInstantGamesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnCreateOrUpdateGoogleResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnCreateOrUpdateKongregateResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnCreateOrUpdateNintendoResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnCreateOrUpdatePSNResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnCreateOrUpdateSteamResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnCreateOrUpdateToxModResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnCreateOrUpdateTwitchResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnDeleteAppleResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnDeleteFacebookResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnDeleteFacebookInstantGamesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnDeleteGoogleResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnDeleteKongregateResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnDeleteNintendoResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnDeletePSNResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnDeleteSteamResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnDeleteToxModResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnDeleteTwitchResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetAppleResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetFacebookResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetFacebookInstantGamesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetGoogleResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetKongregateResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetNintendoResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetPSNResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetSteamResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetToxModResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetTwitchResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);

        bool ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container);
    };
}

#endif
