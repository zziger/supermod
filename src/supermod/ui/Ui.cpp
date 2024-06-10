#include <supermod/ui/Ui.hpp>

#include <imgui-dx9/imgui_impl_dx9.h>
#include <imgui-dx9/imgui_impl_win32.h>
#include <imgui_internal.h>
#include <shellscalingapi.h>
#include <shtypes.h>
#include <spdlog/spdlog.h>
#include <supermod/Config.hpp>
#include <supermod/Utils.hpp>
#include <supermod/events/EventManager.hpp>
#include <supermod/events/GameLoadedEvent.hpp>
#include <supermod/events/TickEvent.hpp>
#include <supermod/events/UIRenderEvent.hpp>
#include <supermod/events/WindowEvent.hpp>
#include <supermod/modloader/ModManager.hpp>
#include <supermod/modloader/install/ModInstaller.hpp>
#include <supermod/modloader/mod/Mod.hpp>
#include <supermod/sdk/DirectX.hpp>
#include <supermod/sdk/Game.hpp>
#include <supermod/ui/NotificationManager.hpp>
#include <supermod/ui/windows/windows.hpp>

using namespace sm::ui;

void Ui::LoadFonts()
{
    fonts = new FontManager(GetScalingFactor());
}

static std::string imguiIniFilename;
static std::string imguiLogFilename;

void Ui::InitImGui()
{
    if (initialized)
        return;

    auto& cfg = Config::Get();

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
    io.ConfigFlags |=
        ImGuiConfigFlags_NoMouseCursorChange | ImGuiConfigFlags_ViewportsEnable | ImGuiConfigFlags_DockingEnable;
    io.ConfigDockingWithShift = cfg.imgui.dockingWithShift;

    ImGui_ImplWin32_Init(*sdk::Game::window);
    ImGui_ImplDX9_Init(sdk::DirectX::GetDx9());

    io.IniFilename = imguiIniFilename.c_str();
    io.LogFilename = imguiLogFilename.c_str();

    initialized = true;
}
void RenderAssetReload() {}

void Ui::ConstraintWindow(const char* windowTitle)
{
    // const ImGuiWindow* existingWindow = ImGui::FindWindowByName(windowTitle);
    // if (existingWindow != nullptr)
    // {
    //     bool needsClampToScreen = false;
    //     ImVec2 targetPos = existingWindow->Pos;
    //     if (existingWindow->Pos.x < 0.f)
    //     {
    //         needsClampToScreen = true;
    //         targetPos.x = 0.f;
    //     }
    //     else if (100 + existingWindow->Pos.x > ImGui::GetMainViewport()->Size.x)
    //     {
    //         needsClampToScreen = true;
    //         targetPos.x = ImGui::GetMainViewport()->Size.x - 100;
    //     }
    //     if (existingWindow->Pos.y < 0.f)
    //     {
    //         needsClampToScreen = true;
    //         targetPos.y = 0.f;
    //     }
    //     else if (100 + existingWindow->Pos.y > ImGui::GetMainViewport()->Size.y)
    //     {
    //         needsClampToScreen = true;
    //         targetPos.y = ImGui::GetMainViewport()->Size.y - 100;
    //     }
    //
    //     if (needsClampToScreen) // Necessary to prevent window from constantly undocking itself if docked.
    //     {
    //         ImGui::SetNextWindowPos(targetPos, ImGuiCond_Always);
    //     }
    // }
}

