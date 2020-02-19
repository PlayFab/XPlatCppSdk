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
        static void ExecuteFunction(CloudScriptModels::ExecuteFunctionRequest& request, const ProcessApiCallback<CloudScriptModels::ExecuteFunctionResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListFunctions(CloudScriptModels::ListFunctionsRequest& request, const ProcessApiCallback<CloudScriptModels::ListFunctionsResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListHttpFunctions(CloudScriptModels::ListFunctionsRequest& request, const ProcessApiCallback<CloudScriptModels::ListHttpFunctionsResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListQueuedFunctions(CloudScriptModels::ListFunctionsRequest& request, const ProcessApiCallback<CloudScriptModels::ListQueuedFunctionsResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void PostFunctionResultForEntityTriggeredAction(CloudScriptModels::PostFunctionResultForEntityTriggeredActionRequest& request, const ProcessApiCallback<CloudScriptModels::EmptyResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void PostFunctionResultForFunctionExecution(CloudScriptModels::PostFunctionResultForFunctionExecutionRequest& request, const ProcessApiCallback<CloudScriptModels::EmptyResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void PostFunctionResultForPlayerTriggeredAction(CloudScriptModels::PostFunctionResultForPlayerTriggeredActionRequest& request, const ProcessApiCallback<CloudScriptModels::EmptyResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void PostFunctionResultForScheduledTask(CloudScriptModels::PostFunctionResultForScheduledTaskRequest& request, const ProcessApiCallback<CloudScriptModels::EmptyResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RegisterHttpFunction(CloudScriptModels::RegisterHttpFunctionRequest& request, const ProcessApiCallback<CloudScriptModels::EmptyResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RegisterQueuedFunction(CloudScriptModels::RegisterQueuedFunctionRequest& request, const ProcessApiCallback<CloudScriptModels::EmptyResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnregisterFunction(CloudScriptModels::UnregisterFunctionRequest& request, const ProcessApiCallback<CloudScriptModels::EmptyResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        PlayFabCloudScriptAPI(); // Private constructor, static class should never have an instance
        PlayFabCloudScriptAPI(const PlayFabCloudScriptAPI& other); // Private copy-constructor, static class should never have an instance

        // ------------ Generated result handlers
        static void OnExecuteEntityCloudScriptResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnExecuteFunctionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnListFunctionsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnListHttpFunctionsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnListQueuedFunctionsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnPostFunctionResultForEntityTriggeredActionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnPostFunctionResultForFunctionExecutionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnPostFunctionResultForPlayerTriggeredActionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnPostFunctionResultForScheduledTaskResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnRegisterHttpFunctionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnRegisterQueuedFunctionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnUnregisterFunctionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);

        static bool ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container);
    };
}

#endif // #if !defined(DISABLE_PLAYFABENTITY_API)
