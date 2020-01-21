#pragma once

#if !defined(DISABLE_PLAYFABENTITY_API)

#include <playfab/PlayFabEventsDataModels.h>
#include <playfab/PlayFabError.h>

namespace PlayFab
{
    class CallRequestContainerBase;
    class CallRequestContainer;
    class PlayFabApiSettings;
    class PlayFabAuthenticationContext;

    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Events APIs
    /// </summary>
    class PlayFabEventsInstanceAPI
    {
    private:
        std::shared_ptr<PlayFabApiSettings> m_settings;
        std::shared_ptr<PlayFabAuthenticationContext> m_context;

    public:
        PlayFabEventsInstanceAPI(const std::shared_ptr<PlayFabAuthenticationContext>& authenticationContext);
        PlayFabEventsInstanceAPI(const std::shared_ptr<PlayFabApiSettings>& apiSettings, const std::shared_ptr<PlayFabAuthenticationContext>& authenticationContext);

        ~PlayFabEventsInstanceAPI() = default;
        PlayFabEventsInstanceAPI(const PlayFabEventsInstanceAPI& source) = delete; // disable copy
        PlayFabEventsInstanceAPI(PlayFabEventsInstanceAPI&&) = delete; // disable move
        PlayFabEventsInstanceAPI& operator=(const PlayFabEventsInstanceAPI& source) = delete; // disable assignment
        PlayFabEventsInstanceAPI& operator=(PlayFabEventsInstanceAPI&& other) = delete; // disable move assignment

        std::shared_ptr<PlayFabApiSettings> GetSettings() const;
        std::shared_ptr<PlayFabAuthenticationContext> GetAuthenticationContext() const;
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
