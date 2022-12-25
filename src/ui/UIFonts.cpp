#include "UIFonts.h"

#include <cstdint>

#include <thirdparty/IconsMaterialDesign.h>
#include <thirdparty/IconsMaterialDesign.h_MaterialIcons-Regular.ttf.h>
#include <thirdparty/IconsFontAwesome5Brands.h>
#include <thirdparty/IconsFontAwesome5Brands.h_fa-brands-400.ttf.h>

using namespace ui;

UIFonts::UIFonts(const ImGuiIO& io) {
    constexpr ImWchar mdRanges[] = { ICON_MIN_MD, ICON_MAX_16_MD, 0 };
    constexpr ImWchar faRanges[] = { ICON_MIN_FAB, ICON_MAX_16_FAB, 0 };
    
    ImFontConfig cfg;
    cfg.MergeMode = true;
    cfg.PixelSnapH = true;
    cfg.GlyphOffset = { 0, 2 };
    
    fontDefault = io.Fonts->AddFontFromFileTTF("C:/Windows/Fonts/Arial.ttf", 18, nullptr, io.Fonts->GetGlyphRangesCyrillic());
    io.Fonts->AddFontFromMemoryTTF(const_cast<void*>(static_cast<const void*>(s_MaterialIcons_Regular_ttf)), sizeof s_MaterialIcons_Regular_ttf / sizeof(uint8_t), 16, &cfg, mdRanges);
    io.Fonts->Build();

    cfg.GlyphOffset = { 0, 7 };
    fontDefault2X = io.Fonts->AddFontFromFileTTF("C:/Windows/Fonts/Arial.ttf", 32, nullptr, io.Fonts->GetGlyphRangesCyrillic());
    io.Fonts->AddFontFromMemoryTTF(const_cast<void*>(static_cast<const void*>(s_MaterialIcons_Regular_ttf)), sizeof s_MaterialIcons_Regular_ttf / sizeof(uint8_t), 32, &cfg, mdRanges);
    io.Fonts->Build();

    cfg.GlyphOffset = {};
    fontFab = io.Fonts->AddFontFromFileTTF("C:/Windows/Fonts/Arial.ttf", 18, nullptr, io.Fonts->GetGlyphRangesCyrillic());
    io.Fonts->AddFontFromMemoryTTF(const_cast<void*>(static_cast<const void*>(s_fa_brands_400_ttf)), sizeof s_fa_brands_400_ttf / sizeof(uint8_t), 16, &cfg, faRanges);
    io.Fonts->Build();
    
    fontFab2X = io.Fonts->AddFontFromFileTTF("C:/Windows/Fonts/Arial.ttf", 32, nullptr, io.Fonts->GetGlyphRangesCyrillic());
    io.Fonts->AddFontFromMemoryTTF(const_cast<void*>(static_cast<const void*>(s_fa_brands_400_ttf)), sizeof s_fa_brands_400_ttf / sizeof(uint8_t), 26, &cfg, faRanges);
    io.Fonts->Build();
}