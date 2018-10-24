#pragma once

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabEvent.h>
#include <playfab/PlayFabEventRouter.h>

namespace PlayFab
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Lightweight/Heavyweight Event APIs
    /// </summary>
    class PlayFabEventAPI
    {
    public:
        PlayFabEventAPI();
        void EmitEvent(std::unique_ptr<const IPlayFabEvent> event, const PlayFabEmitEventCallback callback) const;

    private:
        std::shared_ptr<IPlayFabEventRouter> eventRouter;
    };
}

#endif
