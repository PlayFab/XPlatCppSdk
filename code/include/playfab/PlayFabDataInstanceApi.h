#pragma once

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabApiSettings.h>
#include <playfab/PlayFabDataDataModels.h>
#include <memory>

namespace PlayFab
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Data APIs
    /// </summary>
    class PlayFabDataInstanceAPI
    {
    private:
        std::shared_ptr<PlayFabApiSettings> m_settings{ nullptr };
        std::shared_ptr<PlayFabAuthenticationContext> m_context{ nullptr };

    public:
        explicit PlayFabDataInstanceAPI(std::shared_ptr<PlayFabAuthenticationContext> authenticationContext);
        PlayFabDataInstanceAPI(std::shared_ptr<PlayFabApiSettings> apiSettings, std::shared_ptr<PlayFabAuthenticationContext> authenticationContext);

        ~PlayFabDataInstanceAPI();
        PlayFabDataInstanceAPI(const PlayFabDataInstanceAPI& source) = delete; // disable copy
        PlayFabDataInstanceAPI(PlayFabDataInstanceAPI&&) = delete; // disable move
        PlayFabDataInstanceAPI& operator=(const PlayFabDataInstanceAPI& source) = delete; // disable assignment
        PlayFabDataInstanceAPI& operator=(PlayFabDataInstanceAPI&& other) = delete; // disable move assignment

        std::shared_ptr<PlayFabApiSettings> GetSettings() const;
        std::shared_ptr<PlayFabAuthenticationContext> GetAuthenticationContext() const;
        size_t Update();
        void ForgetAllCredentials();

        // ------------ Generated API calls
        void AbortFileUploads(DataModels::AbortFileUploadsRequest& request, const ProcessApiCallback<DataModels::AbortFileUploadsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteFiles(DataModels::DeleteFilesRequest& request, const ProcessApiCallback<DataModels::DeleteFilesResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void FinalizeFileUploads(DataModels::FinalizeFileUploadsRequest& request, const ProcessApiCallback<DataModels::FinalizeFileUploadsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetFiles(DataModels::GetFilesRequest& request, const ProcessApiCallback<DataModels::GetFilesResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetObjects(DataModels::GetObjectsRequest& request, const ProcessApiCallback<DataModels::GetObjectsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void InitiateFileUploads(DataModels::InitiateFileUploadsRequest& request, const ProcessApiCallback<DataModels::InitiateFileUploadsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SetObjects(DataModels::SetObjectsRequest& request, const ProcessApiCallback<DataModels::SetObjectsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);

        // ------------ Generated result handlers
        void OnAbortFileUploadsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnDeleteFilesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnFinalizeFileUploadsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetFilesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetObjectsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnInitiateFileUploadsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnSetObjectsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        bool ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container);
    };
}

#endif
