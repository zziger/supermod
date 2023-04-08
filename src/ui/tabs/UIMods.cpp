#include <imgui_internal.h>

#include "events/TickEvent.h"
#include "modloader/mods/Mod.h"
#include "modloader/mods/ModManager.h"
#include "sdk/Game.h"
#include "ui/ImGuiWidgets.h"
#include "ui/UI.h"

namespace ui
{
    void UI::RenderModsTab() {
        static std::optional<std::shared_ptr<Mod>> activeMod;
        static bool reorder = false;
        static std::vector<std::shared_ptr<Mod>> reorderMods {};
    
        const auto width = ImGui::GetContentRegionMax().x / 2;
        ImGui::BeginChild("left block", ImVec2(width, 0), false);
        {
            const auto listHeight = ImGui::GetContentRegionMax().y - ImGui::GetFrameHeightWithSpacing();
            ImGui::BeginChild("mods", ImVec2(width, listHeight), true);

            if (!reorder) {
                for (const auto& loadedMod : ModManager::GetMods()) {
                    if (!loadedMod) continue;
                    auto& info = loadedMod->info;
                    info.EnsureIcon();
                    if (widgets::ModSelectable(info.id.c_str(), info.title.c_str(), info.author.c_str(),
                        info.version.c_str(), info.icon, activeMod && (*activeMod)->info.id == info.id, !loadedMod->IsEnabled()))
                            activeMod = loadedMod;
                }
            } else {
                const auto count = reorderMods.size();
                for (auto i = 0; i < count; i++) {
                    const auto loadedMod = reorderMods[i];
                    auto& info = loadedMod->info;
                    info.EnsureIcon();
                    bool hovered, active;
                    widgets::ModSelectable(info.id.c_str(), info.title.c_str(), info.author.c_str(),
                        info.version.c_str(), info.icon, false, !loadedMod->IsEnabled(), &hovered, &active);

                    if (active && !hovered) {
                        const auto dragY = ImGui::GetMouseDragDelta(0).y;
                        if (dragY < 5 && dragY > -5) continue;
                        const int nextI = i + (dragY < 0.f ? -1 : 1);
                        if (nextI < 0 || nextI >= count) continue;
                        std::swap(reorderMods[i], reorderMods[nextI]);
                        ImGui::ResetMouseDragDelta();
                    }
                }
            }
    
            ImGui::EndChild();

            if (!reorder) {
                if (ImGui::Button(ICON_MD_REORDER " Изменить порядок")) {
                    reorderMods.clear();
                    for (auto mod : ModManager::GetMods()) if (!mod->info.internal) reorderMods.push_back(mod);
                    
                    reorder = true;
                    activeMod = std::nullopt;
                }

                ImGui::SameLine();
                ImGui::BeginDisabled(sdk::Game::currentTickIsInner);
                if (ImGui::Button(ICON_MD_REFRESH)) {
                    ModManager::ReloadMods();
                    activeMod = std::nullopt;
                }
                if (ImGui::IsItemHovered(ImGuiHoveredFlags_DelayShort))
                {
                    ImGui::BeginTooltip();
                    ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
                    ImGui::TextUnformatted("Перезагрузить все моды");
                    ImGui::PopTextWrapPos();
                    ImGui::EndTooltip();
                }
                ImGui::EndDisabled();
            } else {
                ImGui::BeginDisabled(sdk::Game::currentTickIsInner);
                if (ImGui::Button(ICON_MD_SAVE " Сохранить")) {
                    ModManager::ReorderMods(reorderMods);
                    reorder = false;
                }
                ImGui::EndDisabled();
                ImGui::SameLine();
                if (ImGui::Button(ICON_MD_CANCEL " Отмена")) reorder = false;
                ImGui::SameLine();
                widgets::HelpMarker("Перетащите моды мышкой для изменения порядка загрузки");
            }
        }
        ImGui::EndChild();

        ImGui::SameLine();
        ImGui::BeginChild("modContent", ImVec2(width, 0), false);

        if (activeMod && !reorder) {
            auto mod = *activeMod;
            auto& info = mod->info;
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
                if (mod->IsEnabled()) ImGui::TextColored(0x77EE77FF_color, ICON_MD_CHECK_CIRCLE " Включен");
                else ImGui::TextColored(0xEE7777FF_color, ICON_MD_RADIO_BUTTON_UNCHECKED " Выключен");

                if (!mod->info.compatible) {
                    ImGui::PushStyleColor(ImGuiCol_Text, 0xFFA000FF_color);
                    ImGui::TextWrapped(ICON_MD_WARNING " Текущая версия игры не поддерживается");
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

                if (mod->incompatibleSdk) {
                    ImGui::PushStyleColor(ImGuiCol_Text, 0xEE7777FF_color);
                    ImGui::TextWrapped(std::format(ICON_MD_ERROR " Нужен SuperMod {} или новее", mod->info.sdkVersion.to_string()).c_str());
                    ImGui::PopStyleColor();
                }
                
                if (mod->loadingError) {
                    ImGui::PushStyleColor(ImGuiCol_Text, 0xEE7777FF_color);
                    ImGui::TextWrapped((ICON_MD_ERROR " " + *mod->loadingError).c_str());
                    ImGui::PopStyleColor();
                }

                ImGui::Spacing();
                ImGui::BeginDisabled(mod->incompatibleSdk || sdk::Game::currentTickIsInner);

                if (ImGui::Button(mod->IsEnabled() ? ICON_MD_POWER_SETTINGS_NEW " Выключить" : ICON_MD_POWER_SETTINGS_NEW " Включить")) {
                    if (mod->IsEnabled()) mod->Disable(true);
                    else mod->Enable(true);
                }

                ImGui::SameLine();
                if (ImGui::Button(ICON_MD_REFRESH)) {
                    mod->Reload();
                }
                if (ImGui::IsItemHovered(ImGuiHoveredFlags_DelayShort))
                {
                    ImGui::BeginTooltip();
                    ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
                    ImGui::TextUnformatted("Перезагрузить");
                    ImGui::PopTextWrapPos();
                    ImGui::EndTooltip();
                }

                widgets::styles::PushButtonDanger();
                if (ImGui::Button(ICON_MD_DELETE " Удалить")) {
                    ImGui::OpenPopup("Удаление мода");
                };
                widgets::styles::PopButtonDanger();
                ImGui::EndDisabled();
                ImGui::SameLine();
                if (ImGui::Button(ICON_MD_FOLDER_OPEN " Открыть папку")) {
                    ShellExecuteW(nullptr, L"explore", mod->info.basePath.wstring().c_str(), nullptr, nullptr, SW_SHOWNORMAL);
                }

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

        ImGui::ErrorCheckEndWindowRecover([](void*, const char* format, ...) {
            va_list va;
            va_start(va, format);
            char buffer[1024];
            vsprintf_s(buffer, 1024, format, va);
            Log::Warn << "Ошибка стека ImGui при отрисовке информации о моде:\n\t" << buffer << Log::Endl;
        }, nullptr);
        ImGui::EndChild();
    }
}