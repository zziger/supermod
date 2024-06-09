#include "Utils.h"
#include "events/EventManager.h"
#include "game/SoundHost.h"
#include "memory/HookManager.h"
#include "sdk/Game.h"
#include <fstream>
#include <spdlog/spdlog.h>

const char* (*parse_level_string)(char* a1, const char* str, const char* substr) = nullptr;

HOOK_FN_CONV(inline int, parse_level_int, ARGS(const char* content, const char* key), __cdecl)
{
    if (key == std::string("curlevelmusic="))
    {
        char musicName[128];
        parse_level_string(musicName, content, "curlevelmusicname=");
        auto index = game::SoundHost::GetInstance()->GetMusicIndex(musicName);
        if (index != -1)
        {
            spdlog::debug("Level music was overwritten with {} at index {}", musicName, index);
            return index;
        }
    }

    return parse_level_int_orig(content, key);
}

inline char(__thiscall* editor_write_level_file_orig)(void* this_, int stage, int levelIndex) = nullptr;
char __fastcall editor_write_level_file(void* this_, void*, int stage, int levelIndex)
{
    const auto res = editor_write_level_file_orig(this_, stage, levelIndex);
    const auto path =
        sdk::Game::GetDataPath() / "levels" / std::to_string(stage + 1) / std::format("level{:02}.lev", levelIndex + 1);

    std::stringstream buf;
    std::fstream file(path, std::fstream::in);

    if (!file.is_open())
    {
        spdlog::error("Failed to open file {} for writing from level editor", path.string());
        return res;
    }

    std::string line;
    while (std::getline(file, line))
    {
        buf << line << std::endl;

        if (line.rfind("curlevelmusic=", 0) == 0)
        {
            auto index = std::stoi(line.substr(14));
            auto host = game::SoundHost::GetInstance();
            if (index < 0 || index >= host->loadedMusic)
                continue;
            buf << "curlevelmusicname=" << host->loadedMusicNames[index] << std::endl;
        }
    }
    file.close();

    file.open(path, std::fstream::out);
    file << buf.str();
    file.close();
    return res;
}

inline EventManager::Ready $level_music_patch([] {
    static constexpr Memory::Pattern pat(
        "55 8B EC 83 EC ? 8B 45 ? 50 8B 4D ? 51 E8 ? ? ? ? 83 C4 ? 89 45 ? 83 7D ? ? 75 ? 8B 55 ? C6 02 ? EB ? 8B 45 ? "
        "50 E8 ? ? ? ? 83 C4 ? 03 45 ? 89 45 ? 8B 4D ? 89 4D ? 8B 55 ? 0F BE 02 83 F8 ? 74");
    parse_level_string = pat.Search().Get<const char* (*)(char* a1, const char* str, const char* substr)>();
    HookManager::RegisterHook("55 8B EC 83 EC ? A1 ? ? ? ? 89 45 ? 8B 45 ? 50 8B 4D ? 51 8D 55 ? 52 E8 ? ? ? ? 83 C4 ? "
                              "0F BE 45 ? 85 C0 75 ? 33 C0",
                              HOOK_REF(parse_level_int));
    HookManager::RegisterHook("55 8B EC 81 EC ? ? ? ? A1 ? ? ? ? 89 45 ? 89 8D ? ? ? ? 8B 45 ? 83 C0 ? 50 68 ? ? ? ? "
                              "8D 8D ? ? ? ? 51 E8 ? ? ? ? 83 C4 ? 68 ? ? ? ? FF 15 ? ? ? ? 8B 55 ? 83 C2 ? 52 68 ? ? "
                              "? ? 8D 85 ? ? ? ? 50 E8 ? ? ? ? 83 C4 ? 8D 8D ? ? ? ? 51 FF 15 ? ? ? ? 85 C0",
                              HOOK_REF_FORCE(editor_write_level_file));
});
