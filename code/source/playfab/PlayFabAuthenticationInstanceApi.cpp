#include <stdafx.h>

#if !defined(DISABLE_PLAYFABENTITY_API)

#include <playfab/PlayFabAuthenticationInstanceApi.h>
#include <playfab/PlayFabPluginManager.h>
#include <playfab/PlayFabSettings.h>

#if defined(PLAYFAB_PLATFORM_WINDOWS)
#pragma warning (disable: 4100) // formal parameters are part of a public interface
#endif // defined(PLAYFAB_PLATFORM_WINDOWS)

namespace PlayFab
{
    using namespace AuthenticationModels;

    PlayFabAuthenticationInstanceAPI::PlayFabAuthenticationInstanceAPI()
    {
        this->m_context = std::make_shared<PlayFabAuthenticationContext>();
    }

    PlayFabAuthenticationInstanceAPI::PlayFabAuthenticationInstanceAPI(const std::shared_ptr<PlayFabApiSettings>& apiSettings)
    {
        this->m_settings = apiSettings;
        this->m_context = std::make_shared<PlayFabAuthenticationContext>();
    }

    PlayFabAuthenticationInstanceAPI::PlayFabAuthenticationInstanceAPI(const std::shared_ptr<PlayFabAuthenticationContext>& authenticationContext)
    {
        this->m_context = authenticationContext;
    }

    PlayFabAuthenticationInstanceAPI::PlayFabAuthenticationInstanceAPI(const std::shared_ptr<PlayFabApiSettings>& apiSettings, const std::shared_ptr<PlayFabAuthenticationContext>& authenticationContext)
    {
        this->m_settings = apiSettings;
        this->m_context = authenticationContext;
    }

    std::shared_ptr<PlayFabApiSettings> PlayFabAuthenticationInstanceAPI::GetSettings() const
    {
        return this->m_settings;
    }

    std::shared_ptr<PlayFabAuthenticationContext> PlayFabAuthenticationInstanceAPI::GetAuthenticationContext() const
    {
        return this->m_context;
    }

    size_t PlayFabAuthenticationInstanceAPI::Update()
    {
        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        return http.Update();
    }

    void PlayFabAuthenticationInstanceAPI::ForgetAllCredentials()
    {
        if (this->m_context != nullptr)
        {
            this->m_context->ForgetAllCredentials();
        }
    }

    // PlayFabAuthentication instance APIs

    void PlayFabAuthenticationInstanceAPI::Delete(
        DeleteRequest& request,
        const ProcessApiCallback<EmptyResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : this->m_context;
        std::shared_ptr<PlayFabApiSettings> settings = this->m_settings != nullptr ? this->m_settings : PlayFabSettings::staticSettings;

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::shared_ptr<PlayFabAuthenticationContext> authenticationContext = request.authenticationContext == nullptr ? this->m_context : request.authenticationContext;
        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", context->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/GameServerIdentity/Delete",
            headers,
            jsonAsString,
            std::bind(&PlayFabAuthenticationInstanceAPI::OnDeleteResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabAuthenticationInstanceAPI::OnDeleteResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        EmptyResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<EmptyResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabAuthenticationInstanceAPI::GetEntityToken(
        GetEntityTokenRequest& request,
        const ProcessApiCallback<GetEntityTokenResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : this->m_context;
        std::shared_ptr<PlayFabApiSettings> settings = this->m_settings != nullptr ? this->m_settings : PlayFabSettings::staticSettings;
        std::string authKey, authValue;
        if (context->entityToken.length() > 0)
        {
            authKey = "X-EntityToken"; authValue = context->entityToken;
        }
        else if (context->clientSessionTicket.length() > 0)
        {
            authKey = "X-Authorization"; authValue = context->clientSessionTicket;
        }
#if defined(ENABLE_PLAYFABSERVER_API) || defined(ENABLE_PLAYFABADMIN_API) || defined(ENABLE_PLAYFAB_SECRETKEY)
        else if (settings->developerSecretKey.length() > 0)
        {
            authKey = "X-SecretKey"; authValue = settings->developerSecretKey;
        }
#endif

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::shared_ptr<PlayFabAuthenticationContext> authenticationContext = request.authenticationContext == nullptr ? this->m_context : request.authenticationContext;
        std::unordered_map<std::string, std::string> headers;
        headers.emplace(authKey, authValue);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Authentication/GetEntityToken",
            headers,
            jsonAsString,
            std::bind(&PlayFabAuthenticationInstanceAPI::OnGetEntityTokenResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetEntityTokenResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabAuthenticationInstanceAPI::OnGetEntityTokenResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetEntityTokenResponse outResult;
        if (ValidateResult(outResult, container))
        {            context->HandlePlayFabLogin("", "", outResult.Entity->Id, outResult.Entity->Type, outResult.EntityToken);

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
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : this->m_context;
        std::shared_ptr<PlayFabApiSettings> settings = this->m_settings != nullptr ? this->m_settings : PlayFabSettings::staticSettings;

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::shared_ptr<PlayFabAuthenticationContext> authenticationContext = request.authenticationContext == nullptr ? this->m_context : request.authenticationContext;
        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", context->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Authentication/ValidateEntityToken",
            headers,
            jsonAsString,
            std::bind(&PlayFabAuthenticationInstanceAPI::OnValidateEntityTokenResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ValidateEntityTokenResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabAuthenticationInstanceAPI::OnValidateEntityTokenResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

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
            {
                PlayFabSettings::globalErrorHandler(container.errorWrapper, container.GetCustomData());
            }

            if (container.errorCallback != nullptr)
            {
                container.errorCallback(container.errorWrapper, container.GetCustomData());
            }
            return false;
        }
    }
}

#endif

#if defined(PLAYFAB_PLATFORM_WINDOWS)
#pragma warning (default: 4100) // formal parameters are part of a public interface
#endif // defined(PLAYFAB_PLATFORM_WINDOWS)
