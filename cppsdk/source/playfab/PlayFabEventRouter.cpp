#include <stdafx.h>

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabEventRouter.h>

namespace PlayFab
{
    PlayFabEventRouter::PlayFabEventRouter()
    {
        //this->pipelines.emplace(0, std::move(std::make_shared<PlayFabPipeline>(std::make_shared<PlayFabPipelineSettings>()))); // add PlayFab pipeline by default
    }

    void PlayFabEventRouter::RouteEvent(std::shared_ptr<const IPlayFabEmitEventRequest> request) const
    {        
        // implement routing to all pipelines (by default)
        //for (auto& pipelineEntry : this->pipelines)
        //{
        //    pipelineEntry.second->IntakeEvent(request);
        //}
    }
}

#endif