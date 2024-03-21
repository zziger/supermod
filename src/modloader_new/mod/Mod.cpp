#include "Mod.h"

#include <cassert>
#include <utility>
#include <Log.h>
#include <modloader_new/ModManager.h>

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

    Log::Debug << "State update for mod " << GetInfo()->GetID() << ": " << state->GetLabel() << Log::Endl;
    this->state = std::move(state);
    this->state->Init(*this);
    ModManager::MarkDirty(ModManager::DirtyFlag::STATES);
    lastStateUpdate = std::chrono::steady_clock::now();
}

void modloader::Mod::Update()
{
    state->Update(*this);
}

void modloader::Mod::Tick() const
{
    if (IsActive()) impl->OnTick();
}
