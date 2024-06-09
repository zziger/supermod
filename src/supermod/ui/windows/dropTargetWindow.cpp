#include <supermod/pch.hpp>
#include <supermod/ui/windows/windows.hpp>

#include <IconsMaterialDesign.h>
#include <supermod/Utils.hpp>
#include <supermod/modloader/install/ModInstaller.hpp>
#include <supermod/ui/Ui.hpp>

void ui::windows::DropTarget()
{
    if (modloader::ModInstaller::GetDropTarget().state)
    {
        const auto viewport = ImGui::GetMainViewport();
        const auto size = viewport->Size * 0.8;
        ImGui::SetNextWindowPos(viewport->GetCenter(), ImGuiCond_Always, {0.5f, 0.5f});
        ImGui::SetNextWindowSize(size, ImGuiCond_Always);
        if (ImGui::Begin("Drop Target", nullptr,
                         ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings |
                             ImGuiWindowFlags_NoTitleBar))
        {
            const auto wrapPos = size.x - 20 * Ui::GetScalingFactor();
            ImGui::PushTextWrapPos(wrapPos);
            Ui::PushFont(20);
            const auto zipNames = modloader::ModInstaller::GetDropTarget().zipNames;
            const auto zipMsg =
                zipNames.size() == 1
                    ? zipNames[0].substr(0, 50) + (zipNames[0].size() > 50 ? "..." : "")
                    : utils::pluralize(zipNames.size(), {"архива", "архивов", "архивов"}); // TODO: locale
            const auto msg = std::format("Отпустите курсор для установки {}", zipMsg);
            const auto msgSize = ImGui::CalcTextSize(msg.c_str(), nullptr, false, wrapPos);

            Ui::PushFont(50);
            const auto icon = ICON_MD_FILE_DOWNLOAD;
            const auto iconSize = ImGui::CalcTextSize(icon);

            const auto padding = 16 * Ui::GetScalingFactor();
            const auto height = msgSize.y + iconSize.y + padding;

            ImGui::SetCursorPos({(size.x - iconSize.x) / 2, (size.y - height) / 2});
            ImGui::Text(icon);
            Ui::PopFont();

            ImGui::SetCursorPos({(size.x - msgSize.x) / 2, (size.y - height) / 2 + iconSize.y + padding});
            ImGui::Text(msg.c_str());
            Ui::PopFont();
            ImGui::PopTextWrapPos();
        }
        ImGui::End();
    }
}
