#pragma once

#if !defined(DISABLE_PLAYFABENTITY_API)

#include <playfab/PlayFabLeaderboardsDataModels.h>
#include <playfab/PlayFabError.h>

namespace PlayFab
{
    class CallRequestContainerBase;
    class CallRequestContainer;
    class PlayFabApiSettings;
    class PlayFabAuthenticationContext;

    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Leaderboards APIs
    /// </summary>
    class PlayFabLeaderboardsInstanceAPI
    {
    private:
        std::shared_ptr<PlayFabApiSettings> m_settings;
        std::shared_ptr<PlayFabAuthenticationContext> m_context;

    public:
        PlayFabLeaderboardsInstanceAPI(const std::shared_ptr<PlayFabAuthenticationContext>& authenticationContext);
        PlayFabLeaderboardsInstanceAPI(const std::shared_ptr<PlayFabApiSettings>& apiSettings, const std::shared_ptr<PlayFabAuthenticationContext>& authenticationContext);

        ~PlayFabLeaderboardsInstanceAPI() = default;
        PlayFabLeaderboardsInstanceAPI(const PlayFabLeaderboardsInstanceAPI& source) = delete; // disable copy
        PlayFabLeaderboardsInstanceAPI(PlayFabLeaderboardsInstanceAPI&&) = delete; // disable move
        PlayFabLeaderboardsInstanceAPI& operator=(const PlayFabLeaderboardsInstanceAPI& source) = delete; // disable assignment
        PlayFabLeaderboardsInstanceAPI& operator=(PlayFabLeaderboardsInstanceAPI&& other) = delete; // disable move assignment

        std::shared_ptr<PlayFabApiSettings> GetSettings() const;
        std::shared_ptr<PlayFabAuthenticationContext> GetAuthenticationContext() const;
        /// <summary>
        /// Calls the Update function on your implementation of the IHttpPlugin to check for responses to HTTP requests.
        /// All api's (Client, Server, Admin etc.) share the same IHttpPlugin. 
        /// This means that you only need to call Update() on one API to retrieve the responses for all APIs.
        /// Additional calls to Update (on any API) during the same tick are unlikely to retrieve additional responses.
        /// Call Update when your game ticks as follows:
        ///     Leaderboards.Update();
        /// </summary>
        size_t Update();
        void ForgetAllCredentials();

        // ------------ Generated API calls
        void CreateLeaderboardDefinition(LeaderboardsModels::CreateLeaderboardDefinitionRequest& request, const ProcessApiCallback<LeaderboardsModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateStatisticDefinition(LeaderboardsModels::CreateStatisticDefinitionRequest& request, const ProcessApiCallback<LeaderboardsModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteLeaderboardDefinition(LeaderboardsModels::DeleteLeaderboardDefinitionRequest& request, const ProcessApiCallback<LeaderboardsModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteLeaderboardEntries(LeaderboardsModels::DeleteLeaderboardEntriesRequest& request, const ProcessApiCallback<LeaderboardsModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteStatisticDefinition(LeaderboardsModels::DeleteStatisticDefinitionRequest& request, const ProcessApiCallback<LeaderboardsModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteStatistics(LeaderboardsModels::DeleteStatisticsRequest& request, const ProcessApiCallback<LeaderboardsModels::DeleteStatisticsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetFriendLeaderboardForEntity(LeaderboardsModels::GetFriendLeaderboardForEntityRequest& request, const ProcessApiCallback<LeaderboardsModels::GetEntityLeaderboardResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetLeaderboard(LeaderboardsModels::GetEntityLeaderboardRequest& request, const ProcessApiCallback<LeaderboardsModels::GetEntityLeaderboardResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetLeaderboardAroundEntity(LeaderboardsModels::GetLeaderboardAroundEntityRequest& request, const ProcessApiCallback<LeaderboardsModels::GetEntityLeaderboardResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetLeaderboardDefinition(LeaderboardsModels::GetLeaderboardDefinitionRequest& request, const ProcessApiCallback<LeaderboardsModels::GetLeaderboardDefinitionResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetLeaderboardForEntities(LeaderboardsModels::GetLeaderboardForEntitiesRequest& request, const ProcessApiCallback<LeaderboardsModels::GetEntityLeaderboardResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetStatisticDefinition(LeaderboardsModels::GetStatisticDefinitionRequest& request, const ProcessApiCallback<LeaderboardsModels::GetStatisticDefinitionResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetStatisticDefinitions(LeaderboardsModels::GetStatisticDefinitionsRequest& request, const ProcessApiCallback<LeaderboardsModels::GetStatisticDefinitionsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetStatistics(LeaderboardsModels::GetStatisticsRequest& request, const ProcessApiCallback<LeaderboardsModels::GetStatisticsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetStatisticsForEntities(LeaderboardsModels::GetStatisticsForEntitiesRequest& request, const ProcessApiCallback<LeaderboardsModels::GetStatisticsForEntitiesResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void IncrementLeaderboardVersion(LeaderboardsModels::IncrementLeaderboardVersionRequest& request, const ProcessApiCallback<LeaderboardsModels::IncrementLeaderboardVersionResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void IncrementStatisticVersion(LeaderboardsModels::IncrementStatisticVersionRequest& request, const ProcessApiCallback<LeaderboardsModels::IncrementStatisticVersionResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ListLeaderboardDefinitions(LeaderboardsModels::ListLeaderboardDefinitionsRequest& request, const ProcessApiCallback<LeaderboardsModels::ListLeaderboardDefinitionsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ListStatisticDefinitions(LeaderboardsModels::ListStatisticDefinitionsRequest& request, const ProcessApiCallback<LeaderboardsModels::ListStatisticDefinitionsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UnlinkLeaderboardFromStatistic(LeaderboardsModels::UnlinkLeaderboardFromStatisticRequest& request, const ProcessApiCallback<LeaderboardsModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateLeaderboardEntries(LeaderboardsModels::UpdateLeaderboardEntriesRequest& request, const ProcessApiCallback<LeaderboardsModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateStatistics(LeaderboardsModels::UpdateStatisticsRequest& request, const ProcessApiCallback<LeaderboardsModels::UpdateStatisticsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);

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
        void OnGetStatisticDefinitionsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetStatisticsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetStatisticsForEntitiesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnIncrementLeaderboardVersionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnIncrementStatisticVersionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnListLeaderboardDefinitionsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnListStatisticDefinitionsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnUnlinkLeaderboardFromStatisticResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnUpdateLeaderboardEntriesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnUpdateStatisticsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);

        bool ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container);
    };
}

#endif
