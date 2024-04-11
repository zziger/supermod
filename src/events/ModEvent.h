#pragma once
#include "EventManager.h"
#include "../modloader/mod/info/ModInfo.h"

template <EventId EventId>
struct ModEvent : IEvent<EventId, ModEvent<EventId>> {
    modloader::ModInfo modInfo;

    explicit ModEvent(modloader::ModInfo modInfo) : modInfo(std::move(modInfo)) {}
    ModEvent() = default;

    void RegisterLuaType(sol::state& state) override {
        state.new_usertype<ModEvent>(sol::no_constructor,
            "modInfo", &ModEvent::modInfo
        );
    }
};

struct ModLoadEvent final : ModEvent<"modLoad"> {
    ModLoadEvent(modloader::ModInfo modInfo): ModEvent(std::move(modInfo)) {}
};
struct ModUnloadEvent final : ModEvent<"modUnload"> {
    ModUnloadEvent(modloader::ModInfo modInfo): ModEvent(std::move(modInfo)) {}
};