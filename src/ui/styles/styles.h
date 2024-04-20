#pragma once

#include <IconsMaterialDesign.h>

namespace ui::styles {
    namespace danger
    {
        void PushStyle();
        void PopStyle();
        void BeginPanel(const char* id);
        void EndPanel();
        void PanelText(const char* text);
    }

    namespace warning
    {
        void PushStyle();
        void PopStyle();
        void BeginPanel(const char* id);
        void EndPanel();
        void PanelText(const char* text);
        void Icon(const char* text = ICON_MD_WARNING);
    }
}