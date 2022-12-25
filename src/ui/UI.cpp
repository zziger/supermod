#include "UI.h"
#include "events/EventManager.h"
#include "events/GameLoadedEvent.h"
#include "events/TickEvent.h"
#include "events/WindowEvent.h"
#include <imgui/imgui_internal.h>
#include <imgui/backends/imgui_impl_win32.h>
#include <imgui-dx8/imgui_impl_dx8.h>
#include "CGameApis.h"
#include "Config.h"
#include "Utils.h"
#include "Log.h"
#include "Memory.h"
#include "events/EventManager.h"
#include "thirdparty/IconsMaterialDesign.h"
#include "events/UIRenderEvent.h"

using namespace ui;


void UI::LoadFonts(const ImGuiIO& io) {
    fonts = new UIFonts(io);
}

void UI::InitImGui() {
    if (initialized) return;
        
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();
        
    ImGuiIO& io = ImGui::GetIO();
        
    LoadFonts(io);
    io.ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;
        
    ImGui_ImplWin32_Init(*CGameApis::window);
    ImGui_ImplDX8_Init(*CGameApis::d3dDevice);
        
    initialized = true;
}

void UI::Render() {
    if (!initialized) return;
    ImGuiIO& io = ImGui::GetIO();

    if (menuOpen && !CGameApis::cursorState) io.ConfigFlags &= ~ImGuiConfigFlags_NoMouseCursorChange;
    else io.ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;
        
    if (ImGui::IsKeyPressed(ImGuiKey_GraveAccent, false))
        menuOpen = !menuOpen;

    ImGui_ImplDX8_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();
        
    RenderWatermark();
    RenderMenu();

    EventManager::Emit(UiRenderEvent());
        
    ImGui::EndFrame();

    const auto d3dDevice = *CGameApis::d3dDevice;
    if (d3dDevice->BeginScene() >= 0)
    {
        ImGui::Render();
        ImGui_ImplDX8_RenderDrawData(ImGui::GetDrawData());
        d3dDevice->EndScene();
    }
}

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
void UI::OnWindowEvent(WindowEvent& evt) {
    if (ImGui_ImplWin32_WndProcHandler(evt.hWnd, evt.msg, evt.wParam, evt.lParam)) return evt.Cancel();
    if (!initialized) return;
    
    const ImGuiIO& io = ImGui::GetIO();
    
    if (io.WantCaptureMouse || menuOpen)
        if (evt.msg >= 0x200 && evt.msg <= 0x20a) // mouse events
            return evt.Cancel();
    
    if (io.WantCaptureKeyboard)
        if (evt.msg == WM_KEYDOWN || evt.msg == WM_KEYUP)
            return evt.Cancel();
}

void UI::Init() {
    EventManager::On<WindowEvent>(OnWindowEvent);
    EventManager::On<TickEvent>([]() {
        InitImGui();
        Render();
    });
    
    showWatermark = Config::Get()["showWatermark"].as<bool>(true);
    
}

inline EventManager::Ready $([] {
    UI::Init();
});