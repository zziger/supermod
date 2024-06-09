#include <supermod/pch.hpp>
#include <supermod/ui/widgets/widgets.hpp>

#include <imgui_internal.h>
#include <supermod/Utils.hpp>
#include <supermod/modloader/mod/states/ModState.hpp>
#include <supermod/ui/Ui.hpp>

bool ui::widgets::mods::Selectable(const std::shared_ptr<modloader::Mod>& mod, bool selected, bool border,
                                   const std::optional<modloader::ModInfo::Dependency>& dependency, bool* hovered,
                                   bool* active)
{
    const auto info = mod->GetInfo();

    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(6, 6) * Ui::GetScalingFactor());
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(6, 4) * Ui::GetScalingFactor());

    ImGui::PushID(info->GetID().c_str());

    const auto frameStart = ImGui::GetCursorScreenPos();
    const auto frameSize = ImVec2{0, 50 * Ui::GetScalingFactor()};

    const auto val =
        ImGui::Selectable("", selected, ImGuiSelectableFlags_NoPadWithHalfSpacing, {0, 50 * Ui::GetScalingFactor()});
    if (active)
        *active = ImGui::IsItemActive();
    if (hovered)
        *hovered = ImGui::IsItemHovered();

    if (ImGui::BeginPopupContextItem())
    {
        ContextMenu(mod);
        ImGui::EndPopup();
    }

    ImGui::SetCursorScreenPos(frameStart);

    // TODO: tooltips
    ImGui::BeginChild("Mod frame", ImGui::GetItemRectSize(),
                      ImGuiChildFlags_AlwaysUseWindowPadding | (border ? ImGuiChildFlags_Border : 0),
                      ImGuiWindowFlags_NoInputs);
    {
        const auto childStart = ImGui::GetCursorScreenPos();
        const auto drawList = ImGui::GetWindowDrawList();
        auto limitX = childStart.x + ImGui::GetContentRegionAvail().x;
        const auto mismatchedDependency = dependency && !dependency->version.Match(mod->GetInfo()->version);

        if (!mod->HasFlag(modloader::Mod::Flag::INTERNAL))
        {
            ImGui::BeginGroup();
            {
                Ui::PushFont(20);

                // Slider
                {
                    const auto sliderSize = ImVec2(20, 10) * Ui::GetScalingFactor();
                    limitX -= sliderSize.x;
                    ImGui::SetCursorScreenPos({limitX, (frameSize.y - sliderSize.y) / 2.f + frameStart.y});
                    widgets::ToggleButton(
                        "Status", mod->IsEnabled(),
                        static_cast<float>(
                            duration_cast<std::chrono::milliseconds>(mod->GetTimeSinceUpdate()).count()) /
                            1000.f,
                        sliderSize);

                    limitX -= 6 * Ui::GetScalingFactor();
                }

                // Status icon
                const auto hidden =
                    (mod->IsEnabled() && mod->GetState()->GetType() == modloader::ModState::Type::ENABLED) ||
                    (!mod->IsEnabled() && mod->GetState()->GetType() == modloader::ModState::Type::DISABLED);
                if (!hidden)
                {
                    const auto icon = mod->GetState()->GetIcon();
                    const auto iconSize = ImGui::CalcTextSize(icon.c_str());
                    limitX -= iconSize.x;
                    ImGui::SetCursorScreenPos({limitX, frameStart.y + (frameSize.y - iconSize.y) / 2.f});
                    ImGui::TextColored(mod->GetState()->GetColor(), "%s", icon.c_str());

                    limitX -= 3 * Ui::GetScalingFactor();
                }

                // Removal pending icon
                if (mod->HasFlag(modloader::Mod::Flag::REMOVAL_SCHEDULED))
                {
                    const auto icon = ICON_MD_DELETE;
                    const auto iconSize = ImGui::CalcTextSize(icon);
                    limitX -= iconSize.x;
                    ImGui::SetCursorScreenPos({limitX, frameStart.y + (frameSize.y - iconSize.y) / 2.f});
                    ImGui::TextColored(0xEE7777FF_color, "%s", icon);

                    limitX -= 3 * Ui::GetScalingFactor();
                }

                // Mod error icon
                if (!mod->GetLoadingError().empty())
                {
                    const auto icon = ICON_MD_ERROR;
                    const auto iconSize = ImGui::CalcTextSize(icon);
                    limitX -= iconSize.x;
                    ImGui::SetCursorScreenPos({limitX, frameStart.y + (frameSize.y - iconSize.y) / 2.f});
                    ImGui::TextColored(0xEE7777FF_color, "%s", icon);

                    limitX -= 3 * Ui::GetScalingFactor();
                }

                // Mod mismatched dependency
                if (mismatchedDependency)
                {
                    const auto icon = ICON_MD_WARNING;
                    const auto iconSize = ImGui::CalcTextSize(icon);
                    limitX -= iconSize.x;
                    ImGui::SetCursorScreenPos({limitX, frameStart.y + (frameSize.y - iconSize.y) / 2.f});
                    ImGui::TextColored(0xeebe77FF_color, "%s", icon);

                    limitX -= 3 * Ui::GetScalingFactor();
                }

                Ui::PopFont();
            }
            ImGui::EndGroup();
        }

        // Mod icon
        ImGui::SetCursorScreenPos(childStart);
        ImGui::Dummy({Ui::ScaledPx(38), Ui::ScaledPx(38)});
        ImGui::GetWindowDrawList()->AddRectFilled(ImGui::GetItemRectMin(), ImGui::GetItemRectMax(), 0x22FFFFFF);
        if (info->icon)
            info->icon->Draw(ImGui::GetWindowDrawList(), ImGui::GetItemRectMin(), ImGui::GetItemRectMax(), 0xFFFFFFFF);
        ImGui::SameLine(0, Ui::ScaledPx(10));

        ImGui::BeginGroup();
        {
            auto versionStr = info->version.str();
            if (mismatchedDependency)
            {
                versionStr += " (требуется " + dependency->version.Serialize(true) + ")";
            }

            const auto lowerLine = ::utils::trim(versionStr + " " + info->author);
            if (lowerLine.empty())
                ImGui::Dummy({Ui::ScaledPx(1), Ui::ScaledPx(6)});

            // Mod label
            Ui::PushFont(18);
            {
                const auto lh = ImGui::GetTextLineHeight();
                const auto min = ImGui::GetCursorScreenPos();
                const auto max = ImVec2(limitX, min.y + lh * 1.5f);
                ImGui::RenderTextEllipsis(drawList, min, max, max.x, max.x, info->title.c_str(), nullptr, nullptr);
                ImGui::Text("");
                Tooltip(info->title.c_str(), ImGuiHoveredFlags_DelayNormal);
            }
            Ui::PopFont();

            // Mod version and author
            if (!lowerLine.empty())
            {
                Ui::PushFont(16);
                {
                    const auto lh = ImGui::GetTextLineHeight();
                    const auto min = ImGui::GetCursorScreenPos();
                    const auto max = ImVec2(limitX, min.y + lh * 1.5f);
                    ImGui::RenderTextEllipsis(drawList, min, max, max.x, max.x, lowerLine.c_str(), nullptr, nullptr);
                    ImGui::Text(" ");
                    widgets::Tooltip(lowerLine.c_str(), ImGuiHoveredFlags_DelayNormal);
                }
                Ui::PopFont();
            }
        }
        ImGui::EndGroup();
    }
    ImGui::EndChild();

    ImGui::PopID();
    ImGui::PopStyleVar(2);

    return val;
}