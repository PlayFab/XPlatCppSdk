#include <stdafx.h>

#include <playfab/PlayFabApiSettings.h>
#include <playfab/PlayFabSettings.h>

namespace PlayFab
{
    const std::map<std::string, std::string> PlayFabApiSettings::requestGetParams = {
        { "sdk", PlayFabSettings::versionString }
    };

    PlayFabApiSettings::PlayFabApiSettings() :
        verticalName(PlayFabSettings::verticalName),
        baseServiceHost(PlayFabSettings::productionEnvironmentURL),
        titleId(PlayFabSettings::titleId)
    {
    }

    std::string PlayFabApiSettings::GetUrl(const std::string& urlPath, const std::map<std::string, std::string>& getParams) const
    {
        std::string fullUrl;
        fullUrl.reserve(1000);

        fullUrl += "https://";

        if (verticalName.length() > 0)
        {
            fullUrl += verticalName;
        }
        else
        {
            fullUrl += titleId;
        }

        fullUrl += baseServiceHost;
        fullUrl += urlPath;

        bool firstParam = true;
        for (auto const& paramPair : getParams)
        {
            if (firstParam) {
                fullUrl += "?";
                firstParam = false;
            }
            else {
                fullUrl += "&";
            }
            fullUrl += paramPair.first;
            fullUrl += "=";
            fullUrl += paramPair.second;
        }

        return fullUrl;
    }
}
