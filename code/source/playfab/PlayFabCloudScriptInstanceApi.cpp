#include <stdafx.h>

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabCloudScriptInstanceApi.h>
#include <playfab/PlayFabPluginManager.h>
#include <playfab/PlayFabSettings.h>
#include <playfab/PlayFabError.h>
#include <memory>

#if defined(PLAYFAB_PLATFORM_WINDOWS)
#pragma warning (disable: 4100) // formal parameters are part of a public interface
#endif // defined(PLAYFAB_PLATFORM_WINDOWS)

namespace PlayFab
{
    using namespace CloudScriptModels;

    PlayFabCloudScriptInstanceAPI::PlayFabCloudScriptInstanceAPI(std::shared_ptr<PlayFabAuthenticationContext> authenticationContext)
    {
        if (authenticationContext == nullptr)
            throw PlayFabException(PlayFabExceptionCode::AuthContextRequired, "Context cannot be null, create a PlayFabAuthenticationContext for each player in advance, or get <PlayFabClientInstanceAPI>.authenticationContext");
        this->authContext = std::move(authenticationContext);
    }

    PlayFabCloudScriptInstanceAPI::PlayFabCloudScriptInstanceAPI(std::shared_ptr<PlayFabApiSettings> apiSettings, std::shared_ptr<PlayFabAuthenticationContext> authenticationContext)
    {
        if (authenticationContext == nullptr)
            throw PlayFabException(PlayFabExceptionCode::AuthContextRequired, "Context cannot be null, create a PlayFabAuthenticationContext for each player in advance, or get <PlayFabClientInstanceAPI>.authenticationContext");
        this->settings = std::move(apiSettings);
        this->authContext = std::move(authenticationContext);
    }

    PlayFabCloudScriptInstanceAPI::~PlayFabCloudScriptInstanceAPI()
    {
    }

    std::shared_ptr<PlayFabApiSettings> PlayFabCloudScriptInstanceAPI::GetSettings() const
    {
        return this->settings;
    }

    void PlayFabCloudScriptInstanceAPI::SetSettings(std::shared_ptr<PlayFabApiSettings> apiSettings)
    {
        this->settings = std::move(apiSettings);
    }

    std::shared_ptr<PlayFabAuthenticationContext> PlayFabCloudScriptInstanceAPI::GetAuthenticationContext() const
    {
        return this->authContext;
    }

    void PlayFabCloudScriptInstanceAPI::SetAuthenticationContext(std::shared_ptr<PlayFabAuthenticationContext> authenticationContext)
    {
        this->authContext = std::move(authenticationContext);
    }

    std::shared_ptr<PlayFabAuthenticationContext> PlayFabCloudScriptInstanceAPI::GetOrCreateAuthenticationContext()
    {
        if (this->authContext == nullptr)
        {
            this->authContext = std::make_shared<PlayFabAuthenticationContext>();
        }
        
        return this->authContext;
    }

    size_t PlayFabCloudScriptInstanceAPI::Update()
    {
        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        return http.Update();
    }

    void PlayFabCloudScriptInstanceAPI::ForgetAllCredentials()
    {
        if (this->authContext == nullptr)
            return;

        this->authContext->ForgetAllCredentials();
    }

    // PlayFabCloudScript instance APIs

    void PlayFabCloudScriptInstanceAPI::ExecuteEntityCloudScript(
        ExecuteEntityCloudScriptRequest& request,
        const ProcessApiCallback<ExecuteCloudScriptResult> callback,
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
            "/CloudScript/ExecuteEntityCloudScript",
            headers,
            jsonAsString,
            std::bind(&PlayFabCloudScriptInstanceAPI::OnExecuteEntityCloudScriptResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            customData,
            this->settings));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ExecuteCloudScriptResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(authenticationContext, this->settings, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabCloudScriptInstanceAPI::OnExecuteEntityCloudScriptResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        ExecuteCloudScriptResult outResult;
        if (ValidateResult(outResult, container))
        {

            std::shared_ptr<void> internalPtr = container.successCallback;
            if (internalPtr.get() != nullptr)
            {
                const auto& callback = *static_cast<ProcessApiCallback<ExecuteCloudScriptResult> *>(internalPtr.get());
                callback(outResult, container.GetCustomData());
            }
        }
    }

    bool PlayFabCloudScriptInstanceAPI::ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container)
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
