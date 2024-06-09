#include <supermod/pch.hpp>
#include <supermod/ui/windows/windows.hpp>

#include <imgui.h>
#include <imgui_internal.h>
#include <supermod/game/models/ModelPool.hpp>
#include <supermod/ui/Ui.hpp>

void ui::windows::ModelViewer()
{
    static auto pool = game::ModelPool::Instance();
    const auto& io = ImGui::GetIO();

    Ui::ConstraintWindow("###Model viewer");
    if (ImGui::Begin("Просмотр моделей###Model viewer", &Ui::modelViewerOpen))
    {
        static char searchBuf[128] = "";
        ImGui::InputTextEx("##search", "Поиск", searchBuf, IM_ARRAYSIZE(searchBuf), {-1.f, 0.f}, 0);
        ImGui::Separator();
        ImGui::Spacing();

        for (auto i = 0; i < pool->modelCount; i++)
        {
            const auto model = pool->models[i];

            if (searchBuf[0] != '\0' && std::string(model->name).find(searchBuf) == std::string::npos)
                continue;

            ImGui::Selectable(model->name);
        }
    }
    ImGui::End();
}