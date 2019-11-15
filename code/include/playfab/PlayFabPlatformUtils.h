#pragma once

#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

namespace PlayFab
{
    typedef std::chrono::time_point<std::chrono::system_clock> TimePoint;

    inline TimePoint GetTimePointNow()
    {
        return std::chrono::system_clock::now();
    }

    inline time_t GetPlayFabTimeTNow()
    {
        time_t now = std::chrono::system_clock::to_time_t(GetTimePointNow());
#if defined(PLAYFAB_PLATFORM_IOS) || defined(PLAYFAB_PLATFORM_ANDROID) || defined(PLAYFAB_PLATFORM_LINUX) || defined(PLAYFAB_PLATFORM_SWITCH)
        return static_cast<Json::Int64>(now);
#else // PLAYFAB_PLATFORM_IOS || PLAYFAB_PLATFORM_ANDROID || PLAYFAB_PLATFORM_LINUX || PLAYFAB_PLATFORM_SWITCH
        return now;
#endif // PLAYFAB_PLATFORM_IOS || PLAYFAB_PLATFORM_ANDROID || PLAYFAB_PLATFORM_LINUX || PLAYFAB_PLATFORM_SWITCH
    }

    inline void AppendIntToString(int value, std::string& output)
    {
        // itoa is not available in android
        char buffer[16];
#if defined(PLAYFAB_PLATFORM_IOS) || defined(PLAYFAB_PLATFORM_ANDROID) || defined(PLAYFAB_PLATFORM_LINUX) || defined(PLAYFAB_PLATFORM_PLAYSTATION) || defined(PLAYFAB_PLATFORM_SWITCH)
        sprintf(buffer, "%d", value);
#else // PLAYFAB_PLATFORM_IOS || PLAYFAB_PLATFORM_ANDROID || PLAYFAB_PLATFORM_LINUX || PLAYFAB_PLATFORM_PLAYSTATION || PLAYFAB_PLATFORM_SWITCH
        sprintf_s(buffer, "%d", value);
#endif // PLAYFAB_PLATFORM_IOS || PLAYFAB_PLATFORM_ANDROID || PLAYFAB_PLATFORM_LINUX || PLAYFAB_PLATFORM_PLAYSTATION || PLAYFAB_PLATFORM_SWITCH
        output.append(buffer);
    }

    inline std::string LocalTimeTToUtcString(time_t now)
    {
        tm timeInfo;
#if defined(PLAYFAB_PLATFORM_WINDOWS) || defined(PLAYFAB_PLATFORM_XBOX)
        gmtime_s(&timeInfo, &now);
#elif defined(PLAYFAB_PLATFORM_LINUX) || defined(PLAYFAB_PLATFORM_IOS) || defined(PLAYFAB_PLATFORM_ANDROID) || defined(PLAYFAB_PLATFORM_PLAYSTATION)
        timeInfo = *gmtime(&now);
#endif
        char buff[64];
        strftime(buff, 64, "%Y-%m-%dT%H:%M:%S.000Z", &timeInfo);

        return buff;
    }

    inline std::string LocalTimePointToUtcString(TimePoint now)
    {
        return LocalTimeTToUtcString(std::chrono::system_clock::to_time_t(now));
    }

    inline time_t UtcStringToLocalTimeT(const std::string& utcString)
    {
        time_t output;
        tm timeStruct = {};

        std::istringstream iss(utcString);
        iss >> std::get_time(&timeStruct, "%Y-%m-%dT%T");
#if defined(PLAYFAB_PLATFORM_PLAYSTATION)
        output = mktime(&timeStruct);
#elif defined(PLAYFAB_PLATFORM_IOS) || defined(PLAYFAB_PLATFORM_ANDROID) || defined(PLAYFAB_PLATFORM_LINUX)
        output = timegm(&timeStruct);
#else
        output = _mkgmtime(&timeStruct);
#endif

        return output;
    }
}
