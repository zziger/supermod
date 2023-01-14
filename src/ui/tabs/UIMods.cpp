#include "modloader/mods/Mod.h"
#include "modloader/mods/ModManager.h"
#include "sdk/Game.h"
#include "ui/ImGuiWidgets.h"
#include "ui/UI.h"

namespace ui
{
    void UI::RenderModsTab() {
        static std::optional<std::shared_ptr<Mod>> activeMod;
    
        auto width = ImGui::GetContentRegionMax().x / 2;
        ImGui::BeginChild("mods", ImVec2(width, 0), true);

        for (const auto& loadedMod : ModManager::GetLoadedMods()) {
            if (!loadedMod) continue;
            auto info = loadedMod->info;
            if (widgets::ModSelectable(info.id.c_str(), info.title.c_str(), info.author.c_str(),
                info.version.c_str(), info.icon, activeMod && (*activeMod)->info.id == info.id, !loadedMod->IsLoaded()))
                    activeMod = loadedMod;
        }
    
        ImGui::EndChild();

        ImGui::SameLine();
        ImGui::BeginChild("modContent", ImVec2(width, 0), false);

        if (activeMod) {
            auto mod = *activeMod;
            auto info = mod->info;
            if (info.icon) {
                ImGui::Image(info.icon, { 50, 50 });
                ImGui::SameLine();
            }
        
            ImGui::BeginGroup();
            ImGui::Text("%s", info.title.c_str());
            if (info.version != "") ImGui::Text("%s", info.version.c_str());
            ImGui::EndGroup();

            if (info.author != "") ImGui::Text("Автор: %s", info.author.c_str());
        
            if (!mod->info.internal) {
                ImGui::Text("Состояние:");
        
                ImGui::SameLine();
                if (mod->IsLoaded()) ImGui::TextColored(0x77EE77FF_color, "Включен");
                else ImGui::TextColored(0xEE7777FF_color, "Выключен");

                if (!mod->info.compatible) {
                    ImGui::PushStyleColor(ImGuiCol_Text, 0xFFA000FF_color);
                    ImGui::TextWrapped("Мод не совместим с текущей версией игры!");
                    ImGui::PopStyleColor();
                }

                const auto currentVersion = sdk::Game::GetGameVersion();
                if (!mod->info.gameVersions.empty()) {
                    if (ImGui::TreeNode("Поддерживаемые версии игры:")) {
                        for (auto gameVersion : mod->info.gameVersions) {
                            ImGui::Text(sdk::Game::SerializeGameVersion(gameVersion).c_str());
                            if (currentVersion == gameVersion) {
                                ImGui::SameLine();
                                widgets::HelpMarker("Текущая версия", ICON_MD_DONE);
                            }
                        } 
                        ImGui::TreePop();   
                    }
                }

                if (ImGui::Button(mod->IsLoaded() ? "Выключить" : "Включить")) {
                    if (mod->IsLoaded()) mod->Unload(true);
                    else mod->Load(true);
                }

                ImGui::SameLine();
                if (ImGui::Button("Открыть папку")) {
                    ShellExecuteA(nullptr, "explore", mod->info.basePath.string().c_str(), nullptr, nullptr, SW_SHOWNORMAL);
                }

                widgets::styles::PushButtonDanger();
                if (ImGui::Button("Удалить")) {
                    ImGui::OpenPopup("Удаление мода");
                };
                widgets::styles::PopButtonDanger();

                if (ImGui::BeginPopupModal("Удаление мода", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
                {
                    ImGui::Text("Вы уверены, что хотите удалить мод %s?", mod->info.title);

                    ImGui::Spacing();
                    widgets::styles::PushButtonDanger();
                    if (ImGui::Button("Да, удалить")) {
                        ModManager::DeleteMod(mod);
                        activeMod = std::nullopt;
                    }
                    widgets::styles::PopButtonDanger();
                    ImGui::SetItemDefaultFocus();
    
                    ImGui::SameLine();
                    if (ImGui::Button("Отмена")) {
                        ImGui::CloseCurrentPopup();
                    }
    
                    ImGui::EndPopup();
                }
            }

            if (mod->modules.items.size() != 0) {
                ImGui::Separator();
                ImGui::Text("Модули:");
            }
            auto& modules = mod->modules.items;
            for (auto module : modules) {
                if (!module) continue;
                ImGui::PushID(module->fullId.c_str());
                auto state = module->IsLoaded();
                ImGui::Checkbox(module->name.c_str(), &state);

                if (module->desc != nullptr) {
                    ImGui::SameLine();
                    widgets::HelpMarker(module->desc);
                }
            
                if (state != module->IsLoaded()) {
                    if (state) module->Load(true);
                    else module->Unload(true);
                }

                module->RenderModuleUI();
                ImGui::PopID();
            }
        
            ImGui::Separator();
            mod->RenderUI();
        } else {
            ImGui::PushStyleVar(ImGuiStyleVar_SelectableTextAlign, ImVec2(0.5f, 0.5f));
            ImGui::Selectable("Выберите мод из\nсписка слева", false, ImGuiSelectableFlags_Disabled, ImGui::GetContentRegionAvail());
            ImGui::PopStyleVar();
        }
    
        ImGui::EndChild();
    }
}