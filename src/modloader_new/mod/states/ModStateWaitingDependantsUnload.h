#pragma once
#include <IconsMaterialDesign.h>

#include "ModState.h"

namespace modloader {
    class ModStateWaitingDependantsUnload final : public ModState {
    public:
        void Init(Mod& mod) override;
        bool IsActive(const Mod& mod) override { return true; }
        void Update(Mod& mod) override;
        Type GetType() override { return Type::WAITING_DEPENDANTS_UNLOAD; }
        std::string GetLabel() override { return "Ожидание выгрузки зависимых модов..."; }
        std::string GetIcon() override { return ICON_MD_HOURGLASS_EMPTY; }

    private:
        static bool Check(const Mod& mod);
    };
}
