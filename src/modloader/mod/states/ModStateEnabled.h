#pragma once
#include <IconsMaterialDesign.h>

#include "ModState.h"

namespace modloader
{
    class ModStateEnabled final : public ModState
    {
    public:
        void Init(Mod& mod) override;
        bool IsActive() override { return true; }
        void Update(Mod& mod) override;
        Type GetType() override { return Type::ENABLED; }
        std::string GetLabel() override { return "Включен"; }
        std::string GetIcon() override { return ICON_MD_CHECK_CIRCLE; }
    };
}
