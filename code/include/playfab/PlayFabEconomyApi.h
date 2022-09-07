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
        static void CreateDraftItem(EconomyModels::CreateDraftItemRequest& request, const ProcessApiCallback<EconomyModels::CreateDraftItemResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateUploadUrls(EconomyModels::CreateUploadUrlsRequest& request, const ProcessApiCallback<EconomyModels::CreateUploadUrlsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteEntityItemReviews(EconomyModels::DeleteEntityItemReviewsRequest& request, const ProcessApiCallback<EconomyModels::DeleteEntityItemReviewsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteItem(EconomyModels::DeleteItemRequest& request, const ProcessApiCallback<EconomyModels::DeleteItemResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCatalogConfig(EconomyModels::GetCatalogConfigRequest& request, const ProcessApiCallback<EconomyModels::GetCatalogConfigResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetDraftItem(EconomyModels::GetDraftItemRequest& request, const ProcessApiCallback<EconomyModels::GetDraftItemResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetDraftItems(EconomyModels::GetDraftItemsRequest& request, const ProcessApiCallback<EconomyModels::GetDraftItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetEntityDraftItems(EconomyModels::GetEntityDraftItemsRequest& request, const ProcessApiCallback<EconomyModels::GetEntityDraftItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetEntityItemReview(EconomyModels::GetEntityItemReviewRequest& request, const ProcessApiCallback<EconomyModels::GetEntityItemReviewResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetItem(EconomyModels::GetItemRequest& request, const ProcessApiCallback<EconomyModels::GetItemResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetItemModerationState(EconomyModels::GetItemModerationStateRequest& request, const ProcessApiCallback<EconomyModels::GetItemModerationStateResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetItemPublishStatus(EconomyModels::GetItemPublishStatusRequest& request, const ProcessApiCallback<EconomyModels::GetItemPublishStatusResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetItemReviews(EconomyModels::GetItemReviewsRequest& request, const ProcessApiCallback<EconomyModels::GetItemReviewsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetItemReviewSummary(EconomyModels::GetItemReviewSummaryRequest& request, const ProcessApiCallback<EconomyModels::GetItemReviewSummaryResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetItems(EconomyModels::GetItemsRequest& request, const ProcessApiCallback<EconomyModels::GetItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void PublishDraftItem(EconomyModels::PublishDraftItemRequest& request, const ProcessApiCallback<EconomyModels::PublishDraftItemResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ReportItem(EconomyModels::ReportItemRequest& request, const ProcessApiCallback<EconomyModels::ReportItemResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ReportItemReview(EconomyModels::ReportItemReviewRequest& request, const ProcessApiCallback<EconomyModels::ReportItemReviewResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ReviewItem(EconomyModels::ReviewItemRequest& request, const ProcessApiCallback<EconomyModels::ReviewItemResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SearchItems(EconomyModels::SearchItemsRequest& request, const ProcessApiCallback<EconomyModels::SearchItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetItemModerationState(EconomyModels::SetItemModerationStateRequest& request, const ProcessApiCallback<EconomyModels::SetItemModerationStateResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SubmitItemReviewVote(EconomyModels::SubmitItemReviewVoteRequest& request, const ProcessApiCallback<EconomyModels::SubmitItemReviewVoteResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void TakedownItemReviews(EconomyModels::TakedownItemReviewsRequest& request, const ProcessApiCallback<EconomyModels::TakedownItemReviewsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateCatalogConfig(EconomyModels::UpdateCatalogConfigRequest& request, const ProcessApiCallback<EconomyModels::UpdateCatalogConfigResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateDraftItem(EconomyModels::UpdateDraftItemRequest& request, const ProcessApiCallback<EconomyModels::UpdateDraftItemResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        PlayFabEconomyAPI(); // Private constructor, static class should never have an instance
        PlayFabEconomyAPI(const PlayFabEconomyAPI& other); // Private copy-constructor, static class should never have an instance

        // ------------ Generated result handlers
        static void OnCreateDraftItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnCreateUploadUrlsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteEntityItemReviewsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetCatalogConfigResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetDraftItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetDraftItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetEntityDraftItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetEntityItemReviewResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetItemModerationStateResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetItemPublishStatusResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetItemReviewsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetItemReviewSummaryResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnPublishDraftItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnReportItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnReportItemReviewResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnReviewItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnSearchItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnSetItemModerationStateResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnSubmitItemReviewVoteResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnTakedownItemReviewsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnUpdateCatalogConfigResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnUpdateDraftItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);

        static bool ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container);
    };
}

#endif // #if !defined(DISABLE_PLAYFABENTITY_API)
