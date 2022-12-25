#pragma once
#include <string>

#include <thirdparty/directx/d3d8.h>

namespace ui::widgets
{
    void TextCentered(std::string text);
    bool MenuTabSelectable(const char* title, const char* icon, const bool selected);
    bool ModSelectable(const char* id, const char* title, const char* author, const char* ver, LPDIRECT3DTEXTURE8 icon, bool selected = false, bool disabled = false);
}
