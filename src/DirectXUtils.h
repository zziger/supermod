#pragma once
#include <string>
#include <thirdparty/directx/d3d8.h>

namespace dx_utils {
    LPDIRECT3DTEXTURE8 load_png(IDirect3DDevice8* device, const char* filename);
    LPDIRECT3DTEXTURE8 load_png_data(IDirect3DDevice8* device, const byte* data, int32_t size);
    LPDIRECT3DTEXTURE8 load_argb_pixel_data(IDirect3DDevice8* device, uint32_t width, uint32_t height, const byte* buf);
    LPDIRECT3DTEXTURE8 load_jpg(IDirect3DDevice8* device, const char* filename);
    bool get_image_dimensions(const std::string& filename, int& x, int& y);
    void force_render_tick();
}
