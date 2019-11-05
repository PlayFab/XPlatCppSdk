#include <stdafx.h>

#include <playfab/PlayFabSettings.h>

namespace PlayFab
{
    // Control whether all callbacks are threaded or whether the user manually controls callback timing from their main-thread
    bool PlayFabSettings::threadedCallbacks = false;
    const std::string PlayFabSettings::sdkVersion = "3.21.191029";
    const std::string PlayFabSettings::buildIdentifier = "xplatcppsdk_manual";
    const std::string PlayFabSettings::versionString = "XPlatCppSdk-3.21.191029";
    std::string PlayFabSettings::productionEnvironmentURL = ".playfabapi.com";
    ErrorCallback PlayFabSettings::globalErrorHandler = nullptr;

    std::shared_ptr<PlayFabApiSettings> PlayFabSettings::staticSettings = std::make_shared<PlayFabApiSettings>();
    std::shared_ptr<PlayFabAuthenticationContext> PlayFabSettings::staticPlayer = std::make_shared<PlayFabAuthenticationContext>();

#ifndef DISABLE_PLAYFABCLIENT_API
    const std::string PlayFabSettings::AD_TYPE_IDFA = "Idfa";
    const std::string PlayFabSettings::AD_TYPE_ANDROID_ID = "Adid";
#endif

    void PlayFabSettings::ForgetAllCredentials()
    {
        staticPlayer->ForgetAllCredentials();
    }

    bool PlayFabSettings::ValidateSettings(CallRequestContainer& container)
    {
        const auto& settings = container.GetApiSettings();

        bool valid = true;
        if (settings->titleId.empty())
        {
            container.errorWrapper.HttpCode = 0;
            container.errorWrapper.HttpStatus = "Client-side validation failure";
            container.errorWrapper.ErrorCode = PlayFabErrorCode::PlayFabErrorInvalidParams;
            container.errorWrapper.ErrorName = container.errorWrapper.HttpStatus;
            container.errorWrapper.ErrorMessage = "PlayFabSettings::staticSettings->titleId has not been set properly. It must not be empty.";
            valid = false;
        }

        if (valid)
            return true;

        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(container.errorWrapper, container.GetCustomData());
        if (container.errorCallback != nullptr)
            container.errorCallback(container.errorWrapper, container.GetCustomData());

        return false;
    }
}
