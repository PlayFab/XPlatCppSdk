#pragma once

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabApiSettings.h>
#include <playfab/PlayFabCloudScriptDataModels.h>
#include <memory>

namespace PlayFab
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all CloudScript APIs
    /// </summary>
    class PlayFabCloudScriptInstanceAPI
    {
    private:
        std::shared_ptr<PlayFabApiSettings> m_settings;
        std::shared_ptr<PlayFabAuthenticationContext> m_context;

    public:
        PlayFabCloudScriptInstanceAPI(const std::shared_ptr<PlayFabAuthenticationContext>& authenticationContext);
        PlayFabCloudScriptInstanceAPI(const std::shared_ptr<PlayFabApiSettings>& apiSettings, const std::shared_ptr<PlayFabAuthenticationContext>& authenticationContext);

        ~PlayFabCloudScriptInstanceAPI() = default;
        PlayFabCloudScriptInstanceAPI(const PlayFabCloudScriptInstanceAPI& source) = delete; // disable copy
        PlayFabCloudScriptInstanceAPI(PlayFabCloudScriptInstanceAPI&&) = delete; // disable move
        PlayFabCloudScriptInstanceAPI& operator=(const PlayFabCloudScriptInstanceAPI& source) = delete; // disable assignment
        PlayFabCloudScriptInstanceAPI& operator=(PlayFabCloudScriptInstanceAPI&& other) = delete; // disable move assignment

        std::shared_ptr<PlayFabApiSettings> GetSettings() const;
        std::shared_ptr<PlayFabAuthenticationContext> GetAuthenticationContext() const;
        size_t Update();
        void ForgetAllCredentials();

        // ------------ Generated API calls
        void ExecuteEntityCloudScript(CloudScriptModels::ExecuteEntityCloudScriptRequest& request, const ProcessApiCallback<CloudScriptModels::ExecuteCloudScriptResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);

        // ------------ Generated result handlers
        void OnExecuteEntityCloudScriptResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        bool ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container);
    };
}

#endif
