#pragma once

#ifndef DISABLE_PLAYFABCLIENT_API

#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabApiSettings.h>
#include <playfab/PlayFabAuthenticationContext.h>
#include <playfab/PlayFabClientDataModels.h>
#include <memory>

#ifndef PLAYFAB_PLATFORM_PLAYSTATION // Issue 32699
namespace PlayFab
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Client APIs
    /// </summary>
    class PlayFabClientInstanceAPI
    {
    private:
        std::shared_ptr<PlayFabApiSettings> settings;
        std::shared_ptr<PlayFabAuthenticationContext> authContext;

    public:
        PlayFabClientInstanceAPI();
        explicit PlayFabClientInstanceAPI(std::shared_ptr<PlayFabApiSettings> apiSettings);
        explicit PlayFabClientInstanceAPI(std::shared_ptr<PlayFabAuthenticationContext> authenticationContext);
        PlayFabClientInstanceAPI(std::shared_ptr<PlayFabApiSettings> apiSettings, std::shared_ptr<PlayFabAuthenticationContext> authenticationContext);
        ~PlayFabClientInstanceAPI();
        PlayFabClientInstanceAPI(const PlayFabClientInstanceAPI& source) = delete; // disable copy
        PlayFabClientInstanceAPI(PlayFabClientInstanceAPI&&) = delete; // disable move
        PlayFabClientInstanceAPI& operator=(const PlayFabClientInstanceAPI& source) = delete; // disable assignment
        PlayFabClientInstanceAPI& operator=(PlayFabClientInstanceAPI&& other) = delete; // disable move assignment

        std::shared_ptr<PlayFabApiSettings> GetSettings() const;
        void SetSettings(std::shared_ptr<PlayFabApiSettings> apiSettings);
        std::shared_ptr<PlayFabAuthenticationContext> GetAuthenticationContext() const;
        void SetAuthenticationContext(std::shared_ptr<PlayFabAuthenticationContext> authenticationContext);
        size_t Update();
        void ForgetAllCredentials();

        // Public, Client-Specific
        bool IsClientLoggedIn();

        // ------------ Generated API calls
        void AcceptTrade(ClientModels::AcceptTradeRequest& request, ProcessApiCallback<ClientModels::AcceptTradeResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void AddFriend(ClientModels::AddFriendRequest& request, ProcessApiCallback<ClientModels::AddFriendResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void AddGenericID(ClientModels::AddGenericIDRequest& request, ProcessApiCallback<ClientModels::AddGenericIDResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void AddOrUpdateContactEmail(ClientModels::AddOrUpdateContactEmailRequest& request, ProcessApiCallback<ClientModels::AddOrUpdateContactEmailResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void AddSharedGroupMembers(ClientModels::AddSharedGroupMembersRequest& request, ProcessApiCallback<ClientModels::AddSharedGroupMembersResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void AddUsernamePassword(ClientModels::AddUsernamePasswordRequest& request, ProcessApiCallback<ClientModels::AddUsernamePasswordResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void AddUserVirtualCurrency(ClientModels::AddUserVirtualCurrencyRequest& request, ProcessApiCallback<ClientModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void AndroidDevicePushNotificationRegistration(ClientModels::AndroidDevicePushNotificationRegistrationRequest& request, ProcessApiCallback<ClientModels::AndroidDevicePushNotificationRegistrationResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void AttributeInstall(ClientModels::AttributeInstallRequest& request, ProcessApiCallback<ClientModels::AttributeInstallResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CancelTrade(ClientModels::CancelTradeRequest& request, ProcessApiCallback<ClientModels::CancelTradeResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ConfirmPurchase(ClientModels::ConfirmPurchaseRequest& request, ProcessApiCallback<ClientModels::ConfirmPurchaseResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ConsumeItem(ClientModels::ConsumeItemRequest& request, ProcessApiCallback<ClientModels::ConsumeItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ConsumePSNEntitlements(ClientModels::ConsumePSNEntitlementsRequest& request, ProcessApiCallback<ClientModels::ConsumePSNEntitlementsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ConsumeXboxEntitlements(ClientModels::ConsumeXboxEntitlementsRequest& request, ProcessApiCallback<ClientModels::ConsumeXboxEntitlementsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateSharedGroup(ClientModels::CreateSharedGroupRequest& request, ProcessApiCallback<ClientModels::CreateSharedGroupResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ExecuteCloudScript(ClientModels::ExecuteCloudScriptRequest& request, ProcessApiCallback<ClientModels::ExecuteCloudScriptResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetAccountInfo(ClientModels::GetAccountInfoRequest& request, ProcessApiCallback<ClientModels::GetAccountInfoResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetAllUsersCharacters(ClientModels::ListUsersCharactersRequest& request, ProcessApiCallback<ClientModels::ListUsersCharactersResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetCatalogItems(ClientModels::GetCatalogItemsRequest& request, ProcessApiCallback<ClientModels::GetCatalogItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetCharacterData(ClientModels::GetCharacterDataRequest& request, ProcessApiCallback<ClientModels::GetCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetCharacterInventory(ClientModels::GetCharacterInventoryRequest& request, ProcessApiCallback<ClientModels::GetCharacterInventoryResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetCharacterLeaderboard(ClientModels::GetCharacterLeaderboardRequest& request, ProcessApiCallback<ClientModels::GetCharacterLeaderboardResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetCharacterReadOnlyData(ClientModels::GetCharacterDataRequest& request, ProcessApiCallback<ClientModels::GetCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetCharacterStatistics(ClientModels::GetCharacterStatisticsRequest& request, ProcessApiCallback<ClientModels::GetCharacterStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetContentDownloadUrl(ClientModels::GetContentDownloadUrlRequest& request, ProcessApiCallback<ClientModels::GetContentDownloadUrlResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetCurrentGames(ClientModels::CurrentGamesRequest& request, ProcessApiCallback<ClientModels::CurrentGamesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetFriendLeaderboard(ClientModels::GetFriendLeaderboardRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetFriendLeaderboardAroundPlayer(ClientModels::GetFriendLeaderboardAroundPlayerRequest& request, ProcessApiCallback<ClientModels::GetFriendLeaderboardAroundPlayerResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetFriendsList(ClientModels::GetFriendsListRequest& request, ProcessApiCallback<ClientModels::GetFriendsListResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetGameServerRegions(ClientModels::GameServerRegionsRequest& request, ProcessApiCallback<ClientModels::GameServerRegionsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetLeaderboard(ClientModels::GetLeaderboardRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetLeaderboardAroundCharacter(ClientModels::GetLeaderboardAroundCharacterRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardAroundCharacterResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetLeaderboardAroundPlayer(ClientModels::GetLeaderboardAroundPlayerRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardAroundPlayerResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetLeaderboardForUserCharacters(ClientModels::GetLeaderboardForUsersCharactersRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardForUsersCharactersResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPaymentToken(ClientModels::GetPaymentTokenRequest& request, ProcessApiCallback<ClientModels::GetPaymentTokenResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPhotonAuthenticationToken(ClientModels::GetPhotonAuthenticationTokenRequest& request, ProcessApiCallback<ClientModels::GetPhotonAuthenticationTokenResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPlayerCombinedInfo(ClientModels::GetPlayerCombinedInfoRequest& request, ProcessApiCallback<ClientModels::GetPlayerCombinedInfoResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPlayerProfile(ClientModels::GetPlayerProfileRequest& request, ProcessApiCallback<ClientModels::GetPlayerProfileResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPlayerSegments(ClientModels::GetPlayerSegmentsRequest& request, ProcessApiCallback<ClientModels::GetPlayerSegmentsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPlayerStatistics(ClientModels::GetPlayerStatisticsRequest& request, ProcessApiCallback<ClientModels::GetPlayerStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPlayerStatisticVersions(ClientModels::GetPlayerStatisticVersionsRequest& request, ProcessApiCallback<ClientModels::GetPlayerStatisticVersionsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPlayerTags(ClientModels::GetPlayerTagsRequest& request, ProcessApiCallback<ClientModels::GetPlayerTagsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPlayerTrades(ClientModels::GetPlayerTradesRequest& request, ProcessApiCallback<ClientModels::GetPlayerTradesResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPlayFabIDsFromFacebookIDs(ClientModels::GetPlayFabIDsFromFacebookIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromFacebookIDsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPlayFabIDsFromFacebookInstantGamesIds(ClientModels::GetPlayFabIDsFromFacebookInstantGamesIdsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromFacebookInstantGamesIdsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPlayFabIDsFromGameCenterIDs(ClientModels::GetPlayFabIDsFromGameCenterIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromGameCenterIDsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPlayFabIDsFromGenericIDs(ClientModels::GetPlayFabIDsFromGenericIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromGenericIDsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPlayFabIDsFromGoogleIDs(ClientModels::GetPlayFabIDsFromGoogleIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromGoogleIDsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPlayFabIDsFromKongregateIDs(ClientModels::GetPlayFabIDsFromKongregateIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromKongregateIDsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPlayFabIDsFromNintendoSwitchDeviceIds(ClientModels::GetPlayFabIDsFromNintendoSwitchDeviceIdsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromNintendoSwitchDeviceIdsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPlayFabIDsFromPSNAccountIDs(ClientModels::GetPlayFabIDsFromPSNAccountIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromPSNAccountIDsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPlayFabIDsFromSteamIDs(ClientModels::GetPlayFabIDsFromSteamIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromSteamIDsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPlayFabIDsFromTwitchIDs(ClientModels::GetPlayFabIDsFromTwitchIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromTwitchIDsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPlayFabIDsFromXboxLiveIDs(ClientModels::GetPlayFabIDsFromXboxLiveIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromXboxLiveIDsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPublisherData(ClientModels::GetPublisherDataRequest& request, ProcessApiCallback<ClientModels::GetPublisherDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPurchase(ClientModels::GetPurchaseRequest& request, ProcessApiCallback<ClientModels::GetPurchaseResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetSharedGroupData(ClientModels::GetSharedGroupDataRequest& request, ProcessApiCallback<ClientModels::GetSharedGroupDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetStoreItems(ClientModels::GetStoreItemsRequest& request, ProcessApiCallback<ClientModels::GetStoreItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetTime(ClientModels::GetTimeRequest& request, ProcessApiCallback<ClientModels::GetTimeResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetTitleData(ClientModels::GetTitleDataRequest& request, ProcessApiCallback<ClientModels::GetTitleDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetTitleNews(ClientModels::GetTitleNewsRequest& request, ProcessApiCallback<ClientModels::GetTitleNewsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetTitlePublicKey(ClientModels::GetTitlePublicKeyRequest& request, ProcessApiCallback<ClientModels::GetTitlePublicKeyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetTradeStatus(ClientModels::GetTradeStatusRequest& request, ProcessApiCallback<ClientModels::GetTradeStatusResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetUserData(ClientModels::GetUserDataRequest& request, ProcessApiCallback<ClientModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetUserInventory(ClientModels::GetUserInventoryRequest& request, ProcessApiCallback<ClientModels::GetUserInventoryResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetUserPublisherData(ClientModels::GetUserDataRequest& request, ProcessApiCallback<ClientModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetUserPublisherReadOnlyData(ClientModels::GetUserDataRequest& request, ProcessApiCallback<ClientModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetUserReadOnlyData(ClientModels::GetUserDataRequest& request, ProcessApiCallback<ClientModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetWindowsHelloChallenge(ClientModels::GetWindowsHelloChallengeRequest& request, ProcessApiCallback<ClientModels::GetWindowsHelloChallengeResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GrantCharacterToUser(ClientModels::GrantCharacterToUserRequest& request, ProcessApiCallback<ClientModels::GrantCharacterToUserResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void LinkAndroidDeviceID(ClientModels::LinkAndroidDeviceIDRequest& request, ProcessApiCallback<ClientModels::LinkAndroidDeviceIDResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void LinkCustomID(ClientModels::LinkCustomIDRequest& request, ProcessApiCallback<ClientModels::LinkCustomIDResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void LinkFacebookAccount(ClientModels::LinkFacebookAccountRequest& request, ProcessApiCallback<ClientModels::LinkFacebookAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void LinkFacebookInstantGamesId(ClientModels::LinkFacebookInstantGamesIdRequest& request, ProcessApiCallback<ClientModels::LinkFacebookInstantGamesIdResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void LinkGameCenterAccount(ClientModels::LinkGameCenterAccountRequest& request, ProcessApiCallback<ClientModels::LinkGameCenterAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void LinkGoogleAccount(ClientModels::LinkGoogleAccountRequest& request, ProcessApiCallback<ClientModels::LinkGoogleAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void LinkIOSDeviceID(ClientModels::LinkIOSDeviceIDRequest& request, ProcessApiCallback<ClientModels::LinkIOSDeviceIDResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void LinkKongregate(ClientModels::LinkKongregateAccountRequest& request, ProcessApiCallback<ClientModels::LinkKongregateAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void LinkNintendoSwitchDeviceId(ClientModels::LinkNintendoSwitchDeviceIdRequest& request, ProcessApiCallback<ClientModels::LinkNintendoSwitchDeviceIdResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void LinkOpenIdConnect(ClientModels::LinkOpenIdConnectRequest& request, ProcessApiCallback<ClientModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void LinkPSNAccount(ClientModels::LinkPSNAccountRequest& request, ProcessApiCallback<ClientModels::LinkPSNAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void LinkSteamAccount(ClientModels::LinkSteamAccountRequest& request, ProcessApiCallback<ClientModels::LinkSteamAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void LinkTwitch(ClientModels::LinkTwitchAccountRequest& request, ProcessApiCallback<ClientModels::LinkTwitchAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void LinkWindowsHello(ClientModels::LinkWindowsHelloAccountRequest& request, ProcessApiCallback<ClientModels::LinkWindowsHelloAccountResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void LinkXboxAccount(ClientModels::LinkXboxAccountRequest& request, ProcessApiCallback<ClientModels::LinkXboxAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void LoginWithAndroidDeviceID(ClientModels::LoginWithAndroidDeviceIDRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void LoginWithCustomID(ClientModels::LoginWithCustomIDRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void LoginWithEmailAddress(ClientModels::LoginWithEmailAddressRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void LoginWithFacebook(ClientModels::LoginWithFacebookRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void LoginWithFacebookInstantGamesId(ClientModels::LoginWithFacebookInstantGamesIdRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void LoginWithGameCenter(ClientModels::LoginWithGameCenterRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void LoginWithGoogleAccount(ClientModels::LoginWithGoogleAccountRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void LoginWithIOSDeviceID(ClientModels::LoginWithIOSDeviceIDRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void LoginWithKongregate(ClientModels::LoginWithKongregateRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void LoginWithNintendoSwitchDeviceId(ClientModels::LoginWithNintendoSwitchDeviceIdRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void LoginWithOpenIdConnect(ClientModels::LoginWithOpenIdConnectRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void LoginWithPlayFab(ClientModels::LoginWithPlayFabRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void LoginWithPSN(ClientModels::LoginWithPSNRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void LoginWithSteam(ClientModels::LoginWithSteamRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void LoginWithTwitch(ClientModels::LoginWithTwitchRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void LoginWithWindowsHello(ClientModels::LoginWithWindowsHelloRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void LoginWithXbox(ClientModels::LoginWithXboxRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void Matchmake(ClientModels::MatchmakeRequest& request, ProcessApiCallback<ClientModels::MatchmakeResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void OpenTrade(ClientModels::OpenTradeRequest& request, ProcessApiCallback<ClientModels::OpenTradeResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void PayForPurchase(ClientModels::PayForPurchaseRequest& request, ProcessApiCallback<ClientModels::PayForPurchaseResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void PurchaseItem(ClientModels::PurchaseItemRequest& request, ProcessApiCallback<ClientModels::PurchaseItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void RedeemCoupon(ClientModels::RedeemCouponRequest& request, ProcessApiCallback<ClientModels::RedeemCouponResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void RefreshPSNAuthToken(ClientModels::RefreshPSNAuthTokenRequest& request, ProcessApiCallback<ClientModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void RegisterForIOSPushNotification(ClientModels::RegisterForIOSPushNotificationRequest& request, ProcessApiCallback<ClientModels::RegisterForIOSPushNotificationResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void RegisterPlayFabUser(ClientModels::RegisterPlayFabUserRequest& request, ProcessApiCallback<ClientModels::RegisterPlayFabUserResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void RegisterWithWindowsHello(ClientModels::RegisterWithWindowsHelloRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void RemoveContactEmail(ClientModels::RemoveContactEmailRequest& request, ProcessApiCallback<ClientModels::RemoveContactEmailResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void RemoveFriend(ClientModels::RemoveFriendRequest& request, ProcessApiCallback<ClientModels::RemoveFriendResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void RemoveGenericID(ClientModels::RemoveGenericIDRequest& request, ProcessApiCallback<ClientModels::RemoveGenericIDResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void RemoveSharedGroupMembers(ClientModels::RemoveSharedGroupMembersRequest& request, ProcessApiCallback<ClientModels::RemoveSharedGroupMembersResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ReportDeviceInfo(ClientModels::DeviceInfoRequest& request, ProcessApiCallback<ClientModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ReportPlayer(ClientModels::ReportPlayerClientRequest& request, ProcessApiCallback<ClientModels::ReportPlayerClientResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void RestoreIOSPurchases(ClientModels::RestoreIOSPurchasesRequest& request, ProcessApiCallback<ClientModels::RestoreIOSPurchasesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SendAccountRecoveryEmail(ClientModels::SendAccountRecoveryEmailRequest& request, ProcessApiCallback<ClientModels::SendAccountRecoveryEmailResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SetFriendTags(ClientModels::SetFriendTagsRequest& request, ProcessApiCallback<ClientModels::SetFriendTagsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SetPlayerSecret(ClientModels::SetPlayerSecretRequest& request, ProcessApiCallback<ClientModels::SetPlayerSecretResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void StartGame(ClientModels::StartGameRequest& request, ProcessApiCallback<ClientModels::StartGameResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void StartPurchase(ClientModels::StartPurchaseRequest& request, ProcessApiCallback<ClientModels::StartPurchaseResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SubtractUserVirtualCurrency(ClientModels::SubtractUserVirtualCurrencyRequest& request, ProcessApiCallback<ClientModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UnlinkAndroidDeviceID(ClientModels::UnlinkAndroidDeviceIDRequest& request, ProcessApiCallback<ClientModels::UnlinkAndroidDeviceIDResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UnlinkCustomID(ClientModels::UnlinkCustomIDRequest& request, ProcessApiCallback<ClientModels::UnlinkCustomIDResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UnlinkFacebookAccount(ClientModels::UnlinkFacebookAccountRequest& request, ProcessApiCallback<ClientModels::UnlinkFacebookAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UnlinkFacebookInstantGamesId(ClientModels::UnlinkFacebookInstantGamesIdRequest& request, ProcessApiCallback<ClientModels::UnlinkFacebookInstantGamesIdResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UnlinkGameCenterAccount(ClientModels::UnlinkGameCenterAccountRequest& request, ProcessApiCallback<ClientModels::UnlinkGameCenterAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UnlinkGoogleAccount(ClientModels::UnlinkGoogleAccountRequest& request, ProcessApiCallback<ClientModels::UnlinkGoogleAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UnlinkIOSDeviceID(ClientModels::UnlinkIOSDeviceIDRequest& request, ProcessApiCallback<ClientModels::UnlinkIOSDeviceIDResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UnlinkKongregate(ClientModels::UnlinkKongregateAccountRequest& request, ProcessApiCallback<ClientModels::UnlinkKongregateAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UnlinkNintendoSwitchDeviceId(ClientModels::UnlinkNintendoSwitchDeviceIdRequest& request, ProcessApiCallback<ClientModels::UnlinkNintendoSwitchDeviceIdResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UnlinkOpenIdConnect(ClientModels::UninkOpenIdConnectRequest& request, ProcessApiCallback<ClientModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UnlinkPSNAccount(ClientModels::UnlinkPSNAccountRequest& request, ProcessApiCallback<ClientModels::UnlinkPSNAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UnlinkSteamAccount(ClientModels::UnlinkSteamAccountRequest& request, ProcessApiCallback<ClientModels::UnlinkSteamAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UnlinkTwitch(ClientModels::UnlinkTwitchAccountRequest& request, ProcessApiCallback<ClientModels::UnlinkTwitchAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UnlinkWindowsHello(ClientModels::UnlinkWindowsHelloAccountRequest& request, ProcessApiCallback<ClientModels::UnlinkWindowsHelloAccountResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UnlinkXboxAccount(ClientModels::UnlinkXboxAccountRequest& request, ProcessApiCallback<ClientModels::UnlinkXboxAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UnlockContainerInstance(ClientModels::UnlockContainerInstanceRequest& request, ProcessApiCallback<ClientModels::UnlockContainerItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UnlockContainerItem(ClientModels::UnlockContainerItemRequest& request, ProcessApiCallback<ClientModels::UnlockContainerItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateAvatarUrl(ClientModels::UpdateAvatarUrlRequest& request, ProcessApiCallback<ClientModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateCharacterData(ClientModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ClientModels::UpdateCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateCharacterStatistics(ClientModels::UpdateCharacterStatisticsRequest& request, ProcessApiCallback<ClientModels::UpdateCharacterStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdatePlayerStatistics(ClientModels::UpdatePlayerStatisticsRequest& request, ProcessApiCallback<ClientModels::UpdatePlayerStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateSharedGroupData(ClientModels::UpdateSharedGroupDataRequest& request, ProcessApiCallback<ClientModels::UpdateSharedGroupDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateUserData(ClientModels::UpdateUserDataRequest& request, ProcessApiCallback<ClientModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateUserPublisherData(ClientModels::UpdateUserDataRequest& request, ProcessApiCallback<ClientModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateUserTitleDisplayName(ClientModels::UpdateUserTitleDisplayNameRequest& request, ProcessApiCallback<ClientModels::UpdateUserTitleDisplayNameResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ValidateAmazonIAPReceipt(ClientModels::ValidateAmazonReceiptRequest& request, ProcessApiCallback<ClientModels::ValidateAmazonReceiptResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ValidateGooglePlayPurchase(ClientModels::ValidateGooglePlayPurchaseRequest& request, ProcessApiCallback<ClientModels::ValidateGooglePlayPurchaseResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ValidateIOSReceipt(ClientModels::ValidateIOSReceiptRequest& request, ProcessApiCallback<ClientModels::ValidateIOSReceiptResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ValidateWindowsStoreReceipt(ClientModels::ValidateWindowsReceiptRequest& request, ProcessApiCallback<ClientModels::ValidateWindowsReceiptResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void WriteCharacterEvent(ClientModels::WriteClientCharacterEventRequest& request, ProcessApiCallback<ClientModels::WriteEventResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void WritePlayerEvent(ClientModels::WriteClientPlayerEventRequest& request, ProcessApiCallback<ClientModels::WriteEventResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void WriteTitleEvent(ClientModels::WriteTitleEventRequest& request, ProcessApiCallback<ClientModels::WriteEventResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

        // ------------ Generated result handlers
        void OnAcceptTradeResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnAddFriendResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnAddGenericIDResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnAddOrUpdateContactEmailResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnAddSharedGroupMembersResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnAddUsernamePasswordResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnAddUserVirtualCurrencyResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnAndroidDevicePushNotificationRegistrationResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnAttributeInstallResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnCancelTradeResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnConfirmPurchaseResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnConsumeItemResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnConsumePSNEntitlementsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnConsumeXboxEntitlementsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnCreateSharedGroupResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnExecuteCloudScriptResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetAccountInfoResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetAllUsersCharactersResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetCatalogItemsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetCharacterDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetCharacterInventoryResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetCharacterLeaderboardResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetCharacterReadOnlyDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetCharacterStatisticsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetContentDownloadUrlResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetCurrentGamesResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetFriendLeaderboardResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetFriendLeaderboardAroundPlayerResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetFriendsListResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetGameServerRegionsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetLeaderboardResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetLeaderboardAroundCharacterResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetLeaderboardAroundPlayerResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetLeaderboardForUserCharactersResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPaymentTokenResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPhotonAuthenticationTokenResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPlayerCombinedInfoResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPlayerProfileResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPlayerSegmentsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPlayerStatisticsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPlayerStatisticVersionsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPlayerTagsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPlayerTradesResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPlayFabIDsFromFacebookIDsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPlayFabIDsFromFacebookInstantGamesIdsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPlayFabIDsFromGameCenterIDsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPlayFabIDsFromGenericIDsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPlayFabIDsFromGoogleIDsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPlayFabIDsFromKongregateIDsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPlayFabIDsFromNintendoSwitchDeviceIdsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPlayFabIDsFromPSNAccountIDsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPlayFabIDsFromSteamIDsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPlayFabIDsFromTwitchIDsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPlayFabIDsFromXboxLiveIDsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPublisherDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPurchaseResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetSharedGroupDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetStoreItemsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetTimeResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetTitleDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetTitleNewsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetTitlePublicKeyResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetTradeStatusResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetUserDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetUserInventoryResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetUserPublisherDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetUserPublisherReadOnlyDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetUserReadOnlyDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetWindowsHelloChallengeResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGrantCharacterToUserResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnLinkAndroidDeviceIDResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnLinkCustomIDResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnLinkFacebookAccountResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnLinkFacebookInstantGamesIdResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnLinkGameCenterAccountResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnLinkGoogleAccountResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnLinkIOSDeviceIDResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnLinkKongregateResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnLinkNintendoSwitchDeviceIdResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnLinkOpenIdConnectResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnLinkPSNAccountResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnLinkSteamAccountResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnLinkTwitchResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnLinkWindowsHelloResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnLinkXboxAccountResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnLoginWithAndroidDeviceIDResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnLoginWithCustomIDResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnLoginWithEmailAddressResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnLoginWithFacebookResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnLoginWithFacebookInstantGamesIdResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnLoginWithGameCenterResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnLoginWithGoogleAccountResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnLoginWithIOSDeviceIDResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnLoginWithKongregateResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnLoginWithNintendoSwitchDeviceIdResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnLoginWithOpenIdConnectResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnLoginWithPlayFabResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnLoginWithPSNResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnLoginWithSteamResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnLoginWithTwitchResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnLoginWithWindowsHelloResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnLoginWithXboxResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnMatchmakeResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnOpenTradeResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnPayForPurchaseResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnPurchaseItemResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnRedeemCouponResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnRefreshPSNAuthTokenResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnRegisterForIOSPushNotificationResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnRegisterPlayFabUserResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnRegisterWithWindowsHelloResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnRemoveContactEmailResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnRemoveFriendResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnRemoveGenericIDResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnRemoveSharedGroupMembersResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnReportDeviceInfoResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnReportPlayerResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnRestoreIOSPurchasesResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnSendAccountRecoveryEmailResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnSetFriendTagsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnSetPlayerSecretResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnStartGameResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnStartPurchaseResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnSubtractUserVirtualCurrencyResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUnlinkAndroidDeviceIDResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUnlinkCustomIDResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUnlinkFacebookAccountResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUnlinkFacebookInstantGamesIdResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUnlinkGameCenterAccountResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUnlinkGoogleAccountResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUnlinkIOSDeviceIDResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUnlinkKongregateResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUnlinkNintendoSwitchDeviceIdResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUnlinkOpenIdConnectResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUnlinkPSNAccountResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUnlinkSteamAccountResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUnlinkTwitchResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUnlinkWindowsHelloResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUnlinkXboxAccountResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUnlockContainerInstanceResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUnlockContainerItemResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUpdateAvatarUrlResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUpdateCharacterDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUpdateCharacterStatisticsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUpdatePlayerStatisticsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUpdateSharedGroupDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUpdateUserDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUpdateUserPublisherDataResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUpdateUserTitleDisplayNameResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnValidateAmazonIAPReceiptResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnValidateGooglePlayPurchaseResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnValidateIOSReceiptResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnValidateWindowsStoreReceiptResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnWriteCharacterEventResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnWritePlayerEventResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnWriteTitleEventResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);

        // Private, Client-Specific
        void MultiStepClientLogin(bool needsAttribution);
        bool ValidateResult(PlayFabResultCommon& resultCommon, CallRequestContainer& container);
    private:
        std::shared_ptr<PlayFabAuthenticationContext> GetOrCreateAuthenticationContext();
    };
}

#endif
#endif
