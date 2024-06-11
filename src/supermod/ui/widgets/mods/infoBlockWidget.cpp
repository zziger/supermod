#include <supermod/pch.hpp>
#include <supermod/ui/widgets/widgets.hpp>

#include <supermod/ui/Ui.hpp>

void sm::ui::widgets::mods::InfoBlock(const modloader::ModInfo& modInfo)
{
    ImGui::Dummy({Ui::ScaledPx(60), Ui::ScaledPx(60)});
    ImGui::GetWindowDrawList()->AddRectFilled(ImGui::GetItemRectMin(), ImGui::GetItemRectMax(), 0x22FFFFFF);
    if (modInfo.icon)
        modInfo.icon->Draw(ImGui::GetWindowDrawList(), ImGui::GetItemRectMin(), ImGui::GetItemRectMax(), 0xFFFFFFFF);
    ImGui::SameLine();

    ImGui::BeginGroup();
    ImGui::TextWrapped("%s", modInfo.title.c_str());
    ImGui::TextWrapped("%s", modInfo.version.str().c_str());
    if (!modInfo.author.empty())
        ImGui::TextWrapped("Автор: %s", modInfo.author.c_str());
    ImGui::EndGroup();
}
