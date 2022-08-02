#include <stdafx.h>

#if !defined(DISABLE_PLAYFABCLIENT_API)

#include <playfab/PlayFabClientApi.h>
#include <playfab/PlayFabPluginManager.h>
#include <playfab/PlayFabSettings.h>
#include <playfab/PlayFabError.h>
#include <memory>

#if defined(PLAYFAB_PLATFORM_WINDOWS)
#pragma warning (disable: 4100) // formal parameters are part of a public interface
#endif // defined(PLAYFAB_PLATFORM_WINDOWS)

namespace PlayFab
{
    using namespace ClientModels;

    size_t PlayFabClientAPI::Update()
    {
        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        return http.Update();
    }

    void PlayFabClientAPI::ForgetAllCredentials()
    {
        return PlayFabSettings::ForgetAllCredentials();
    }

    // PlayFabClient APIs

    void PlayFabClientAPI::AcceptTrade(
        AcceptTradeRequest& request,
        const ProcessApiCallback<AcceptTradeResponse> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/AcceptTrade",
            headers,
            jsonAsString,
            OnAcceptTradeResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<AcceptTradeResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnAcceptTradeResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        AcceptTradeResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<AcceptTradeResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::AddFriend(
        AddFriendRequest& request,
        const ProcessApiCallback<AddFriendResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/AddFriend",
            headers,
            jsonAsString,
            OnAddFriendResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<AddFriendResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnAddFriendResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        AddFriendResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<AddFriendResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::AddGenericID(
        AddGenericIDRequest& request,
        const ProcessApiCallback<AddGenericIDResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/AddGenericID",
            headers,
            jsonAsString,
            OnAddGenericIDResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<AddGenericIDResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnAddGenericIDResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        AddGenericIDResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<AddGenericIDResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::AddOrUpdateContactEmail(
        AddOrUpdateContactEmailRequest& request,
        const ProcessApiCallback<AddOrUpdateContactEmailResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/AddOrUpdateContactEmail",
            headers,
            jsonAsString,
            OnAddOrUpdateContactEmailResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<AddOrUpdateContactEmailResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnAddOrUpdateContactEmailResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        AddOrUpdateContactEmailResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<AddOrUpdateContactEmailResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::AddSharedGroupMembers(
        AddSharedGroupMembersRequest& request,
        const ProcessApiCallback<AddSharedGroupMembersResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/AddSharedGroupMembers",
            headers,
            jsonAsString,
            OnAddSharedGroupMembersResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<AddSharedGroupMembersResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnAddSharedGroupMembersResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        AddSharedGroupMembersResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<AddSharedGroupMembersResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::AddUsernamePassword(
        AddUsernamePasswordRequest& request,
        const ProcessApiCallback<AddUsernamePasswordResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/AddUsernamePassword",
            headers,
            jsonAsString,
            OnAddUsernamePasswordResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<AddUsernamePasswordResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnAddUsernamePasswordResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        AddUsernamePasswordResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<AddUsernamePasswordResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::AddUserVirtualCurrency(
        AddUserVirtualCurrencyRequest& request,
        const ProcessApiCallback<ModifyUserVirtualCurrencyResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/AddUserVirtualCurrency",
            headers,
            jsonAsString,
            OnAddUserVirtualCurrencyResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ModifyUserVirtualCurrencyResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnAddUserVirtualCurrencyResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        ModifyUserVirtualCurrencyResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<ModifyUserVirtualCurrencyResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::AndroidDevicePushNotificationRegistration(
        AndroidDevicePushNotificationRegistrationRequest& request,
        const ProcessApiCallback<AndroidDevicePushNotificationRegistrationResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/AndroidDevicePushNotificationRegistration",
            headers,
            jsonAsString,
            OnAndroidDevicePushNotificationRegistrationResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<AndroidDevicePushNotificationRegistrationResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnAndroidDevicePushNotificationRegistrationResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        AndroidDevicePushNotificationRegistrationResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<AndroidDevicePushNotificationRegistrationResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::AttributeInstall(
        AttributeInstallRequest& request,
        const ProcessApiCallback<AttributeInstallResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/AttributeInstall",
            headers,
            jsonAsString,
            OnAttributeInstallResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<AttributeInstallResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnAttributeInstallResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        AttributeInstallResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<AttributeInstallResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::CancelTrade(
        CancelTradeRequest& request,
        const ProcessApiCallback<CancelTradeResponse> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/CancelTrade",
            headers,
            jsonAsString,
            OnCancelTradeResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<CancelTradeResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnCancelTradeResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        CancelTradeResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<CancelTradeResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::ConfirmPurchase(
        ConfirmPurchaseRequest& request,
        const ProcessApiCallback<ConfirmPurchaseResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/ConfirmPurchase",
            headers,
            jsonAsString,
            OnConfirmPurchaseResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ConfirmPurchaseResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnConfirmPurchaseResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        ConfirmPurchaseResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<ConfirmPurchaseResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::ConsumeItem(
        ConsumeItemRequest& request,
        const ProcessApiCallback<ConsumeItemResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/ConsumeItem",
            headers,
            jsonAsString,
            OnConsumeItemResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ConsumeItemResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnConsumeItemResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        ConsumeItemResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<ConsumeItemResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::ConsumeMicrosoftStoreEntitlements(
        ConsumeMicrosoftStoreEntitlementsRequest& request,
        const ProcessApiCallback<ConsumeMicrosoftStoreEntitlementsResponse> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/ConsumeMicrosoftStoreEntitlements",
            headers,
            jsonAsString,
            OnConsumeMicrosoftStoreEntitlementsResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ConsumeMicrosoftStoreEntitlementsResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnConsumeMicrosoftStoreEntitlementsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        ConsumeMicrosoftStoreEntitlementsResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<ConsumeMicrosoftStoreEntitlementsResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::ConsumePS5Entitlements(
        ConsumePS5EntitlementsRequest& request,
        const ProcessApiCallback<ConsumePS5EntitlementsResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/ConsumePS5Entitlements",
            headers,
            jsonAsString,
            OnConsumePS5EntitlementsResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ConsumePS5EntitlementsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnConsumePS5EntitlementsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        ConsumePS5EntitlementsResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<ConsumePS5EntitlementsResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::ConsumePSNEntitlements(
        ConsumePSNEntitlementsRequest& request,
        const ProcessApiCallback<ConsumePSNEntitlementsResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/ConsumePSNEntitlements",
            headers,
            jsonAsString,
            OnConsumePSNEntitlementsResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ConsumePSNEntitlementsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnConsumePSNEntitlementsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        ConsumePSNEntitlementsResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<ConsumePSNEntitlementsResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::ConsumeXboxEntitlements(
        ConsumeXboxEntitlementsRequest& request,
        const ProcessApiCallback<ConsumeXboxEntitlementsResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/ConsumeXboxEntitlements",
            headers,
            jsonAsString,
            OnConsumeXboxEntitlementsResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ConsumeXboxEntitlementsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnConsumeXboxEntitlementsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        ConsumeXboxEntitlementsResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<ConsumeXboxEntitlementsResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::CreateSharedGroup(
        CreateSharedGroupRequest& request,
        const ProcessApiCallback<CreateSharedGroupResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/CreateSharedGroup",
            headers,
            jsonAsString,
            OnCreateSharedGroupResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<CreateSharedGroupResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnCreateSharedGroupResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        CreateSharedGroupResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<CreateSharedGroupResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::ExecuteCloudScript(
        ExecuteCloudScriptRequest& request,
        const ProcessApiCallback<ExecuteCloudScriptResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/ExecuteCloudScript",
            headers,
            jsonAsString,
            OnExecuteCloudScriptResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ExecuteCloudScriptResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnExecuteCloudScriptResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        ExecuteCloudScriptResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<ExecuteCloudScriptResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetAccountInfo(
        GetAccountInfoRequest& request,
        const ProcessApiCallback<GetAccountInfoResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetAccountInfo",
            headers,
            jsonAsString,
            OnGetAccountInfoResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetAccountInfoResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetAccountInfoResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetAccountInfoResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetAccountInfoResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetAdPlacements(
        GetAdPlacementsRequest& request,
        const ProcessApiCallback<GetAdPlacementsResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetAdPlacements",
            headers,
            jsonAsString,
            OnGetAdPlacementsResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetAdPlacementsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetAdPlacementsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetAdPlacementsResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetAdPlacementsResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetAllUsersCharacters(
        ListUsersCharactersRequest& request,
        const ProcessApiCallback<ListUsersCharactersResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetAllUsersCharacters",
            headers,
            jsonAsString,
            OnGetAllUsersCharactersResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ListUsersCharactersResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetAllUsersCharactersResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        ListUsersCharactersResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<ListUsersCharactersResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetCatalogItems(
        GetCatalogItemsRequest& request,
        const ProcessApiCallback<GetCatalogItemsResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetCatalogItems",
            headers,
            jsonAsString,
            OnGetCatalogItemsResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCatalogItemsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetCatalogItemsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetCatalogItemsResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetCatalogItemsResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetCharacterData(
        GetCharacterDataRequest& request,
        const ProcessApiCallback<GetCharacterDataResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetCharacterData",
            headers,
            jsonAsString,
            OnGetCharacterDataResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCharacterDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetCharacterDataResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetCharacterDataResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetCharacterDataResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetCharacterInventory(
        GetCharacterInventoryRequest& request,
        const ProcessApiCallback<GetCharacterInventoryResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetCharacterInventory",
            headers,
            jsonAsString,
            OnGetCharacterInventoryResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCharacterInventoryResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetCharacterInventoryResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetCharacterInventoryResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetCharacterInventoryResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetCharacterLeaderboard(
        GetCharacterLeaderboardRequest& request,
        const ProcessApiCallback<GetCharacterLeaderboardResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetCharacterLeaderboard",
            headers,
            jsonAsString,
            OnGetCharacterLeaderboardResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCharacterLeaderboardResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetCharacterLeaderboardResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetCharacterLeaderboardResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetCharacterLeaderboardResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetCharacterReadOnlyData(
        GetCharacterDataRequest& request,
        const ProcessApiCallback<GetCharacterDataResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetCharacterReadOnlyData",
            headers,
            jsonAsString,
            OnGetCharacterReadOnlyDataResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCharacterDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetCharacterReadOnlyDataResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetCharacterDataResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetCharacterDataResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetCharacterStatistics(
        GetCharacterStatisticsRequest& request,
        const ProcessApiCallback<GetCharacterStatisticsResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetCharacterStatistics",
            headers,
            jsonAsString,
            OnGetCharacterStatisticsResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCharacterStatisticsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetCharacterStatisticsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetCharacterStatisticsResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetCharacterStatisticsResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetContentDownloadUrl(
        GetContentDownloadUrlRequest& request,
        const ProcessApiCallback<GetContentDownloadUrlResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetContentDownloadUrl",
            headers,
            jsonAsString,
            OnGetContentDownloadUrlResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetContentDownloadUrlResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetContentDownloadUrlResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetContentDownloadUrlResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetContentDownloadUrlResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetCurrentGames(
        CurrentGamesRequest& request,
        const ProcessApiCallback<CurrentGamesResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetCurrentGames",
            headers,
            jsonAsString,
            OnGetCurrentGamesResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<CurrentGamesResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetCurrentGamesResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        CurrentGamesResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<CurrentGamesResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetFriendLeaderboard(
        GetFriendLeaderboardRequest& request,
        const ProcessApiCallback<GetLeaderboardResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetFriendLeaderboard",
            headers,
            jsonAsString,
            OnGetFriendLeaderboardResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetLeaderboardResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetFriendLeaderboardResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetLeaderboardResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetLeaderboardResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetFriendLeaderboardAroundPlayer(
        GetFriendLeaderboardAroundPlayerRequest& request,
        const ProcessApiCallback<GetFriendLeaderboardAroundPlayerResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetFriendLeaderboardAroundPlayer",
            headers,
            jsonAsString,
            OnGetFriendLeaderboardAroundPlayerResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetFriendLeaderboardAroundPlayerResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetFriendLeaderboardAroundPlayerResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetFriendLeaderboardAroundPlayerResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetFriendLeaderboardAroundPlayerResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetFriendsList(
        GetFriendsListRequest& request,
        const ProcessApiCallback<GetFriendsListResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetFriendsList",
            headers,
            jsonAsString,
            OnGetFriendsListResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetFriendsListResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetFriendsListResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetFriendsListResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetFriendsListResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetGameServerRegions(
        GameServerRegionsRequest& request,
        const ProcessApiCallback<GameServerRegionsResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetGameServerRegions",
            headers,
            jsonAsString,
            OnGetGameServerRegionsResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GameServerRegionsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetGameServerRegionsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GameServerRegionsResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GameServerRegionsResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetLeaderboard(
        GetLeaderboardRequest& request,
        const ProcessApiCallback<GetLeaderboardResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetLeaderboard",
            headers,
            jsonAsString,
            OnGetLeaderboardResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetLeaderboardResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetLeaderboardResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetLeaderboardResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetLeaderboardResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetLeaderboardAroundCharacter(
        GetLeaderboardAroundCharacterRequest& request,
        const ProcessApiCallback<GetLeaderboardAroundCharacterResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetLeaderboardAroundCharacter",
            headers,
            jsonAsString,
            OnGetLeaderboardAroundCharacterResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetLeaderboardAroundCharacterResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetLeaderboardAroundCharacterResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetLeaderboardAroundCharacterResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetLeaderboardAroundCharacterResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetLeaderboardAroundPlayer(
        GetLeaderboardAroundPlayerRequest& request,
        const ProcessApiCallback<GetLeaderboardAroundPlayerResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetLeaderboardAroundPlayer",
            headers,
            jsonAsString,
            OnGetLeaderboardAroundPlayerResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetLeaderboardAroundPlayerResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetLeaderboardAroundPlayerResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetLeaderboardAroundPlayerResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetLeaderboardAroundPlayerResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetLeaderboardForUserCharacters(
        GetLeaderboardForUsersCharactersRequest& request,
        const ProcessApiCallback<GetLeaderboardForUsersCharactersResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetLeaderboardForUserCharacters",
            headers,
            jsonAsString,
            OnGetLeaderboardForUserCharactersResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetLeaderboardForUsersCharactersResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetLeaderboardForUserCharactersResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetLeaderboardForUsersCharactersResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetLeaderboardForUsersCharactersResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetPaymentToken(
        GetPaymentTokenRequest& request,
        const ProcessApiCallback<GetPaymentTokenResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetPaymentToken",
            headers,
            jsonAsString,
            OnGetPaymentTokenResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPaymentTokenResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetPaymentTokenResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetPaymentTokenResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetPaymentTokenResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetPhotonAuthenticationToken(
        GetPhotonAuthenticationTokenRequest& request,
        const ProcessApiCallback<GetPhotonAuthenticationTokenResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetPhotonAuthenticationToken",
            headers,
            jsonAsString,
            OnGetPhotonAuthenticationTokenResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPhotonAuthenticationTokenResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetPhotonAuthenticationTokenResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetPhotonAuthenticationTokenResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetPhotonAuthenticationTokenResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetPlayerCombinedInfo(
        GetPlayerCombinedInfoRequest& request,
        const ProcessApiCallback<GetPlayerCombinedInfoResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetPlayerCombinedInfo",
            headers,
            jsonAsString,
            OnGetPlayerCombinedInfoResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerCombinedInfoResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetPlayerCombinedInfoResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetPlayerCombinedInfoResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetPlayerCombinedInfoResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetPlayerProfile(
        GetPlayerProfileRequest& request,
        const ProcessApiCallback<GetPlayerProfileResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetPlayerProfile",
            headers,
            jsonAsString,
            OnGetPlayerProfileResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerProfileResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetPlayerProfileResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetPlayerProfileResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetPlayerProfileResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetPlayerSegments(
        GetPlayerSegmentsRequest& request,
        const ProcessApiCallback<GetPlayerSegmentsResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetPlayerSegments",
            headers,
            jsonAsString,
            OnGetPlayerSegmentsResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerSegmentsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetPlayerSegmentsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetPlayerSegmentsResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetPlayerSegmentsResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetPlayerStatistics(
        GetPlayerStatisticsRequest& request,
        const ProcessApiCallback<GetPlayerStatisticsResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetPlayerStatistics",
            headers,
            jsonAsString,
            OnGetPlayerStatisticsResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerStatisticsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetPlayerStatisticsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetPlayerStatisticsResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetPlayerStatisticsResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetPlayerStatisticVersions(
        GetPlayerStatisticVersionsRequest& request,
        const ProcessApiCallback<GetPlayerStatisticVersionsResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetPlayerStatisticVersions",
            headers,
            jsonAsString,
            OnGetPlayerStatisticVersionsResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerStatisticVersionsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetPlayerStatisticVersionsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetPlayerStatisticVersionsResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetPlayerStatisticVersionsResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetPlayerTags(
        GetPlayerTagsRequest& request,
        const ProcessApiCallback<GetPlayerTagsResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetPlayerTags",
            headers,
            jsonAsString,
            OnGetPlayerTagsResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerTagsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetPlayerTagsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetPlayerTagsResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetPlayerTagsResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetPlayerTrades(
        GetPlayerTradesRequest& request,
        const ProcessApiCallback<GetPlayerTradesResponse> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetPlayerTrades",
            headers,
            jsonAsString,
            OnGetPlayerTradesResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerTradesResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetPlayerTradesResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetPlayerTradesResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetPlayerTradesResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetPlayFabIDsFromFacebookIDs(
        GetPlayFabIDsFromFacebookIDsRequest& request,
        const ProcessApiCallback<GetPlayFabIDsFromFacebookIDsResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetPlayFabIDsFromFacebookIDs",
            headers,
            jsonAsString,
            OnGetPlayFabIDsFromFacebookIDsResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromFacebookIDsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetPlayFabIDsFromFacebookIDsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetPlayFabIDsFromFacebookIDsResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetPlayFabIDsFromFacebookIDsResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetPlayFabIDsFromFacebookInstantGamesIds(
        GetPlayFabIDsFromFacebookInstantGamesIdsRequest& request,
        const ProcessApiCallback<GetPlayFabIDsFromFacebookInstantGamesIdsResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetPlayFabIDsFromFacebookInstantGamesIds",
            headers,
            jsonAsString,
            OnGetPlayFabIDsFromFacebookInstantGamesIdsResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromFacebookInstantGamesIdsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetPlayFabIDsFromFacebookInstantGamesIdsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetPlayFabIDsFromFacebookInstantGamesIdsResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetPlayFabIDsFromFacebookInstantGamesIdsResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetPlayFabIDsFromGameCenterIDs(
        GetPlayFabIDsFromGameCenterIDsRequest& request,
        const ProcessApiCallback<GetPlayFabIDsFromGameCenterIDsResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetPlayFabIDsFromGameCenterIDs",
            headers,
            jsonAsString,
            OnGetPlayFabIDsFromGameCenterIDsResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromGameCenterIDsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetPlayFabIDsFromGameCenterIDsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetPlayFabIDsFromGameCenterIDsResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetPlayFabIDsFromGameCenterIDsResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetPlayFabIDsFromGenericIDs(
        GetPlayFabIDsFromGenericIDsRequest& request,
        const ProcessApiCallback<GetPlayFabIDsFromGenericIDsResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetPlayFabIDsFromGenericIDs",
            headers,
            jsonAsString,
            OnGetPlayFabIDsFromGenericIDsResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromGenericIDsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetPlayFabIDsFromGenericIDsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetPlayFabIDsFromGenericIDsResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetPlayFabIDsFromGenericIDsResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetPlayFabIDsFromGoogleIDs(
        GetPlayFabIDsFromGoogleIDsRequest& request,
        const ProcessApiCallback<GetPlayFabIDsFromGoogleIDsResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetPlayFabIDsFromGoogleIDs",
            headers,
            jsonAsString,
            OnGetPlayFabIDsFromGoogleIDsResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromGoogleIDsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetPlayFabIDsFromGoogleIDsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetPlayFabIDsFromGoogleIDsResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetPlayFabIDsFromGoogleIDsResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetPlayFabIDsFromKongregateIDs(
        GetPlayFabIDsFromKongregateIDsRequest& request,
        const ProcessApiCallback<GetPlayFabIDsFromKongregateIDsResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetPlayFabIDsFromKongregateIDs",
            headers,
            jsonAsString,
            OnGetPlayFabIDsFromKongregateIDsResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromKongregateIDsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetPlayFabIDsFromKongregateIDsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetPlayFabIDsFromKongregateIDsResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetPlayFabIDsFromKongregateIDsResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetPlayFabIDsFromNintendoServiceAccountIds(
        GetPlayFabIDsFromNintendoServiceAccountIdsRequest& request,
        const ProcessApiCallback<GetPlayFabIDsFromNintendoServiceAccountIdsResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetPlayFabIDsFromNintendoServiceAccountIds",
            headers,
            jsonAsString,
            OnGetPlayFabIDsFromNintendoServiceAccountIdsResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromNintendoServiceAccountIdsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetPlayFabIDsFromNintendoServiceAccountIdsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetPlayFabIDsFromNintendoServiceAccountIdsResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetPlayFabIDsFromNintendoServiceAccountIdsResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetPlayFabIDsFromNintendoSwitchDeviceIds(
        GetPlayFabIDsFromNintendoSwitchDeviceIdsRequest& request,
        const ProcessApiCallback<GetPlayFabIDsFromNintendoSwitchDeviceIdsResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetPlayFabIDsFromNintendoSwitchDeviceIds",
            headers,
            jsonAsString,
            OnGetPlayFabIDsFromNintendoSwitchDeviceIdsResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromNintendoSwitchDeviceIdsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetPlayFabIDsFromNintendoSwitchDeviceIdsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetPlayFabIDsFromNintendoSwitchDeviceIdsResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetPlayFabIDsFromNintendoSwitchDeviceIdsResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetPlayFabIDsFromPSNAccountIDs(
        GetPlayFabIDsFromPSNAccountIDsRequest& request,
        const ProcessApiCallback<GetPlayFabIDsFromPSNAccountIDsResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetPlayFabIDsFromPSNAccountIDs",
            headers,
            jsonAsString,
            OnGetPlayFabIDsFromPSNAccountIDsResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromPSNAccountIDsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetPlayFabIDsFromPSNAccountIDsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetPlayFabIDsFromPSNAccountIDsResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetPlayFabIDsFromPSNAccountIDsResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetPlayFabIDsFromSteamIDs(
        GetPlayFabIDsFromSteamIDsRequest& request,
        const ProcessApiCallback<GetPlayFabIDsFromSteamIDsResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetPlayFabIDsFromSteamIDs",
            headers,
            jsonAsString,
            OnGetPlayFabIDsFromSteamIDsResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromSteamIDsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetPlayFabIDsFromSteamIDsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetPlayFabIDsFromSteamIDsResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetPlayFabIDsFromSteamIDsResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetPlayFabIDsFromTwitchIDs(
        GetPlayFabIDsFromTwitchIDsRequest& request,
        const ProcessApiCallback<GetPlayFabIDsFromTwitchIDsResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetPlayFabIDsFromTwitchIDs",
            headers,
            jsonAsString,
            OnGetPlayFabIDsFromTwitchIDsResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromTwitchIDsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetPlayFabIDsFromTwitchIDsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetPlayFabIDsFromTwitchIDsResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetPlayFabIDsFromTwitchIDsResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetPlayFabIDsFromXboxLiveIDs(
        GetPlayFabIDsFromXboxLiveIDsRequest& request,
        const ProcessApiCallback<GetPlayFabIDsFromXboxLiveIDsResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetPlayFabIDsFromXboxLiveIDs",
            headers,
            jsonAsString,
            OnGetPlayFabIDsFromXboxLiveIDsResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromXboxLiveIDsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetPlayFabIDsFromXboxLiveIDsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetPlayFabIDsFromXboxLiveIDsResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetPlayFabIDsFromXboxLiveIDsResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetPublisherData(
        GetPublisherDataRequest& request,
        const ProcessApiCallback<GetPublisherDataResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetPublisherData",
            headers,
            jsonAsString,
            OnGetPublisherDataResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPublisherDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetPublisherDataResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetPublisherDataResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetPublisherDataResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetPurchase(
        GetPurchaseRequest& request,
        const ProcessApiCallback<GetPurchaseResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetPurchase",
            headers,
            jsonAsString,
            OnGetPurchaseResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPurchaseResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetPurchaseResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetPurchaseResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetPurchaseResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetSharedGroupData(
        GetSharedGroupDataRequest& request,
        const ProcessApiCallback<GetSharedGroupDataResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetSharedGroupData",
            headers,
            jsonAsString,
            OnGetSharedGroupDataResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetSharedGroupDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetSharedGroupDataResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetSharedGroupDataResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetSharedGroupDataResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetStoreItems(
        GetStoreItemsRequest& request,
        const ProcessApiCallback<GetStoreItemsResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetStoreItems",
            headers,
            jsonAsString,
            OnGetStoreItemsResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetStoreItemsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetStoreItemsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetStoreItemsResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetStoreItemsResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetTime(
        GetTimeRequest& request,
        const ProcessApiCallback<GetTimeResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetTime",
            headers,
            jsonAsString,
            OnGetTimeResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetTimeResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetTimeResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetTimeResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetTimeResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetTitleData(
        GetTitleDataRequest& request,
        const ProcessApiCallback<GetTitleDataResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetTitleData",
            headers,
            jsonAsString,
            OnGetTitleDataResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetTitleDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetTitleDataResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetTitleDataResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetTitleDataResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetTitleNews(
        GetTitleNewsRequest& request,
        const ProcessApiCallback<GetTitleNewsResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetTitleNews",
            headers,
            jsonAsString,
            OnGetTitleNewsResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetTitleNewsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetTitleNewsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetTitleNewsResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetTitleNewsResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetTitlePublicKey(
        GetTitlePublicKeyRequest& request,
        const ProcessApiCallback<GetTitlePublicKeyResult> callback,
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

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetTitlePublicKey",
            headers,
            jsonAsString,
            OnGetTitlePublicKeyResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetTitlePublicKeyResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetTitlePublicKeyResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetTitlePublicKeyResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetTitlePublicKeyResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetTradeStatus(
        GetTradeStatusRequest& request,
        const ProcessApiCallback<GetTradeStatusResponse> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetTradeStatus",
            headers,
            jsonAsString,
            OnGetTradeStatusResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetTradeStatusResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetTradeStatusResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetTradeStatusResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetTradeStatusResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetUserData(
        GetUserDataRequest& request,
        const ProcessApiCallback<GetUserDataResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetUserData",
            headers,
            jsonAsString,
            OnGetUserDataResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetUserDataResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetUserDataResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetUserDataResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetUserInventory(
        GetUserInventoryRequest& request,
        const ProcessApiCallback<GetUserInventoryResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetUserInventory",
            headers,
            jsonAsString,
            OnGetUserInventoryResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserInventoryResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetUserInventoryResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetUserInventoryResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetUserInventoryResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetUserPublisherData(
        GetUserDataRequest& request,
        const ProcessApiCallback<GetUserDataResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetUserPublisherData",
            headers,
            jsonAsString,
            OnGetUserPublisherDataResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetUserPublisherDataResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetUserDataResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetUserDataResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetUserPublisherReadOnlyData(
        GetUserDataRequest& request,
        const ProcessApiCallback<GetUserDataResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetUserPublisherReadOnlyData",
            headers,
            jsonAsString,
            OnGetUserPublisherReadOnlyDataResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetUserPublisherReadOnlyDataResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetUserDataResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetUserDataResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GetUserReadOnlyData(
        GetUserDataRequest& request,
        const ProcessApiCallback<GetUserDataResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GetUserReadOnlyData",
            headers,
            jsonAsString,
            OnGetUserReadOnlyDataResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGetUserReadOnlyDataResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetUserDataResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GetUserDataResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::GrantCharacterToUser(
        GrantCharacterToUserRequest& request,
        const ProcessApiCallback<GrantCharacterToUserResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/GrantCharacterToUser",
            headers,
            jsonAsString,
            OnGrantCharacterToUserResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GrantCharacterToUserResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnGrantCharacterToUserResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GrantCharacterToUserResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<GrantCharacterToUserResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::LinkAndroidDeviceID(
        LinkAndroidDeviceIDRequest& request,
        const ProcessApiCallback<LinkAndroidDeviceIDResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/LinkAndroidDeviceID",
            headers,
            jsonAsString,
            OnLinkAndroidDeviceIDResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkAndroidDeviceIDResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnLinkAndroidDeviceIDResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        LinkAndroidDeviceIDResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<LinkAndroidDeviceIDResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::LinkApple(
        LinkAppleRequest& request,
        const ProcessApiCallback<EmptyResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/LinkApple",
            headers,
            jsonAsString,
            OnLinkAppleResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnLinkAppleResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        EmptyResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<EmptyResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::LinkCustomID(
        LinkCustomIDRequest& request,
        const ProcessApiCallback<LinkCustomIDResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/LinkCustomID",
            headers,
            jsonAsString,
            OnLinkCustomIDResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkCustomIDResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnLinkCustomIDResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        LinkCustomIDResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<LinkCustomIDResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::LinkFacebookAccount(
        LinkFacebookAccountRequest& request,
        const ProcessApiCallback<LinkFacebookAccountResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/LinkFacebookAccount",
            headers,
            jsonAsString,
            OnLinkFacebookAccountResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkFacebookAccountResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnLinkFacebookAccountResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        LinkFacebookAccountResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<LinkFacebookAccountResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::LinkFacebookInstantGamesId(
        LinkFacebookInstantGamesIdRequest& request,
        const ProcessApiCallback<LinkFacebookInstantGamesIdResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/LinkFacebookInstantGamesId",
            headers,
            jsonAsString,
            OnLinkFacebookInstantGamesIdResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkFacebookInstantGamesIdResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnLinkFacebookInstantGamesIdResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        LinkFacebookInstantGamesIdResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<LinkFacebookInstantGamesIdResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::LinkGameCenterAccount(
        LinkGameCenterAccountRequest& request,
        const ProcessApiCallback<LinkGameCenterAccountResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/LinkGameCenterAccount",
            headers,
            jsonAsString,
            OnLinkGameCenterAccountResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkGameCenterAccountResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnLinkGameCenterAccountResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        LinkGameCenterAccountResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<LinkGameCenterAccountResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::LinkGoogleAccount(
        LinkGoogleAccountRequest& request,
        const ProcessApiCallback<LinkGoogleAccountResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/LinkGoogleAccount",
            headers,
            jsonAsString,
            OnLinkGoogleAccountResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkGoogleAccountResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnLinkGoogleAccountResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        LinkGoogleAccountResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<LinkGoogleAccountResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::LinkIOSDeviceID(
        LinkIOSDeviceIDRequest& request,
        const ProcessApiCallback<LinkIOSDeviceIDResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/LinkIOSDeviceID",
            headers,
            jsonAsString,
            OnLinkIOSDeviceIDResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkIOSDeviceIDResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnLinkIOSDeviceIDResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        LinkIOSDeviceIDResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<LinkIOSDeviceIDResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::LinkKongregate(
        LinkKongregateAccountRequest& request,
        const ProcessApiCallback<LinkKongregateAccountResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/LinkKongregate",
            headers,
            jsonAsString,
            OnLinkKongregateResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkKongregateAccountResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnLinkKongregateResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        LinkKongregateAccountResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<LinkKongregateAccountResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::LinkNintendoServiceAccount(
        LinkNintendoServiceAccountRequest& request,
        const ProcessApiCallback<EmptyResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/LinkNintendoServiceAccount",
            headers,
            jsonAsString,
            OnLinkNintendoServiceAccountResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnLinkNintendoServiceAccountResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        EmptyResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<EmptyResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::LinkNintendoSwitchDeviceId(
        LinkNintendoSwitchDeviceIdRequest& request,
        const ProcessApiCallback<LinkNintendoSwitchDeviceIdResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/LinkNintendoSwitchDeviceId",
            headers,
            jsonAsString,
            OnLinkNintendoSwitchDeviceIdResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkNintendoSwitchDeviceIdResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnLinkNintendoSwitchDeviceIdResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        LinkNintendoSwitchDeviceIdResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<LinkNintendoSwitchDeviceIdResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::LinkOpenIdConnect(
        LinkOpenIdConnectRequest& request,
        const ProcessApiCallback<EmptyResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/LinkOpenIdConnect",
            headers,
            jsonAsString,
            OnLinkOpenIdConnectResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnLinkOpenIdConnectResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        EmptyResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<EmptyResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::LinkPSNAccount(
        LinkPSNAccountRequest& request,
        const ProcessApiCallback<LinkPSNAccountResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/LinkPSNAccount",
            headers,
            jsonAsString,
            OnLinkPSNAccountResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkPSNAccountResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnLinkPSNAccountResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        LinkPSNAccountResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<LinkPSNAccountResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::LinkSteamAccount(
        LinkSteamAccountRequest& request,
        const ProcessApiCallback<LinkSteamAccountResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/LinkSteamAccount",
            headers,
            jsonAsString,
            OnLinkSteamAccountResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkSteamAccountResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnLinkSteamAccountResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        LinkSteamAccountResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<LinkSteamAccountResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::LinkTwitch(
        LinkTwitchAccountRequest& request,
        const ProcessApiCallback<LinkTwitchAccountResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/LinkTwitch",
            headers,
            jsonAsString,
            OnLinkTwitchResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkTwitchAccountResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnLinkTwitchResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        LinkTwitchAccountResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<LinkTwitchAccountResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::LinkXboxAccount(
        LinkXboxAccountRequest& request,
        const ProcessApiCallback<LinkXboxAccountResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/LinkXboxAccount",
            headers,
            jsonAsString,
            OnLinkXboxAccountResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkXboxAccountResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnLinkXboxAccountResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        LinkXboxAccountResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<LinkXboxAccountResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::LoginWithAndroidDeviceID(
        LoginWithAndroidDeviceIDRequest& request,
        const ProcessApiCallback<LoginResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;
        if (request.TitleId.empty())
        {
                if (!settings->titleId.empty())
                {
                        request.TitleId = settings->titleId;
                }
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/LoginWithAndroidDeviceID",
            headers,
            jsonAsString,
            OnLoginWithAndroidDeviceIDResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnLoginWithAndroidDeviceIDResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        LoginResult outResult;
        if (ValidateResult(outResult, container))
        {            
            outResult.authenticationContext = std::make_shared<PlayFabAuthenticationContext>();
            if (outResult.EntityToken.notNull())
            {
                outResult.authenticationContext->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);
                context->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);
            }
            else
            {
                if (container.errorCallback != nullptr)
                {
                     PlayFabError error;
                     error.ErrorCode = PlayFabErrorCode::PlayFabErrorEntityTokenMissing;
                     error.ErrorMessage = "The Login Attempt returned a null EntityToken. This was a mistake. Please try the login again in a moment.";
                     container.errorCallback(error, container.GetCustomData());
                     return;
                }
            }

            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::LoginWithApple(
        LoginWithAppleRequest& request,
        const ProcessApiCallback<LoginResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;
        if (request.TitleId.empty())
        {
                if (!settings->titleId.empty())
                {
                        request.TitleId = settings->titleId;
                }
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/LoginWithApple",
            headers,
            jsonAsString,
            OnLoginWithAppleResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnLoginWithAppleResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        LoginResult outResult;
        if (ValidateResult(outResult, container))
        {            
            outResult.authenticationContext = std::make_shared<PlayFabAuthenticationContext>();
            if (outResult.EntityToken.notNull())
            {
                outResult.authenticationContext->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);
                context->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);
            }
            else
            {
                if (container.errorCallback != nullptr)
                {
                     PlayFabError error;
                     error.ErrorCode = PlayFabErrorCode::PlayFabErrorEntityTokenMissing;
                     error.ErrorMessage = "The Login Attempt returned a null EntityToken. This was a mistake. Please try the login again in a moment.";
                     container.errorCallback(error, container.GetCustomData());
                     return;
                }
            }

            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::LoginWithCustomID(
        LoginWithCustomIDRequest& request,
        const ProcessApiCallback<LoginResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;
        if (request.TitleId.empty())
        {
                if (!settings->titleId.empty())
                {
                        request.TitleId = settings->titleId;
                }
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/LoginWithCustomID",
            headers,
            jsonAsString,
            OnLoginWithCustomIDResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnLoginWithCustomIDResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        LoginResult outResult;
        if (ValidateResult(outResult, container))
        {            
            outResult.authenticationContext = std::make_shared<PlayFabAuthenticationContext>();
            if (outResult.EntityToken.notNull())
            {
                outResult.authenticationContext->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);
                context->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);
            }
            else
            {
                if (container.errorCallback != nullptr)
                {
                     PlayFabError error;
                     error.ErrorCode = PlayFabErrorCode::PlayFabErrorEntityTokenMissing;
                     error.ErrorMessage = "The Login Attempt returned a null EntityToken. This was a mistake. Please try the login again in a moment.";
                     container.errorCallback(error, container.GetCustomData());
                     return;
                }
            }

            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::LoginWithEmailAddress(
        LoginWithEmailAddressRequest& request,
        const ProcessApiCallback<LoginResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;
        if (request.TitleId.empty())
        {
                if (!settings->titleId.empty())
                {
                        request.TitleId = settings->titleId;
                }
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/LoginWithEmailAddress",
            headers,
            jsonAsString,
            OnLoginWithEmailAddressResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnLoginWithEmailAddressResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        LoginResult outResult;
        if (ValidateResult(outResult, container))
        {            
            outResult.authenticationContext = std::make_shared<PlayFabAuthenticationContext>();
            if (outResult.EntityToken.notNull())
            {
                outResult.authenticationContext->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);
                context->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);
            }
            else
            {
                if (container.errorCallback != nullptr)
                {
                     PlayFabError error;
                     error.ErrorCode = PlayFabErrorCode::PlayFabErrorEntityTokenMissing;
                     error.ErrorMessage = "The Login Attempt returned a null EntityToken. This was a mistake. Please try the login again in a moment.";
                     container.errorCallback(error, container.GetCustomData());
                     return;
                }
            }

            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::LoginWithFacebook(
        LoginWithFacebookRequest& request,
        const ProcessApiCallback<LoginResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;
        if (request.TitleId.empty())
        {
                if (!settings->titleId.empty())
                {
                        request.TitleId = settings->titleId;
                }
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/LoginWithFacebook",
            headers,
            jsonAsString,
            OnLoginWithFacebookResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnLoginWithFacebookResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        LoginResult outResult;
        if (ValidateResult(outResult, container))
        {            
            outResult.authenticationContext = std::make_shared<PlayFabAuthenticationContext>();
            if (outResult.EntityToken.notNull())
            {
                outResult.authenticationContext->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);
                context->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);
            }
            else
            {
                if (container.errorCallback != nullptr)
                {
                     PlayFabError error;
                     error.ErrorCode = PlayFabErrorCode::PlayFabErrorEntityTokenMissing;
                     error.ErrorMessage = "The Login Attempt returned a null EntityToken. This was a mistake. Please try the login again in a moment.";
                     container.errorCallback(error, container.GetCustomData());
                     return;
                }
            }

            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::LoginWithFacebookInstantGamesId(
        LoginWithFacebookInstantGamesIdRequest& request,
        const ProcessApiCallback<LoginResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;
        if (request.TitleId.empty())
        {
                if (!settings->titleId.empty())
                {
                        request.TitleId = settings->titleId;
                }
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/LoginWithFacebookInstantGamesId",
            headers,
            jsonAsString,
            OnLoginWithFacebookInstantGamesIdResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnLoginWithFacebookInstantGamesIdResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        LoginResult outResult;
        if (ValidateResult(outResult, container))
        {            
            outResult.authenticationContext = std::make_shared<PlayFabAuthenticationContext>();
            if (outResult.EntityToken.notNull())
            {
                outResult.authenticationContext->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);
                context->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);
            }
            else
            {
                if (container.errorCallback != nullptr)
                {
                     PlayFabError error;
                     error.ErrorCode = PlayFabErrorCode::PlayFabErrorEntityTokenMissing;
                     error.ErrorMessage = "The Login Attempt returned a null EntityToken. This was a mistake. Please try the login again in a moment.";
                     container.errorCallback(error, container.GetCustomData());
                     return;
                }
            }

            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::LoginWithGameCenter(
        LoginWithGameCenterRequest& request,
        const ProcessApiCallback<LoginResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;
        if (request.TitleId.empty())
        {
                if (!settings->titleId.empty())
                {
                        request.TitleId = settings->titleId;
                }
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/LoginWithGameCenter",
            headers,
            jsonAsString,
            OnLoginWithGameCenterResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnLoginWithGameCenterResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        LoginResult outResult;
        if (ValidateResult(outResult, container))
        {            
            outResult.authenticationContext = std::make_shared<PlayFabAuthenticationContext>();
            if (outResult.EntityToken.notNull())
            {
                outResult.authenticationContext->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);
                context->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);
            }
            else
            {
                if (container.errorCallback != nullptr)
                {
                     PlayFabError error;
                     error.ErrorCode = PlayFabErrorCode::PlayFabErrorEntityTokenMissing;
                     error.ErrorMessage = "The Login Attempt returned a null EntityToken. This was a mistake. Please try the login again in a moment.";
                     container.errorCallback(error, container.GetCustomData());
                     return;
                }
            }

            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::LoginWithGoogleAccount(
        LoginWithGoogleAccountRequest& request,
        const ProcessApiCallback<LoginResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;
        if (request.TitleId.empty())
        {
                if (!settings->titleId.empty())
                {
                        request.TitleId = settings->titleId;
                }
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/LoginWithGoogleAccount",
            headers,
            jsonAsString,
            OnLoginWithGoogleAccountResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnLoginWithGoogleAccountResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        LoginResult outResult;
        if (ValidateResult(outResult, container))
        {            
            outResult.authenticationContext = std::make_shared<PlayFabAuthenticationContext>();
            if (outResult.EntityToken.notNull())
            {
                outResult.authenticationContext->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);
                context->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);
            }
            else
            {
                if (container.errorCallback != nullptr)
                {
                     PlayFabError error;
                     error.ErrorCode = PlayFabErrorCode::PlayFabErrorEntityTokenMissing;
                     error.ErrorMessage = "The Login Attempt returned a null EntityToken. This was a mistake. Please try the login again in a moment.";
                     container.errorCallback(error, container.GetCustomData());
                     return;
                }
            }

            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::LoginWithGooglePlayGamesServices(
        LoginWithGooglePlayGamesServicesRequest& request,
        const ProcessApiCallback<LoginResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;
        if (request.TitleId.empty())
        {
                if (!settings->titleId.empty())
                {
                        request.TitleId = settings->titleId;
                }
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/LoginWithGooglePlayGamesServices",
            headers,
            jsonAsString,
            OnLoginWithGooglePlayGamesServicesResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnLoginWithGooglePlayGamesServicesResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        LoginResult outResult;
        if (ValidateResult(outResult, container))
        {            
            outResult.authenticationContext = std::make_shared<PlayFabAuthenticationContext>();
            if (outResult.EntityToken.notNull())
            {
                outResult.authenticationContext->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);
                context->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);
            }
            else
            {
                if (container.errorCallback != nullptr)
                {
                     PlayFabError error;
                     error.ErrorCode = PlayFabErrorCode::PlayFabErrorEntityTokenMissing;
                     error.ErrorMessage = "The Login Attempt returned a null EntityToken. This was a mistake. Please try the login again in a moment.";
                     container.errorCallback(error, container.GetCustomData());
                     return;
                }
            }

            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::LoginWithIOSDeviceID(
        LoginWithIOSDeviceIDRequest& request,
        const ProcessApiCallback<LoginResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;
        if (request.TitleId.empty())
        {
                if (!settings->titleId.empty())
                {
                        request.TitleId = settings->titleId;
                }
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/LoginWithIOSDeviceID",
            headers,
            jsonAsString,
            OnLoginWithIOSDeviceIDResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnLoginWithIOSDeviceIDResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        LoginResult outResult;
        if (ValidateResult(outResult, container))
        {            
            outResult.authenticationContext = std::make_shared<PlayFabAuthenticationContext>();
            if (outResult.EntityToken.notNull())
            {
                outResult.authenticationContext->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);
                context->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);
            }
            else
            {
                if (container.errorCallback != nullptr)
                {
                     PlayFabError error;
                     error.ErrorCode = PlayFabErrorCode::PlayFabErrorEntityTokenMissing;
                     error.ErrorMessage = "The Login Attempt returned a null EntityToken. This was a mistake. Please try the login again in a moment.";
                     container.errorCallback(error, container.GetCustomData());
                     return;
                }
            }

            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::LoginWithKongregate(
        LoginWithKongregateRequest& request,
        const ProcessApiCallback<LoginResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;
        if (request.TitleId.empty())
        {
                if (!settings->titleId.empty())
                {
                        request.TitleId = settings->titleId;
                }
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/LoginWithKongregate",
            headers,
            jsonAsString,
            OnLoginWithKongregateResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnLoginWithKongregateResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        LoginResult outResult;
        if (ValidateResult(outResult, container))
        {            
            outResult.authenticationContext = std::make_shared<PlayFabAuthenticationContext>();
            if (outResult.EntityToken.notNull())
            {
                outResult.authenticationContext->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);
                context->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);
            }
            else
            {
                if (container.errorCallback != nullptr)
                {
                     PlayFabError error;
                     error.ErrorCode = PlayFabErrorCode::PlayFabErrorEntityTokenMissing;
                     error.ErrorMessage = "The Login Attempt returned a null EntityToken. This was a mistake. Please try the login again in a moment.";
                     container.errorCallback(error, container.GetCustomData());
                     return;
                }
            }

            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::LoginWithNintendoServiceAccount(
        LoginWithNintendoServiceAccountRequest& request,
        const ProcessApiCallback<LoginResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;
        if (request.TitleId.empty())
        {
                if (!settings->titleId.empty())
                {
                        request.TitleId = settings->titleId;
                }
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/LoginWithNintendoServiceAccount",
            headers,
            jsonAsString,
            OnLoginWithNintendoServiceAccountResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnLoginWithNintendoServiceAccountResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        LoginResult outResult;
        if (ValidateResult(outResult, container))
        {            
            outResult.authenticationContext = std::make_shared<PlayFabAuthenticationContext>();
            if (outResult.EntityToken.notNull())
            {
                outResult.authenticationContext->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);
                context->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);
            }
            else
            {
                if (container.errorCallback != nullptr)
                {
                     PlayFabError error;
                     error.ErrorCode = PlayFabErrorCode::PlayFabErrorEntityTokenMissing;
                     error.ErrorMessage = "The Login Attempt returned a null EntityToken. This was a mistake. Please try the login again in a moment.";
                     container.errorCallback(error, container.GetCustomData());
                     return;
                }
            }

            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::LoginWithNintendoSwitchDeviceId(
        LoginWithNintendoSwitchDeviceIdRequest& request,
        const ProcessApiCallback<LoginResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;
        if (request.TitleId.empty())
        {
                if (!settings->titleId.empty())
                {
                        request.TitleId = settings->titleId;
                }
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/LoginWithNintendoSwitchDeviceId",
            headers,
            jsonAsString,
            OnLoginWithNintendoSwitchDeviceIdResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnLoginWithNintendoSwitchDeviceIdResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        LoginResult outResult;
        if (ValidateResult(outResult, container))
        {            
            outResult.authenticationContext = std::make_shared<PlayFabAuthenticationContext>();
            if (outResult.EntityToken.notNull())
            {
                outResult.authenticationContext->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);
                context->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);
            }
            else
            {
                if (container.errorCallback != nullptr)
                {
                     PlayFabError error;
                     error.ErrorCode = PlayFabErrorCode::PlayFabErrorEntityTokenMissing;
                     error.ErrorMessage = "The Login Attempt returned a null EntityToken. This was a mistake. Please try the login again in a moment.";
                     container.errorCallback(error, container.GetCustomData());
                     return;
                }
            }

            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::LoginWithOpenIdConnect(
        LoginWithOpenIdConnectRequest& request,
        const ProcessApiCallback<LoginResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;
        if (request.TitleId.empty())
        {
                if (!settings->titleId.empty())
                {
                        request.TitleId = settings->titleId;
                }
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/LoginWithOpenIdConnect",
            headers,
            jsonAsString,
            OnLoginWithOpenIdConnectResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnLoginWithOpenIdConnectResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        LoginResult outResult;
        if (ValidateResult(outResult, container))
        {            
            outResult.authenticationContext = std::make_shared<PlayFabAuthenticationContext>();
            if (outResult.EntityToken.notNull())
            {
                outResult.authenticationContext->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);
                context->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);
            }
            else
            {
                if (container.errorCallback != nullptr)
                {
                     PlayFabError error;
                     error.ErrorCode = PlayFabErrorCode::PlayFabErrorEntityTokenMissing;
                     error.ErrorMessage = "The Login Attempt returned a null EntityToken. This was a mistake. Please try the login again in a moment.";
                     container.errorCallback(error, container.GetCustomData());
                     return;
                }
            }

            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::LoginWithPlayFab(
        LoginWithPlayFabRequest& request,
        const ProcessApiCallback<LoginResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;
        if (request.TitleId.empty())
        {
                if (!settings->titleId.empty())
                {
                        request.TitleId = settings->titleId;
                }
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/LoginWithPlayFab",
            headers,
            jsonAsString,
            OnLoginWithPlayFabResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnLoginWithPlayFabResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        LoginResult outResult;
        if (ValidateResult(outResult, container))
        {            
            outResult.authenticationContext = std::make_shared<PlayFabAuthenticationContext>();
            if (outResult.EntityToken.notNull())
            {
                outResult.authenticationContext->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);
                context->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);
            }
            else
            {
                if (container.errorCallback != nullptr)
                {
                     PlayFabError error;
                     error.ErrorCode = PlayFabErrorCode::PlayFabErrorEntityTokenMissing;
                     error.ErrorMessage = "The Login Attempt returned a null EntityToken. This was a mistake. Please try the login again in a moment.";
                     container.errorCallback(error, container.GetCustomData());
                     return;
                }
            }

            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::LoginWithPSN(
        LoginWithPSNRequest& request,
        const ProcessApiCallback<LoginResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;
        if (request.TitleId.empty())
        {
                if (!settings->titleId.empty())
                {
                        request.TitleId = settings->titleId;
                }
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/LoginWithPSN",
            headers,
            jsonAsString,
            OnLoginWithPSNResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnLoginWithPSNResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        LoginResult outResult;
        if (ValidateResult(outResult, container))
        {            
            outResult.authenticationContext = std::make_shared<PlayFabAuthenticationContext>();
            if (outResult.EntityToken.notNull())
            {
                outResult.authenticationContext->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);
                context->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);
            }
            else
            {
                if (container.errorCallback != nullptr)
                {
                     PlayFabError error;
                     error.ErrorCode = PlayFabErrorCode::PlayFabErrorEntityTokenMissing;
                     error.ErrorMessage = "The Login Attempt returned a null EntityToken. This was a mistake. Please try the login again in a moment.";
                     container.errorCallback(error, container.GetCustomData());
                     return;
                }
            }

            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::LoginWithSteam(
        LoginWithSteamRequest& request,
        const ProcessApiCallback<LoginResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;
        if (request.TitleId.empty())
        {
                if (!settings->titleId.empty())
                {
                        request.TitleId = settings->titleId;
                }
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/LoginWithSteam",
            headers,
            jsonAsString,
            OnLoginWithSteamResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnLoginWithSteamResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        LoginResult outResult;
        if (ValidateResult(outResult, container))
        {            
            outResult.authenticationContext = std::make_shared<PlayFabAuthenticationContext>();
            if (outResult.EntityToken.notNull())
            {
                outResult.authenticationContext->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);
                context->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);
            }
            else
            {
                if (container.errorCallback != nullptr)
                {
                     PlayFabError error;
                     error.ErrorCode = PlayFabErrorCode::PlayFabErrorEntityTokenMissing;
                     error.ErrorMessage = "The Login Attempt returned a null EntityToken. This was a mistake. Please try the login again in a moment.";
                     container.errorCallback(error, container.GetCustomData());
                     return;
                }
            }

            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::LoginWithTwitch(
        LoginWithTwitchRequest& request,
        const ProcessApiCallback<LoginResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;
        if (request.TitleId.empty())
        {
                if (!settings->titleId.empty())
                {
                        request.TitleId = settings->titleId;
                }
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/LoginWithTwitch",
            headers,
            jsonAsString,
            OnLoginWithTwitchResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnLoginWithTwitchResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        LoginResult outResult;
        if (ValidateResult(outResult, container))
        {            
            outResult.authenticationContext = std::make_shared<PlayFabAuthenticationContext>();
            if (outResult.EntityToken.notNull())
            {
                outResult.authenticationContext->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);
                context->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);
            }
            else
            {
                if (container.errorCallback != nullptr)
                {
                     PlayFabError error;
                     error.ErrorCode = PlayFabErrorCode::PlayFabErrorEntityTokenMissing;
                     error.ErrorMessage = "The Login Attempt returned a null EntityToken. This was a mistake. Please try the login again in a moment.";
                     container.errorCallback(error, container.GetCustomData());
                     return;
                }
            }

            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::LoginWithXbox(
        LoginWithXboxRequest& request,
        const ProcessApiCallback<LoginResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;
        if (request.TitleId.empty())
        {
                if (!settings->titleId.empty())
                {
                        request.TitleId = settings->titleId;
                }
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/LoginWithXbox",
            headers,
            jsonAsString,
            OnLoginWithXboxResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnLoginWithXboxResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        LoginResult outResult;
        if (ValidateResult(outResult, container))
        {            
            outResult.authenticationContext = std::make_shared<PlayFabAuthenticationContext>();
            if (outResult.EntityToken.notNull())
            {
                outResult.authenticationContext->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);
                context->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);
            }
            else
            {
                if (container.errorCallback != nullptr)
                {
                     PlayFabError error;
                     error.ErrorCode = PlayFabErrorCode::PlayFabErrorEntityTokenMissing;
                     error.ErrorMessage = "The Login Attempt returned a null EntityToken. This was a mistake. Please try the login again in a moment.";
                     container.errorCallback(error, container.GetCustomData());
                     return;
                }
            }

            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::Matchmake(
        MatchmakeRequest& request,
        const ProcessApiCallback<MatchmakeResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/Matchmake",
            headers,
            jsonAsString,
            OnMatchmakeResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<MatchmakeResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnMatchmakeResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        MatchmakeResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<MatchmakeResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::OpenTrade(
        OpenTradeRequest& request,
        const ProcessApiCallback<OpenTradeResponse> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/OpenTrade",
            headers,
            jsonAsString,
            OnOpenTradeResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<OpenTradeResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnOpenTradeResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        OpenTradeResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<OpenTradeResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::PayForPurchase(
        PayForPurchaseRequest& request,
        const ProcessApiCallback<PayForPurchaseResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/PayForPurchase",
            headers,
            jsonAsString,
            OnPayForPurchaseResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<PayForPurchaseResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnPayForPurchaseResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        PayForPurchaseResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<PayForPurchaseResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::PurchaseItem(
        PurchaseItemRequest& request,
        const ProcessApiCallback<PurchaseItemResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/PurchaseItem",
            headers,
            jsonAsString,
            OnPurchaseItemResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<PurchaseItemResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnPurchaseItemResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        PurchaseItemResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<PurchaseItemResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::RedeemCoupon(
        RedeemCouponRequest& request,
        const ProcessApiCallback<RedeemCouponResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/RedeemCoupon",
            headers,
            jsonAsString,
            OnRedeemCouponResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RedeemCouponResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnRedeemCouponResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        RedeemCouponResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<RedeemCouponResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::RefreshPSNAuthToken(
        RefreshPSNAuthTokenRequest& request,
        const ProcessApiCallback<EmptyResponse> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/RefreshPSNAuthToken",
            headers,
            jsonAsString,
            OnRefreshPSNAuthTokenResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnRefreshPSNAuthTokenResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        EmptyResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<EmptyResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::RegisterForIOSPushNotification(
        RegisterForIOSPushNotificationRequest& request,
        const ProcessApiCallback<RegisterForIOSPushNotificationResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/RegisterForIOSPushNotification",
            headers,
            jsonAsString,
            OnRegisterForIOSPushNotificationResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RegisterForIOSPushNotificationResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnRegisterForIOSPushNotificationResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        RegisterForIOSPushNotificationResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<RegisterForIOSPushNotificationResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::RegisterPlayFabUser(
        RegisterPlayFabUserRequest& request,
        const ProcessApiCallback<RegisterPlayFabUserResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = PlayFabSettings::staticSettings;
        if (request.TitleId.empty())
        {
                if (!settings->titleId.empty())
                {
                        request.TitleId = settings->titleId;
                }
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/RegisterPlayFabUser",
            headers,
            jsonAsString,
            OnRegisterPlayFabUserResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RegisterPlayFabUserResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnRegisterPlayFabUserResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        RegisterPlayFabUserResult outResult;
        if (ValidateResult(outResult, container))
        {            context->HandlePlayFabLogin(outResult.PlayFabId, outResult.SessionTicket, outResult.EntityToken->Entity->Id, outResult.EntityToken->Entity->Type, outResult.EntityToken->EntityToken);

            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<RegisterPlayFabUserResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::RemoveContactEmail(
        RemoveContactEmailRequest& request,
        const ProcessApiCallback<RemoveContactEmailResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/RemoveContactEmail",
            headers,
            jsonAsString,
            OnRemoveContactEmailResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RemoveContactEmailResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnRemoveContactEmailResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        RemoveContactEmailResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<RemoveContactEmailResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::RemoveFriend(
        RemoveFriendRequest& request,
        const ProcessApiCallback<RemoveFriendResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/RemoveFriend",
            headers,
            jsonAsString,
            OnRemoveFriendResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RemoveFriendResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnRemoveFriendResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        RemoveFriendResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<RemoveFriendResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::RemoveGenericID(
        RemoveGenericIDRequest& request,
        const ProcessApiCallback<RemoveGenericIDResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/RemoveGenericID",
            headers,
            jsonAsString,
            OnRemoveGenericIDResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RemoveGenericIDResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnRemoveGenericIDResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        RemoveGenericIDResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<RemoveGenericIDResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::RemoveSharedGroupMembers(
        RemoveSharedGroupMembersRequest& request,
        const ProcessApiCallback<RemoveSharedGroupMembersResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/RemoveSharedGroupMembers",
            headers,
            jsonAsString,
            OnRemoveSharedGroupMembersResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RemoveSharedGroupMembersResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnRemoveSharedGroupMembersResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        RemoveSharedGroupMembersResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<RemoveSharedGroupMembersResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::ReportAdActivity(
        ReportAdActivityRequest& request,
        const ProcessApiCallback<ReportAdActivityResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/ReportAdActivity",
            headers,
            jsonAsString,
            OnReportAdActivityResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ReportAdActivityResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnReportAdActivityResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        ReportAdActivityResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<ReportAdActivityResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::ReportDeviceInfo(
        DeviceInfoRequest& request,
        const ProcessApiCallback<EmptyResponse> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/ReportDeviceInfo",
            headers,
            jsonAsString,
            OnReportDeviceInfoResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnReportDeviceInfoResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        EmptyResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<EmptyResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::ReportPlayer(
        ReportPlayerClientRequest& request,
        const ProcessApiCallback<ReportPlayerClientResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/ReportPlayer",
            headers,
            jsonAsString,
            OnReportPlayerResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ReportPlayerClientResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnReportPlayerResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        ReportPlayerClientResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<ReportPlayerClientResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::RestoreIOSPurchases(
        RestoreIOSPurchasesRequest& request,
        const ProcessApiCallback<RestoreIOSPurchasesResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/RestoreIOSPurchases",
            headers,
            jsonAsString,
            OnRestoreIOSPurchasesResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RestoreIOSPurchasesResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnRestoreIOSPurchasesResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        RestoreIOSPurchasesResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<RestoreIOSPurchasesResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::RewardAdActivity(
        RewardAdActivityRequest& request,
        const ProcessApiCallback<RewardAdActivityResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/RewardAdActivity",
            headers,
            jsonAsString,
            OnRewardAdActivityResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RewardAdActivityResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnRewardAdActivityResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        RewardAdActivityResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<RewardAdActivityResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::SendAccountRecoveryEmail(
        SendAccountRecoveryEmailRequest& request,
        const ProcessApiCallback<SendAccountRecoveryEmailResult> callback,
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

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/SendAccountRecoveryEmail",
            headers,
            jsonAsString,
            OnSendAccountRecoveryEmailResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SendAccountRecoveryEmailResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnSendAccountRecoveryEmailResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        SendAccountRecoveryEmailResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<SendAccountRecoveryEmailResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::SetFriendTags(
        SetFriendTagsRequest& request,
        const ProcessApiCallback<SetFriendTagsResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/SetFriendTags",
            headers,
            jsonAsString,
            OnSetFriendTagsResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SetFriendTagsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnSetFriendTagsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        SetFriendTagsResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<SetFriendTagsResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::SetPlayerSecret(
        SetPlayerSecretRequest& request,
        const ProcessApiCallback<SetPlayerSecretResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/SetPlayerSecret",
            headers,
            jsonAsString,
            OnSetPlayerSecretResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SetPlayerSecretResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnSetPlayerSecretResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        SetPlayerSecretResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<SetPlayerSecretResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::StartPurchase(
        StartPurchaseRequest& request,
        const ProcessApiCallback<StartPurchaseResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/StartPurchase",
            headers,
            jsonAsString,
            OnStartPurchaseResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<StartPurchaseResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnStartPurchaseResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        StartPurchaseResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<StartPurchaseResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::SubtractUserVirtualCurrency(
        SubtractUserVirtualCurrencyRequest& request,
        const ProcessApiCallback<ModifyUserVirtualCurrencyResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/SubtractUserVirtualCurrency",
            headers,
            jsonAsString,
            OnSubtractUserVirtualCurrencyResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ModifyUserVirtualCurrencyResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnSubtractUserVirtualCurrencyResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        ModifyUserVirtualCurrencyResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<ModifyUserVirtualCurrencyResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::UnlinkAndroidDeviceID(
        UnlinkAndroidDeviceIDRequest& request,
        const ProcessApiCallback<UnlinkAndroidDeviceIDResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/UnlinkAndroidDeviceID",
            headers,
            jsonAsString,
            OnUnlinkAndroidDeviceIDResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkAndroidDeviceIDResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnUnlinkAndroidDeviceIDResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        UnlinkAndroidDeviceIDResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<UnlinkAndroidDeviceIDResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::UnlinkApple(
        UnlinkAppleRequest& request,
        const ProcessApiCallback<EmptyResponse> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/UnlinkApple",
            headers,
            jsonAsString,
            OnUnlinkAppleResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnUnlinkAppleResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        EmptyResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<EmptyResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::UnlinkCustomID(
        UnlinkCustomIDRequest& request,
        const ProcessApiCallback<UnlinkCustomIDResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/UnlinkCustomID",
            headers,
            jsonAsString,
            OnUnlinkCustomIDResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkCustomIDResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnUnlinkCustomIDResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        UnlinkCustomIDResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<UnlinkCustomIDResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::UnlinkFacebookAccount(
        UnlinkFacebookAccountRequest& request,
        const ProcessApiCallback<UnlinkFacebookAccountResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/UnlinkFacebookAccount",
            headers,
            jsonAsString,
            OnUnlinkFacebookAccountResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkFacebookAccountResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnUnlinkFacebookAccountResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        UnlinkFacebookAccountResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<UnlinkFacebookAccountResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::UnlinkFacebookInstantGamesId(
        UnlinkFacebookInstantGamesIdRequest& request,
        const ProcessApiCallback<UnlinkFacebookInstantGamesIdResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/UnlinkFacebookInstantGamesId",
            headers,
            jsonAsString,
            OnUnlinkFacebookInstantGamesIdResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkFacebookInstantGamesIdResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnUnlinkFacebookInstantGamesIdResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        UnlinkFacebookInstantGamesIdResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<UnlinkFacebookInstantGamesIdResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::UnlinkGameCenterAccount(
        UnlinkGameCenterAccountRequest& request,
        const ProcessApiCallback<UnlinkGameCenterAccountResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/UnlinkGameCenterAccount",
            headers,
            jsonAsString,
            OnUnlinkGameCenterAccountResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkGameCenterAccountResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnUnlinkGameCenterAccountResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        UnlinkGameCenterAccountResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<UnlinkGameCenterAccountResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::UnlinkGoogleAccount(
        UnlinkGoogleAccountRequest& request,
        const ProcessApiCallback<UnlinkGoogleAccountResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/UnlinkGoogleAccount",
            headers,
            jsonAsString,
            OnUnlinkGoogleAccountResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkGoogleAccountResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnUnlinkGoogleAccountResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        UnlinkGoogleAccountResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<UnlinkGoogleAccountResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::UnlinkIOSDeviceID(
        UnlinkIOSDeviceIDRequest& request,
        const ProcessApiCallback<UnlinkIOSDeviceIDResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/UnlinkIOSDeviceID",
            headers,
            jsonAsString,
            OnUnlinkIOSDeviceIDResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkIOSDeviceIDResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnUnlinkIOSDeviceIDResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        UnlinkIOSDeviceIDResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<UnlinkIOSDeviceIDResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::UnlinkKongregate(
        UnlinkKongregateAccountRequest& request,
        const ProcessApiCallback<UnlinkKongregateAccountResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/UnlinkKongregate",
            headers,
            jsonAsString,
            OnUnlinkKongregateResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkKongregateAccountResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnUnlinkKongregateResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        UnlinkKongregateAccountResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<UnlinkKongregateAccountResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::UnlinkNintendoServiceAccount(
        UnlinkNintendoServiceAccountRequest& request,
        const ProcessApiCallback<EmptyResponse> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/UnlinkNintendoServiceAccount",
            headers,
            jsonAsString,
            OnUnlinkNintendoServiceAccountResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnUnlinkNintendoServiceAccountResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        EmptyResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<EmptyResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::UnlinkNintendoSwitchDeviceId(
        UnlinkNintendoSwitchDeviceIdRequest& request,
        const ProcessApiCallback<UnlinkNintendoSwitchDeviceIdResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/UnlinkNintendoSwitchDeviceId",
            headers,
            jsonAsString,
            OnUnlinkNintendoSwitchDeviceIdResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkNintendoSwitchDeviceIdResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnUnlinkNintendoSwitchDeviceIdResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        UnlinkNintendoSwitchDeviceIdResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<UnlinkNintendoSwitchDeviceIdResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::UnlinkOpenIdConnect(
        UnlinkOpenIdConnectRequest& request,
        const ProcessApiCallback<EmptyResponse> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/UnlinkOpenIdConnect",
            headers,
            jsonAsString,
            OnUnlinkOpenIdConnectResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnUnlinkOpenIdConnectResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        EmptyResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<EmptyResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::UnlinkPSNAccount(
        UnlinkPSNAccountRequest& request,
        const ProcessApiCallback<UnlinkPSNAccountResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/UnlinkPSNAccount",
            headers,
            jsonAsString,
            OnUnlinkPSNAccountResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkPSNAccountResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnUnlinkPSNAccountResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        UnlinkPSNAccountResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<UnlinkPSNAccountResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::UnlinkSteamAccount(
        UnlinkSteamAccountRequest& request,
        const ProcessApiCallback<UnlinkSteamAccountResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/UnlinkSteamAccount",
            headers,
            jsonAsString,
            OnUnlinkSteamAccountResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkSteamAccountResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnUnlinkSteamAccountResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        UnlinkSteamAccountResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<UnlinkSteamAccountResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::UnlinkTwitch(
        UnlinkTwitchAccountRequest& request,
        const ProcessApiCallback<UnlinkTwitchAccountResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/UnlinkTwitch",
            headers,
            jsonAsString,
            OnUnlinkTwitchResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkTwitchAccountResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnUnlinkTwitchResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        UnlinkTwitchAccountResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<UnlinkTwitchAccountResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::UnlinkXboxAccount(
        UnlinkXboxAccountRequest& request,
        const ProcessApiCallback<UnlinkXboxAccountResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/UnlinkXboxAccount",
            headers,
            jsonAsString,
            OnUnlinkXboxAccountResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkXboxAccountResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnUnlinkXboxAccountResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        UnlinkXboxAccountResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<UnlinkXboxAccountResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::UnlockContainerInstance(
        UnlockContainerInstanceRequest& request,
        const ProcessApiCallback<UnlockContainerItemResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/UnlockContainerInstance",
            headers,
            jsonAsString,
            OnUnlockContainerInstanceResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlockContainerItemResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnUnlockContainerInstanceResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        UnlockContainerItemResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<UnlockContainerItemResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::UnlockContainerItem(
        UnlockContainerItemRequest& request,
        const ProcessApiCallback<UnlockContainerItemResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/UnlockContainerItem",
            headers,
            jsonAsString,
            OnUnlockContainerItemResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlockContainerItemResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnUnlockContainerItemResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        UnlockContainerItemResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<UnlockContainerItemResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::UpdateAvatarUrl(
        UpdateAvatarUrlRequest& request,
        const ProcessApiCallback<EmptyResponse> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/UpdateAvatarUrl",
            headers,
            jsonAsString,
            OnUpdateAvatarUrlResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnUpdateAvatarUrlResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        EmptyResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<EmptyResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::UpdateCharacterData(
        UpdateCharacterDataRequest& request,
        const ProcessApiCallback<UpdateCharacterDataResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/UpdateCharacterData",
            headers,
            jsonAsString,
            OnUpdateCharacterDataResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateCharacterDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnUpdateCharacterDataResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        UpdateCharacterDataResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<UpdateCharacterDataResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::UpdateCharacterStatistics(
        UpdateCharacterStatisticsRequest& request,
        const ProcessApiCallback<UpdateCharacterStatisticsResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/UpdateCharacterStatistics",
            headers,
            jsonAsString,
            OnUpdateCharacterStatisticsResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateCharacterStatisticsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnUpdateCharacterStatisticsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        UpdateCharacterStatisticsResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<UpdateCharacterStatisticsResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::UpdatePlayerStatistics(
        UpdatePlayerStatisticsRequest& request,
        const ProcessApiCallback<UpdatePlayerStatisticsResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/UpdatePlayerStatistics",
            headers,
            jsonAsString,
            OnUpdatePlayerStatisticsResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdatePlayerStatisticsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnUpdatePlayerStatisticsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        UpdatePlayerStatisticsResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<UpdatePlayerStatisticsResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::UpdateSharedGroupData(
        UpdateSharedGroupDataRequest& request,
        const ProcessApiCallback<UpdateSharedGroupDataResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/UpdateSharedGroupData",
            headers,
            jsonAsString,
            OnUpdateSharedGroupDataResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateSharedGroupDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnUpdateSharedGroupDataResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        UpdateSharedGroupDataResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<UpdateSharedGroupDataResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::UpdateUserData(
        UpdateUserDataRequest& request,
        const ProcessApiCallback<UpdateUserDataResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/UpdateUserData",
            headers,
            jsonAsString,
            OnUpdateUserDataResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnUpdateUserDataResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        UpdateUserDataResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<UpdateUserDataResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::UpdateUserPublisherData(
        UpdateUserDataRequest& request,
        const ProcessApiCallback<UpdateUserDataResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/UpdateUserPublisherData",
            headers,
            jsonAsString,
            OnUpdateUserPublisherDataResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnUpdateUserPublisherDataResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        UpdateUserDataResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<UpdateUserDataResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::UpdateUserTitleDisplayName(
        UpdateUserTitleDisplayNameRequest& request,
        const ProcessApiCallback<UpdateUserTitleDisplayNameResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/UpdateUserTitleDisplayName",
            headers,
            jsonAsString,
            OnUpdateUserTitleDisplayNameResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserTitleDisplayNameResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnUpdateUserTitleDisplayNameResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        UpdateUserTitleDisplayNameResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<UpdateUserTitleDisplayNameResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::ValidateAmazonIAPReceipt(
        ValidateAmazonReceiptRequest& request,
        const ProcessApiCallback<ValidateAmazonReceiptResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/ValidateAmazonIAPReceipt",
            headers,
            jsonAsString,
            OnValidateAmazonIAPReceiptResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ValidateAmazonReceiptResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnValidateAmazonIAPReceiptResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        ValidateAmazonReceiptResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<ValidateAmazonReceiptResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::ValidateGooglePlayPurchase(
        ValidateGooglePlayPurchaseRequest& request,
        const ProcessApiCallback<ValidateGooglePlayPurchaseResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/ValidateGooglePlayPurchase",
            headers,
            jsonAsString,
            OnValidateGooglePlayPurchaseResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ValidateGooglePlayPurchaseResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnValidateGooglePlayPurchaseResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        ValidateGooglePlayPurchaseResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<ValidateGooglePlayPurchaseResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::ValidateIOSReceipt(
        ValidateIOSReceiptRequest& request,
        const ProcessApiCallback<ValidateIOSReceiptResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/ValidateIOSReceipt",
            headers,
            jsonAsString,
            OnValidateIOSReceiptResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ValidateIOSReceiptResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnValidateIOSReceiptResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        ValidateIOSReceiptResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<ValidateIOSReceiptResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::ValidateWindowsStoreReceipt(
        ValidateWindowsReceiptRequest& request,
        const ProcessApiCallback<ValidateWindowsReceiptResult> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/ValidateWindowsStoreReceipt",
            headers,
            jsonAsString,
            OnValidateWindowsStoreReceiptResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ValidateWindowsReceiptResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnValidateWindowsStoreReceiptResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        ValidateWindowsReceiptResult outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<ValidateWindowsReceiptResult> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::WriteCharacterEvent(
        WriteClientCharacterEventRequest& request,
        const ProcessApiCallback<WriteEventResponse> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/WriteCharacterEvent",
            headers,
            jsonAsString,
            OnWriteCharacterEventResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<WriteEventResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnWriteCharacterEventResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        WriteEventResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<WriteEventResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::WritePlayerEvent(
        WriteClientPlayerEventRequest& request,
        const ProcessApiCallback<WriteEventResponse> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/WritePlayerEvent",
            headers,
            jsonAsString,
            OnWritePlayerEventResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<WriteEventResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnWritePlayerEventResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        WriteEventResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<WriteEventResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabClientAPI::WriteTitleEvent(
        WriteTitleEventRequest& request,
        const ProcessApiCallback<WriteEventResponse> callback,
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
        headers.emplace("X-Authorization", context->clientSessionTicket);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Client/WriteTitleEvent",
            headers,
            jsonAsString,
            OnWriteTitleEventResult,
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<WriteEventResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabClientAPI::OnWriteTitleEventResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        WriteEventResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = (*static_cast<ProcessApiCallback<WriteEventResponse> *>(internalPtr.get()));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    // Private PlayFabClientAPI specific
    bool PlayFabClientAPI::IsClientLoggedIn()
    {
        return !PlayFabSettings::staticPlayer->clientSessionTicket.empty();
    }


    bool PlayFabClientAPI::ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container)
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

#endif // #if !defined(DISABLE_PLAYFABCLIENT_API)

#if defined(PLAYFAB_PLATFORM_WINDOWS)
#pragma warning (default: 4100) // formal parameters are part of a public interface
#endif // defined(PLAYFAB_PLATFORM_WINDOWS)
