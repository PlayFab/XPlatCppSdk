#pragma once

#if !defined(DISABLE_PLAYFABENTITY_API)

#include <playfab/PlayFabEconomyDataModels.h>
#include <playfab/PlayFabError.h>

namespace PlayFab
{
    class CallRequestContainerBase;
    class CallRequestContainer;

    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Economy APIs
    /// </summary>
    class PlayFabEconomyAPI
    {
    public:
        /// <summary>
        /// Calls the Update function on your implementation of the IHttpPlugin to check for responses to HTTP requests.
        /// All api's (Client, Server, Admin etc.) share the same IHttpPlugin. 
        /// This means that you only need to call Update() on one API to retrieve the responses for all APIs.
        /// Additional calls to Update (on any API) during the same tick are unlikely to retrieve additional responses.
        /// Call Update when your game ticks as follows:
        ///     Economy.Update();
        /// </summary>
        static size_t Update();
        static void ForgetAllCredentials();


        // ------------ Generated API calls
        static void AddInventoryItems(EconomyModels::AddInventoryItemsRequest& request, const ProcessApiCallback<EconomyModels::AddInventoryItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateDraftItem(EconomyModels::CreateDraftItemRequest& request, const ProcessApiCallback<EconomyModels::CreateDraftItemResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateUploadUrls(EconomyModels::CreateUploadUrlsRequest& request, const ProcessApiCallback<EconomyModels::CreateUploadUrlsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteEntityItemReviews(EconomyModels::DeleteEntityItemReviewsRequest& request, const ProcessApiCallback<EconomyModels::DeleteEntityItemReviewsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteInventoryCollection(EconomyModels::DeleteInventoryCollectionRequest& request, const ProcessApiCallback<EconomyModels::DeleteInventoryCollectionResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteInventoryItems(EconomyModels::DeleteInventoryItemsRequest& request, const ProcessApiCallback<EconomyModels::DeleteInventoryItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteItem(EconomyModels::DeleteItemRequest& request, const ProcessApiCallback<EconomyModels::DeleteItemResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ExecuteInventoryOperations(EconomyModels::ExecuteInventoryOperationsRequest& request, const ProcessApiCallback<EconomyModels::ExecuteInventoryOperationsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCatalogConfig(EconomyModels::GetCatalogConfigRequest& request, const ProcessApiCallback<EconomyModels::GetCatalogConfigResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetDraftItem(EconomyModels::GetDraftItemRequest& request, const ProcessApiCallback<EconomyModels::GetDraftItemResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetDraftItems(EconomyModels::GetDraftItemsRequest& request, const ProcessApiCallback<EconomyModels::GetDraftItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetEntityDraftItems(EconomyModels::GetEntityDraftItemsRequest& request, const ProcessApiCallback<EconomyModels::GetEntityDraftItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetEntityItemReview(EconomyModels::GetEntityItemReviewRequest& request, const ProcessApiCallback<EconomyModels::GetEntityItemReviewResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetInventoryCollectionIds(EconomyModels::GetInventoryCollectionIdsRequest& request, const ProcessApiCallback<EconomyModels::GetInventoryCollectionIdsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetInventoryItems(EconomyModels::GetInventoryItemsRequest& request, const ProcessApiCallback<EconomyModels::GetInventoryItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetItem(EconomyModels::GetItemRequest& request, const ProcessApiCallback<EconomyModels::GetItemResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetItemContainers(EconomyModels::GetItemContainersRequest& request, const ProcessApiCallback<EconomyModels::GetItemContainersResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetItemModerationState(EconomyModels::GetItemModerationStateRequest& request, const ProcessApiCallback<EconomyModels::GetItemModerationStateResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetItemPublishStatus(EconomyModels::GetItemPublishStatusRequest& request, const ProcessApiCallback<EconomyModels::GetItemPublishStatusResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetItemReviews(EconomyModels::GetItemReviewsRequest& request, const ProcessApiCallback<EconomyModels::GetItemReviewsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetItemReviewSummary(EconomyModels::GetItemReviewSummaryRequest& request, const ProcessApiCallback<EconomyModels::GetItemReviewSummaryResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetItems(EconomyModels::GetItemsRequest& request, const ProcessApiCallback<EconomyModels::GetItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetMicrosoftStoreAccessTokens(EconomyModels::GetMicrosoftStoreAccessTokensRequest& request, const ProcessApiCallback<EconomyModels::GetMicrosoftStoreAccessTokensResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void PublishDraftItem(EconomyModels::PublishDraftItemRequest& request, const ProcessApiCallback<EconomyModels::PublishDraftItemResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void PurchaseInventoryItems(EconomyModels::PurchaseInventoryItemsRequest& request, const ProcessApiCallback<EconomyModels::PurchaseInventoryItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RedeemAppleAppStoreInventoryItems(EconomyModels::RedeemAppleAppStoreInventoryItemsRequest& request, const ProcessApiCallback<EconomyModels::RedeemAppleAppStoreInventoryItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RedeemGooglePlayInventoryItems(EconomyModels::RedeemGooglePlayInventoryItemsRequest& request, const ProcessApiCallback<EconomyModels::RedeemGooglePlayInventoryItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RedeemMicrosoftStoreInventoryItems(EconomyModels::RedeemMicrosoftStoreInventoryItemsRequest& request, const ProcessApiCallback<EconomyModels::RedeemMicrosoftStoreInventoryItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RedeemNintendoEShopInventoryItems(EconomyModels::RedeemNintendoEShopInventoryItemsRequest& request, const ProcessApiCallback<EconomyModels::RedeemNintendoEShopInventoryItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RedeemPlayStationStoreInventoryItems(EconomyModels::RedeemPlayStationStoreInventoryItemsRequest& request, const ProcessApiCallback<EconomyModels::RedeemPlayStationStoreInventoryItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RedeemSteamInventoryItems(EconomyModels::RedeemSteamInventoryItemsRequest& request, const ProcessApiCallback<EconomyModels::RedeemSteamInventoryItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ReportItem(EconomyModels::ReportItemRequest& request, const ProcessApiCallback<EconomyModels::ReportItemResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ReportItemReview(EconomyModels::ReportItemReviewRequest& request, const ProcessApiCallback<EconomyModels::ReportItemReviewResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ReviewItem(EconomyModels::ReviewItemRequest& request, const ProcessApiCallback<EconomyModels::ReviewItemResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SearchItems(EconomyModels::SearchItemsRequest& request, const ProcessApiCallback<EconomyModels::SearchItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetItemModerationState(EconomyModels::SetItemModerationStateRequest& request, const ProcessApiCallback<EconomyModels::SetItemModerationStateResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SubmitItemReviewVote(EconomyModels::SubmitItemReviewVoteRequest& request, const ProcessApiCallback<EconomyModels::SubmitItemReviewVoteResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SubtractInventoryItems(EconomyModels::SubtractInventoryItemsRequest& request, const ProcessApiCallback<EconomyModels::SubtractInventoryItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void TakedownItemReviews(EconomyModels::TakedownItemReviewsRequest& request, const ProcessApiCallback<EconomyModels::TakedownItemReviewsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void TransferInventoryItems(EconomyModels::TransferInventoryItemsRequest& request, const ProcessApiCallback<EconomyModels::TransferInventoryItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateCatalogConfig(EconomyModels::UpdateCatalogConfigRequest& request, const ProcessApiCallback<EconomyModels::UpdateCatalogConfigResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateDraftItem(EconomyModels::UpdateDraftItemRequest& request, const ProcessApiCallback<EconomyModels::UpdateDraftItemResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateInventoryItems(EconomyModels::UpdateInventoryItemsRequest& request, const ProcessApiCallback<EconomyModels::UpdateInventoryItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        PlayFabEconomyAPI(); // Private constructor, static class should never have an instance
        PlayFabEconomyAPI(const PlayFabEconomyAPI& other); // Private copy-constructor, static class should never have an instance

        // ------------ Generated result handlers
        static void OnAddInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnCreateDraftItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnCreateUploadUrlsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteEntityItemReviewsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteInventoryCollectionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnExecuteInventoryOperationsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetCatalogConfigResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetDraftItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetDraftItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetEntityDraftItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetEntityItemReviewResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetInventoryCollectionIdsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetItemContainersResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetItemModerationStateResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetItemPublishStatusResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetItemReviewsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetItemReviewSummaryResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetMicrosoftStoreAccessTokensResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnPublishDraftItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnPurchaseInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnRedeemAppleAppStoreInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnRedeemGooglePlayInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnRedeemMicrosoftStoreInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnRedeemNintendoEShopInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnRedeemPlayStationStoreInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnRedeemSteamInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnReportItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnReportItemReviewResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnReviewItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnSearchItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnSetItemModerationStateResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnSubmitItemReviewVoteResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnSubtractInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnTakedownItemReviewsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnTransferInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnUpdateCatalogConfigResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnUpdateDraftItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnUpdateInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);

        static bool ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container);
    };
}

#endif // #if !defined(DISABLE_PLAYFABENTITY_API)
