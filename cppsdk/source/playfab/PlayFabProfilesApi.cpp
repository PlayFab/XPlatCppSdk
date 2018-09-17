#include <stdafx.h>

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabProfilesApi.h>
#include <playfab/PlayFabHttp.h>
#include <playfab/PlayFabSettings.h>

namespace PlayFab
{
    using namespace ProfilesModels;

    size_t PlayFabProfilesAPI::Update()
    {
        return PlayFabHttp::Get().Update();
    }

    void PlayFabProfilesAPI::ForgetAllCredentials()
    {
        return PlayFabSettings::ForgetAllCredentials();
    }

    // PlayFabProfiles APIs

    void PlayFabProfilesAPI::GetGlobalPolicy(
        GetGlobalPolicyRequest& request,
        ProcessApiCallback<GetGlobalPolicyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Profile/GetGlobalPolicy", "X-EntityToken", PlayFabSettings::entityToken, requestJson, OnGetGlobalPolicyResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetGlobalPolicyResponse>(callback)), errorCallback, customData);
    }

    void PlayFabProfilesAPI::OnGetGlobalPolicyResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetGlobalPolicyResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetGlobalPolicyResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabProfilesAPI::GetProfile(
        GetEntityProfileRequest& request,
        ProcessApiCallback<GetEntityProfileResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Profile/GetProfile", "X-EntityToken", PlayFabSettings::entityToken, requestJson, OnGetProfileResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetEntityProfileResponse>(callback)), errorCallback, customData);
    }

    void PlayFabProfilesAPI::OnGetProfileResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetEntityProfileResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetEntityProfileResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabProfilesAPI::GetProfiles(
        GetEntityProfilesRequest& request,
        ProcessApiCallback<GetEntityProfilesResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Profile/GetProfiles", "X-EntityToken", PlayFabSettings::entityToken, requestJson, OnGetProfilesResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetEntityProfilesResponse>(callback)), errorCallback, customData);
    }

    void PlayFabProfilesAPI::OnGetProfilesResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        GetEntityProfilesResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<GetEntityProfilesResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabProfilesAPI::SetGlobalPolicy(
        SetGlobalPolicyRequest& request,
        ProcessApiCallback<SetGlobalPolicyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Profile/SetGlobalPolicy", "X-EntityToken", PlayFabSettings::entityToken, requestJson, OnSetGlobalPolicyResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<SetGlobalPolicyResponse>(callback)), errorCallback, customData);
    }

    void PlayFabProfilesAPI::OnSetGlobalPolicyResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        SetGlobalPolicyResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<SetGlobalPolicyResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabProfilesAPI::SetProfileLanguage(
        SetProfileLanguageRequest& request,
        ProcessApiCallback<SetProfileLanguageResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Profile/SetProfileLanguage", "X-EntityToken", PlayFabSettings::entityToken, requestJson, OnSetProfileLanguageResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<SetProfileLanguageResponse>(callback)), errorCallback, customData);
    }

    void PlayFabProfilesAPI::OnSetProfileLanguageResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        SetProfileLanguageResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<SetProfileLanguageResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabProfilesAPI::SetProfilePolicy(
        SetEntityProfilePolicyRequest& request,
        ProcessApiCallback<SetEntityProfilePolicyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        const auto requestJson = request.ToJson();
        http.AddRequest("/Profile/SetProfilePolicy", "X-EntityToken", PlayFabSettings::entityToken, requestJson, OnSetProfilePolicyResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<SetEntityProfilePolicyResponse>(callback)), errorCallback, customData);
    }

    void PlayFabProfilesAPI::OnSetProfilePolicyResult(CallRequestContainerBase& pRequest)
    {
        CallRequestContainer request = static_cast<CallRequestContainer&>(pRequest);
        SetEntityProfilePolicyResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.errorWrapper.Request;

        const auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            const auto callback = (*static_cast<ProcessApiCallback<SetEntityProfilePolicyResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }
}

#endif
