#include <Config.h>
#include <Console.h>

#include "views.h"

#include <IconsMaterialDesign.h>
#include <imgui.h>
#include <sdk/Game.h>
#include <ui/Ui.h>
#include <ui/popups/popups.h>
#include <ui/styles/styles.h>
#include <ui/widgets/widgets.h>

void ui::windows::main::SettingsView()
{
    const auto width = ImGui::GetContentRegionMax().x / 2;
    ImGui::PushItemWidth(width);

    ImGui::SeparatorText("Игра");
    ImGui::Text("Версия игры:");
    ImGui::SameLine();

    const auto gameVer = sdk::Game::SerializeGameVersion(sdk::Game::GetGameVersion());
    ImGui::TextColored(0xFFA000FF_color, gameVer.c_str());

    if (ImGui::Button("Скопировать"))
    {
        utils::copy_text(gameVer);
    }

    auto watermarkCfg = Config::Get()["watermark"];
    bool showWatermark = watermarkCfg["show"].as<bool>(true);
    auto watermarkPosition = static_cast<WatermarkPosition>(watermarkCfg["position"].as<int>(TOP_CENTER));
    auto watermarkOpacity = watermarkCfg["opacity"].as<float>(1.0f);
    auto watermarkBgOpacity = watermarkCfg["bgOpacity"].as<float>(0.35f);

    ImGui::PushID("watermark");
    {
        ImGui::Spacing();
        ImGui::SeparatorText("Водяной знак");
        if (ImGui::Checkbox("Отображать", &showWatermark))
        {
            const Config cfg;
            cfg.data["watermark"]["show"] = showWatermark;
        }

        if (showWatermark)
        {
            const char* positions[] = {
                "Сверху слева", "Сверху по центру", "Сверху справа", "Снизу слева", "Снизу по центру", "Снизу справа"
            };
            if (ImGui::Combo("Позиция", (int*)&watermarkPosition, positions, IM_ARRAYSIZE(positions)))
            {
                const Config cfg;
                cfg.data["watermark"]["position"] = (int)watermarkPosition;
            }

            if (ImGui::SliderFloat("Непрозрачность", &watermarkOpacity, 0, 1))
            {
                const Config cfg;
                cfg.data["watermark"]["opacity"] = watermarkOpacity;
            }

            if (ImGui::SliderFloat("Непрозрачность фона", &watermarkBgOpacity, 0, 1))
            {
                const Config cfg;
                cfg.data["watermark"]["bgOpacity"] = watermarkBgOpacity;
            }
        }
    }
    ImGui::PopID();

    ImGui::PushID("console");
    {
        ImGui::Spacing();
        ImGui::SeparatorText("Консоль");
        bool consoleEnabled = Console::enabled;
        if (ImGui::Checkbox("Отображать", &consoleEnabled))
        {
            const Config cfg;
            cfg.data["console"] = consoleEnabled;
            if (consoleEnabled) Console::Enable();
            else Console::Disable();
        }
    }
    ImGui::PopID();
}
