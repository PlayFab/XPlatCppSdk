#include <stdafx.h>

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabEventApi.h>

namespace PlayFab
{
    PlayFabEventAPI::PlayFabEventAPI(bool threadedEventPipeline) : 
        eventRouter(std::make_shared<PlayFabEventRouter>(threadedEventPipeline))
    {
    }

    std::shared_ptr<IPlayFabEventRouter> PlayFabEventAPI::GetEventRouter() const
    {
        return this->eventRouter;
    }

    void PlayFabEventAPI::EmitEvent(std::unique_ptr<const IPlayFabEvent> event, const PlayFabEmitEventCallback callback) const
    {
        auto eventRequest = std::shared_ptr<PlayFabEmitEventRequest>(new PlayFabEmitEventRequest());
        std::shared_ptr<const IPlayFabEvent> sharedGenericEvent = std::move(event);
        eventRequest->event = std::dynamic_pointer_cast<const PlayFabEvent>(sharedGenericEvent);
        eventRequest->callback = callback;

        this->eventRouter->RouteEvent(eventRequest);
    }

    void PlayFabEventAPI::EmitEvent(std::unique_ptr<const IPlayFabEvent> event, std::function<void(std::shared_ptr<const IPlayFabEvent>, std::shared_ptr<const IPlayFabEmitEventResponse>)> callback) const
    {
        auto eventRequest = std::shared_ptr<PlayFabEmitEventRequest>(new PlayFabEmitEventRequest());
        std::shared_ptr<const IPlayFabEvent> sharedGenericEvent = std::move(event);
        eventRequest->event = std::dynamic_pointer_cast<const PlayFabEvent>(sharedGenericEvent);
        eventRequest->stdCallback = callback;

        this->eventRouter->RouteEvent(eventRequest);
    }
    
    void PlayFabEventAPI::Update()
    {
        this->eventRouter->Update();
    }
}

#endif
