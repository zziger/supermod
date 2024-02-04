#include "Mod.h"

#include <cassert>

#include "states/ModStateDisabled.h"

modloader::Mod::Mod(std::unique_ptr<ModInfo>&& info, std::unique_ptr<ModImpl>&& impl)
    : info(std::move(info))
    , impl(std::move(impl))
    , state(std::make_unique<ModStateDisabled>())
{
    assert(this->impl && "Tried to create mod with empty impl pointer");

    this->state->Init(*this);
}

void modloader::Mod::SetState(std::unique_ptr<ModState>&& state)
{
    assert(state && "Tried to set empty state pointer to mod");

    this->state = std::move(state);
    this->state->Init(*this);
}

void modloader::Mod::Tick()
{
    state->Update(*this);
    if (IsActive()) impl->OnTick();
}
