#pragma once
#include <supermod/pch.hpp>

#include <supermod/events/EventManager.hpp>

namespace sm
{
struct UiRenderEvent final : IEvent<"uiRender", UiRenderEvent>
{
};
} // namespace sm