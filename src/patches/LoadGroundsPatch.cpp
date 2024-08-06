#include "Utils.h"
#include "events/EventManager.h"
#include "game/SoundHost.h"
#include "memory/HookManager.h"
#include "sdk/Game.h"
#include <fstream>

#include "events/ModEvent.h"
#include "modloader/mods/ModManager.h"

static Memory fillOutGrounds;
static Memory readGrounds;
static Memory fillOutLimit;
static Memory readLimit;
static Memory reloadGrounds;
static Memory printMethod;
static void* buffer;

HOOK_FN(inline void*, load_ground_textures, ARGS())
{
    auto grounds = 5;

    for (auto& mod : ModManager::GetMods())
    {
        if (mod->info.internal || !mod->IsEnabled()) continue;
        const auto levelobjs = mod->info.basePath / "data" / "levelobjs";
        auto i = 5;
        while (exists(levelobjs / std::format("ground{}.tga", i + 1)) || exists(
            levelobjs / std::format("_a_ground{}.jpg", i + 1)))
        {
            Log::Info << (levelobjs / std::format("ground{}.tga", i + 1)).string() << Log::Endl;
            i++;
        }

        grounds = std::max(grounds, i);
    }

    if (buffer != nullptr) free(buffer);
    buffer = calloc(grounds, 4);
    (fillOutGrounds + 3).Put(buffer);
    (readGrounds + 3).Put(buffer);
    (fillOutLimit + 3).Put((char)grounds);
    (readLimit + 3).Put((char)grounds);

    return load_ground_textures_orig();
}

HOOK_FN_CONV(inline uintptr_t, create_object, ARGS(int gameobjIndex), __cdecl)
{
    auto resultingObject = create_object_orig(gameobjIndex);
    std::string name = reinterpret_cast<const char*>(resultingObject + 0x4);
    if (name.starts_with("ground"))
    {
        auto index = 0;
        try
        {
            index = std::stoi(name.substr(6));
        }
        catch (...)
        {
        }

        *reinterpret_cast<uint32_t*>(resultingObject + 0xEC) = index - 1;
    }
    return resultingObject;
}

inline int write_ground_to_level(FILE* ptr, const char* pat, char value)
{
    return printMethod.Call<int>(ptr, "%c", value + '0');
}

inline EventManager::Ready $load_grounds_patch([]
{
    static constexpr Memory::Pattern fillOutPat("89 04 8D ? ? ? ? EB ? 68 ? ? ? ? FF 15 ? ? ? ? 68");
    fillOutGrounds = fillOutPat.Search();
    static constexpr Memory::Pattern readPat("8B 04 95 ? ? ? ? 50 E8 ? ? ? ? 83 C4 ? 8B 4D 98");
    readGrounds = readPat.Search();
    static constexpr Memory::Pattern fillOutLimitPat("83 7D D8 ? 7D ? 8B 4D D8 83 C1");
    fillOutLimit = fillOutLimitPat.Search();
    static constexpr Memory::Pattern readLimitPat("83 7D F8 ? 7C ? C7 45 F8");
    readLimit = readLimitPat.Search();
    static constexpr Memory::Pattern reloadTexPat(
        "55 8B EC 83 EC ? A1 ? ? ? ? 89 45 FC 68 ? ? ? ? FF 15 ? ? ? ? C7 45 D8");
    reloadGrounds = reloadTexPat.Search();
    static constexpr Memory::Pattern printMethodPat("55 8B EC 56 57 FF 75 ? E8 ? ? ? ? 8B F0");
    printMethod = printMethodPat.Search();

    EventManager::On<ModLoadEvent>([] { reloadGrounds.Call(); });
    EventManager::On<ModUnloadEvent>([] { reloadGrounds.Call(); });

    HookManager::RegisterHook(reloadGrounds, HOOK_REF(load_ground_textures));
    HookManager::RegisterHook("55 8B EC 6A ? 68 ? ? ? ? 64 A1 ? ? ? ? 50 64 89 25 ? ? ? ? 81 EC ? ? ? ? 8B 45",
                              HOOK_REF(create_object));

    static constexpr Memory::Pattern writeGroundDigit("E8 ? ? ? ? 83 C4 ? EB ? 68 ? ? ? ? 8B 8D");
    writeGroundDigit.Search().NearCall(write_ground_to_level);
});
