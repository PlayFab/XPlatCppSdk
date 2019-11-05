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
        playFabId.clear();
        clientSessionTicket.clear();
        advertisingIdType.clear();
        advertisingIdValue.clear();
#endif
        entityId.clear();
        entityType.clear();
        entityToken.clear();
    }

    void PlayFabAuthenticationContext::HandlePlayFabLogin(const std::string& setPlayFabId, const std::string& setClientSessionTicket, const std::string& setEntityId, const std::string& setEntityType, const std::string& setEntityToken)
    {
        if (!setPlayFabId.empty()) playFabId = setPlayFabId;
        if (!setClientSessionTicket.empty()) clientSessionTicket = setClientSessionTicket;
        if (!setEntityId.empty()) entityId = setEntityId;
        if (!setEntityType.empty()) entityType = setEntityType;
        if (!setEntityToken.empty()) entityToken = setEntityToken;
    }
}
