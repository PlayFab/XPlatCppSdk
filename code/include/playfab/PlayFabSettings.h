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
        static const std::string verticalName;

        static bool useDevelopmentEnvironment;
        static std::string developmentEnvironmentURL;
        static std::string productionEnvironmentURL;
        static std::string titleId; // You must set this value for PlayFabSdk to work properly (Found in the Game Manager for your title, at the PlayFab Website)
        static ErrorCallback globalErrorHandler;

        static std::shared_ptr<PlayFabApiSettings> staticSettings;
        static std::shared_ptr<PlayFabAuthenticationContext> staticPlayer;

        // Control whether all callbacks are threaded or whether the user manually controls callback timing from their main-thread
        static bool threadedCallbacks;

#ifndef DISABLE_PLAYFABCLIENT_API
        static const std::string AD_TYPE_IDFA;
        static const std::string AD_TYPE_ANDROID_ID;

        static void ForgetAllCredentials();

        static std::string GetUrl(const std::string& urlPath, const std::map<std::string, std::string>& getParams);
#endif
        static bool ValidateSettings(const std::shared_ptr<PlayFabAuthenticationContext> authenticationContext, const std::shared_ptr<PlayFabApiSettings> apiSettings, CallRequestContainer& container);
    private:
        PlayFabSettings(); // Private constructor, static class should never have an instance
        PlayFabSettings(const PlayFabSettings& other); // Private copy-constructor, static class should never have an instance
    };
}
