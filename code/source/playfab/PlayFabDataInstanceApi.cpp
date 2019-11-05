#include <stdafx.h>

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabDataInstanceApi.h>
#include <playfab/PlayFabPluginManager.h>
#include <playfab/PlayFabSettings.h>
#include <playfab/PlayFabError.h>
#include <memory>

#if defined(PLAYFAB_PLATFORM_WINDOWS)
#pragma warning (disable: 4100) // formal parameters are part of a public interface
#endif // defined(PLAYFAB_PLATFORM_WINDOWS)

namespace PlayFab
{
    using namespace DataModels;

    PlayFabDataInstanceAPI::PlayFabDataInstanceAPI(std::shared_ptr<PlayFabAuthenticationContext> authenticationContext)
    {
        if (authenticationContext == nullptr)
            throw PlayFabException(PlayFabExceptionCode::AuthContextRequired, "Context cannot be null, create a PlayFabAuthenticationContext for each player in advance, or get <PlayFabClientInstanceAPI>.authenticationContext");
        this->m_authContext = std::move(authenticationContext);
    }

    PlayFabDataInstanceAPI::PlayFabDataInstanceAPI(std::shared_ptr<PlayFabApiSettings> apiSettings, std::shared_ptr<PlayFabAuthenticationContext> authenticationContext)
    {
        if (authenticationContext == nullptr)
            throw PlayFabException(PlayFabExceptionCode::AuthContextRequired, "Context cannot be null, create a PlayFabAuthenticationContext for each player in advance, or get <PlayFabClientInstanceAPI>.authenticationContext");
        this->m_settings = std::move(apiSettings);
        this->m_authContext = std::move(authenticationContext);
    }

    PlayFabDataInstanceAPI::~PlayFabDataInstanceAPI()
    {
    }

    std::shared_ptr<PlayFabApiSettings> PlayFabDataInstanceAPI::GetSettings() const
    {
        return this->m_settings;
    }

    void PlayFabDataInstanceAPI::SetSettings(std::shared_ptr<PlayFabApiSettings> apiSettings)
    {
        this->m_settings = std::move(apiSettings);
    }

    std::shared_ptr<PlayFabAuthenticationContext> PlayFabDataInstanceAPI::GetAuthenticationContext() const
    {
        return this->m_authContext;
    }

    void PlayFabDataInstanceAPI::SetAuthenticationContext(std::shared_ptr<PlayFabAuthenticationContext> authenticationContext)
    {
        this->m_authContext = std::move(authenticationContext);
    }

    size_t PlayFabDataInstanceAPI::Update()
    {
        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        return http.Update();
    }

    void PlayFabDataInstanceAPI::ForgetAllCredentials()
    {
        if (this->m_authContext == nullptr)
            return;

        this->m_authContext->ForgetAllCredentials();
    }

    // PlayFabData instance APIs

