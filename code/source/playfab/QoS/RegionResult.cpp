#include <stdafx.h>

#if defined (PLAYFAB_PLATFORM_WINDOWS) || defined (PLAYFAB_PLATFORM_XBOX)
#include <playfab/QoS/RegionResult.h>

namespace PlayFab
{
    namespace QoS
    {
        RegionResult::RegionResult(const std::string& region, int latencyMs, int errorCode) :
            region(region), latencyMs(latencyMs), errorCode(errorCode)
        {
        }
    }
}
#endif // defined (PLAYFAB_PLATFORM_WINDOWS) || defined (PLAYFAB_PLATFORM_XBOX)