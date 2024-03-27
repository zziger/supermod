#pragma once

#include <imgui.h>
#include <IconsMaterialDesign.h>
#include <modloader/mod/Mod.h>

namespace ui::widgets {
    void ProgressBar(float fraction, const ImVec2& sizeArg = ImVec2(-FLT_MIN, 0), const char* overlay = nullptr);
    void Tooltip(const char* text, ImGuiHoveredFlags flags = ImGuiHoveredFlags_None);
    void HelpMarker(const char* desc, const char* icon = ICON_MD_QUESTION_MARK);
    bool ToggleButton(const char* strId, bool value, float time = -1, ImVec2 size = { -1.f, -1.f });

    namespace mods
    {
        std::shared_ptr<modloader::Mod> Reference(const std::string& modId);
        bool Selectable(const std::shared_ptr<modloader::Mod>& mod, bool selected = false, bool border = false, bool contextMenu = true, bool* hovered = nullptr, bool* active = nullptr);
        void ContextMenu(const std::shared_ptr<modloader::Mod>& mod);
        void Status(const std::shared_ptr<modloader::Mod>& mod);
        void InfoBlock(const std::shared_ptr<modloader::ModInfo>& modInfo);
        bool Description(const std::shared_ptr<modloader::ModInfo>& modInfo);
    }
}