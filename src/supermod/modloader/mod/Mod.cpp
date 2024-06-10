#include <supermod/modloader/mod/Mod.hpp>
#include <supermod/pch.hpp>

#include <supermod/logs/Console.hpp>
#include <supermod/modloader/ModManager.hpp>
#include <supermod/modloader/mod/states/ModStateDisabled.hpp>
#include <utility>

namespace sm::modloader
{
Mod::Mod(std::shared_ptr<ModInfo> info, std::unique_ptr<ModImpl>&& impl)
    : info(std::move(info)),
      impl(std::move(impl)),
      state(std::make_unique<ModStateDisabled>())
{
    assert(this->info && "Tried to create mod with empty info pointer");
    assert(this->impl && "Tried to create mod with empty impl pointer");

    this->state->Init(*this);
}

void Mod::SetInfo(const std::shared_ptr<ModInfo>& newInfo)
{
    assert(info->GetID() == newInfo->GetID() && "Tried to set info with different ID");
    info = newInfo;
}

void Mod::SetState(std::unique_ptr<ModState>&& state)
{
    assert(state && "Tried to set empty state pointer to mod");

    if (!HasFlag(Flag::INTERNAL))
        spdlog::debug("State update for mod {}: {}", Console::StyleModName(GetInfo()->GetID()), state->GetLabel());
    this->state = std::move(state);
    this->state->Init(*this);
    ModManager::MarkDirty(ModManager::DirtyFlag::STATES);
    lastStateUpdate = std::chrono::steady_clock::now();
}

void Mod::Toggle(const bool value)
{
    loadingError = "";
    if (!HasFlag(Flag::INTERNAL))
        spdlog::info("{} mod {}", Console::StyleToggle(value ? "Enabling" : "Disabling", value),
                     Console::StyleModName(GetID()));
    SetFlag(Flag::ENABLED, value);
}

void Mod::Update()
{
    state->Update(*this);
}

void Mod::Tick() const
{
    if (IsActive())
        impl->OnTick();
}
} // namespace sm::modloader