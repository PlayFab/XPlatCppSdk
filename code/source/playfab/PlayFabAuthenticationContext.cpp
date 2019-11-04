#include <stdafx.h>

#include <playfab/PlayFabAuthenticationContext.h>
#include <playfab/PlayFabSettings.h>

namespace PlayFab
{
    PlayFabAuthenticationContext::PlayFabAuthenticationContext()
    {
        ForgetAllCredentials();
    }

    void PlayFabAuthenticationContext::ForgetAllCredentials()
    {
#ifndef DISABLE_PLAYFABCLIENT_API
        clientSessionTicket.clear();
#endif
#ifndef DISABLE_PLAYFABENTITY_API
        entityToken.clear();
#endif
    }
}
