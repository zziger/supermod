#include <iostream>
#include <windows.h>

#include "main.h"

struct msimg32_dll { 
	HMODULE dll;
	FARPROC OrignalAlphaBlend;
	FARPROC OrignalDllInitialize;
	FARPROC OrignalGradientFill;
	FARPROC OrignalTransparentBlt;
	FARPROC OrignalvSetDdrawflag;
} msimg32;

extern "C"
{
	__declspec(naked) void __stdcall FakeAlphaBlend() { _asm { jmp[msimg32.OrignalAlphaBlend] } }
	__declspec(naked) void __stdcall FakeDllInitialize() { _asm { jmp[msimg32.OrignalDllInitialize] } }
	__declspec(naked) void __stdcall FakeGradientFill() { _asm { jmp[msimg32.OrignalGradientFill] } }
	__declspec(naked) void __stdcall FakeTransparentBlt() { _asm { jmp[msimg32.OrignalTransparentBlt] } }
	__declspec(naked) void __stdcall FakevSetDdrawflag() { _asm { jmp[msimg32.OrignalvSetDdrawflag] } }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
		wchar_t path[MAX_PATH];
		GetSystemDirectory(path, MAX_PATH);
		std::wstring pathname = path + std::wstring(L"\\msimg32.dll");
		msimg32.dll = LoadLibrary(pathname.c_str());
		if (msimg32.dll == false)
		{
			MessageBox(0, L"Cannot load original msimg32.dll library", L"Proxy", MB_ICONERROR);
			ExitProcess(0);
		}
		msimg32.OrignalAlphaBlend = GetProcAddress(msimg32.dll, "AlphaBlend");
		msimg32.OrignalDllInitialize = GetProcAddress(msimg32.dll, "DllInitialize");
		msimg32.OrignalGradientFill = GetProcAddress(msimg32.dll, "GradientFill");
		msimg32.OrignalTransparentBlt = GetProcAddress(msimg32.dll, "TransparentBlt");
		msimg32.OrignalvSetDdrawflag = GetProcAddress(msimg32.dll, "vSetDdrawflag");

		break;
	}
	case DLL_PROCESS_DETACH:
	{
		FreeLibrary(msimg32.dll);
	}
	break;
	}
	return main(hModule, ul_reason_for_call, lpReserved);
}
