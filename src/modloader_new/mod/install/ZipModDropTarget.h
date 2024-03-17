#pragma once
#include <windows.h>
#include <shlobj.h>
#include <string>

class ZipModDropTarget final : public IDropTarget {
public:
    STDMETHODIMP QueryInterface(REFIID riid, void **ppv) override;

    STDMETHODIMP_(ULONG) AddRef() override { return 1; }
    STDMETHODIMP_(ULONG) Release() override { return 1; }

    bool state = false;
    DWORD lastEffect = DROPEFFECT_NONE;

    STDMETHODIMP DragEnter(IDataObject *pDataObj, DWORD grfKeyState, POINTL pt, DWORD *pdwEffect) override;

    STDMETHODIMP DragOver(DWORD grfKeyState, POINTL pt, DWORD *pdwEffect) override;

    STDMETHODIMP DragLeave() override;

    STDMETHODIMP Drop(IDataObject *pDataObj, DWORD grfKeyState, POINTL pt, DWORD *pdwEffect) override;
};

