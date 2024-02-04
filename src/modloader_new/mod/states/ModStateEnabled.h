#pragma once
#include "ModState.h"

namespace modloader
{
    class ModStateEnabled final : public ModState
    {
    public:
        void Init(Mod& mod) override;
        bool IsActive(const Mod& mod) override { return true; }
        void Update(Mod& mod) override;
        std::string GetLabel() override { return "Включен"; }
    };
}
