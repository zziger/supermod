#include <supermod/modloader/install/ZipModDropTarget.hpp>
#include <supermod/pch.hpp>

#include <supermod/game/Game.hpp>
#include <supermod/modloader/install/ModInstaller.hpp>
#include <supermod/modloader/install/provider/ModSourceProviderZip.hpp>
#include <supermod/ui/NotificationManager.hpp>

namespace sm::modloader
{
STDMETHODIMP ZipModDropTarget::QueryInterface(REFIID riid, void** ppv)
{
    if (IsEqualIID(riid, IID_IDropTarget) || IsEqualIID(riid, IID_IUnknown))
    {
        *ppv = static_cast<IDropTarget*>(this);
        return S_OK;
    }
    *ppv = nullptr;
    return E_NOINTERFACE;
}

HRESULT ZipModDropTarget::DragEnter(IDataObject* pDataObj, DWORD grfKeyState, POINTL pt, DWORD* pdwEffect)
{
    lastEffect = *pdwEffect = DROPEFFECT_NONE;

    FORMATETC fmt = {CF_HDROP, nullptr, DVASPECT_CONTENT, -1, TYMED_HGLOBAL};
    if (pDataObj->QueryGetData(&fmt) != S_OK)
        return S_OK;

    STGMEDIUM stgMedium;
    if (pDataObj->GetData(&fmt, &stgMedium) != S_OK)
        return S_OK;

    const auto hDrop = static_cast<HDROP>(stgMedium.hGlobal);
    const auto count = DragQueryFile(hDrop, 0xFFFFFFFF, nullptr, 0);
    bool containsZip = false;
    zipNames.clear();
    for (UINT i = 0; i < count; ++i)
    {
        TCHAR filename[MAX_PATH];
        if (DragQueryFile(hDrop, i, filename, MAX_PATH) > 0)
        {
            auto path = std::filesystem::path(filename);
            if (path.extension() == ".zip" || path.extension() == ".sprm")
            {
                zipNames.push_back(path.filename().string());
                containsZip = true;
            }
        }
    }
    ReleaseStgMedium(&stgMedium);

    if (!containsZip)
        return S_OK;

    SetActiveWindow(*game::Game::window);
    lastEffect = *pdwEffect = DROPEFFECT_COPY;
    state = true;
    return S_OK;
}

HRESULT ZipModDropTarget::DragOver(DWORD grfKeyState, POINTL pt, DWORD* pdwEffect)
{
    SetActiveWindow(*game::Game::window);
    *pdwEffect = lastEffect;
    return S_OK;
}

HRESULT ZipModDropTarget::DragLeave()
{
    state = false;
    return S_OK;
}

HRESULT ZipModDropTarget::Drop(IDataObject* pDataObj, DWORD grfKeyState, POINTL pt, DWORD* pdwEffect)
{
    state = false;
    lastEffect = *pdwEffect = DROPEFFECT_NONE;
    FORMATETC fmt = {CF_HDROP, nullptr, DVASPECT_CONTENT, -1, TYMED_HGLOBAL};
    if (pDataObj->QueryGetData(&fmt) != S_OK)
        return S_OK;

    STGMEDIUM stgMedium;
    if (pDataObj->GetData(&fmt, &stgMedium) != S_OK)
        return S_OK;

    const auto hDrop = static_cast<HDROP>(stgMedium.hGlobal);
    const auto count = DragQueryFile(hDrop, 0xFFFFFFFF, nullptr, 0);
    for (UINT i = 0; i < count; ++i)
    {
        TCHAR filename[MAX_PATH];
        if (DragQueryFile(hDrop, i, filename, MAX_PATH) > 0)
        {
            auto path = std::filesystem::path(filename);
            if (path.extension() == ".zip" || path.extension() == ".sprm")
            {
                *pdwEffect = DROPEFFECT_COPY;
                auto zip = std::make_shared<io::OwnedZip>(path.string(), false);
                modloader::ModInstaller::AddProvider(
                    std::make_shared<ModSourceProviderZip>(path.filename().string(), zip));
            }
        }
    }

    ReleaseStgMedium(&stgMedium);
    return S_OK;
}
} // namespace sm::modloader
