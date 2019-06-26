#pragma once

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabApiSettings.h>
#include <playfab/PlayFabAuthenticationContext.h>
#include <playfab/PlayFabGroupsDataModels.h>
#include <memory>

#ifndef PLAYFAB_PLATFORM_PLAYSTATION // Issue 32699
namespace PlayFab
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Groups APIs
    /// </summary>
    class PlayFabGroupsInstanceAPI
    {
    private:
        std::shared_ptr<PlayFabApiSettings> settings;
        std::shared_ptr<PlayFabAuthenticationContext> authContext;

    public:
        PlayFabGroupsInstanceAPI();
        explicit PlayFabGroupsInstanceAPI(std::shared_ptr<PlayFabApiSettings> apiSettings);
        explicit PlayFabGroupsInstanceAPI(std::shared_ptr<PlayFabAuthenticationContext> authenticationContext);
        PlayFabGroupsInstanceAPI(std::shared_ptr<PlayFabApiSettings> apiSettings, std::shared_ptr<PlayFabAuthenticationContext> authenticationContext);
        ~PlayFabGroupsInstanceAPI();
        PlayFabGroupsInstanceAPI(const PlayFabGroupsInstanceAPI& source) = delete; // disable copy
        PlayFabGroupsInstanceAPI(PlayFabGroupsInstanceAPI&&) = delete; // disable move
        PlayFabGroupsInstanceAPI& operator=(const PlayFabGroupsInstanceAPI& source) = delete; // disable assignment
        PlayFabGroupsInstanceAPI& operator=(PlayFabGroupsInstanceAPI&& other) = delete; // disable move assignment

        std::shared_ptr<PlayFabApiSettings> GetSettings() const;
        void SetSettings(std::shared_ptr<PlayFabApiSettings> apiSettings);
        std::shared_ptr<PlayFabAuthenticationContext> GetAuthenticationContext() const;
        void SetAuthenticationContext(std::shared_ptr<PlayFabAuthenticationContext> authenticationContext);
        size_t Update();
        void ForgetAllCredentials();

        // ------------ Generated API calls
        void AcceptGroupApplication(GroupsModels::AcceptGroupApplicationRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void AcceptGroupInvitation(GroupsModels::AcceptGroupInvitationRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void AddMembers(GroupsModels::AddMembersRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ApplyToGroup(GroupsModels::ApplyToGroupRequest& request, ProcessApiCallback<GroupsModels::ApplyToGroupResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void BlockEntity(GroupsModels::BlockEntityRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ChangeMemberRole(GroupsModels::ChangeMemberRoleRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateGroup(GroupsModels::CreateGroupRequest& request, ProcessApiCallback<GroupsModels::CreateGroupResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateRole(GroupsModels::CreateGroupRoleRequest& request, ProcessApiCallback<GroupsModels::CreateGroupRoleResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteGroup(GroupsModels::DeleteGroupRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteRole(GroupsModels::DeleteRoleRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetGroup(GroupsModels::GetGroupRequest& request, ProcessApiCallback<GroupsModels::GetGroupResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void InviteToGroup(GroupsModels::InviteToGroupRequest& request, ProcessApiCallback<GroupsModels::InviteToGroupResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void IsMember(GroupsModels::IsMemberRequest& request, ProcessApiCallback<GroupsModels::IsMemberResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ListGroupApplications(GroupsModels::ListGroupApplicationsRequest& request, ProcessApiCallback<GroupsModels::ListGroupApplicationsResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ListGroupBlocks(GroupsModels::ListGroupBlocksRequest& request, ProcessApiCallback<GroupsModels::ListGroupBlocksResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ListGroupInvitations(GroupsModels::ListGroupInvitationsRequest& request, ProcessApiCallback<GroupsModels::ListGroupInvitationsResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ListGroupMembers(GroupsModels::ListGroupMembersRequest& request, ProcessApiCallback<GroupsModels::ListGroupMembersResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ListMembership(GroupsModels::ListMembershipRequest& request, ProcessApiCallback<GroupsModels::ListMembershipResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ListMembershipOpportunities(GroupsModels::ListMembershipOpportunitiesRequest& request, ProcessApiCallback<GroupsModels::ListMembershipOpportunitiesResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void RemoveGroupApplication(GroupsModels::RemoveGroupApplicationRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void RemoveGroupInvitation(GroupsModels::RemoveGroupInvitationRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void RemoveMembers(GroupsModels::RemoveMembersRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UnblockEntity(GroupsModels::UnblockEntityRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateGroup(GroupsModels::UpdateGroupRequest& request, ProcessApiCallback<GroupsModels::UpdateGroupResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateRole(GroupsModels::UpdateGroupRoleRequest& request, ProcessApiCallback<GroupsModels::UpdateGroupRoleResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

        // ------------ Generated result handlers
        void OnAcceptGroupApplicationResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnAcceptGroupInvitationResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnAddMembersResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnApplyToGroupResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnBlockEntityResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnChangeMemberRoleResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnCreateGroupResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnCreateRoleResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnDeleteGroupResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnDeleteRoleResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnGetGroupResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnInviteToGroupResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnIsMemberResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnListGroupApplicationsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnListGroupBlocksResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnListGroupInvitationsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnListGroupMembersResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnListMembershipResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnListMembershipOpportunitiesResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnRemoveGroupApplicationResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnRemoveGroupInvitationResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnRemoveMembersResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUnblockEntityResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUpdateGroupResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        void OnUpdateRoleResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer);
        bool ValidateResult(PlayFabResultCommon& resultCommon, CallRequestContainer& container);
    private:
        std::shared_ptr<PlayFabAuthenticationContext> GetOrCreateAuthenticationContext();
    };
}

#endif
#endif
