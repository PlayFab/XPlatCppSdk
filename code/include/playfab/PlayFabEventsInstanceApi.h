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
        /// <summary>
        /// Calls the Update function on your implementation of the IHttpPlugin to check for responses to HTTP requests.
        /// All api's (Client, Server, Admin etc.) share the same IHttpPlugin. 
        /// This means that you only need to call Update() on one API to retrieve the responses for all APIs.
        /// Additional calls to Update (on any API) during the same tick are unlikely to retrieve additional responses.
        /// Call Update when your game ticks as follows:
        ///     Events.Update();
        /// </summary>
        size_t Update();
        void ForgetAllCredentials();

        // ------------ Generated API calls
        void CreateTelemetryKey(EventsModels::CreateTelemetryKeyRequest& request, const ProcessApiCallback<EventsModels::CreateTelemetryKeyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteTelemetryKey(EventsModels::DeleteTelemetryKeyRequest& request, const ProcessApiCallback<EventsModels::DeleteTelemetryKeyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetTelemetryKey(EventsModels::GetTelemetryKeyRequest& request, const ProcessApiCallback<EventsModels::GetTelemetryKeyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ListTelemetryKeys(EventsModels::ListTelemetryKeysRequest& request, const ProcessApiCallback<EventsModels::ListTelemetryKeysResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SetTelemetryKeyActive(EventsModels::SetTelemetryKeyActiveRequest& request, const ProcessApiCallback<EventsModels::SetTelemetryKeyActiveResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void WriteEvents(EventsModels::WriteEventsRequest& request, const ProcessApiCallback<EventsModels::WriteEventsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void WriteTelemetryEvents(EventsModels::WriteEventsRequest& request, const ProcessApiCallback<EventsModels::WriteEventsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void WriteTelemetryEvents(EventsModels::WriteEventsRequest& request, std::string telemetryKey, const ProcessApiCallback<EventsModels::WriteEventsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);

        // ------------ Generated result handlers
        void OnCreateTelemetryKeyResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnDeleteTelemetryKeyResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetTelemetryKeyResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnListTelemetryKeysResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnSetTelemetryKeyActiveResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnWriteEventsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnWriteTelemetryEventsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);

        bool ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container);
    };
}

#endif
