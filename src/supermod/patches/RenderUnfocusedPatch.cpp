/// Forces game to render even when window is not in focus

#include <supermod/pch.hpp>

#include <supermod/events/EventManager.hpp>
#include <supermod/events/WindowEvent.hpp>

inline EventManager::Ready $render_unfocused_patch([] {
    EventManager::On<WindowEvent>([](WindowEvent& evt) {
        if (evt.msg == WM_ACTIVATE && evt.wParam == WA_INACTIVE)
            evt.Cancel();
    });
});