#pragma once
#include "CGameApis.h"
#include "Utils.h"
#include "module/IMod.h"
#include "module/IPatch.h"

class CEarlyStats final : public IMod {
    HOOK_DEF(
        "55 8B EC 51 8B 45 08 A3 ? ? ? ? C7 05 ? ? ? ? ? ? ? ? 8B 4D 08",
        int, someStateChange, ARGS(int a1),
        {
            static constexpr CMemory::Pattern cmpCoins("A1 ? ? ? ? 3B 05 ? ? ? ? 7E ? 8B 0D ? ? ? ? 89 0D ? ? ? ? 8B 15 ? ? ? ? 3B 15 ? ? ? ? 7E ? A1 ? ? ? ? A3 ? ? ? ? 8B 0D ? ? ? ? 3B 0D ? ? ? ? 7E ? 8B 15 ? ? ? ? 89 15 ? ? ? ? A1 ? ? ? ?");
            static auto coinsPat = cmpCoins.Search();
            static int* coinsCollected = *coinsPat.Get<int**>(1);
            static int* coinsTotal = *coinsPat.Get<int**>(7);
            
            static constexpr CMemory::Pattern cmpGems("8B 0D ? ? ? ? 3B 0D ? ? ? ? 7E ? 8B 15 ? ? ? ? 89 15 ? ? ? ? A1 ? ? ? ? 3B 05 ? ? ? ?");
            static int* gemsCollected = *cmpGems.Search().Get<int**>(2);
            static int* gemsTotal = *cmpGems.Search().Get<int**>(8);
            
            static constexpr CMemory::Pattern cmpMonsters("8B 15 ? ? ? ? 3B 15 ? ? ? ? 7E ? A1 ? ? ? ? A3 ? ? ? ? 8B 0D ? ? ? ? 3B 0D ? ? ? ? 7E ? 8B 15 ? ? ? ? 89 15 ? ? ? ? A1 ? ? ? ? 03 05 ? ? ? ?");
            static int* monstersKilled = *cmpMonsters.Search().Get<int**>(2);
            static int* monstersTotal = *cmpMonsters.Search().Get<int**>(8);
            
            static constexpr CMemory::Pattern cmpSecrets("8B 0D ? ? ? ? 3B 0D ? ? ? ? 7E ? 8B 15 ? ? ? ? 89 15 ? ? ? ? A1 ? ? ? ? 03 05 ? ? ? ?");
            static int* secretsFound = *cmpSecrets.Search().Get<int**>(2);
            static int* secretsTotal = *cmpSecrets.Search().Get<int**>(8);
            
            if (a1 == 1) {
                const auto total = *coinsTotal + *gemsTotal + *monstersTotal + *secretsTotal;
                auto current = (*secretsFound + *monstersKilled + *gemsCollected + *coinsCollected) * 100.0 / total;
                
                std::stringstream ss;
                ss << current << "% ";
                if (*coinsCollected != *coinsTotal) ss << *coinsCollected << "/" << *coinsTotal << "co ";
                if (*gemsCollected != *gemsTotal) ss << *gemsCollected << "/" << *gemsTotal << "ge ";
                if (*monstersKilled != *monstersTotal) ss << *monstersKilled << "/" << *monstersTotal << "mo ";
                if (*secretsFound != *secretsTotal) ss << *secretsFound << "/" << *secretsTotal << "se";
                CGameApis::ShowLowerMessage(U16(ss.str()));
            }
            return someStateChange_orig(a1);
        }
    );
    
public:
    void Load() override {
        IMod::Load();
        HOOK_APPLY(someStateChange);
    }

    std::string GetName() override {
        return "EARLY_STATS";
    }
};