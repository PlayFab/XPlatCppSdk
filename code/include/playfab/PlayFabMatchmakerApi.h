#pragma once

#if defined(ENABLE_PLAYFABSERVER_API)

#include <playfab/PlayFabMatchmakerDataModels.h>
#include <playfab/PlayFabError.h>

namespace PlayFab
{
    class CallRequestContainerBase;
    class CallRequestContainer;

    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Matchmaker APIs
    /// </summary>
    class PlayFabMatchmakerAPI
    {
    public:
        /// <summary>
        /// Calls the Update function on your implementation of the IHttpPlugin to check for responses to HTTP requests.
        /// All api's (Client, Server, Admin etc.) share the same IHttpPlugin. 
        /// This means that you only need to call Update() on one API to retrieve the responses for all APIs.
        /// Additional calls to Update (on any API) during the same tick are unlikely to retrieve additional responses.
        /// Call Update when your game ticks as follows:
        ///     Matchmaker.Update();
        /// </summary>
        static size_t Update();
        static void ForgetAllCredentials();


        // ------------ Generated API calls

    private:
        PlayFabMatchmakerAPI(); // Private constructor, static class should never have an instance
        PlayFabMatchmakerAPI(const PlayFabMatchmakerAPI& other); // Private copy-constructor, static class should never have an instance

        // ------------ Generated result handlers

        static bool ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container);
    };
}

#endif // #if defined(ENABLE_PLAYFABSERVER_API)
