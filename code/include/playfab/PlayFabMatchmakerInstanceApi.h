#pragma once

#if defined(ENABLE_PLAYFABSERVER_API)

#include <playfab/PlayFabMatchmakerDataModels.h>
#include <playfab/PlayFabError.h>

namespace PlayFab
{
    class CallRequestContainerBase;
    class CallRequestContainer;
    class PlayFabApiSettings;
    class PlayFabAuthenticationContext;

    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Matchmaker APIs
    /// </summary>
    class PlayFabMatchmakerInstanceAPI
    {
    private:
        std::shared_ptr<PlayFabApiSettings> m_settings;
        std::shared_ptr<PlayFabAuthenticationContext> m_context;

    public:
        PlayFabMatchmakerInstanceAPI(const std::shared_ptr<PlayFabAuthenticationContext>& authenticationContext);
        PlayFabMatchmakerInstanceAPI(const std::shared_ptr<PlayFabApiSettings>& apiSettings, const std::shared_ptr<PlayFabAuthenticationContext>& authenticationContext);

        ~PlayFabMatchmakerInstanceAPI() = default;
        PlayFabMatchmakerInstanceAPI(const PlayFabMatchmakerInstanceAPI& source) = delete; // disable copy
        PlayFabMatchmakerInstanceAPI(PlayFabMatchmakerInstanceAPI&&) = delete; // disable move
        PlayFabMatchmakerInstanceAPI& operator=(const PlayFabMatchmakerInstanceAPI& source) = delete; // disable assignment
        PlayFabMatchmakerInstanceAPI& operator=(PlayFabMatchmakerInstanceAPI&& other) = delete; // disable move assignment

        std::shared_ptr<PlayFabApiSettings> GetSettings() const;
        std::shared_ptr<PlayFabAuthenticationContext> GetAuthenticationContext() const;
        /// <summary>
        /// Calls the Update function on your implementation of the IHttpPlugin to check for responses to HTTP requests.
        /// All api's (Client, Server, Admin etc.) share the same IHttpPlugin. 
        /// This means that you only need to call Update() on one API to retrieve the responses for all APIs.
        /// Additional calls to Update (on any API) during the same tick are unlikely to retrieve additional responses.
        /// Call Update when your game ticks as follows:
        ///     Matchmaker.Update();
        /// </summary>
        size_t Update();
        void ForgetAllCredentials();

        // ------------ Generated API calls

        // ------------ Generated result handlers

        bool ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container);
    };
}

#endif
