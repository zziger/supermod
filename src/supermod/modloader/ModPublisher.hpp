#pragma once

#include <supermod/modloader/mod/Mod.hpp>
#include <supermod/pch.hpp>

namespace sm::modloader
{
class ModPublisher
{
public:
    static inline std::atomic_bool publishing = false;
    static inline std::atomic<float> publishProgress = false;

    static async::task<void> Publish(const std::shared_ptr<Mod>& mod);
};
} // namespace sm::modloader