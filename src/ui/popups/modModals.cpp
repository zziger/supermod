#include "popups.h"

#include <imgui_internal.h>
#include <modloader_new/ModManager.h>
#include <ui/Ui.h>
#include <ui/styles/styles.h>

void ui::popups::ModModals(const std::shared_ptr<modloader::Mod>& mod) {
    ImGui::PushOverrideID(Ui::GetModalsId(mod));
    ImGui::SetNextWindowPos(ImGui::GetMainViewport()->GetCenter(), ImGuiCond_Always, ImVec2(0.5f, 0.5f));
    if (ImGui::BeginPopupModal("Удаление мода", nullptr, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings))
    {
        ImGui::Text("Вы уверены, что хотите удалить мод %s?", mod->GetInfo()->title.c_str());

        ImGui::Spacing();
        styles::danger::PushStyle();
        if (ImGui::Button("Да, удалить")) {
            modloader::ModManager::ScheduleModRemoval(mod);
            ImGui::CloseCurrentPopup();
        }
        styles::danger::PopStyle();
        ImGui::SetItemDefaultFocus();

        ImGui::SameLine();
        if (ImGui::Button("Отмена")) {
            ImGui::CloseCurrentPopup();
        }

        ImGui::EndPopup();
    }
    ImGui::PopID();
}
