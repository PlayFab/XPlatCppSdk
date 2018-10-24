#include <stdafx.h>

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabEvent.h>

namespace PlayFab
{
    void PlayFabEvent::SetName(const std::string& eventName)
    {
        this->eventContents.Name = eventName;
    }

    void PlayFabEvent::SetProperty(const std::string& name, const std::string& value)
    {
        this->eventContents.Payload[name] = value;
    }

    void PlayFabEvent::SetProperty(const std::string& name, const bool value)
    {
        this->eventContents.Payload[name] = value;
    }

    void PlayFabEvent::SetProperty(const std::string& name, const int8_t value)
    {
        this->eventContents.Payload[name] = value;
    }

    void PlayFabEvent::SetProperty(const std::string& name, const int16_t value)
    {
        this->eventContents.Payload[name] = value;
    }

    void PlayFabEvent::SetProperty(const std::string& name, const int32_t value)
    {
        this->eventContents.Payload[name] = value;
    }

    void PlayFabEvent::SetProperty(const std::string& name, const int64_t value)
    {
        this->eventContents.Payload[name] = value;
    }

    void PlayFabEvent::SetProperty(const std::string& name, const uint8_t value)
    {
        this->eventContents.Payload[name] = value;
    }

    void PlayFabEvent::SetProperty(const std::string& name, const uint16_t value)
    {
        this->eventContents.Payload[name] = value;
    }

    void PlayFabEvent::SetProperty(const std::string& name, const uint32_t value)
    {
        this->eventContents.Payload[name] = value;
    }

    void PlayFabEvent::SetProperty(const std::string& name, const uint64_t value)
    {
        this->eventContents.Payload[name] = value;
    }

    void PlayFabEvent::SetProperty(const std::string& name, const double value)
    {
        this->eventContents.Payload[name] = value;
    }
}

#endif