#pragma once

#ifndef DISABLE_PLAYFABCLIENT_API

#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabHttp.h>
#include <playfab/PlayFabClientDataModels.h>

namespace PlayFab
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Client APIs
    /// </summary>
    class PlayFabClientAPI
    {
    public:
        static size_t Update();
        static void ForgetAllCredentials();


        // Public, Client-Specific
        static bool IsClientLoggedIn();

        // ------------ Generated API calls
        static void AcceptTrade(ClientModels::AcceptTradeRequest& request, ProcessApiCallback<ClientModels::AcceptTradeResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddFriend(ClientModels::AddFriendRequest& request, ProcessApiCallback<ClientModels::AddFriendResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddGenericID(ClientModels::AddGenericIDRequest& request, ProcessApiCallback<ClientModels::AddGenericIDResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddOrUpdateContactEmail(ClientModels::AddOrUpdateContactEmailRequest& request, ProcessApiCallback<ClientModels::AddOrUpdateContactEmailResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddSharedGroupMembers(ClientModels::AddSharedGroupMembersRequest& request, ProcessApiCallback<ClientModels::AddSharedGroupMembersResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddUsernamePassword(ClientModels::AddUsernamePasswordRequest& request, ProcessApiCallback<ClientModels::AddUsernamePasswordResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddUserVirtualCurrency(ClientModels::AddUserVirtualCurrencyRequest& request, ProcessApiCallback<ClientModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AndroidDevicePushNotificationRegistration(ClientModels::AndroidDevicePushNotificationRegistrationRequest& request, ProcessApiCallback<ClientModels::AndroidDevicePushNotificationRegistrationResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AttributeInstall(ClientModels::AttributeInstallRequest& request, ProcessApiCallback<ClientModels::AttributeInstallResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CancelTrade(ClientModels::CancelTradeRequest& request, ProcessApiCallback<ClientModels::CancelTradeResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ConfirmPurchase(ClientModels::ConfirmPurchaseRequest& request, ProcessApiCallback<ClientModels::ConfirmPurchaseResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ConsumeItem(ClientModels::ConsumeItemRequest& request, ProcessApiCallback<ClientModels::ConsumeItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ConsumeXboxEntitlements(ClientModels::ConsumeXboxEntitlementsRequest& request, ProcessApiCallback<ClientModels::ConsumeXboxEntitlementsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateSharedGroup(ClientModels::CreateSharedGroupRequest& request, ProcessApiCallback<ClientModels::CreateSharedGroupResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ExecuteCloudScript(ClientModels::ExecuteCloudScriptRequest& request, ProcessApiCallback<ClientModels::ExecuteCloudScriptResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetAccountInfo(ClientModels::GetAccountInfoRequest& request, ProcessApiCallback<ClientModels::GetAccountInfoResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetAllUsersCharacters(ClientModels::ListUsersCharactersRequest& request, ProcessApiCallback<ClientModels::ListUsersCharactersResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCatalogItems(ClientModels::GetCatalogItemsRequest& request, ProcessApiCallback<ClientModels::GetCatalogItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCharacterData(ClientModels::GetCharacterDataRequest& request, ProcessApiCallback<ClientModels::GetCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCharacterInventory(ClientModels::GetCharacterInventoryRequest& request, ProcessApiCallback<ClientModels::GetCharacterInventoryResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCharacterLeaderboard(ClientModels::GetCharacterLeaderboardRequest& request, ProcessApiCallback<ClientModels::GetCharacterLeaderboardResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCharacterReadOnlyData(ClientModels::GetCharacterDataRequest& request, ProcessApiCallback<ClientModels::GetCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCharacterStatistics(ClientModels::GetCharacterStatisticsRequest& request, ProcessApiCallback<ClientModels::GetCharacterStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetContentDownloadUrl(ClientModels::GetContentDownloadUrlRequest& request, ProcessApiCallback<ClientModels::GetContentDownloadUrlResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCurrentGames(ClientModels::CurrentGamesRequest& request, ProcessApiCallback<ClientModels::CurrentGamesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetFriendLeaderboard(ClientModels::GetFriendLeaderboardRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetFriendLeaderboardAroundPlayer(ClientModels::GetFriendLeaderboardAroundPlayerRequest& request, ProcessApiCallback<ClientModels::GetFriendLeaderboardAroundPlayerResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetFriendsList(ClientModels::GetFriendsListRequest& request, ProcessApiCallback<ClientModels::GetFriendsListResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetGameServerRegions(ClientModels::GameServerRegionsRequest& request, ProcessApiCallback<ClientModels::GameServerRegionsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetLeaderboard(ClientModels::GetLeaderboardRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetLeaderboardAroundCharacter(ClientModels::GetLeaderboardAroundCharacterRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardAroundCharacterResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetLeaderboardAroundPlayer(ClientModels::GetLeaderboardAroundPlayerRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardAroundPlayerResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetLeaderboardForUserCharacters(ClientModels::GetLeaderboardForUsersCharactersRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardForUsersCharactersResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPaymentToken(ClientModels::GetPaymentTokenRequest& request, ProcessApiCallback<ClientModels::GetPaymentTokenResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPhotonAuthenticationToken(ClientModels::GetPhotonAuthenticationTokenRequest& request, ProcessApiCallback<ClientModels::GetPhotonAuthenticationTokenResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerCombinedInfo(ClientModels::GetPlayerCombinedInfoRequest& request, ProcessApiCallback<ClientModels::GetPlayerCombinedInfoResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerProfile(ClientModels::GetPlayerProfileRequest& request, ProcessApiCallback<ClientModels::GetPlayerProfileResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerSegments(ClientModels::GetPlayerSegmentsRequest& request, ProcessApiCallback<ClientModels::GetPlayerSegmentsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerStatistics(ClientModels::GetPlayerStatisticsRequest& request, ProcessApiCallback<ClientModels::GetPlayerStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerStatisticVersions(ClientModels::GetPlayerStatisticVersionsRequest& request, ProcessApiCallback<ClientModels::GetPlayerStatisticVersionsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerTags(ClientModels::GetPlayerTagsRequest& request, ProcessApiCallback<ClientModels::GetPlayerTagsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerTrades(ClientModels::GetPlayerTradesRequest& request, ProcessApiCallback<ClientModels::GetPlayerTradesResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayFabIDsFromFacebookIDs(ClientModels::GetPlayFabIDsFromFacebookIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromFacebookIDsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayFabIDsFromFacebookInstantGamesIds(ClientModels::GetPlayFabIDsFromFacebookInstantGamesIdsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromFacebookInstantGamesIdsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayFabIDsFromGameCenterIDs(ClientModels::GetPlayFabIDsFromGameCenterIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromGameCenterIDsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayFabIDsFromGenericIDs(ClientModels::GetPlayFabIDsFromGenericIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromGenericIDsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayFabIDsFromGoogleIDs(ClientModels::GetPlayFabIDsFromGoogleIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromGoogleIDsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayFabIDsFromKongregateIDs(ClientModels::GetPlayFabIDsFromKongregateIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromKongregateIDsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayFabIDsFromNintendoSwitchDeviceIds(ClientModels::GetPlayFabIDsFromNintendoSwitchDeviceIdsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromNintendoSwitchDeviceIdsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayFabIDsFromSteamIDs(ClientModels::GetPlayFabIDsFromSteamIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromSteamIDsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayFabIDsFromTwitchIDs(ClientModels::GetPlayFabIDsFromTwitchIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromTwitchIDsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPublisherData(ClientModels::GetPublisherDataRequest& request, ProcessApiCallback<ClientModels::GetPublisherDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPurchase(ClientModels::GetPurchaseRequest& request, ProcessApiCallback<ClientModels::GetPurchaseResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetSharedGroupData(ClientModels::GetSharedGroupDataRequest& request, ProcessApiCallback<ClientModels::GetSharedGroupDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetStoreItems(ClientModels::GetStoreItemsRequest& request, ProcessApiCallback<ClientModels::GetStoreItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetTime(ClientModels::GetTimeRequest& request, ProcessApiCallback<ClientModels::GetTimeResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetTitleData(ClientModels::GetTitleDataRequest& request, ProcessApiCallback<ClientModels::GetTitleDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetTitleNews(ClientModels::GetTitleNewsRequest& request, ProcessApiCallback<ClientModels::GetTitleNewsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetTitlePublicKey(ClientModels::GetTitlePublicKeyRequest& request, ProcessApiCallback<ClientModels::GetTitlePublicKeyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetTradeStatus(ClientModels::GetTradeStatusRequest& request, ProcessApiCallback<ClientModels::GetTradeStatusResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserData(ClientModels::GetUserDataRequest& request, ProcessApiCallback<ClientModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserInventory(ClientModels::GetUserInventoryRequest& request, ProcessApiCallback<ClientModels::GetUserInventoryResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserPublisherData(ClientModels::GetUserDataRequest& request, ProcessApiCallback<ClientModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserPublisherReadOnlyData(ClientModels::GetUserDataRequest& request, ProcessApiCallback<ClientModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserReadOnlyData(ClientModels::GetUserDataRequest& request, ProcessApiCallback<ClientModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetWindowsHelloChallenge(ClientModels::GetWindowsHelloChallengeRequest& request, ProcessApiCallback<ClientModels::GetWindowsHelloChallengeResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GrantCharacterToUser(ClientModels::GrantCharacterToUserRequest& request, ProcessApiCallback<ClientModels::GrantCharacterToUserResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LinkAndroidDeviceID(ClientModels::LinkAndroidDeviceIDRequest& request, ProcessApiCallback<ClientModels::LinkAndroidDeviceIDResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LinkCustomID(ClientModels::LinkCustomIDRequest& request, ProcessApiCallback<ClientModels::LinkCustomIDResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LinkFacebookAccount(ClientModels::LinkFacebookAccountRequest& request, ProcessApiCallback<ClientModels::LinkFacebookAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LinkFacebookInstantGamesId(ClientModels::LinkFacebookInstantGamesIdRequest& request, ProcessApiCallback<ClientModels::LinkFacebookInstantGamesIdResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LinkGameCenterAccount(ClientModels::LinkGameCenterAccountRequest& request, ProcessApiCallback<ClientModels::LinkGameCenterAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LinkGoogleAccount(ClientModels::LinkGoogleAccountRequest& request, ProcessApiCallback<ClientModels::LinkGoogleAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LinkIOSDeviceID(ClientModels::LinkIOSDeviceIDRequest& request, ProcessApiCallback<ClientModels::LinkIOSDeviceIDResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LinkKongregate(ClientModels::LinkKongregateAccountRequest& request, ProcessApiCallback<ClientModels::LinkKongregateAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LinkNintendoSwitchDeviceId(ClientModels::LinkNintendoSwitchDeviceIdRequest& request, ProcessApiCallback<ClientModels::LinkNintendoSwitchDeviceIdResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LinkSteamAccount(ClientModels::LinkSteamAccountRequest& request, ProcessApiCallback<ClientModels::LinkSteamAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LinkTwitch(ClientModels::LinkTwitchAccountRequest& request, ProcessApiCallback<ClientModels::LinkTwitchAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LinkWindowsHello(ClientModels::LinkWindowsHelloAccountRequest& request, ProcessApiCallback<ClientModels::LinkWindowsHelloAccountResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LinkXboxAccount(ClientModels::LinkXboxAccountRequest& request, ProcessApiCallback<ClientModels::LinkXboxAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LoginWithAndroidDeviceID(ClientModels::LoginWithAndroidDeviceIDRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LoginWithCustomID(ClientModels::LoginWithCustomIDRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LoginWithEmailAddress(ClientModels::LoginWithEmailAddressRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LoginWithFacebook(ClientModels::LoginWithFacebookRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LoginWithFacebookInstantGamesId(ClientModels::LoginWithFacebookInstantGamesIdRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LoginWithGameCenter(ClientModels::LoginWithGameCenterRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LoginWithGoogleAccount(ClientModels::LoginWithGoogleAccountRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LoginWithIOSDeviceID(ClientModels::LoginWithIOSDeviceIDRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LoginWithKongregate(ClientModels::LoginWithKongregateRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LoginWithNintendoSwitchDeviceId(ClientModels::LoginWithNintendoSwitchDeviceIdRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LoginWithPlayFab(ClientModels::LoginWithPlayFabRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LoginWithSteam(ClientModels::LoginWithSteamRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LoginWithTwitch(ClientModels::LoginWithTwitchRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LoginWithWindowsHello(ClientModels::LoginWithWindowsHelloRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LoginWithXbox(ClientModels::LoginWithXboxRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void Matchmake(ClientModels::MatchmakeRequest& request, ProcessApiCallback<ClientModels::MatchmakeResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void OpenTrade(ClientModels::OpenTradeRequest& request, ProcessApiCallback<ClientModels::OpenTradeResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void PayForPurchase(ClientModels::PayForPurchaseRequest& request, ProcessApiCallback<ClientModels::PayForPurchaseResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void PurchaseItem(ClientModels::PurchaseItemRequest& request, ProcessApiCallback<ClientModels::PurchaseItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RedeemCoupon(ClientModels::RedeemCouponRequest& request, ProcessApiCallback<ClientModels::RedeemCouponResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RegisterForIOSPushNotification(ClientModels::RegisterForIOSPushNotificationRequest& request, ProcessApiCallback<ClientModels::RegisterForIOSPushNotificationResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RegisterPlayFabUser(ClientModels::RegisterPlayFabUserRequest& request, ProcessApiCallback<ClientModels::RegisterPlayFabUserResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RegisterWithWindowsHello(ClientModels::RegisterWithWindowsHelloRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemoveContactEmail(ClientModels::RemoveContactEmailRequest& request, ProcessApiCallback<ClientModels::RemoveContactEmailResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemoveFriend(ClientModels::RemoveFriendRequest& request, ProcessApiCallback<ClientModels::RemoveFriendResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemoveGenericID(ClientModels::RemoveGenericIDRequest& request, ProcessApiCallback<ClientModels::RemoveGenericIDResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemoveSharedGroupMembers(ClientModels::RemoveSharedGroupMembersRequest& request, ProcessApiCallback<ClientModels::RemoveSharedGroupMembersResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ReportDeviceInfo(ClientModels::DeviceInfoRequest& request, ProcessApiCallback<ClientModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ReportPlayer(ClientModels::ReportPlayerClientRequest& request, ProcessApiCallback<ClientModels::ReportPlayerClientResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RestoreIOSPurchases(ClientModels::RestoreIOSPurchasesRequest& request, ProcessApiCallback<ClientModels::RestoreIOSPurchasesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SendAccountRecoveryEmail(ClientModels::SendAccountRecoveryEmailRequest& request, ProcessApiCallback<ClientModels::SendAccountRecoveryEmailResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetFriendTags(ClientModels::SetFriendTagsRequest& request, ProcessApiCallback<ClientModels::SetFriendTagsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetPlayerSecret(ClientModels::SetPlayerSecretRequest& request, ProcessApiCallback<ClientModels::SetPlayerSecretResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void StartGame(ClientModels::StartGameRequest& request, ProcessApiCallback<ClientModels::StartGameResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void StartPurchase(ClientModels::StartPurchaseRequest& request, ProcessApiCallback<ClientModels::StartPurchaseResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SubtractUserVirtualCurrency(ClientModels::SubtractUserVirtualCurrencyRequest& request, ProcessApiCallback<ClientModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlinkAndroidDeviceID(ClientModels::UnlinkAndroidDeviceIDRequest& request, ProcessApiCallback<ClientModels::UnlinkAndroidDeviceIDResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlinkCustomID(ClientModels::UnlinkCustomIDRequest& request, ProcessApiCallback<ClientModels::UnlinkCustomIDResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlinkFacebookAccount(ClientModels::UnlinkFacebookAccountRequest& request, ProcessApiCallback<ClientModels::UnlinkFacebookAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlinkFacebookInstantGamesId(ClientModels::UnlinkFacebookInstantGamesIdRequest& request, ProcessApiCallback<ClientModels::UnlinkFacebookInstantGamesIdResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlinkGameCenterAccount(ClientModels::UnlinkGameCenterAccountRequest& request, ProcessApiCallback<ClientModels::UnlinkGameCenterAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlinkGoogleAccount(ClientModels::UnlinkGoogleAccountRequest& request, ProcessApiCallback<ClientModels::UnlinkGoogleAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlinkIOSDeviceID(ClientModels::UnlinkIOSDeviceIDRequest& request, ProcessApiCallback<ClientModels::UnlinkIOSDeviceIDResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlinkKongregate(ClientModels::UnlinkKongregateAccountRequest& request, ProcessApiCallback<ClientModels::UnlinkKongregateAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlinkNintendoSwitchDeviceId(ClientModels::UnlinkNintendoSwitchDeviceIdRequest& request, ProcessApiCallback<ClientModels::UnlinkNintendoSwitchDeviceIdResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlinkSteamAccount(ClientModels::UnlinkSteamAccountRequest& request, ProcessApiCallback<ClientModels::UnlinkSteamAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlinkTwitch(ClientModels::UnlinkTwitchAccountRequest& request, ProcessApiCallback<ClientModels::UnlinkTwitchAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlinkWindowsHello(ClientModels::UnlinkWindowsHelloAccountRequest& request, ProcessApiCallback<ClientModels::UnlinkWindowsHelloAccountResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlinkXboxAccount(ClientModels::UnlinkXboxAccountRequest& request, ProcessApiCallback<ClientModels::UnlinkXboxAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlockContainerInstance(ClientModels::UnlockContainerInstanceRequest& request, ProcessApiCallback<ClientModels::UnlockContainerItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlockContainerItem(ClientModels::UnlockContainerItemRequest& request, ProcessApiCallback<ClientModels::UnlockContainerItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateAvatarUrl(ClientModels::UpdateAvatarUrlRequest& request, ProcessApiCallback<ClientModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateCharacterData(ClientModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ClientModels::UpdateCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateCharacterStatistics(ClientModels::UpdateCharacterStatisticsRequest& request, ProcessApiCallback<ClientModels::UpdateCharacterStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdatePlayerStatistics(ClientModels::UpdatePlayerStatisticsRequest& request, ProcessApiCallback<ClientModels::UpdatePlayerStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateSharedGroupData(ClientModels::UpdateSharedGroupDataRequest& request, ProcessApiCallback<ClientModels::UpdateSharedGroupDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserData(ClientModels::UpdateUserDataRequest& request, ProcessApiCallback<ClientModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserPublisherData(ClientModels::UpdateUserDataRequest& request, ProcessApiCallback<ClientModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserTitleDisplayName(ClientModels::UpdateUserTitleDisplayNameRequest& request, ProcessApiCallback<ClientModels::UpdateUserTitleDisplayNameResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ValidateAmazonIAPReceipt(ClientModels::ValidateAmazonReceiptRequest& request, ProcessApiCallback<ClientModels::ValidateAmazonReceiptResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ValidateGooglePlayPurchase(ClientModels::ValidateGooglePlayPurchaseRequest& request, ProcessApiCallback<ClientModels::ValidateGooglePlayPurchaseResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ValidateIOSReceipt(ClientModels::ValidateIOSReceiptRequest& request, ProcessApiCallback<ClientModels::ValidateIOSReceiptResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ValidateWindowsStoreReceipt(ClientModels::ValidateWindowsReceiptRequest& request, ProcessApiCallback<ClientModels::ValidateWindowsReceiptResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void WriteCharacterEvent(ClientModels::WriteClientCharacterEventRequest& request, ProcessApiCallback<ClientModels::WriteEventResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void WritePlayerEvent(ClientModels::WriteClientPlayerEventRequest& request, ProcessApiCallback<ClientModels::WriteEventResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void WriteTitleEvent(ClientModels::WriteTitleEventRequest& request, ProcessApiCallback<ClientModels::WriteEventResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        PlayFabClientAPI(); // Private constructor, static class should never have an instance
        PlayFabClientAPI(const PlayFabClientAPI& other); // Private copy-constructor, static class should never have an instance

        // ------------ Generated result handlers
        static void OnAcceptTradeResult(CallRequestContainerBase& request);
        static void OnAddFriendResult(CallRequestContainerBase& request);
        static void OnAddGenericIDResult(CallRequestContainerBase& request);
        static void OnAddOrUpdateContactEmailResult(CallRequestContainerBase& request);
        static void OnAddSharedGroupMembersResult(CallRequestContainerBase& request);
        static void OnAddUsernamePasswordResult(CallRequestContainerBase& request);
        static void OnAddUserVirtualCurrencyResult(CallRequestContainerBase& request);
        static void OnAndroidDevicePushNotificationRegistrationResult(CallRequestContainerBase& request);
        static void OnAttributeInstallResult(CallRequestContainerBase& request);
        static void OnCancelTradeResult(CallRequestContainerBase& request);
        static void OnConfirmPurchaseResult(CallRequestContainerBase& request);
        static void OnConsumeItemResult(CallRequestContainerBase& request);
        static void OnConsumeXboxEntitlementsResult(CallRequestContainerBase& request);
        static void OnCreateSharedGroupResult(CallRequestContainerBase& request);
        static void OnExecuteCloudScriptResult(CallRequestContainerBase& request);
        static void OnGetAccountInfoResult(CallRequestContainerBase& request);
        static void OnGetAllUsersCharactersResult(CallRequestContainerBase& request);
        static void OnGetCatalogItemsResult(CallRequestContainerBase& request);
        static void OnGetCharacterDataResult(CallRequestContainerBase& request);
        static void OnGetCharacterInventoryResult(CallRequestContainerBase& request);
        static void OnGetCharacterLeaderboardResult(CallRequestContainerBase& request);
        static void OnGetCharacterReadOnlyDataResult(CallRequestContainerBase& request);
        static void OnGetCharacterStatisticsResult(CallRequestContainerBase& request);
        static void OnGetContentDownloadUrlResult(CallRequestContainerBase& request);
        static void OnGetCurrentGamesResult(CallRequestContainerBase& request);
        static void OnGetFriendLeaderboardResult(CallRequestContainerBase& request);
        static void OnGetFriendLeaderboardAroundPlayerResult(CallRequestContainerBase& request);
        static void OnGetFriendsListResult(CallRequestContainerBase& request);
        static void OnGetGameServerRegionsResult(CallRequestContainerBase& request);
        static void OnGetLeaderboardResult(CallRequestContainerBase& request);
        static void OnGetLeaderboardAroundCharacterResult(CallRequestContainerBase& request);
        static void OnGetLeaderboardAroundPlayerResult(CallRequestContainerBase& request);
        static void OnGetLeaderboardForUserCharactersResult(CallRequestContainerBase& request);
        static void OnGetPaymentTokenResult(CallRequestContainerBase& request);
        static void OnGetPhotonAuthenticationTokenResult(CallRequestContainerBase& request);
        static void OnGetPlayerCombinedInfoResult(CallRequestContainerBase& request);
        static void OnGetPlayerProfileResult(CallRequestContainerBase& request);
        static void OnGetPlayerSegmentsResult(CallRequestContainerBase& request);
        static void OnGetPlayerStatisticsResult(CallRequestContainerBase& request);
        static void OnGetPlayerStatisticVersionsResult(CallRequestContainerBase& request);
        static void OnGetPlayerTagsResult(CallRequestContainerBase& request);
        static void OnGetPlayerTradesResult(CallRequestContainerBase& request);
        static void OnGetPlayFabIDsFromFacebookIDsResult(CallRequestContainerBase& request);
        static void OnGetPlayFabIDsFromFacebookInstantGamesIdsResult(CallRequestContainerBase& request);
        static void OnGetPlayFabIDsFromGameCenterIDsResult(CallRequestContainerBase& request);
        static void OnGetPlayFabIDsFromGenericIDsResult(CallRequestContainerBase& request);
        static void OnGetPlayFabIDsFromGoogleIDsResult(CallRequestContainerBase& request);
        static void OnGetPlayFabIDsFromKongregateIDsResult(CallRequestContainerBase& request);
        static void OnGetPlayFabIDsFromNintendoSwitchDeviceIdsResult(CallRequestContainerBase& request);
        static void OnGetPlayFabIDsFromSteamIDsResult(CallRequestContainerBase& request);
        static void OnGetPlayFabIDsFromTwitchIDsResult(CallRequestContainerBase& request);
        static void OnGetPublisherDataResult(CallRequestContainerBase& request);
        static void OnGetPurchaseResult(CallRequestContainerBase& request);
        static void OnGetSharedGroupDataResult(CallRequestContainerBase& request);
        static void OnGetStoreItemsResult(CallRequestContainerBase& request);
        static void OnGetTimeResult(CallRequestContainerBase& request);
        static void OnGetTitleDataResult(CallRequestContainerBase& request);
        static void OnGetTitleNewsResult(CallRequestContainerBase& request);
        static void OnGetTitlePublicKeyResult(CallRequestContainerBase& request);
        static void OnGetTradeStatusResult(CallRequestContainerBase& request);
        static void OnGetUserDataResult(CallRequestContainerBase& request);
        static void OnGetUserInventoryResult(CallRequestContainerBase& request);
        static void OnGetUserPublisherDataResult(CallRequestContainerBase& request);
        static void OnGetUserPublisherReadOnlyDataResult(CallRequestContainerBase& request);
        static void OnGetUserReadOnlyDataResult(CallRequestContainerBase& request);
        static void OnGetWindowsHelloChallengeResult(CallRequestContainerBase& request);
        static void OnGrantCharacterToUserResult(CallRequestContainerBase& request);
        static void OnLinkAndroidDeviceIDResult(CallRequestContainerBase& request);
        static void OnLinkCustomIDResult(CallRequestContainerBase& request);
        static void OnLinkFacebookAccountResult(CallRequestContainerBase& request);
        static void OnLinkFacebookInstantGamesIdResult(CallRequestContainerBase& request);
        static void OnLinkGameCenterAccountResult(CallRequestContainerBase& request);
        static void OnLinkGoogleAccountResult(CallRequestContainerBase& request);
        static void OnLinkIOSDeviceIDResult(CallRequestContainerBase& request);
        static void OnLinkKongregateResult(CallRequestContainerBase& request);
        static void OnLinkNintendoSwitchDeviceIdResult(CallRequestContainerBase& request);
        static void OnLinkSteamAccountResult(CallRequestContainerBase& request);
        static void OnLinkTwitchResult(CallRequestContainerBase& request);
        static void OnLinkWindowsHelloResult(CallRequestContainerBase& request);
        static void OnLinkXboxAccountResult(CallRequestContainerBase& request);
        static void OnLoginWithAndroidDeviceIDResult(CallRequestContainerBase& request);
        static void OnLoginWithCustomIDResult(CallRequestContainerBase& request);
        static void OnLoginWithEmailAddressResult(CallRequestContainerBase& request);
        static void OnLoginWithFacebookResult(CallRequestContainerBase& request);
        static void OnLoginWithFacebookInstantGamesIdResult(CallRequestContainerBase& request);
        static void OnLoginWithGameCenterResult(CallRequestContainerBase& request);
        static void OnLoginWithGoogleAccountResult(CallRequestContainerBase& request);
        static void OnLoginWithIOSDeviceIDResult(CallRequestContainerBase& request);
        static void OnLoginWithKongregateResult(CallRequestContainerBase& request);
        static void OnLoginWithNintendoSwitchDeviceIdResult(CallRequestContainerBase& request);
        static void OnLoginWithPlayFabResult(CallRequestContainerBase& request);
        static void OnLoginWithSteamResult(CallRequestContainerBase& request);
        static void OnLoginWithTwitchResult(CallRequestContainerBase& request);
        static void OnLoginWithWindowsHelloResult(CallRequestContainerBase& request);
        static void OnLoginWithXboxResult(CallRequestContainerBase& request);
        static void OnMatchmakeResult(CallRequestContainerBase& request);
        static void OnOpenTradeResult(CallRequestContainerBase& request);
        static void OnPayForPurchaseResult(CallRequestContainerBase& request);
        static void OnPurchaseItemResult(CallRequestContainerBase& request);
        static void OnRedeemCouponResult(CallRequestContainerBase& request);
        static void OnRegisterForIOSPushNotificationResult(CallRequestContainerBase& request);
        static void OnRegisterPlayFabUserResult(CallRequestContainerBase& request);
        static void OnRegisterWithWindowsHelloResult(CallRequestContainerBase& request);
        static void OnRemoveContactEmailResult(CallRequestContainerBase& request);
        static void OnRemoveFriendResult(CallRequestContainerBase& request);
        static void OnRemoveGenericIDResult(CallRequestContainerBase& request);
        static void OnRemoveSharedGroupMembersResult(CallRequestContainerBase& request);
        static void OnReportDeviceInfoResult(CallRequestContainerBase& request);
        static void OnReportPlayerResult(CallRequestContainerBase& request);
        static void OnRestoreIOSPurchasesResult(CallRequestContainerBase& request);
        static void OnSendAccountRecoveryEmailResult(CallRequestContainerBase& request);
        static void OnSetFriendTagsResult(CallRequestContainerBase& request);
        static void OnSetPlayerSecretResult(CallRequestContainerBase& request);
        static void OnStartGameResult(CallRequestContainerBase& request);
        static void OnStartPurchaseResult(CallRequestContainerBase& request);
        static void OnSubtractUserVirtualCurrencyResult(CallRequestContainerBase& request);
        static void OnUnlinkAndroidDeviceIDResult(CallRequestContainerBase& request);
        static void OnUnlinkCustomIDResult(CallRequestContainerBase& request);
        static void OnUnlinkFacebookAccountResult(CallRequestContainerBase& request);
        static void OnUnlinkFacebookInstantGamesIdResult(CallRequestContainerBase& request);
        static void OnUnlinkGameCenterAccountResult(CallRequestContainerBase& request);
        static void OnUnlinkGoogleAccountResult(CallRequestContainerBase& request);
        static void OnUnlinkIOSDeviceIDResult(CallRequestContainerBase& request);
        static void OnUnlinkKongregateResult(CallRequestContainerBase& request);
        static void OnUnlinkNintendoSwitchDeviceIdResult(CallRequestContainerBase& request);
        static void OnUnlinkSteamAccountResult(CallRequestContainerBase& request);
        static void OnUnlinkTwitchResult(CallRequestContainerBase& request);
        static void OnUnlinkWindowsHelloResult(CallRequestContainerBase& request);
        static void OnUnlinkXboxAccountResult(CallRequestContainerBase& request);
        static void OnUnlockContainerInstanceResult(CallRequestContainerBase& request);
        static void OnUnlockContainerItemResult(CallRequestContainerBase& request);
        static void OnUpdateAvatarUrlResult(CallRequestContainerBase& request);
        static void OnUpdateCharacterDataResult(CallRequestContainerBase& request);
        static void OnUpdateCharacterStatisticsResult(CallRequestContainerBase& request);
        static void OnUpdatePlayerStatisticsResult(CallRequestContainerBase& request);
        static void OnUpdateSharedGroupDataResult(CallRequestContainerBase& request);
        static void OnUpdateUserDataResult(CallRequestContainerBase& request);
        static void OnUpdateUserPublisherDataResult(CallRequestContainerBase& request);
        static void OnUpdateUserTitleDisplayNameResult(CallRequestContainerBase& request);
        static void OnValidateAmazonIAPReceiptResult(CallRequestContainerBase& request);
        static void OnValidateGooglePlayPurchaseResult(CallRequestContainerBase& request);
        static void OnValidateIOSReceiptResult(CallRequestContainerBase& request);
        static void OnValidateWindowsStoreReceiptResult(CallRequestContainerBase& request);
        static void OnWriteCharacterEventResult(CallRequestContainerBase& request);
        static void OnWritePlayerEventResult(CallRequestContainerBase& request);
        static void OnWriteTitleEventResult(CallRequestContainerBase& request);


        // Private, Client-Specific
        static void MultiStepClientLogin(bool needsAttribution);
    };
}

#endif
