#include <supermod/DirectXUtils.hpp>
#include <supermod/pch.hpp>

#include <Shlwapi.h>
#include <fstream>
#include <gdiplus.h>
#include <supermod/Utils.hpp>
#include <supermod/events/EventManager.hpp>
#include <supermod/events/TickEvent.hpp>
#include <supermod/exceptions/Error.hpp>
#include <supermod/sdk/DirectX.hpp>
#include <supermod/sdk/Game.hpp>

namespace sm::dx_utils
{

void force_render_tick()
{
    static tagMSG msg{};

    sdk::Game::currentTickIsInner = true;
    (*sdk::DirectX::d3dDevice)->Clear(0, nullptr, D3DCLEAR_TARGET, 0xFF121212, 0, 0);
    EventManager::Emit(BeforeTickEvent{});
    (*sdk::DirectX::d3dDevice)->Present(nullptr, nullptr, nullptr, nullptr);
    EventManager::Emit(AfterTickEvent{});
    sdk::Game::currentTickIsInner = false;

    if (PeekMessageA(&msg, nullptr, 0, 0, 1u))
    {
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }
}
} // namespace sm::dx_utils