#pragma once
#include "ModState.h"

namespace modloader
{
    class ModStateWaitingDependencies final : public ModState {
        std::string GetLabel() override;
        void Update(Mod& mod) override;
    };
}
