#include <stdafx.h>

#ifdef ENABLE_PLAYFABENTITY_API

#include <playfab/PlayFabCloudScriptApi.h>
#include <playfab/PlayFabHttp.h>
#include <playfab/PlayFabSettings.h>

namespace PlayFab
{
    using namespace CloudScriptModels;

    size_t PlayFabCloudScriptAPI::Update()
    {
        return PlayFabHttp::Get().Update();
    }

    void PlayFabCloudScriptAPI::ForgetAllCredentials()
    {
        return PlayFabSettings::ForgetAllCredentials();
    }

    // PlayFabCloudScript APIs

    void PlayFabCloudScriptAPI::ExecuteEntityCloudScript(
        ExecuteEntityCloudScriptRequest& request,
        ProcessApiCallback<ExecuteCloudScriptResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/CloudScript/ExecuteEntityCloudScript", "X-EntityToken", PlayFabSettings::entityToken, requestJson, OnExecuteEntityCloudScriptResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ExecuteCloudScriptResult>(callback)), errorCallback, customData);
    }

    void PlayFabCloudScriptAPI::OnExecuteEntityCloudScriptResult(CallRequestContainer& request)
    {
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
}

#endif
