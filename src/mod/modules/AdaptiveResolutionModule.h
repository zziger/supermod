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

    static inline vector2i lastResolution { 800, 600 };
    static vector2i GetTargetResolution();
    
    static constexpr int REQUIRED_STYLES = WS_MAXIMIZEBOX | WS_SIZEBOX;

    bool state = true;

    std::optional<HookManager::RegisteredHook> d3dParamsHook;
    std::optional<uint32_t> windowEventHandler;

    void Init();
    void Render();

private:
    void OnLoad();
    void OnUnload();
};
