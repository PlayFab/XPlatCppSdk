#pragma once

//#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabPluginManager.h>
//#include <playfab/PlayFabError.h>
//#include <functional>
//#include <memory>
//#include <thread>
//#include <mutex>

namespace PlayFab
{
    /// <summary>
    /// Implementation of PlayFab endpoint plugin specific to PlayFab event ingestion service.
    /// </summary>
    class PlayFabEndpoint : public IPlayFabEndpointPlugin
    {
    public:
        virtual void Initialize() override;
        virtual void WorkerThread() override;
        virtual void ProcessEventQueue() override;
    };
}

