#pragma once

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabApiSettings.h>
#include <playfab/PlayFabAuthenticationContext.h>
#include <playfab/PlayFabEventsDataModels.h>
#include <memory>

namespace PlayFab
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Events APIs
    /// </summary>
    class PlayFabEventsInstanceAPI
    {
    private:
        std::shared_ptr<PlayFabApiSettings> m_settings{ nullptr };
        std::shared_ptr<PlayFabAuthenticationContext> m_authContext{ nullptr };

    public:
        explicit PlayFabEventsInstanceAPI(std::shared_ptr<PlayFabAuthenticationContext> authenticationContext);
        PlayFabEventsInstanceAPI(std::shared_ptr<PlayFabApiSettings> apiSettings, std::shared_ptr<PlayFabAuthenticationContext> authenticationContext);

        ~PlayFabEventsInstanceAPI();
        PlayFabEventsInstanceAPI(const PlayFabEventsInstanceAPI& source) = delete; // disable copy
        PlayFabEventsInstanceAPI(PlayFabEventsInstanceAPI&&) = delete; // disable move
        PlayFabEventsInstanceAPI& operator=(const PlayFabEventsInstanceAPI& source) = delete; // disable assignment
        PlayFabEventsInstanceAPI& operator=(PlayFabEventsInstanceAPI&& other) = delete; // disable move assignment

        std::shared_ptr<PlayFabApiSettings> GetSettings() const;
        void SetSettings(std::shared_ptr<PlayFabApiSettings> apiSettings);
        std::shared_ptr<PlayFabAuthenticationContext> GetAuthenticationContext() const;
        void SetAuthenticationContext(std::shared_ptr<PlayFabAuthenticationContext> authenticationContext);
        size_t Update();
        void ForgetAllCredentials();

        // ------------ Generated API calls
        void WriteEvents(EventsModels::WriteEventsRequest& request, const ProcessApiCallback<EventsModels::WriteEventsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void WriteTelemetryEvents(EventsModels::WriteEventsRequest& request, const ProcessApiCallback<EventsModels::WriteEventsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);

        // ------------ Generated result handlers
        void OnWriteEventsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnWriteTelemetryEventsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        bool ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container);
    };
}

#endif
