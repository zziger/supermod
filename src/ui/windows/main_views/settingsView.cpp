#include "views.h"

#include <Config.h>
#include <Console.h>
#include <imgui.h>
#include <sdk/Game.h>
#include <ui/Ui.h>

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

    auto& cfg = Config::Get();

    ImGui::PushID("watermark");
    {
        ImGui::Spacing();
        ImGui::SeparatorText("Водяной знак");

        if (ImGui::Checkbox("Отображать", &cfg.watermark.show))
            cfg.Save();

        if (cfg.watermark.show)
        {
            const char* positions[] = {
                "Сверху слева", "Сверху по центру", "Сверху справа", "Снизу слева", "Снизу по центру", "Снизу справа"
            };

            if (ImGui::Combo("Позиция", reinterpret_cast<int*>(&cfg.watermark.position), positions, IM_ARRAYSIZE(positions)))
                cfg.Save();

            ImGui::SliderFloat("Непрозрачность", &cfg.watermark.opacity, 0, 1);
            if (ImGui::IsItemDeactivatedAfterEdit()) cfg.Save();

            ImGui::SliderFloat("Непрозрачность фона", &cfg.watermark.bgOpacity, 0, 1);
            if (ImGui::IsItemDeactivatedAfterEdit()) cfg.Save();
        }
    }
    ImGui::PopID();

    ImGui::PushID("console");
    {
        ImGui::Spacing();
        ImGui::SeparatorText("Консоль");
        if (ImGui::Checkbox("Отображать", &cfg.console))
        {
            cfg.Save();
            if (cfg.console) Console::Enable();
            else Console::Disable();
        }
    }
    ImGui::PopID();

    ImGui::PushID("dev");
    {
        ImGui::Spacing();
        ImGui::SeparatorText("Для разработчиков");
        if (ImGui::Checkbox("Отображать окно ImGui Demo", &cfg.developer.showImGuiDemo))
            cfg.Save();
    }
    ImGui::PopID();
}
