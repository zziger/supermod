#pragma once

#include <IconsMaterialDesign.h>
#include <imgui.h>
#include <supermod/modloader/mod/Mod.hpp>
#include <supermod/modloader/mod/info/ModInfo.hpp>
#include <supermod/modloader/mod/info/ModInfoRegistry.hpp>
#include <supermod/registry/RegistryManager.hpp>

namespace sm::ui::widgets
{
void ProgressBar(float fraction, const ImVec2& sizeArg = ImVec2(-FLT_MIN, 0), const char* overlay = nullptr);
void Tooltip(const char* text, ImGuiHoveredFlags flags = ImGuiHoveredFlags_None);
void HelpMarker(const char* desc, const char* icon = ICON_MD_QUESTION_MARK);
bool ToggleButton(const char* strId, bool value, float time = -1, ImVec2 size = {-1.f, -1.f});

namespace mods
{
std::shared_ptr<modloader::Mod> Reference(
    const std::string& modId, const std::optional<modloader::ModInfo::Dependency>& dependency = std::nullopt);
bool Selectable(const std::shared_ptr<modloader::Mod>& mod, bool selected = false, bool border = false,
                const std::optional<modloader::ModInfo::Dependency>& dependency = std::nullopt, bool* hovered = nullptr,
                bool* active = nullptr);
bool SelectableRegistry(const modloader::ModInfoRegistry& info, bool selected = false);
void ContextMenu(const std::shared_ptr<modloader::Mod>& mod);
void Status(const std::shared_ptr<modloader::Mod>& mod);
void InfoBlock(const modloader::ModInfo& modInfo);
bool Description(const modloader::ModInfo& modInfo);
} // namespace mods

namespace registry
{
void Uploader(const sm::registry::RegistryManager::User& user);
} // namespace registry
} // namespace sm::ui::widgets