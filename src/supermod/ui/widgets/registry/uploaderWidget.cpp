#include <supermod/pch.hpp>
#include <supermod/ui/widgets/widgets.hpp>

#include <supermod/modloader/mod/Mod.hpp>

void sm::ui::widgets::registry::Uploader(const sm::registry::RegistryManager::User& user)
{
    ImGui::Text(user.name.c_str());

    if (user.role != sm::registry::RegistryManager::User::USER)
    {
        ImGui::SameLine(0, 4);
        ImGui::TextColored(0x77EE77FF_color, ICON_MD_VERIFIED);
        widgets::Tooltip(user.role == sm::registry::RegistryManager::User::TRUSTED ? "Доверенный пользователь"
                                                                                   : "Администратор");
    }
};