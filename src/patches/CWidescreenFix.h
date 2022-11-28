#pragma once
#include <intrin.h>

#include "Utils.h"
#include "CModLoader.h"
#include "module/IPatch.h"



inline bool GetImageSize(const char *fn, int *x,int *y)
{
    FILE *f=fopen(fn,"rb");
    if (f==0) return false;
    fseek(f,0,SEEK_END);
    long len=ftell(f);
    fseek(f,0,SEEK_SET);
    if (len<24) {
        fclose(f);
        return false;
    }
  // Strategy:
  // reading GIF dimensions requires the first 10 bytes of the file
  // reading PNG dimensions requires the first 24 bytes of the file
  // reading JPEG dimensions requires scanning through jpeg chunks
  // In all formats, the file is at least 24 bytes big, so we'll read that always
  unsigned char buf[24]; fread(buf,1,24,f);

  // For JPEGs, we need to read the first 12 bytes of each chunk.
  // We'll read those 12 bytes at buf+2...buf+14, i.e. overwriting the existing buf.
  if (buf[0]==0xFF && buf[1]==0xD8 && buf[2]==0xFF && buf[3]==0xE0 && buf[6]=='J' && buf[7]=='F' && buf[8]=='I' && buf[9]=='F')
  { long pos=2;
    while (buf[2]==0xFF)
    { if (buf[3]==0xC0 || buf[3]==0xC1 || buf[3]==0xC2 || buf[3]==0xC3 || buf[3]==0xC9 || buf[3]==0xCA || buf[3]==0xCB) break;
      pos += 2+(buf[4]<<8)+buf[5];
      if (pos+12>len) break;
      fseek(f,pos,SEEK_SET); fread(buf+2,1,12,f);
    }
  }

  fclose(f);

  // JPEG: (first two bytes of buf are first two bytes of the jpeg file; rest of buf is the DCT frame
  if (buf[0]==0xFF && buf[1]==0xD8 && buf[2]==0xFF)
  { *y = (buf[7]<<8) + buf[8];
    *x = (buf[9]<<8) + buf[10];
    //cout << *x << endl;
    return true;
  }

  // GIF: first three bytes say "GIF", next three give version number. Then dimensions
  if (buf[0]=='G' && buf[1]=='I' && buf[2]=='F')
  { *x = buf[6] + (buf[7]<<8);
    *y = buf[8] + (buf[9]<<8);
    return true;
  }

  // PNG: the first frame is by definition an IHDR frame, which gives dimensions
  if ( buf[0]==0x89 && buf[1]=='P' && buf[2]=='N' && buf[3]=='G' && buf[4]==0x0D && buf[5]==0x0A && buf[6]==0x1A && buf[7]==0x0A
    && buf[12]=='I' && buf[13]=='H' && buf[14]=='D' && buf[15]=='R')
  { *x = (buf[16]<<24) + (buf[17]<<16) + (buf[18]<<8) + (buf[19]<<0);
    *y = (buf[20]<<24) + (buf[21]<<16) + (buf[22]<<8) + (buf[23]<<0);
    return true;
  }

  return false;
}


class CWidescreenFix final : public IPatch {
    static inline bool overrideResolution = false;
    static inline int overrideWidth = 0;
    static inline int overrideHeight = 0;
    static inline void* lastTex = nullptr;

    static int GetTextureDimensions(int a1) {
        int v3 = 1;
        for ( int i = 2; i < 18; ++i ) // 12 in original fn
            {
            v3 *= 2;
            if ( a1 <= v3 )
                return v3;
            }
        return 0;
    }

    static float GetTextureDimensionsUv(int a1) {
        return (float) a1 / (float) GetTextureDimensions(a1);
    }

    static inline std::unordered_map<std::string, vector2i> textureOverrides = {};
    static inline std::unordered_map<void*, vector2> cachedTextures = {};

    HOOK_DEF("55 8B EC 83 EC ? C7 45 FC ? ? ? ? C7 45 F8 ? ? ? ? EB ? 8B 45 F8 83 C0 ? 89 45 F8 83 7D F8",
        int, getTextureDimensions, ARGS(int a1), {
            return GetTextureDimensions(a1); // patches larger image loading
        });

    HOOK_DEF("55 8B EC 83 7D 08 ? 74 ? 8B 45 08 8B 88 88 00 00 00",
        int, setTexture, ARGS(void* shit), {
            lastTex = shit;
            return setTexture_orig(shit);
        });

