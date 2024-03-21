#include "AdaptiveResolutionModule.h"

#include <ui/widgets/widgets.h>
#include "events/ResolutionChangeEvent.h"

vector2i AdaptiveResolutionModule::GetTargetResolution() {
    const auto& cfg = Config::Get().patches.resolution;
    auto mode = cfg.mode;

    if (mode == Config::ResolutionPatchMode::WINDOW && sdk::Game::IsGameFullscreen())
        mode = Config::ResolutionPatchMode::SCREEN;

    vector2i res {};
    RECT rect;
        
    switch(mode) {
        case Config::ResolutionPatchMode::WINDOW:
            GetClientRect(*sdk::Game::window, &rect);
            res = vector2i { static_cast<int>(rect.right - rect.left), static_cast<int>(rect.bottom - rect.top) };
            break;
        case Config::ResolutionPatchMode::SCREEN:
            static HWND desktopWnd = GetDesktopWindow();
            GetWindowRect(desktopWnd, &rect);
            res = { static_cast<int>(rect.right - rect.left), static_cast<int>(rect.bottom - rect.top) };
            break;
        case Config::ResolutionPatchMode::CUSTOM:
            res = { cfg.width, cfg.height };
    }

    if (res.x == 0 || res.y == 0) res = lastResolution;
    else lastResolution = res;

    return res;
}

HOOK_FN(inline static int, setup_d3d_params, ARGS())
{
    static constexpr Memory::Pattern paramsSetPat("89 15 ? ? ? ? 8B 41 04");
    
    static int* ptr = *paramsSetPat.Search().Get<int**>(2);
    const auto value = setup_d3d_params_orig();
        
    const auto [x, y] = AdaptiveResolutionModule::GetTargetResolution();
    Log::Debug << "Разрешение рендера установлено на " << x << "x" << y << Log::Endl;
        
    ptr[0] = x;
    ptr[1] = y;
        
    EventManager::Emit(ResolutionChangeEvent(x, y));
    return value;
}


void AdaptiveResolutionModule::Init()
{
    state = Config::Get().patches.resolution.enabled;
    if (state) OnLoad();
}

void AdaptiveResolutionModule::OnLoad() {
    d3dParamsHook = HookManager::RegisterHook("55 8B EC 51 C7 45 FC ? ? ? ? EB ? 8B 45 FC 83 C0 ? 89 45 FC 8B 4D FC 3B 0D ? ? ? ? 7D ? 8B 55 FC 8B 04 D5",
                 HOOK_REF(setup_d3d_params));
        
    windowEventHandler = EventManager::On<WindowEvent>([](const WindowEvent& evt) {
        if (evt.hWnd != *sdk::Game::window) return;
            
        if (evt.msg == WM_SIZE) sdk::DirectX::ResetDevice();
            
        if (evt.msg == WM_STYLECHANGED && evt.wParam == GWL_STYLE && !sdk::Game::IsGameFullscreen()) {
            const auto style = (STYLESTRUCT*) evt.lParam;
            if ((style->styleNew & REQUIRED_STYLES) != REQUIRED_STYLES)
                SetWindowLongA(evt.hWnd, GWL_STYLE, style->styleNew | REQUIRED_STYLES);
        }
            
        if (evt.msg == WM_ACTIVATE && !sdk::Game::IsGameFullscreen()) {
            const auto oldStyle = GetWindowLongA(*sdk::Game::window, GWL_STYLE);
            if ((oldStyle & REQUIRED_STYLES) != REQUIRED_STYLES)
                SetWindowLongA(*sdk::Game::window, GWL_STYLE, oldStyle | REQUIRED_STYLES);
        }
    });

    sdk::DirectX::ResetDevice();
    if (!sdk::Game::IsGameFullscreen()) SetWindowLongA(*sdk::Game::window, GWL_STYLE, GetWindowLongA(*sdk::Game::window, GWL_STYLE) | REQUIRED_STYLES);
}

void AdaptiveResolutionModule::OnUnload() {
    if (d3dParamsHook) HookManager::UnregisterHook(*d3dParamsHook);
    if (windowEventHandler) EventManager::Off(*windowEventHandler);
    sdk::DirectX::ResetDevice();
}

void AdaptiveResolutionModule::Render() {
    auto& cfg = Config::Get();
    auto& cfgBlock = cfg.patches.resolution;

    if (ImGui::Checkbox("Адаптивное разрешение", &state))
    {
        cfgBlock.enabled = state;
        cfg.Save();

        if (state)
            OnLoad();
        else
            OnUnload();
    }

    ImGui::SameLine();
    ui::widgets::HelpMarker("Позволяет игре рисоваться в другом разрешении,\nисправляет проблемы с качеством картинки.");
    ImGui::Spacing();

    if (ImGui::TreeNode("Параметры разрешения")) {
        static bool changed = false;
        const auto modePtr = reinterpret_cast<int*>(&cfgBlock.mode);

        if (ImGui::RadioButton("Разрешение окна", modePtr, 0)) changed = true;

        ImGui::SameLine();
        ui::widgets::HelpMarker("Рекомендуемый вариант", ICON_MD_SETTINGS_SUGGEST);

        if (ImGui::RadioButton("Разрешение экрана", modePtr, 1)) changed = true;
        if (ImGui::RadioButton("Ввести вручную", modePtr, 2)) changed = true;
        if (cfgBlock.mode == Config::ResolutionPatchMode::CUSTOM)
            if (ImGui::InputInt2("##resolution", &cfgBlock.width)) changed = true;

        if (changed) {
            if (ImGui::Button("Сохранить")) {
                cfg.Save();
                sdk::DirectX::ResetDevice();
                changed = false;
            }
        }

        ImGui::TreePop();
    }
}
