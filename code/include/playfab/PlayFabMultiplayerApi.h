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
        static void CancelAllMatchmakingTicketsForPlayer(MultiplayerModels::CancelAllMatchmakingTicketsForPlayerRequest& request, ProcessApiCallback<MultiplayerModels::CancelAllMatchmakingTicketsForPlayerResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CancelMatchmakingTicket(MultiplayerModels::CancelMatchmakingTicketRequest& request, ProcessApiCallback<MultiplayerModels::CancelMatchmakingTicketResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateBuildWithCustomContainer(MultiplayerModels::CreateBuildWithCustomContainerRequest& request, ProcessApiCallback<MultiplayerModels::CreateBuildWithCustomContainerResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateBuildWithManagedContainer(MultiplayerModels::CreateBuildWithManagedContainerRequest& request, ProcessApiCallback<MultiplayerModels::CreateBuildWithManagedContainerResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateMatchmakingTicket(MultiplayerModels::CreateMatchmakingTicketRequest& request, ProcessApiCallback<MultiplayerModels::CreateMatchmakingTicketResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateRemoteUser(MultiplayerModels::CreateRemoteUserRequest& request, ProcessApiCallback<MultiplayerModels::CreateRemoteUserResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateServerMatchmakingTicket(MultiplayerModels::CreateServerMatchmakingTicketRequest& request, ProcessApiCallback<MultiplayerModels::CreateMatchmakingTicketResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteAsset(MultiplayerModels::DeleteAssetRequest& request, ProcessApiCallback<MultiplayerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteBuild(MultiplayerModels::DeleteBuildRequest& request, ProcessApiCallback<MultiplayerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteCertificate(MultiplayerModels::DeleteCertificateRequest& request, ProcessApiCallback<MultiplayerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteRemoteUser(MultiplayerModels::DeleteRemoteUserRequest& request, ProcessApiCallback<MultiplayerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void EnableMultiplayerServersForTitle(MultiplayerModels::EnableMultiplayerServersForTitleRequest& request, ProcessApiCallback<MultiplayerModels::EnableMultiplayerServersForTitleResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetAssetUploadUrl(MultiplayerModels::GetAssetUploadUrlRequest& request, ProcessApiCallback<MultiplayerModels::GetAssetUploadUrlResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetBuild(MultiplayerModels::GetBuildRequest& request, ProcessApiCallback<MultiplayerModels::GetBuildResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetContainerRegistryCredentials(MultiplayerModels::GetContainerRegistryCredentialsRequest& request, ProcessApiCallback<MultiplayerModels::GetContainerRegistryCredentialsResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetMatch(MultiplayerModels::GetMatchRequest& request, ProcessApiCallback<MultiplayerModels::GetMatchResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetMatchmakingQueue(MultiplayerModels::GetMatchmakingQueueRequest& request, ProcessApiCallback<MultiplayerModels::GetMatchmakingQueueResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetMatchmakingTicket(MultiplayerModels::GetMatchmakingTicketRequest& request, ProcessApiCallback<MultiplayerModels::GetMatchmakingTicketResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetMultiplayerServerDetails(MultiplayerModels::GetMultiplayerServerDetailsRequest& request, ProcessApiCallback<MultiplayerModels::GetMultiplayerServerDetailsResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetQueueStatistics(MultiplayerModels::GetQueueStatisticsRequest& request, ProcessApiCallback<MultiplayerModels::GetQueueStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetRemoteLoginEndpoint(MultiplayerModels::GetRemoteLoginEndpointRequest& request, ProcessApiCallback<MultiplayerModels::GetRemoteLoginEndpointResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetTitleEnabledForMultiplayerServersStatus(MultiplayerModels::GetTitleEnabledForMultiplayerServersStatusRequest& request, ProcessApiCallback<MultiplayerModels::GetTitleEnabledForMultiplayerServersStatusResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void JoinMatchmakingTicket(MultiplayerModels::JoinMatchmakingTicketRequest& request, ProcessApiCallback<MultiplayerModels::JoinMatchmakingTicketResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListArchivedMultiplayerServers(MultiplayerModels::ListMultiplayerServersRequest& request, ProcessApiCallback<MultiplayerModels::ListMultiplayerServersResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListAssetSummaries(MultiplayerModels::ListAssetSummariesRequest& request, ProcessApiCallback<MultiplayerModels::ListAssetSummariesResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListBuildSummaries(MultiplayerModels::ListBuildSummariesRequest& request, ProcessApiCallback<MultiplayerModels::ListBuildSummariesResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListCertificateSummaries(MultiplayerModels::ListCertificateSummariesRequest& request, ProcessApiCallback<MultiplayerModels::ListCertificateSummariesResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListContainerImages(MultiplayerModels::ListContainerImagesRequest& request, ProcessApiCallback<MultiplayerModels::ListContainerImagesResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListContainerImageTags(MultiplayerModels::ListContainerImageTagsRequest& request, ProcessApiCallback<MultiplayerModels::ListContainerImageTagsResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListMatchmakingQueues(MultiplayerModels::ListMatchmakingQueuesRequest& request, ProcessApiCallback<MultiplayerModels::ListMatchmakingQueuesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListMatchmakingTicketsForPlayer(MultiplayerModels::ListMatchmakingTicketsForPlayerRequest& request, ProcessApiCallback<MultiplayerModels::ListMatchmakingTicketsForPlayerResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListMultiplayerServers(MultiplayerModels::ListMultiplayerServersRequest& request, ProcessApiCallback<MultiplayerModels::ListMultiplayerServersResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListQosServers(MultiplayerModels::ListQosServersRequest& request, ProcessApiCallback<MultiplayerModels::ListQosServersResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListVirtualMachineSummaries(MultiplayerModels::ListVirtualMachineSummariesRequest& request, ProcessApiCallback<MultiplayerModels::ListVirtualMachineSummariesResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemoveMatchmakingQueue(MultiplayerModels::RemoveMatchmakingQueueRequest& request, ProcessApiCallback<MultiplayerModels::RemoveMatchmakingQueueResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RequestMultiplayerServer(MultiplayerModels::RequestMultiplayerServerRequest& request, ProcessApiCallback<MultiplayerModels::RequestMultiplayerServerResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RolloverContainerRegistryCredentials(MultiplayerModels::RolloverContainerRegistryCredentialsRequest& request, ProcessApiCallback<MultiplayerModels::RolloverContainerRegistryCredentialsResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetMatchmakingQueue(MultiplayerModels::SetMatchmakingQueueRequest& request, ProcessApiCallback<MultiplayerModels::SetMatchmakingQueueResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ShutdownMultiplayerServer(MultiplayerModels::ShutdownMultiplayerServerRequest& request, ProcessApiCallback<MultiplayerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateBuildRegions(MultiplayerModels::UpdateBuildRegionsRequest& request, ProcessApiCallback<MultiplayerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UploadCertificate(MultiplayerModels::UploadCertificateRequest& request, ProcessApiCallback<MultiplayerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        PlayFabMultiplayerAPI(); // Private constructor, static class should never have an instance
        PlayFabMultiplayerAPI(const PlayFabMultiplayerAPI& other); // Private copy-constructor, static class should never have an instance

        // ------------ Generated result handlers
        static void OnCancelAllMatchmakingTicketsForPlayerResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnCancelMatchmakingTicketResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnCreateBuildWithCustomContainerResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnCreateBuildWithManagedContainerResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnCreateMatchmakingTicketResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnCreateRemoteUserResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnCreateServerMatchmakingTicketResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnDeleteAssetResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnDeleteBuildResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnDeleteCertificateResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnDeleteRemoteUserResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnEnableMultiplayerServersForTitleResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetAssetUploadUrlResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetBuildResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetContainerRegistryCredentialsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetMatchResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetMatchmakingQueueResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetMatchmakingTicketResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetMultiplayerServerDetailsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetQueueStatisticsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetRemoteLoginEndpointResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetTitleEnabledForMultiplayerServersStatusResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnJoinMatchmakingTicketResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnListArchivedMultiplayerServersResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnListAssetSummariesResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnListBuildSummariesResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnListCertificateSummariesResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnListContainerImagesResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnListContainerImageTagsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnListMatchmakingQueuesResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnListMatchmakingTicketsForPlayerResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnListMultiplayerServersResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnListQosServersResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnListVirtualMachineSummariesResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnRemoveMatchmakingQueueResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnRequestMultiplayerServerResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnRolloverContainerRegistryCredentialsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnSetMatchmakingQueueResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnShutdownMultiplayerServerResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnUpdateBuildRegionsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        static void OnUploadCertificateResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);

        static bool ValidateResult(PlayFabResultCommon& resultCommon, CallRequestContainer& container);
    };
}

#endif
