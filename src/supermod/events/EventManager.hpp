﻿#pragma once
#include <supermod/pch.hpp>

#include <atomic>
#include <concepts>
#include <iostream>
#include <map>
#include <supermod/modloader/mod/impl/lua/LuaScriptRuntime.hpp>
#include <supermod/modloader/mod/impl/lua/lua.hpp>
#include <typeindex>
#include <typeinfo>
#include <unordered_set>

namespace sm
{
struct IAnyEvent
{
    virtual ~IAnyEvent() = default;

    virtual void RegisterLuaType(sol::state& state) {}
};

template <size_t N>
struct EventId
{
    constexpr EventId(const char (&str)[N]) { std::copy_n(str, N, value); }

    char value[N];
};

template <EventId EventId, class EventType>
struct IEvent : IAnyEvent
{
    static constexpr auto eventId = EventId.value;
};

template <EventId EventId, class EventType>
struct ICancellableEvent : IEvent<EventId, EventType>
{
    virtual void Cancel() { _cancelled = true; }

    bool IsCancelled() const { return _cancelled; }

    void RegisterLuaType(sol::state& state) override
    {
        state.new_usertype<EventType>(sol::no_constructor, "cancel", &EventType::Cancel, "isCancelled",
                                      &EventType::IsCancelled);
    }

private:
    bool _cancelled = false;
};

struct ReadyEvent : IEvent<"ready", ReadyEvent>
{
};
struct WindowReadyEvent : IEvent<"windowReady", ReadyEvent>
{
};

typedef std::pair<const uint32_t, const std::function<void(IAnyEvent&)>> TEventPair;
typedef std::multimap<const std::string, TEventPair> TEventMap;

class EventManager
{
    static inline TEventMap _eventMap = {};
    static inline std::unordered_set<std::string> _enabledEvents{};
    static inline std::atomic_uint32_t _lastId = 0;
    inline static std::recursive_mutex _mutex{};

public:
    template <std::derived_from<IAnyEvent> Event>
    static uint32_t On(std::function<void(Event&)> fn)
    {
        std::lock_guard lock(_mutex);
        auto id = _lastId++;
        std::string typeId = Event::eventId;
        _enabledEvents.emplace(typeId);
        _eventMap.emplace(typeId, std::pair(id, [fn](IAnyEvent& event) { fn(static_cast<Event&>(event)); }));
        return id;
    }

    static uint32_t On(const std::string& name, std::function<void(IAnyEvent&)> fn)
    {
        std::lock_guard lock(_mutex);
        auto id = _lastId++;
        _enabledEvents.emplace(name);
        _eventMap.emplace(name, std::pair(id, [fn](IAnyEvent& event) { fn(event); }));
        return id;
    }

    template <std::derived_from<IAnyEvent> Event>
    static uint32_t Once(std::function<void(Event&)> fn)
    {
        std::lock_guard lock(_mutex);
        auto id = _lastId++;
        std::string typeId = Event::eventId;
        _enabledEvents.emplace(typeId);
        _eventMap.emplace(typeId, std::pair(id, [id, fn](IAnyEvent& event) {
                              fn(static_cast<Event&>(event));
                              Off(id);
                          }));
        return id;
    }

    template <std::derived_from<IAnyEvent> Event>
    static uint32_t On(const std::function<void()>& fn)
    {
        std::lock_guard lock(_mutex);
        auto id = _lastId++;
        std::string typeId = Event::eventId;
        _enabledEvents.emplace(typeId);
        _eventMap.emplace(typeId, std::pair(id, [fn](IAnyEvent&) { fn(); }));
        return id;
    }

    static uint32_t On(const std::string& name, const std::function<void()>& fn)
    {
        std::lock_guard lock(_mutex);
        auto id = _lastId++;
        _enabledEvents.emplace(name);
        _eventMap.emplace(name, std::pair(id, [fn](IAnyEvent&) { fn(); }));
        return id;
    }

    template <std::derived_from<IAnyEvent> Event>
    static uint32_t Once(const std::function<void()>& fn)
    {
        std::lock_guard lock(_mutex);
        auto id = _lastId++;
        std::string typeId = Event::eventId;
        _enabledEvents.emplace(typeId);
        _eventMap.emplace(typeId, std::pair(id, [id, fn](IAnyEvent&) {
                              fn();
                              Off(id);
                          }));
        return id;
    }

    static uint32_t Off(const uint32_t id)
    {
        std::lock_guard lock(_mutex);
        std::erase_if(_eventMap, [&](const auto& item) { return item.second.first == id; });
        return id;
    }

    template <std::derived_from<IAnyEvent> Event>
    static void Emit(Event& event)
    {
        const std::string typeId = Event::eventId;

        std::vector<TEventPair> fns;
        {
            std::lock_guard lock(_mutex);
            if (_enabledEvents.contains(typeId))
            {
                const auto range = _eventMap.equal_range(typeId);
                for (auto it = range.first; it != range.second; ++it)
                    fns.push_back(it->second);
            }
        }

        for (auto& fn : fns)
            fn.second(event);

        modloader::LuaScriptRuntime::DispatchEvent(typeId, event);
    }

    template <std::derived_from<IAnyEvent> Event>
    static void Emit(Event&& event)
    {
        const std::string typeId = Event::eventId;

        std::vector<TEventPair> fns{};
        {
            std::lock_guard lock(_mutex);
            if (_enabledEvents.contains(typeId))
            {
                const auto range = _eventMap.equal_range(typeId);
                for (auto it = range.first; it != range.second; ++it)
                    fns.push_back(it->second);
            }
        }

        for (auto& fn : fns)
            fn.second(event);

        modloader::LuaScriptRuntime::DispatchEvent(typeId, event);
    }

    struct Ready
    {
        Ready(const std::function<void()>& fn) { On<ReadyEvent>(fn); }
    };
};
} // namespace sm