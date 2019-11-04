#include <stdafx.h>

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabAuthenticationInstanceApi.h>
#include <playfab/PlayFabPluginManager.h>
#include <playfab/PlayFabSettings.h>
#include <playfab/PlayFabError.h>
#include <memory>

#if defined(PLAYFAB_PLATFORM_WINDOWS)
#pragma warning (disable: 4100) // formal parameters are part of a public interface
#endif // defined(PLAYFAB_PLATFORM_WINDOWS)

namespace PlayFab
{
    using namespace AuthenticationModels;

    PlayFabAuthenticationInstanceAPI::PlayFabAuthenticationInstanceAPI()
    {
    }

    PlayFabAuthenticationInstanceAPI::PlayFabAuthenticationInstanceAPI(std::shared_ptr<PlayFabApiSettings> apiSettings)
    {
        this->settings = std::move(apiSettings);
    }

    PlayFabAuthenticationInstanceAPI::PlayFabAuthenticationInstanceAPI(std::shared_ptr<PlayFabAuthenticationContext> authenticationContext)
    {
        this->authContext = std::move(authenticationContext);
    }

    PlayFabAuthenticationInstanceAPI::PlayFabAuthenticationInstanceAPI(std::shared_ptr<PlayFabApiSettings> apiSettings, std::shared_ptr<PlayFabAuthenticationContext> authenticationContext)
    {
        this->settings = std::move(apiSettings);
        this->authContext = std::move(authenticationContext);
    }

    PlayFabAuthenticationInstanceAPI::~PlayFabAuthenticationInstanceAPI()
    {
    }

    std::shared_ptr<PlayFabApiSettings> PlayFabAuthenticationInstanceAPI::GetSettings() const
    {
        return this->settings;
    }

    void PlayFabAuthenticationInstanceAPI::SetSettings(std::shared_ptr<PlayFabApiSettings> apiSettings)
    {
        this->settings = std::move(apiSettings);
    }

    std::shared_ptr<PlayFabAuthenticationContext> PlayFabAuthenticationInstanceAPI::GetAuthenticationContext() const
    {
        return this->authContext;
    }

    void PlayFabAuthenticationInstanceAPI::SetAuthenticationContext(std::shared_ptr<PlayFabAuthenticationContext> authenticationContext)
    {
        this->authContext = std::move(authenticationContext);
    }

    std::shared_ptr<PlayFabAuthenticationContext> PlayFabAuthenticationInstanceAPI::GetOrCreateAuthenticationContext()
    {
        if (this->authContext == nullptr)
        {
            this->authContext = std::make_shared<PlayFabAuthenticationContext>();
        }
        
        return this->authContext;
    }

    size_t PlayFabAuthenticationInstanceAPI::Update()
    {
        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        return http.Update();
    }

    void PlayFabAuthenticationInstanceAPI::ForgetAllCredentials()
    {
        if (this->authContext == nullptr)
            return;

        this->authContext->ForgetAllCredentials();
    }

    // PlayFabAuthentication instance APIs

    void PlayFabAuthenticationInstanceAPI::GetEntityToken(
        GetEntityTokenRequest& request,
        const ProcessApiCallback<GetEntityTokenResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::string authKey, authValue;
        if (request.authenticationContext != nullptr) {
            if (request.authenticationContext->entityToken.length() > 0) {
                authKey = "X-EntityToken"; authValue = request.authenticationContext->entityToken;
            }
            else if (request.authenticationContext->clientSessionTicket.length() > 0) {
                authKey = "X-Authorization"; authValue = request.authenticationContext->clientSessionTicket;
            }
    #if defined(ENABLE_PLAYFABSERVER_API) || defined(ENABLE_PLAYFABADMIN_API)
            else if (request.authenticationContext->developerSecretKey.length() > 0) {
                authKey = "X-SecretKey"; authValue = request.authenticationContext->developerSecretKey;
            }
    #endif
        }
        else {
            std::shared_ptr<PlayFabAuthenticationContext> authenticationContext = this->GetOrCreateAuthenticationContext();
            if (authenticationContext->entityToken.length() > 0) {
                authKey = "X-EntityToken"; authValue = authenticationContext->entityToken;
            }
            else if (authenticationContext->clientSessionTicket.length() > 0) {
                authKey = "X-Authorization"; authValue = authenticationContext->clientSessionTicket;
            }
    #if defined(ENABLE_PLAYFABSERVER_API) || defined(ENABLE_PLAYFABADMIN_API)
            else if (authenticationContext->developerSecretKey.length() > 0) {
                authKey = "X-SecretKey"; authValue = authenticationContext->developerSecretKey;
            }
    #endif
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::shared_ptr<PlayFabAuthenticationContext> authenticationContext = request.authenticationContext == nullptr ? this->GetOrCreateAuthenticationContext() : request.authenticationContext;
        std::unordered_map<std::string, std::string> headers;
        headers.emplace(authKey, authValue);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Authentication/GetEntityToken",
            headers,
            jsonAsString,
            std::bind(&PlayFabAuthenticationInstanceAPI::OnGetEntityTokenResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            customData,
            this->settings));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetEntityTokenResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(authenticationContext, this->settings, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabAuthenticationInstanceAPI::OnGetEntityTokenResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        GetEntityTokenResponse outResult;
        if (ValidateResult(outResult, container))
        {
            if (outResult.EntityToken.length() > 0)            {
                this->GetOrCreateAuthenticationContext()->entityToken = outResult.EntityToken;
            }

            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<GetEntityTokenResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabAuthenticationInstanceAPI::ValidateEntityToken(
        ValidateEntityTokenRequest& request,
        const ProcessApiCallback<ValidateEntityTokenResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::shared_ptr<PlayFabAuthenticationContext> authenticationContext = request.authenticationContext == nullptr ? this->GetOrCreateAuthenticationContext() : request.authenticationContext;
        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? this->GetOrCreateAuthenticationContext()->entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Authentication/ValidateEntityToken",
            headers,
            jsonAsString,
            std::bind(&PlayFabAuthenticationInstanceAPI::OnValidateEntityTokenResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            customData,
            this->settings));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ValidateEntityTokenResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(authenticationContext, this->settings, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabAuthenticationInstanceAPI::OnValidateEntityTokenResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        ValidateEntityTokenResponse outResult;
        if (ValidateResult(outResult, container))
        {

            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<ValidateEntityTokenResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    bool PlayFabAuthenticationInstanceAPI::ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container)
    {
        if (container.errorWrapper.HttpCode == 200)
        {
            resultCommon.FromJson(container.errorWrapper.Data);
            resultCommon.Request = container.errorWrapper.Request;
            return true;
        }
        else // Process the error case
        {
            if (PlayFabSettings::globalErrorHandler != nullptr)
                PlayFabSettings::globalErrorHandler(container.errorWrapper, container.GetCustomData());
            if (container.errorCallback != nullptr)
                container.errorCallback(container.errorWrapper, container.GetCustomData());
            return false;
        }
    }
}

#endif

#if defined(PLAYFAB_PLATFORM_WINDOWS)
#pragma warning (default: 4100) // formal parameters are part of a public interface
#endif // defined(PLAYFAB_PLATFORM_WINDOWS)
