#pragma once

#if !defined(DISABLE_PLAYFABENTITY_API)

#include <playfab/PlayFabEventsDataModels.h>
#include <playfab/PlayFabError.h>

namespace PlayFab
{
    class CallRequestContainerBase;
    class CallRequestContainer;

    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Events APIs
    /// </summary>
    class PlayFabEventsAPI
    {
    public:
        /// <summary>
        /// Calls the Update function on your implementation of the IHttpPlugin to check for responses to HTTP requests.
        /// All api's (Client, Server, Admin etc.) share the same IHttpPlugin. 
        /// This means that you only need to call Update() on one API to retrieve the responses for all APIs.
        /// Additional calls to Update (on any API) during the same tick are unlikely to retrieve additional responses.
        /// Call Update when your game ticks as follows:
        ///     Events.Update();
        /// </summary>
        static size_t Update();
        static void ForgetAllCredentials();


        // ------------ Generated API calls
        static void CreateTelemetryKey(EventsModels::CreateTelemetryKeyRequest& request, const ProcessApiCallback<EventsModels::CreateTelemetryKeyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteDataConnection(EventsModels::DeleteDataConnectionRequest& request, const ProcessApiCallback<EventsModels::DeleteDataConnectionResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteTelemetryKey(EventsModels::DeleteTelemetryKeyRequest& request, const ProcessApiCallback<EventsModels::DeleteTelemetryKeyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetDataConnection(EventsModels::GetDataConnectionRequest& request, const ProcessApiCallback<EventsModels::GetDataConnectionResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetTelemetryKey(EventsModels::GetTelemetryKeyRequest& request, const ProcessApiCallback<EventsModels::GetTelemetryKeyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListDataConnections(EventsModels::ListDataConnectionsRequest& request, const ProcessApiCallback<EventsModels::ListDataConnectionsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListTelemetryKeys(EventsModels::ListTelemetryKeysRequest& request, const ProcessApiCallback<EventsModels::ListTelemetryKeysResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetDataConnection(EventsModels::SetDataConnectionRequest& request, const ProcessApiCallback<EventsModels::SetDataConnectionResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetDataConnectionActive(EventsModels::SetDataConnectionActiveRequest& request, const ProcessApiCallback<EventsModels::SetDataConnectionActiveResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetTelemetryKeyActive(EventsModels::SetTelemetryKeyActiveRequest& request, const ProcessApiCallback<EventsModels::SetTelemetryKeyActiveResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void WriteEvents(EventsModels::WriteEventsRequest& request, const ProcessApiCallback<EventsModels::WriteEventsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void WriteTelemetryEvents(EventsModels::WriteEventsRequest& request, const ProcessApiCallback<EventsModels::WriteEventsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void WriteTelemetryEvents(EventsModels::WriteEventsRequest& request, std::string telemetryKey, const ProcessApiCallback<EventsModels::WriteEventsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        PlayFabEventsAPI(); // Private constructor, static class should never have an instance
        PlayFabEventsAPI(const PlayFabEventsAPI& other); // Private copy-constructor, static class should never have an instance

        // ------------ Generated result handlers
        static void OnCreateTelemetryKeyResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteDataConnectionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteTelemetryKeyResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetDataConnectionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetTelemetryKeyResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnListDataConnectionsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnListTelemetryKeysResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnSetDataConnectionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnSetDataConnectionActiveResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnSetTelemetryKeyActiveResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnWriteEventsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnWriteTelemetryEventsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);

        static bool ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container);
    };
}

#endif // #if !defined(DISABLE_PLAYFABENTITY_API)
