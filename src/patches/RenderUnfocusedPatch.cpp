/// Forces game to render even when window is not in focus

#include <events/D3dInitEvent.h>
#include <events/WindowEvent.h>
#include <sdk/DirectX.h>

#include "events/EventManager.h"

inline EventManager::Ready $render_unfocused_patch([] {
    EventManager::On<WindowEvent>([](WindowEvent& evt) {
        if (evt.msg == WM_ACTIVATE && evt.wParam == WA_INACTIVE)
            evt.Cancel();
    });
});