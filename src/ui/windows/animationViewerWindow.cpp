#include <game/animations/AnimationPool.h>
#include <ui/Ui.h>

#include "windows.h"

void ui::windows::AnimationViewer()
{
    static auto pool = game::AnimationPool::Instance();
    const auto& io = ImGui::GetIO();

    Ui::ConstraintWindow("###Animation viewer");
    if (ImGui::Begin("Просмотр анимаций###Animation viewer", &Ui::animationViewerOpen))
    {
        static char searchBuf[128] = "";
        ImGui::InputTextEx("##search", "Поиск", searchBuf, IM_ARRAYSIZE(searchBuf), {-1.f, 0.f}, 0);
        ImGui::Separator();
        ImGui::Spacing();

        for (auto i = 0; i < pool->animationCount; i++)
        {
            const auto model = pool->animations[i];

            if (searchBuf[0] != '\0' && std::string(model->name).find(searchBuf) == std::string::npos)
                continue;

            ImGui::Selectable(model->name);
        }
    }
    ImGui::End();
}