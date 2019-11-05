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
        std::string clientSessionTicket; // Client session ticket that is used as an authentication token in many PlayFab API methods.
        std::string advertisingIdType; // Set this to the appropriate AD_TYPE_X constant below
        std::string advertisingIdValue; // Set this to corresponding device value
#endif
#ifndef DISABLE_PLAYFABENTITY_API
        std::string entityToken; // User's entity token. Entity tokens are required by all Entity API methods.
#endif

        PlayFabAuthenticationContext();
        void ForgetAllCredentials();
    };
}
