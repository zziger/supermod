#include "RenderUnfocusedModule.h"

#include <Config.h>
#include <ui/widgets/widgets.h>

#include "events/WindowEvent.h"

void RenderUnfocusedModule::Init()
{
    state = Config::Get().patches.renderUnfocused.enabled;
    if (state) OnLoad();
}

void RenderUnfocusedModule::Render()
{
    auto& cfg = Config::Get();
    auto& cfgBlock = cfg.patches.renderUnfocused;

    if (ImGui::Checkbox("Рендер вне фокуса", &state))
    {
        cfgBlock.enabled = state;
        cfg.Save();

        if (state) OnLoad();
        else OnUnload();
    }

    ImGui::SameLine();
    ui::widgets::HelpMarker("Не ставит игру на паузу когда она свёрнута");
}

void RenderUnfocusedModule::OnLoad()
{
    windowEventHandler = EventManager::On<WindowEvent>([](WindowEvent& evt) {
        if (evt.msg == WM_ACTIVATE && evt.wParam == WA_INACTIVE) evt.Cancel();
    });
}

void RenderUnfocusedModule::OnUnload()
{
    if (windowEventHandler) EventManager::Off(*windowEventHandler);
}
