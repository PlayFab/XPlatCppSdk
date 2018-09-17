#pragma once

#ifdef ENABLE_PLAYFABADMIN_API

#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabHttp.h>
#include <playfab/PlayFabAdminDataModels.h>

namespace PlayFab
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Admin APIs
    /// </summary>
    class PlayFabAdminAPI
    {
    public:
        static size_t Update();
        static void ForgetAllCredentials();


        // ------------ Generated API calls
        static void AbortTaskInstance(AdminModels::AbortTaskInstanceRequest& request, ProcessApiCallback<AdminModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddNews(AdminModels::AddNewsRequest& request, ProcessApiCallback<AdminModels::AddNewsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddPlayerTag(AdminModels::AddPlayerTagRequest& request, ProcessApiCallback<AdminModels::AddPlayerTagResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddServerBuild(AdminModels::AddServerBuildRequest& request, ProcessApiCallback<AdminModels::AddServerBuildResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddUserVirtualCurrency(AdminModels::AddUserVirtualCurrencyRequest& request, ProcessApiCallback<AdminModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddVirtualCurrencyTypes(AdminModels::AddVirtualCurrencyTypesRequest& request, ProcessApiCallback<AdminModels::BlankResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void BanUsers(AdminModels::BanUsersRequest& request, ProcessApiCallback<AdminModels::BanUsersResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CheckLimitedEditionItemAvailability(AdminModels::CheckLimitedEditionItemAvailabilityRequest& request, ProcessApiCallback<AdminModels::CheckLimitedEditionItemAvailabilityResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateActionsOnPlayersInSegmentTask(AdminModels::CreateActionsOnPlayerSegmentTaskRequest& request, ProcessApiCallback<AdminModels::CreateTaskResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateCloudScriptTask(AdminModels::CreateCloudScriptTaskRequest& request, ProcessApiCallback<AdminModels::CreateTaskResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreatePlayerSharedSecret(AdminModels::CreatePlayerSharedSecretRequest& request, ProcessApiCallback<AdminModels::CreatePlayerSharedSecretResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreatePlayerStatisticDefinition(AdminModels::CreatePlayerStatisticDefinitionRequest& request, ProcessApiCallback<AdminModels::CreatePlayerStatisticDefinitionResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteContent(AdminModels::DeleteContentRequest& request, ProcessApiCallback<AdminModels::BlankResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteMasterPlayerAccount(AdminModels::DeleteMasterPlayerAccountRequest& request, ProcessApiCallback<AdminModels::DeleteMasterPlayerAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeletePlayer(AdminModels::DeletePlayerRequest& request, ProcessApiCallback<AdminModels::DeletePlayerResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeletePlayerSharedSecret(AdminModels::DeletePlayerSharedSecretRequest& request, ProcessApiCallback<AdminModels::DeletePlayerSharedSecretResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteStore(AdminModels::DeleteStoreRequest& request, ProcessApiCallback<AdminModels::DeleteStoreResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteTask(AdminModels::DeleteTaskRequest& request, ProcessApiCallback<AdminModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteTitle(AdminModels::DeleteTitleRequest& request, ProcessApiCallback<AdminModels::DeleteTitleResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ExportMasterPlayerData(AdminModels::ExportMasterPlayerDataRequest& request, ProcessApiCallback<AdminModels::ExportMasterPlayerDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetActionsOnPlayersInSegmentTaskInstance(AdminModels::GetTaskInstanceRequest& request, ProcessApiCallback<AdminModels::GetActionsOnPlayersInSegmentTaskInstanceResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetAllSegments(AdminModels::GetAllSegmentsRequest& request, ProcessApiCallback<AdminModels::GetAllSegmentsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCatalogItems(AdminModels::GetCatalogItemsRequest& request, ProcessApiCallback<AdminModels::GetCatalogItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCloudScriptRevision(AdminModels::GetCloudScriptRevisionRequest& request, ProcessApiCallback<AdminModels::GetCloudScriptRevisionResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCloudScriptTaskInstance(AdminModels::GetTaskInstanceRequest& request, ProcessApiCallback<AdminModels::GetCloudScriptTaskInstanceResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCloudScriptVersions(AdminModels::GetCloudScriptVersionsRequest& request, ProcessApiCallback<AdminModels::GetCloudScriptVersionsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetContentList(AdminModels::GetContentListRequest& request, ProcessApiCallback<AdminModels::GetContentListResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetContentUploadUrl(AdminModels::GetContentUploadUrlRequest& request, ProcessApiCallback<AdminModels::GetContentUploadUrlResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetDataReport(AdminModels::GetDataReportRequest& request, ProcessApiCallback<AdminModels::GetDataReportResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetMatchmakerGameInfo(AdminModels::GetMatchmakerGameInfoRequest& request, ProcessApiCallback<AdminModels::GetMatchmakerGameInfoResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetMatchmakerGameModes(AdminModels::GetMatchmakerGameModesRequest& request, ProcessApiCallback<AdminModels::GetMatchmakerGameModesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetMatchmakingQueue(AdminModels::GetMatchmakingQueueRequest& request, ProcessApiCallback<AdminModels::GetMatchmakingQueueResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayedTitleList(AdminModels::GetPlayedTitleListRequest& request, ProcessApiCallback<AdminModels::GetPlayedTitleListResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerIdFromAuthToken(AdminModels::GetPlayerIdFromAuthTokenRequest& request, ProcessApiCallback<AdminModels::GetPlayerIdFromAuthTokenResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerProfile(AdminModels::GetPlayerProfileRequest& request, ProcessApiCallback<AdminModels::GetPlayerProfileResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerSegments(AdminModels::GetPlayersSegmentsRequest& request, ProcessApiCallback<AdminModels::GetPlayerSegmentsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerSharedSecrets(AdminModels::GetPlayerSharedSecretsRequest& request, ProcessApiCallback<AdminModels::GetPlayerSharedSecretsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayersInSegment(AdminModels::GetPlayersInSegmentRequest& request, ProcessApiCallback<AdminModels::GetPlayersInSegmentResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerStatisticDefinitions(AdminModels::GetPlayerStatisticDefinitionsRequest& request, ProcessApiCallback<AdminModels::GetPlayerStatisticDefinitionsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerStatisticVersions(AdminModels::GetPlayerStatisticVersionsRequest& request, ProcessApiCallback<AdminModels::GetPlayerStatisticVersionsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerTags(AdminModels::GetPlayerTagsRequest& request, ProcessApiCallback<AdminModels::GetPlayerTagsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPolicy(AdminModels::GetPolicyRequest& request, ProcessApiCallback<AdminModels::GetPolicyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPublisherData(AdminModels::GetPublisherDataRequest& request, ProcessApiCallback<AdminModels::GetPublisherDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetRandomResultTables(AdminModels::GetRandomResultTablesRequest& request, ProcessApiCallback<AdminModels::GetRandomResultTablesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetServerBuildInfo(AdminModels::GetServerBuildInfoRequest& request, ProcessApiCallback<AdminModels::GetServerBuildInfoResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetServerBuildUploadUrl(AdminModels::GetServerBuildUploadURLRequest& request, ProcessApiCallback<AdminModels::GetServerBuildUploadURLResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetStoreItems(AdminModels::GetStoreItemsRequest& request, ProcessApiCallback<AdminModels::GetStoreItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetTaskInstances(AdminModels::GetTaskInstancesRequest& request, ProcessApiCallback<AdminModels::GetTaskInstancesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetTasks(AdminModels::GetTasksRequest& request, ProcessApiCallback<AdminModels::GetTasksResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetTitleData(AdminModels::GetTitleDataRequest& request, ProcessApiCallback<AdminModels::GetTitleDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetTitleInternalData(AdminModels::GetTitleDataRequest& request, ProcessApiCallback<AdminModels::GetTitleDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserAccountInfo(AdminModels::LookupUserAccountInfoRequest& request, ProcessApiCallback<AdminModels::LookupUserAccountInfoResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserBans(AdminModels::GetUserBansRequest& request, ProcessApiCallback<AdminModels::GetUserBansResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserInternalData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserInventory(AdminModels::GetUserInventoryRequest& request, ProcessApiCallback<AdminModels::GetUserInventoryResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserPublisherData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserPublisherInternalData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserPublisherReadOnlyData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserReadOnlyData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GrantItemsToUsers(AdminModels::GrantItemsToUsersRequest& request, ProcessApiCallback<AdminModels::GrantItemsToUsersResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void IncrementLimitedEditionItemAvailability(AdminModels::IncrementLimitedEditionItemAvailabilityRequest& request, ProcessApiCallback<AdminModels::IncrementLimitedEditionItemAvailabilityResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void IncrementPlayerStatisticVersion(AdminModels::IncrementPlayerStatisticVersionRequest& request, ProcessApiCallback<AdminModels::IncrementPlayerStatisticVersionResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListMatchmakingQueues(AdminModels::ListMatchmakingQueuesRequest& request, ProcessApiCallback<AdminModels::ListMatchmakingQueuesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListServerBuilds(AdminModels::ListBuildsRequest& request, ProcessApiCallback<AdminModels::ListBuildsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListVirtualCurrencyTypes(AdminModels::ListVirtualCurrencyTypesRequest& request, ProcessApiCallback<AdminModels::ListVirtualCurrencyTypesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ModifyMatchmakerGameModes(AdminModels::ModifyMatchmakerGameModesRequest& request, ProcessApiCallback<AdminModels::ModifyMatchmakerGameModesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ModifyServerBuild(AdminModels::ModifyServerBuildRequest& request, ProcessApiCallback<AdminModels::ModifyServerBuildResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RefundPurchase(AdminModels::RefundPurchaseRequest& request, ProcessApiCallback<AdminModels::RefundPurchaseResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemoveMatchmakingQueue(AdminModels::RemoveMatchmakingQueueRequest& request, ProcessApiCallback<AdminModels::RemoveMatchmakingQueueResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemovePlayerTag(AdminModels::RemovePlayerTagRequest& request, ProcessApiCallback<AdminModels::RemovePlayerTagResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemoveServerBuild(AdminModels::RemoveServerBuildRequest& request, ProcessApiCallback<AdminModels::RemoveServerBuildResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemoveVirtualCurrencyTypes(AdminModels::RemoveVirtualCurrencyTypesRequest& request, ProcessApiCallback<AdminModels::BlankResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ResetCharacterStatistics(AdminModels::ResetCharacterStatisticsRequest& request, ProcessApiCallback<AdminModels::ResetCharacterStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ResetPassword(AdminModels::ResetPasswordRequest& request, ProcessApiCallback<AdminModels::ResetPasswordResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ResetUserStatistics(AdminModels::ResetUserStatisticsRequest& request, ProcessApiCallback<AdminModels::ResetUserStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ResolvePurchaseDispute(AdminModels::ResolvePurchaseDisputeRequest& request, ProcessApiCallback<AdminModels::ResolvePurchaseDisputeResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RevokeAllBansForUser(AdminModels::RevokeAllBansForUserRequest& request, ProcessApiCallback<AdminModels::RevokeAllBansForUserResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RevokeBans(AdminModels::RevokeBansRequest& request, ProcessApiCallback<AdminModels::RevokeBansResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RevokeInventoryItem(AdminModels::RevokeInventoryItemRequest& request, ProcessApiCallback<AdminModels::RevokeInventoryResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RevokeInventoryItems(AdminModels::RevokeInventoryItemsRequest& request, ProcessApiCallback<AdminModels::RevokeInventoryItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RunTask(AdminModels::RunTaskRequest& request, ProcessApiCallback<AdminModels::RunTaskResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SendAccountRecoveryEmail(AdminModels::SendAccountRecoveryEmailRequest& request, ProcessApiCallback<AdminModels::SendAccountRecoveryEmailResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetCatalogItems(AdminModels::UpdateCatalogItemsRequest& request, ProcessApiCallback<AdminModels::UpdateCatalogItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetMatchmakingQueue(AdminModels::SetMatchmakingQueueRequest& request, ProcessApiCallback<AdminModels::SetMatchmakingQueueResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetPlayerSecret(AdminModels::SetPlayerSecretRequest& request, ProcessApiCallback<AdminModels::SetPlayerSecretResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetPublishedRevision(AdminModels::SetPublishedRevisionRequest& request, ProcessApiCallback<AdminModels::SetPublishedRevisionResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetPublisherData(AdminModels::SetPublisherDataRequest& request, ProcessApiCallback<AdminModels::SetPublisherDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetStoreItems(AdminModels::UpdateStoreItemsRequest& request, ProcessApiCallback<AdminModels::UpdateStoreItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetTitleData(AdminModels::SetTitleDataRequest& request, ProcessApiCallback<AdminModels::SetTitleDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetTitleInternalData(AdminModels::SetTitleDataRequest& request, ProcessApiCallback<AdminModels::SetTitleDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetupPushNotification(AdminModels::SetupPushNotificationRequest& request, ProcessApiCallback<AdminModels::SetupPushNotificationResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SubtractUserVirtualCurrency(AdminModels::SubtractUserVirtualCurrencyRequest& request, ProcessApiCallback<AdminModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateBans(AdminModels::UpdateBansRequest& request, ProcessApiCallback<AdminModels::UpdateBansResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateCatalogItems(AdminModels::UpdateCatalogItemsRequest& request, ProcessApiCallback<AdminModels::UpdateCatalogItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateCloudScript(AdminModels::UpdateCloudScriptRequest& request, ProcessApiCallback<AdminModels::UpdateCloudScriptResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdatePlayerSharedSecret(AdminModels::UpdatePlayerSharedSecretRequest& request, ProcessApiCallback<AdminModels::UpdatePlayerSharedSecretResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdatePlayerStatisticDefinition(AdminModels::UpdatePlayerStatisticDefinitionRequest& request, ProcessApiCallback<AdminModels::UpdatePlayerStatisticDefinitionResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdatePolicy(AdminModels::UpdatePolicyRequest& request, ProcessApiCallback<AdminModels::UpdatePolicyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateRandomResultTables(AdminModels::UpdateRandomResultTablesRequest& request, ProcessApiCallback<AdminModels::UpdateRandomResultTablesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateStoreItems(AdminModels::UpdateStoreItemsRequest& request, ProcessApiCallback<AdminModels::UpdateStoreItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateTask(AdminModels::UpdateTaskRequest& request, ProcessApiCallback<AdminModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserData(AdminModels::UpdateUserDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserInternalData(AdminModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserPublisherData(AdminModels::UpdateUserDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserPublisherInternalData(AdminModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserPublisherReadOnlyData(AdminModels::UpdateUserDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserReadOnlyData(AdminModels::UpdateUserDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserTitleDisplayName(AdminModels::UpdateUserTitleDisplayNameRequest& request, ProcessApiCallback<AdminModels::UpdateUserTitleDisplayNameResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        PlayFabAdminAPI(); // Private constructor, static class should never have an instance
        PlayFabAdminAPI(const PlayFabAdminAPI& other); // Private copy-constructor, static class should never have an instance

        // ------------ Generated result handlers
        static void OnAbortTaskInstanceResult(CallRequestContainerBase& request);
        static void OnAddNewsResult(CallRequestContainerBase& request);
        static void OnAddPlayerTagResult(CallRequestContainerBase& request);
        static void OnAddServerBuildResult(CallRequestContainerBase& request);
        static void OnAddUserVirtualCurrencyResult(CallRequestContainerBase& request);
        static void OnAddVirtualCurrencyTypesResult(CallRequestContainerBase& request);
        static void OnBanUsersResult(CallRequestContainerBase& request);
        static void OnCheckLimitedEditionItemAvailabilityResult(CallRequestContainerBase& request);
        static void OnCreateActionsOnPlayersInSegmentTaskResult(CallRequestContainerBase& request);
        static void OnCreateCloudScriptTaskResult(CallRequestContainerBase& request);
        static void OnCreatePlayerSharedSecretResult(CallRequestContainerBase& request);
        static void OnCreatePlayerStatisticDefinitionResult(CallRequestContainerBase& request);
        static void OnDeleteContentResult(CallRequestContainerBase& request);
        static void OnDeleteMasterPlayerAccountResult(CallRequestContainerBase& request);
        static void OnDeletePlayerResult(CallRequestContainerBase& request);
        static void OnDeletePlayerSharedSecretResult(CallRequestContainerBase& request);
        static void OnDeleteStoreResult(CallRequestContainerBase& request);
        static void OnDeleteTaskResult(CallRequestContainerBase& request);
        static void OnDeleteTitleResult(CallRequestContainerBase& request);
        static void OnExportMasterPlayerDataResult(CallRequestContainerBase& request);
        static void OnGetActionsOnPlayersInSegmentTaskInstanceResult(CallRequestContainerBase& request);
        static void OnGetAllSegmentsResult(CallRequestContainerBase& request);
        static void OnGetCatalogItemsResult(CallRequestContainerBase& request);
        static void OnGetCloudScriptRevisionResult(CallRequestContainerBase& request);
        static void OnGetCloudScriptTaskInstanceResult(CallRequestContainerBase& request);
        static void OnGetCloudScriptVersionsResult(CallRequestContainerBase& request);
        static void OnGetContentListResult(CallRequestContainerBase& request);
        static void OnGetContentUploadUrlResult(CallRequestContainerBase& request);
        static void OnGetDataReportResult(CallRequestContainerBase& request);
        static void OnGetMatchmakerGameInfoResult(CallRequestContainerBase& request);
        static void OnGetMatchmakerGameModesResult(CallRequestContainerBase& request);
        static void OnGetMatchmakingQueueResult(CallRequestContainerBase& request);
        static void OnGetPlayedTitleListResult(CallRequestContainerBase& request);
        static void OnGetPlayerIdFromAuthTokenResult(CallRequestContainerBase& request);
        static void OnGetPlayerProfileResult(CallRequestContainerBase& request);
        static void OnGetPlayerSegmentsResult(CallRequestContainerBase& request);
        static void OnGetPlayerSharedSecretsResult(CallRequestContainerBase& request);
        static void OnGetPlayersInSegmentResult(CallRequestContainerBase& request);
        static void OnGetPlayerStatisticDefinitionsResult(CallRequestContainerBase& request);
        static void OnGetPlayerStatisticVersionsResult(CallRequestContainerBase& request);
        static void OnGetPlayerTagsResult(CallRequestContainerBase& request);
        static void OnGetPolicyResult(CallRequestContainerBase& request);
        static void OnGetPublisherDataResult(CallRequestContainerBase& request);
        static void OnGetRandomResultTablesResult(CallRequestContainerBase& request);
        static void OnGetServerBuildInfoResult(CallRequestContainerBase& request);
        static void OnGetServerBuildUploadUrlResult(CallRequestContainerBase& request);
        static void OnGetStoreItemsResult(CallRequestContainerBase& request);
        static void OnGetTaskInstancesResult(CallRequestContainerBase& request);
        static void OnGetTasksResult(CallRequestContainerBase& request);
        static void OnGetTitleDataResult(CallRequestContainerBase& request);
        static void OnGetTitleInternalDataResult(CallRequestContainerBase& request);
        static void OnGetUserAccountInfoResult(CallRequestContainerBase& request);
        static void OnGetUserBansResult(CallRequestContainerBase& request);
        static void OnGetUserDataResult(CallRequestContainerBase& request);
        static void OnGetUserInternalDataResult(CallRequestContainerBase& request);
        static void OnGetUserInventoryResult(CallRequestContainerBase& request);
        static void OnGetUserPublisherDataResult(CallRequestContainerBase& request);
        static void OnGetUserPublisherInternalDataResult(CallRequestContainerBase& request);
        static void OnGetUserPublisherReadOnlyDataResult(CallRequestContainerBase& request);
        static void OnGetUserReadOnlyDataResult(CallRequestContainerBase& request);
        static void OnGrantItemsToUsersResult(CallRequestContainerBase& request);
        static void OnIncrementLimitedEditionItemAvailabilityResult(CallRequestContainerBase& request);
        static void OnIncrementPlayerStatisticVersionResult(CallRequestContainerBase& request);
        static void OnListMatchmakingQueuesResult(CallRequestContainerBase& request);
        static void OnListServerBuildsResult(CallRequestContainerBase& request);
        static void OnListVirtualCurrencyTypesResult(CallRequestContainerBase& request);
        static void OnModifyMatchmakerGameModesResult(CallRequestContainerBase& request);
        static void OnModifyServerBuildResult(CallRequestContainerBase& request);
        static void OnRefundPurchaseResult(CallRequestContainerBase& request);
        static void OnRemoveMatchmakingQueueResult(CallRequestContainerBase& request);
        static void OnRemovePlayerTagResult(CallRequestContainerBase& request);
        static void OnRemoveServerBuildResult(CallRequestContainerBase& request);
        static void OnRemoveVirtualCurrencyTypesResult(CallRequestContainerBase& request);
        static void OnResetCharacterStatisticsResult(CallRequestContainerBase& request);
        static void OnResetPasswordResult(CallRequestContainerBase& request);
        static void OnResetUserStatisticsResult(CallRequestContainerBase& request);
        static void OnResolvePurchaseDisputeResult(CallRequestContainerBase& request);
        static void OnRevokeAllBansForUserResult(CallRequestContainerBase& request);
        static void OnRevokeBansResult(CallRequestContainerBase& request);
        static void OnRevokeInventoryItemResult(CallRequestContainerBase& request);
        static void OnRevokeInventoryItemsResult(CallRequestContainerBase& request);
        static void OnRunTaskResult(CallRequestContainerBase& request);
        static void OnSendAccountRecoveryEmailResult(CallRequestContainerBase& request);
        static void OnSetCatalogItemsResult(CallRequestContainerBase& request);
        static void OnSetMatchmakingQueueResult(CallRequestContainerBase& request);
        static void OnSetPlayerSecretResult(CallRequestContainerBase& request);
        static void OnSetPublishedRevisionResult(CallRequestContainerBase& request);
        static void OnSetPublisherDataResult(CallRequestContainerBase& request);
        static void OnSetStoreItemsResult(CallRequestContainerBase& request);
        static void OnSetTitleDataResult(CallRequestContainerBase& request);
        static void OnSetTitleInternalDataResult(CallRequestContainerBase& request);
        static void OnSetupPushNotificationResult(CallRequestContainerBase& request);
        static void OnSubtractUserVirtualCurrencyResult(CallRequestContainerBase& request);
        static void OnUpdateBansResult(CallRequestContainerBase& request);
        static void OnUpdateCatalogItemsResult(CallRequestContainerBase& request);
        static void OnUpdateCloudScriptResult(CallRequestContainerBase& request);
        static void OnUpdatePlayerSharedSecretResult(CallRequestContainerBase& request);
        static void OnUpdatePlayerStatisticDefinitionResult(CallRequestContainerBase& request);
        static void OnUpdatePolicyResult(CallRequestContainerBase& request);
        static void OnUpdateRandomResultTablesResult(CallRequestContainerBase& request);
        static void OnUpdateStoreItemsResult(CallRequestContainerBase& request);
        static void OnUpdateTaskResult(CallRequestContainerBase& request);
        static void OnUpdateUserDataResult(CallRequestContainerBase& request);
        static void OnUpdateUserInternalDataResult(CallRequestContainerBase& request);
        static void OnUpdateUserPublisherDataResult(CallRequestContainerBase& request);
        static void OnUpdateUserPublisherInternalDataResult(CallRequestContainerBase& request);
        static void OnUpdateUserPublisherReadOnlyDataResult(CallRequestContainerBase& request);
        static void OnUpdateUserReadOnlyDataResult(CallRequestContainerBase& request);
        static void OnUpdateUserTitleDisplayNameResult(CallRequestContainerBase& request);

    };
}

#endif
