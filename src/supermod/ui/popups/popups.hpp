#pragma once
#include <supermod/modloader/mod/Mod.hpp>

namespace sm::ui::popups
{
void ModModals(const std::shared_ptr<modloader::Mod>& mod);
void DisableSuperMod(bool restart);

namespace open
{
void DisableSuperMod();
}
} // namespace sm::ui::popups