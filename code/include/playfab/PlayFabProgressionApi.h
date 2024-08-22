#pragma once

#if !defined(DISABLE_PLAYFABENTITY_API)

#include <playfab/PlayFabProgressionDataModels.h>
#include <playfab/PlayFabError.h>

namespace PlayFab
{
    class CallRequestContainerBase;
    class CallRequestContainer;

    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Progression APIs
    /// </summary>
    class PlayFabProgressionAPI
    {
    public:
        /// <summary>
        /// Calls the Update function on your implementation of the IHttpPlugin to check for responses to HTTP requests.
        /// All api's (Client, Server, Admin etc.) share the same IHttpPlugin. 
        /// This means that you only need to call Update() on one API to retrieve the responses for all APIs.
        /// Additional calls to Update (on any API) during the same tick are unlikely to retrieve additional responses.
        /// Call Update when your game ticks as follows:
        ///     Progression.Update();
        /// </summary>
        static size_t Update();
        static void ForgetAllCredentials();


        // ------------ Generated API calls
        static void CreateLeaderboardDefinition(ProgressionModels::CreateLeaderboardDefinitionRequest& request, const ProcessApiCallback<ProgressionModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateStatisticDefinition(ProgressionModels::CreateStatisticDefinitionRequest& request, const ProcessApiCallback<ProgressionModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteLeaderboardDefinition(ProgressionModels::DeleteLeaderboardDefinitionRequest& request, const ProcessApiCallback<ProgressionModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteLeaderboardEntries(ProgressionModels::DeleteLeaderboardEntriesRequest& request, const ProcessApiCallback<ProgressionModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteStatisticDefinition(ProgressionModels::DeleteStatisticDefinitionRequest& request, const ProcessApiCallback<ProgressionModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteStatistics(ProgressionModels::DeleteStatisticsRequest& request, const ProcessApiCallback<ProgressionModels::DeleteStatisticsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetFriendLeaderboardForEntity(ProgressionModels::GetFriendLeaderboardForEntityRequest& request, const ProcessApiCallback<ProgressionModels::GetEntityLeaderboardResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetLeaderboard(ProgressionModels::GetEntityLeaderboardRequest& request, const ProcessApiCallback<ProgressionModels::GetEntityLeaderboardResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetLeaderboardAroundEntity(ProgressionModels::GetLeaderboardAroundEntityRequest& request, const ProcessApiCallback<ProgressionModels::GetEntityLeaderboardResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetLeaderboardDefinition(ProgressionModels::GetLeaderboardDefinitionRequest& request, const ProcessApiCallback<ProgressionModels::GetLeaderboardDefinitionResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetLeaderboardForEntities(ProgressionModels::GetLeaderboardForEntitiesRequest& request, const ProcessApiCallback<ProgressionModels::GetEntityLeaderboardResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetStatisticDefinition(ProgressionModels::GetStatisticDefinitionRequest& request, const ProcessApiCallback<ProgressionModels::GetStatisticDefinitionResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetStatisticDefinitions(ProgressionModels::GetStatisticDefinitionsRequest& request, const ProcessApiCallback<ProgressionModels::GetStatisticDefinitionsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetStatistics(ProgressionModels::GetStatisticsRequest& request, const ProcessApiCallback<ProgressionModels::GetStatisticsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetStatisticsForEntities(ProgressionModels::GetStatisticsForEntitiesRequest& request, const ProcessApiCallback<ProgressionModels::GetStatisticsForEntitiesResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void IncrementLeaderboardVersion(ProgressionModels::IncrementLeaderboardVersionRequest& request, const ProcessApiCallback<ProgressionModels::IncrementLeaderboardVersionResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void IncrementStatisticVersion(ProgressionModels::IncrementStatisticVersionRequest& request, const ProcessApiCallback<ProgressionModels::IncrementStatisticVersionResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListLeaderboardDefinitions(ProgressionModels::ListLeaderboardDefinitionsRequest& request, const ProcessApiCallback<ProgressionModels::ListLeaderboardDefinitionsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListStatisticDefinitions(ProgressionModels::ListStatisticDefinitionsRequest& request, const ProcessApiCallback<ProgressionModels::ListStatisticDefinitionsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlinkLeaderboardFromStatistic(ProgressionModels::UnlinkLeaderboardFromStatisticRequest& request, const ProcessApiCallback<ProgressionModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateLeaderboardEntries(ProgressionModels::UpdateLeaderboardEntriesRequest& request, const ProcessApiCallback<ProgressionModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateStatistics(ProgressionModels::UpdateStatisticsRequest& request, const ProcessApiCallback<ProgressionModels::UpdateStatisticsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        PlayFabProgressionAPI(); // Private constructor, static class should never have an instance
        PlayFabProgressionAPI(const PlayFabProgressionAPI& other); // Private copy-constructor, static class should never have an instance

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
