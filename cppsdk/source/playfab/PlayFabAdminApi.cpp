#include <stdafx.h>

#ifdef ENABLE_PLAYFABADMIN_API

#include <playfab/PlayFabAdminApi.h>
#include <playfab/PlayFabHttp.h>
#include <playfab/PlayFabSettings.h>

namespace PlayFab
{
    using namespace AdminModels;

    size_t PlayFabAdminAPI::Update()
    {
        return PlayFabHttp::Get().Update();
    }

    void PlayFabAdminAPI::ForgetAllCredentials()
    {
        return PlayFabSettings::ForgetAllCredentials();
    }

    // PlayFabAdmin APIs

    void PlayFabAdminAPI::AbortTaskInstance(
        AbortTaskInstanceRequest& request,
        ProcessApiCallback<EmptyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/AbortTaskInstance", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnAbortTaskInstanceResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnAbortTaskInstanceResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        EmptyResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<EmptyResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::AddNews(
        AddNewsRequest& request,
        ProcessApiCallback<AddNewsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/AddNews", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnAddNewsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<AddNewsResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnAddNewsResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        AddNewsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<AddNewsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::AddPlayerTag(
        AddPlayerTagRequest& request,
        ProcessApiCallback<AddPlayerTagResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/AddPlayerTag", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnAddPlayerTagResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<AddPlayerTagResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnAddPlayerTagResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        AddPlayerTagResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<AddPlayerTagResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::AddServerBuild(
        AddServerBuildRequest& request,
        ProcessApiCallback<AddServerBuildResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/AddServerBuild", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnAddServerBuildResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<AddServerBuildResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnAddServerBuildResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        AddServerBuildResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<AddServerBuildResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::AddUserVirtualCurrency(
        AddUserVirtualCurrencyRequest& request,
        ProcessApiCallback<ModifyUserVirtualCurrencyResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/AddUserVirtualCurrency", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnAddUserVirtualCurrencyResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ModifyUserVirtualCurrencyResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnAddUserVirtualCurrencyResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        ModifyUserVirtualCurrencyResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<ModifyUserVirtualCurrencyResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::AddVirtualCurrencyTypes(
        AddVirtualCurrencyTypesRequest& request,
        ProcessApiCallback<BlankResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/AddVirtualCurrencyTypes", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnAddVirtualCurrencyTypesResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<BlankResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnAddVirtualCurrencyTypesResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        BlankResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<BlankResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::BanUsers(
        BanUsersRequest& request,
        ProcessApiCallback<BanUsersResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/BanUsers", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnBanUsersResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<BanUsersResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnBanUsersResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        BanUsersResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<BanUsersResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::CheckLimitedEditionItemAvailability(
        CheckLimitedEditionItemAvailabilityRequest& request,
        ProcessApiCallback<CheckLimitedEditionItemAvailabilityResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/CheckLimitedEditionItemAvailability", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnCheckLimitedEditionItemAvailabilityResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<CheckLimitedEditionItemAvailabilityResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnCheckLimitedEditionItemAvailabilityResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        CheckLimitedEditionItemAvailabilityResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<CheckLimitedEditionItemAvailabilityResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::CreateActionsOnPlayersInSegmentTask(
        CreateActionsOnPlayerSegmentTaskRequest& request,
        ProcessApiCallback<CreateTaskResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/CreateActionsOnPlayersInSegmentTask", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnCreateActionsOnPlayersInSegmentTaskResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<CreateTaskResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnCreateActionsOnPlayersInSegmentTaskResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        CreateTaskResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<CreateTaskResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::CreateCloudScriptTask(
        CreateCloudScriptTaskRequest& request,
        ProcessApiCallback<CreateTaskResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/CreateCloudScriptTask", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnCreateCloudScriptTaskResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<CreateTaskResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnCreateCloudScriptTaskResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        CreateTaskResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<CreateTaskResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::CreatePlayerSharedSecret(
        CreatePlayerSharedSecretRequest& request,
        ProcessApiCallback<CreatePlayerSharedSecretResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/CreatePlayerSharedSecret", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnCreatePlayerSharedSecretResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<CreatePlayerSharedSecretResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnCreatePlayerSharedSecretResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        CreatePlayerSharedSecretResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<CreatePlayerSharedSecretResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::CreatePlayerStatisticDefinition(
        CreatePlayerStatisticDefinitionRequest& request,
        ProcessApiCallback<CreatePlayerStatisticDefinitionResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/CreatePlayerStatisticDefinition", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnCreatePlayerStatisticDefinitionResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<CreatePlayerStatisticDefinitionResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnCreatePlayerStatisticDefinitionResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        CreatePlayerStatisticDefinitionResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<CreatePlayerStatisticDefinitionResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::DeleteContent(
        DeleteContentRequest& request,
        ProcessApiCallback<BlankResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/DeleteContent", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnDeleteContentResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<BlankResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnDeleteContentResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        BlankResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<BlankResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::DeleteMasterPlayerAccount(
        DeleteMasterPlayerAccountRequest& request,
        ProcessApiCallback<DeleteMasterPlayerAccountResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/DeleteMasterPlayerAccount", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnDeleteMasterPlayerAccountResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<DeleteMasterPlayerAccountResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnDeleteMasterPlayerAccountResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        DeleteMasterPlayerAccountResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<DeleteMasterPlayerAccountResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::DeletePlayer(
        DeletePlayerRequest& request,
        ProcessApiCallback<DeletePlayerResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/DeletePlayer", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnDeletePlayerResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<DeletePlayerResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnDeletePlayerResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        DeletePlayerResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<DeletePlayerResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::DeletePlayerSharedSecret(
        DeletePlayerSharedSecretRequest& request,
        ProcessApiCallback<DeletePlayerSharedSecretResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/DeletePlayerSharedSecret", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnDeletePlayerSharedSecretResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<DeletePlayerSharedSecretResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnDeletePlayerSharedSecretResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        DeletePlayerSharedSecretResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<DeletePlayerSharedSecretResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::DeleteStore(
        DeleteStoreRequest& request,
        ProcessApiCallback<DeleteStoreResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/DeleteStore", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnDeleteStoreResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<DeleteStoreResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnDeleteStoreResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        DeleteStoreResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<DeleteStoreResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::DeleteTask(
        DeleteTaskRequest& request,
        ProcessApiCallback<EmptyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/DeleteTask", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnDeleteTaskResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnDeleteTaskResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        EmptyResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<EmptyResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::DeleteTitle(
        DeleteTitleRequest& request,
        ProcessApiCallback<DeleteTitleResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/DeleteTitle", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnDeleteTitleResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<DeleteTitleResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnDeleteTitleResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        DeleteTitleResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<DeleteTitleResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::ExportMasterPlayerData(
        ExportMasterPlayerDataRequest& request,
        ProcessApiCallback<ExportMasterPlayerDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/ExportMasterPlayerData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnExportMasterPlayerDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ExportMasterPlayerDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnExportMasterPlayerDataResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        ExportMasterPlayerDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<ExportMasterPlayerDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetActionsOnPlayersInSegmentTaskInstance(
        GetTaskInstanceRequest& request,
        ProcessApiCallback<GetActionsOnPlayersInSegmentTaskInstanceResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetActionsOnPlayersInSegmentTaskInstance", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetActionsOnPlayersInSegmentTaskInstanceResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetActionsOnPlayersInSegmentTaskInstanceResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetActionsOnPlayersInSegmentTaskInstanceResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetActionsOnPlayersInSegmentTaskInstanceResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetActionsOnPlayersInSegmentTaskInstanceResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetAllSegments(
        GetAllSegmentsRequest& request,
        ProcessApiCallback<GetAllSegmentsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetAllSegments", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetAllSegmentsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetAllSegmentsResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetAllSegmentsResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetAllSegmentsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetAllSegmentsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetCatalogItems(
        GetCatalogItemsRequest& request,
        ProcessApiCallback<GetCatalogItemsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetCatalogItems", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetCatalogItemsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCatalogItemsResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetCatalogItemsResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetCatalogItemsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetCatalogItemsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetCloudScriptRevision(
        GetCloudScriptRevisionRequest& request,
        ProcessApiCallback<GetCloudScriptRevisionResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetCloudScriptRevision", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetCloudScriptRevisionResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCloudScriptRevisionResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetCloudScriptRevisionResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetCloudScriptRevisionResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetCloudScriptRevisionResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetCloudScriptTaskInstance(
        GetTaskInstanceRequest& request,
        ProcessApiCallback<GetCloudScriptTaskInstanceResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetCloudScriptTaskInstance", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetCloudScriptTaskInstanceResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCloudScriptTaskInstanceResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetCloudScriptTaskInstanceResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetCloudScriptTaskInstanceResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetCloudScriptTaskInstanceResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetCloudScriptVersions(
        GetCloudScriptVersionsRequest& request,
        ProcessApiCallback<GetCloudScriptVersionsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetCloudScriptVersions", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetCloudScriptVersionsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCloudScriptVersionsResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetCloudScriptVersionsResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetCloudScriptVersionsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetCloudScriptVersionsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetContentList(
        GetContentListRequest& request,
        ProcessApiCallback<GetContentListResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetContentList", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetContentListResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetContentListResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetContentListResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetContentListResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetContentListResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetContentUploadUrl(
        GetContentUploadUrlRequest& request,
        ProcessApiCallback<GetContentUploadUrlResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetContentUploadUrl", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetContentUploadUrlResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetContentUploadUrlResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetContentUploadUrlResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetContentUploadUrlResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetContentUploadUrlResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetDataReport(
        GetDataReportRequest& request,
        ProcessApiCallback<GetDataReportResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetDataReport", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetDataReportResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetDataReportResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetDataReportResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetDataReportResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetDataReportResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetMatchmakerGameInfo(
        GetMatchmakerGameInfoRequest& request,
        ProcessApiCallback<GetMatchmakerGameInfoResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetMatchmakerGameInfo", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetMatchmakerGameInfoResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetMatchmakerGameInfoResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetMatchmakerGameInfoResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetMatchmakerGameInfoResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetMatchmakerGameInfoResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetMatchmakerGameModes(
        GetMatchmakerGameModesRequest& request,
        ProcessApiCallback<GetMatchmakerGameModesResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetMatchmakerGameModes", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetMatchmakerGameModesResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetMatchmakerGameModesResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetMatchmakerGameModesResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetMatchmakerGameModesResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetMatchmakerGameModesResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetMatchmakingQueue(
        GetMatchmakingQueueRequest& request,
        ProcessApiCallback<GetMatchmakingQueueResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetMatchmakingQueue", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetMatchmakingQueueResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetMatchmakingQueueResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetMatchmakingQueueResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetMatchmakingQueueResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetMatchmakingQueueResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetPlayedTitleList(
        GetPlayedTitleListRequest& request,
        ProcessApiCallback<GetPlayedTitleListResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetPlayedTitleList", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetPlayedTitleListResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayedTitleListResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetPlayedTitleListResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetPlayedTitleListResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetPlayedTitleListResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetPlayerIdFromAuthToken(
        GetPlayerIdFromAuthTokenRequest& request,
        ProcessApiCallback<GetPlayerIdFromAuthTokenResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetPlayerIdFromAuthToken", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetPlayerIdFromAuthTokenResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerIdFromAuthTokenResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetPlayerIdFromAuthTokenResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetPlayerIdFromAuthTokenResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetPlayerIdFromAuthTokenResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetPlayerProfile(
        GetPlayerProfileRequest& request,
        ProcessApiCallback<GetPlayerProfileResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetPlayerProfile", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetPlayerProfileResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerProfileResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetPlayerProfileResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetPlayerProfileResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetPlayerProfileResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetPlayerSegments(
        GetPlayersSegmentsRequest& request,
        ProcessApiCallback<GetPlayerSegmentsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetPlayerSegments", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetPlayerSegmentsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerSegmentsResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetPlayerSegmentsResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetPlayerSegmentsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetPlayerSegmentsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetPlayerSharedSecrets(
        GetPlayerSharedSecretsRequest& request,
        ProcessApiCallback<GetPlayerSharedSecretsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetPlayerSharedSecrets", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetPlayerSharedSecretsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerSharedSecretsResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetPlayerSharedSecretsResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetPlayerSharedSecretsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetPlayerSharedSecretsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetPlayersInSegment(
        GetPlayersInSegmentRequest& request,
        ProcessApiCallback<GetPlayersInSegmentResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetPlayersInSegment", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetPlayersInSegmentResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayersInSegmentResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetPlayersInSegmentResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetPlayersInSegmentResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetPlayersInSegmentResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetPlayerStatisticDefinitions(
        GetPlayerStatisticDefinitionsRequest& request,
        ProcessApiCallback<GetPlayerStatisticDefinitionsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetPlayerStatisticDefinitions", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetPlayerStatisticDefinitionsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerStatisticDefinitionsResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetPlayerStatisticDefinitionsResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetPlayerStatisticDefinitionsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetPlayerStatisticDefinitionsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetPlayerStatisticVersions(
        GetPlayerStatisticVersionsRequest& request,
        ProcessApiCallback<GetPlayerStatisticVersionsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetPlayerStatisticVersions", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetPlayerStatisticVersionsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerStatisticVersionsResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetPlayerStatisticVersionsResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetPlayerStatisticVersionsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetPlayerStatisticVersionsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetPlayerTags(
        GetPlayerTagsRequest& request,
        ProcessApiCallback<GetPlayerTagsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetPlayerTags", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetPlayerTagsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerTagsResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetPlayerTagsResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetPlayerTagsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetPlayerTagsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetPolicy(
        GetPolicyRequest& request,
        ProcessApiCallback<GetPolicyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetPolicy", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetPolicyResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPolicyResponse>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetPolicyResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetPolicyResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetPolicyResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetPublisherData(
        GetPublisherDataRequest& request,
        ProcessApiCallback<GetPublisherDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetPublisherData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetPublisherDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPublisherDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetPublisherDataResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetPublisherDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetPublisherDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetRandomResultTables(
        GetRandomResultTablesRequest& request,
        ProcessApiCallback<GetRandomResultTablesResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetRandomResultTables", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetRandomResultTablesResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetRandomResultTablesResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetRandomResultTablesResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetRandomResultTablesResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetRandomResultTablesResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetServerBuildInfo(
        GetServerBuildInfoRequest& request,
        ProcessApiCallback<GetServerBuildInfoResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetServerBuildInfo", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetServerBuildInfoResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetServerBuildInfoResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetServerBuildInfoResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetServerBuildInfoResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetServerBuildInfoResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetServerBuildUploadUrl(
        GetServerBuildUploadURLRequest& request,
        ProcessApiCallback<GetServerBuildUploadURLResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetServerBuildUploadUrl", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetServerBuildUploadUrlResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetServerBuildUploadURLResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetServerBuildUploadUrlResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetServerBuildUploadURLResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetServerBuildUploadURLResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetStoreItems(
        GetStoreItemsRequest& request,
        ProcessApiCallback<GetStoreItemsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetStoreItems", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetStoreItemsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetStoreItemsResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetStoreItemsResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetStoreItemsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetStoreItemsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetTaskInstances(
        GetTaskInstancesRequest& request,
        ProcessApiCallback<GetTaskInstancesResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetTaskInstances", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetTaskInstancesResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetTaskInstancesResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetTaskInstancesResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetTaskInstancesResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetTaskInstancesResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetTasks(
        GetTasksRequest& request,
        ProcessApiCallback<GetTasksResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetTasks", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetTasksResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetTasksResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetTasksResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetTasksResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetTasksResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetTitleData(
        GetTitleDataRequest& request,
        ProcessApiCallback<GetTitleDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetTitleData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetTitleDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetTitleDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetTitleDataResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetTitleDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetTitleDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetTitleInternalData(
        GetTitleDataRequest& request,
        ProcessApiCallback<GetTitleDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetTitleInternalData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetTitleInternalDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetTitleDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetTitleInternalDataResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetTitleDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetTitleDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetUserAccountInfo(
        LookupUserAccountInfoRequest& request,
        ProcessApiCallback<LookupUserAccountInfoResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetUserAccountInfo", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetUserAccountInfoResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<LookupUserAccountInfoResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetUserAccountInfoResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        LookupUserAccountInfoResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<LookupUserAccountInfoResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetUserBans(
        GetUserBansRequest& request,
        ProcessApiCallback<GetUserBansResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetUserBans", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetUserBansResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserBansResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetUserBansResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetUserBansResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetUserBansResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetUserData(
        GetUserDataRequest& request,
        ProcessApiCallback<GetUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetUserData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetUserDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetUserDataResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetUserDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetUserDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetUserInternalData(
        GetUserDataRequest& request,
        ProcessApiCallback<GetUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetUserInternalData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetUserInternalDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetUserInternalDataResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetUserDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetUserDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetUserInventory(
        GetUserInventoryRequest& request,
        ProcessApiCallback<GetUserInventoryResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetUserInventory", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetUserInventoryResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserInventoryResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetUserInventoryResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetUserInventoryResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetUserInventoryResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetUserPublisherData(
        GetUserDataRequest& request,
        ProcessApiCallback<GetUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetUserPublisherData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetUserPublisherDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetUserPublisherDataResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetUserDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetUserDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetUserPublisherInternalData(
        GetUserDataRequest& request,
        ProcessApiCallback<GetUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetUserPublisherInternalData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetUserPublisherInternalDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetUserPublisherInternalDataResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetUserDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetUserDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetUserPublisherReadOnlyData(
        GetUserDataRequest& request,
        ProcessApiCallback<GetUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetUserPublisherReadOnlyData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetUserPublisherReadOnlyDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetUserPublisherReadOnlyDataResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetUserDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetUserDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetUserReadOnlyData(
        GetUserDataRequest& request,
        ProcessApiCallback<GetUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GetUserReadOnlyData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetUserReadOnlyDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetUserReadOnlyDataResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetUserDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetUserDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GrantItemsToUsers(
        GrantItemsToUsersRequest& request,
        ProcessApiCallback<GrantItemsToUsersResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/GrantItemsToUsers", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGrantItemsToUsersResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GrantItemsToUsersResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGrantItemsToUsersResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GrantItemsToUsersResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GrantItemsToUsersResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::IncrementLimitedEditionItemAvailability(
        IncrementLimitedEditionItemAvailabilityRequest& request,
        ProcessApiCallback<IncrementLimitedEditionItemAvailabilityResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/IncrementLimitedEditionItemAvailability", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnIncrementLimitedEditionItemAvailabilityResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<IncrementLimitedEditionItemAvailabilityResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnIncrementLimitedEditionItemAvailabilityResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        IncrementLimitedEditionItemAvailabilityResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<IncrementLimitedEditionItemAvailabilityResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::IncrementPlayerStatisticVersion(
        IncrementPlayerStatisticVersionRequest& request,
        ProcessApiCallback<IncrementPlayerStatisticVersionResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/IncrementPlayerStatisticVersion", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnIncrementPlayerStatisticVersionResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<IncrementPlayerStatisticVersionResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnIncrementPlayerStatisticVersionResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        IncrementPlayerStatisticVersionResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<IncrementPlayerStatisticVersionResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::ListMatchmakingQueues(
        ListMatchmakingQueuesRequest& request,
        ProcessApiCallback<ListMatchmakingQueuesResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/ListMatchmakingQueues", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnListMatchmakingQueuesResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ListMatchmakingQueuesResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnListMatchmakingQueuesResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        ListMatchmakingQueuesResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<ListMatchmakingQueuesResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::ListServerBuilds(
        ListBuildsRequest& request,
        ProcessApiCallback<ListBuildsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/ListServerBuilds", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnListServerBuildsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ListBuildsResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnListServerBuildsResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        ListBuildsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<ListBuildsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::ListVirtualCurrencyTypes(
        ListVirtualCurrencyTypesRequest& request,
        ProcessApiCallback<ListVirtualCurrencyTypesResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/ListVirtualCurrencyTypes", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnListVirtualCurrencyTypesResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ListVirtualCurrencyTypesResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnListVirtualCurrencyTypesResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        ListVirtualCurrencyTypesResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<ListVirtualCurrencyTypesResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::ModifyMatchmakerGameModes(
        ModifyMatchmakerGameModesRequest& request,
        ProcessApiCallback<ModifyMatchmakerGameModesResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/ModifyMatchmakerGameModes", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnModifyMatchmakerGameModesResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ModifyMatchmakerGameModesResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnModifyMatchmakerGameModesResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        ModifyMatchmakerGameModesResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<ModifyMatchmakerGameModesResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::ModifyServerBuild(
        ModifyServerBuildRequest& request,
        ProcessApiCallback<ModifyServerBuildResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/ModifyServerBuild", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnModifyServerBuildResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ModifyServerBuildResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnModifyServerBuildResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        ModifyServerBuildResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<ModifyServerBuildResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::RefundPurchase(
        RefundPurchaseRequest& request,
        ProcessApiCallback<RefundPurchaseResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/RefundPurchase", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnRefundPurchaseResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<RefundPurchaseResponse>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnRefundPurchaseResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        RefundPurchaseResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<RefundPurchaseResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::RemoveMatchmakingQueue(
        RemoveMatchmakingQueueRequest& request,
        ProcessApiCallback<RemoveMatchmakingQueueResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/RemoveMatchmakingQueue", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnRemoveMatchmakingQueueResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<RemoveMatchmakingQueueResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnRemoveMatchmakingQueueResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        RemoveMatchmakingQueueResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<RemoveMatchmakingQueueResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::RemovePlayerTag(
        RemovePlayerTagRequest& request,
        ProcessApiCallback<RemovePlayerTagResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/RemovePlayerTag", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnRemovePlayerTagResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<RemovePlayerTagResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnRemovePlayerTagResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        RemovePlayerTagResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<RemovePlayerTagResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::RemoveServerBuild(
        RemoveServerBuildRequest& request,
        ProcessApiCallback<RemoveServerBuildResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/RemoveServerBuild", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnRemoveServerBuildResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<RemoveServerBuildResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnRemoveServerBuildResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        RemoveServerBuildResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<RemoveServerBuildResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::RemoveVirtualCurrencyTypes(
        RemoveVirtualCurrencyTypesRequest& request,
        ProcessApiCallback<BlankResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/RemoveVirtualCurrencyTypes", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnRemoveVirtualCurrencyTypesResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<BlankResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnRemoveVirtualCurrencyTypesResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        BlankResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<BlankResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::ResetCharacterStatistics(
        ResetCharacterStatisticsRequest& request,
        ProcessApiCallback<ResetCharacterStatisticsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/ResetCharacterStatistics", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnResetCharacterStatisticsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ResetCharacterStatisticsResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnResetCharacterStatisticsResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        ResetCharacterStatisticsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<ResetCharacterStatisticsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::ResetPassword(
        ResetPasswordRequest& request,
        ProcessApiCallback<ResetPasswordResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/ResetPassword", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnResetPasswordResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ResetPasswordResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnResetPasswordResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        ResetPasswordResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<ResetPasswordResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::ResetUserStatistics(
        ResetUserStatisticsRequest& request,
        ProcessApiCallback<ResetUserStatisticsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/ResetUserStatistics", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnResetUserStatisticsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ResetUserStatisticsResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnResetUserStatisticsResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        ResetUserStatisticsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<ResetUserStatisticsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::ResolvePurchaseDispute(
        ResolvePurchaseDisputeRequest& request,
        ProcessApiCallback<ResolvePurchaseDisputeResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/ResolvePurchaseDispute", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnResolvePurchaseDisputeResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ResolvePurchaseDisputeResponse>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnResolvePurchaseDisputeResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        ResolvePurchaseDisputeResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<ResolvePurchaseDisputeResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::RevokeAllBansForUser(
        RevokeAllBansForUserRequest& request,
        ProcessApiCallback<RevokeAllBansForUserResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/RevokeAllBansForUser", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnRevokeAllBansForUserResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<RevokeAllBansForUserResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnRevokeAllBansForUserResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        RevokeAllBansForUserResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<RevokeAllBansForUserResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::RevokeBans(
        RevokeBansRequest& request,
        ProcessApiCallback<RevokeBansResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/RevokeBans", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnRevokeBansResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<RevokeBansResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnRevokeBansResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        RevokeBansResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<RevokeBansResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::RevokeInventoryItem(
        RevokeInventoryItemRequest& request,
        ProcessApiCallback<RevokeInventoryResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/RevokeInventoryItem", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnRevokeInventoryItemResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<RevokeInventoryResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnRevokeInventoryItemResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        RevokeInventoryResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<RevokeInventoryResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::RevokeInventoryItems(
        RevokeInventoryItemsRequest& request,
        ProcessApiCallback<RevokeInventoryItemsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/RevokeInventoryItems", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnRevokeInventoryItemsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<RevokeInventoryItemsResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnRevokeInventoryItemsResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        RevokeInventoryItemsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<RevokeInventoryItemsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::RunTask(
        RunTaskRequest& request,
        ProcessApiCallback<RunTaskResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/RunTask", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnRunTaskResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<RunTaskResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnRunTaskResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        RunTaskResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<RunTaskResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::SendAccountRecoveryEmail(
        SendAccountRecoveryEmailRequest& request,
        ProcessApiCallback<SendAccountRecoveryEmailResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/SendAccountRecoveryEmail", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnSendAccountRecoveryEmailResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<SendAccountRecoveryEmailResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnSendAccountRecoveryEmailResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        SendAccountRecoveryEmailResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<SendAccountRecoveryEmailResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::SetCatalogItems(
        UpdateCatalogItemsRequest& request,
        ProcessApiCallback<UpdateCatalogItemsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/SetCatalogItems", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnSetCatalogItemsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateCatalogItemsResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnSetCatalogItemsResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        UpdateCatalogItemsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<UpdateCatalogItemsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::SetMatchmakingQueue(
        SetMatchmakingQueueRequest& request,
        ProcessApiCallback<SetMatchmakingQueueResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/SetMatchmakingQueue", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnSetMatchmakingQueueResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<SetMatchmakingQueueResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnSetMatchmakingQueueResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        SetMatchmakingQueueResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<SetMatchmakingQueueResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::SetPlayerSecret(
        SetPlayerSecretRequest& request,
        ProcessApiCallback<SetPlayerSecretResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/SetPlayerSecret", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnSetPlayerSecretResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<SetPlayerSecretResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnSetPlayerSecretResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        SetPlayerSecretResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<SetPlayerSecretResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::SetPublishedRevision(
        SetPublishedRevisionRequest& request,
        ProcessApiCallback<SetPublishedRevisionResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/SetPublishedRevision", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnSetPublishedRevisionResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<SetPublishedRevisionResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnSetPublishedRevisionResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        SetPublishedRevisionResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<SetPublishedRevisionResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::SetPublisherData(
        SetPublisherDataRequest& request,
        ProcessApiCallback<SetPublisherDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/SetPublisherData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnSetPublisherDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<SetPublisherDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnSetPublisherDataResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        SetPublisherDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<SetPublisherDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::SetStoreItems(
        UpdateStoreItemsRequest& request,
        ProcessApiCallback<UpdateStoreItemsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/SetStoreItems", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnSetStoreItemsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateStoreItemsResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnSetStoreItemsResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        UpdateStoreItemsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<UpdateStoreItemsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::SetTitleData(
        SetTitleDataRequest& request,
        ProcessApiCallback<SetTitleDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/SetTitleData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnSetTitleDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<SetTitleDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnSetTitleDataResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        SetTitleDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<SetTitleDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::SetTitleInternalData(
        SetTitleDataRequest& request,
        ProcessApiCallback<SetTitleDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/SetTitleInternalData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnSetTitleInternalDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<SetTitleDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnSetTitleInternalDataResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        SetTitleDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<SetTitleDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::SetupPushNotification(
        SetupPushNotificationRequest& request,
        ProcessApiCallback<SetupPushNotificationResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/SetupPushNotification", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnSetupPushNotificationResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<SetupPushNotificationResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnSetupPushNotificationResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        SetupPushNotificationResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<SetupPushNotificationResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::SubtractUserVirtualCurrency(
        SubtractUserVirtualCurrencyRequest& request,
        ProcessApiCallback<ModifyUserVirtualCurrencyResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/SubtractUserVirtualCurrency", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnSubtractUserVirtualCurrencyResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ModifyUserVirtualCurrencyResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnSubtractUserVirtualCurrencyResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        ModifyUserVirtualCurrencyResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<ModifyUserVirtualCurrencyResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::UpdateBans(
        UpdateBansRequest& request,
        ProcessApiCallback<UpdateBansResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/UpdateBans", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateBansResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateBansResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnUpdateBansResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        UpdateBansResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<UpdateBansResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::UpdateCatalogItems(
        UpdateCatalogItemsRequest& request,
        ProcessApiCallback<UpdateCatalogItemsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/UpdateCatalogItems", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateCatalogItemsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateCatalogItemsResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnUpdateCatalogItemsResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        UpdateCatalogItemsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<UpdateCatalogItemsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::UpdateCloudScript(
        UpdateCloudScriptRequest& request,
        ProcessApiCallback<UpdateCloudScriptResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/UpdateCloudScript", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateCloudScriptResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateCloudScriptResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnUpdateCloudScriptResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        UpdateCloudScriptResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<UpdateCloudScriptResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::UpdatePlayerSharedSecret(
        UpdatePlayerSharedSecretRequest& request,
        ProcessApiCallback<UpdatePlayerSharedSecretResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/UpdatePlayerSharedSecret", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdatePlayerSharedSecretResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdatePlayerSharedSecretResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnUpdatePlayerSharedSecretResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        UpdatePlayerSharedSecretResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<UpdatePlayerSharedSecretResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::UpdatePlayerStatisticDefinition(
        UpdatePlayerStatisticDefinitionRequest& request,
        ProcessApiCallback<UpdatePlayerStatisticDefinitionResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/UpdatePlayerStatisticDefinition", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdatePlayerStatisticDefinitionResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdatePlayerStatisticDefinitionResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnUpdatePlayerStatisticDefinitionResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        UpdatePlayerStatisticDefinitionResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<UpdatePlayerStatisticDefinitionResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::UpdatePolicy(
        UpdatePolicyRequest& request,
        ProcessApiCallback<UpdatePolicyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/UpdatePolicy", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdatePolicyResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdatePolicyResponse>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnUpdatePolicyResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        UpdatePolicyResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<UpdatePolicyResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::UpdateRandomResultTables(
        UpdateRandomResultTablesRequest& request,
        ProcessApiCallback<UpdateRandomResultTablesResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/UpdateRandomResultTables", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateRandomResultTablesResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateRandomResultTablesResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnUpdateRandomResultTablesResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        UpdateRandomResultTablesResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<UpdateRandomResultTablesResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::UpdateStoreItems(
        UpdateStoreItemsRequest& request,
        ProcessApiCallback<UpdateStoreItemsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/UpdateStoreItems", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateStoreItemsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateStoreItemsResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnUpdateStoreItemsResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        UpdateStoreItemsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<UpdateStoreItemsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::UpdateTask(
        UpdateTaskRequest& request,
        ProcessApiCallback<EmptyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/UpdateTask", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateTaskResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnUpdateTaskResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        EmptyResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<EmptyResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::UpdateUserData(
        UpdateUserDataRequest& request,
        ProcessApiCallback<UpdateUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/UpdateUserData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateUserDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnUpdateUserDataResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        UpdateUserDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<UpdateUserDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::UpdateUserInternalData(
        UpdateUserInternalDataRequest& request,
        ProcessApiCallback<UpdateUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/UpdateUserInternalData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateUserInternalDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnUpdateUserInternalDataResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        UpdateUserDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<UpdateUserDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::UpdateUserPublisherData(
        UpdateUserDataRequest& request,
        ProcessApiCallback<UpdateUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/UpdateUserPublisherData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateUserPublisherDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnUpdateUserPublisherDataResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        UpdateUserDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<UpdateUserDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::UpdateUserPublisherInternalData(
        UpdateUserInternalDataRequest& request,
        ProcessApiCallback<UpdateUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/UpdateUserPublisherInternalData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateUserPublisherInternalDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnUpdateUserPublisherInternalDataResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        UpdateUserDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<UpdateUserDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::UpdateUserPublisherReadOnlyData(
        UpdateUserDataRequest& request,
        ProcessApiCallback<UpdateUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/UpdateUserPublisherReadOnlyData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateUserPublisherReadOnlyDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnUpdateUserPublisherReadOnlyDataResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        UpdateUserDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<UpdateUserDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::UpdateUserReadOnlyData(
        UpdateUserDataRequest& request,
        ProcessApiCallback<UpdateUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/UpdateUserReadOnlyData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateUserReadOnlyDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnUpdateUserReadOnlyDataResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        UpdateUserDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<UpdateUserDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::UpdateUserTitleDisplayName(
        UpdateUserTitleDisplayNameRequest& request,
        ProcessApiCallback<UpdateUserTitleDisplayNameResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Admin/UpdateUserTitleDisplayName", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateUserTitleDisplayNameResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserTitleDisplayNameResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnUpdateUserTitleDisplayNameResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        UpdateUserTitleDisplayNameResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<UpdateUserTitleDisplayNameResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }
}

#endif
