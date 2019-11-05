#pragma once

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabApiSettings.h>
#include <playfab/PlayFabAuthenticationContext.h>
#include <playfab/PlayFabLocalizationDataModels.h>
#include <memory>

namespace PlayFab
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Localization APIs
    /// </summary>
    class PlayFabLocalizationInstanceAPI
    {
    private:
        std::shared_ptr<PlayFabApiSettings> m_settings{ nullptr };
        std::shared_ptr<PlayFabAuthenticationContext> m_context{ nullptr };

    public:
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
        void GetLanguageList(LocalizationModels::GetLanguageListRequest& request, const ProcessApiCallback<LocalizationModels::GetLanguageListResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);

        // ------------ Generated result handlers
        void OnGetLanguageListResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        bool ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container);
    };
}

#endif
