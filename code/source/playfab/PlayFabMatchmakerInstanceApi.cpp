#include <stdafx.h>

#ifdef ENABLE_PLAYFABSERVER_API

#include <playfab/PlayFabMatchmakerInstanceApi.h>
#include <playfab/PlayFabPluginManager.h>
#include <playfab/PlayFabSettings.h>
#include <playfab/PlayFabError.h>
#include <memory>

#if defined(PLAYFAB_PLATFORM_WINDOWS)
#pragma warning (disable: 4100) // formal parameters are part of a public interface
#endif // defined(PLAYFAB_PLATFORM_WINDOWS)

namespace PlayFab
{
    using namespace MatchmakerModels;

    PlayFabMatchmakerInstanceAPI::PlayFabMatchmakerInstanceAPI(std::shared_ptr<PlayFabAuthenticationContext> authenticationContext)
    {
        if (authenticationContext == nullptr)
            throw PlayFabException(PlayFabExceptionCode::AuthContextRequired, "Context cannot be null, create a PlayFabAuthenticationContext for each player in advance, or get <PlayFabClientInstanceAPI>.authenticationContext");
        this->authContext = std::move(authenticationContext);
    }

    PlayFabMatchmakerInstanceAPI::PlayFabMatchmakerInstanceAPI(std::shared_ptr<PlayFabApiSettings> apiSettings, std::shared_ptr<PlayFabAuthenticationContext> authenticationContext)
    {
        if (authenticationContext == nullptr)
            throw PlayFabException(PlayFabExceptionCode::AuthContextRequired, "Context cannot be null, create a PlayFabAuthenticationContext for each player in advance, or get <PlayFabClientInstanceAPI>.authenticationContext");
        this->settings = std::move(apiSettings);
        this->authContext = std::move(authenticationContext);
    }

    PlayFabMatchmakerInstanceAPI::~PlayFabMatchmakerInstanceAPI()
    {
    }

    std::shared_ptr<PlayFabApiSettings> PlayFabMatchmakerInstanceAPI::GetSettings() const
    {
        return this->settings;
    }

    void PlayFabMatchmakerInstanceAPI::SetSettings(std::shared_ptr<PlayFabApiSettings> apiSettings)
    {
        this->settings = std::move(apiSettings);
    }

    std::shared_ptr<PlayFabAuthenticationContext> PlayFabMatchmakerInstanceAPI::GetAuthenticationContext() const
    {
        return this->authContext;
    }

    void PlayFabMatchmakerInstanceAPI::SetAuthenticationContext(std::shared_ptr<PlayFabAuthenticationContext> authenticationContext)
    {
        this->authContext = std::move(authenticationContext);
    }

    std::shared_ptr<PlayFabAuthenticationContext> PlayFabMatchmakerInstanceAPI::GetOrCreateAuthenticationContext()
    {
        if (this->authContext == nullptr)
        {
            this->authContext = std::make_shared<PlayFabAuthenticationContext>();
        }
        
        return this->authContext;
    }

    size_t PlayFabMatchmakerInstanceAPI::Update()
    {
        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        return http.Update();
    }

    void PlayFabMatchmakerInstanceAPI::ForgetAllCredentials()
    {
        if (this->authContext == nullptr)
            return;

        this->authContext->ForgetAllCredentials();
    }

    // PlayFabMatchmaker instance APIs

