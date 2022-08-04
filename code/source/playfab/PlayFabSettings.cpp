#include <stdafx.h>

#include <playfab/PlayFabSettings.h>

namespace PlayFab
{
    // Control whether all callbacks are threaded or whether the user manually controls callback timing from their main-thread
    // Note ANY api call may synchronously throw an exception if the title id is not set
    bool PlayFabSettings::threadedCallbacks = false;
    const std::string PlayFabSettings::sdkVersion = "3.87.220804";
    const std::string PlayFabSettings::buildIdentifier = "adobuild_xplatcppsdk_118";
    const std::string PlayFabSettings::versionString = "XPlatCppSdk-3.87.220804";
    std::string PlayFabSettings::productionEnvironmentURL = ".playfabapi.com";
    
    ErrorCallback PlayFabSettings::globalErrorHandler = nullptr;

    const std::shared_ptr<PlayFabApiSettings> PlayFabSettings::staticSettings = std::make_shared<PlayFabApiSettings>();
    const std::shared_ptr<PlayFabAuthenticationContext> PlayFabSettings::staticPlayer = std::make_shared<PlayFabAuthenticationContext>();

    void PlayFabSettings::ForgetAllCredentials()
    {
        staticPlayer->ForgetAllCredentials();
    }
}
