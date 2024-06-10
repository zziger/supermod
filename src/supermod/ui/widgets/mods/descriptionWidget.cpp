#include <supermod/pch.hpp>
#include <supermod/ui/widgets/widgets.hpp>

#include <IconsFontAwesome5Brands.h>
#include <supermod/Utils.hpp>
#include <supermod/ui/Ui.hpp>

static inline std::map<std::string, std::string> LINK_ICONS = {
    {"discord", ICON_FA_DISCORD},
    {"github", ICON_FA_GITHUB},
    {"gitlab", ICON_FA_GITLAB},
    {"bitbucket", ICON_FA_BITBUCKET},
    {"youtube", ICON_FA_YOUTUBE},
    {"reddit", ICON_FA_REDDIT},
    {"patreon", ICON_FA_PATREON},
    {"twitter", ICON_FA_TWITTER},
    {"instagram", ICON_FA_INSTAGRAM},
    {"vk", ICON_FA_VK},
    {"odnoklassniki", ICON_FA_ODNOKLASSNIKI},
    {"googlePay", ICON_FA_GOOGLE_PAY},
    {"bingChilling", ICON_FA_ZHIHU},
    {"wikipedia", ICON_FA_WIKIPEDIA_W},
    {"steam", ICON_FA_STEAM},
};

bool sm::ui::widgets::mods::Description(const std::shared_ptr<modloader::ModInfo>& modInfo)
{
    if (!modInfo->description.empty() || !modInfo->socialLinks.empty())
    {
        ImGui::TextWrapped("%s", modInfo->description.c_str());

        Ui::PushFont(32, FontManager::FAB);
        ImGui::PushStyleColor(ImGuiCol_Button, 0x0_color);

        const float windowVisible = ImGui::GetWindowPos().x + ImGui::GetWindowContentRegionMax().x - Ui::ScaledPx(12);
        const auto& style = ImGui::GetStyle();
        bool first = true;
        for (const auto& [key, link] : modInfo->socialLinks)
        {
            const auto& icon = LINK_ICONS.at(key);
            if (icon.empty())
                continue;

            const float lastButton = ImGui::GetItemRectMax().x;
            const float nextButton = lastButton + style.ItemSpacing.x + Ui::ScaledPx(32);
            if (nextButton < windowVisible && !first)
                ImGui::SameLine();
            first = false;

            if (ImGui::Button(icon.c_str(), ImVec2(Ui::ScaledPx(38), Ui::ScaledPx(38))))
                ShellExecuteW(nullptr, L"open", utils::str_to_wstr(link).c_str(), nullptr, nullptr, SW_SHOWNORMAL);
        }

        ImGui::PopStyleColor();
        Ui::PopFont();
        return true;
    }

    return false;
}