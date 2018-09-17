#pragma once

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabHttp.h>
#include <playfab/PlayFabGroupsDataModels.h>

namespace PlayFab
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Groups APIs
    /// </summary>
    class PlayFabGroupsAPI
    {
    public:
        static size_t Update();
        static void ForgetAllCredentials();


        // ------------ Generated API calls
        static void AcceptGroupApplication(GroupsModels::AcceptGroupApplicationRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AcceptGroupInvitation(GroupsModels::AcceptGroupInvitationRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddMembers(GroupsModels::AddMembersRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ApplyToGroup(GroupsModels::ApplyToGroupRequest& request, ProcessApiCallback<GroupsModels::ApplyToGroupResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void BlockEntity(GroupsModels::BlockEntityRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ChangeMemberRole(GroupsModels::ChangeMemberRoleRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateGroup(GroupsModels::CreateGroupRequest& request, ProcessApiCallback<GroupsModels::CreateGroupResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateRole(GroupsModels::CreateGroupRoleRequest& request, ProcessApiCallback<GroupsModels::CreateGroupRoleResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteGroup(GroupsModels::DeleteGroupRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteRole(GroupsModels::DeleteRoleRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetGroup(GroupsModels::GetGroupRequest& request, ProcessApiCallback<GroupsModels::GetGroupResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void InviteToGroup(GroupsModels::InviteToGroupRequest& request, ProcessApiCallback<GroupsModels::InviteToGroupResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void IsMember(GroupsModels::IsMemberRequest& request, ProcessApiCallback<GroupsModels::IsMemberResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListGroupApplications(GroupsModels::ListGroupApplicationsRequest& request, ProcessApiCallback<GroupsModels::ListGroupApplicationsResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListGroupBlocks(GroupsModels::ListGroupBlocksRequest& request, ProcessApiCallback<GroupsModels::ListGroupBlocksResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListGroupInvitations(GroupsModels::ListGroupInvitationsRequest& request, ProcessApiCallback<GroupsModels::ListGroupInvitationsResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListGroupMembers(GroupsModels::ListGroupMembersRequest& request, ProcessApiCallback<GroupsModels::ListGroupMembersResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListMembership(GroupsModels::ListMembershipRequest& request, ProcessApiCallback<GroupsModels::ListMembershipResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListMembershipOpportunities(GroupsModels::ListMembershipOpportunitiesRequest& request, ProcessApiCallback<GroupsModels::ListMembershipOpportunitiesResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemoveGroupApplication(GroupsModels::RemoveGroupApplicationRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemoveGroupInvitation(GroupsModels::RemoveGroupInvitationRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemoveMembers(GroupsModels::RemoveMembersRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnblockEntity(GroupsModels::UnblockEntityRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateGroup(GroupsModels::UpdateGroupRequest& request, ProcessApiCallback<GroupsModels::UpdateGroupResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateRole(GroupsModels::UpdateGroupRoleRequest& request, ProcessApiCallback<GroupsModels::UpdateGroupRoleResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        PlayFabGroupsAPI(); // Private constructor, static class should never have an instance
        PlayFabGroupsAPI(const PlayFabGroupsAPI& other); // Private copy-constructor, static class should never have an instance

        // ------------ Generated result handlers
        static void OnAcceptGroupApplicationResult(CallRequestContainerBase& request);
        static void OnAcceptGroupInvitationResult(CallRequestContainerBase& request);
        static void OnAddMembersResult(CallRequestContainerBase& request);
        static void OnApplyToGroupResult(CallRequestContainerBase& request);
        static void OnBlockEntityResult(CallRequestContainerBase& request);
        static void OnChangeMemberRoleResult(CallRequestContainerBase& request);
        static void OnCreateGroupResult(CallRequestContainerBase& request);
        static void OnCreateRoleResult(CallRequestContainerBase& request);
        static void OnDeleteGroupResult(CallRequestContainerBase& request);
        static void OnDeleteRoleResult(CallRequestContainerBase& request);
        static void OnGetGroupResult(CallRequestContainerBase& request);
        static void OnInviteToGroupResult(CallRequestContainerBase& request);
        static void OnIsMemberResult(CallRequestContainerBase& request);
        static void OnListGroupApplicationsResult(CallRequestContainerBase& request);
        static void OnListGroupBlocksResult(CallRequestContainerBase& request);
        static void OnListGroupInvitationsResult(CallRequestContainerBase& request);
        static void OnListGroupMembersResult(CallRequestContainerBase& request);
        static void OnListMembershipResult(CallRequestContainerBase& request);
        static void OnListMembershipOpportunitiesResult(CallRequestContainerBase& request);
        static void OnRemoveGroupApplicationResult(CallRequestContainerBase& request);
        static void OnRemoveGroupInvitationResult(CallRequestContainerBase& request);
        static void OnRemoveMembersResult(CallRequestContainerBase& request);
        static void OnUnblockEntityResult(CallRequestContainerBase& request);
        static void OnUpdateGroupResult(CallRequestContainerBase& request);
        static void OnUpdateRoleResult(CallRequestContainerBase& request);

    };
}

#endif