void Ui::Render()
{
    if (!initialized)
        return;

    ImGuiIO& io = ImGui::GetIO();
    auto& cfg = Config::Get();
    io.IniFilename = imguiIniFilename.c_str();
    io.LogFilename = imguiLogFilename.c_str();

    if (menuOpen)
        io.ConfigFlags &= ~ImGuiConfigFlags_NoMouseCursorChange;
    else
        io.ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;

    if (ImGui::IsKeyPressed(ImGuiKey_GraveAccent, false))
        menuOpen = !menuOpen;

    ImGui_ImplDX9_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();

    const auto showValue = cfg.developer.showImGuiDemo;
    if (showValue)
        ImGui::ShowDemoWindow(&cfg.developer.showImGuiDemo);
    if (showValue != cfg.developer.showImGuiDemo)
        cfg.Save();

    try
    {
        windows::Boot();
        windows::Watermark();
        windows::Main();
        if (textureViewerOpen)
            windows::TextureViewer();
        if (animationViewerOpen)
            windows::AnimationViewer();
        if (modelViewerOpen)
            windows::ModelViewer();
        ui::NotificationManager::Render();

        for (const auto& mod : modloader::ModManager::GetMods())
        {
            if (!mod->IsActive())
                continue;
            mod->GetImpl()->Render();
        }

        windows::Installer();
        windows::DropTarget();
        EventManager::Emit(UiRenderEvent());
    }
    catch (std::exception& e)
    {
        spdlog::error("Error in ImGui render function: {}", e.what());
    }

    ImGui::ErrorCheckEndFrameRecover(ImGuiErrorHandler, nullptr);
    ImGui::EndFrame();

    const auto d3dDevice = *sdk::DirectX::d3dDevice;
    if (d3dDevice->BeginScene() >= 0)
    {
        ImGui::Render();
        ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
        d3dDevice->EndScene();
    }

    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
    }
}
ImGuiID Ui::GetModalsId(const std::shared_ptr<modloader::Mod>& mod)
{
    return ImHashStr(std::format("modals_{}", mod->GetID()).c_str());
}

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
void Ui::OnWindowEvent(WindowEvent& evt)
{
    if (ImGui_ImplWin32_WndProcHandler(evt.hWnd, evt.msg, evt.wParam, evt.lParam))
        return evt.Cancel();
    if (!initialized)
        return;

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
    if (value > 0)
        return value;

    const auto monitor = MonitorFromWindow(*sdk::Game::window, MONITOR_DEFAULTTONEAREST);

    DEVICE_SCALE_FACTOR factor;
    const auto result = GetScaleFactorForMonitor(monitor, &factor);
    if (FAILED(result) || factor == DEVICE_SCALE_FACTOR_INVALID)
        return 1.f;

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

void Ui::FixNextPopupModal(bool center)
{
    ImGuiWindowClass noAutoMerge;
    noAutoMerge.ViewportFlagsOverrideSet = ImGuiViewportFlags_NoAutoMerge | ImGuiViewportFlags_TopMost;
    ImGui::SetNextWindowClass(&noAutoMerge);
    if (center)
    {
        ImVec2 viewportCenter = ImGui::GetMainViewport()->GetCenter();
        ImGui::SetNextWindowPos(viewportCenter, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
    }
}

static inline int(__thiscall* AssetPool__freeAssetsFromD3d_orig)(void* this_) = nullptr;
static int __fastcall AssetPool__freeAssetsFromD3d(void* this_, void*)
{
    ImGui_ImplDX9_InvalidateDeviceObjects();
    return AssetPool__freeAssetsFromD3d_orig(this_);
}

static inline int(__thiscall* AssetPool__reloadAssetsToD3d_orig)(void* this_) = nullptr;
static int __fastcall AssetPool__reloadAssetsToD3d(void* this_, void*)
{
    const auto res = AssetPool__reloadAssetsToD3d_orig(this_);
    ImGui_ImplDX9_CreateDeviceObjects();
    return res;
}

void Ui::Init()
{
    EventManager::On<WindowEvent>(OnWindowEvent);
    EventManager::On<TickEvent>([] {
        try
        {
            InitImGui();
        }
        catch (const std::exception& e)
        {
            spdlog::error("Failed to init ImGui: {}", e.what());
            return;
        }

        try
        {
            Render();
        }
        catch (const std::exception& e)
        {
            spdlog::error("Failed to render ImGui frame: {}", e.what());
        }
    });

    HookManager::RegisterHook("55 8B EC 83 EC ? 89 4D ? C7 45 ? ? ? ? ? EB ? 8B 45 ? 83 C0 ? 89 45 ? 8B 4D ? 8B 55 ? "
                              "3B 91 ? ? ? ? 7D ? 8B 45 ? 8B 4D ? 8B 54 81 ? 0F B6 82",
                              HOOK_REF_FORCE(AssetPool__freeAssetsFromD3d));
    HookManager::RegisterHook("55 8B EC 83 EC ? 89 4D ? C7 45 ? ? ? ? ? EB ? 8B 45 ? 83 C0 ? 89 45 ? 8B 4D ? 8B 55 ? "
                              "3B 91 ? ? ? ? 0F 8D ? ? ? ? 8B 45",
                              HOOK_REF_FORCE(AssetPool__reloadAssetsToD3d));
}

// ReSharper disable once CppParameterMayBeConstPtrOrRef
void Ui::ImGuiErrorHandler(void* source, const char* msg, ...)
{
    va_list va;
    va_start(va, msg);
    char buffer[1024];
    vsprintf_s(buffer, 1024, msg, va);
    spdlog::error("ImGui stack error while rendering {}:\n\t{}", source ? static_cast<const char*>(source) : "frame",
                  buffer);
}

inline sm::EventManager::Ready $ui_ready([] { Ui::Init(); });
