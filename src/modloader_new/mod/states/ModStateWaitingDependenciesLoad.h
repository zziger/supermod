#pragma once
#include "ModState.h"

namespace modloader
{
    class ModStateWaitingDependenciesLoad final : public ModState {
    public:
        void Init(Mod& mod) override;
        void Update(Mod& mod) override;
        std::string GetLabel() override { return "Ожидание зависимостей..."; }

    private:
        static bool Check(const Mod& mod);
    };
}
