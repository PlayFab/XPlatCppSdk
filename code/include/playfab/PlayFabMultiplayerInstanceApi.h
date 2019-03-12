#pragma once

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabApiSettings.h>
#include <playfab/PlayFabAuthenticationContext.h>
#include <playfab/PlayFabMultiplayerDataModels.h>
#include <memory>

namespace PlayFab
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Multiplayer APIs
    /// </summary>
    class PlayFabMultiplayerInstanceAPI
    {
    private:
        std::shared_ptr<PlayFabApiSettings> settings;
        std::shared_ptr<PlayFabAuthenticationContext> authContext;

    public:
        PlayFabMultiplayerInstanceAPI();
        explicit PlayFabMultiplayerInstanceAPI(std::shared_ptr<PlayFabApiSettings> apiSettings);
        explicit PlayFabMultiplayerInstanceAPI(std::shared_ptr<PlayFabAuthenticationContext> authenticationContext);
        PlayFabMultiplayerInstanceAPI(std::shared_ptr<PlayFabApiSettings> apiSettings, std::shared_ptr<PlayFabAuthenticationContext> authenticationContext);
        ~PlayFabMultiplayerInstanceAPI();
        PlayFabMultiplayerInstanceAPI(const PlayFabMultiplayerInstanceAPI& source) = delete; // disable copy
        PlayFabMultiplayerInstanceAPI(PlayFabMultiplayerInstanceAPI&&) = delete; // disable move
        PlayFabMultiplayerInstanceAPI& operator=(const PlayFabMultiplayerInstanceAPI& source) = delete; // disable assignment
        PlayFabMultiplayerInstanceAPI& operator=(PlayFabMultiplayerInstanceAPI&& other) = delete; // disable move assignment

        std::shared_ptr<PlayFabApiSettings> GetSettings() const;
        void SetSettings(std::shared_ptr<PlayFabApiSettings> apiSettings);
        std::shared_ptr<PlayFabAuthenticationContext> GetAuthenticationContext() const;
        void SetAuthenticationContext(std::shared_ptr<PlayFabAuthenticationContext> authenticationContext);
        size_t Update();
        void ForgetAllCredentials();

        // ------------ Generated API calls
        void CancelAllMatchmakingTicketsForPlayer(MultiplayerModels::CancelAllMatchmakingTicketsForPlayerRequest& request, ProcessApiCallback<MultiplayerModels::CancelAllMatchmakingTicketsForPlayerResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CancelMatchmakingTicket(MultiplayerModels::CancelMatchmakingTicketRequest& request, ProcessApiCallback<MultiplayerModels::CancelMatchmakingTicketResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateBuildWithCustomContainer(MultiplayerModels::CreateBuildWithCustomContainerRequest& request, ProcessApiCallback<MultiplayerModels::CreateBuildWithCustomContainerResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateBuildWithManagedContainer(MultiplayerModels::CreateBuildWithManagedContainerRequest& request, ProcessApiCallback<MultiplayerModels::CreateBuildWithManagedContainerResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateMatchmakingTicket(MultiplayerModels::CreateMatchmakingTicketRequest& request, ProcessApiCallback<MultiplayerModels::CreateMatchmakingTicketResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateRemoteUser(MultiplayerModels::CreateRemoteUserRequest& request, ProcessApiCallback<MultiplayerModels::CreateRemoteUserResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateServerMatchmakingTicket(MultiplayerModels::CreateServerMatchmakingTicketRequest& request, ProcessApiCallback<MultiplayerModels::CreateMatchmakingTicketResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteAsset(MultiplayerModels::DeleteAssetRequest& request, ProcessApiCallback<MultiplayerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteBuild(MultiplayerModels::DeleteBuildRequest& request, ProcessApiCallback<MultiplayerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteCertificate(MultiplayerModels::DeleteCertificateRequest& request, ProcessApiCallback<MultiplayerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteRemoteUser(MultiplayerModels::DeleteRemoteUserRequest& request, ProcessApiCallback<MultiplayerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void EnableMultiplayerServersForTitle(MultiplayerModels::EnableMultiplayerServersForTitleRequest& request, ProcessApiCallback<MultiplayerModels::EnableMultiplayerServersForTitleResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetAssetUploadUrl(MultiplayerModels::GetAssetUploadUrlRequest& request, ProcessApiCallback<MultiplayerModels::GetAssetUploadUrlResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetBuild(MultiplayerModels::GetBuildRequest& request, ProcessApiCallback<MultiplayerModels::GetBuildResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetContainerRegistryCredentials(MultiplayerModels::GetContainerRegistryCredentialsRequest& request, ProcessApiCallback<MultiplayerModels::GetContainerRegistryCredentialsResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetMatch(MultiplayerModels::GetMatchRequest& request, ProcessApiCallback<MultiplayerModels::GetMatchResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetMatchmakingQueue(MultiplayerModels::GetMatchmakingQueueRequest& request, ProcessApiCallback<MultiplayerModels::GetMatchmakingQueueResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetMatchmakingTicket(MultiplayerModels::GetMatchmakingTicketRequest& request, ProcessApiCallback<MultiplayerModels::GetMatchmakingTicketResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetMultiplayerServerDetails(MultiplayerModels::GetMultiplayerServerDetailsRequest& request, ProcessApiCallback<MultiplayerModels::GetMultiplayerServerDetailsResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetQueueStatistics(MultiplayerModels::GetQueueStatisticsRequest& request, ProcessApiCallback<MultiplayerModels::GetQueueStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetRemoteLoginEndpoint(MultiplayerModels::GetRemoteLoginEndpointRequest& request, ProcessApiCallback<MultiplayerModels::GetRemoteLoginEndpointResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetTitleEnabledForMultiplayerServersStatus(MultiplayerModels::GetTitleEnabledForMultiplayerServersStatusRequest& request, ProcessApiCallback<MultiplayerModels::GetTitleEnabledForMultiplayerServersStatusResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void JoinMatchmakingTicket(MultiplayerModels::JoinMatchmakingTicketRequest& request, ProcessApiCallback<MultiplayerModels::JoinMatchmakingTicketResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ListArchivedMultiplayerServers(MultiplayerModels::ListMultiplayerServersRequest& request, ProcessApiCallback<MultiplayerModels::ListMultiplayerServersResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ListAssetSummaries(MultiplayerModels::ListAssetSummariesRequest& request, ProcessApiCallback<MultiplayerModels::ListAssetSummariesResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ListBuildSummaries(MultiplayerModels::ListBuildSummariesRequest& request, ProcessApiCallback<MultiplayerModels::ListBuildSummariesResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ListCertificateSummaries(MultiplayerModels::ListCertificateSummariesRequest& request, ProcessApiCallback<MultiplayerModels::ListCertificateSummariesResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ListContainerImages(MultiplayerModels::ListContainerImagesRequest& request, ProcessApiCallback<MultiplayerModels::ListContainerImagesResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ListContainerImageTags(MultiplayerModels::ListContainerImageTagsRequest& request, ProcessApiCallback<MultiplayerModels::ListContainerImageTagsResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ListMatchmakingQueues(MultiplayerModels::ListMatchmakingQueuesRequest& request, ProcessApiCallback<MultiplayerModels::ListMatchmakingQueuesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ListMatchmakingTicketsForPlayer(MultiplayerModels::ListMatchmakingTicketsForPlayerRequest& request, ProcessApiCallback<MultiplayerModels::ListMatchmakingTicketsForPlayerResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ListMultiplayerServers(MultiplayerModels::ListMultiplayerServersRequest& request, ProcessApiCallback<MultiplayerModels::ListMultiplayerServersResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ListQosServers(MultiplayerModels::ListQosServersRequest& request, ProcessApiCallback<MultiplayerModels::ListQosServersResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ListVirtualMachineSummaries(MultiplayerModels::ListVirtualMachineSummariesRequest& request, ProcessApiCallback<MultiplayerModels::ListVirtualMachineSummariesResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void RemoveMatchmakingQueue(MultiplayerModels::RemoveMatchmakingQueueRequest& request, ProcessApiCallback<MultiplayerModels::RemoveMatchmakingQueueResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void RequestMultiplayerServer(MultiplayerModels::RequestMultiplayerServerRequest& request, ProcessApiCallback<MultiplayerModels::RequestMultiplayerServerResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void RolloverContainerRegistryCredentials(MultiplayerModels::RolloverContainerRegistryCredentialsRequest& request, ProcessApiCallback<MultiplayerModels::RolloverContainerRegistryCredentialsResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SetMatchmakingQueue(MultiplayerModels::SetMatchmakingQueueRequest& request, ProcessApiCallback<MultiplayerModels::SetMatchmakingQueueResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ShutdownMultiplayerServer(MultiplayerModels::ShutdownMultiplayerServerRequest& request, ProcessApiCallback<MultiplayerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateBuildRegions(MultiplayerModels::UpdateBuildRegionsRequest& request, ProcessApiCallback<MultiplayerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UploadCertificate(MultiplayerModels::UploadCertificateRequest& request, ProcessApiCallback<MultiplayerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

        // ------------ Generated result handlers
        void OnCancelAllMatchmakingTicketsForPlayerResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnCancelMatchmakingTicketResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnCreateBuildWithCustomContainerResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnCreateBuildWithManagedContainerResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnCreateMatchmakingTicketResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnCreateRemoteUserResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnCreateServerMatchmakingTicketResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnDeleteAssetResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnDeleteBuildResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnDeleteCertificateResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnDeleteRemoteUserResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnEnableMultiplayerServersForTitleResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetAssetUploadUrlResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetBuildResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetContainerRegistryCredentialsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetMatchResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetMatchmakingQueueResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetMatchmakingTicketResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetMultiplayerServerDetailsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetQueueStatisticsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetRemoteLoginEndpointResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetTitleEnabledForMultiplayerServersStatusResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnJoinMatchmakingTicketResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnListArchivedMultiplayerServersResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnListAssetSummariesResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnListBuildSummariesResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnListCertificateSummariesResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnListContainerImagesResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnListContainerImageTagsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnListMatchmakingQueuesResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnListMatchmakingTicketsForPlayerResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnListMultiplayerServersResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnListQosServersResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnListVirtualMachineSummariesResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnRemoveMatchmakingQueueResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnRequestMultiplayerServerResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnRolloverContainerRegistryCredentialsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnSetMatchmakingQueueResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnShutdownMultiplayerServerResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUpdateBuildRegionsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUploadCertificateResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        bool ValidateResult(PlayFabResultCommon& resultCommon, CallRequestContainer& container);
    private:
        std::shared_ptr<PlayFabAuthenticationContext> GetOrCreateAuthenticationContext();
    };
}

#endif
