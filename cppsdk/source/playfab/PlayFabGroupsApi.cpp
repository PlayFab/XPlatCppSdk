#include <stdafx.h>

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabGroupsApi.h>
#include <playfab/PlayFabHttp.h>
#include <playfab/PlayFabSettings.h>

namespace PlayFab
{
    using namespace GroupsModels;

    size_t PlayFabGroupsAPI::Update()
    {
        return PlayFabHttp::Get().Update();
    }

    void PlayFabGroupsAPI::ForgetAllCredentials()
    {
        return PlayFabSettings::ForgetAllCredentials();
    }

    // PlayFabGroups APIs

    void PlayFabGroupsAPI::AcceptGroupApplication(
        AcceptGroupApplicationRequest& request,
        ProcessApiCallback<EmptyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Group/AcceptGroupApplication", "X-EntityToken", PlayFabSettings::entityToken, requestJson, OnAcceptGroupApplicationResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnAcceptGroupApplicationResult(CallRequestContainerBase& pRequest)
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

    void PlayFabGroupsAPI::AcceptGroupInvitation(
        AcceptGroupInvitationRequest& request,
        ProcessApiCallback<EmptyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Group/AcceptGroupInvitation", "X-EntityToken", PlayFabSettings::entityToken, requestJson, OnAcceptGroupInvitationResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnAcceptGroupInvitationResult(CallRequestContainerBase& pRequest)
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

    void PlayFabGroupsAPI::AddMembers(
        AddMembersRequest& request,
        ProcessApiCallback<EmptyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Group/AddMembers", "X-EntityToken", PlayFabSettings::entityToken, requestJson, OnAddMembersResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnAddMembersResult(CallRequestContainerBase& pRequest)
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

    void PlayFabGroupsAPI::ApplyToGroup(
        ApplyToGroupRequest& request,
        ProcessApiCallback<ApplyToGroupResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Group/ApplyToGroup", "X-EntityToken", PlayFabSettings::entityToken, requestJson, OnApplyToGroupResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ApplyToGroupResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnApplyToGroupResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        ApplyToGroupResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<ApplyToGroupResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabGroupsAPI::BlockEntity(
        BlockEntityRequest& request,
        ProcessApiCallback<EmptyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Group/BlockEntity", "X-EntityToken", PlayFabSettings::entityToken, requestJson, OnBlockEntityResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnBlockEntityResult(CallRequestContainerBase& pRequest)
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

    void PlayFabGroupsAPI::ChangeMemberRole(
        ChangeMemberRoleRequest& request,
        ProcessApiCallback<EmptyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Group/ChangeMemberRole", "X-EntityToken", PlayFabSettings::entityToken, requestJson, OnChangeMemberRoleResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnChangeMemberRoleResult(CallRequestContainerBase& pRequest)
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

    void PlayFabGroupsAPI::CreateGroup(
        CreateGroupRequest& request,
        ProcessApiCallback<CreateGroupResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Group/CreateGroup", "X-EntityToken", PlayFabSettings::entityToken, requestJson, OnCreateGroupResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<CreateGroupResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnCreateGroupResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        CreateGroupResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<CreateGroupResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabGroupsAPI::CreateRole(
        CreateGroupRoleRequest& request,
        ProcessApiCallback<CreateGroupRoleResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Group/CreateRole", "X-EntityToken", PlayFabSettings::entityToken, requestJson, OnCreateRoleResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<CreateGroupRoleResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnCreateRoleResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        CreateGroupRoleResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<CreateGroupRoleResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabGroupsAPI::DeleteGroup(
        DeleteGroupRequest& request,
        ProcessApiCallback<EmptyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Group/DeleteGroup", "X-EntityToken", PlayFabSettings::entityToken, requestJson, OnDeleteGroupResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnDeleteGroupResult(CallRequestContainerBase& pRequest)
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

    void PlayFabGroupsAPI::DeleteRole(
        DeleteRoleRequest& request,
        ProcessApiCallback<EmptyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Group/DeleteRole", "X-EntityToken", PlayFabSettings::entityToken, requestJson, OnDeleteRoleResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnDeleteRoleResult(CallRequestContainerBase& pRequest)
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

    void PlayFabGroupsAPI::GetGroup(
        GetGroupRequest& request,
        ProcessApiCallback<GetGroupResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Group/GetGroup", "X-EntityToken", PlayFabSettings::entityToken, requestJson, OnGetGroupResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetGroupResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnGetGroupResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetGroupResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetGroupResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabGroupsAPI::InviteToGroup(
        InviteToGroupRequest& request,
        ProcessApiCallback<InviteToGroupResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Group/InviteToGroup", "X-EntityToken", PlayFabSettings::entityToken, requestJson, OnInviteToGroupResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<InviteToGroupResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnInviteToGroupResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        InviteToGroupResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<InviteToGroupResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabGroupsAPI::IsMember(
        IsMemberRequest& request,
        ProcessApiCallback<IsMemberResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Group/IsMember", "X-EntityToken", PlayFabSettings::entityToken, requestJson, OnIsMemberResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<IsMemberResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnIsMemberResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        IsMemberResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<IsMemberResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabGroupsAPI::ListGroupApplications(
        ListGroupApplicationsRequest& request,
        ProcessApiCallback<ListGroupApplicationsResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Group/ListGroupApplications", "X-EntityToken", PlayFabSettings::entityToken, requestJson, OnListGroupApplicationsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ListGroupApplicationsResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnListGroupApplicationsResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        ListGroupApplicationsResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<ListGroupApplicationsResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabGroupsAPI::ListGroupBlocks(
        ListGroupBlocksRequest& request,
        ProcessApiCallback<ListGroupBlocksResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Group/ListGroupBlocks", "X-EntityToken", PlayFabSettings::entityToken, requestJson, OnListGroupBlocksResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ListGroupBlocksResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnListGroupBlocksResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        ListGroupBlocksResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<ListGroupBlocksResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabGroupsAPI::ListGroupInvitations(
        ListGroupInvitationsRequest& request,
        ProcessApiCallback<ListGroupInvitationsResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Group/ListGroupInvitations", "X-EntityToken", PlayFabSettings::entityToken, requestJson, OnListGroupInvitationsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ListGroupInvitationsResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnListGroupInvitationsResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        ListGroupInvitationsResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<ListGroupInvitationsResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabGroupsAPI::ListGroupMembers(
        ListGroupMembersRequest& request,
        ProcessApiCallback<ListGroupMembersResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Group/ListGroupMembers", "X-EntityToken", PlayFabSettings::entityToken, requestJson, OnListGroupMembersResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ListGroupMembersResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnListGroupMembersResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        ListGroupMembersResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<ListGroupMembersResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabGroupsAPI::ListMembership(
        ListMembershipRequest& request,
        ProcessApiCallback<ListMembershipResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Group/ListMembership", "X-EntityToken", PlayFabSettings::entityToken, requestJson, OnListMembershipResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ListMembershipResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnListMembershipResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        ListMembershipResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<ListMembershipResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabGroupsAPI::ListMembershipOpportunities(
        ListMembershipOpportunitiesRequest& request,
        ProcessApiCallback<ListMembershipOpportunitiesResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Group/ListMembershipOpportunities", "X-EntityToken", PlayFabSettings::entityToken, requestJson, OnListMembershipOpportunitiesResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ListMembershipOpportunitiesResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnListMembershipOpportunitiesResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        ListMembershipOpportunitiesResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<ListMembershipOpportunitiesResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabGroupsAPI::RemoveGroupApplication(
        RemoveGroupApplicationRequest& request,
        ProcessApiCallback<EmptyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Group/RemoveGroupApplication", "X-EntityToken", PlayFabSettings::entityToken, requestJson, OnRemoveGroupApplicationResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnRemoveGroupApplicationResult(CallRequestContainerBase& pRequest)
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

    void PlayFabGroupsAPI::RemoveGroupInvitation(
        RemoveGroupInvitationRequest& request,
        ProcessApiCallback<EmptyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Group/RemoveGroupInvitation", "X-EntityToken", PlayFabSettings::entityToken, requestJson, OnRemoveGroupInvitationResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnRemoveGroupInvitationResult(CallRequestContainerBase& pRequest)
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

    void PlayFabGroupsAPI::RemoveMembers(
        RemoveMembersRequest& request,
        ProcessApiCallback<EmptyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Group/RemoveMembers", "X-EntityToken", PlayFabSettings::entityToken, requestJson, OnRemoveMembersResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnRemoveMembersResult(CallRequestContainerBase& pRequest)
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

    void PlayFabGroupsAPI::UnblockEntity(
        UnblockEntityRequest& request,
        ProcessApiCallback<EmptyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Group/UnblockEntity", "X-EntityToken", PlayFabSettings::entityToken, requestJson, OnUnblockEntityResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnUnblockEntityResult(CallRequestContainerBase& pRequest)
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

    void PlayFabGroupsAPI::UpdateGroup(
        UpdateGroupRequest& request,
        ProcessApiCallback<UpdateGroupResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Group/UpdateGroup", "X-EntityToken", PlayFabSettings::entityToken, requestJson, OnUpdateGroupResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateGroupResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnUpdateGroupResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        UpdateGroupResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<UpdateGroupResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabGroupsAPI::UpdateRole(
        UpdateGroupRoleRequest& request,
        ProcessApiCallback<UpdateGroupRoleResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Group/UpdateRole", "X-EntityToken", PlayFabSettings::entityToken, requestJson, OnUpdateRoleResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateGroupRoleResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnUpdateRoleResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        UpdateGroupRoleResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<UpdateGroupRoleResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }
}

#endif
