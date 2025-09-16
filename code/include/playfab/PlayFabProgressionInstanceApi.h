#pragma once

#if !defined(DISABLE_PLAYFABENTITY_API)

#include <playfab/PlayFabProgressionDataModels.h>
#include <playfab/PlayFabError.h>

namespace PlayFab
{
    class CallRequestContainerBase;
    class CallRequestContainer;
    class PlayFabApiSettings;
    class PlayFabAuthenticationContext;

    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Progression APIs
    /// </summary>
    class PlayFabProgressionInstanceAPI
    {
    private:
        std::shared_ptr<PlayFabApiSettings> m_settings;
        std::shared_ptr<PlayFabAuthenticationContext> m_context;

    public:
        PlayFabProgressionInstanceAPI(const std::shared_ptr<PlayFabAuthenticationContext>& authenticationContext);
        PlayFabProgressionInstanceAPI(const std::shared_ptr<PlayFabApiSettings>& apiSettings, const std::shared_ptr<PlayFabAuthenticationContext>& authenticationContext);

        ~PlayFabProgressionInstanceAPI() = default;
        PlayFabProgressionInstanceAPI(const PlayFabProgressionInstanceAPI& source) = delete; // disable copy
        PlayFabProgressionInstanceAPI(PlayFabProgressionInstanceAPI&&) = delete; // disable move
        PlayFabProgressionInstanceAPI& operator=(const PlayFabProgressionInstanceAPI& source) = delete; // disable assignment
        PlayFabProgressionInstanceAPI& operator=(PlayFabProgressionInstanceAPI&& other) = delete; // disable move assignment

        std::shared_ptr<PlayFabApiSettings> GetSettings() const;
        std::shared_ptr<PlayFabAuthenticationContext> GetAuthenticationContext() const;
        /// <summary>
        /// Calls the Update function on your implementation of the IHttpPlugin to check for responses to HTTP requests.
        /// All api's (Client, Server, Admin etc.) share the same IHttpPlugin. 
        /// This means that you only need to call Update() on one API to retrieve the responses for all APIs.
        /// Additional calls to Update (on any API) during the same tick are unlikely to retrieve additional responses.
        /// Call Update when your game ticks as follows:
        ///     Progression.Update();
        /// </summary>
        size_t Update();
        void ForgetAllCredentials();

        // ------------ Generated API calls
        void CreateLeaderboardDefinition(ProgressionModels::CreateLeaderboardDefinitionRequest& request, const ProcessApiCallback<ProgressionModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateStatisticDefinition(ProgressionModels::CreateStatisticDefinitionRequest& request, const ProcessApiCallback<ProgressionModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteLeaderboardDefinition(ProgressionModels::DeleteLeaderboardDefinitionRequest& request, const ProcessApiCallback<ProgressionModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteLeaderboardEntries(ProgressionModels::DeleteLeaderboardEntriesRequest& request, const ProcessApiCallback<ProgressionModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteStatisticDefinition(ProgressionModels::DeleteStatisticDefinitionRequest& request, const ProcessApiCallback<ProgressionModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteStatistics(ProgressionModels::DeleteStatisticsRequest& request, const ProcessApiCallback<ProgressionModels::DeleteStatisticsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetFriendLeaderboardForEntity(ProgressionModels::GetFriendLeaderboardForEntityRequest& request, const ProcessApiCallback<ProgressionModels::GetEntityLeaderboardResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetLeaderboard(ProgressionModels::GetEntityLeaderboardRequest& request, const ProcessApiCallback<ProgressionModels::GetEntityLeaderboardResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetLeaderboardAroundEntity(ProgressionModels::GetLeaderboardAroundEntityRequest& request, const ProcessApiCallback<ProgressionModels::GetEntityLeaderboardResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetLeaderboardDefinition(ProgressionModels::GetLeaderboardDefinitionRequest& request, const ProcessApiCallback<ProgressionModels::GetLeaderboardDefinitionResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetLeaderboardForEntities(ProgressionModels::GetLeaderboardForEntitiesRequest& request, const ProcessApiCallback<ProgressionModels::GetEntityLeaderboardResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetStatisticDefinition(ProgressionModels::GetStatisticDefinitionRequest& request, const ProcessApiCallback<ProgressionModels::GetStatisticDefinitionResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetStatistics(ProgressionModels::GetStatisticsRequest& request, const ProcessApiCallback<ProgressionModels::GetStatisticsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetStatisticsForEntities(ProgressionModels::GetStatisticsForEntitiesRequest& request, const ProcessApiCallback<ProgressionModels::GetStatisticsForEntitiesResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void IncrementLeaderboardVersion(ProgressionModels::IncrementLeaderboardVersionRequest& request, const ProcessApiCallback<ProgressionModels::IncrementLeaderboardVersionResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void IncrementStatisticVersion(ProgressionModels::IncrementStatisticVersionRequest& request, const ProcessApiCallback<ProgressionModels::IncrementStatisticVersionResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ListLeaderboardDefinitions(ProgressionModels::ListLeaderboardDefinitionsRequest& request, const ProcessApiCallback<ProgressionModels::ListLeaderboardDefinitionsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ListStatisticDefinitions(ProgressionModels::ListStatisticDefinitionsRequest& request, const ProcessApiCallback<ProgressionModels::ListStatisticDefinitionsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UnlinkAggregationSourceFromStatistic(ProgressionModels::UnlinkAggregationSourceFromStatisticRequest& request, const ProcessApiCallback<ProgressionModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UnlinkLeaderboardFromStatistic(ProgressionModels::UnlinkLeaderboardFromStatisticRequest& request, const ProcessApiCallback<ProgressionModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateLeaderboardDefinition(ProgressionModels::UpdateLeaderboardDefinitionRequest& request, const ProcessApiCallback<ProgressionModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateLeaderboardEntries(ProgressionModels::UpdateLeaderboardEntriesRequest& request, const ProcessApiCallback<ProgressionModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateStatisticDefinition(ProgressionModels::UpdateStatisticDefinitionRequest& request, const ProcessApiCallback<ProgressionModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateStatistics(ProgressionModels::UpdateStatisticsRequest& request, const ProcessApiCallback<ProgressionModels::UpdateStatisticsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);

        // ------------ Generated result handlers
        void OnCreateLeaderboardDefinitionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnCreateStatisticDefinitionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnDeleteLeaderboardDefinitionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnDeleteLeaderboardEntriesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnDeleteStatisticDefinitionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnDeleteStatisticsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetFriendLeaderboardForEntityResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetLeaderboardResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetLeaderboardAroundEntityResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetLeaderboardDefinitionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetLeaderboardForEntitiesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetStatisticDefinitionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetStatisticsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetStatisticsForEntitiesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnIncrementLeaderboardVersionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnIncrementStatisticVersionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnListLeaderboardDefinitionsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnListStatisticDefinitionsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnUnlinkAggregationSourceFromStatisticResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnUnlinkLeaderboardFromStatisticResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnUpdateLeaderboardDefinitionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnUpdateLeaderboardEntriesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnUpdateStatisticDefinitionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnUpdateStatisticsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);

        bool ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container);
    };
}

#endif
