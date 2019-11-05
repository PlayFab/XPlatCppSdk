#pragma once

#include <string>

namespace PlayFab
{
    /// <summary>
    /// Container for PlayFab authentication credentials data.
    /// </summary>
    class PlayFabAuthenticationContext
    {
    public:
#ifndef DISABLE_PLAYFABCLIENT_API
        // DisableAdvertising is provided for completeness, but changing it is not suggested
        // Disabling this may prevent your advertising-related PlayFab marketplace partners from working correctly
        bool disableAdvertising;
        std::string playFabId; // Master_Player_Entity Id for the Player that logged in
        std::string clientSessionTicket; // Client session ticket that is used as an authentication token in many PlayFab API methods.
        std::string advertisingIdType; // Set this to the appropriate AD_TYPE_X constant below
        std::string advertisingIdValue; // Set this to corresponding device value
#endif
        std::string entityId; // Entity Id for the active entity
        std::string entityType; // Entity Type for the active entity
        std::string entityToken; // User's entity token. Entity tokens are required by all Entity API methods.

        PlayFabAuthenticationContext();
        void HandlePlayFabLogin(const std::string& setPlayFabId, const std::string& setClientSessionTicket, const std::string& setEntityId, const std::string& setEntityType, const std::string& setEntityToken);
        void ForgetAllCredentials();
    };
}
