#include "Mod.h"

#include <cassert>
#include <utility>
#include <Log.h>

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

void modloader::Mod::SetState(std::unique_ptr<ModState>&& state)
{
    assert(state && "Tried to set empty state pointer to mod");

    Log::Info << "State update for mod " << GetInfo()->GetID() << ": " << state->GetLabel() << Log::Endl;
    this->state = std::move(state);
    this->state->Init(*this);
}

void modloader::Mod::Tick()
{
    state->Update(*this);
    if (IsActive()) impl->OnTick();
}
