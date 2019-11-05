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
        static const std::map<std::string, std::string> requestGetParams;

        std::string baseServiceHost; // The base for a PlayFab service host
        std::string titleId; // You must set this value for PlayFabSdk to work properly (found in the Game Manager for your title, at the PlayFab Website)
#if defined(ENABLE_PLAYFABSERVER_API) || defined(ENABLE_PLAYFABADMIN_API)
        std::string developerSecretKey; // Developer secret key. These keys can be used in development environments.
#endif

        PlayFabApiSettings();
        std::string GetUrl(const std::string& urlPath) const;
    };
}
