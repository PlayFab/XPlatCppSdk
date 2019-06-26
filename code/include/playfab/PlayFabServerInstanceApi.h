#pragma once

#ifdef ENABLE_PLAYFABSERVER_API

#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabApiSettings.h>
#include <playfab/PlayFabAuthenticationContext.h>
#include <playfab/PlayFabServerDataModels.h>
#include <memory>

#ifndef PLAYFAB_PLATFORM_PLAYSTATION // Issue 32699
namespace PlayFab
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Server APIs
    /// </summary>
    class PlayFabServerInstanceAPI
    {
    private:
        std::shared_ptr<PlayFabApiSettings> settings;
        std::shared_ptr<PlayFabAuthenticationContext> authContext;

    public:
        PlayFabServerInstanceAPI();
        explicit PlayFabServerInstanceAPI(std::shared_ptr<PlayFabApiSettings> apiSettings);
        explicit PlayFabServerInstanceAPI(std::shared_ptr<PlayFabAuthenticationContext> authenticationContext);
        PlayFabServerInstanceAPI(std::shared_ptr<PlayFabApiSettings> apiSettings, std::shared_ptr<PlayFabAuthenticationContext> authenticationContext);
        ~PlayFabServerInstanceAPI();
        PlayFabServerInstanceAPI(const PlayFabServerInstanceAPI& source) = delete; // disable copy
        PlayFabServerInstanceAPI(PlayFabServerInstanceAPI&&) = delete; // disable move
        PlayFabServerInstanceAPI& operator=(const PlayFabServerInstanceAPI& source) = delete; // disable assignment
        PlayFabServerInstanceAPI& operator=(PlayFabServerInstanceAPI&& other) = delete; // disable move assignment

        std::shared_ptr<PlayFabApiSettings> GetSettings() const;
        void SetSettings(std::shared_ptr<PlayFabApiSettings> apiSettings);
        std::shared_ptr<PlayFabAuthenticationContext> GetAuthenticationContext() const;
        void SetAuthenticationContext(std::shared_ptr<PlayFabAuthenticationContext> authenticationContext);
        size_t Update();
        void ForgetAllCredentials();

        // ------------ Generated API calls
        void AddCharacterVirtualCurrency(ServerModels::AddCharacterVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyCharacterVirtualCurrencyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void AddFriend(ServerModels::AddFriendRequest& request, ProcessApiCallback<ServerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void AddGenericID(ServerModels::AddGenericIDRequest& request, ProcessApiCallback<ServerModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void AddPlayerTag(ServerModels::AddPlayerTagRequest& request, ProcessApiCallback<ServerModels::AddPlayerTagResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void AddSharedGroupMembers(ServerModels::AddSharedGroupMembersRequest& request, ProcessApiCallback<ServerModels::AddSharedGroupMembersResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void AddUserVirtualCurrency(ServerModels::AddUserVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void AuthenticateSessionTicket(ServerModels::AuthenticateSessionTicketRequest& request, ProcessApiCallback<ServerModels::AuthenticateSessionTicketResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void AwardSteamAchievement(ServerModels::AwardSteamAchievementRequest& request, ProcessApiCallback<ServerModels::AwardSteamAchievementResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void BanUsers(ServerModels::BanUsersRequest& request, ProcessApiCallback<ServerModels::BanUsersResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ConsumeItem(ServerModels::ConsumeItemRequest& request, ProcessApiCallback<ServerModels::ConsumeItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateSharedGroup(ServerModels::CreateSharedGroupRequest& request, ProcessApiCallback<ServerModels::CreateSharedGroupResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteCharacterFromUser(ServerModels::DeleteCharacterFromUserRequest& request, ProcessApiCallback<ServerModels::DeleteCharacterFromUserResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeletePlayer(ServerModels::DeletePlayerRequest& request, ProcessApiCallback<ServerModels::DeletePlayerResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeletePushNotificationTemplate(ServerModels::DeletePushNotificationTemplateRequest& request, ProcessApiCallback<ServerModels::DeletePushNotificationTemplateResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteSharedGroup(ServerModels::DeleteSharedGroupRequest& request, ProcessApiCallback<ServerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeregisterGame(ServerModels::DeregisterGameRequest& request, ProcessApiCallback<ServerModels::DeregisterGameResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void EvaluateRandomResultTable(ServerModels::EvaluateRandomResultTableRequest& request, ProcessApiCallback<ServerModels::EvaluateRandomResultTableResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ExecuteCloudScript(ServerModels::ExecuteCloudScriptServerRequest& request, ProcessApiCallback<ServerModels::ExecuteCloudScriptResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetAllSegments(ServerModels::GetAllSegmentsRequest& request, ProcessApiCallback<ServerModels::GetAllSegmentsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetAllUsersCharacters(ServerModels::ListUsersCharactersRequest& request, ProcessApiCallback<ServerModels::ListUsersCharactersResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetCatalogItems(ServerModels::GetCatalogItemsRequest& request, ProcessApiCallback<ServerModels::GetCatalogItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetCharacterData(ServerModels::GetCharacterDataRequest& request, ProcessApiCallback<ServerModels::GetCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetCharacterInternalData(ServerModels::GetCharacterDataRequest& request, ProcessApiCallback<ServerModels::GetCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetCharacterInventory(ServerModels::GetCharacterInventoryRequest& request, ProcessApiCallback<ServerModels::GetCharacterInventoryResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetCharacterLeaderboard(ServerModels::GetCharacterLeaderboardRequest& request, ProcessApiCallback<ServerModels::GetCharacterLeaderboardResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetCharacterReadOnlyData(ServerModels::GetCharacterDataRequest& request, ProcessApiCallback<ServerModels::GetCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetCharacterStatistics(ServerModels::GetCharacterStatisticsRequest& request, ProcessApiCallback<ServerModels::GetCharacterStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetContentDownloadUrl(ServerModels::GetContentDownloadUrlRequest& request, ProcessApiCallback<ServerModels::GetContentDownloadUrlResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetFriendLeaderboard(ServerModels::GetFriendLeaderboardRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetFriendsList(ServerModels::GetFriendsListRequest& request, ProcessApiCallback<ServerModels::GetFriendsListResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetLeaderboard(ServerModels::GetLeaderboardRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetLeaderboardAroundCharacter(ServerModels::GetLeaderboardAroundCharacterRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardAroundCharacterResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetLeaderboardAroundUser(ServerModels::GetLeaderboardAroundUserRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardAroundUserResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetLeaderboardForUserCharacters(ServerModels::GetLeaderboardForUsersCharactersRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardForUsersCharactersResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPlayerCombinedInfo(ServerModels::GetPlayerCombinedInfoRequest& request, ProcessApiCallback<ServerModels::GetPlayerCombinedInfoResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPlayerProfile(ServerModels::GetPlayerProfileRequest& request, ProcessApiCallback<ServerModels::GetPlayerProfileResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPlayerSegments(ServerModels::GetPlayersSegmentsRequest& request, ProcessApiCallback<ServerModels::GetPlayerSegmentsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPlayersInSegment(ServerModels::GetPlayersInSegmentRequest& request, ProcessApiCallback<ServerModels::GetPlayersInSegmentResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPlayerStatistics(ServerModels::GetPlayerStatisticsRequest& request, ProcessApiCallback<ServerModels::GetPlayerStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPlayerStatisticVersions(ServerModels::GetPlayerStatisticVersionsRequest& request, ProcessApiCallback<ServerModels::GetPlayerStatisticVersionsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPlayerTags(ServerModels::GetPlayerTagsRequest& request, ProcessApiCallback<ServerModels::GetPlayerTagsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPlayFabIDsFromFacebookIDs(ServerModels::GetPlayFabIDsFromFacebookIDsRequest& request, ProcessApiCallback<ServerModels::GetPlayFabIDsFromFacebookIDsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPlayFabIDsFromFacebookInstantGamesIds(ServerModels::GetPlayFabIDsFromFacebookInstantGamesIdsRequest& request, ProcessApiCallback<ServerModels::GetPlayFabIDsFromFacebookInstantGamesIdsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPlayFabIDsFromGenericIDs(ServerModels::GetPlayFabIDsFromGenericIDsRequest& request, ProcessApiCallback<ServerModels::GetPlayFabIDsFromGenericIDsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPlayFabIDsFromNintendoSwitchDeviceIds(ServerModels::GetPlayFabIDsFromNintendoSwitchDeviceIdsRequest& request, ProcessApiCallback<ServerModels::GetPlayFabIDsFromNintendoSwitchDeviceIdsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPlayFabIDsFromPSNAccountIDs(ServerModels::GetPlayFabIDsFromPSNAccountIDsRequest& request, ProcessApiCallback<ServerModels::GetPlayFabIDsFromPSNAccountIDsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPlayFabIDsFromSteamIDs(ServerModels::GetPlayFabIDsFromSteamIDsRequest& request, ProcessApiCallback<ServerModels::GetPlayFabIDsFromSteamIDsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPlayFabIDsFromXboxLiveIDs(ServerModels::GetPlayFabIDsFromXboxLiveIDsRequest& request, ProcessApiCallback<ServerModels::GetPlayFabIDsFromXboxLiveIDsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPublisherData(ServerModels::GetPublisherDataRequest& request, ProcessApiCallback<ServerModels::GetPublisherDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetRandomResultTables(ServerModels::GetRandomResultTablesRequest& request, ProcessApiCallback<ServerModels::GetRandomResultTablesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetServerCustomIDsFromPlayFabIDs(ServerModels::GetServerCustomIDsFromPlayFabIDsRequest& request, ProcessApiCallback<ServerModels::GetServerCustomIDsFromPlayFabIDsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetSharedGroupData(ServerModels::GetSharedGroupDataRequest& request, ProcessApiCallback<ServerModels::GetSharedGroupDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetTime(ServerModels::GetTimeRequest& request, ProcessApiCallback<ServerModels::GetTimeResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetTitleData(ServerModels::GetTitleDataRequest& request, ProcessApiCallback<ServerModels::GetTitleDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetTitleInternalData(ServerModels::GetTitleDataRequest& request, ProcessApiCallback<ServerModels::GetTitleDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetTitleNews(ServerModels::GetTitleNewsRequest& request, ProcessApiCallback<ServerModels::GetTitleNewsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetUserAccountInfo(ServerModels::GetUserAccountInfoRequest& request, ProcessApiCallback<ServerModels::GetUserAccountInfoResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetUserBans(ServerModels::GetUserBansRequest& request, ProcessApiCallback<ServerModels::GetUserBansResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetUserData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetUserInternalData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetUserInventory(ServerModels::GetUserInventoryRequest& request, ProcessApiCallback<ServerModels::GetUserInventoryResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetUserPublisherData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetUserPublisherInternalData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetUserPublisherReadOnlyData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetUserReadOnlyData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GrantCharacterToUser(ServerModels::GrantCharacterToUserRequest& request, ProcessApiCallback<ServerModels::GrantCharacterToUserResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GrantItemsToCharacter(ServerModels::GrantItemsToCharacterRequest& request, ProcessApiCallback<ServerModels::GrantItemsToCharacterResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GrantItemsToUser(ServerModels::GrantItemsToUserRequest& request, ProcessApiCallback<ServerModels::GrantItemsToUserResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GrantItemsToUsers(ServerModels::GrantItemsToUsersRequest& request, ProcessApiCallback<ServerModels::GrantItemsToUsersResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void LinkServerCustomId(ServerModels::LinkServerCustomIdRequest& request, ProcessApiCallback<ServerModels::LinkServerCustomIdResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void LinkXboxAccount(ServerModels::LinkXboxAccountRequest& request, ProcessApiCallback<ServerModels::LinkXboxAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void LoginWithServerCustomId(ServerModels::LoginWithServerCustomIdRequest& request, ProcessApiCallback<ServerModels::ServerLoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void LoginWithXbox(ServerModels::LoginWithXboxRequest& request, ProcessApiCallback<ServerModels::ServerLoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ModifyItemUses(ServerModels::ModifyItemUsesRequest& request, ProcessApiCallback<ServerModels::ModifyItemUsesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void MoveItemToCharacterFromCharacter(ServerModels::MoveItemToCharacterFromCharacterRequest& request, ProcessApiCallback<ServerModels::MoveItemToCharacterFromCharacterResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void MoveItemToCharacterFromUser(ServerModels::MoveItemToCharacterFromUserRequest& request, ProcessApiCallback<ServerModels::MoveItemToCharacterFromUserResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void MoveItemToUserFromCharacter(ServerModels::MoveItemToUserFromCharacterRequest& request, ProcessApiCallback<ServerModels::MoveItemToUserFromCharacterResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void NotifyMatchmakerPlayerLeft(ServerModels::NotifyMatchmakerPlayerLeftRequest& request, ProcessApiCallback<ServerModels::NotifyMatchmakerPlayerLeftResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void RedeemCoupon(ServerModels::RedeemCouponRequest& request, ProcessApiCallback<ServerModels::RedeemCouponResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void RedeemMatchmakerTicket(ServerModels::RedeemMatchmakerTicketRequest& request, ProcessApiCallback<ServerModels::RedeemMatchmakerTicketResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void RefreshGameServerInstanceHeartbeat(ServerModels::RefreshGameServerInstanceHeartbeatRequest& request, ProcessApiCallback<ServerModels::RefreshGameServerInstanceHeartbeatResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void RegisterGame(ServerModels::RegisterGameRequest& request, ProcessApiCallback<ServerModels::RegisterGameResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void RemoveFriend(ServerModels::RemoveFriendRequest& request, ProcessApiCallback<ServerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void RemoveGenericID(ServerModels::RemoveGenericIDRequest& request, ProcessApiCallback<ServerModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void RemovePlayerTag(ServerModels::RemovePlayerTagRequest& request, ProcessApiCallback<ServerModels::RemovePlayerTagResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void RemoveSharedGroupMembers(ServerModels::RemoveSharedGroupMembersRequest& request, ProcessApiCallback<ServerModels::RemoveSharedGroupMembersResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ReportPlayer(ServerModels::ReportPlayerServerRequest& request, ProcessApiCallback<ServerModels::ReportPlayerServerResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void RevokeAllBansForUser(ServerModels::RevokeAllBansForUserRequest& request, ProcessApiCallback<ServerModels::RevokeAllBansForUserResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void RevokeBans(ServerModels::RevokeBansRequest& request, ProcessApiCallback<ServerModels::RevokeBansResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void RevokeInventoryItem(ServerModels::RevokeInventoryItemRequest& request, ProcessApiCallback<ServerModels::RevokeInventoryResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void RevokeInventoryItems(ServerModels::RevokeInventoryItemsRequest& request, ProcessApiCallback<ServerModels::RevokeInventoryItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SavePushNotificationTemplate(ServerModels::SavePushNotificationTemplateRequest& request, ProcessApiCallback<ServerModels::SavePushNotificationTemplateResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SendCustomAccountRecoveryEmail(ServerModels::SendCustomAccountRecoveryEmailRequest& request, ProcessApiCallback<ServerModels::SendCustomAccountRecoveryEmailResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SendEmailFromTemplate(ServerModels::SendEmailFromTemplateRequest& request, ProcessApiCallback<ServerModels::SendEmailFromTemplateResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SendPushNotification(ServerModels::SendPushNotificationRequest& request, ProcessApiCallback<ServerModels::SendPushNotificationResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SendPushNotificationFromTemplate(ServerModels::SendPushNotificationFromTemplateRequest& request, ProcessApiCallback<ServerModels::SendPushNotificationResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SetFriendTags(ServerModels::SetFriendTagsRequest& request, ProcessApiCallback<ServerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SetGameServerInstanceData(ServerModels::SetGameServerInstanceDataRequest& request, ProcessApiCallback<ServerModels::SetGameServerInstanceDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SetGameServerInstanceState(ServerModels::SetGameServerInstanceStateRequest& request, ProcessApiCallback<ServerModels::SetGameServerInstanceStateResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SetGameServerInstanceTags(ServerModels::SetGameServerInstanceTagsRequest& request, ProcessApiCallback<ServerModels::SetGameServerInstanceTagsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SetPlayerSecret(ServerModels::SetPlayerSecretRequest& request, ProcessApiCallback<ServerModels::SetPlayerSecretResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SetPublisherData(ServerModels::SetPublisherDataRequest& request, ProcessApiCallback<ServerModels::SetPublisherDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SetTitleData(ServerModels::SetTitleDataRequest& request, ProcessApiCallback<ServerModels::SetTitleDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SetTitleInternalData(ServerModels::SetTitleDataRequest& request, ProcessApiCallback<ServerModels::SetTitleDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SubtractCharacterVirtualCurrency(ServerModels::SubtractCharacterVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyCharacterVirtualCurrencyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SubtractUserVirtualCurrency(ServerModels::SubtractUserVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UnlinkServerCustomId(ServerModels::UnlinkServerCustomIdRequest& request, ProcessApiCallback<ServerModels::UnlinkServerCustomIdResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UnlinkXboxAccount(ServerModels::UnlinkXboxAccountRequest& request, ProcessApiCallback<ServerModels::UnlinkXboxAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UnlockContainerInstance(ServerModels::UnlockContainerInstanceRequest& request, ProcessApiCallback<ServerModels::UnlockContainerItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UnlockContainerItem(ServerModels::UnlockContainerItemRequest& request, ProcessApiCallback<ServerModels::UnlockContainerItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateAvatarUrl(ServerModels::UpdateAvatarUrlRequest& request, ProcessApiCallback<ServerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateBans(ServerModels::UpdateBansRequest& request, ProcessApiCallback<ServerModels::UpdateBansResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateCharacterData(ServerModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateCharacterInternalData(ServerModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateCharacterReadOnlyData(ServerModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateCharacterStatistics(ServerModels::UpdateCharacterStatisticsRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdatePlayerStatistics(ServerModels::UpdatePlayerStatisticsRequest& request, ProcessApiCallback<ServerModels::UpdatePlayerStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateSharedGroupData(ServerModels::UpdateSharedGroupDataRequest& request, ProcessApiCallback<ServerModels::UpdateSharedGroupDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateUserData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateUserInternalData(ServerModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateUserInventoryItemCustomData(ServerModels::UpdateUserInventoryItemDataRequest& request, ProcessApiCallback<ServerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateUserPublisherData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateUserPublisherInternalData(ServerModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateUserPublisherReadOnlyData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateUserReadOnlyData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void WriteCharacterEvent(ServerModels::WriteServerCharacterEventRequest& request, ProcessApiCallback<ServerModels::WriteEventResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void WritePlayerEvent(ServerModels::WriteServerPlayerEventRequest& request, ProcessApiCallback<ServerModels::WriteEventResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void WriteTitleEvent(ServerModels::WriteTitleEventRequest& request, ProcessApiCallback<ServerModels::WriteEventResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

        // ------------ Generated result handlers
        void OnAddCharacterVirtualCurrencyResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnAddFriendResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnAddGenericIDResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnAddPlayerTagResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnAddSharedGroupMembersResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnAddUserVirtualCurrencyResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnAuthenticateSessionTicketResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnAwardSteamAchievementResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnBanUsersResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnConsumeItemResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnCreateSharedGroupResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnDeleteCharacterFromUserResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnDeletePlayerResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnDeletePushNotificationTemplateResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnDeleteSharedGroupResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnDeregisterGameResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnEvaluateRandomResultTableResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnExecuteCloudScriptResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetAllSegmentsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetAllUsersCharactersResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetCatalogItemsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetCharacterDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetCharacterInternalDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetCharacterInventoryResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetCharacterLeaderboardResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetCharacterReadOnlyDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetCharacterStatisticsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetContentDownloadUrlResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetFriendLeaderboardResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetFriendsListResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetLeaderboardResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetLeaderboardAroundCharacterResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetLeaderboardAroundUserResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetLeaderboardForUserCharactersResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPlayerCombinedInfoResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPlayerProfileResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPlayerSegmentsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPlayersInSegmentResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPlayerStatisticsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPlayerStatisticVersionsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPlayerTagsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPlayFabIDsFromFacebookIDsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPlayFabIDsFromFacebookInstantGamesIdsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPlayFabIDsFromGenericIDsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPlayFabIDsFromNintendoSwitchDeviceIdsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPlayFabIDsFromPSNAccountIDsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPlayFabIDsFromSteamIDsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPlayFabIDsFromXboxLiveIDsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPublisherDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetRandomResultTablesResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetServerCustomIDsFromPlayFabIDsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetSharedGroupDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetTimeResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetTitleDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetTitleInternalDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetTitleNewsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetUserAccountInfoResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetUserBansResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetUserDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetUserInternalDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetUserInventoryResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetUserPublisherDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetUserPublisherInternalDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetUserPublisherReadOnlyDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetUserReadOnlyDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGrantCharacterToUserResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGrantItemsToCharacterResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGrantItemsToUserResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGrantItemsToUsersResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnLinkServerCustomIdResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnLinkXboxAccountResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnLoginWithServerCustomIdResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnLoginWithXboxResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnModifyItemUsesResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnMoveItemToCharacterFromCharacterResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnMoveItemToCharacterFromUserResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnMoveItemToUserFromCharacterResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnNotifyMatchmakerPlayerLeftResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnRedeemCouponResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnRedeemMatchmakerTicketResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnRefreshGameServerInstanceHeartbeatResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnRegisterGameResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnRemoveFriendResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnRemoveGenericIDResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnRemovePlayerTagResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnRemoveSharedGroupMembersResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnReportPlayerResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnRevokeAllBansForUserResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnRevokeBansResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnRevokeInventoryItemResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnRevokeInventoryItemsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnSavePushNotificationTemplateResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnSendCustomAccountRecoveryEmailResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnSendEmailFromTemplateResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnSendPushNotificationResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnSendPushNotificationFromTemplateResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnSetFriendTagsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnSetGameServerInstanceDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnSetGameServerInstanceStateResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnSetGameServerInstanceTagsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnSetPlayerSecretResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnSetPublisherDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnSetTitleDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnSetTitleInternalDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnSubtractCharacterVirtualCurrencyResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnSubtractUserVirtualCurrencyResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUnlinkServerCustomIdResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUnlinkXboxAccountResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUnlockContainerInstanceResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUnlockContainerItemResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUpdateAvatarUrlResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUpdateBansResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUpdateCharacterDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUpdateCharacterInternalDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUpdateCharacterReadOnlyDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUpdateCharacterStatisticsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUpdatePlayerStatisticsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUpdateSharedGroupDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUpdateUserDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUpdateUserInternalDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUpdateUserInventoryItemCustomDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUpdateUserPublisherDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUpdateUserPublisherInternalDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUpdateUserPublisherReadOnlyDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUpdateUserReadOnlyDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnWriteCharacterEventResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnWritePlayerEventResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnWriteTitleEventResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        bool ValidateResult(PlayFabResultCommon& resultCommon, CallRequestContainer& container);
    private:
        std::shared_ptr<PlayFabAuthenticationContext> GetOrCreateAuthenticationContext();
    };
}

#endif
#endif
