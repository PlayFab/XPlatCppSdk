#pragma once

#if !defined(DISABLE_PLAYFABENTITY_API)

#include <playfab/PlayFabCloudScriptDataModels.h>
#include <playfab/PlayFabError.h>

namespace PlayFab
{
    class CallRequestContainerBase;
    class CallRequestContainer;

    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all CloudScript APIs
    /// </summary>
    class PlayFabCloudScriptAPI
    {
    public:
        static size_t Update();
        static void ForgetAllCredentials();


        // ------------ Generated API calls
        static void ExecuteEntityCloudScript(CloudScriptModels::ExecuteEntityCloudScriptRequest& request, const ProcessApiCallback<CloudScriptModels::ExecuteCloudScriptResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        PlayFabCloudScriptAPI(); // Private constructor, static class should never have an instance
        PlayFabCloudScriptAPI(const PlayFabCloudScriptAPI& other); // Private copy-constructor, static class should never have an instance

        // ------------ Generated result handlers
        static void OnExecuteEntityCloudScriptResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);

        static bool ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container);
    };
}

#endif // #if !defined(DISABLE_PLAYFABENTITY_API)
