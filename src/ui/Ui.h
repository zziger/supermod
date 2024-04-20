#pragma once
#include "FontManager.h"
#include "events/WindowEvent.h"
#include <imgui.h>
#include <imgui_internal.h>
#include <modloader/mod/Mod.h>

#include "IconsFontAwesome5Brands.h"

namespace ui
{
    class Ui {
        static void LoadFonts();
        static void OnWindowEvent(WindowEvent& evt);
        static void InitImGui();

        static inline FontManager* fonts = nullptr;

    public:
        static inline bool initialized = false;
        static inline bool menuOpen = false;
        static inline bool textureViewerOpen = false;
        static inline bool animationViewerOpen = false;
        static inline bool modelViewerOpen = false;

        static float GetScalingFactor();
        static float ScaledPx(float px);
        static void PushFont(float size, FontManager::FontType type = FontManager::DEFAULT);
        static void PopFont();
        static void FixNextPopupModal(bool center = true);

        static void Init();

        static void ImGuiErrorHandler(void* source, const char* msg, ...);
        static void ConstraintWindow(const char* windowTitle);
        static void Render();
        static ImGuiID GetModalsId(const std::shared_ptr<modloader::Mod>& mod);
    };
}
