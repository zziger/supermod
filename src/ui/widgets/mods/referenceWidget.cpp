#include <modloader/ModManager.h>

#include "../widgets.h"

std::shared_ptr<modloader::Mod> ui::widgets::mods::Reference(const std::string& modId)
{
    const auto mod = modloader::ModManager::FindModByID(modId);

    if (!mod)
    {
        ImGui::BeginChild(modId.c_str(), { -1, 0 }, ImGuiChildFlags_AlwaysUseWindowPadding | ImGuiChildFlags_Border | ImGuiChildFlags_AutoResizeY, ImGuiWindowFlags_NoInputs);
        ImGui::TextUnformatted(std::format("{}\nНеизвестный мод", modId).c_str());
        ImGui::EndChild();
    }
    else
    {
        if (Selectable(mod, false, true))
        {
            return mod;
        }
    }

    return nullptr;
}