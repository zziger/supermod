#pragma once
#include <supermod/pch.hpp>

#include <supermod/events/EventManager.hpp>

struct ResolutionChangeEvent final : IEvent<"resolutionChange", ResolutionChangeEvent>
{
    int x;
    int y;

    ResolutionChangeEvent(int x, int y) : x(x), y(y) {}

    void RegisterLuaType(sol::state& state) override
    {
        state.new_usertype<ResolutionChangeEvent>(sol::no_constructor, "x", &ResolutionChangeEvent::x, "y",
                                                  &ResolutionChangeEvent::y);
    }
};