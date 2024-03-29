#include "views.h"

#include <Config.h>
#include <logs/Console.h>
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
        ImGui::SeparatorText("Логи и консоль");

        if (ImGui::Checkbox("Отображать консоль", &cfg.console))
        {
            cfg.Save();
            Console::Update();
        }

        ImGui::Spacing();
        if (ImGui::Checkbox("Ограничить количество лог-файлов", &cfg.log.limitFiles))
        {
            cfg.Save();
        }

        if (cfg.log.limitFiles)
        {
            ImGui::Spacing();
            ImGui::Text("Максимальное количество лог-файлов:");
            if (ImGui::InputInt("##Max log files", &cfg.log.maxFiles, 1, 100))
            {
                cfg.Save();
            }
        }

        ImGui::Spacing();
        ImGui::Text("Уровень логов:");

        std::vector<std::tuple<spdlog::level::level_enum, std::string>> items = {
            { spdlog::level::err, "Только ошибки" },
            { spdlog::level::warn, "Ошибки и предупреждения" },
            { spdlog::level::info, "Ошибки, предупреждения и сообщения (по-умолчанию)" },
            { spdlog::level::debug, "Информация для разработчиков" },
            { spdlog::level::trace, "Все сообщения (медленно)" },
        };

        auto currentItem = std::ranges::find_if(items, [&cfg](const auto& item) {
            return std::get<0>(item) == cfg.log.level;
        });
        if (ImGui::BeginCombo("##Log level", currentItem == items.end() ? nullptr : std::get<1>(*currentItem).c_str()))
        {
            for (const auto& [level, msg] : items)
            {
                const auto selected = cfg.log.level == level;
                if (ImGui::Selectable(msg.c_str(), selected))
                {
                    cfg.log.level = level;
                    cfg.Save();
                    Console::Update();
                }

                if (selected)
                    ImGui::SetItemDefaultFocus();
            }

            ImGui::EndCombo();
        }

        ImGui::Spacing();
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
