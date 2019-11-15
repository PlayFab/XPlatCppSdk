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

    void SetIfNotNull(const std::string& input, std::string& output)
    {
        if (!input.empty())
        {
            output = input;
        }
    }

    void PlayFabAuthenticationContext::HandlePlayFabLogin(
        const std::string& _playFabId,
        const std::string& _clientSessionTicket,
        const std::string& _entityId,
        const std::string& _entityType,
        const std::string& _entityToken
    )
    {
        SetIfNotNull(_playFabId, playFabId);
        SetIfNotNull(_clientSessionTicket, clientSessionTicket);
        SetIfNotNull(_entityId, entityId);
        SetIfNotNull(_entityType, entityType);
        SetIfNotNull(_entityToken, entityToken);
    }
}
