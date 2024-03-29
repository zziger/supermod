#include "DirectXUtils.h"

#include <format>
#include <vector>
#include <fstream>

#include "exceptions/Error.h"
#include <gdiplus.h>

#include "Utils.h"
#include <Shlwapi.h>

#include "events/EventManager.h"
#include "events/TickEvent.h"
#include "sdk/DirectX.h"
#include "sdk/Game.h"

namespace dx_utils
{

    void force_render_tick() {
        static tagMSG msg {};
        
        sdk::Game::currentTickIsInner = true;
        (*sdk::DirectX::d3dDevice)->Clear(0, nullptr, D3DCLEAR_TARGET, 0xFF121212, 0, 0);
        EventManager::Emit(BeforeTickEvent{});
        (*sdk::DirectX::d3dDevice)->Present(nullptr, nullptr, nullptr, nullptr);
        EventManager::Emit(AfterTickEvent{});
        sdk::Game::currentTickIsInner = false;
        
        if ( PeekMessageA(&msg, nullptr, 0, 0, 1u) ) {
            TranslateMessage(&msg);
            DispatchMessageA(&msg);
        }

    }
}