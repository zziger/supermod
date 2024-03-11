#pragma once
#include <IconsMaterialDesign.h>

#include "ModState.h"

namespace modloader {
    class ModStateWaitingDependentsUnload final : public ModState {
    public:
        void Init(Mod& mod) override;
        bool IsActive(const Mod& mod) override { return true; }
        void Update(Mod& mod) override;
        Type GetType() override { return Type::WAITING_DEPENDENTS_UNLOAD; }
        std::string GetLabel() override { return "Ожидание выгрузки зависимых модов..."; }
        std::string GetIcon() override;

    private:
        static bool Check(const Mod& mod);
    };
}
