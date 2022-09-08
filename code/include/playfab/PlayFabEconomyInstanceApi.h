#pragma once

#if !defined(DISABLE_PLAYFABENTITY_API)

#include <playfab/PlayFabEconomyDataModels.h>
#include <playfab/PlayFabError.h>

namespace PlayFab
{
    class CallRequestContainerBase;
    class CallRequestContainer;
    class PlayFabApiSettings;
    class PlayFabAuthenticationContext;

    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Economy APIs
    /// </summary>
    class PlayFabEconomyInstanceAPI
    {
    private:
        std::shared_ptr<PlayFabApiSettings> m_settings;
        std::shared_ptr<PlayFabAuthenticationContext> m_context;

    public:
        PlayFabEconomyInstanceAPI(const std::shared_ptr<PlayFabAuthenticationContext>& authenticationContext);
        PlayFabEconomyInstanceAPI(const std::shared_ptr<PlayFabApiSettings>& apiSettings, const std::shared_ptr<PlayFabAuthenticationContext>& authenticationContext);

        ~PlayFabEconomyInstanceAPI() = default;
        PlayFabEconomyInstanceAPI(const PlayFabEconomyInstanceAPI& source) = delete; // disable copy
        PlayFabEconomyInstanceAPI(PlayFabEconomyInstanceAPI&&) = delete; // disable move
        PlayFabEconomyInstanceAPI& operator=(const PlayFabEconomyInstanceAPI& source) = delete; // disable assignment
        PlayFabEconomyInstanceAPI& operator=(PlayFabEconomyInstanceAPI&& other) = delete; // disable move assignment

        std::shared_ptr<PlayFabApiSettings> GetSettings() const;
        std::shared_ptr<PlayFabAuthenticationContext> GetAuthenticationContext() const;
        /// <summary>
        /// Calls the Update function on your implementation of the IHttpPlugin to check for responses to HTTP requests.
        /// All api's (Client, Server, Admin etc.) share the same IHttpPlugin. 
        /// This means that you only need to call Update() on one API to retrieve the responses for all APIs.
        /// Additional calls to Update (on any API) during the same tick are unlikely to retrieve additional responses.
        /// Call Update when your game ticks as follows:
        ///     Economy.Update();
        /// </summary>
        size_t Update();
        void ForgetAllCredentials();

