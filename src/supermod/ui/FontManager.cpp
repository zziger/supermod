#include <supermod/ui/FontManager.hpp>

#include <IconsFontAwesome5Brands.h>
#include <IconsMaterialDesign.h>
#include <fonts/FaBrands.h>
#include <fonts/MaterialIconsRegular.h>

using namespace sm::ui;

FontManager::FontManager(const float scalingFactor) : scalingFactor(scalingFactor)
{
    const auto& io = ImGui::GetIO();
    constexpr ImWchar mdRanges[] = {ICON_MIN_MD, ICON_MAX_16_MD, 0};
    constexpr ImWchar faRanges[] = {ICON_MIN_FAB, ICON_MAX_16_FAB, 0};

    ImFontConfig cfg;
    cfg.MergeMode = true;
    cfg.PixelSnapH = true;
    cfg.GlyphOffset = {0, SIZE_1X * 0.11f * scalingFactor};

    fontDefault = io.Fonts->AddFontFromFileTTF("C:/Windows/Fonts/Arial.ttf", SIZE_1X * scalingFactor, nullptr,
                                               io.Fonts->GetGlyphRangesCyrillic());
    io.Fonts->AddFontFromMemoryCompressedTTF(materialicons_regular_ttf_compressed_data,
                                             materialicons_regular_ttf_compressed_size, SIZE_1X * 0.88f * scalingFactor,
                                             &cfg, mdRanges);
    io.Fonts->Build();

    cfg.GlyphOffset = {0, SIZE_2X * 0.16f * scalingFactor};
    fontDefault2X = io.Fonts->AddFontFromFileTTF("C:/Windows/Fonts/Arial.ttf", SIZE_2X * scalingFactor, nullptr,
                                                 io.Fonts->GetGlyphRangesCyrillic());
    io.Fonts->AddFontFromMemoryCompressedTTF(materialicons_regular_ttf_compressed_data,
                                             materialicons_regular_ttf_compressed_size, SIZE_2X * 0.88f * scalingFactor,
                                             &cfg, mdRanges);
    io.Fonts->Build();

    cfg.GlyphOffset = {};
    fontFab = io.Fonts->AddFontFromFileTTF("C:/Windows/Fonts/Arial.ttf", SIZE_1X * scalingFactor, nullptr,
                                           io.Fonts->GetGlyphRangesCyrillic());
    io.Fonts->AddFontFromMemoryCompressedTTF(fa_brands_400_ttf_compressed_data, fa_brands_400_ttf_compressed_size,
                                             SIZE_1X * 0.88f * scalingFactor, &cfg, faRanges);
    io.Fonts->Build();

    fontFab2X = io.Fonts->AddFontFromFileTTF("C:/Windows/Fonts/Arial.ttf", SIZE_2X * scalingFactor, nullptr,
                                             io.Fonts->GetGlyphRangesCyrillic());
    io.Fonts->AddFontFromMemoryCompressedTTF(fa_brands_400_ttf_compressed_data, fa_brands_400_ttf_compressed_size,
                                             SIZE_2X * 0.78f * scalingFactor, &cfg, faRanges);
    io.Fonts->Build();
}

void FontManager::PushFont(float size, FontType type)
{
    const bool use2x = size > SIZE_1X;
    const float modifier = size / (use2x ? SIZE_2X : SIZE_1X);

    fontSizeStack.push(modifier);

    if (type == DEFAULT)
        ImGui::PushFont(use2x ? fontDefault2X : fontDefault);
    else
        ImGui::PushFont(use2x ? fontFab2X : fontFab);

    UpdateFontSize();
}

void FontManager::PopFont()
{
    ImGui::PopFont();
    fontSizeStack.pop();
    UpdateFontSize();
}

void FontManager::UpdateFontSize()
{
    ImGui::SetWindowFontScale(fontSizeStack.empty() ? 1.f : fontSizeStack.top());
}