    HOOK_THISCALL_DEF(
        "55 8B EC 83 EC ? 89 4D D8 8B 45 08",
        void*, loadTexture, ARGS(char* filename, int width, int height), {
            const auto overriden = textureOverrides.count(filename) != 0;
            Log::Debug << (overriden ? "Overriden texture " : "Texture ") << filename << " loaded" << Log::Endl;
            vector2i vec;
            if (overriden) {
                vec = textureOverrides[filename];
                if (vec.x == -1 || vec.y == -1) {
                    GetImageSize(CModLoader::ResolveFilePath(filename).generic_string().c_str(), &vec.x, &vec.y);
                }
                width = vec.x;
                height = vec.y;
            }
            const auto res = loadTexture_orig(this_, filename, width, height);
            if (overriden) {
                vector2 uv;
                uv.x = GetTextureDimensionsUv(vec.x);
                uv.y = GetTextureDimensionsUv(vec.y);
                cachedTextures[res] = uv;
            }
            return res;
        });

    HOOK_THISCALL_DEF(
        "55 8B EC 83 EC ? 89 4D A8 8B 45 08",
        void*, loadTexture2, ARGS(char* filename, int width, int height), {
            const auto overriden = textureOverrides.count(filename) != 0;
            Log::Debug << (overriden ? "Overriden texture " : "Texture ") << filename << " loaded" << Log::Endl;
            vector2i vec;
            if (overriden) {
                vec = textureOverrides[filename];
                if (vec.x == -1 || vec.y == -1) {
                    GetImageSize(CModLoader::ResolveFilePath(filename).generic_string().c_str(), &vec.x, &vec.y);
                }
                width = vec.x;
                height = vec.y;
            }
            const auto res = loadTexture_orig(this_, filename, width, height);
            if (overriden) {
                vector2 uv;
                uv.x = GetTextureDimensionsUv(vec.x);
                uv.y = GetTextureDimensionsUv(vec.y);
                cachedTextures[res] = uv;
            }
            return res;
        });

    HOOK_DEF("55 8B EC 83 EC ? 8D 4D C0 E8 ? ? ? ? 8D 4D E0",
        int, renderUiTexture, ARGS(float *pos, float *uv, MANYARGS_T(DWORD)), {
            // if (va_arg1) va_arg1 &= 0xffff0000; // killer cow mode
            if (cachedTextures.count(lastTex)) {
                const auto vec = cachedTextures[lastTex];
                uv[2] = vec.x;
                uv[3] = vec.y;
            }

            return renderUiTexture_orig(pos, uv, MANYARGS);
        });

    HOOK_DEF("55 8B EC 83 EC ? 8B 45 0C 50 B9",
        int, renderUiTexture2Inner, ARGS(vector3* a1, vector3* a2, vector3* a3, vector3* a4, float* a5, float* a6, float* a7, float* a8, int a9), {
            
            if (cachedTextures.count(lastTex)) {
                const auto vec = cachedTextures[lastTex];
                a6[0] = vec.x;
                a5[0] = vec.x;
                a5[1] = vec.y;
                a8[1] = vec.y;
            }
            
            // a9 &= 0xffff0000; // killer cow mode

            return renderUiTexture2Inner_orig(a1, a2, a3, a4, a5, a6, a7, a8, a9);
        });

    HOOK_DEF("55 8B EC 81 EC ? ? ? ? D9 ? ? D8 ? ? ? ? ? D9",
        int, renderUiTexture3, ARGS(float a1, float a2, float a3, float a4, float* a5, int a6, MANYARGS_T(DWORD)), {
            
            if (cachedTextures.count(lastTex)) {
                const auto vec = cachedTextures[lastTex];
                a5[2] = vec.x;
                a5[3] = vec.y;
            }
            
            // a6 &= 0xffff0000; // killer cow mode

            return renderUiTexture3_orig(a1, a2, a3, a4, a5, a6, MANYARGS);
        });

    HOOK_DEF("55 8B EC 81 EC ? ? ? ? 8D 4D B4",
        int, renderUiTexture4, ARGS(float a2, float a3, int a4, float a5, float a6, float a7, float a8, float* a9, int a10, int a11, float a12, float a13, MANYARGS_T(DWORD)), {
            
            if (cachedTextures.count(lastTex)) {
                const auto vec = cachedTextures[lastTex];
                a9[2] = vec.x;
                a9[3] = vec.y;
            }
            
            // a10 &= 0xffff0000; // killer cow mode

            return renderUiTexture4_orig(a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, MANYARGS);
        });
    
