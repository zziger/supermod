#include <supermod/pch.hpp>
#include <supermod/ui/windows/windows.hpp>

#include <IconsFontAwesome5Brands.h>
#include <imgui_internal.h>
#include <supermod/Utils.hpp>
#include <supermod/ui/Ui.hpp>
#include <supermod/ui/widgets/widgets.hpp>
#include <supermod/ui/windows/main_views/views.hpp>

namespace ui
{
bool SelectableIcon(const char* title, const char* icon, const bool selected)
{
    const auto windowWidth = ImGui::GetWindowSize().x;
    const auto textWidth = ImGui::CalcTextSize(icon).x;

    ImGui::PushID(title);

    const auto value = ImGui::Selectable("", selected, ImGuiSelectableFlags_SetNavIdOnHover);
    Ui::PushFont(18);
    widgets::Tooltip(title);
    Ui::PopFont();

    ImGui::SameLine();
    ImGui::SetCursorPosX((windowWidth - textWidth) * 0.5f);
    ImGui::Text(icon);

    ImGui::PopID();
    return value;
}

void Tab(const char* icon, const int index)
{
    if (SelectableIcon(windows::main::VIEW_NAMES[index].c_str(), icon, windows::main::currentView == index))
        windows::main::currentView = index;
}

void Link(const char* title, const char* icon, const char* url)
{
    if (SelectableIcon(title, icon, false))
    {
        ShellExecuteW(nullptr, L"open", utils::str_to_wstr(url).c_str(), nullptr, nullptr, SW_SHOWNORMAL);
    }
}

void windows::Main()
{
    if (!Ui::menuOpen)
        return;

    constexpr auto lowerElements = 2;
    constexpr auto upperElements = 3;

    const auto style = ImGui::GetStyle();
    const auto spacing = style.ItemSpacing;
    constexpr auto elements = lowerElements + upperElements;
    constexpr auto fontSize = 32;
    const auto elementSize = fontSize + spacing.y * 2;
    const auto menuSize = elementSize * (elements + 0.5f);
    const auto headerSize = ImGui::GetFontSize();

    // ImGui::ShowDemoWindow();
    ImGui::SetNextWindowSize(ImVec2(700, 300), ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSizeConstraints(ImVec2(500, menuSize + headerSize), ImVec2(FLT_MAX, FLT_MAX));
    Ui::ConstraintWindow("###MainWindow");

    if (ImGui::Begin(std::format("SuperMod / {}###MainWindow", main::VIEW_NAMES[main::currentView]).c_str(),
                     &Ui::menuOpen))
    {
        ImGui::BeginChild("menu", ImVec2(Ui::ScaledPx(fontSize), 0));

        ImGui::BeginChild("upper", ImVec2(Ui::ScaledPx(fontSize), (-Ui::ScaledPx(fontSize) - spacing.y * 2) * 2));
        Ui::PushFont(fontSize);
        Tab(ICON_MD_FORMAT_LIST_BULLETED, 0);
        Tab(ICON_MD_SETTINGS, 1);
        Tab(ICON_MD_BUILD, 2);
        Ui::PopFont();
        ImGui::EndChild();

        Ui::PushFont(fontSize, FontManager::FAB);
        Link("Discord сервер", ICON_FA_DISCORD, "https://discord.supercow.community");
        Link("GitHub репозиторий", ICON_FA_GITHUB, "https://github.com/zziger/supercow-mod");
        Ui::PopFont();

        ImGui::EndChild();

        ImGui::SameLine();
        ImGui::BeginChild("content", ImVec2(0, 0));

        main::View(main::currentView);

        ImGui::EndChild();
    }
    ImGui::End();
}
} // namespace ui
