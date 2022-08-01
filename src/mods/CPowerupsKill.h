#pragma once
#include "Utils.h"
#include "module/IMod.h"
#include "module/IPatch.h"

class CPowerupsKill final : public IMod {
    static inline constexpr CMemory::Pattern jump_boost_time_left_check = { "D9 ? ? ? ? ? D8 ? ? ? ? ? DF E0 F6 C4 ? 0F 85 ? ? ? ? D9 ? ? ? ? ? D8 ? ? ? ? ? 51 D9 ? ? E8 ? ? ? ? DC ? D8 ? ? ? ? ? D9 ? ? 8B 0D ? ? ? ?" };
    static inline constexpr CMemory::Pattern horse_shoe_time_check = { "D9 ? ? ? ? ? D8 ? ? ? ? ? DF E0 F6 C4 ? 0F 85 ? ? ? ? D9 ? ? ? ? ? D8 ? ? ? ? ? 51 D9 ? ? E8 ? ? ? ? DC ? D8 ? ? ? ? ? D9 ? ? A1 ? ? ? ?" };
    static inline constexpr CMemory::Pattern invincibility_time_check = { "D9 ? ? ? ? ? D8 ? ? ? ? ? DF E0 F6 C4 ? 0F 85 ? ? ? ? D9 ? ? ? ? ? D8 ? ? ? ? ? 51 D9 ? ? E8 ? ? ? ? DC ? D8 ? ? ? ? ? D9 ? ? 8B 15 ? ? ? ?" };
    static inline bool _already_killed = true;
    
    HOOK_DEF(
        "55 8B EC 6A ? 68 ? ? ? ? 64 A1 ? ? ? ? 50 64 89 25 ? ? ? ? 81 EC ? ? ? ? A1 ? ? ? ? 89 45 B0",
        int, updatePowerupsUi, ARGS(),
        {
            static const float* jumpBoostPtr = *jump_boost_time_left_check.Search().Get<float**>(2);
            static const float* horseShoePtr = *horse_shoe_time_check.Search().Get<float**>(2);
            static const float* invincibilityPtr = *invincibility_time_check.Search().Get<float**>(2);
        
            if (*jumpBoostPtr || *horseShoePtr || *invincibilityPtr) _already_killed = false;
            else if (!_already_killed) {
                CGameApis::Kill();
                _already_killed = true;
            }
        
            return updatePowerupsUi_orig();
        }
    );
    
public:
    void Load() override {
        IMod::Load();
        HOOK_APPLY(updatePowerupsUi);
    }

    std::string GetName() override {
        return "POWERUPS_KILL";
    }
};