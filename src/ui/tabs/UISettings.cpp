#include "Config.h"
#include "Console.h"
#include "modloader/mods/Mod.h"
#include "modloader/mods/ModManager.h"
#include "sdk/Game.h"
#include "ui/ImGuiWidgets.h"
#include "ui/UI.h"

namespace ui
{
    void UI::RenderSettingsTab() {
        auto width = ImGui::GetContentRegionMax().x / 2;
        ImGui::PushItemWidth(width);

        ImGui::Text("Версия игры:");
        ImGui::SameLine();
        
        auto gameVer = sdk::Game::SerializeGameVersion(sdk::Game::GetGameVersion());
        ImGui::TextColored(0xFFA000FF_color, gameVer.c_str());
        ImGui::SameLine();
        if (ImGui::SmallButton("Скопировать")) {
            utils::copy_text(gameVer);
        }
        
        ImGui::PushID("watermark");
        ImGui::Text("Водяной знак");
        if (ImGui::Checkbox("Отображать", &showWatermark)) {
            const Config cfg;
            cfg.data["watermark"]["show"] = showWatermark;
        }
    
        if (showWatermark) {
            const char* positions[] = { "Сверху слева", "Сверху по центру", "Сверху справа", "Снизу слева", "Снизу по центру", "Снизу справа" };
            if (ImGui::Combo("Позиция", (int*) &watermarkPosition, positions, IM_ARRAYSIZE(positions))) {
                const Config cfg;
                cfg.data["watermark"]["position"] = (int) watermarkPosition;
            }

            if (ImGui::SliderFloat("Непрозрачность", &watermarkOpacity, 0, 1)) {
                const Config cfg;
                cfg.data["watermark"]["opacity"] = watermarkOpacity;
            }
        
            if (ImGui::SliderFloat("Непрозрачность фона", &watermarkBgOpacity, 0, 1)) {
                const Config cfg;
                cfg.data["watermark"]["bgOpacity"] = watermarkBgOpacity;
            }
        }
        ImGui::PopID();

        ImGui::PushID("console");
        ImGui::Text("Консоль");
        bool consoleEnabled = Console::enabled;
        if (ImGui::Checkbox("Отображать", &consoleEnabled)) {
            const Config cfg;
            cfg.data["console"] = consoleEnabled;
            if (consoleEnabled) Console::Enable();
            else Console::Disable();
        }
        ImGui::PopID();
    }

}