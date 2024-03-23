#include "MusicLoader.h"

#include <events/EventManager.h>
#include <events/SoundHostInitEvent.h>
#include <game/AssetPool.h>
#include <game/SoundHost.h>
#include <modloader/files/ModFileResolver.h>

namespace modloader {
    MusicLoader::MusicLoader()
    {
        EventManager::On<SoundHostInitEvent>([this]
        {
            Log::Debug << "Sound host init" << Log::Endl;
            std::unordered_set<std::string> defaultMusic{};

            for (const auto& entry : std::filesystem::directory_iterator(sdk::Game::GetDataPath() / "audio" / "music"))
                defaultMusic.emplace(entry.path().filename().generic_string());

            for (const auto& loadedMod : ModManager::GetMods())
            {
                if (loadedMod->HasFlag(Mod::Flag::INTERNAL) || !loadedMod->IsActive()) continue;
                const auto infoFilesystem = std::dynamic_pointer_cast<ModInfoFilesystem>(loadedMod->GetInfo());
                if (!infoFilesystem) continue;
                const auto musicPath = infoFilesystem->basePath / "data" / "audio" / "music";
                if (!exists(musicPath)) continue;

                for (const auto& entry : std::filesystem::directory_iterator(musicPath)) {
                    auto filename = entry.path().filename();
                    if (defaultMusic.contains(filename.generic_string()) || filename.extension() != ".ogg") continue;

                    Load(entry.path());
                }
            }
        });
    }

    bool MusicLoader::Load(const std::filesystem::path& path)
    {
        if (path.parent_path().filename() != "music")
            return false;

        if (!game::SoundHost::initialized)
            return false;

        const auto filename = path.filename().generic_string();
        const auto host = game::SoundHost::GetInstance();
        auto cwd = std::filesystem::current_path();
        const auto index = host->GetMusicIndex(filename.c_str());

        const auto resolvedPath = ModFileResolver::ResolveGameFile(sdk::Game::GetDataPath() / path);
        if (resolvedPath.empty() || !exists(resolvedPath))
        {
            if (soundMemory.contains(filename)) free(soundMemory[filename]);
            if (index != -1) host->RemoveMusic(index);
            Log::Info << "Музыка " << filename << " выгружена" << Log::Endl;
            return true;
        }

        int size = 0;
        const auto mem = utils::read_file(resolvedPath.string(), size);
        if (soundMemory.contains(filename)) free(soundMemory[filename]);
        soundMemory[filename] = mem;

        const auto stream = BASS_StreamCreateFile(true, mem, 0, size, 4);

        if (!stream) {
            free(soundMemory[filename]);
            soundMemory.erase(filename);
            Log::Error << "Не удалось загрузить файл " << filename << ". Ошибка: " << BASS_ErrorGetCode() << Log::Endl;
            return true;
        }

        if (index == -1) {
            host->LoadMusic(filename, stream);
            Log::Info << "Музыка " << filename << " загружена" << Log::Endl;
        } else {
            host->ReplaceMusic(index, stream);
            Log::Info << "Музыка " << filename << " перезагружена" << Log::Endl;
        }

        return true;
    }
}
