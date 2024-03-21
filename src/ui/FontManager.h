#pragma once
#include <cstdint>
#include <imgui.h>
#include <stack>
#include <vector>

namespace ui
{
    class FontManager {
    public:
        ImFont* fontDefault;
        ImFont* fontDefault2X;
        ImFont* fontFab;
        ImFont* fontFab2X;
        const float scalingFactor;

        static constexpr float SIZE_1X = 18.f;
        static constexpr float SIZE_2X = 50.f;

        explicit FontManager(float scalingFactor);

        enum FontType
        {
            DEFAULT,
            FAB
        };

        void PushFont(float size, FontType = DEFAULT);
        void PopFont();

    private:

        std::stack<float> fontSizeStack;
        void UpdateFontSize();
    };
}