    void PlayFabMatchmakerInstanceAPI::AuthUser(
        AuthUserRequest& request,
        const ProcessApiCallback<AuthUserResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : this.apiContext != nullptr ? this.apiContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = this.settings != nullptr ? this.settings : PlayFabSettings::staticSettings;


        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::shared_ptr<PlayFabAuthenticationContext> authenticationContext = request.authenticationContext == nullptr ? this->GetOrCreateAuthenticationContext() : request.authenticationContext;
        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-SecretKey", settings->developerSecretKey);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Matchmaker/AuthUser",
            headers,
            jsonAsString,
            std::bind(&PlayFabMatchmakerInstanceAPI::OnAuthUserResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            customData,
            this->settings));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<AuthUserResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(authenticationContext, this->settings, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabMatchmakerInstanceAPI::OnAuthUserResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        AuthUserResponse outResult;
        if (ValidateResult(outResult, container))
        {

            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<AuthUserResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabMatchmakerInstanceAPI::PlayerJoined(
        PlayerJoinedRequest& request,
        const ProcessApiCallback<PlayerJoinedResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : this.apiContext != nullptr ? this.apiContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = this.settings != nullptr ? this.settings : PlayFabSettings::staticSettings;


        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::shared_ptr<PlayFabAuthenticationContext> authenticationContext = request.authenticationContext == nullptr ? this->GetOrCreateAuthenticationContext() : request.authenticationContext;
        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-SecretKey", settings->developerSecretKey);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Matchmaker/PlayerJoined",
            headers,
            jsonAsString,
            std::bind(&PlayFabMatchmakerInstanceAPI::OnPlayerJoinedResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            customData,
            this->settings));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<PlayerJoinedResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(authenticationContext, this->settings, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabMatchmakerInstanceAPI::OnPlayerJoinedResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        PlayerJoinedResponse outResult;
        if (ValidateResult(outResult, container))
        {

            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<PlayerJoinedResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabMatchmakerInstanceAPI::PlayerLeft(
        PlayerLeftRequest& request,
        const ProcessApiCallback<PlayerLeftResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : this.apiContext != nullptr ? this.apiContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = this.settings != nullptr ? this.settings : PlayFabSettings::staticSettings;


        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::shared_ptr<PlayFabAuthenticationContext> authenticationContext = request.authenticationContext == nullptr ? this->GetOrCreateAuthenticationContext() : request.authenticationContext;
        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-SecretKey", settings->developerSecretKey);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Matchmaker/PlayerLeft",
            headers,
            jsonAsString,
            std::bind(&PlayFabMatchmakerInstanceAPI::OnPlayerLeftResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            customData,
            this->settings));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<PlayerLeftResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(authenticationContext, this->settings, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabMatchmakerInstanceAPI::OnPlayerLeftResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        PlayerLeftResponse outResult;
        if (ValidateResult(outResult, container))
        {

            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<PlayerLeftResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabMatchmakerInstanceAPI::StartGame(
        StartGameRequest& request,
        const ProcessApiCallback<StartGameResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : this.apiContext != nullptr ? this.apiContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = this.settings != nullptr ? this.settings : PlayFabSettings::staticSettings;


        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::shared_ptr<PlayFabAuthenticationContext> authenticationContext = request.authenticationContext == nullptr ? this->GetOrCreateAuthenticationContext() : request.authenticationContext;
        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-SecretKey", settings->developerSecretKey);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Matchmaker/StartGame",
            headers,
            jsonAsString,
            std::bind(&PlayFabMatchmakerInstanceAPI::OnStartGameResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            customData,
            this->settings));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<StartGameResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(authenticationContext, this->settings, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabMatchmakerInstanceAPI::OnStartGameResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        StartGameResponse outResult;
        if (ValidateResult(outResult, container))
        {

            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<StartGameResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabMatchmakerInstanceAPI::UserInfo(
        UserInfoRequest& request,
        const ProcessApiCallback<UserInfoResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : this.apiContext != nullptr ? this.apiContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = this.settings != nullptr ? this.settings : PlayFabSettings::staticSettings;


        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::shared_ptr<PlayFabAuthenticationContext> authenticationContext = request.authenticationContext == nullptr ? this->GetOrCreateAuthenticationContext() : request.authenticationContext;
        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-SecretKey", settings->developerSecretKey);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Matchmaker/UserInfo",
            headers,
            jsonAsString,
            std::bind(&PlayFabMatchmakerInstanceAPI::OnUserInfoResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            customData,
            this->settings));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UserInfoResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(authenticationContext, this->settings, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabMatchmakerInstanceAPI::OnUserInfoResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        UserInfoResponse outResult;
        if (ValidateResult(outResult, container))
        {

            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<UserInfoResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    bool PlayFabMatchmakerInstanceAPI::ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container)
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
