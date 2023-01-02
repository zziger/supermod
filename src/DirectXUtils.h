#pragma once
#include <thirdparty/directx/d3d8.h>

namespace dx_utils {
    LPDIRECT3DTEXTURE8 load_png(IDirect3DDevice8* device, const char* filename);
    LPDIRECT3DTEXTURE8 load_jpg(IDirect3DDevice8* device, const char* filename);
};
