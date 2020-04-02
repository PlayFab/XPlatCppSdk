#include <stdafx.h>

#if !defined(DISABLE_PLAYFABENTITY_API)

#include <playfab/PlayFabInsightsInstanceApi.h>
#include <playfab/PlayFabPluginManager.h>
#include <playfab/PlayFabSettings.h>

#if defined(PLAYFAB_PLATFORM_WINDOWS)
#pragma warning (disable: 4100) // formal parameters are part of a public interface
#endif // defined(PLAYFAB_PLATFORM_WINDOWS)

namespace PlayFab
{
    using namespace InsightsModels;

    PlayFabInsightsInstanceAPI::PlayFabInsightsInstanceAPI(const std::shared_ptr<PlayFabAuthenticationContext>& authenticationContext)
    {
        if (authenticationContext == nullptr)
        {
            throw PlayFabException(PlayFabExceptionCode::AuthContextRequired, "Context cannot be null, create a PlayFabAuthenticationContext for each player in advance, or get <PlayFabClientInstanceAPI>.authenticationContext");
        }
        this->m_context = authenticationContext;
    }

    PlayFabInsightsInstanceAPI::PlayFabInsightsInstanceAPI(const std::shared_ptr<PlayFabApiSettings>& apiSettings, const std::shared_ptr<PlayFabAuthenticationContext>& authenticationContext)
    {
        if (authenticationContext == nullptr)
        {
            throw PlayFabException(PlayFabExceptionCode::AuthContextRequired, "Context cannot be null, create a PlayFabAuthenticationContext for each player in advance, or get <PlayFabClientInstanceAPI>.authenticationContext");
        }
        this->m_settings = apiSettings;
        this->m_context = authenticationContext;
    }

    std::shared_ptr<PlayFabApiSettings> PlayFabInsightsInstanceAPI::GetSettings() const
    {
        return this->m_settings;
    }

    std::shared_ptr<PlayFabAuthenticationContext> PlayFabInsightsInstanceAPI::GetAuthenticationContext() const
    {
        return this->m_context;
    }

    size_t PlayFabInsightsInstanceAPI::Update()
    {
        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        return http.Update();
    }

    void PlayFabInsightsInstanceAPI::ForgetAllCredentials()
    {
        if (this->m_context != nullptr)
        {
            this->m_context->ForgetAllCredentials();
        }
    }

    // PlayFabInsights instance APIs

    void PlayFabInsightsInstanceAPI::GetDetails(
        InsightsEmptyRequest& request,
        const ProcessApiCallback<InsightsGetDetailsResponse> callback,
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
            "/Insights/GetDetails",
            headers,
            jsonAsString,
            std::bind(&PlayFabInsightsInstanceAPI::OnGetDetailsResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<InsightsGetDetailsResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabInsightsInstanceAPI::OnGetDetailsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        InsightsGetDetailsResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<InsightsGetDetailsResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabInsightsInstanceAPI::GetLimits(
        InsightsEmptyRequest& request,
        const ProcessApiCallback<InsightsGetLimitsResponse> callback,
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
            "/Insights/GetLimits",
            headers,
            jsonAsString,
            std::bind(&PlayFabInsightsInstanceAPI::OnGetLimitsResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<InsightsGetLimitsResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabInsightsInstanceAPI::OnGetLimitsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        InsightsGetLimitsResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<InsightsGetLimitsResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabInsightsInstanceAPI::GetOperationStatus(
        InsightsGetOperationStatusRequest& request,
        const ProcessApiCallback<InsightsGetOperationStatusResponse> callback,
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
            "/Insights/GetOperationStatus",
            headers,
            jsonAsString,
            std::bind(&PlayFabInsightsInstanceAPI::OnGetOperationStatusResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<InsightsGetOperationStatusResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabInsightsInstanceAPI::OnGetOperationStatusResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        InsightsGetOperationStatusResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<InsightsGetOperationStatusResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabInsightsInstanceAPI::GetPendingOperations(
        InsightsGetPendingOperationsRequest& request,
        const ProcessApiCallback<InsightsGetPendingOperationsResponse> callback,
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
            "/Insights/GetPendingOperations",
            headers,
            jsonAsString,
            std::bind(&PlayFabInsightsInstanceAPI::OnGetPendingOperationsResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<InsightsGetPendingOperationsResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabInsightsInstanceAPI::OnGetPendingOperationsResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        InsightsGetPendingOperationsResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<InsightsGetPendingOperationsResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabInsightsInstanceAPI::SetPerformance(
        InsightsSetPerformanceRequest& request,
        const ProcessApiCallback<InsightsOperationResponse> callback,
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
            "/Insights/SetPerformance",
            headers,
            jsonAsString,
            std::bind(&PlayFabInsightsInstanceAPI::OnSetPerformanceResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<InsightsOperationResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabInsightsInstanceAPI::OnSetPerformanceResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        InsightsOperationResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<InsightsOperationResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabInsightsInstanceAPI::SetStorageRetention(
        InsightsSetStorageRetentionRequest& request,
        const ProcessApiCallback<InsightsOperationResponse> callback,
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
            "/Insights/SetStorageRetention",
            headers,
            jsonAsString,
            std::bind(&PlayFabInsightsInstanceAPI::OnSetStorageRetentionResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            settings,
            context,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<InsightsOperationResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
    }

    void PlayFabInsightsInstanceAPI::OnSetStorageRetentionResult(int /*httpCode*/, const std::string& /*result*/, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        InsightsOperationResponse outResult;
        if (ValidateResult(outResult, container))
        {
            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<InsightsOperationResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    bool PlayFabInsightsInstanceAPI::ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container)
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
