#include "modloader/mixins/EventUser.h"

template <std::derived_from<IEvent> Event>
uint32_t EventUser::OnEvent(std::function<void(Event&)> fn) {
    const uint32_t eventId = EventManager::On<Event>(fn);
    return _events += eventId;
}

template <std::derived_from<IEvent> Event>
uint32_t EventUser::OnEvent(const std::function<void()>& fn) {
    const uint32_t eventId = EventManager::On<Event>(fn);
    return _events += eventId;
}

uint32_t EventUser::OffEvent(const uint32_t eventId) {
    return _events -= eventId;
}

void EventUser::UnloadEvents() {
    _events.Unload();
}