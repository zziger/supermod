#include "SoundLoader.h"

#include <game/AssetPool.h>
#include <game/SoundHost.h>
#include <modloader/files/ModFileResolver.h>
#include <spdlog/spdlog.h>

namespace modloader {
    bool SoundLoader::Load(const std::filesystem::path& path)
    {
        if (!game::SoundHost::initialized)
            return false;

        const auto filename = path.filename().generic_string();
        const auto host = game::SoundHost::GetInstance();
        auto cwd = std::filesystem::current_path();
        const auto index = host->GetSoundIndex(filename.c_str());

        const auto resolvedPath = ModFileResolver::ResolveGameFile(sdk::Game::GetDataPath() / path);
        if (resolvedPath.empty() || !exists(resolvedPath))
        {
            spdlog::warn("Sound file {} was not found", filename);
            return false;
        }

        if (index == -1) {
            spdlog::warn("Sound {} does not exist in the game", filename);
            return false;
        }

        auto& sound = host->soundPool[index];
        const auto sample = BASS_SampleLoad(0, resolvedPath.string().c_str(), 0, 0, 255, 0);

        if (!sample) {
            spdlog::error("Failed to load sound {}: BASS error {}", filename, BASS_ErrorGetCode());
            return false;
        }

        BASS_SampleFree(sound.soundSample);
        sound.soundSample = sample;

        spdlog::debug("Reloaded sound {}", filename);
        return true;
    }
}
