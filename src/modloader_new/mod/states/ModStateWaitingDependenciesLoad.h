#pragma once
#include <IconsMaterialDesign.h>

#include "ModState.h"

namespace modloader
{
    class ModStateWaitingDependenciesLoad final : public ModState {
    public:
        void Init(Mod& mod) override;
        void Update(Mod& mod) override;
        Type GetType() override { return Type::WAITING_DEPENDENCIES_LOAD; }
        std::string GetLabel() override { return "Ожидание зависимостей..."; }
        std::string GetIcon() override { return ICON_MD_HOURGLASS_EMPTY; }

    private:
        static bool Check(const Mod& mod);
    };
}
