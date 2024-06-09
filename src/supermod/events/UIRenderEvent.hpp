#pragma once
#include <supermod/pch.hpp>

#include <supermod/events/EventManager.hpp>

struct UiRenderEvent final : IEvent<"uiRender", UiRenderEvent>
{
};