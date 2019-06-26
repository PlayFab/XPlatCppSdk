#pragma once

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabApiSettings.h>
#include <playfab/PlayFabAuthenticationContext.h>
#include <playfab/PlayFabLocalizationDataModels.h>
#include <memory>

#ifndef PLAYFAB_PLATFORM_PLAYSTATION // Issue 32699
namespace PlayFab
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Localization APIs
    /// </summary>
    class PlayFabLocalizationInstanceAPI
    {
    private:
        std::shared_ptr<PlayFabApiSettings> settings;
        std::shared_ptr<PlayFabAuthenticationContext> authContext;

    public:
        PlayFabLocalizationInstanceAPI();
        explicit PlayFabLocalizationInstanceAPI(std::shared_ptr<PlayFabApiSettings> apiSettings);
        explicit PlayFabLocalizationInstanceAPI(std::shared_ptr<PlayFabAuthenticationContext> authenticationContext);
        PlayFabLocalizationInstanceAPI(std::shared_ptr<PlayFabApiSettings> apiSettings, std::shared_ptr<PlayFabAuthenticationContext> authenticationContext);
        ~PlayFabLocalizationInstanceAPI();
        PlayFabLocalizationInstanceAPI(const PlayFabLocalizationInstanceAPI& source) = delete; // disable copy
        PlayFabLocalizationInstanceAPI(PlayFabLocalizationInstanceAPI&&) = delete; // disable move
        PlayFabLocalizationInstanceAPI& operator=(const PlayFabLocalizationInstanceAPI& source) = delete; // disable assignment
        PlayFabLocalizationInstanceAPI& operator=(PlayFabLocalizationInstanceAPI&& other) = delete; // disable move assignment

        std::shared_ptr<PlayFabApiSettings> GetSettings() const;
        void SetSettings(std::shared_ptr<PlayFabApiSettings> apiSettings);
        std::shared_ptr<PlayFabAuthenticationContext> GetAuthenticationContext() const;
        void SetAuthenticationContext(std::shared_ptr<PlayFabAuthenticationContext> authenticationContext);
        size_t Update();
        void ForgetAllCredentials();

        // ------------ Generated API calls
        void GetLanguageList(LocalizationModels::GetLanguageListRequest& request, ProcessApiCallback<LocalizationModels::GetLanguageListResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

        // ------------ Generated result handlers
        void OnGetLanguageListResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        bool ValidateResult(PlayFabResultCommon& resultCommon, CallRequestContainer& container);
    private:
        std::shared_ptr<PlayFabAuthenticationContext> GetOrCreateAuthenticationContext();
    };
}

#endif
#endif
