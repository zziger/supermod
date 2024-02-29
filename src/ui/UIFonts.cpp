#include "UIFonts.h"

#include <cstdint>

#include <thirdparty/IconsMaterialDesign.h>
#include <thirdparty/IconsFontAwesome5Brands.h>

#include "thirdparty/fonts/FaBrands.h"
#include "thirdparty/fonts/MaterialIconsRegular.h"

using namespace ui;

UIFonts::UIFonts(const ImGuiIO& io, const float scalingFactor) {
    constexpr ImWchar mdRanges[] = { ICON_MIN_MD, ICON_MAX_16_MD, 0 };
    constexpr ImWchar faRanges[] = { ICON_MIN_FAB, ICON_MAX_16_FAB, 0 };
    
    ImFontConfig cfg;
    cfg.MergeMode = true;
    cfg.PixelSnapH = true;
    cfg.GlyphOffset = { 0, 2 };
    
    fontDefault = io.Fonts->AddFontFromFileTTF("C:/Windows/Fonts/Arial.ttf", 18 * scalingFactor, nullptr, io.Fonts->GetGlyphRangesCyrillic());
    io.Fonts->AddFontFromMemoryCompressedTTF(materialicons_regular_ttf_compressed_data, materialicons_regular_ttf_compressed_size, 16 * scalingFactor, &cfg, mdRanges);
    io.Fonts->Build();

    cfg.GlyphOffset = { 0, 7 };
    fontDefault2X = io.Fonts->AddFontFromFileTTF("C:/Windows/Fonts/Arial.ttf", 32 * scalingFactor, nullptr, io.Fonts->GetGlyphRangesCyrillic());
    io.Fonts->AddFontFromMemoryCompressedTTF(materialicons_regular_ttf_compressed_data, materialicons_regular_ttf_compressed_size, 32 * scalingFactor, &cfg, mdRanges);
    io.Fonts->Build();

    cfg.GlyphOffset = {};
    fontFab = io.Fonts->AddFontFromFileTTF("C:/Windows/Fonts/Arial.ttf", 18 * scalingFactor, nullptr, io.Fonts->GetGlyphRangesCyrillic());
    io.Fonts->AddFontFromMemoryCompressedTTF(fa_brands_400_ttf_compressed_data, fa_brands_400_ttf_compressed_size, 16 * scalingFactor, &cfg, faRanges);
    io.Fonts->Build();
    
    fontFab2X = io.Fonts->AddFontFromFileTTF("C:/Windows/Fonts/Arial.ttf", 32 * scalingFactor, nullptr, io.Fonts->GetGlyphRangesCyrillic());
    io.Fonts->AddFontFromMemoryCompressedTTF(fa_brands_400_ttf_compressed_data, fa_brands_400_ttf_compressed_size, 26 * scalingFactor, &cfg, faRanges);
    io.Fonts->Build();
}