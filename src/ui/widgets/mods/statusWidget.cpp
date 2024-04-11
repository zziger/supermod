#include "../widgets.h"
#include "Utils.h"

void ui::widgets::mods::Status(const std::shared_ptr<modloader::Mod>& mod)
{
    ImGui::TextColored(mod->IsActive() ? 0x77EE77FF_color : 0xEE7777FF_color, "%s", (mod->GetState()->GetIcon() + " " + mod->GetState()->GetLabel()).c_str());
}