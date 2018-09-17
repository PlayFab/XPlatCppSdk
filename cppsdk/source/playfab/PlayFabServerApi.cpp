#include <stdafx.h>

#ifdef ENABLE_PLAYFABSERVER_API

#include <playfab/PlayFabServerApi.h>
#include <playfab/PlayFabHttp.h>
#include <playfab/PlayFabSettings.h>

namespace PlayFab
{
    using namespace ServerModels;

    size_t PlayFabServerAPI::Update()
    {
        return PlayFabHttp::Get().Update();
    }

    void PlayFabServerAPI::ForgetAllCredentials()
    {
        return PlayFabSettings::ForgetAllCredentials();
    }

    // PlayFabServer APIs

    void PlayFabServerAPI::AddCharacterVirtualCurrency(
        AddCharacterVirtualCurrencyRequest& request,
        ProcessApiCallback<ModifyCharacterVirtualCurrencyResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/AddCharacterVirtualCurrency", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnAddCharacterVirtualCurrencyResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ModifyCharacterVirtualCurrencyResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnAddCharacterVirtualCurrencyResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        ModifyCharacterVirtualCurrencyResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<ModifyCharacterVirtualCurrencyResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::AddFriend(
        AddFriendRequest& request,
        ProcessApiCallback<EmptyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/AddFriend", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnAddFriendResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnAddFriendResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::AddPlayerTag(
        AddPlayerTagRequest& request,
        ProcessApiCallback<AddPlayerTagResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/AddPlayerTag", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnAddPlayerTagResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<AddPlayerTagResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnAddPlayerTagResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::AddSharedGroupMembers(
        AddSharedGroupMembersRequest& request,
        ProcessApiCallback<AddSharedGroupMembersResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/AddSharedGroupMembers", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnAddSharedGroupMembersResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<AddSharedGroupMembersResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnAddSharedGroupMembersResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        AddSharedGroupMembersResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<AddSharedGroupMembersResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::AddUserVirtualCurrency(
        AddUserVirtualCurrencyRequest& request,
        ProcessApiCallback<ModifyUserVirtualCurrencyResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/AddUserVirtualCurrency", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnAddUserVirtualCurrencyResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ModifyUserVirtualCurrencyResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnAddUserVirtualCurrencyResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::AuthenticateSessionTicket(
        AuthenticateSessionTicketRequest& request,
        ProcessApiCallback<AuthenticateSessionTicketResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/AuthenticateSessionTicket", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnAuthenticateSessionTicketResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<AuthenticateSessionTicketResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnAuthenticateSessionTicketResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        AuthenticateSessionTicketResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<AuthenticateSessionTicketResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::AwardSteamAchievement(
        AwardSteamAchievementRequest& request,
        ProcessApiCallback<AwardSteamAchievementResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/AwardSteamAchievement", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnAwardSteamAchievementResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<AwardSteamAchievementResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnAwardSteamAchievementResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        AwardSteamAchievementResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<AwardSteamAchievementResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::BanUsers(
        BanUsersRequest& request,
        ProcessApiCallback<BanUsersResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/BanUsers", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnBanUsersResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<BanUsersResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnBanUsersResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::ConsumeItem(
        ConsumeItemRequest& request,
        ProcessApiCallback<ConsumeItemResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/ConsumeItem", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnConsumeItemResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ConsumeItemResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnConsumeItemResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        ConsumeItemResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<ConsumeItemResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::CreateSharedGroup(
        CreateSharedGroupRequest& request,
        ProcessApiCallback<CreateSharedGroupResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/CreateSharedGroup", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnCreateSharedGroupResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<CreateSharedGroupResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnCreateSharedGroupResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        CreateSharedGroupResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<CreateSharedGroupResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::DeleteCharacterFromUser(
        DeleteCharacterFromUserRequest& request,
        ProcessApiCallback<DeleteCharacterFromUserResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/DeleteCharacterFromUser", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnDeleteCharacterFromUserResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<DeleteCharacterFromUserResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnDeleteCharacterFromUserResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        DeleteCharacterFromUserResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<DeleteCharacterFromUserResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::DeletePlayer(
        DeletePlayerRequest& request,
        ProcessApiCallback<DeletePlayerResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/DeletePlayer", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnDeletePlayerResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<DeletePlayerResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnDeletePlayerResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::DeleteSharedGroup(
        DeleteSharedGroupRequest& request,
        ProcessApiCallback<EmptyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/DeleteSharedGroup", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnDeleteSharedGroupResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnDeleteSharedGroupResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::DeleteUsers(
        DeleteUsersRequest& request,
        ProcessApiCallback<DeleteUsersResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/DeleteUsers", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnDeleteUsersResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<DeleteUsersResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnDeleteUsersResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        DeleteUsersResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<DeleteUsersResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::DeregisterGame(
        DeregisterGameRequest& request,
        ProcessApiCallback<DeregisterGameResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/DeregisterGame", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnDeregisterGameResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<DeregisterGameResponse>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnDeregisterGameResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        DeregisterGameResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<DeregisterGameResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::EvaluateRandomResultTable(
        EvaluateRandomResultTableRequest& request,
        ProcessApiCallback<EvaluateRandomResultTableResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/EvaluateRandomResultTable", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnEvaluateRandomResultTableResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<EvaluateRandomResultTableResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnEvaluateRandomResultTableResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        EvaluateRandomResultTableResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<EvaluateRandomResultTableResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::ExecuteCloudScript(
        ExecuteCloudScriptServerRequest& request,
        ProcessApiCallback<ExecuteCloudScriptResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/ExecuteCloudScript", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnExecuteCloudScriptResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ExecuteCloudScriptResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnExecuteCloudScriptResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        ExecuteCloudScriptResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<ExecuteCloudScriptResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::GetAllSegments(
        GetAllSegmentsRequest& request,
        ProcessApiCallback<GetAllSegmentsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetAllSegments", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetAllSegmentsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetAllSegmentsResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetAllSegmentsResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::GetAllUsersCharacters(
        ListUsersCharactersRequest& request,
        ProcessApiCallback<ListUsersCharactersResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetAllUsersCharacters", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetAllUsersCharactersResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ListUsersCharactersResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetAllUsersCharactersResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        ListUsersCharactersResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<ListUsersCharactersResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::GetCatalogItems(
        GetCatalogItemsRequest& request,
        ProcessApiCallback<GetCatalogItemsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetCatalogItems", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetCatalogItemsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCatalogItemsResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetCatalogItemsResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::GetCharacterData(
        GetCharacterDataRequest& request,
        ProcessApiCallback<GetCharacterDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetCharacterData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetCharacterDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCharacterDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetCharacterDataResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetCharacterDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetCharacterDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::GetCharacterInternalData(
        GetCharacterDataRequest& request,
        ProcessApiCallback<GetCharacterDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetCharacterInternalData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetCharacterInternalDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCharacterDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetCharacterInternalDataResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetCharacterDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetCharacterDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::GetCharacterInventory(
        GetCharacterInventoryRequest& request,
        ProcessApiCallback<GetCharacterInventoryResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetCharacterInventory", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetCharacterInventoryResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCharacterInventoryResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetCharacterInventoryResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetCharacterInventoryResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetCharacterInventoryResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::GetCharacterLeaderboard(
        GetCharacterLeaderboardRequest& request,
        ProcessApiCallback<GetCharacterLeaderboardResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetCharacterLeaderboard", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetCharacterLeaderboardResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCharacterLeaderboardResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetCharacterLeaderboardResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetCharacterLeaderboardResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetCharacterLeaderboardResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::GetCharacterReadOnlyData(
        GetCharacterDataRequest& request,
        ProcessApiCallback<GetCharacterDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetCharacterReadOnlyData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetCharacterReadOnlyDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCharacterDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetCharacterReadOnlyDataResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetCharacterDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetCharacterDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::GetCharacterStatistics(
        GetCharacterStatisticsRequest& request,
        ProcessApiCallback<GetCharacterStatisticsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetCharacterStatistics", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetCharacterStatisticsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCharacterStatisticsResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetCharacterStatisticsResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetCharacterStatisticsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetCharacterStatisticsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::GetContentDownloadUrl(
        GetContentDownloadUrlRequest& request,
        ProcessApiCallback<GetContentDownloadUrlResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetContentDownloadUrl", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetContentDownloadUrlResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetContentDownloadUrlResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetContentDownloadUrlResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetContentDownloadUrlResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetContentDownloadUrlResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::GetFriendLeaderboard(
        GetFriendLeaderboardRequest& request,
        ProcessApiCallback<GetLeaderboardResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetFriendLeaderboard", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetFriendLeaderboardResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetLeaderboardResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetFriendLeaderboardResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetLeaderboardResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetLeaderboardResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::GetFriendsList(
        GetFriendsListRequest& request,
        ProcessApiCallback<GetFriendsListResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetFriendsList", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetFriendsListResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetFriendsListResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetFriendsListResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetFriendsListResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetFriendsListResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::GetLeaderboard(
        GetLeaderboardRequest& request,
        ProcessApiCallback<GetLeaderboardResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetLeaderboard", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetLeaderboardResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetLeaderboardResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetLeaderboardResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetLeaderboardResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetLeaderboardResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::GetLeaderboardAroundCharacter(
        GetLeaderboardAroundCharacterRequest& request,
        ProcessApiCallback<GetLeaderboardAroundCharacterResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetLeaderboardAroundCharacter", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetLeaderboardAroundCharacterResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetLeaderboardAroundCharacterResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetLeaderboardAroundCharacterResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetLeaderboardAroundCharacterResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetLeaderboardAroundCharacterResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::GetLeaderboardAroundUser(
        GetLeaderboardAroundUserRequest& request,
        ProcessApiCallback<GetLeaderboardAroundUserResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetLeaderboardAroundUser", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetLeaderboardAroundUserResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetLeaderboardAroundUserResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetLeaderboardAroundUserResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetLeaderboardAroundUserResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetLeaderboardAroundUserResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::GetLeaderboardForUserCharacters(
        GetLeaderboardForUsersCharactersRequest& request,
        ProcessApiCallback<GetLeaderboardForUsersCharactersResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetLeaderboardForUserCharacters", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetLeaderboardForUserCharactersResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetLeaderboardForUsersCharactersResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetLeaderboardForUserCharactersResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetLeaderboardForUsersCharactersResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetLeaderboardForUsersCharactersResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::GetPlayerCombinedInfo(
        GetPlayerCombinedInfoRequest& request,
        ProcessApiCallback<GetPlayerCombinedInfoResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetPlayerCombinedInfo", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetPlayerCombinedInfoResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerCombinedInfoResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetPlayerCombinedInfoResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetPlayerCombinedInfoResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetPlayerCombinedInfoResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::GetPlayerProfile(
        GetPlayerProfileRequest& request,
        ProcessApiCallback<GetPlayerProfileResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetPlayerProfile", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetPlayerProfileResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerProfileResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetPlayerProfileResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::GetPlayerSegments(
        GetPlayersSegmentsRequest& request,
        ProcessApiCallback<GetPlayerSegmentsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetPlayerSegments", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetPlayerSegmentsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerSegmentsResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetPlayerSegmentsResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::GetPlayersInSegment(
        GetPlayersInSegmentRequest& request,
        ProcessApiCallback<GetPlayersInSegmentResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetPlayersInSegment", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetPlayersInSegmentResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayersInSegmentResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetPlayersInSegmentResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::GetPlayerStatistics(
        GetPlayerStatisticsRequest& request,
        ProcessApiCallback<GetPlayerStatisticsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetPlayerStatistics", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetPlayerStatisticsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerStatisticsResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetPlayerStatisticsResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetPlayerStatisticsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetPlayerStatisticsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::GetPlayerStatisticVersions(
        GetPlayerStatisticVersionsRequest& request,
        ProcessApiCallback<GetPlayerStatisticVersionsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetPlayerStatisticVersions", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetPlayerStatisticVersionsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerStatisticVersionsResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetPlayerStatisticVersionsResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::GetPlayerTags(
        GetPlayerTagsRequest& request,
        ProcessApiCallback<GetPlayerTagsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetPlayerTags", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetPlayerTagsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerTagsResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetPlayerTagsResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::GetPlayFabIDsFromFacebookIDs(
        GetPlayFabIDsFromFacebookIDsRequest& request,
        ProcessApiCallback<GetPlayFabIDsFromFacebookIDsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetPlayFabIDsFromFacebookIDs", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetPlayFabIDsFromFacebookIDsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromFacebookIDsResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetPlayFabIDsFromFacebookIDsResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetPlayFabIDsFromFacebookIDsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetPlayFabIDsFromFacebookIDsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::GetPlayFabIDsFromFacebookInstantGamesIds(
        GetPlayFabIDsFromFacebookInstantGamesIdsRequest& request,
        ProcessApiCallback<GetPlayFabIDsFromFacebookInstantGamesIdsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetPlayFabIDsFromFacebookInstantGamesIds", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetPlayFabIDsFromFacebookInstantGamesIdsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromFacebookInstantGamesIdsResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetPlayFabIDsFromFacebookInstantGamesIdsResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetPlayFabIDsFromFacebookInstantGamesIdsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetPlayFabIDsFromFacebookInstantGamesIdsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::GetPlayFabIDsFromNintendoSwitchDeviceIds(
        GetPlayFabIDsFromNintendoSwitchDeviceIdsRequest& request,
        ProcessApiCallback<GetPlayFabIDsFromNintendoSwitchDeviceIdsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetPlayFabIDsFromNintendoSwitchDeviceIds", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetPlayFabIDsFromNintendoSwitchDeviceIdsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromNintendoSwitchDeviceIdsResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetPlayFabIDsFromNintendoSwitchDeviceIdsResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetPlayFabIDsFromNintendoSwitchDeviceIdsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetPlayFabIDsFromNintendoSwitchDeviceIdsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::GetPlayFabIDsFromSteamIDs(
        GetPlayFabIDsFromSteamIDsRequest& request,
        ProcessApiCallback<GetPlayFabIDsFromSteamIDsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetPlayFabIDsFromSteamIDs", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetPlayFabIDsFromSteamIDsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromSteamIDsResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetPlayFabIDsFromSteamIDsResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetPlayFabIDsFromSteamIDsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetPlayFabIDsFromSteamIDsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::GetPublisherData(
        GetPublisherDataRequest& request,
        ProcessApiCallback<GetPublisherDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetPublisherData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetPublisherDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPublisherDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetPublisherDataResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::GetRandomResultTables(
        GetRandomResultTablesRequest& request,
        ProcessApiCallback<GetRandomResultTablesResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetRandomResultTables", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetRandomResultTablesResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetRandomResultTablesResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetRandomResultTablesResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::GetSharedGroupData(
        GetSharedGroupDataRequest& request,
        ProcessApiCallback<GetSharedGroupDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetSharedGroupData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetSharedGroupDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetSharedGroupDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetSharedGroupDataResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetSharedGroupDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetSharedGroupDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::GetTime(
        GetTimeRequest& request,
        ProcessApiCallback<GetTimeResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetTime", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetTimeResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetTimeResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetTimeResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetTimeResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetTimeResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::GetTitleData(
        GetTitleDataRequest& request,
        ProcessApiCallback<GetTitleDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetTitleData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetTitleDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetTitleDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetTitleDataResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::GetTitleInternalData(
        GetTitleDataRequest& request,
        ProcessApiCallback<GetTitleDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetTitleInternalData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetTitleInternalDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetTitleDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetTitleInternalDataResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::GetTitleNews(
        GetTitleNewsRequest& request,
        ProcessApiCallback<GetTitleNewsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetTitleNews", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetTitleNewsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetTitleNewsResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetTitleNewsResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetTitleNewsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetTitleNewsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::GetUserAccountInfo(
        GetUserAccountInfoRequest& request,
        ProcessApiCallback<GetUserAccountInfoResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetUserAccountInfo", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetUserAccountInfoResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserAccountInfoResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetUserAccountInfoResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetUserAccountInfoResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetUserAccountInfoResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::GetUserBans(
        GetUserBansRequest& request,
        ProcessApiCallback<GetUserBansResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetUserBans", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetUserBansResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserBansResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetUserBansResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::GetUserData(
        GetUserDataRequest& request,
        ProcessApiCallback<GetUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetUserData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetUserDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetUserDataResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::GetUserInternalData(
        GetUserDataRequest& request,
        ProcessApiCallback<GetUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetUserInternalData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetUserInternalDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetUserInternalDataResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::GetUserInventory(
        GetUserInventoryRequest& request,
        ProcessApiCallback<GetUserInventoryResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetUserInventory", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetUserInventoryResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserInventoryResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetUserInventoryResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::GetUserPublisherData(
        GetUserDataRequest& request,
        ProcessApiCallback<GetUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetUserPublisherData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetUserPublisherDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetUserPublisherDataResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::GetUserPublisherInternalData(
        GetUserDataRequest& request,
        ProcessApiCallback<GetUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetUserPublisherInternalData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetUserPublisherInternalDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetUserPublisherInternalDataResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::GetUserPublisherReadOnlyData(
        GetUserDataRequest& request,
        ProcessApiCallback<GetUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetUserPublisherReadOnlyData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetUserPublisherReadOnlyDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetUserPublisherReadOnlyDataResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::GetUserReadOnlyData(
        GetUserDataRequest& request,
        ProcessApiCallback<GetUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GetUserReadOnlyData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetUserReadOnlyDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGetUserReadOnlyDataResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::GrantCharacterToUser(
        GrantCharacterToUserRequest& request,
        ProcessApiCallback<GrantCharacterToUserResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GrantCharacterToUser", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGrantCharacterToUserResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GrantCharacterToUserResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGrantCharacterToUserResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GrantCharacterToUserResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GrantCharacterToUserResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::GrantItemsToCharacter(
        GrantItemsToCharacterRequest& request,
        ProcessApiCallback<GrantItemsToCharacterResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GrantItemsToCharacter", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGrantItemsToCharacterResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GrantItemsToCharacterResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGrantItemsToCharacterResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GrantItemsToCharacterResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GrantItemsToCharacterResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::GrantItemsToUser(
        GrantItemsToUserRequest& request,
        ProcessApiCallback<GrantItemsToUserResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GrantItemsToUser", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGrantItemsToUserResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GrantItemsToUserResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGrantItemsToUserResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GrantItemsToUserResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GrantItemsToUserResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::GrantItemsToUsers(
        GrantItemsToUsersRequest& request,
        ProcessApiCallback<GrantItemsToUsersResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/GrantItemsToUsers", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGrantItemsToUsersResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GrantItemsToUsersResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnGrantItemsToUsersResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::ModifyItemUses(
        ModifyItemUsesRequest& request,
        ProcessApiCallback<ModifyItemUsesResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/ModifyItemUses", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnModifyItemUsesResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ModifyItemUsesResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnModifyItemUsesResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        ModifyItemUsesResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<ModifyItemUsesResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::MoveItemToCharacterFromCharacter(
        MoveItemToCharacterFromCharacterRequest& request,
        ProcessApiCallback<MoveItemToCharacterFromCharacterResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/MoveItemToCharacterFromCharacter", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnMoveItemToCharacterFromCharacterResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<MoveItemToCharacterFromCharacterResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnMoveItemToCharacterFromCharacterResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        MoveItemToCharacterFromCharacterResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<MoveItemToCharacterFromCharacterResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::MoveItemToCharacterFromUser(
        MoveItemToCharacterFromUserRequest& request,
        ProcessApiCallback<MoveItemToCharacterFromUserResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/MoveItemToCharacterFromUser", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnMoveItemToCharacterFromUserResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<MoveItemToCharacterFromUserResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnMoveItemToCharacterFromUserResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        MoveItemToCharacterFromUserResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<MoveItemToCharacterFromUserResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::MoveItemToUserFromCharacter(
        MoveItemToUserFromCharacterRequest& request,
        ProcessApiCallback<MoveItemToUserFromCharacterResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/MoveItemToUserFromCharacter", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnMoveItemToUserFromCharacterResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<MoveItemToUserFromCharacterResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnMoveItemToUserFromCharacterResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        MoveItemToUserFromCharacterResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<MoveItemToUserFromCharacterResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::NotifyMatchmakerPlayerLeft(
        NotifyMatchmakerPlayerLeftRequest& request,
        ProcessApiCallback<NotifyMatchmakerPlayerLeftResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/NotifyMatchmakerPlayerLeft", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnNotifyMatchmakerPlayerLeftResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<NotifyMatchmakerPlayerLeftResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnNotifyMatchmakerPlayerLeftResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        NotifyMatchmakerPlayerLeftResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<NotifyMatchmakerPlayerLeftResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::RedeemCoupon(
        RedeemCouponRequest& request,
        ProcessApiCallback<RedeemCouponResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/RedeemCoupon", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnRedeemCouponResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<RedeemCouponResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnRedeemCouponResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        RedeemCouponResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<RedeemCouponResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::RedeemMatchmakerTicket(
        RedeemMatchmakerTicketRequest& request,
        ProcessApiCallback<RedeemMatchmakerTicketResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/RedeemMatchmakerTicket", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnRedeemMatchmakerTicketResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<RedeemMatchmakerTicketResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnRedeemMatchmakerTicketResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        RedeemMatchmakerTicketResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<RedeemMatchmakerTicketResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::RefreshGameServerInstanceHeartbeat(
        RefreshGameServerInstanceHeartbeatRequest& request,
        ProcessApiCallback<RefreshGameServerInstanceHeartbeatResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/RefreshGameServerInstanceHeartbeat", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnRefreshGameServerInstanceHeartbeatResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<RefreshGameServerInstanceHeartbeatResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnRefreshGameServerInstanceHeartbeatResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        RefreshGameServerInstanceHeartbeatResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<RefreshGameServerInstanceHeartbeatResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::RegisterGame(
        RegisterGameRequest& request,
        ProcessApiCallback<RegisterGameResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/RegisterGame", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnRegisterGameResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<RegisterGameResponse>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnRegisterGameResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        RegisterGameResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<RegisterGameResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::RemoveFriend(
        RemoveFriendRequest& request,
        ProcessApiCallback<EmptyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/RemoveFriend", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnRemoveFriendResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnRemoveFriendResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::RemovePlayerTag(
        RemovePlayerTagRequest& request,
        ProcessApiCallback<RemovePlayerTagResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/RemovePlayerTag", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnRemovePlayerTagResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<RemovePlayerTagResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnRemovePlayerTagResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::RemoveSharedGroupMembers(
        RemoveSharedGroupMembersRequest& request,
        ProcessApiCallback<RemoveSharedGroupMembersResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/RemoveSharedGroupMembers", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnRemoveSharedGroupMembersResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<RemoveSharedGroupMembersResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnRemoveSharedGroupMembersResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        RemoveSharedGroupMembersResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<RemoveSharedGroupMembersResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::ReportPlayer(
        ReportPlayerServerRequest& request,
        ProcessApiCallback<ReportPlayerServerResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/ReportPlayer", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnReportPlayerResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ReportPlayerServerResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnReportPlayerResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        ReportPlayerServerResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<ReportPlayerServerResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::RevokeAllBansForUser(
        RevokeAllBansForUserRequest& request,
        ProcessApiCallback<RevokeAllBansForUserResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/RevokeAllBansForUser", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnRevokeAllBansForUserResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<RevokeAllBansForUserResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnRevokeAllBansForUserResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::RevokeBans(
        RevokeBansRequest& request,
        ProcessApiCallback<RevokeBansResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/RevokeBans", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnRevokeBansResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<RevokeBansResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnRevokeBansResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::RevokeInventoryItem(
        RevokeInventoryItemRequest& request,
        ProcessApiCallback<RevokeInventoryResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/RevokeInventoryItem", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnRevokeInventoryItemResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<RevokeInventoryResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnRevokeInventoryItemResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::RevokeInventoryItems(
        RevokeInventoryItemsRequest& request,
        ProcessApiCallback<RevokeInventoryItemsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/RevokeInventoryItems", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnRevokeInventoryItemsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<RevokeInventoryItemsResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnRevokeInventoryItemsResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::SendCustomAccountRecoveryEmail(
        SendCustomAccountRecoveryEmailRequest& request,
        ProcessApiCallback<SendCustomAccountRecoveryEmailResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/SendCustomAccountRecoveryEmail", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnSendCustomAccountRecoveryEmailResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<SendCustomAccountRecoveryEmailResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnSendCustomAccountRecoveryEmailResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        SendCustomAccountRecoveryEmailResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<SendCustomAccountRecoveryEmailResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::SendEmailFromTemplate(
        SendEmailFromTemplateRequest& request,
        ProcessApiCallback<SendEmailFromTemplateResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/SendEmailFromTemplate", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnSendEmailFromTemplateResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<SendEmailFromTemplateResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnSendEmailFromTemplateResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        SendEmailFromTemplateResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<SendEmailFromTemplateResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::SendPushNotification(
        SendPushNotificationRequest& request,
        ProcessApiCallback<SendPushNotificationResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/SendPushNotification", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnSendPushNotificationResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<SendPushNotificationResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnSendPushNotificationResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        SendPushNotificationResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<SendPushNotificationResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::SetFriendTags(
        SetFriendTagsRequest& request,
        ProcessApiCallback<EmptyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/SetFriendTags", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnSetFriendTagsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnSetFriendTagsResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::SetGameServerInstanceData(
        SetGameServerInstanceDataRequest& request,
        ProcessApiCallback<SetGameServerInstanceDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/SetGameServerInstanceData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnSetGameServerInstanceDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<SetGameServerInstanceDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnSetGameServerInstanceDataResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        SetGameServerInstanceDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<SetGameServerInstanceDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::SetGameServerInstanceState(
        SetGameServerInstanceStateRequest& request,
        ProcessApiCallback<SetGameServerInstanceStateResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/SetGameServerInstanceState", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnSetGameServerInstanceStateResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<SetGameServerInstanceStateResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnSetGameServerInstanceStateResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        SetGameServerInstanceStateResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<SetGameServerInstanceStateResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::SetGameServerInstanceTags(
        SetGameServerInstanceTagsRequest& request,
        ProcessApiCallback<SetGameServerInstanceTagsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/SetGameServerInstanceTags", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnSetGameServerInstanceTagsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<SetGameServerInstanceTagsResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnSetGameServerInstanceTagsResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        SetGameServerInstanceTagsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<SetGameServerInstanceTagsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::SetPlayerSecret(
        SetPlayerSecretRequest& request,
        ProcessApiCallback<SetPlayerSecretResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/SetPlayerSecret", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnSetPlayerSecretResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<SetPlayerSecretResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnSetPlayerSecretResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::SetPublisherData(
        SetPublisherDataRequest& request,
        ProcessApiCallback<SetPublisherDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/SetPublisherData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnSetPublisherDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<SetPublisherDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnSetPublisherDataResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::SetTitleData(
        SetTitleDataRequest& request,
        ProcessApiCallback<SetTitleDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/SetTitleData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnSetTitleDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<SetTitleDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnSetTitleDataResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::SetTitleInternalData(
        SetTitleDataRequest& request,
        ProcessApiCallback<SetTitleDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/SetTitleInternalData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnSetTitleInternalDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<SetTitleDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnSetTitleInternalDataResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::SubtractCharacterVirtualCurrency(
        SubtractCharacterVirtualCurrencyRequest& request,
        ProcessApiCallback<ModifyCharacterVirtualCurrencyResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/SubtractCharacterVirtualCurrency", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnSubtractCharacterVirtualCurrencyResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ModifyCharacterVirtualCurrencyResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnSubtractCharacterVirtualCurrencyResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        ModifyCharacterVirtualCurrencyResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<ModifyCharacterVirtualCurrencyResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::SubtractUserVirtualCurrency(
        SubtractUserVirtualCurrencyRequest& request,
        ProcessApiCallback<ModifyUserVirtualCurrencyResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/SubtractUserVirtualCurrency", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnSubtractUserVirtualCurrencyResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ModifyUserVirtualCurrencyResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnSubtractUserVirtualCurrencyResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::UnlockContainerInstance(
        UnlockContainerInstanceRequest& request,
        ProcessApiCallback<UnlockContainerItemResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/UnlockContainerInstance", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUnlockContainerInstanceResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlockContainerItemResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnUnlockContainerInstanceResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        UnlockContainerItemResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<UnlockContainerItemResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::UnlockContainerItem(
        UnlockContainerItemRequest& request,
        ProcessApiCallback<UnlockContainerItemResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/UnlockContainerItem", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUnlockContainerItemResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlockContainerItemResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnUnlockContainerItemResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        UnlockContainerItemResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<UnlockContainerItemResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::UpdateAvatarUrl(
        UpdateAvatarUrlRequest& request,
        ProcessApiCallback<EmptyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/UpdateAvatarUrl", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateAvatarUrlResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnUpdateAvatarUrlResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::UpdateBans(
        UpdateBansRequest& request,
        ProcessApiCallback<UpdateBansResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/UpdateBans", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateBansResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateBansResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnUpdateBansResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::UpdateCharacterData(
        UpdateCharacterDataRequest& request,
        ProcessApiCallback<UpdateCharacterDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/UpdateCharacterData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateCharacterDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateCharacterDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnUpdateCharacterDataResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        UpdateCharacterDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<UpdateCharacterDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::UpdateCharacterInternalData(
        UpdateCharacterDataRequest& request,
        ProcessApiCallback<UpdateCharacterDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/UpdateCharacterInternalData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateCharacterInternalDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateCharacterDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnUpdateCharacterInternalDataResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        UpdateCharacterDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<UpdateCharacterDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::UpdateCharacterReadOnlyData(
        UpdateCharacterDataRequest& request,
        ProcessApiCallback<UpdateCharacterDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/UpdateCharacterReadOnlyData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateCharacterReadOnlyDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateCharacterDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnUpdateCharacterReadOnlyDataResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        UpdateCharacterDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<UpdateCharacterDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::UpdateCharacterStatistics(
        UpdateCharacterStatisticsRequest& request,
        ProcessApiCallback<UpdateCharacterStatisticsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/UpdateCharacterStatistics", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateCharacterStatisticsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateCharacterStatisticsResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnUpdateCharacterStatisticsResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        UpdateCharacterStatisticsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<UpdateCharacterStatisticsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::UpdatePlayerStatistics(
        UpdatePlayerStatisticsRequest& request,
        ProcessApiCallback<UpdatePlayerStatisticsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/UpdatePlayerStatistics", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdatePlayerStatisticsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdatePlayerStatisticsResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnUpdatePlayerStatisticsResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        UpdatePlayerStatisticsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<UpdatePlayerStatisticsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::UpdateSharedGroupData(
        UpdateSharedGroupDataRequest& request,
        ProcessApiCallback<UpdateSharedGroupDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/UpdateSharedGroupData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateSharedGroupDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateSharedGroupDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnUpdateSharedGroupDataResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        UpdateSharedGroupDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<UpdateSharedGroupDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::UpdateUserData(
        UpdateUserDataRequest& request,
        ProcessApiCallback<UpdateUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/UpdateUserData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateUserDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnUpdateUserDataResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::UpdateUserInternalData(
        UpdateUserInternalDataRequest& request,
        ProcessApiCallback<UpdateUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/UpdateUserInternalData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateUserInternalDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnUpdateUserInternalDataResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::UpdateUserInventoryItemCustomData(
        UpdateUserInventoryItemDataRequest& request,
        ProcessApiCallback<EmptyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/UpdateUserInventoryItemCustomData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateUserInventoryItemCustomDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnUpdateUserInventoryItemCustomDataResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::UpdateUserPublisherData(
        UpdateUserDataRequest& request,
        ProcessApiCallback<UpdateUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/UpdateUserPublisherData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateUserPublisherDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnUpdateUserPublisherDataResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::UpdateUserPublisherInternalData(
        UpdateUserInternalDataRequest& request,
        ProcessApiCallback<UpdateUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/UpdateUserPublisherInternalData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateUserPublisherInternalDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnUpdateUserPublisherInternalDataResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::UpdateUserPublisherReadOnlyData(
        UpdateUserDataRequest& request,
        ProcessApiCallback<UpdateUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/UpdateUserPublisherReadOnlyData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateUserPublisherReadOnlyDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnUpdateUserPublisherReadOnlyDataResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::UpdateUserReadOnlyData(
        UpdateUserDataRequest& request,
        ProcessApiCallback<UpdateUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/UpdateUserReadOnlyData", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateUserReadOnlyDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnUpdateUserReadOnlyDataResult(CallRequestContainerBase& pRequest)
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

    void PlayFabServerAPI::WriteCharacterEvent(
        WriteServerCharacterEventRequest& request,
        ProcessApiCallback<WriteEventResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/WriteCharacterEvent", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnWriteCharacterEventResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<WriteEventResponse>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnWriteCharacterEventResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        WriteEventResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<WriteEventResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::WritePlayerEvent(
        WriteServerPlayerEventRequest& request,
        ProcessApiCallback<WriteEventResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/WritePlayerEvent", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnWritePlayerEventResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<WriteEventResponse>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnWritePlayerEventResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        WriteEventResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<WriteEventResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabServerAPI::WriteTitleEvent(
        WriteTitleEventRequest& request,
        ProcessApiCallback<WriteEventResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Server/WriteTitleEvent", "X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnWriteTitleEventResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<WriteEventResponse>(callback)), errorCallback, customData);
    }

    void PlayFabServerAPI::OnWriteTitleEventResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        WriteEventResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<WriteEventResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }
}

#endif
