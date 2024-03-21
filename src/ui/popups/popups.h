#pragma once
#include <modloader_new/mod/Mod.h>

namespace ui::popups {
    void ModModals(const std::shared_ptr<modloader::Mod>& mod);
    void DisableSuperMod(bool restart);

    namespace open {
        void DisableSuperMod();
    }
}