#include "Ui.h"
#include "events/EventManager.h"
#include "events/GameLoadedEvent.h"
#include "events/TickEvent.h"
#include "events/WindowEvent.h"
#include <imgui_internal.h>
#include <shtypes.h>
#include <shellscalingapi.h>
#include <backends/imgui_impl_win32.h>
#include <imgui-dx8/imgui_impl_dx8.h>
#include <modloader_new/ModManager.h>
#include <modloader_new/install/ModInstaller.h>
#include <modloader_new/mod/Mod.h>

#include "Config.h"
#include "Utils.h"
#include "events/UIRenderEvent.h"
#include "sdk/DirectX.h"
#include "sdk/Game.h"
#include "windows/windows.h"


using namespace ui;


void Ui::LoadFonts() {
    fonts = new FontManager(GetScalingFactor());
}

static std::string imguiIniFilename;
static std::string imguiLogFilename;

void Ui::InitImGui() {
    if (initialized) return;
        
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();
    ImGui::GetStyle().ScaleAllSizes(GetScalingFactor());
        
    ImGuiIO& io = ImGui::GetIO();

    imguiIniFilename = (sdk::Game::GetRootPath() / "imgui.ini").string();
    io.IniFilename = imguiIniFilename.c_str();
    
    imguiLogFilename = (sdk::Game::GetRootPath() / "imguilog.txt").string();
    io.LogFilename = imguiLogFilename.c_str();
        
    LoadFonts();
    io.ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;
        
    ImGui_ImplWin32_Init(*sdk::Game::window);
    ImGui_ImplDX8_Init(*sdk::DirectX::d3dDevice);
    
    io.IniFilename = imguiIniFilename.c_str();
    io.LogFilename = imguiLogFilename.c_str();
        
    initialized = true;
}
void RenderAssetReload() {
}

void Ui::ConstraintWindow(const char* windowTitle)
{
    const ImGuiWindow* existingWindow = ImGui::FindWindowByName(windowTitle);
    if (existingWindow != nullptr)
    {
        bool needsClampToScreen = false;
        ImVec2 targetPos = existingWindow->Pos;
        if (existingWindow->Pos.x < 0.f)
        {
            needsClampToScreen = true;
            targetPos.x = 0.f;
        }
        else if (100 + existingWindow->Pos.x > ImGui::GetMainViewport()->Size.x)
        {
            needsClampToScreen = true;
            targetPos.x = ImGui::GetMainViewport()->Size.x - 100;
        }
        if (existingWindow->Pos.y < 0.f)
        {
            needsClampToScreen = true;
            targetPos.y = 0.f;
        }
        else if (100 + existingWindow->Pos.y > ImGui::GetMainViewport()->Size.y)
        {
            needsClampToScreen = true;
            targetPos.y = ImGui::GetMainViewport()->Size.y - 100;
        }

        if (needsClampToScreen) // Necessary to prevent window from constantly undocking itself if docked.
        {
            ImGui::SetNextWindowPos(targetPos, ImGuiCond_Always);
        }
    }

}

void Ui::Render() {
    if (!initialized) return;
    
    ImGuiIO& io = ImGui::GetIO();
    io.IniFilename = imguiIniFilename.c_str();
    io.LogFilename = imguiLogFilename.c_str();

    if (menuOpen) io.ConfigFlags &= ~ImGuiConfigFlags_NoMouseCursorChange;
    else io.ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;
        
    if (ImGui::IsKeyPressed(ImGuiKey_GraveAccent, false))
        menuOpen = !menuOpen;

    ImGui_ImplDX8_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();
    ImGui::ShowDemoWindow();
    
    try {
        windows::Boot();
        windows::Watermark();
        windows::Main();
        if (textureViewerOpen) windows::TextureViewer();

        for (const auto& mod : modloader::ModManager::GetMods()) {
            if (!mod->IsActive()) continue;
            mod->GetImpl()->Render();
        }

        windows::Installer();
        windows::DropTarget();
        EventManager::Emit(UiRenderEvent());
    } catch(std::exception& e) {
        Log::Error << "Произошла ошибка в отрисовке кадра: " << e.what() << Log::Endl;
    }
    
    ImGui::ErrorCheckEndFrameRecover(ImGuiErrorHandler, nullptr);
    ImGui::EndFrame();

    const auto d3dDevice = *sdk::DirectX::d3dDevice;
    if (d3dDevice->BeginScene() >= 0)
    {
        ImGui::Render();
        ImGui_ImplDX8_RenderDrawData(ImGui::GetDrawData());
        d3dDevice->EndScene();
    }
}

ImGuiID Ui::GetModalsId(const std::shared_ptr<modloader::Mod>& mod)
{
    return ImHashStr(std::format("modals_{}", mod->GetID()).c_str());
}

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
void Ui::OnWindowEvent(WindowEvent& evt) {
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

float Ui::GetScalingFactor()
{
    static float value = 0;
    if (value > 0) return value;

    const auto monitor = MonitorFromWindow(*sdk::Game::window, MONITOR_DEFAULTTONEAREST);

    DEVICE_SCALE_FACTOR factor;
    const auto result = GetScaleFactorForMonitor(monitor, &factor);
    if (FAILED(result) || factor == DEVICE_SCALE_FACTOR_INVALID) return 1.f;

    value = static_cast<float>(factor) / 100.f;
    return value;
}

float Ui::ScaledPx(const float px)
{
    return px * GetScalingFactor();
}

void Ui::PushFont(const float size, const FontManager::FontType type)
{
    fonts->PushFont(size, type);
}

void Ui::PopFont()
{
    fonts->PopFont();
}

static inline int (__thiscall *AssetPool__freeAssetsFromD3d_orig)(void* this_) = nullptr;
static int __fastcall AssetPool__freeAssetsFromD3d(void* this_, void*) {
    ImGui_ImplDX8_InvalidateDeviceObjects();
    return AssetPool__freeAssetsFromD3d_orig(this_);
}

void Ui::Init() {
    EventManager::On<WindowEvent>(OnWindowEvent);
    EventManager::On<TickEvent>([] {
        InitImGui();
        Render();
    });

    HookManager::RegisterHook("55 8B EC 83 EC ? 89 4D ? C7 45 ? ? ? ? ? EB ? 8B 45 ? 83 C0 ? 89 45 ? 8B 4D ? 8B 55 ? 3B 91 ? ? ? ? 7D ? 8B 45 ? 8B 4D ? 8B 54 81 ? 0F B6 82",
        HOOK_REF_FORCE(AssetPool__freeAssetsFromD3d));
}

// ReSharper disable once CppParameterMayBeConstPtrOrRef
void Ui::ImGuiErrorHandler(void* source, const char* msg, ...)
{
    va_list va;
    va_start(va, msg);
    char buffer[1024];
    vsprintf_s(buffer, 1024, msg, va);
    Log::Warn << "Ошибка стека ImGui" << (source ? " " : "") << (source ? static_cast<const char*>(source) : "") << ":\n\t" << buffer << Log::Endl;
}

inline EventManager::Ready $ui_ready([] {
    Ui::Init();
});