    HOOK_DEF(
        "55 8B EC 51 C7 45 FC ? ? ? ? EB ? 8B 45 FC 83 C0 ? 89 45 FC 8B 4D FC 3B 0D ? ? ? ? 7D ? 8B 55 FC 8B 04 D5",
        int, setupD3dParams, ARGS(),
        {
            static constexpr CMemory::Pattern paramsSetPat("89 15 ? ? ? ? 8B 41 04");
            static constexpr CMemory::Pattern set32BitPat("C7 05 ? ? ? ? ? ? ? ? D9 ? ? ? ? ? D8 ? ? ? ? ? E8");
            static int* ptr = *paramsSetPat.Search().Get<int**>(2);
            static int* set32BitPtr = *set32BitPat.Search().Get<int**>(2);
            static HWND desktopWnd = GetDesktopWindow();

            *set32BitPtr = 1;
            const auto value = setupD3dParams_orig();
            RECT desktop;
            if (overrideResolution) desktop = RECT({ 0, 0, overrideWidth, overrideHeight });
            else GetWindowRect(desktopWnd, &desktop);
            Log::Debug << "Setting render params to " << desktop.right << "x" << desktop.bottom << Log::Endl;
            ptr[0] = desktop.right;
            ptr[1] = desktop.bottom;
            ptr[2] = 21;
            return value;
        }
    );
    
public:
    void Load() override {
        IPatch::Load();
        auto cfg = CConfig::Instance().cfg; 
        if (cfg.contains("widescreenFixOverride")) {
            overrideResolution = true;
            auto arr = cfg["widescreenFixOverride"].get<std::vector<int>>();
            overrideWidth = arr[0];
            overrideHeight = arr[1];
        }
        if (cfg.contains("widescreenFixTextureOverride")) {
            auto obj = cfg["widescreenFixTextureOverride"].get<std::map<std::string, std::vector<int>>>();
            for (auto [key, val] : obj) {
                textureOverrides[key] = { val[0], val[1] };
            }
        }
        HOOK_APPLY(setupD3dParams);
        HOOK_APPLY(getTextureDimensions);
        HOOK_APPLY(loadTexture);
        HOOK_APPLY(loadTexture2);
        HOOK_APPLY(renderUiTexture);
        HOOK_APPLY(renderUiTexture2Inner);
        HOOK_APPLY(renderUiTexture3);
        HOOK_APPLY(renderUiTexture4);
        HOOK_APPLY(setTexture);
    }

    bool HandleCommand(Command command) override {
        if (command.cmd == "overrideRes") { 
            if (command.args.size() < 2) {
                Log::Error << "Usage: overrideRes 1920 1080" << Log::Endl;
                return true;
            }
            
            overrideWidth = std::stoi(command.args[0]);
            overrideHeight = std::stoi(command.args[1]);
            overrideResolution = true;
            CConfig::Instance().cfg["widescreenFixOverride"] = { overrideWidth, overrideHeight };
            CConfig::Instance().Save();
            return true;
        }

        if (command.cmd == "resetResOverride") {
            overrideWidth = 0;
            overrideHeight = 0;
            overrideResolution = false;
            CConfig::Instance().cfg.erase("widescreenFixOverride");
            CConfig::Instance().Save();
            return true;
        }

        if (command.cmd == "addTextureOverride") { 
            if (command.args.size() != 1 && command.args.size() != 3) {
                Log::Error << "Usage: addTextureOverride loadscreen.jpg 1366 768" << Log::Endl;
                return true;
            }
            
            int width, height;
            if (command.args.size() >= 3) {
                width = std::stoi(command.args[1]);
                height = std::stoi(command.args[2]);
            } else {
                width = -1;
                height = -1;
            }
            
            textureOverrides[command.args[0]] = { width, height };
            auto cfg = CConfig::Instance();
            if (!cfg.cfg.count("widescreenFixTextureOverride")) cfg.cfg["widescreenFixTextureOverride"] = nlohmann::json::object();
            cfg.cfg["widescreenFixTextureOverride"][command.args[0]] = { width, height };
            cfg.Save();
            return true;
        }

        if (command.cmd == "removeTextureOverride") {
            if (command.args.size() < 1) {
                Log::Error << "Usage: removeTextureOverride loadscreen.jpg" << Log::Endl;
                return true;
            }

            if (!CConfig::Instance().cfg.count("widescreenFixTextureOverride")) return true;
            textureOverrides.erase(command.args[0]);
            CConfig::Instance().cfg["widescreenFixTextureOverride"].erase(command.args[0]);
            CConfig::Instance().Save();
            return true;
        }

        return false;
    }

    void LogDescription(const bool loaded) override {
        if (!loaded) return;
        Log::Instance() << Log::Color::GRAY << "    Доступные команды:" << Log::Endl;
        Log::Instance() << Log::Color::GRAY << "    - overrideRes 1920 1020\t\t\t\tПерезаписывает разрешение" << Log::Endl;
        Log::Instance() << Log::Color::GRAY << "    - resetResOverride\t\t\t\t\tСбрасывает перезапись разрешения" << Log::Endl;
        Log::Instance() << Log::Color::GRAY << "    - addTextureOverride loadscreen.jpg 1366 768\tПерезаписывает разрешение загрузки выбранной текстуры" << Log::Endl;
        Log::Instance() << Log::Color::GRAY << "    - removeTextureOverride loadscreen.jpg\t\tСбрасывает перезапись разрешения текстуры" << Log::Endl;
    }

    std::string GetName() override {
        return "WIDESCREEN_FIX";
    }
};