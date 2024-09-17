local ffi = require("ffi")

if ffi.abi '64bit' then

  ffi.cdef [[

    typedef __int64 LONG_PTR;
    typedef unsigned __int64 UINT_PTR;

  ]]

else

  ffi.cdef [[

    typedef long LONG_PTR;
    typedef unsigned int UINT_PTR;

  ]]

end

ffi.cdef [[

	enum {
		S_OK = 0,
		S_FALSE = 1,

		CS_VREDRAW = 0x0001,
		CS_HREDRAW = 0x0002,
		CS_DBLCLKS = 0x0008,
		CS_OWNDC = 0x0020,
		CS_CLASSDC = 0x0040,
		CS_PARENTDC = 0x0080,
		CS_NOCLOSE = 0x0200,
		CS_SAVEBITS = 0x0800,
		CS_BYTEALIGNCLIENT = 0x1000,
		CS_BYTEALIGNWINDOW = 0x2000,
		CS_GLOBALCLASS = 0x4000,
		MB_OK = 0x00000000,
		MB_OKCANCEL = 0x00000001,
		MB_ABORTRETRYIGNORE = 0x00000002,
		MB_YESNOCANCEL = 0x00000003,
		MB_YESNO = 0x00000004,
		MB_RETRYCANCEL = 0x00000005,
		MB_CANCELTRYCONTINUE = 0x00000006,
		MB_ICONHAND = 0x00000010,
		MB_ICONQUESTION = 0x00000020,
		MB_ICONEXCLAMATION = 0x00000030,
		MB_ICONASTERISK = 0x00000040,
		MB_USERICON = 0x00000080,
		MB_ICONWARNING = MB_ICONEXCLAMATION,
		MB_ICONERROR = MB_ICONHAND,
		MB_ICONINFORMATION = MB_ICONASTERISK,
		MB_ICONSTOP = MB_ICONHAND,
		MB_DEFBUTTON1               = 0x00000000,
		MB_DEFBUTTON2               = 0x00000100,
		MB_DEFBUTTON3               = 0x00000200,
		MB_DEFBUTTON4               = 0x00000300,
		MB_APPLMODAL                = 0x00000000,
		MB_SYSTEMMODAL              = 0x00001000,
		MB_TASKMODAL                = 0x00002000,
		MB_HELP                     = 0x00004000,
		MB_NOFOCUS                  = 0x00008000,
		MB_SETFOREGROUND            = 0x00010000,
		MB_DEFAULT_DESKTOP_ONLY     = 0x00020000,
		MB_TOPMOST                  = 0x00040000,
		MB_RIGHT                    = 0x00080000,
		MB_RTLREADING               = 0x00100000,
		SW_HIDE             = 0,
		SW_SHOWNORMAL       = 1,
		SW_NORMAL           = 1,
		SW_SHOWMINIMIZED    = 2,
		SW_SHOWMAXIMIZED    = 3,
		SW_MAXIMIZE         = 3,
		SW_SHOWNOACTIVATE   = 4,
		SW_SHOW             = 5,
		SW_MINIMIZE         = 6,
		SW_SHOWMINNOACTIVE  = 7,
		SW_SHOWNA           = 8,
		SW_RESTORE          = 9,
		SW_SHOWDEFAULT      = 10,
		SW_FORCEMINIMIZE    = 11,
		SW_MAX              = 11,
		WS_OVERLAPPED       = 0x00000000,
		WS_POPUP            = 0x80000000,
		WS_CHILD            = 0x40000000,
		WS_MINIMIZE         = 0x20000000,
		WS_VISIBLE          = 0x10000000,
		WS_DISABLED         = 0x08000000,
		WS_CLIPSIBLINGS     = 0x04000000,
		WS_CLIPCHILDREN     = 0x02000000,
		WS_MAXIMIZE         = 0x01000000,
		WS_CAPTION          = 0x00C00000,
		WS_BORDER           = 0x00800000,
		WS_DLGFRAME         = 0x00400000,
		WS_VSCROLL          = 0x00200000,
		WS_HSCROLL          = 0x00100000,
		WS_SYSMENU          = 0x00080000,
		WS_THICKFRAME       = 0x00040000,
		WS_GROUP            = 0x00020000,
		WS_TABSTOP          = 0x00010000,
		WS_MINIMIZEBOX      = 0x00020000,
		WS_MAXIMIZEBOX      = 0x00010000,
		WS_TILED            = WS_OVERLAPPED,
		WS_ICONIC           = WS_MINIMIZE,
		WS_SIZEBOX          = WS_THICKFRAME,
		WS_OVERLAPPEDWINDOW = 0x00CF0000,
		WS_TILEDWINDOW      = WS_OVERLAPPEDWINDOW,
		WS_POPUPWINDOW      = 0x80880000,
		WS_CHILDWINDOW      = WS_CHILD,
		WS_EX_DLGMODALFRAME     = 0x00000001,
		WS_EX_NOPARENTNOTIFY    = 0x00000004,
		WS_EX_TOPMOST           = 0x00000008,
		WS_EX_ACCEPTFILES       = 0x00000010,
		WS_EX_TRANSPARENT       = 0x00000020,
		WS_EX_MDICHILD          = 0x00000040,
		WS_EX_TOOLWINDOW        = 0x00000080,
		WS_EX_WINDOWEDGE        = 0x00000100,
		WS_EX_CLIENTEDGE        = 0x00000200,
		WS_EX_CONTEXTHELP       = 0x00000400,
		WS_EX_RIGHT             = 0x00001000,
		WS_EX_LEFT              = 0x00000000,
		WS_EX_RTLREADING        = 0x00002000,
		WS_EX_LTRREADING        = 0x00000000,
		WS_EX_LEFTSCROLLBAR     = 0x00004000,
		WS_EX_RIGHTSCROLLBAR    = 0x00000000,
		WS_EX_CONTROLPARENT     = 0x00010000,
		WS_EX_STATICEDGE        = 0x00020000,
		WS_EX_APPWINDOW         = 0x00040000,
		WS_EX_OVERLAPPEDWINDOW  = 0x00000300,
		WS_EX_PALETTEWINDOW     = 0x00000188,
		WS_EX_LAYERED           = 0x00080000,
		WS_EX_NOINHERITLAYOUT   = 0x00100000,
		WS_EX_LAYOUTRTL         = 0x00400000,
		WS_EX_COMPOSITED        = 0x02000000,
		WS_EX_NOACTIVATE        = 0x08000000,
		WM_NULL                         = 0x0000,
		WM_CREATE                       = 0x0001,
		WM_DESTROY                      = 0x0002,
		WM_MOVE                         = 0x0003,
		WM_SIZE                         = 0x0005,
		WM_ACTIVATE                     = 0x0006,
		WA_INACTIVE     = 0,
		WA_ACTIVE       = 1,
		WA_CLICKACTIVE  = 2,
		WM_SETFOCUS                     = 0x0007,
		WM_KILLFOCUS                    = 0x0008,
		WM_ENABLE                       = 0x000A,
		WM_SETREDRAW                    = 0x000B,
		WM_SETTEXT                      = 0x000C,
		WM_GETTEXT                      = 0x000D,
		WM_GETTEXTLENGTH                = 0x000E,
		WM_PAINT                        = 0x000F,
		WM_CLOSE                        = 0x0010,
		WM_QUERYENDSESSION              = 0x0011,
		WM_QUERYOPEN                    = 0x0013,
		WM_ENDSESSION                   = 0x0016,
		WM_QUIT                         = 0x0012,
		WM_ERASEBKGND                   = 0x0014,
		WM_SYSCOLORCHANGE               = 0x0015,
		WM_SHOWWINDOW                   = 0x0018,
		WM_WININICHANGE                 = 0x001A,
		WM_SETTINGCHANGE                = WM_WININICHANGE,
		WM_DEVMODECHANGE                = 0x001B,
		WM_ACTIVATEAPP                  = 0x001C,
		WM_FONTCHANGE                   = 0x001D,
		WM_TIMECHANGE                   = 0x001E,
		WM_CANCELMODE                   = 0x001F,
		WM_SETCURSOR                    = 0x0020,
		WM_MOUSEACTIVATE                = 0x0021,
		WM_CHILDACTIVATE                = 0x0022,
		WM_QUEUESYNC                    = 0x0023,
		WM_GETMINMAXINFO                = 0x0024,
		WM_PAINTICON                    = 0x0026,
		WM_ICONERASEBKGND               = 0x0027,
		WM_NEXTDLGCTL                   = 0x0028,
		WM_SPOOLERSTATUS                = 0x002A,
		WM_DRAWITEM                     = 0x002B,
		WM_MEASUREITEM                  = 0x002C,
		WM_DELETEITEM                   = 0x002D,
		WM_VKEYTOITEM                   = 0x002E,
		WM_CHARTOITEM                   = 0x002F,
		WM_SETFONT                      = 0x0030,
		WM_GETFONT                      = 0x0031,
		WM_SETHOTKEY                    = 0x0032,
		WM_GETHOTKEY                    = 0x0033,
		WM_QUERYDRAGICON                = 0x0037,
		WM_COMPAREITEM                  = 0x0039,
		WM_GETOBJECT                    = 0x003D,
		WM_COMPACTING                   = 0x0041,
		WM_COMMNOTIFY                   = 0x0044,
		WM_WINDOWPOSCHANGING            = 0x0046,
		WM_WINDOWPOSCHANGED             = 0x0047,
		WM_POWER                        = 0x0048,

    CW_USEDEFAULT = 0x80000000
	};
	typedef const char* LPCSTR;

	typedef unsigned long       DWORD;
    typedef int                 BOOL;
    typedef unsigned char       BYTE;
    typedef unsigned short      WORD;
    typedef float               FLOAT;
    typedef FLOAT               *PFLOAT;
    typedef BOOL                *PBOOL;
    typedef BOOL                *LPBOOL;
    typedef BYTE                *PBYTE;
    typedef BYTE                *LPBYTE;
    typedef int                 *PINT;
    typedef int                 *LPINT;
    typedef WORD                *PWORD;
    typedef WORD                *LPWORD;
    typedef long                *LPLONG;
    typedef DWORD               *PDWORD;
    typedef DWORD               *LPDWORD;
    typedef void                *LPVOID;
    typedef const void          *LPCVOID;

    typedef int                 INT;
    typedef unsigned int        UINT;
    typedef unsigned int        *PUINT;

	typedef int32_t bool32;
	typedef void* HANDLE;
	typedef void* HWND;
	typedef void* HMONITOR;
	typedef void* HICON;
	typedef void* HCURSOR;
	typedef void* HINSTANCE;
	typedef void* HBRUSH;
	typedef void* HMENU;
	typedef void* HDC;
	typedef void* HGLRC;
	typedef void* HFONT;
	typedef void* HMODULE;
	typedef struct FILETIME { uint32_t dwLowDateTime, dwHighDateTime; } FILETIME;
	typedef struct GUID { uint32_t Data1; uint16_t Data2, Data3; uint8_t Data4[8]; } GUID;
	typedef struct RECT { int32_t left, top, right, bottom; } RECT;
	typedef struct SIZE { int32_t cx, cy; } SIZE;
	typedef struct POINT { int32_t x, y; } POINT;
	typedef struct RGNDATA {
		struct { uint32_t dwSize, iType, nCount, nRgnSize; RECT rcBound; } rdh;
		char Buffer[1];
	} RGNDATA;
	typedef struct { uint8_t peRed, peGreen, peBlue, peFlags; } PALETTEENTRY;
  typedef LONG_PTR (__stdcall *WNDPROC)(void* hwnd, unsigned int message, UINT_PTR wparam, LONG_PTR lparam);
	//typedef union LPCTSTR { const char* ansi; const wchar_t* unicode; } LPCTSTR;
	typedef struct WNDCLASSEXA {
		uint32_t cbSize, style;
		WNDPROC lpfnWndProc;
		int32_t cbClsExtra, cbWndExtra;
		HINSTANCE hInstance;
		HICON hIcon;
		HCURSOR hCursor;
		HBRUSH hbrBackground;
		const char* lpszMenuName;
		const char* lpszClassName;
		HICON hIconSm;
	} WNDCLASSEXA;
	typedef struct MSG {
		HWND hwnd;
		uint32_t message;
		uintptr_t wParam, lParam;
		uint32_t time;
		POINT pt;
	} MSG;

	enum {
		LF_FACESIZE = 32
	};

	typedef struct LOGFONT {
		int32_t lfHeight, lfWidth, lfEscapement, lfOrientationm, lfWeight;
		uint8_t lfItalic, lfUnderline, lfStrikeOut, lfCharSet, lfOutPrecision, lfClipPrecision, lfQuality, lfPitchAndFamily;
		union {
			char lfFaceNameA[LF_FACESIZE];
			wchar_t lfFaceNameW[LF_FACESIZE];
		};
	} LOGFONT;

	int32_t MessageBoxA(HWND window, const char* text, const char* caption, uint32_t flags);
	intptr_t DefWindowProcA(HWND window, uint32_t msg, uintptr_t wparam, uintptr_t lparam);
	uint16_t RegisterClassExA(const WNDCLASSEXA*);
	HWND CreateWindowExA(uint32_t exstyle, const char* classname, const char* windowname, int32_t style,
		int32_t x, int32_t y, int32_t width, int32_t height, HWND parent, HMENU menu, HINSTANCE instance, void* param);
	bool32 ShowWindow(HWND window, int32_t command);
  bool32 UpdateWindow(void* hwnd);
	bool32 GetMessageA(MSG* out_msg, HWND hwnd, uint32_t filter_min, uint32_t filter_max);
	bool32 TranslateMessage(const MSG* msg);
	intptr_t DispatchMessageA(const MSG* msg);
	HWND SetFocus(HWND window);
	HWND GetActiveWindow();
	HWND GetFocus();
  uint32_t GetLastError();
	int32_t GetWindowTextA(HWND, char* out_string, int32_t max_count);
  void PostQuitMessage(int exitcode);

	typedef struct TEXTMETRICA {
		int32_t tmHeight;
		int32_t tmAscent;
		int32_t tmDescent;
		int32_t tmInternalLeading;
		int32_t tmExternalLeading;
		int32_t tmAveCharWidth;
		int32_t tmMaxCharWidth;
		int32_t tmWeight;
		int32_t tmOverhang;
		int32_t tmDigitizedAspectX;
		int32_t tmDigitizedAspectY;
		char tmFirstChar;
		char tmLastChar;
		char tmDefaultChar;
		char tmBreakChar;
		uint8_t tmItalic;
		uint8_t tmUnderlined;
		uint8_t tmStruckOut;
		uint8_t tmPitchAndFamily;
		uint8_t tmCharSet;
	} TEXTMETRICA;

	typedef struct TEXTMETRICW {
		int32_t tmHeight;
		int32_t tmAscent;
		int32_t tmDescent;
		int32_t tmInternalLeading;
		int32_t tmExternalLeading;
		int32_t tmAveCharWidth;
		int32_t tmMaxCharWidth;
		int32_t tmWeight;
		int32_t tmOverhang;
		int32_t tmDigitizedAspectX;
		int32_t tmDigitizedAspectY;
		wchar_t tmFirstChar;
		wchar_t tmLastChar;
		wchar_t tmDefaultChar;
		wchar_t tmBreakChar;
		uint8_t tmItalic;
		uint8_t tmUnderlined;
		uint8_t tmStruckOut;
		uint8_t tmPitchAndFamily;
		uint8_t tmCharSet;
	} TEXTMETRICW;

	int WideCharToMultiByte(
		uint32_t codePage,
		uint32_t flags,
		const wchar_t* wide,
		int wide_count,
		char* out_multibyte,
		int multibyte_count,
		const char* defaultChar,
		bool32* out_usedDefaultChar);

  void* GetModuleHandleA(const char* name);

]]

ffi.metatype('GUID', {
	__tostring = function(guid)
		return string.format('%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x',
			guid.Data1,
			guid.Data2, guid.Data3,
			guid.Data4[0], guid.Data4[1], guid.Data4[2], guid.Data4[3],
			guid.Data4[4], guid.Data4[5], guid.Data4[6], guid.Data4[7])
	end
})