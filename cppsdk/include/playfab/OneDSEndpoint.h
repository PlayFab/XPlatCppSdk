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
    /// Implementation of OneDS endpoint plugin specific to 1DS event ingestion service.
    /// </summary>
    class OneDSEndpoint : public IPlayFabEndpointPlugin
    {
    public:
        virtual void Initialize() override;
        virtual void WorkerThread() override;
        virtual void ProcessEventQueue() override;
    };
}
