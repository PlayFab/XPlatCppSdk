#include <stdafx.h>

#if !defined(DISABLE_PLAYFABENTITY_API)

#include <playfab/PlayFabEconomyInstanceApi.h>
#include <playfab/PlayFabPluginManager.h>
#include <playfab/PlayFabSettings.h>

#if defined(PLAYFAB_PLATFORM_WINDOWS)
#pragma warning (disable: 4100) // formal parameters are part of a public interface
#endif // defined(PLAYFAB_PLATFORM_WINDOWS)

namespace PlayFab
{
    using namespace EconomyModels;

    PlayFabEconomyInstanceAPI::PlayFabEconomyInstanceAPI(const std::shared_ptr<PlayFabAuthenticationContext>& authenticationContext)
    {
        if (authenticationContext == nullptr)
        {
            throw PlayFabException(PlayFabExceptionCode::AuthContextRequired, "Context cannot be null, create a PlayFabAuthenticationContext for each player in advance, or get <PlayFabClientInstanceAPI>.authenticationContext");
        }
        this->m_context = authenticationContext;
    }

    PlayFabEconomyInstanceAPI::PlayFabEconomyInstanceAPI(const std::shared_ptr<PlayFabApiSettings>& apiSettings, const std::shared_ptr<PlayFabAuthenticationContext>& authenticationContext)
    {
        if (authenticationContext == nullptr)
        {
            throw PlayFabException(PlayFabExceptionCode::AuthContextRequired, "Context cannot be null, create a PlayFabAuthenticationContext for each player in advance, or get <PlayFabClientInstanceAPI>.authenticationContext");
        }
        this->m_settings = apiSettings;
        this->m_context = authenticationContext;
    }

    std::shared_ptr<PlayFabApiSettings> PlayFabEconomyInstanceAPI::GetSettings() const
    {
        return this->m_settings;
    }

    std::shared_ptr<PlayFabAuthenticationContext> PlayFabEconomyInstanceAPI::GetAuthenticationContext() const
    {
        return this->m_context;
    }

    size_t PlayFabEconomyInstanceAPI::Update()
    {
        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        return http.Update();
    }

    void PlayFabEconomyInstanceAPI::ForgetAllCredentials()
    {
        if (this->m_context != nullptr)
        {
            this->m_context->ForgetAllCredentials();
        }
    }

    // PlayFabEconomy instance APIs

