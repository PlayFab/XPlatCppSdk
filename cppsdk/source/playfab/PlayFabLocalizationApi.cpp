#include <stdafx.h>

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabLocalizationApi.h>
#include <playfab/PlayFabHttp.h>
#include <playfab/PlayFabSettings.h>

namespace PlayFab
{
    using namespace LocalizationModels;

    size_t PlayFabLocalizationAPI::Update()
    {
        return PlayFabHttp::Get().Update();
    }

    void PlayFabLocalizationAPI::ForgetAllCredentials()
    {
        return PlayFabSettings::ForgetAllCredentials();
    }

    // PlayFabLocalization APIs

    void PlayFabLocalizationAPI::GetLanguageList(
        GetLanguageListRequest& request,
        ProcessApiCallback<GetLanguageListResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Locale/GetLanguageList", "X-EntityToken", PlayFabSettings::entityToken, requestJson, OnGetLanguageListResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetLanguageListResponse>(callback)), errorCallback, customData);
    }

    void PlayFabLocalizationAPI::OnGetLanguageListResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetLanguageListResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetLanguageListResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }
}

#endif
