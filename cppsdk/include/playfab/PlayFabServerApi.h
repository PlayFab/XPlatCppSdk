#pragma once

#ifdef ENABLE_PLAYFABSERVER_API

#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabHttp.h>
#include <playfab/PlayFabServerDataModels.h>

namespace PlayFab
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Server APIs
    /// </summary>
    class PlayFabServerAPI
    {
    public:
        static size_t Update();
        static void ForgetAllCredentials();


        // ------------ Generated API calls
        static void AddCharacterVirtualCurrency(ServerModels::AddCharacterVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyCharacterVirtualCurrencyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddFriend(ServerModels::AddFriendRequest& request, ProcessApiCallback<ServerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddPlayerTag(ServerModels::AddPlayerTagRequest& request, ProcessApiCallback<ServerModels::AddPlayerTagResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddSharedGroupMembers(ServerModels::AddSharedGroupMembersRequest& request, ProcessApiCallback<ServerModels::AddSharedGroupMembersResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddUserVirtualCurrency(ServerModels::AddUserVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AuthenticateSessionTicket(ServerModels::AuthenticateSessionTicketRequest& request, ProcessApiCallback<ServerModels::AuthenticateSessionTicketResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AwardSteamAchievement(ServerModels::AwardSteamAchievementRequest& request, ProcessApiCallback<ServerModels::AwardSteamAchievementResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void BanUsers(ServerModels::BanUsersRequest& request, ProcessApiCallback<ServerModels::BanUsersResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ConsumeItem(ServerModels::ConsumeItemRequest& request, ProcessApiCallback<ServerModels::ConsumeItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateSharedGroup(ServerModels::CreateSharedGroupRequest& request, ProcessApiCallback<ServerModels::CreateSharedGroupResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteCharacterFromUser(ServerModels::DeleteCharacterFromUserRequest& request, ProcessApiCallback<ServerModels::DeleteCharacterFromUserResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeletePlayer(ServerModels::DeletePlayerRequest& request, ProcessApiCallback<ServerModels::DeletePlayerResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteSharedGroup(ServerModels::DeleteSharedGroupRequest& request, ProcessApiCallback<ServerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteUsers(ServerModels::DeleteUsersRequest& request, ProcessApiCallback<ServerModels::DeleteUsersResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeregisterGame(ServerModels::DeregisterGameRequest& request, ProcessApiCallback<ServerModels::DeregisterGameResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void EvaluateRandomResultTable(ServerModels::EvaluateRandomResultTableRequest& request, ProcessApiCallback<ServerModels::EvaluateRandomResultTableResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ExecuteCloudScript(ServerModels::ExecuteCloudScriptServerRequest& request, ProcessApiCallback<ServerModels::ExecuteCloudScriptResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetAllSegments(ServerModels::GetAllSegmentsRequest& request, ProcessApiCallback<ServerModels::GetAllSegmentsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetAllUsersCharacters(ServerModels::ListUsersCharactersRequest& request, ProcessApiCallback<ServerModels::ListUsersCharactersResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCatalogItems(ServerModels::GetCatalogItemsRequest& request, ProcessApiCallback<ServerModels::GetCatalogItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCharacterData(ServerModels::GetCharacterDataRequest& request, ProcessApiCallback<ServerModels::GetCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCharacterInternalData(ServerModels::GetCharacterDataRequest& request, ProcessApiCallback<ServerModels::GetCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCharacterInventory(ServerModels::GetCharacterInventoryRequest& request, ProcessApiCallback<ServerModels::GetCharacterInventoryResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCharacterLeaderboard(ServerModels::GetCharacterLeaderboardRequest& request, ProcessApiCallback<ServerModels::GetCharacterLeaderboardResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCharacterReadOnlyData(ServerModels::GetCharacterDataRequest& request, ProcessApiCallback<ServerModels::GetCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCharacterStatistics(ServerModels::GetCharacterStatisticsRequest& request, ProcessApiCallback<ServerModels::GetCharacterStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetContentDownloadUrl(ServerModels::GetContentDownloadUrlRequest& request, ProcessApiCallback<ServerModels::GetContentDownloadUrlResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetFriendLeaderboard(ServerModels::GetFriendLeaderboardRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetFriendsList(ServerModels::GetFriendsListRequest& request, ProcessApiCallback<ServerModels::GetFriendsListResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetLeaderboard(ServerModels::GetLeaderboardRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetLeaderboardAroundCharacter(ServerModels::GetLeaderboardAroundCharacterRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardAroundCharacterResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetLeaderboardAroundUser(ServerModels::GetLeaderboardAroundUserRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardAroundUserResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetLeaderboardForUserCharacters(ServerModels::GetLeaderboardForUsersCharactersRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardForUsersCharactersResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerCombinedInfo(ServerModels::GetPlayerCombinedInfoRequest& request, ProcessApiCallback<ServerModels::GetPlayerCombinedInfoResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerProfile(ServerModels::GetPlayerProfileRequest& request, ProcessApiCallback<ServerModels::GetPlayerProfileResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerSegments(ServerModels::GetPlayersSegmentsRequest& request, ProcessApiCallback<ServerModels::GetPlayerSegmentsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayersInSegment(ServerModels::GetPlayersInSegmentRequest& request, ProcessApiCallback<ServerModels::GetPlayersInSegmentResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerStatistics(ServerModels::GetPlayerStatisticsRequest& request, ProcessApiCallback<ServerModels::GetPlayerStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerStatisticVersions(ServerModels::GetPlayerStatisticVersionsRequest& request, ProcessApiCallback<ServerModels::GetPlayerStatisticVersionsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerTags(ServerModels::GetPlayerTagsRequest& request, ProcessApiCallback<ServerModels::GetPlayerTagsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayFabIDsFromFacebookIDs(ServerModels::GetPlayFabIDsFromFacebookIDsRequest& request, ProcessApiCallback<ServerModels::GetPlayFabIDsFromFacebookIDsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayFabIDsFromFacebookInstantGamesIds(ServerModels::GetPlayFabIDsFromFacebookInstantGamesIdsRequest& request, ProcessApiCallback<ServerModels::GetPlayFabIDsFromFacebookInstantGamesIdsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayFabIDsFromNintendoSwitchDeviceIds(ServerModels::GetPlayFabIDsFromNintendoSwitchDeviceIdsRequest& request, ProcessApiCallback<ServerModels::GetPlayFabIDsFromNintendoSwitchDeviceIdsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayFabIDsFromSteamIDs(ServerModels::GetPlayFabIDsFromSteamIDsRequest& request, ProcessApiCallback<ServerModels::GetPlayFabIDsFromSteamIDsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPublisherData(ServerModels::GetPublisherDataRequest& request, ProcessApiCallback<ServerModels::GetPublisherDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetRandomResultTables(ServerModels::GetRandomResultTablesRequest& request, ProcessApiCallback<ServerModels::GetRandomResultTablesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetSharedGroupData(ServerModels::GetSharedGroupDataRequest& request, ProcessApiCallback<ServerModels::GetSharedGroupDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetTime(ServerModels::GetTimeRequest& request, ProcessApiCallback<ServerModels::GetTimeResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetTitleData(ServerModels::GetTitleDataRequest& request, ProcessApiCallback<ServerModels::GetTitleDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetTitleInternalData(ServerModels::GetTitleDataRequest& request, ProcessApiCallback<ServerModels::GetTitleDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetTitleNews(ServerModels::GetTitleNewsRequest& request, ProcessApiCallback<ServerModels::GetTitleNewsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserAccountInfo(ServerModels::GetUserAccountInfoRequest& request, ProcessApiCallback<ServerModels::GetUserAccountInfoResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserBans(ServerModels::GetUserBansRequest& request, ProcessApiCallback<ServerModels::GetUserBansResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserInternalData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserInventory(ServerModels::GetUserInventoryRequest& request, ProcessApiCallback<ServerModels::GetUserInventoryResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserPublisherData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserPublisherInternalData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserPublisherReadOnlyData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserReadOnlyData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GrantCharacterToUser(ServerModels::GrantCharacterToUserRequest& request, ProcessApiCallback<ServerModels::GrantCharacterToUserResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GrantItemsToCharacter(ServerModels::GrantItemsToCharacterRequest& request, ProcessApiCallback<ServerModels::GrantItemsToCharacterResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GrantItemsToUser(ServerModels::GrantItemsToUserRequest& request, ProcessApiCallback<ServerModels::GrantItemsToUserResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GrantItemsToUsers(ServerModels::GrantItemsToUsersRequest& request, ProcessApiCallback<ServerModels::GrantItemsToUsersResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ModifyItemUses(ServerModels::ModifyItemUsesRequest& request, ProcessApiCallback<ServerModels::ModifyItemUsesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void MoveItemToCharacterFromCharacter(ServerModels::MoveItemToCharacterFromCharacterRequest& request, ProcessApiCallback<ServerModels::MoveItemToCharacterFromCharacterResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void MoveItemToCharacterFromUser(ServerModels::MoveItemToCharacterFromUserRequest& request, ProcessApiCallback<ServerModels::MoveItemToCharacterFromUserResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void MoveItemToUserFromCharacter(ServerModels::MoveItemToUserFromCharacterRequest& request, ProcessApiCallback<ServerModels::MoveItemToUserFromCharacterResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void NotifyMatchmakerPlayerLeft(ServerModels::NotifyMatchmakerPlayerLeftRequest& request, ProcessApiCallback<ServerModels::NotifyMatchmakerPlayerLeftResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RedeemCoupon(ServerModels::RedeemCouponRequest& request, ProcessApiCallback<ServerModels::RedeemCouponResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RedeemMatchmakerTicket(ServerModels::RedeemMatchmakerTicketRequest& request, ProcessApiCallback<ServerModels::RedeemMatchmakerTicketResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RefreshGameServerInstanceHeartbeat(ServerModels::RefreshGameServerInstanceHeartbeatRequest& request, ProcessApiCallback<ServerModels::RefreshGameServerInstanceHeartbeatResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RegisterGame(ServerModels::RegisterGameRequest& request, ProcessApiCallback<ServerModels::RegisterGameResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemoveFriend(ServerModels::RemoveFriendRequest& request, ProcessApiCallback<ServerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemovePlayerTag(ServerModels::RemovePlayerTagRequest& request, ProcessApiCallback<ServerModels::RemovePlayerTagResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemoveSharedGroupMembers(ServerModels::RemoveSharedGroupMembersRequest& request, ProcessApiCallback<ServerModels::RemoveSharedGroupMembersResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ReportPlayer(ServerModels::ReportPlayerServerRequest& request, ProcessApiCallback<ServerModels::ReportPlayerServerResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RevokeAllBansForUser(ServerModels::RevokeAllBansForUserRequest& request, ProcessApiCallback<ServerModels::RevokeAllBansForUserResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RevokeBans(ServerModels::RevokeBansRequest& request, ProcessApiCallback<ServerModels::RevokeBansResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RevokeInventoryItem(ServerModels::RevokeInventoryItemRequest& request, ProcessApiCallback<ServerModels::RevokeInventoryResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RevokeInventoryItems(ServerModels::RevokeInventoryItemsRequest& request, ProcessApiCallback<ServerModels::RevokeInventoryItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SendCustomAccountRecoveryEmail(ServerModels::SendCustomAccountRecoveryEmailRequest& request, ProcessApiCallback<ServerModels::SendCustomAccountRecoveryEmailResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SendEmailFromTemplate(ServerModels::SendEmailFromTemplateRequest& request, ProcessApiCallback<ServerModels::SendEmailFromTemplateResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SendPushNotification(ServerModels::SendPushNotificationRequest& request, ProcessApiCallback<ServerModels::SendPushNotificationResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetFriendTags(ServerModels::SetFriendTagsRequest& request, ProcessApiCallback<ServerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetGameServerInstanceData(ServerModels::SetGameServerInstanceDataRequest& request, ProcessApiCallback<ServerModels::SetGameServerInstanceDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetGameServerInstanceState(ServerModels::SetGameServerInstanceStateRequest& request, ProcessApiCallback<ServerModels::SetGameServerInstanceStateResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetGameServerInstanceTags(ServerModels::SetGameServerInstanceTagsRequest& request, ProcessApiCallback<ServerModels::SetGameServerInstanceTagsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetPlayerSecret(ServerModels::SetPlayerSecretRequest& request, ProcessApiCallback<ServerModels::SetPlayerSecretResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetPublisherData(ServerModels::SetPublisherDataRequest& request, ProcessApiCallback<ServerModels::SetPublisherDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetTitleData(ServerModels::SetTitleDataRequest& request, ProcessApiCallback<ServerModels::SetTitleDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetTitleInternalData(ServerModels::SetTitleDataRequest& request, ProcessApiCallback<ServerModels::SetTitleDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SubtractCharacterVirtualCurrency(ServerModels::SubtractCharacterVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyCharacterVirtualCurrencyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SubtractUserVirtualCurrency(ServerModels::SubtractUserVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlockContainerInstance(ServerModels::UnlockContainerInstanceRequest& request, ProcessApiCallback<ServerModels::UnlockContainerItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlockContainerItem(ServerModels::UnlockContainerItemRequest& request, ProcessApiCallback<ServerModels::UnlockContainerItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateAvatarUrl(ServerModels::UpdateAvatarUrlRequest& request, ProcessApiCallback<ServerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateBans(ServerModels::UpdateBansRequest& request, ProcessApiCallback<ServerModels::UpdateBansResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateCharacterData(ServerModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateCharacterInternalData(ServerModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateCharacterReadOnlyData(ServerModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateCharacterStatistics(ServerModels::UpdateCharacterStatisticsRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdatePlayerStatistics(ServerModels::UpdatePlayerStatisticsRequest& request, ProcessApiCallback<ServerModels::UpdatePlayerStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateSharedGroupData(ServerModels::UpdateSharedGroupDataRequest& request, ProcessApiCallback<ServerModels::UpdateSharedGroupDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserInternalData(ServerModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserInventoryItemCustomData(ServerModels::UpdateUserInventoryItemDataRequest& request, ProcessApiCallback<ServerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserPublisherData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserPublisherInternalData(ServerModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserPublisherReadOnlyData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserReadOnlyData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void WriteCharacterEvent(ServerModels::WriteServerCharacterEventRequest& request, ProcessApiCallback<ServerModels::WriteEventResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void WritePlayerEvent(ServerModels::WriteServerPlayerEventRequest& request, ProcessApiCallback<ServerModels::WriteEventResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void WriteTitleEvent(ServerModels::WriteTitleEventRequest& request, ProcessApiCallback<ServerModels::WriteEventResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        PlayFabServerAPI(); // Private constructor, static class should never have an instance
        PlayFabServerAPI(const PlayFabServerAPI& other); // Private copy-constructor, static class should never have an instance

        // ------------ Generated result handlers
        static void OnAddCharacterVirtualCurrencyResult(CallRequestContainerBase& request);
        static void OnAddFriendResult(CallRequestContainerBase& request);
        static void OnAddPlayerTagResult(CallRequestContainerBase& request);
        static void OnAddSharedGroupMembersResult(CallRequestContainerBase& request);
        static void OnAddUserVirtualCurrencyResult(CallRequestContainerBase& request);
        static void OnAuthenticateSessionTicketResult(CallRequestContainerBase& request);
        static void OnAwardSteamAchievementResult(CallRequestContainerBase& request);
        static void OnBanUsersResult(CallRequestContainerBase& request);
        static void OnConsumeItemResult(CallRequestContainerBase& request);
        static void OnCreateSharedGroupResult(CallRequestContainerBase& request);
        static void OnDeleteCharacterFromUserResult(CallRequestContainerBase& request);
        static void OnDeletePlayerResult(CallRequestContainerBase& request);
        static void OnDeleteSharedGroupResult(CallRequestContainerBase& request);
        static void OnDeleteUsersResult(CallRequestContainerBase& request);
        static void OnDeregisterGameResult(CallRequestContainerBase& request);
        static void OnEvaluateRandomResultTableResult(CallRequestContainerBase& request);
        static void OnExecuteCloudScriptResult(CallRequestContainerBase& request);
        static void OnGetAllSegmentsResult(CallRequestContainerBase& request);
        static void OnGetAllUsersCharactersResult(CallRequestContainerBase& request);
        static void OnGetCatalogItemsResult(CallRequestContainerBase& request);
        static void OnGetCharacterDataResult(CallRequestContainerBase& request);
        static void OnGetCharacterInternalDataResult(CallRequestContainerBase& request);
        static void OnGetCharacterInventoryResult(CallRequestContainerBase& request);
        static void OnGetCharacterLeaderboardResult(CallRequestContainerBase& request);
        static void OnGetCharacterReadOnlyDataResult(CallRequestContainerBase& request);
        static void OnGetCharacterStatisticsResult(CallRequestContainerBase& request);
        static void OnGetContentDownloadUrlResult(CallRequestContainerBase& request);
        static void OnGetFriendLeaderboardResult(CallRequestContainerBase& request);
        static void OnGetFriendsListResult(CallRequestContainerBase& request);
        static void OnGetLeaderboardResult(CallRequestContainerBase& request);
        static void OnGetLeaderboardAroundCharacterResult(CallRequestContainerBase& request);
        static void OnGetLeaderboardAroundUserResult(CallRequestContainerBase& request);
        static void OnGetLeaderboardForUserCharactersResult(CallRequestContainerBase& request);
        static void OnGetPlayerCombinedInfoResult(CallRequestContainerBase& request);
        static void OnGetPlayerProfileResult(CallRequestContainerBase& request);
        static void OnGetPlayerSegmentsResult(CallRequestContainerBase& request);
        static void OnGetPlayersInSegmentResult(CallRequestContainerBase& request);
        static void OnGetPlayerStatisticsResult(CallRequestContainerBase& request);
        static void OnGetPlayerStatisticVersionsResult(CallRequestContainerBase& request);
        static void OnGetPlayerTagsResult(CallRequestContainerBase& request);
        static void OnGetPlayFabIDsFromFacebookIDsResult(CallRequestContainerBase& request);
        static void OnGetPlayFabIDsFromFacebookInstantGamesIdsResult(CallRequestContainerBase& request);
        static void OnGetPlayFabIDsFromNintendoSwitchDeviceIdsResult(CallRequestContainerBase& request);
        static void OnGetPlayFabIDsFromSteamIDsResult(CallRequestContainerBase& request);
        static void OnGetPublisherDataResult(CallRequestContainerBase& request);
        static void OnGetRandomResultTablesResult(CallRequestContainerBase& request);
        static void OnGetSharedGroupDataResult(CallRequestContainerBase& request);
        static void OnGetTimeResult(CallRequestContainerBase& request);
        static void OnGetTitleDataResult(CallRequestContainerBase& request);
        static void OnGetTitleInternalDataResult(CallRequestContainerBase& request);
        static void OnGetTitleNewsResult(CallRequestContainerBase& request);
        static void OnGetUserAccountInfoResult(CallRequestContainerBase& request);
        static void OnGetUserBansResult(CallRequestContainerBase& request);
        static void OnGetUserDataResult(CallRequestContainerBase& request);
        static void OnGetUserInternalDataResult(CallRequestContainerBase& request);
        static void OnGetUserInventoryResult(CallRequestContainerBase& request);
        static void OnGetUserPublisherDataResult(CallRequestContainerBase& request);
        static void OnGetUserPublisherInternalDataResult(CallRequestContainerBase& request);
        static void OnGetUserPublisherReadOnlyDataResult(CallRequestContainerBase& request);
        static void OnGetUserReadOnlyDataResult(CallRequestContainerBase& request);
        static void OnGrantCharacterToUserResult(CallRequestContainerBase& request);
        static void OnGrantItemsToCharacterResult(CallRequestContainerBase& request);
        static void OnGrantItemsToUserResult(CallRequestContainerBase& request);
        static void OnGrantItemsToUsersResult(CallRequestContainerBase& request);
        static void OnModifyItemUsesResult(CallRequestContainerBase& request);
        static void OnMoveItemToCharacterFromCharacterResult(CallRequestContainerBase& request);
        static void OnMoveItemToCharacterFromUserResult(CallRequestContainerBase& request);
        static void OnMoveItemToUserFromCharacterResult(CallRequestContainerBase& request);
        static void OnNotifyMatchmakerPlayerLeftResult(CallRequestContainerBase& request);
        static void OnRedeemCouponResult(CallRequestContainerBase& request);
        static void OnRedeemMatchmakerTicketResult(CallRequestContainerBase& request);
        static void OnRefreshGameServerInstanceHeartbeatResult(CallRequestContainerBase& request);
        static void OnRegisterGameResult(CallRequestContainerBase& request);
        static void OnRemoveFriendResult(CallRequestContainerBase& request);
        static void OnRemovePlayerTagResult(CallRequestContainerBase& request);
        static void OnRemoveSharedGroupMembersResult(CallRequestContainerBase& request);
        static void OnReportPlayerResult(CallRequestContainerBase& request);
        static void OnRevokeAllBansForUserResult(CallRequestContainerBase& request);
        static void OnRevokeBansResult(CallRequestContainerBase& request);
        static void OnRevokeInventoryItemResult(CallRequestContainerBase& request);
        static void OnRevokeInventoryItemsResult(CallRequestContainerBase& request);
        static void OnSendCustomAccountRecoveryEmailResult(CallRequestContainerBase& request);
        static void OnSendEmailFromTemplateResult(CallRequestContainerBase& request);
        static void OnSendPushNotificationResult(CallRequestContainerBase& request);
        static void OnSetFriendTagsResult(CallRequestContainerBase& request);
        static void OnSetGameServerInstanceDataResult(CallRequestContainerBase& request);
        static void OnSetGameServerInstanceStateResult(CallRequestContainerBase& request);
        static void OnSetGameServerInstanceTagsResult(CallRequestContainerBase& request);
        static void OnSetPlayerSecretResult(CallRequestContainerBase& request);
        static void OnSetPublisherDataResult(CallRequestContainerBase& request);
        static void OnSetTitleDataResult(CallRequestContainerBase& request);
        static void OnSetTitleInternalDataResult(CallRequestContainerBase& request);
        static void OnSubtractCharacterVirtualCurrencyResult(CallRequestContainerBase& request);
        static void OnSubtractUserVirtualCurrencyResult(CallRequestContainerBase& request);
        static void OnUnlockContainerInstanceResult(CallRequestContainerBase& request);
        static void OnUnlockContainerItemResult(CallRequestContainerBase& request);
        static void OnUpdateAvatarUrlResult(CallRequestContainerBase& request);
        static void OnUpdateBansResult(CallRequestContainerBase& request);
        static void OnUpdateCharacterDataResult(CallRequestContainerBase& request);
        static void OnUpdateCharacterInternalDataResult(CallRequestContainerBase& request);
        static void OnUpdateCharacterReadOnlyDataResult(CallRequestContainerBase& request);
        static void OnUpdateCharacterStatisticsResult(CallRequestContainerBase& request);
        static void OnUpdatePlayerStatisticsResult(CallRequestContainerBase& request);
        static void OnUpdateSharedGroupDataResult(CallRequestContainerBase& request);
        static void OnUpdateUserDataResult(CallRequestContainerBase& request);
        static void OnUpdateUserInternalDataResult(CallRequestContainerBase& request);
        static void OnUpdateUserInventoryItemCustomDataResult(CallRequestContainerBase& request);
        static void OnUpdateUserPublisherDataResult(CallRequestContainerBase& request);
        static void OnUpdateUserPublisherInternalDataResult(CallRequestContainerBase& request);
        static void OnUpdateUserPublisherReadOnlyDataResult(CallRequestContainerBase& request);
        static void OnUpdateUserReadOnlyDataResult(CallRequestContainerBase& request);
        static void OnWriteCharacterEventResult(CallRequestContainerBase& request);
        static void OnWritePlayerEventResult(CallRequestContainerBase& request);
        static void OnWriteTitleEventResult(CallRequestContainerBase& request);

    };
}

#endif
