#pragma once

#if !defined(DISABLE_PLAYFABENTITY_API)

#include <playfab/PlayFabLeaderboardsDataModels.h>
#include <playfab/PlayFabError.h>

namespace PlayFab
{
    class CallRequestContainerBase;
    class CallRequestContainer;

    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Leaderboards APIs
    /// </summary>
    class PlayFabLeaderboardsAPI
    {
    public:
        /// <summary>
        /// Calls the Update function on your implementation of the IHttpPlugin to check for responses to HTTP requests.
        /// All api's (Client, Server, Admin etc.) share the same IHttpPlugin. 
        /// This means that you only need to call Update() on one API to retrieve the responses for all APIs.
        /// Additional calls to Update (on any API) during the same tick are unlikely to retrieve additional responses.
        /// Call Update when your game ticks as follows:
        ///     Leaderboards.Update();
        /// </summary>
        static size_t Update();
        static void ForgetAllCredentials();


        // ------------ Generated API calls
        static void CreateLeaderboardDefinition(LeaderboardsModels::CreateLeaderboardDefinitionRequest& request, const ProcessApiCallback<LeaderboardsModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateStatisticDefinition(LeaderboardsModels::CreateStatisticDefinitionRequest& request, const ProcessApiCallback<LeaderboardsModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteLeaderboardDefinition(LeaderboardsModels::DeleteLeaderboardDefinitionRequest& request, const ProcessApiCallback<LeaderboardsModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteLeaderboardEntries(LeaderboardsModels::DeleteLeaderboardEntriesRequest& request, const ProcessApiCallback<LeaderboardsModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteStatisticDefinition(LeaderboardsModels::DeleteStatisticDefinitionRequest& request, const ProcessApiCallback<LeaderboardsModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteStatistics(LeaderboardsModels::DeleteStatisticsRequest& request, const ProcessApiCallback<LeaderboardsModels::DeleteStatisticsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetFriendLeaderboardForEntity(LeaderboardsModels::GetFriendLeaderboardForEntityRequest& request, const ProcessApiCallback<LeaderboardsModels::GetEntityLeaderboardResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetLeaderboard(LeaderboardsModels::GetEntityLeaderboardRequest& request, const ProcessApiCallback<LeaderboardsModels::GetEntityLeaderboardResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetLeaderboardAroundEntity(LeaderboardsModels::GetLeaderboardAroundEntityRequest& request, const ProcessApiCallback<LeaderboardsModels::GetEntityLeaderboardResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetLeaderboardDefinition(LeaderboardsModels::GetLeaderboardDefinitionRequest& request, const ProcessApiCallback<LeaderboardsModels::GetLeaderboardDefinitionResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetLeaderboardForEntities(LeaderboardsModels::GetLeaderboardForEntitiesRequest& request, const ProcessApiCallback<LeaderboardsModels::GetEntityLeaderboardResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetStatisticDefinition(LeaderboardsModels::GetStatisticDefinitionRequest& request, const ProcessApiCallback<LeaderboardsModels::GetStatisticDefinitionResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetStatisticDefinitions(LeaderboardsModels::GetStatisticDefinitionsRequest& request, const ProcessApiCallback<LeaderboardsModels::GetStatisticDefinitionsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetStatistics(LeaderboardsModels::GetStatisticsRequest& request, const ProcessApiCallback<LeaderboardsModels::GetStatisticsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetStatisticsForEntities(LeaderboardsModels::GetStatisticsForEntitiesRequest& request, const ProcessApiCallback<LeaderboardsModels::GetStatisticsForEntitiesResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void IncrementLeaderboardVersion(LeaderboardsModels::IncrementLeaderboardVersionRequest& request, const ProcessApiCallback<LeaderboardsModels::IncrementLeaderboardVersionResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void IncrementStatisticVersion(LeaderboardsModels::IncrementStatisticVersionRequest& request, const ProcessApiCallback<LeaderboardsModels::IncrementStatisticVersionResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListLeaderboardDefinitions(LeaderboardsModels::ListLeaderboardDefinitionsRequest& request, const ProcessApiCallback<LeaderboardsModels::ListLeaderboardDefinitionsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListStatisticDefinitions(LeaderboardsModels::ListStatisticDefinitionsRequest& request, const ProcessApiCallback<LeaderboardsModels::ListStatisticDefinitionsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlinkLeaderboardFromStatistic(LeaderboardsModels::UnlinkLeaderboardFromStatisticRequest& request, const ProcessApiCallback<LeaderboardsModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateLeaderboardEntries(LeaderboardsModels::UpdateLeaderboardEntriesRequest& request, const ProcessApiCallback<LeaderboardsModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateStatistics(LeaderboardsModels::UpdateStatisticsRequest& request, const ProcessApiCallback<LeaderboardsModels::UpdateStatisticsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        PlayFabLeaderboardsAPI(); // Private constructor, static class should never have an instance
        PlayFabLeaderboardsAPI(const PlayFabLeaderboardsAPI& other); // Private copy-constructor, static class should never have an instance

        // ------------ Generated result handlers
        static void OnCreateLeaderboardDefinitionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnCreateStatisticDefinitionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteLeaderboardDefinitionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteLeaderboardEntriesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteStatisticDefinitionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteStatisticsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetFriendLeaderboardForEntityResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetLeaderboardResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetLeaderboardAroundEntityResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetLeaderboardDefinitionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetLeaderboardForEntitiesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetStatisticDefinitionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetStatisticDefinitionsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetStatisticsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetStatisticsForEntitiesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnIncrementLeaderboardVersionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnIncrementStatisticVersionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnListLeaderboardDefinitionsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnListStatisticDefinitionsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnUnlinkLeaderboardFromStatisticResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnUpdateLeaderboardEntriesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnUpdateStatisticsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);

        static bool ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container);
    };
}

#endif // #if !defined(DISABLE_PLAYFABENTITY_API)
