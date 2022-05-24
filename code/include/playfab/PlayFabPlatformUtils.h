#pragma once

#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

namespace PlayFab
{
#if defined(PLAYFAB_PLATFORM_SWITCH)
    static_assert("You must request the Nintendo specific XPlat SDK from PlayFab support.");
#else
    typedef std::chrono::system_clock Clock;
    typedef std::chrono::time_point<Clock> TimePoint;
#endif

    // The primary purpose of these format strings is to communicate to and from the PlayFab server with consistent accuracy across platforms supported by this SDK
    constexpr char TIMESTAMP_READ_FORMAT[] = "%Y-%m-%dT%T";
    constexpr char TIMESTAMP_WRITE_FORMAT[] = "%Y-%m-%dT%H:%M:%S.000Z";
    constexpr int TIMESTAMP_BUFFER_SIZE = 64; // Arbitrary number sufficiently large enough to contain the timestamp strings sent by PlayFab server

    // Initialize may be required on some platforms
    inline void InitializeClock()
    {
#if defined(PLAYFAB_PLATFORM_SWITCH)
        static_assert("You must request the Nintendo specific XPlat SDK from PlayFab support.");
#endif
    }

    // Time type conversions
    inline time_t TimePointToTimeT(const TimePoint& input)
    {
        return Clock::to_time_t(input);
    }

    inline TimePoint TimeTToTimePoint(time_t input)
    {
        return Clock::from_time_t(input);
    }

    inline tm TimeTToUtcTm(time_t input)
    {
        tm timeInfo{ 0 };
#if defined(PLAYFAB_PLATFORM_PLAYSTATION)
        gmtime_s(&input, &timeInfo);
#elif defined(PLAYFAB_PLATFORM_WINDOWS) || defined(PLAYFAB_PLATFORM_XBOX) || defined(PLAYFAB_PLATFORM_GDK)
        gmtime_s(&timeInfo, &input);
#else
        gmtime_r(&input, &timeInfo);
#endif
        return timeInfo;
    }

    inline time_t UtcTmToTimeT(tm input)
    {
#if defined(PLAYFAB_PLATFORM_PLAYSTATION)
        return mktime(&input);
#elif defined(PLAYFAB_PLATFORM_WINDOWS) || defined(PLAYFAB_PLATFORM_XBOX) || defined (PLAYFAB_PLATFORM_GDK)
        return _mkgmtime(&input);
#else
        return timegm(&input);
#endif
    }

    inline tm TimePointToUtcTm(const TimePoint& input)
    {
        return TimeTToUtcTm(Clock::to_time_t(input));
    }

    inline TimePoint UtcTmToTimePoint(const tm& input)
    {
        return TimeTToTimePoint(UtcTmToTimeT(input));
    }

    // Get Time now - Platform dependent granularity (granularity: upto 1 second, accuracy within a few seconds)
    inline TimePoint GetTimePointNow()
    {
        // The conversion is mostly to ensure consistent behavior among all platforms
        return std::chrono::time_point_cast<std::chrono::seconds>(Clock::now());
    }

    inline time_t GetTimeTNow()
    {
        return TimePointToTimeT(GetTimePointNow());
    }

    // Get a tick count that represents now in milliseconds (not useful for absolute time)
    inline Int64 GetMilliTicks()
    {
#if defined(PLAYFAB_PLATFORM_SWITCH)
        static_assert("You must request the Nintendo specific XPlat SDK from PlayFab support.");
#else
        auto msClock = std::chrono::time_point_cast<std::chrono::milliseconds>(Clock::now());
        return msClock.time_since_epoch().count();
#endif
    }

    // Time Serialization
    inline std::string UtcTmToIso8601String(const tm& input)
    {
        char buff[TIMESTAMP_BUFFER_SIZE];
        strftime(buff, TIMESTAMP_BUFFER_SIZE, TIMESTAMP_WRITE_FORMAT, &input);
        return buff;
    }

    inline tm Iso8601StringToTm(const std::string& utcString)
    {
        tm timeInfo{ 0 };
        std::istringstream iss(utcString);
        iss >> std::get_time(&timeInfo, TIMESTAMP_READ_FORMAT);
        return timeInfo;
    }

    inline std::string TimeTToIso8601String(time_t input)
    {
        return UtcTmToIso8601String(TimeTToUtcTm(input));
    }

    inline time_t Iso8601StringToTimeT(const std::string& input)
    {
        return UtcTmToTimeT(Iso8601StringToTm(input));
    }

    // TODO: Invert this conversion at some point, and serialize the milliseconds as well
    inline std::string TimePointToIso8601String(const TimePoint& input)
    {
        return UtcTmToIso8601String(TimePointToUtcTm(input));
    }

    inline TimePoint Iso8601StringToTimePoint(const std::string& input)
    {
        return UtcTmToTimePoint(Iso8601StringToTm(input));
    }
}