    void PlayFabDataInstanceAPI::AbortFileUploads(
        AbortFileUploadsRequest& request,
        const ProcessApiCallback<AbortFileUploadsResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : this->m_authContext != nullptr ? this->m_authContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = this->m_settings != nullptr ? this->m_settings : PlayFabSettings::staticSettings;

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::shared_ptr<PlayFabAuthenticationContext> authenticationContext = request.authenticationContext == nullptr ? this->m_authContext : request.authenticationContext;
        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", context->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/File/AbortFileUploads",
            headers,
            jsonAsString,
            std::bind(&PlayFabDataInstanceAPI::OnAbortFileUploadsResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            customData,
            settings));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<AbortFileUploadsResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(authenticationContext, settings, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabDataInstanceAPI::OnAbortFileUploadsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        AbortFileUploadsResponse outResult;
        if (ValidateResult(outResult, container))
        {

            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<AbortFileUploadsResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabDataInstanceAPI::DeleteFiles(
        DeleteFilesRequest& request,
        const ProcessApiCallback<DeleteFilesResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : this->m_authContext != nullptr ? this->m_authContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = this->m_settings != nullptr ? this->m_settings : PlayFabSettings::staticSettings;

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::shared_ptr<PlayFabAuthenticationContext> authenticationContext = request.authenticationContext == nullptr ? this->m_authContext : request.authenticationContext;
        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", context->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/File/DeleteFiles",
            headers,
            jsonAsString,
            std::bind(&PlayFabDataInstanceAPI::OnDeleteFilesResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            customData,
            settings));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<DeleteFilesResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(authenticationContext, settings, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabDataInstanceAPI::OnDeleteFilesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        DeleteFilesResponse outResult;
        if (ValidateResult(outResult, container))
        {

            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<DeleteFilesResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabDataInstanceAPI::FinalizeFileUploads(
        FinalizeFileUploadsRequest& request,
        const ProcessApiCallback<FinalizeFileUploadsResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : this->m_authContext != nullptr ? this->m_authContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = this->m_settings != nullptr ? this->m_settings : PlayFabSettings::staticSettings;

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::shared_ptr<PlayFabAuthenticationContext> authenticationContext = request.authenticationContext == nullptr ? this->m_authContext : request.authenticationContext;
        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", context->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/File/FinalizeFileUploads",
            headers,
            jsonAsString,
            std::bind(&PlayFabDataInstanceAPI::OnFinalizeFileUploadsResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            customData,
            settings));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<FinalizeFileUploadsResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(authenticationContext, settings, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabDataInstanceAPI::OnFinalizeFileUploadsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        FinalizeFileUploadsResponse outResult;
        if (ValidateResult(outResult, container))
        {

            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<FinalizeFileUploadsResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabDataInstanceAPI::GetFiles(
        GetFilesRequest& request,
        const ProcessApiCallback<GetFilesResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : this->m_authContext != nullptr ? this->m_authContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = this->m_settings != nullptr ? this->m_settings : PlayFabSettings::staticSettings;

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::shared_ptr<PlayFabAuthenticationContext> authenticationContext = request.authenticationContext == nullptr ? this->m_authContext : request.authenticationContext;
        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", context->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/File/GetFiles",
            headers,
            jsonAsString,
            std::bind(&PlayFabDataInstanceAPI::OnGetFilesResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            customData,
            settings));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetFilesResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(authenticationContext, settings, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabDataInstanceAPI::OnGetFilesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetFilesResponse outResult;
        if (ValidateResult(outResult, container))
        {

            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<GetFilesResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabDataInstanceAPI::GetObjects(
        GetObjectsRequest& request,
        const ProcessApiCallback<GetObjectsResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : this->m_authContext != nullptr ? this->m_authContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = this->m_settings != nullptr ? this->m_settings : PlayFabSettings::staticSettings;

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::shared_ptr<PlayFabAuthenticationContext> authenticationContext = request.authenticationContext == nullptr ? this->m_authContext : request.authenticationContext;
        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", context->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Object/GetObjects",
            headers,
            jsonAsString,
            std::bind(&PlayFabDataInstanceAPI::OnGetObjectsResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            customData,
            settings));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetObjectsResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(authenticationContext, settings, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabDataInstanceAPI::OnGetObjectsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        GetObjectsResponse outResult;
        if (ValidateResult(outResult, container))
        {

            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<GetObjectsResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabDataInstanceAPI::InitiateFileUploads(
        InitiateFileUploadsRequest& request,
        const ProcessApiCallback<InitiateFileUploadsResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : this->m_authContext != nullptr ? this->m_authContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = this->m_settings != nullptr ? this->m_settings : PlayFabSettings::staticSettings;

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::shared_ptr<PlayFabAuthenticationContext> authenticationContext = request.authenticationContext == nullptr ? this->m_authContext : request.authenticationContext;
        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", context->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/File/InitiateFileUploads",
            headers,
            jsonAsString,
            std::bind(&PlayFabDataInstanceAPI::OnInitiateFileUploadsResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            customData,
            settings));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<InitiateFileUploadsResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(authenticationContext, settings, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabDataInstanceAPI::OnInitiateFileUploadsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        InitiateFileUploadsResponse outResult;
        if (ValidateResult(outResult, container))
        {

            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<InitiateFileUploadsResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabDataInstanceAPI::SetObjects(
        SetObjectsRequest& request,
        const ProcessApiCallback<SetObjectsResponse> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {
        std::shared_ptr<PlayFabAuthenticationContext> context = request.authenticationContext != nullptr ? request.authenticationContext : this->m_authContext != nullptr ? this->m_authContext : PlayFabSettings::staticPlayer;
        std::shared_ptr<PlayFabApiSettings> settings = this->m_settings != nullptr ? this->m_settings : PlayFabSettings::staticSettings;

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const Json::Value requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::shared_ptr<PlayFabAuthenticationContext> authenticationContext = request.authenticationContext == nullptr ? this->m_authContext : request.authenticationContext;
        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", context->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Object/SetObjects",
            headers,
            jsonAsString,
            std::bind(&PlayFabDataInstanceAPI::OnSetObjectsResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            customData,
            settings));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SetObjectsResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(authenticationContext, settings, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabDataInstanceAPI::OnSetObjectsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);
        std::shared_ptr<PlayFabAuthenticationContext> context = container.GetContext();

        SetObjectsResponse outResult;
        if (ValidateResult(outResult, container))
        {

            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<SetObjectsResponse> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    bool PlayFabDataInstanceAPI::ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container)
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
