#include <supermod/pch.hpp>
#include <supermod/ui/widgets/widgets.hpp>

#include <supermod/modloader/mod/Mod.hpp>

void sm::ui::widgets::mods::Status(const std::shared_ptr<modloader::Mod>& mod)
{
    ImGui::TextColored(mod->GetState()->GetColor(), "%s",
                       (mod->GetState()->GetIcon() + " " + mod->GetState()->GetLabel()).c_str());
}