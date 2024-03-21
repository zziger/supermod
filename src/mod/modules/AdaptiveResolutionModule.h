#pragma once
#include <imgui-dx8/imgui_impl_dx8.h>

#include "Config.h"
#include "data.h"
#include "Utils.h"
#include "events/GameLoadedEvent.h"
#include "events/TickEvent.h"
#include "events/WindowEvent.h"
#include "modloader/mods/Module.h"
#include "sdk/DirectX.h"
#include "sdk/Game.h"
#include "thirdparty/IconsMaterialDesign.h"

class AdaptiveResolutionModule {
public:
    // AdaptiveResolutionModule() :
    //     Module(
    //         "adaptiveResolution",
    //         "",
    //         "Позволяет игре рендериться в другом разрешении,\n"
    //         "а так же разрешает менять размер окна.\n\n"
    //         "До 1.0.0 модуль назывался WIDESCREEN_FIX", true) {
    // }

    enum resolution_mode {
        window,
        screen,
        custom
    };

    static inline vector2i lastResolution{ 800, 600 };
    static vector2i GetTargetResolution();
    
    static constexpr int required_styles = WS_MAXIMIZEBOX | WS_SIZEBOX;

    bool state = true;

    std::optional<HookManager::RegisteredHook> d3dParamsHook;
    std::optional<uint32_t> windowEventHandler;

    void Init();
    void Render();

private:
    static YAML::Node GetConfigNode(YAML::Node node);
    void OnLoad(bool manual);
    void OnUnload();
};
