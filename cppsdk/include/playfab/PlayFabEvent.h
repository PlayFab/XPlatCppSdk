#pragma once

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabError.h>
#include <playfab/PlayFabEventsDataModels.h>

namespace PlayFab
{
    enum struct PlayFabEventServerProcessingType
    {
        Default,
        Lightweight,
        Heavyweight
    };

    /// <summary>
    /// Interface for any event
    /// </summary>
    struct IPlayFabEvent
    {
    public:
        virtual ~IPlayFabEvent() {}
    };

    /// <summary>
    /// PlayFab-specific implementation of an event
    /// </summary>
    struct PlayFabEvent : public IPlayFabEvent
    {
    public:
        PlayFabEventServerProcessingType serverProcessingType;
        EventsModels::EventContents eventContents;
    };

    /// <summary>
    /// Interface for any emit event request
    /// </summary>
    struct IPlayFabEmitEventRequest
    {
    public:
        virtual ~IPlayFabEmitEventRequest() {}
    };

    /// <summary>
    /// Interface for any emit event response
    /// </summary>
    struct IPlayFabEmitEventResponse
    {
    public:
        virtual ~IPlayFabEmitEventResponse() {}
    };

    // A callback that can be used in asynchronous emit event operations that take IPlayFabEvent as a parameter
    // and return back an IPlayFabEmitEventResponse. The callback procedure must be thread-safe.
    using PlayFabEmitEventCallback = void(*)(std::shared_ptr<const IPlayFabEvent>, std::shared_ptr<IPlayFabEmitEventResponse>);

    /// <summary>
    /// PlayFab-specific implementation of an emit event request
    /// </summary>
    struct PlayFabEmitEventRequest : public IPlayFabEmitEventRequest
    {
    public:
        std::shared_ptr<const PlayFabEvent> event;
        PlayFabEmitEventCallback callback;
    };

    /// <summary>
    /// PlayFab-specific implementation of an emit event response
    /// </summary>
    struct PlayFabEmitEventResponse : public IPlayFabEmitEventResponse
    {
    public:
        std::shared_ptr<const PlayFabError> playFabError;
        std::shared_ptr<const EventsModels::WriteEventsResponse> writeEventsResponse;
    };
}

#endif