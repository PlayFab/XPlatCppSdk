#pragma once

#include <playfab/PlayFabError.h>
#include <playfab/PlayFabSettings.h>
#include <playfab/PlayFabCallRequestContainer.h>

namespace PlayFab
{
    /// <summary>
    /// All settings and global variables for PlayFab
    /// </summary>
    class PlayFabSettings
    {
    public:
        static const std::string sdkVersion;
        static const std::string buildIdentifier;
        static const std::string versionString;

        static std::string productionEnvironmentURL;
        static ErrorCallback globalErrorHandler;

        static std::shared_ptr<PlayFabApiSettings> staticSettings;
        static std::shared_ptr<PlayFabAuthenticationContext> staticPlayer;

        // Control whether all callbacks are threaded or whether the user manually controls callback timing from their main-thread
        static bool threadedCallbacks;

#ifndef DISABLE_PLAYFABCLIENT_API
        static const std::string AD_TYPE_IDFA;
        static const std::string AD_TYPE_ANDROID_ID;
#endif

        static void ForgetAllCredentials();
    private:
        PlayFabSettings(); // Private constructor, static class should never have an instance
        PlayFabSettings(const PlayFabSettings& other); // Private copy-constructor, static class should never have an instance
    };
}
