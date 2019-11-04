#pragma once

#include <string>
#include <map>

namespace PlayFab
{
    /// <summary>
    /// The settings that can be used (optionally) by instance versions of PlayFab APIs.
    /// </summary>
    class PlayFabApiSettings
    {
    public:
#ifndef DISABLE_PLAYFABCLIENT_API
        std::string advertisingIdType; // Set this to the appropriate AD_TYPE_X constant (defined in PlayFabSettings)
        std::string advertisingIdValue; // Set this to corresponding device value

        // DisableAdvertising is provided for completeness, but changing it is not suggested
        // Disabling this may prevent your advertising-related PlayFab marketplace partners from working correctly
        bool disableAdvertising;
#endif

        // Control whether all callbacks are threaded or whether the user manually controls callback timing from their main-thread
        static bool threadedCallbacks;

        static const std::map<std::string, std::string> requestGetParams;

        std::string verticalName; // The name of a PlayFab service vertical
        std::string baseServiceHost; // The base for a PlayFab service host
        std::string titleId; // You must set this value for PlayFabSdk to work properly (found in the Game Manager for your title, at the PlayFab Website)
#if defined(ENABLE_PLAYFABSERVER_API) || defined(ENABLE_PLAYFABADMIN_API)
        std::string developerSecretKey; // Developer secret key. These keys can be used in development environments.
#endif

        PlayFabApiSettings();
        std::string GetUrl(const std::string& urlPath, const std::map<std::string, std::string>& getParams) const;
    };
}
