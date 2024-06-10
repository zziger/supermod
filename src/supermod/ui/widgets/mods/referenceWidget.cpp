#include <supermod/pch.hpp>
#include <supermod/ui/widgets/widgets.hpp>

#include <supermod/modloader/ModManager.hpp>

std::shared_ptr<sm::modloader::Mod> sm::ui::widgets::mods::Reference(
    const std::string& modId, const std::optional<modloader::ModInfo::Dependency>& dependency)
{
    auto mod = modloader::ModManager::FindModByID(modId);

    if (!mod)
    {
        ImGui::BeginChild(modId.c_str(), {-1, 0},
                          ImGuiChildFlags_AlwaysUseWindowPadding | ImGuiChildFlags_Border | ImGuiChildFlags_AutoResizeY,
                          ImGuiWindowFlags_NoInputs);
        ImGui::TextUnformatted(std::format("{}\nНеизвестный мод", modId).c_str());
        ImGui::EndChild();
    }
    else
    {
        if (Selectable(mod, false, true, dependency))
        {
            return mod;
        }
    }

    return nullptr;
}