    void PlayFabEconomyInstanceAPI::AddInventoryItems(
        AddInventoryItemsRequest& request,
        const ProcessApiCallback<AddInventoryItemsResponse> callback,
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
            "/Inventory/AddInventoryItems",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnAddInventoryItemsResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<AddInventoryItemsResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnAddInventoryItemsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        AddInventoryItemsResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<AddInventoryItemsResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::CreateDraftItem(
        CreateDraftItemRequest& request,
        const ProcessApiCallback<CreateDraftItemResponse> callback,
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
            "/Catalog/CreateDraftItem",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnCreateDraftItemResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<CreateDraftItemResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnCreateDraftItemResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        CreateDraftItemResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<CreateDraftItemResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::CreateUploadUrls(
        CreateUploadUrlsRequest& request,
        const ProcessApiCallback<CreateUploadUrlsResponse> callback,
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
            "/Catalog/CreateUploadUrls",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnCreateUploadUrlsResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<CreateUploadUrlsResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnCreateUploadUrlsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        CreateUploadUrlsResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<CreateUploadUrlsResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::DeleteEntityItemReviews(
        DeleteEntityItemReviewsRequest& request,
        const ProcessApiCallback<DeleteEntityItemReviewsResponse> callback,
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
            "/Catalog/DeleteEntityItemReviews",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnDeleteEntityItemReviewsResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<DeleteEntityItemReviewsResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnDeleteEntityItemReviewsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        DeleteEntityItemReviewsResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<DeleteEntityItemReviewsResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::DeleteInventoryCollection(
        DeleteInventoryCollectionRequest& request,
        const ProcessApiCallback<DeleteInventoryCollectionResponse> callback,
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
            "/Inventory/DeleteInventoryCollection",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnDeleteInventoryCollectionResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<DeleteInventoryCollectionResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnDeleteInventoryCollectionResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        DeleteInventoryCollectionResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<DeleteInventoryCollectionResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::DeleteInventoryItems(
        DeleteInventoryItemsRequest& request,
        const ProcessApiCallback<DeleteInventoryItemsResponse> callback,
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
            "/Inventory/DeleteInventoryItems",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnDeleteInventoryItemsResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<DeleteInventoryItemsResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnDeleteInventoryItemsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        DeleteInventoryItemsResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<DeleteInventoryItemsResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::DeleteItem(
        DeleteItemRequest& request,
        const ProcessApiCallback<DeleteItemResponse> callback,
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
            "/Catalog/DeleteItem",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnDeleteItemResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<DeleteItemResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnDeleteItemResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        DeleteItemResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<DeleteItemResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::ExecuteInventoryOperations(
        ExecuteInventoryOperationsRequest& request,
        const ProcessApiCallback<ExecuteInventoryOperationsResponse> callback,
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
            "/Inventory/ExecuteInventoryOperations",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnExecuteInventoryOperationsResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ExecuteInventoryOperationsResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnExecuteInventoryOperationsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        ExecuteInventoryOperationsResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<ExecuteInventoryOperationsResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::GetCatalogConfig(
        GetCatalogConfigRequest& request,
        const ProcessApiCallback<GetCatalogConfigResponse> callback,
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
            "/Catalog/GetCatalogConfig",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnGetCatalogConfigResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCatalogConfigResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnGetCatalogConfigResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetCatalogConfigResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<GetCatalogConfigResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::GetDraftItem(
        GetDraftItemRequest& request,
        const ProcessApiCallback<GetDraftItemResponse> callback,
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
            "/Catalog/GetDraftItem",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnGetDraftItemResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetDraftItemResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnGetDraftItemResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetDraftItemResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<GetDraftItemResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::GetDraftItems(
        GetDraftItemsRequest& request,
        const ProcessApiCallback<GetDraftItemsResponse> callback,
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
            "/Catalog/GetDraftItems",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnGetDraftItemsResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetDraftItemsResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnGetDraftItemsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetDraftItemsResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<GetDraftItemsResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::GetEntityDraftItems(
        GetEntityDraftItemsRequest& request,
        const ProcessApiCallback<GetEntityDraftItemsResponse> callback,
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
            "/Catalog/GetEntityDraftItems",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnGetEntityDraftItemsResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetEntityDraftItemsResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnGetEntityDraftItemsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetEntityDraftItemsResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<GetEntityDraftItemsResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::GetEntityItemReview(
        GetEntityItemReviewRequest& request,
        const ProcessApiCallback<GetEntityItemReviewResponse> callback,
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
            "/Catalog/GetEntityItemReview",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnGetEntityItemReviewResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetEntityItemReviewResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnGetEntityItemReviewResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetEntityItemReviewResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<GetEntityItemReviewResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::GetInventoryCollectionIds(
        GetInventoryCollectionIdsRequest& request,
        const ProcessApiCallback<GetInventoryCollectionIdsResponse> callback,
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
            "/Inventory/GetInventoryCollectionIds",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnGetInventoryCollectionIdsResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetInventoryCollectionIdsResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnGetInventoryCollectionIdsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetInventoryCollectionIdsResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<GetInventoryCollectionIdsResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::GetInventoryItems(
        GetInventoryItemsRequest& request,
        const ProcessApiCallback<GetInventoryItemsResponse> callback,
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
            "/Inventory/GetInventoryItems",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnGetInventoryItemsResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetInventoryItemsResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnGetInventoryItemsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetInventoryItemsResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<GetInventoryItemsResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::GetItem(
        GetItemRequest& request,
        const ProcessApiCallback<GetItemResponse> callback,
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
            "/Catalog/GetItem",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnGetItemResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetItemResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnGetItemResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetItemResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<GetItemResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::GetItemContainers(
        GetItemContainersRequest& request,
        const ProcessApiCallback<GetItemContainersResponse> callback,
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
            "/Catalog/GetItemContainers",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnGetItemContainersResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetItemContainersResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnGetItemContainersResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetItemContainersResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<GetItemContainersResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::GetItemModerationState(
        GetItemModerationStateRequest& request,
        const ProcessApiCallback<GetItemModerationStateResponse> callback,
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
            "/Catalog/GetItemModerationState",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnGetItemModerationStateResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetItemModerationStateResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnGetItemModerationStateResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetItemModerationStateResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<GetItemModerationStateResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::GetItemPublishStatus(
        GetItemPublishStatusRequest& request,
        const ProcessApiCallback<GetItemPublishStatusResponse> callback,
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
            "/Catalog/GetItemPublishStatus",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnGetItemPublishStatusResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetItemPublishStatusResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnGetItemPublishStatusResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetItemPublishStatusResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<GetItemPublishStatusResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::GetItemReviews(
        GetItemReviewsRequest& request,
        const ProcessApiCallback<GetItemReviewsResponse> callback,
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
            "/Catalog/GetItemReviews",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnGetItemReviewsResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetItemReviewsResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnGetItemReviewsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetItemReviewsResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<GetItemReviewsResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::GetItemReviewSummary(
        GetItemReviewSummaryRequest& request,
        const ProcessApiCallback<GetItemReviewSummaryResponse> callback,
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
            "/Catalog/GetItemReviewSummary",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnGetItemReviewSummaryResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetItemReviewSummaryResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnGetItemReviewSummaryResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetItemReviewSummaryResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<GetItemReviewSummaryResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::GetItems(
        GetItemsRequest& request,
        const ProcessApiCallback<GetItemsResponse> callback,
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
            "/Catalog/GetItems",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnGetItemsResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetItemsResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnGetItemsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetItemsResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<GetItemsResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::GetMicrosoftStoreAccessTokens(
        GetMicrosoftStoreAccessTokensRequest& request,
        const ProcessApiCallback<GetMicrosoftStoreAccessTokensResponse> callback,
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
            "/Inventory/GetMicrosoftStoreAccessTokens",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnGetMicrosoftStoreAccessTokensResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetMicrosoftStoreAccessTokensResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnGetMicrosoftStoreAccessTokensResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetMicrosoftStoreAccessTokensResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<GetMicrosoftStoreAccessTokensResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::GetTransactionHistory(
        GetTransactionHistoryRequest& request,
        const ProcessApiCallback<GetTransactionHistoryResponse> callback,
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
            "/Inventory/GetTransactionHistory",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnGetTransactionHistoryResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetTransactionHistoryResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnGetTransactionHistoryResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetTransactionHistoryResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<GetTransactionHistoryResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::PublishDraftItem(
        PublishDraftItemRequest& request,
        const ProcessApiCallback<PublishDraftItemResponse> callback,
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
            "/Catalog/PublishDraftItem",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnPublishDraftItemResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<PublishDraftItemResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnPublishDraftItemResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        PublishDraftItemResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<PublishDraftItemResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::PurchaseInventoryItems(
        PurchaseInventoryItemsRequest& request,
        const ProcessApiCallback<PurchaseInventoryItemsResponse> callback,
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
            "/Inventory/PurchaseInventoryItems",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnPurchaseInventoryItemsResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<PurchaseInventoryItemsResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnPurchaseInventoryItemsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        PurchaseInventoryItemsResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<PurchaseInventoryItemsResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::RedeemAppleAppStoreInventoryItems(
        RedeemAppleAppStoreInventoryItemsRequest& request,
        const ProcessApiCallback<RedeemAppleAppStoreInventoryItemsResponse> callback,
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
            "/Inventory/RedeemAppleAppStoreInventoryItems",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnRedeemAppleAppStoreInventoryItemsResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RedeemAppleAppStoreInventoryItemsResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnRedeemAppleAppStoreInventoryItemsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        RedeemAppleAppStoreInventoryItemsResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<RedeemAppleAppStoreInventoryItemsResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::RedeemGooglePlayInventoryItems(
        RedeemGooglePlayInventoryItemsRequest& request,
        const ProcessApiCallback<RedeemGooglePlayInventoryItemsResponse> callback,
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
            "/Inventory/RedeemGooglePlayInventoryItems",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnRedeemGooglePlayInventoryItemsResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RedeemGooglePlayInventoryItemsResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnRedeemGooglePlayInventoryItemsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        RedeemGooglePlayInventoryItemsResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<RedeemGooglePlayInventoryItemsResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::RedeemMicrosoftStoreInventoryItems(
        RedeemMicrosoftStoreInventoryItemsRequest& request,
        const ProcessApiCallback<RedeemMicrosoftStoreInventoryItemsResponse> callback,
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
            "/Inventory/RedeemMicrosoftStoreInventoryItems",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnRedeemMicrosoftStoreInventoryItemsResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RedeemMicrosoftStoreInventoryItemsResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnRedeemMicrosoftStoreInventoryItemsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        RedeemMicrosoftStoreInventoryItemsResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<RedeemMicrosoftStoreInventoryItemsResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::RedeemNintendoEShopInventoryItems(
        RedeemNintendoEShopInventoryItemsRequest& request,
        const ProcessApiCallback<RedeemNintendoEShopInventoryItemsResponse> callback,
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
            "/Inventory/RedeemNintendoEShopInventoryItems",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnRedeemNintendoEShopInventoryItemsResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RedeemNintendoEShopInventoryItemsResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnRedeemNintendoEShopInventoryItemsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        RedeemNintendoEShopInventoryItemsResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<RedeemNintendoEShopInventoryItemsResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::RedeemPlayStationStoreInventoryItems(
        RedeemPlayStationStoreInventoryItemsRequest& request,
        const ProcessApiCallback<RedeemPlayStationStoreInventoryItemsResponse> callback,
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
            "/Inventory/RedeemPlayStationStoreInventoryItems",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnRedeemPlayStationStoreInventoryItemsResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RedeemPlayStationStoreInventoryItemsResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnRedeemPlayStationStoreInventoryItemsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        RedeemPlayStationStoreInventoryItemsResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<RedeemPlayStationStoreInventoryItemsResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::RedeemSteamInventoryItems(
        RedeemSteamInventoryItemsRequest& request,
        const ProcessApiCallback<RedeemSteamInventoryItemsResponse> callback,
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
            "/Inventory/RedeemSteamInventoryItems",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnRedeemSteamInventoryItemsResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RedeemSteamInventoryItemsResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnRedeemSteamInventoryItemsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        RedeemSteamInventoryItemsResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<RedeemSteamInventoryItemsResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::ReportItem(
        ReportItemRequest& request,
        const ProcessApiCallback<ReportItemResponse> callback,
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
            "/Catalog/ReportItem",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnReportItemResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ReportItemResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnReportItemResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        ReportItemResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<ReportItemResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::ReportItemReview(
        ReportItemReviewRequest& request,
        const ProcessApiCallback<ReportItemReviewResponse> callback,
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
            "/Catalog/ReportItemReview",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnReportItemReviewResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ReportItemReviewResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnReportItemReviewResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        ReportItemReviewResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<ReportItemReviewResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::ReviewItem(
        ReviewItemRequest& request,
        const ProcessApiCallback<ReviewItemResponse> callback,
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
            "/Catalog/ReviewItem",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnReviewItemResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ReviewItemResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnReviewItemResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        ReviewItemResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<ReviewItemResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::SearchItems(
        SearchItemsRequest& request,
        const ProcessApiCallback<SearchItemsResponse> callback,
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
            "/Catalog/SearchItems",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnSearchItemsResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SearchItemsResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnSearchItemsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        SearchItemsResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<SearchItemsResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::SetItemModerationState(
        SetItemModerationStateRequest& request,
        const ProcessApiCallback<SetItemModerationStateResponse> callback,
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
            "/Catalog/SetItemModerationState",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnSetItemModerationStateResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SetItemModerationStateResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnSetItemModerationStateResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        SetItemModerationStateResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<SetItemModerationStateResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::SubmitItemReviewVote(
        SubmitItemReviewVoteRequest& request,
        const ProcessApiCallback<SubmitItemReviewVoteResponse> callback,
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
            "/Catalog/SubmitItemReviewVote",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnSubmitItemReviewVoteResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SubmitItemReviewVoteResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnSubmitItemReviewVoteResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        SubmitItemReviewVoteResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<SubmitItemReviewVoteResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::SubtractInventoryItems(
        SubtractInventoryItemsRequest& request,
        const ProcessApiCallback<SubtractInventoryItemsResponse> callback,
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
            "/Inventory/SubtractInventoryItems",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnSubtractInventoryItemsResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SubtractInventoryItemsResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnSubtractInventoryItemsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        SubtractInventoryItemsResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<SubtractInventoryItemsResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::TakedownItemReviews(
        TakedownItemReviewsRequest& request,
        const ProcessApiCallback<TakedownItemReviewsResponse> callback,
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
            "/Catalog/TakedownItemReviews",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnTakedownItemReviewsResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<TakedownItemReviewsResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnTakedownItemReviewsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        TakedownItemReviewsResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<TakedownItemReviewsResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::TransferInventoryItems(
        TransferInventoryItemsRequest& request,
        const ProcessApiCallback<TransferInventoryItemsResponse> callback,
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
            "/Inventory/TransferInventoryItems",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnTransferInventoryItemsResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<TransferInventoryItemsResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnTransferInventoryItemsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        TransferInventoryItemsResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<TransferInventoryItemsResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::UpdateCatalogConfig(
        UpdateCatalogConfigRequest& request,
        const ProcessApiCallback<UpdateCatalogConfigResponse> callback,
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
            "/Catalog/UpdateCatalogConfig",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnUpdateCatalogConfigResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateCatalogConfigResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnUpdateCatalogConfigResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        UpdateCatalogConfigResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<UpdateCatalogConfigResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::UpdateDraftItem(
        UpdateDraftItemRequest& request,
        const ProcessApiCallback<UpdateDraftItemResponse> callback,
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
            "/Catalog/UpdateDraftItem",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnUpdateDraftItemResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateDraftItemResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnUpdateDraftItemResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        UpdateDraftItemResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<UpdateDraftItemResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyInstanceAPI::UpdateInventoryItems(
        UpdateInventoryItemsRequest& request,
        const ProcessApiCallback<UpdateInventoryItemsResponse> callback,
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
            "/Inventory/UpdateInventoryItems",
            headers,
            jsonAsString,
            std::bind(&PlayFabEconomyInstanceAPI::OnUpdateInventoryItemsResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateInventoryItemsResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabEconomyInstanceAPI::OnUpdateInventoryItemsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        UpdateInventoryItemsResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<UpdateInventoryItemsResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    bool PlayFabEconomyInstanceAPI::ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container)
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
