#include <imgui_internal.h>
#include <supermod/pch.hpp>
#include <supermod/ui/windows/windows.hpp>

#include <supermod/game/Game.hpp>
#include <supermod/modloader/ModManager.hpp>
#include <supermod/modloader/install/ModInstaller.hpp>
#include <supermod/ui/Ui.hpp>
#include <supermod/ui/styles/styles.hpp>
#include <supermod/ui/widgets/widgets.hpp>

void sm::ui::windows::Installer()
{
    static bool installerOpen = false;

    if (!modloader::ModInstaller::IsInstallerActive())
    {
        installerOpen = false;
        return;
    }

    const bool firstFrame = installerOpen == false;
    installerOpen = true;

    ImVec2 viewportCenter = ImGui::GetMainViewport()->GetCenter();
    auto& style = ImGui::GetStyle();

    if (modloader::ModInstaller::IsInstalling())
    {

        ImGui::SetNextWindowSize(ImVec2{600, 0}, ImGuiCond_Appearing);
        if (ImGui::Begin("Установка модов", nullptr,
                         ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize))
        {
            ImGui::Spacing();
            auto idx = modloader::ModInstaller::GetCurrentInstallingRequestIndex();
            auto count = modloader::ModInstaller::GetCandidateRequests().size();
            widgets::ProgressBar(static_cast<float>(idx) / static_cast<float>(count), ImVec2(-FLT_MIN, 0),
                                 std::format("{} / {}", idx, count).c_str());

            ImGui::Spacing();
            auto req = modloader::ModInstaller::GetCurrentInstallingRequest();
            if (req != nullptr)
            {
                auto source = req->GetActiveSource();
                ImGui::Text("Установка мода %s...", req->GetModInfo()->title);
                const auto message = source->GetInstallMessage();
                if (message)
                    ImGui::Text("%s", message->c_str());
                ImGui::Spacing();

                auto progress = source->GetInstallProgress();
                if (progress < 0)
                    progress = static_cast<float>(ImGui::GetTime()) * -0.5f;
                widgets::ProgressBar(source->GetInstallProgress(), ImVec2(-FLT_MIN, 0));

                ImGui::Spacing();
                ImGui::Spacing();
            }
            ImGui::Button("Отмена");
        }
        ImGui::End();
    }
    else
    {
        ImGui::SetNextWindowSize(ImVec2{795, 595}, ImGuiCond_Appearing);
        ImGui::SetNextWindowPos(viewportCenter, ImGuiCond_Appearing, ImVec2{0.5f, 0.5f});
        ImGui::SetNextWindowSizeConstraints(ImVec2{760, 500}, ImVec2{FLT_MAX, FLT_MAX});
        if (ImGui::Begin("Установка модов", nullptr, ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse))
        {
            static int activeMod = 0;
            if (firstFrame)
                activeMod = 0;

            auto& requests = modloader::ModInstaller::GetCandidateRequests();
            const int numRequests = static_cast<int>(requests.size());
            const int minIndex = modloader::ModInstaller::providerErrors.empty() ? 0 : -1;

            if (activeMod >= numRequests || activeMod < minIndex)
                activeMod = minIndex;

            ImVec2 buttonSize(130.f, 0.f);
            auto rightColumnWidthNeeded = buttonSize.x * 3 + style.ItemSpacing.x * 4;
            ImGui::SetNextWindowSizeConstraints(
                ImVec2{300, 0}, ImVec2{ImGui::GetContentRegionAvail().x - rightColumnWidthNeeded, FLT_MAX});
            ImGui::BeginChild("mod list", ImVec2(300, 0), ImGuiChildFlags_Border | ImGuiChildFlags_ResizeX,
                              ImGuiWindowFlags_NoSavedSettings);
            {
                if (minIndex <= -1)
                {
                    ImGui::PushStyleVar(ImGuiStyleVar_SelectableTextAlign, ImVec2(0.5f, 0.5f));
                    if (ImGui::Selectable(ICON_MD_WARNING " Ошибки установки", activeMod == -1,
                                          ImGuiSelectableFlags_NoPadWithHalfSpacing, {0, 50 * Ui::GetScalingFactor()}))
                    {
                        activeMod = -1;
                    }
                    ImGui::PopStyleVar();
                }

                for (int i = 0; i < numRequests; i++)
                {
                    auto& mod = requests[i];
                    if (!mod->IsCandidate())
                        continue;
                    if (widgets::mods::Selectable(nullptr, mod->GetModInfo(), activeMod == i))
                    {
                        activeMod = i;
                    }
                }
            }
            ImGui::EndChild();

            ImGui::SameLine();
            ImGui::BeginGroup();
            ImGui::BeginChild("mod info", ImVec2(0, -ImGui::GetFrameHeightWithSpacing()));
            if (activeMod >= 0 && activeMod < numRequests)
            {
                auto& request = requests[activeMod];
                auto modInfo = request->GetModInfo();
                widgets::mods::InfoBlock(*modInfo);
                ImGui::Spacing();
                ImGui::Separator();
                ImGui::Spacing();

                if (request->sources.empty())
                {
                    styles::warning::PanelText("Мод требуется другими модами, но не был найден в доступных источниках");
                }
                else
                {
                    ImGui::Text("Выберите источник:");
                    if (ImGui::RadioButton("Не устанавливать", &request->activeSource,
                                           modloader::ModInstallRequest::DONT_INSTALL))
                    {
                        modloader::ModInstaller::UpdateCandidates();
                    }
                    for (int i = 0; i < request->sources.size(); i++)
                    {
                        auto& source = request->sources[i];
                        if (ImGui::RadioButton(source->GetLabel().c_str(), &request->activeSource, i))
                        {
                            modloader::ModInstaller::UpdateCandidates();
                        }
                    }
                }

                ImGui::Spacing();
                ImGui::Separator();
                ImGui::Spacing();

                if (widgets::mods::Description(*modInfo))
                    ImGui::Spacing();

                if (!request->requiredBy.empty())
                {
                    ImGui::Text("Требуется для модов:");
                    ImGui::Spacing();
                    ImGui::PushID("required for");

                    for (auto& mod : request->requiredBy)
                    {
                        auto otherRequest = modloader::ModInstaller::GetRequest(mod, false);
                        if (widgets::mods::Selectable(nullptr, otherRequest->GetModInfo(), false, true))
                        {
                            auto index = std::distance(requests.begin(), std::ranges::find(requests, otherRequest));
                            activeMod = index;
                        }
                    }
                    ImGui::PopID();
                    ImGui::Spacing();
                }
                ImGui::Spacing();
            }
            else if (activeMod == -1)
            {
                ImGui::TextWrapped("Во время поиска модов для установки произошли следующие ошибки:");
                ImGui::Spacing();
                ImGui::Spacing();
                for (auto& err : modloader::ModInstaller::providerErrors)
                {
                    styles::danger::PanelText(err.c_str());
                }
            }
            ImGui::EndChild();

            if (ImGui::Button("Отмена", buttonSize))
                modloader::ModInstaller::Reset();

            ImGui::SameLine();
            float widthNeeded = buttonSize.x + style.ItemSpacing.x + buttonSize.x;
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetContentRegionAvail().x - widthNeeded);

            ImGui::BeginDisabled(activeMod <= minIndex);
            if (ImGui::Button("Назад", buttonSize))
                activeMod--;
            ImGui::EndDisabled();

            ImGui::SameLine();

            if (activeMod >= numRequests - 1)
            {
                const auto installBtn =
                    numRequests == 0 || std::ranges::find_if(requests, [&](const auto& req) {
                                            return req->activeSource != modloader::ModInstallRequest::DONT_INSTALL;
                                        }) != requests.end();
                ImGui::BeginDisabled(numRequests == 0);
                if (ImGui::Button(installBtn ? "Установить" : "Готово", buttonSize))
                    modloader::ModInstaller::Install();
                ImGui::EndDisabled();
            }
            else
            {
                if (ImGui::Button("Далее", buttonSize))
                    activeMod++;
            }

            ImGui::EndGroup();
        }
        ImGui::End();
    }
}
