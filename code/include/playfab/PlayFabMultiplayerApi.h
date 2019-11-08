#pragma once

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabMultiplayerDataModels.h>

namespace PlayFab
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Multiplayer APIs
    /// </summary>
    class PlayFabMultiplayerAPI
    {
    public:
        static size_t Update();
        static void ForgetAllCredentials();


        // ------------ Generated API calls
        static void CancelAllMatchmakingTicketsForPlayer(MultiplayerModels::CancelAllMatchmakingTicketsForPlayerRequest& request, const ProcessApiCallback<MultiplayerModels::CancelAllMatchmakingTicketsForPlayerResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CancelMatchmakingTicket(MultiplayerModels::CancelMatchmakingTicketRequest& request, const ProcessApiCallback<MultiplayerModels::CancelMatchmakingTicketResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateBuildAlias(MultiplayerModels::CreateBuildAliasRequest& request, const ProcessApiCallback<MultiplayerModels::BuildAliasDetailsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateBuildWithCustomContainer(MultiplayerModels::CreateBuildWithCustomContainerRequest& request, const ProcessApiCallback<MultiplayerModels::CreateBuildWithCustomContainerResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateBuildWithManagedContainer(MultiplayerModels::CreateBuildWithManagedContainerRequest& request, const ProcessApiCallback<MultiplayerModels::CreateBuildWithManagedContainerResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateMatchmakingTicket(MultiplayerModels::CreateMatchmakingTicketRequest& request, const ProcessApiCallback<MultiplayerModels::CreateMatchmakingTicketResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateRemoteUser(MultiplayerModels::CreateRemoteUserRequest& request, const ProcessApiCallback<MultiplayerModels::CreateRemoteUserResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateServerMatchmakingTicket(MultiplayerModels::CreateServerMatchmakingTicketRequest& request, const ProcessApiCallback<MultiplayerModels::CreateMatchmakingTicketResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteAsset(MultiplayerModels::DeleteAssetRequest& request, const ProcessApiCallback<MultiplayerModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteBuild(MultiplayerModels::DeleteBuildRequest& request, const ProcessApiCallback<MultiplayerModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteBuildAlias(MultiplayerModels::DeleteBuildAliasRequest& request, const ProcessApiCallback<MultiplayerModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteCertificate(MultiplayerModels::DeleteCertificateRequest& request, const ProcessApiCallback<MultiplayerModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteRemoteUser(MultiplayerModels::DeleteRemoteUserRequest& request, const ProcessApiCallback<MultiplayerModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void EnableMultiplayerServersForTitle(MultiplayerModels::EnableMultiplayerServersForTitleRequest& request, const ProcessApiCallback<MultiplayerModels::EnableMultiplayerServersForTitleResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetAssetUploadUrl(MultiplayerModels::GetAssetUploadUrlRequest& request, const ProcessApiCallback<MultiplayerModels::GetAssetUploadUrlResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetBuild(MultiplayerModels::GetBuildRequest& request, const ProcessApiCallback<MultiplayerModels::GetBuildResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetBuildAlias(MultiplayerModels::GetBuildAliasRequest& request, const ProcessApiCallback<MultiplayerModels::BuildAliasDetailsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetContainerRegistryCredentials(MultiplayerModels::GetContainerRegistryCredentialsRequest& request, const ProcessApiCallback<MultiplayerModels::GetContainerRegistryCredentialsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetMatch(MultiplayerModels::GetMatchRequest& request, const ProcessApiCallback<MultiplayerModels::GetMatchResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetMatchmakingTicket(MultiplayerModels::GetMatchmakingTicketRequest& request, const ProcessApiCallback<MultiplayerModels::GetMatchmakingTicketResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetMultiplayerServerDetails(MultiplayerModels::GetMultiplayerServerDetailsRequest& request, const ProcessApiCallback<MultiplayerModels::GetMultiplayerServerDetailsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetQueueStatistics(MultiplayerModels::GetQueueStatisticsRequest& request, const ProcessApiCallback<MultiplayerModels::GetQueueStatisticsResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetRemoteLoginEndpoint(MultiplayerModels::GetRemoteLoginEndpointRequest& request, const ProcessApiCallback<MultiplayerModels::GetRemoteLoginEndpointResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetTitleEnabledForMultiplayerServersStatus(MultiplayerModels::GetTitleEnabledForMultiplayerServersStatusRequest& request, const ProcessApiCallback<MultiplayerModels::GetTitleEnabledForMultiplayerServersStatusResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetTitleMultiplayerServersQuotas(MultiplayerModels::GetTitleMultiplayerServersQuotasRequest& request, const ProcessApiCallback<MultiplayerModels::GetTitleMultiplayerServersQuotasResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void JoinMatchmakingTicket(MultiplayerModels::JoinMatchmakingTicketRequest& request, const ProcessApiCallback<MultiplayerModels::JoinMatchmakingTicketResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListArchivedMultiplayerServers(MultiplayerModels::ListMultiplayerServersRequest& request, const ProcessApiCallback<MultiplayerModels::ListMultiplayerServersResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListAssetSummaries(MultiplayerModels::ListAssetSummariesRequest& request, const ProcessApiCallback<MultiplayerModels::ListAssetSummariesResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListBuildAliases(MultiplayerModels::MultiplayerEmptyRequest& request, const ProcessApiCallback<MultiplayerModels::ListBuildAliasesForTitleResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListBuildSummaries(MultiplayerModels::ListBuildSummariesRequest& request, const ProcessApiCallback<MultiplayerModels::ListBuildSummariesResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListCertificateSummaries(MultiplayerModels::ListCertificateSummariesRequest& request, const ProcessApiCallback<MultiplayerModels::ListCertificateSummariesResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListContainerImages(MultiplayerModels::ListContainerImagesRequest& request, const ProcessApiCallback<MultiplayerModels::ListContainerImagesResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListContainerImageTags(MultiplayerModels::ListContainerImageTagsRequest& request, const ProcessApiCallback<MultiplayerModels::ListContainerImageTagsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListMatchmakingTicketsForPlayer(MultiplayerModels::ListMatchmakingTicketsForPlayerRequest& request, const ProcessApiCallback<MultiplayerModels::ListMatchmakingTicketsForPlayerResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListMultiplayerServers(MultiplayerModels::ListMultiplayerServersRequest& request, const ProcessApiCallback<MultiplayerModels::ListMultiplayerServersResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListPartyQosServers(MultiplayerModels::ListPartyQosServersRequest& request, const ProcessApiCallback<MultiplayerModels::ListPartyQosServersResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListQosServers(MultiplayerModels::ListQosServersRequest& request, const ProcessApiCallback<MultiplayerModels::ListQosServersResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListQosServersForTitle(MultiplayerModels::ListQosServersForTitleRequest& request, const ProcessApiCallback<MultiplayerModels::ListQosServersForTitleResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListVirtualMachineSummaries(MultiplayerModels::ListVirtualMachineSummariesRequest& request, const ProcessApiCallback<MultiplayerModels::ListVirtualMachineSummariesResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RequestMultiplayerServer(MultiplayerModels::RequestMultiplayerServerRequest& request, const ProcessApiCallback<MultiplayerModels::RequestMultiplayerServerResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RolloverContainerRegistryCredentials(MultiplayerModels::RolloverContainerRegistryCredentialsRequest& request, const ProcessApiCallback<MultiplayerModels::RolloverContainerRegistryCredentialsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ShutdownMultiplayerServer(MultiplayerModels::ShutdownMultiplayerServerRequest& request, const ProcessApiCallback<MultiplayerModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateBuildAlias(MultiplayerModels::UpdateBuildAliasRequest& request, const ProcessApiCallback<MultiplayerModels::BuildAliasDetailsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateBuildRegions(MultiplayerModels::UpdateBuildRegionsRequest& request, const ProcessApiCallback<MultiplayerModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UploadCertificate(MultiplayerModels::UploadCertificateRequest& request, const ProcessApiCallback<MultiplayerModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        PlayFabMultiplayerAPI(); // Private constructor, static class should never have an instance
        PlayFabMultiplayerAPI(const PlayFabMultiplayerAPI& other); // Private copy-constructor, static class should never have an instance

        // ------------ Generated result handlers
        static void OnCancelAllMatchmakingTicketsForPlayerResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnCancelMatchmakingTicketResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnCreateBuildAliasResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnCreateBuildWithCustomContainerResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnCreateBuildWithManagedContainerResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnCreateMatchmakingTicketResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnCreateRemoteUserResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnCreateServerMatchmakingTicketResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteAssetResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteBuildResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteBuildAliasResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteCertificateResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteRemoteUserResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnEnableMultiplayerServersForTitleResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetAssetUploadUrlResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetBuildResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetBuildAliasResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetContainerRegistryCredentialsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetMatchResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetMatchmakingTicketResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetMultiplayerServerDetailsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetQueueStatisticsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetRemoteLoginEndpointResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetTitleEnabledForMultiplayerServersStatusResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetTitleMultiplayerServersQuotasResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnJoinMatchmakingTicketResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnListArchivedMultiplayerServersResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnListAssetSummariesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnListBuildAliasesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnListBuildSummariesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnListCertificateSummariesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnListContainerImagesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnListContainerImageTagsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnListMatchmakingTicketsForPlayerResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnListMultiplayerServersResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnListPartyQosServersResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnListQosServersResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnListQosServersForTitleResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnListVirtualMachineSummariesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnRequestMultiplayerServerResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnRolloverContainerRegistryCredentialsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnShutdownMultiplayerServerResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnUpdateBuildAliasResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnUpdateBuildRegionsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnUploadCertificateResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);

        static bool ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container);
    };
}

#endif // #ifndef DISABLE_PLAYFABENTITY_API
