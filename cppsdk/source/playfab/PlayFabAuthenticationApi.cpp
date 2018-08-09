#include <stdafx.h>

#ifdef ENABLE_PLAYFABENTITY_API

#include <playfab/PlayFabAuthenticationApi.h>
#include <playfab/PlayFabHttp.h>
#include <playfab/PlayFabSettings.h>

namespace PlayFab
{
    using namespace AuthenticationModels;

    size_t PlayFabAuthenticationAPI::Update()
    {
        return PlayFabHttp::Get().Update();
    }

    void PlayFabAuthenticationAPI::ForgetAllCredentials()
    {
        return PlayFabSettings::ForgetAllCredentials();
    }

    // PlayFabAuthentication APIs

    void PlayFabAuthenticationAPI::GetEntityToken(
        GetEntityTokenRequest& request,
        ProcessApiCallback<GetEntityTokenResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {
        std::string authKey, authValue;
        if (PlayFabSettings::entityToken.length() > 0) {
            authKey = "X-EntityToken"; authValue = PlayFabSettings::entityToken;
        } else if (PlayFabSettings::clientSessionTicket.length() > 0) {
            authKey = "X-Authorization"; authValue = PlayFabSettings::clientSessionTicket;
        } else if (PlayFabSettings::developerSecretKey.length() > 0) {
            authKey = "X-SecretKey"; authValue = PlayFabSettings::developerSecretKey;
        }

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Authentication/GetEntityToken", authKey, authValue, requestJson, OnGetEntityTokenResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetEntityTokenResponse>(callback)), errorCallback, customData);
    }

    void PlayFabAuthenticationAPI::OnGetEntityTokenResult(CallRequestContainer& request)
    {
        GetEntityTokenResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;
        if (outResult.EntityToken.length() > 0) PlayFabSettings::entityToken = outResult.EntityToken;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetEntityTokenResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }
}

#endif
