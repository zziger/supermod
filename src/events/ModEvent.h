#pragma once
#include "EventManager.h"
#include "../modloader/mods/ModInfo.h"

template <EventId EventId>
struct ModEvent : IEvent<EventId, ModEvent<EventId>> {
    ModInfo modInfo;

    explicit ModEvent(ModInfo modInfo) : modInfo(std::move(modInfo)) {}
    ModEvent() = default;

    void RegisterType(LuaContext* ctx) override sealed {
        ctx->registerConstMember("modInfo", &ModEvent::modInfo);
    }
};

struct ModLoadEvent final : ModEvent<"modLoad"> {
    ModLoadEvent(ModInfo modInfo): ModEvent(std::move(modInfo)) {}
};
struct ModUnloadEvent final : ModEvent<"modUnload"> {
    ModUnloadEvent(ModInfo modInfo): ModEvent(std::move(modInfo)) {}
};