        // ------------ Generated API calls
        void AddInventoryItems(EconomyModels::AddInventoryItemsRequest& request, const ProcessApiCallback<EconomyModels::AddInventoryItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateDraftItem(EconomyModels::CreateDraftItemRequest& request, const ProcessApiCallback<EconomyModels::CreateDraftItemResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateUploadUrls(EconomyModels::CreateUploadUrlsRequest& request, const ProcessApiCallback<EconomyModels::CreateUploadUrlsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteEntityItemReviews(EconomyModels::DeleteEntityItemReviewsRequest& request, const ProcessApiCallback<EconomyModels::DeleteEntityItemReviewsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteInventoryCollection(EconomyModels::DeleteInventoryCollectionRequest& request, const ProcessApiCallback<EconomyModels::DeleteInventoryCollectionResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteInventoryItems(EconomyModels::DeleteInventoryItemsRequest& request, const ProcessApiCallback<EconomyModels::DeleteInventoryItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteItem(EconomyModels::DeleteItemRequest& request, const ProcessApiCallback<EconomyModels::DeleteItemResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ExecuteInventoryOperations(EconomyModels::ExecuteInventoryOperationsRequest& request, const ProcessApiCallback<EconomyModels::ExecuteInventoryOperationsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetCatalogConfig(EconomyModels::GetCatalogConfigRequest& request, const ProcessApiCallback<EconomyModels::GetCatalogConfigResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetDraftItem(EconomyModels::GetDraftItemRequest& request, const ProcessApiCallback<EconomyModels::GetDraftItemResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetDraftItems(EconomyModels::GetDraftItemsRequest& request, const ProcessApiCallback<EconomyModels::GetDraftItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetEntityDraftItems(EconomyModels::GetEntityDraftItemsRequest& request, const ProcessApiCallback<EconomyModels::GetEntityDraftItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetEntityItemReview(EconomyModels::GetEntityItemReviewRequest& request, const ProcessApiCallback<EconomyModels::GetEntityItemReviewResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetInventoryCollectionIds(EconomyModels::GetInventoryCollectionIdsRequest& request, const ProcessApiCallback<EconomyModels::GetInventoryCollectionIdsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetInventoryItems(EconomyModels::GetInventoryItemsRequest& request, const ProcessApiCallback<EconomyModels::GetInventoryItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetItem(EconomyModels::GetItemRequest& request, const ProcessApiCallback<EconomyModels::GetItemResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetItemContainers(EconomyModels::GetItemContainersRequest& request, const ProcessApiCallback<EconomyModels::GetItemContainersResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetItemModerationState(EconomyModels::GetItemModerationStateRequest& request, const ProcessApiCallback<EconomyModels::GetItemModerationStateResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetItemPublishStatus(EconomyModels::GetItemPublishStatusRequest& request, const ProcessApiCallback<EconomyModels::GetItemPublishStatusResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetItemReviews(EconomyModels::GetItemReviewsRequest& request, const ProcessApiCallback<EconomyModels::GetItemReviewsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetItemReviewSummary(EconomyModels::GetItemReviewSummaryRequest& request, const ProcessApiCallback<EconomyModels::GetItemReviewSummaryResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetItems(EconomyModels::GetItemsRequest& request, const ProcessApiCallback<EconomyModels::GetItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetMicrosoftStoreAccessTokens(EconomyModels::GetMicrosoftStoreAccessTokensRequest& request, const ProcessApiCallback<EconomyModels::GetMicrosoftStoreAccessTokensResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void PublishDraftItem(EconomyModels::PublishDraftItemRequest& request, const ProcessApiCallback<EconomyModels::PublishDraftItemResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void PurchaseInventoryItems(EconomyModels::PurchaseInventoryItemsRequest& request, const ProcessApiCallback<EconomyModels::PurchaseInventoryItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void RedeemAppleAppStoreInventoryItems(EconomyModels::RedeemAppleAppStoreInventoryItemsRequest& request, const ProcessApiCallback<EconomyModels::RedeemAppleAppStoreInventoryItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void RedeemGooglePlayInventoryItems(EconomyModels::RedeemGooglePlayInventoryItemsRequest& request, const ProcessApiCallback<EconomyModels::RedeemGooglePlayInventoryItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void RedeemMicrosoftStoreInventoryItems(EconomyModels::RedeemMicrosoftStoreInventoryItemsRequest& request, const ProcessApiCallback<EconomyModels::RedeemMicrosoftStoreInventoryItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void RedeemNintendoEShopInventoryItems(EconomyModels::RedeemNintendoEShopInventoryItemsRequest& request, const ProcessApiCallback<EconomyModels::RedeemNintendoEShopInventoryItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void RedeemPlayStationStoreInventoryItems(EconomyModels::RedeemPlayStationStoreInventoryItemsRequest& request, const ProcessApiCallback<EconomyModels::RedeemPlayStationStoreInventoryItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void RedeemSteamInventoryItems(EconomyModels::RedeemSteamInventoryItemsRequest& request, const ProcessApiCallback<EconomyModels::RedeemSteamInventoryItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ReportItem(EconomyModels::ReportItemRequest& request, const ProcessApiCallback<EconomyModels::ReportItemResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ReportItemReview(EconomyModels::ReportItemReviewRequest& request, const ProcessApiCallback<EconomyModels::ReportItemReviewResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ReviewItem(EconomyModels::ReviewItemRequest& request, const ProcessApiCallback<EconomyModels::ReviewItemResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SearchItems(EconomyModels::SearchItemsRequest& request, const ProcessApiCallback<EconomyModels::SearchItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SetItemModerationState(EconomyModels::SetItemModerationStateRequest& request, const ProcessApiCallback<EconomyModels::SetItemModerationStateResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SubmitItemReviewVote(EconomyModels::SubmitItemReviewVoteRequest& request, const ProcessApiCallback<EconomyModels::SubmitItemReviewVoteResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SubtractInventoryItems(EconomyModels::SubtractInventoryItemsRequest& request, const ProcessApiCallback<EconomyModels::SubtractInventoryItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void TakedownItemReviews(EconomyModels::TakedownItemReviewsRequest& request, const ProcessApiCallback<EconomyModels::TakedownItemReviewsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void TransferInventoryItems(EconomyModels::TransferInventoryItemsRequest& request, const ProcessApiCallback<EconomyModels::TransferInventoryItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateCatalogConfig(EconomyModels::UpdateCatalogConfigRequest& request, const ProcessApiCallback<EconomyModels::UpdateCatalogConfigResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateDraftItem(EconomyModels::UpdateDraftItemRequest& request, const ProcessApiCallback<EconomyModels::UpdateDraftItemResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateInventoryItems(EconomyModels::UpdateInventoryItemsRequest& request, const ProcessApiCallback<EconomyModels::UpdateInventoryItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);

        // ------------ Generated result handlers
        void OnAddInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnCreateDraftItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnCreateUploadUrlsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnDeleteEntityItemReviewsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnDeleteInventoryCollectionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnDeleteInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnDeleteItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnExecuteInventoryOperationsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetCatalogConfigResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetDraftItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetDraftItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetEntityDraftItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetEntityItemReviewResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetInventoryCollectionIdsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetItemContainersResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetItemModerationStateResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetItemPublishStatusResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetItemReviewsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetItemReviewSummaryResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetMicrosoftStoreAccessTokensResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnPublishDraftItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnPurchaseInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnRedeemAppleAppStoreInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnRedeemGooglePlayInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnRedeemMicrosoftStoreInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnRedeemNintendoEShopInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnRedeemPlayStationStoreInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnRedeemSteamInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnReportItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnReportItemReviewResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnReviewItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnSearchItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnSetItemModerationStateResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnSubmitItemReviewVoteResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnSubtractInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnTakedownItemReviewsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnTransferInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnUpdateCatalogConfigResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnUpdateDraftItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnUpdateInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);

        bool ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container);
    };
}

#endif
