#include <stdafx.h>

    #include <playfab/PlayFabApiSettings.h>
    #include <playfab/PlayFabSettings.h>
    
    namespace PlayFab
    {
        PlayFabApiSettings::PlayFabApiSettings() :
            baseServiceHost(PlayFabSettings::productionEnvironmentURL)
        {
            requestGetParams["sdk"] = PlayFabSettings::versionString;
    
            // Don't let PlayFabSettings::staticSettings pull titleId from itself
            if (PlayFabSettings::staticSettings != nullptr)
            {
                titleId = PlayFabSettings::staticSettings->titleId;
                
            }
        }
    
        std::string PlayFabApiSettings::GetUrl(const std::string& urlPath) const
        {
            std::string fullUrl;
            const size_t kDefaultUrlCharSize = 1000;

                fullUrl.reserve(kDefaultUrlCharSize);
    
                fullUrl += "https://";
                fullUrl += titleId;
                fullUrl += baseServiceHost;

            
            fullUrl += urlPath;
    
            bool firstParam = true;
            for (auto const& paramPair : requestGetParams)
            {
                if (firstParam)
                {
                    fullUrl += "?";
                    firstParam = false;
                }
                else
                {
                    fullUrl += "&";
                }
                fullUrl += paramPair.first;
                fullUrl += "=";
                fullUrl += paramPair.second;
            }
    
            return fullUrl;
        }
    }
    