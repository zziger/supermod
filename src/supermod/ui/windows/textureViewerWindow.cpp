#include <supermod/pch.hpp>
#include <supermod/ui/windows/windows.hpp>

#include <imgui.h>
#include <imgui_internal.h>
#include <supermod/game/AssetPool.hpp>
#include <supermod/ui/Ui.hpp>

void ui::windows::TextureViewer()
{
    static auto pool = game::AssetPool::Instance();
    const auto& io = ImGui::GetIO();

    Ui::ConstraintWindow("###Texture viewer");
    if (ImGui::Begin("Просмотр текстур###Texture viewer", &Ui::textureViewerOpen))
    {
        static char searchBuf[128] = "";
        ImGui::InputTextEx("##search", "Поиск", searchBuf, IM_ARRAYSIZE(searchBuf), {-1.f, 0.f}, 0);
        ImGui::Separator();
        ImGui::Spacing();

        for (auto i = 0; i < pool->assetCount; i++)
        {
            const auto asset = pool->assets[i];

            if (searchBuf[0] != '\0' && std::string(asset->name).find(searchBuf) == std::string::npos)
                continue;

            if (ImGui::TreeNode(asset->name, "%s (%dx%d)", asset->name, asset->width, asset->height))
            {
                const ImVec2 pos = ImGui::GetCursorScreenPos();
                const auto aspectRatio = static_cast<float>(asset->height) / static_cast<float>(asset->width);
                const auto width = std::min(ImGui::GetContentRegionAvail().x - ImGui::GetCursorPosX(),
                                            static_cast<float>(asset->width));
                auto texSize = ImVec2(width, aspectRatio * width);
                ImGui::Image(asset->texture, texSize, {0, 0}, {1, 1}, 0xFFFFFFFF_color, 0xFFFFFFAA_color);

                // Mangifier tooltip
                if (ImGui::IsItemHovered())
                {
                    ImGui::BeginTooltip();
                    constexpr float regionSz = 64.0f;
                    constexpr float zoom = 2.0f;
                    auto off = regionSz * 0.5f;
                    const auto x = std::clamp(io.MousePos.x - pos.x, off, texSize.x - off);
                    const auto y = std::clamp(io.MousePos.y - pos.y, off, texSize.y - off);
                    ImGui::Text(
                        "X: %d Y: %d",
                        static_cast<int>((io.MousePos.x - pos.x) / texSize.x * static_cast<float>(asset->width)),
                        static_cast<int>((io.MousePos.y - pos.y) / texSize.y * static_cast<float>(asset->height)));
                    ImVec2 uv0{(x - off) / texSize.x, (y - off) / texSize.y};
                    ImVec2 uv1{(x + off) / texSize.x, (y + off) / texSize.y};

                    if (static_cast<float>(asset->width) < regionSz)
                    {
                        uv0 = {0, uv0.y};
                        uv1 = {1, uv1.y};
                    }

                    if (static_cast<float>(asset->height) < regionSz)
                    {
                        uv0 = {uv0.x, 0};
                        uv1 = {uv1.x, 1};
                    }

                    ImGui::Image(asset->texture, ImVec2(regionSz * zoom, regionSz * zoom), uv0, uv1);
                    ImGui::EndTooltip();
                }

                if (ImGui::TreeNode("Доп. информация"))
                {
                    if (ImGui::BeginTable("info", 2, ImGuiTableFlags_RowBg | ImGuiTableFlags_Borders))
                    {
                        ImGui::TableSetupColumn("Параметр");
                        ImGui::TableSetupColumn("Значение");
                        ImGui::TableHeadersRow();

                        std::map<std::string, std::string> data{
                            {"Прозрачная", asset->hasAlpha ? "да" : "нет"},
                            {"Пул", asset->isPoolDefault ? "D3DPOOL_DEFAULT" : "D3DPOOL_MANAGED"},
                            {"Формат",
                             asset->format == D3DFMT_A8R8G8B8 ? "D3DFMT_A8R8G8B8" : std::to_string(asset->format)},
                            {"Не найдена", asset->meta->notFound ? "да" : "нет"},
                            {"Загружена вручную", asset->meta->loadedManually ? "да" : "нет"},
                            {"Ориг название", asset->meta->origName},
                            {"Ориг путь", asset->meta->origDir.string()},
                            {"Модификатор размера", std::to_string(asset->meta->canvasSizeMultiplier.x) + " " +
                                                        std::to_string(asset->meta->canvasSizeMultiplier.y)},
                        };

                        for (auto& row : data)
                        {
                            ImGui::TableNextRow();
                            ImGui::TableNextColumn();
                            ImGui::Text("%s", row.first.c_str());
                            ImGui::TableNextColumn();
                            ImGui::Text("%s", row.second.c_str());
                        }

                        ImGui::EndTable();
                    }

                    ImGui::TreePop();
                }

                ImGui::TreePop();
            }
        }
    }
    ImGui::End();
}