#include <regex>
#include <queue>
#include <modloader_new/ModManager.h>
#include <modloader_new/mod/Mod.h>

#include "DirectXUtils.h"
#include "Utils.h"
#include "../ModFileResolver.h"
#include "events/ResolveFileEvent.h"
#include "game/AssetPool.h"
#include "game/CachedFilePool.h"
#include "game/SoundHost.h"
#include "modloader/mods/ModManager.h"
#include "sdk/DirectX.h"


void ModFileResolver::LoadSound(std::filesystem::path soundPath) {
    if (!exists(soundPath)) return;
    const auto host = game::SoundHost::GetInstance();
    const auto filename = soundPath.filename().generic_string();

    if (soundPath.parent_path().filename() == "music") {
        auto cwd = std::filesystem::current_path();
        const auto index = host->GetMusicIndex(filename.c_str());

        int size = 0;
        const auto mem = utils::read_file(soundPath.string(), size);
        if (_soundMemory.contains(filename)) free(_soundMemory[filename]);
        _soundMemory[filename] = mem;
        
        const auto stream = BASS_StreamCreateFile(true, mem, 0, size, 4);

        if (!stream) {
            Log::Error << "Не удалось загрузить файл " << filename << ". Ошибка: " << BASS_ErrorGetCode() << Log::Endl;
            return;
        }
        
        if (index == -1) {
            host->musicPool[host->loadedMusic] = stream;
            filename.copy(host->loadedMusicNames[host->loadedMusic], 32);
            host->loadedMusic++;
            Log::Info << "Музыка " << filename << " перезагружена" << Log::Endl;
        } else {
            const auto old = host->musicPool[index];

            BASS_StreamFree(old);
            host->musicPool[index] = stream;
            Log::Info << "Музыка " << filename << " загружена" << Log::Endl;
        }
    } else {
        const auto index = host->GetSoundIndex(filename.c_str());
    
        if (index == -1) {
            Log::Warn << "Звук " << filename << " не найден в игре" << Log::Endl;
            return;
        }

        auto& sound = host->soundPool[index];
        const auto sample = BASS_SampleLoad(0, soundPath.string().c_str(), 0, 0, 255, 0);

        if (!sample) {
            Log::Debug << "Не удалось загрузить файл " << filename << ". Ошибка: " << BASS_ErrorGetCode() << Log::Endl;
            return;
        }
    
        BASS_SampleFree(sound.soundSample);
        sound.soundSample = sample;

        Log::Info << "Звук " << filename << " перезагружен" << Log::Endl;
    }
}

void ModFileResolver::LoadAdditionalMusic() {
    std::unordered_set<std::string> defaultMusic{};
    
    for (const auto& entry : std::filesystem::directory_iterator(sdk::Game::GetDataPath() / "audio" / "music"))
        defaultMusic.emplace(entry.path().filename().generic_string());

    for (const auto& loadedMod : modloader::ModManager::GetMods()) {
        if (loadedMod->HasFlag(modloader::Mod::Flag::INTERNAL) || !loadedMod->IsActive()) continue;
        const auto info = std::dynamic_pointer_cast<modloader::ModInfoFilesystem>(loadedMod->GetInfo());
        if (!info) continue;
        if (!exists(info->basePath / "data" / "audio" / "music")) continue;
        
        for (const auto& entry : std::filesystem::directory_iterator(info->basePath / "data" / "audio" / "music")) {
            const auto filename = entry.path().filename();
            if (defaultMusic.contains(filename.generic_string()) || filename.extension() != ".ogg") continue;

            LoadSound(entry.path());
        }
    }
}