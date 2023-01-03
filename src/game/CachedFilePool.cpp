#include "CachedFilePool.h"

#include "memory/Memory.h"

namespace game
{
    CachedFilePool* CachedFilePool::GetInstance() {
        static constexpr Memory::Pattern pat("8B 0C 85 ? ? ? ? 51 E8 ? ? ? ? 83 C4 ? 85 C0 75"); //  mov ecx, cachedFiles[eax*4]
        static auto mem = pat.Search();
        return *mem.Get<CachedFilePool**>(3);
    }
    
    CachedFile* CachedFilePool::GetByName(const std::string& name) const {
        static constexpr Memory::Pattern pat("55 8B EC 83 EC ? A1 ? ? ? ? 89 45 ? 8B 45 ? 50 8D 4D");
        static auto mem = pat.Search();
        return mem.Call<CachedFile*>(name.c_str());
    }
    
}