#pragma once
#include "Utils.h"
#include "module/IMod.h"
#include "module/IPatch.h"

class CLadno final : public IMod {
    HOOK_DEF(
        "55 8B EC 81 EC ? ? ? ? 8D 4D EC",
        int, drawText, ARGS(char16_t* text),
        {
            return drawText_orig(U16("ладно"));
        }
    )

    HOOK_DEF(
        "55 8B EC 81 EC ? ? ? ? 8D 4D F0",
        int, drawText2, ARGS(char16_t* text),
        {
            return drawText2_orig(U16("ЛАДНО"));
        }
    );

    HOOK_DEF(
        "55 8B EC 83 EC ? C7 45 F8 ? ? ? ? 8B 45 18",
        int, drawFancyText, ARGS(char16_t* a2, float a3, int a4, int a5, float a6, float a7),
        {
            return drawFancyText_orig(U16("ПРОХЛАДНО"), a3, a4, a5, a6, a7);
        }
    );
    
public:
    void Load() override {
        IMod::Load();
        HOOK_APPLY(drawText);
        HOOK_APPLY(drawText2);
        HOOK_APPLY(drawFancyText);
    }

    std::string GetName() override {
        return "LADNO";
    }
};