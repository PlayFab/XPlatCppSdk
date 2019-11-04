#pragma once

#ifndef DISABLE_PLAYFABENTITY_API
#ifndef PLAYFAB_DISABLE_STATIC_API

#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabLocalizationDataModels.h>

namespace PlayFab
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Localization APIs
    /// </summary>
    class PlayFabLocalizationAPI
    {
    public:
        static size_t Update();
        static void ForgetAllCredentials();


        // ------------ Generated API calls
        static void GetLanguageList(LocalizationModels::GetLanguageListRequest& request, const ProcessApiCallback<LocalizationModels::GetLanguageListResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        PlayFabLocalizationAPI(); // Private constructor, static class should never have an instance
        PlayFabLocalizationAPI(const PlayFabLocalizationAPI& other); // Private copy-constructor, static class should never have an instance

        // ------------ Generated result handlers
        static void OnGetLanguageListResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);

        static bool ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container);
    };
}

#endif // PLAYFAB_DISABLE_STATIC_API
#endif // #ifndef DISABLE_PLAYFABENTITY_API
