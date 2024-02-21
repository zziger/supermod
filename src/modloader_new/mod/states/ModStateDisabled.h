#pragma once
#include "ModState.h"

namespace modloader
{
    class ModStateDisabled final : public ModState
    {
    public:
        void Init(Mod& mod) override;
        void Update(Mod& mod) override;
        Type GetType() override { return Type::DISABLED; }
        std::string GetLabel() override { return "Выключен"; }
    };
}