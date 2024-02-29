#pragma once
#include "UIFonts.h"
#include "events/WindowEvent.h"
#include <imgui.h>

#include "IconsFontAwesome5Brands.h"

namespace ui
{
    enum WatermarkPosition : int {
        TOP_LEFT,
        TOP_CENTER,
        TOP_RIGHT,
        BOTTOM_LEFT,
        BOTTOM_CENTER,
        BOTTOM_RIGHT
    };
    
    class UI {

        static void LoadFonts(const ImGuiIO& io);

        static void RenderWatermark();

        static void RenderModsTab();
        
        static void RenderSettingsTab();
        
        static void RenderToolsTab();
        
        static void RenderMenu();
        
        static void RenderBoot();
        static void RenderDisableModPopup(bool restart = false);

        static void OnWindowEvent(WindowEvent& evt);

        static float GetScalingFactor();

        static void InitImGui();

        static void RenderWindows();

        static inline bool _textureViewerOpen = false;
        static void RenderTextureViewer();

        static inline std::map<std::string, std::string> linkIcons = {
            { "discord", ICON_FA_DISCORD },
            { "github", ICON_FA_GITHUB },
            { "gitlab", ICON_FA_GITLAB },
            { "bitbucket", ICON_FA_BITBUCKET },
            { "youtube", ICON_FA_YOUTUBE },
            { "reddit", ICON_FA_REDDIT },
            { "patreon", ICON_FA_PATREON },
            { "twitter", ICON_FA_TWITTER },
            { "instagram", ICON_FA_INSTAGRAM },
            { "vk", ICON_FA_VK },
            { "odnoklassniki", ICON_FA_ODNOKLASSNIKI },
            { "googlePay", ICON_FA_GOOGLE_PAY },
            { "bingChilling", ICON_FA_ZHIHU },
            { "wikipedia", ICON_FA_WIKIPEDIA_W },
            { "steam", ICON_FA_STEAM },
        };
    public:
        static inline bool initialized = false;
        static inline bool menuOpen = false;
        
        static inline bool showWatermark = true;
        static inline WatermarkPosition watermarkPosition = TOP_CENTER;
        static inline float watermarkOpacity = 1.0f;
        static inline float watermarkBgOpacity = 0.35f;
        static inline UIFonts* fonts = nullptr;

        static void Init();

        static void ConstraintWindow(const char * windowTitle);
        static void Render();
    };
}
