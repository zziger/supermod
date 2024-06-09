#pragma once
#include <supermod/modloader/mod/Mod.hpp>

namespace ui::popups
{
void ModModals(const std::shared_ptr<modloader::Mod>& mod);
void DisableSuperMod(bool restart);

namespace open
{
void DisableSuperMod();
}
} // namespace ui::popups