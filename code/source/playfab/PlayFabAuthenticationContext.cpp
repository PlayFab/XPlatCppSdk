#include <stdafx.h>

    #include <playfab/PlayFabAuthenticationContext.h>
    
    namespace PlayFab
    {
        PlayFabAuthenticationContext::PlayFabAuthenticationContext()
        {
            ForgetAllCredentials();
        }
    
        void PlayFabAuthenticationContext::ForgetAllCredentials()
        {
    #if !defined(DISABLE_PLAYFABCLIENT_API)
            playFabId.clear();
            clientSessionTicket.clear();
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
    
        bool PlayFabAuthenticationContext::IsClientLoggedIn()
        {
            return !clientSessionTicket.empty();
        }
    
        bool PlayFabAuthenticationContext::IsEntityLoggedIn()
        {
            return !entityToken.empty();
        }
    }
    