#include <supermod/pch.hpp>
#include <supermod/ui/windows/main_views/views.hpp>

#include <imgui.h>
#include <supermod/Config.hpp>
#include <supermod/UpdateManager.hpp>
#include <supermod/Utils.hpp>
#include <supermod/logs/Console.hpp>
#include <supermod/game/Game.hpp>
#include <supermod/ui/Ui.hpp>

void sm::ui::windows::main::SettingsView()
{
    auto& cfg = Config::Get();

    const auto width = ImGui::GetContentRegionMax().x / 2;
    ImGui::PushItemWidth(width);

    ImGui::SeparatorText("Обновления");

    update::UpdateManager::RenderMessage();
    ImGui::Spacing();
    if (ImGui::Checkbox("Проверять автоматически", &cfg.updater.checkAutomatically))
        cfg.Save();
    if (ImGui::Checkbox("Устанавливать бета версии", &cfg.updater.usePrerelease))
        cfg.Save();

    ImGui::Spacing();
    ImGui::SeparatorText("Игра");
    ImGui::Text("Версия игры:");
    ImGui::SameLine();

    const auto gameVer = game::Game::SerializeGameVersion(game::Game::GetGameVersion());
    ImGui::TextColored(0xFFA000FF_color, gameVer.c_str());

    if (ImGui::Button("Скопировать"))
    {
        utils::copy_text(gameVer);
    }

    ImGui::PushID("watermark");
    {
        ImGui::Spacing();
        ImGui::SeparatorText("Водяной знак");

        if (ImGui::Checkbox("Отображать", &cfg.watermark.show))
            cfg.Save();

        if (cfg.watermark.show)
        {
            const char* positions[] = {"Сверху слева", "Сверху по центру", "Сверху справа",
                                       "Снизу слева",  "Снизу по центру",  "Снизу справа"};

            if (ImGui::Combo("Позиция", reinterpret_cast<int*>(&cfg.watermark.position), positions,
                             IM_ARRAYSIZE(positions)))
                cfg.Save();

            ImGui::SliderFloat("Непрозрачность", &cfg.watermark.opacity, 0, 1);
            if (ImGui::IsItemDeactivatedAfterEdit())
                cfg.Save();

            ImGui::SliderFloat("Непрозрачность фона", &cfg.watermark.bgOpacity, 0, 1);
            if (ImGui::IsItemDeactivatedAfterEdit())
                cfg.Save();
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
            {spdlog::level::err, "Только ошибки"},
            {spdlog::level::warn, "Ошибки и предупреждения"},
            {spdlog::level::info, "Ошибки, предупреждения и сообщения (по-умолчанию)"},
            {spdlog::level::debug, "Информация для разработчиков"},
            {spdlog::level::trace, "Все сообщения (медленно)"},
        };

        auto currentItem =
            std::ranges::find_if(items, [&cfg](const auto& item) { return std::get<0>(item) == cfg.log.level; });
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

    ImGui::PushID("imgui");
    {
        ImGui::Spacing();
        ImGui::SeparatorText("ImGui");
        if (ImGui::Checkbox("Совмещать окна только с зажатой клавишей Shift", &cfg.imgui.dockingWithShift))
        {
            cfg.Save();
            ImGuiIO& io = ImGui::GetIO();
            io.ConfigDockingWithShift = cfg.imgui.dockingWithShift;
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
