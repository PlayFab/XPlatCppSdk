#include <stdafx.h>

#if !defined(DISABLE_PLAYFABENTITY_API)

#include <playfab/PlayFabAddonApi.h>
#include <playfab/PlayFabPluginManager.h>
#include <playfab/PlayFabSettings.h>
#include <playfab/PlayFabError.h>
#include <memory>

#if defined(PLAYFAB_PLATFORM_WINDOWS)
#pragma warning (disable: 4100) // formal parameters are part of a public interface
#endif // defined(PLAYFAB_PLATFORM_WINDOWS)

namespace PlayFab
{
    using namespace AddonModels;

    size_t PlayFabAddonAPI::Update()
    {
        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        return http.Update();
    }

    void PlayFabAddonAPI::ForgetAllCredentials()
    {
        return PlayFabSettings::ForgetAllCredentials();
    }

    // PlayFabAddon APIs

    void PlayFabAddonAPI::CreateOrUpdateApple(
        CreateOrUpdateAppleRequest& request,
        const ProcessApiCallback<CreateOrUpdateAppleResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", context->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Addon/CreateOrUpdateApple",
            headers,
            jsonAsString,
            OnCreateOrUpdateAppleResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<CreateOrUpdateAppleResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabAddonAPI::OnCreateOrUpdateAppleResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        CreateOrUpdateAppleResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<CreateOrUpdateAppleResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabAddonAPI::CreateOrUpdateFacebook(
        CreateOrUpdateFacebookRequest& request,
        const ProcessApiCallback<CreateOrUpdateFacebookResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", context->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Addon/CreateOrUpdateFacebook",
            headers,
            jsonAsString,
            OnCreateOrUpdateFacebookResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<CreateOrUpdateFacebookResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabAddonAPI::OnCreateOrUpdateFacebookResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        CreateOrUpdateFacebookResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<CreateOrUpdateFacebookResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabAddonAPI::CreateOrUpdateFacebookInstantGames(
        CreateOrUpdateFacebookInstantGamesRequest& request,
        const ProcessApiCallback<CreateOrUpdateFacebookInstantGamesResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", context->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Addon/CreateOrUpdateFacebookInstantGames",
            headers,
            jsonAsString,
            OnCreateOrUpdateFacebookInstantGamesResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<CreateOrUpdateFacebookInstantGamesResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabAddonAPI::OnCreateOrUpdateFacebookInstantGamesResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        CreateOrUpdateFacebookInstantGamesResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<CreateOrUpdateFacebookInstantGamesResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabAddonAPI::CreateOrUpdateGoogle(
        CreateOrUpdateGoogleRequest& request,
        const ProcessApiCallback<CreateOrUpdateGoogleResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", context->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Addon/CreateOrUpdateGoogle",
            headers,
            jsonAsString,
            OnCreateOrUpdateGoogleResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<CreateOrUpdateGoogleResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabAddonAPI::OnCreateOrUpdateGoogleResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        CreateOrUpdateGoogleResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<CreateOrUpdateGoogleResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabAddonAPI::CreateOrUpdateKongregate(
        CreateOrUpdateKongregateRequest& request,
        const ProcessApiCallback<CreateOrUpdateKongregateResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", context->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Addon/CreateOrUpdateKongregate",
            headers,
            jsonAsString,
            OnCreateOrUpdateKongregateResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<CreateOrUpdateKongregateResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabAddonAPI::OnCreateOrUpdateKongregateResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        CreateOrUpdateKongregateResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<CreateOrUpdateKongregateResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabAddonAPI::CreateOrUpdateNintendo(
        CreateOrUpdateNintendoRequest& request,
        const ProcessApiCallback<CreateOrUpdateNintendoResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", context->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Addon/CreateOrUpdateNintendo",
            headers,
            jsonAsString,
            OnCreateOrUpdateNintendoResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<CreateOrUpdateNintendoResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabAddonAPI::OnCreateOrUpdateNintendoResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        CreateOrUpdateNintendoResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<CreateOrUpdateNintendoResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabAddonAPI::CreateOrUpdatePSN(
        CreateOrUpdatePSNRequest& request,
        const ProcessApiCallback<CreateOrUpdatePSNResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", context->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Addon/CreateOrUpdatePSN",
            headers,
            jsonAsString,
            OnCreateOrUpdatePSNResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<CreateOrUpdatePSNResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabAddonAPI::OnCreateOrUpdatePSNResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        CreateOrUpdatePSNResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<CreateOrUpdatePSNResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabAddonAPI::CreateOrUpdateSteam(
        CreateOrUpdateSteamRequest& request,
        const ProcessApiCallback<CreateOrUpdateSteamResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", context->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Addon/CreateOrUpdateSteam",
            headers,
            jsonAsString,
            OnCreateOrUpdateSteamResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<CreateOrUpdateSteamResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabAddonAPI::OnCreateOrUpdateSteamResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        CreateOrUpdateSteamResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<CreateOrUpdateSteamResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabAddonAPI::CreateOrUpdateTwitch(
        CreateOrUpdateTwitchRequest& request,
        const ProcessApiCallback<CreateOrUpdateTwitchResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", context->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Addon/CreateOrUpdateTwitch",
            headers,
            jsonAsString,
            OnCreateOrUpdateTwitchResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<CreateOrUpdateTwitchResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabAddonAPI::OnCreateOrUpdateTwitchResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        CreateOrUpdateTwitchResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<CreateOrUpdateTwitchResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabAddonAPI::DeleteApple(
        DeleteAppleRequest& request,
        const ProcessApiCallback<DeleteAppleResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", context->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Addon/DeleteApple",
            headers,
            jsonAsString,
            OnDeleteAppleResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<DeleteAppleResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabAddonAPI::OnDeleteAppleResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        DeleteAppleResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<DeleteAppleResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabAddonAPI::DeleteFacebook(
        DeleteFacebookRequest& request,
        const ProcessApiCallback<DeleteFacebookResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", context->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Addon/DeleteFacebook",
            headers,
            jsonAsString,
            OnDeleteFacebookResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<DeleteFacebookResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabAddonAPI::OnDeleteFacebookResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        DeleteFacebookResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<DeleteFacebookResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabAddonAPI::DeleteFacebookInstantGames(
        DeleteFacebookInstantGamesRequest& request,
        const ProcessApiCallback<DeleteFacebookInstantGamesResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", context->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Addon/DeleteFacebookInstantGames",
            headers,
            jsonAsString,
            OnDeleteFacebookInstantGamesResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<DeleteFacebookInstantGamesResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabAddonAPI::OnDeleteFacebookInstantGamesResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        DeleteFacebookInstantGamesResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<DeleteFacebookInstantGamesResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabAddonAPI::DeleteGoogle(
        DeleteGoogleRequest& request,
        const ProcessApiCallback<DeleteGoogleResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", context->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Addon/DeleteGoogle",
            headers,
            jsonAsString,
            OnDeleteGoogleResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<DeleteGoogleResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabAddonAPI::OnDeleteGoogleResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        DeleteGoogleResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<DeleteGoogleResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabAddonAPI::DeleteKongregate(
        DeleteKongregateRequest& request,
        const ProcessApiCallback<DeleteKongregateResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", context->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Addon/DeleteKongregate",
            headers,
            jsonAsString,
            OnDeleteKongregateResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<DeleteKongregateResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabAddonAPI::OnDeleteKongregateResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        DeleteKongregateResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<DeleteKongregateResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabAddonAPI::DeleteNintendo(
        DeleteNintendoRequest& request,
        const ProcessApiCallback<DeleteNintendoResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", context->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Addon/DeleteNintendo",
            headers,
            jsonAsString,
            OnDeleteNintendoResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<DeleteNintendoResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabAddonAPI::OnDeleteNintendoResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        DeleteNintendoResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<DeleteNintendoResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabAddonAPI::DeletePSN(
        DeletePSNRequest& request,
        const ProcessApiCallback<DeletePSNResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", context->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Addon/DeletePSN",
            headers,
            jsonAsString,
            OnDeletePSNResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<DeletePSNResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabAddonAPI::OnDeletePSNResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        DeletePSNResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<DeletePSNResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabAddonAPI::DeleteSteam(
        DeleteSteamRequest& request,
        const ProcessApiCallback<DeleteSteamResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", context->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Addon/DeleteSteam",
            headers,
            jsonAsString,
            OnDeleteSteamResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<DeleteSteamResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabAddonAPI::OnDeleteSteamResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        DeleteSteamResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<DeleteSteamResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabAddonAPI::DeleteTwitch(
        DeleteTwitchRequest& request,
        const ProcessApiCallback<DeleteTwitchResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", context->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Addon/DeleteTwitch",
            headers,
            jsonAsString,
            OnDeleteTwitchResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<DeleteTwitchResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabAddonAPI::OnDeleteTwitchResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        DeleteTwitchResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<DeleteTwitchResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabAddonAPI::GetApple(
        GetAppleRequest& request,
        const ProcessApiCallback<GetAppleResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", context->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Addon/GetApple",
            headers,
            jsonAsString,
            OnGetAppleResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetAppleResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabAddonAPI::OnGetAppleResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetAppleResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetAppleResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabAddonAPI::GetFacebook(
        GetFacebookRequest& request,
        const ProcessApiCallback<GetFacebookResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", context->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Addon/GetFacebook",
            headers,
            jsonAsString,
            OnGetFacebookResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetFacebookResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabAddonAPI::OnGetFacebookResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetFacebookResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetFacebookResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabAddonAPI::GetFacebookInstantGames(
        GetFacebookInstantGamesRequest& request,
        const ProcessApiCallback<GetFacebookInstantGamesResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", context->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Addon/GetFacebookInstantGames",
            headers,
            jsonAsString,
            OnGetFacebookInstantGamesResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetFacebookInstantGamesResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabAddonAPI::OnGetFacebookInstantGamesResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetFacebookInstantGamesResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetFacebookInstantGamesResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabAddonAPI::GetGoogle(
        GetGoogleRequest& request,
        const ProcessApiCallback<GetGoogleResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", context->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Addon/GetGoogle",
            headers,
            jsonAsString,
            OnGetGoogleResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetGoogleResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabAddonAPI::OnGetGoogleResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetGoogleResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetGoogleResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabAddonAPI::GetKongregate(
        GetKongregateRequest& request,
        const ProcessApiCallback<GetKongregateResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", context->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Addon/GetKongregate",
            headers,
            jsonAsString,
            OnGetKongregateResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetKongregateResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabAddonAPI::OnGetKongregateResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetKongregateResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetKongregateResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabAddonAPI::GetNintendo(
        GetNintendoRequest& request,
        const ProcessApiCallback<GetNintendoResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", context->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Addon/GetNintendo",
            headers,
            jsonAsString,
            OnGetNintendoResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetNintendoResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabAddonAPI::OnGetNintendoResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetNintendoResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetNintendoResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabAddonAPI::GetPSN(
        GetPSNRequest& request,
        const ProcessApiCallback<GetPSNResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", context->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Addon/GetPSN",
            headers,
            jsonAsString,
            OnGetPSNResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPSNResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabAddonAPI::OnGetPSNResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetPSNResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetPSNResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabAddonAPI::GetSteam(
        GetSteamRequest& request,
        const ProcessApiCallback<GetSteamResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", context->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Addon/GetSteam",
            headers,
            jsonAsString,
            OnGetSteamResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetSteamResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabAddonAPI::OnGetSteamResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetSteamResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetSteamResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabAddonAPI::GetTwitch(
        GetTwitchRequest& request,
        const ProcessApiCallback<GetTwitchResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", context->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Addon/GetTwitch",
            headers,
            jsonAsString,
            OnGetTwitchResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetTwitchResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabAddonAPI::OnGetTwitchResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetTwitchResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetTwitchResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    bool PlayFabAddonAPI::ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container)
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

#endif // #if !defined(DISABLE_PLAYFABENTITY_API)

#if defined(PLAYFAB_PLATFORM_WINDOWS)
#pragma warning (default: 4100) // formal parameters are part of a public interface
#endif // defined(PLAYFAB_PLATFORM_WINDOWS)
