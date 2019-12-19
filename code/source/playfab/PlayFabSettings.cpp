#include <stdafx.h>

#include <playfab/PlayFabSettings.h>

namespace PlayFab
{
    // Control whether all callbacks are threaded or whether the user manually controls callback timing from their main-thread
    bool PlayFabSettings::threadedCallbacks = false;
    const std::string PlayFabSettings::sdkVersion = "3.22.191218";
    const std::string PlayFabSettings::buildIdentifier = "jbuild_xplatcppsdk__sdk-genericslave-3_0";
    const std::string PlayFabSettings::versionString = "XPlatCppSdk-3.22.191218";
    std::string PlayFabSettings::productionEnvironmentURL = ".playfabapi.com";
    ErrorCallback PlayFabSettings::globalErrorHandler = nullptr;

    const std::shared_ptr<PlayFabApiSettings> PlayFabSettings::staticSettings = std::make_shared<PlayFabApiSettings>();
    const std::shared_ptr<PlayFabAuthenticationContext> PlayFabSettings::staticPlayer = std::make_shared<PlayFabAuthenticationContext>();

#ifndef DISABLE_PLAYFABCLIENT_API
    const std::string PlayFabSettings::AD_TYPE_IDFA = "Idfa";
    const std::string PlayFabSettings::AD_TYPE_ANDROID_ID = "Adid";
#endif

    void PlayFabSettings::ForgetAllCredentials()
    {
        staticPlayer->ForgetAllCredentials();
    }
}
