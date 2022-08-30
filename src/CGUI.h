#pragma once
#include <imgui_internal.h>
#include <backends/imgui_impl_win32.h>
#include <imgui-dx8/imgui_impl_dx8.h>

#include "CGameApis.h"
#include "Utils.h"
#include "Log.h"
#include "CMemory.h"
#include "CModuleManager.h"
#include "imgui/imgui.h"

class CGUI {
public:
    static inline bool initialized = false;
    static inline bool menuOpen = false;
    static inline bool showWatermark = false;
    
    static void Initalize() {
        if (initialized) return;
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\Arial.ttf", 18);
        ImFontConfig cfg;
        cfg.MergeMode = true;
        io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\Arial.ttf", 18, &cfg, io.Fonts->GetGlyphRangesCyrillic());
        ImGui::StyleColorsDark();
        ImGui_ImplWin32_Init(*CGameApis::window);
        ImGui_ImplDX8_Init(*CGameApis::d3dDevice);
        initialized = true;
    }

    static void Render() {
        if (!initialized) return;
        // std::cout << "sus" << std::endl;
        ImGuiIO& io = ImGui::GetIO();
        ImGui_ImplDX8_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();
        if (showWatermark) {
            ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
            ImGui::SetNextWindowBgAlpha(0.2f);
            ImGui::SetNextWindowPos({ io.DisplaySize.x * 0.5f, 0 }, ImGuiCond_Always, { 0.5f, 0 });
            ImGui::Begin("watermark", nullptr, ImGuiWindowFlags_NoTitleBar|ImGuiWindowFlags_NoResize|ImGuiWindowFlags_NoMove|ImGuiWindowFlags_NoScrollbar|ImGuiWindowFlags_NoSavedSettings|ImGuiWindowFlags_NoInputs);
            ImGui::SetWindowFontScale(0.8f);
            std::stringstream ss;
            ss << "SuperMod " << VERSION << " " << CModuleManager::CountLoadedMods() << " mods " << CModuleManager::CountLoadedPatches() << " patches";
            ImGui::Text(ss.str().c_str());
            ImGui::End();
            // ImGui::PopStyleVar(ImGuiStyleVar_WindowBorderSize);
        }
        if (menuOpen) {
            ImGui::Begin("Настройки");
            ImGui::Checkbox("Отображать водяной знак", &showWatermark);
            ImGui::End();
        }
        ImGui::EndFrame();

        const auto d3dDevice = *CGameApis::d3dDevice;
        if (d3dDevice->BeginScene() >= 0)
        {
            ImGui::Render();
            ImGui_ImplDX8_RenderDrawData(ImGui::GetDrawData());
            d3dDevice->EndScene();
        }
    }
};
