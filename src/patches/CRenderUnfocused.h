#pragma once
#include "Utils.h"
#include "module/IPatch.h"

class CRenderUnfocused final : public IPatch {
    static inline bool _lastWindowFocusState = false;
    
    HOOK_DEF(
        "55 8B EC 51 8B 45 0C 89 45 FC",
        int, handleWinMessage, ARGS(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam),
        {
            if (msg == 6) {
                _lastWindowFocusState = (bool) wParam;
                if (!wParam) return DefWindowProcA(hWnd, msg, wParam, lParam); // force focused
            }
            return handleWinMessage_orig(hWnd, msg, wParam, lParam);
        }
    );
    
    HOOK_DEF(
        "55 8B EC 83 EC ? 0F B6 05 ? ? ? ? 85 C0 75 ? 8D 4D F0",
        void, handleGameEventStuff, ARGS(),
        {
            static constexpr CMemory::Pattern allowCursorPattern("C6 05 ? ? ? ? ? 68 ? ? ? ? 68 ? ? ? ? FF 15");
            static auto isCursorVisible = *allowCursorPattern.Search().Get<int**>(2);
            const auto lastValue = *isCursorVisible;
            if (!_lastWindowFocusState) *isCursorVisible = 1;
            handleGameEventStuff_orig();
            *isCursorVisible = lastValue;
        }
    );
    
public:
    void Load() override {
        IPatch::Load();
        HOOK_APPLY(handleWinMessage);
        HOOK_APPLY(handleGameEventStuff);
    }

    std::string GetName() override {
        return "RENDER_UNFOCUSED";
    }
};