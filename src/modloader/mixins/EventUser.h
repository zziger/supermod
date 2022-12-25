#pragma once
#include "modloader/containers/EventContainer.h"

class EventUser {
    EventContainer _events {};
    
protected:
    template <std::derived_from<IEvent> Event>
    uint32_t OnEvent(std::function<void(Event&)> fn);
    
    template <std::derived_from<IEvent> Event>
    uint32_t OnEvent(const std::function<void()>& fn);

    uint32_t OffEvent(uint32_t eventId);

public:
    virtual ~EventUser() = default;
    void UnloadEvents();
};