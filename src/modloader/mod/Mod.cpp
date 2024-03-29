#include "Mod.h"

#include <cassert>
#include <logs/Console.h>
#include <utility>
#include <modloader/ModManager.h>
#include <spdlog/spdlog.h>

#include "states/ModStateDisabled.h"

modloader::Mod::Mod(std::shared_ptr<ModInfo> info, std::unique_ptr<ModImpl>&& impl)
    : info(std::move(info))
    , impl(std::move(impl))
    , state(std::make_unique<ModStateDisabled>())
{
    assert(this->info && "Tried to create mod with empty info pointer");
    assert(this->impl && "Tried to create mod with empty impl pointer");

    this->state->Init(*this);
}

void modloader::Mod::SetInfo(const std::shared_ptr<ModInfo>& newInfo)
{
    assert(info->GetID() == newInfo->GetID() && "Tried to set info with different ID");
    info = newInfo;
}

void modloader::Mod::SetState(std::unique_ptr<ModState>&& state)
{
    assert(state && "Tried to set empty state pointer to mod");

    if (!HasFlag(Flag::INTERNAL)) spdlog::debug("State update for mod {}: {}", Console::StyleModName(GetInfo()->GetID()), state->GetLabel());
    this->state = std::move(state);
    this->state->Init(*this);
    ModManager::MarkDirty(ModManager::DirtyFlag::STATES);
    lastStateUpdate = std::chrono::steady_clock::now();
}

void modloader::Mod::Toggle(const bool value)
{
    if (!HasFlag(Flag::INTERNAL)) spdlog::info(
        "{} mod {}",
        Console::StyleToggle(value ? "Enabling" : "Disabling", value),
        Console::StyleModName(GetID())
    );
    SetFlag(Flag::ENABLED, value);
}

void modloader::Mod::Update()
{
    state->Update(*this);
}

void modloader::Mod::Tick() const
{
    if (IsActive()) impl->OnTick();
}
