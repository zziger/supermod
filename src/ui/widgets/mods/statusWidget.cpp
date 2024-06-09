#include "../widgets.h"
#include "Utils.h"

void ui::widgets::mods::Status(const std::shared_ptr<modloader::Mod>& mod)
{
    ImGui::TextColored(mod->GetState()->GetColor(), "%s",
                       (mod->GetState()->GetIcon() + " " + mod->GetState()->GetLabel()).c_str());
}