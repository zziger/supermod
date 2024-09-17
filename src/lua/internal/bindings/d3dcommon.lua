
-- common definitions for Direct3D, up to & including version 9

local ffi = require 'ffi'

ffi.cdef [[

	typedef uint32_t D3Denum;

	enum {

    D3DADAPTER_DEFAULT = 0,
    D3DBACKBUFFER_TYPE_LEFT = 1,
    D3DBACKBUFFER_TYPE_MONO = 0,
    D3DBACKBUFFER_TYPE_RIGHT = 2,
    D3DBASIS_BEZIER = 0,
    D3DBASIS_BSPLINE = 1,
    D3DBASIS_CATMULL_ROM = 2,
    D3DBASIS_INTERPOLATE = 2,
    D3DBLENDOP_ADD              = 1,
    D3DBLENDOP_MAX              = 5,
    D3DBLENDOP_MIN              = 4,
    D3DBLENDOP_REVSUBTRACT      = 3,
    D3DBLENDOP_SUBTRACT         = 2,
    D3DBLEND_BLENDFACTOR = 14,
    D3DBLEND_BOTHINVSRCALPHA = 13,
    D3DBLEND_BOTHSRCALPHA = 12,
    D3DBLEND_DESTALPHA = 7,
    D3DBLEND_DESTCOLOR = 9,
    D3DBLEND_INVBLENDFACTOR = 15,
    D3DBLEND_INVDESTALPHA = 8,
    D3DBLEND_INVDESTCOLOR = 10,
    D3DBLEND_INVSRCALPHA = 6,
    D3DBLEND_INVSRCCOLOR = 4,
    D3DBLEND_ONE = 2,
    D3DBLEND_SRCALPHA = 5,
    D3DBLEND_SRCALPHASAT = 11,
    D3DBLEND_SRCCOLOR = 3,
    D3DBLEND_ZERO = 1,
    D3DCAPS2_CANAUTOGENMIPMAP = 0x40000000,
    D3DCAPS2_CANCALIBRATEGAMMA = 0x00100000,
    D3DCAPS2_CANMANAGERESOURCE = 0x10000000,
    D3DCAPS2_CANRENDERWINDOWED = 0x00080000,
    D3DCAPS2_DYNAMICTEXTURES = 0x20000000,
    D3DCAPS2_FULLSCREENGAMMA = 0x00020000,
    D3DCAPS2_NO2DDURING3DSCENE = 0x00000002,
    D3DCAPS2_RESERVED = 0x02000000,
    D3DCAPS3_ALPHA_FULLSCREEN_FLIP_OR_DISCARD = 0x00000020,
    D3DCAPS3_COPY_TO_SYSTEMMEM = 0x00000200,
    D3DCAPS3_COPY_TO_VIDMEM = 0x00000100,
    D3DCAPS3_LINEAR_TO_SRGB_PRESENTATION = 0x00000080,
    D3DCAPS3_RESERVED = 0x8000001f,
    D3DCAPS_READ_SCANLINE = 0x00020000,
    D3DCLEAR_STENCIL = 4,
    D3DCLEAR_TARGET = 1,
    D3DCLEAR_ZBUFFER = 2,
    D3DCLIPPLANE0 = 1,
    D3DCLIPPLANE1 = 2,
    D3DCLIPPLANE2 = 4,
    D3DCLIPPLANE3 = 8,
    D3DCLIPPLANE4 = 16,
    D3DCLIPPLANE5 = 32,
    D3DCMP_ALWAYS = 8,
    D3DCMP_EQUAL = 3,
    D3DCMP_GREATER = 5,
    D3DCMP_GREATEREQUAL = 7,
    D3DCMP_LESS = 2,
    D3DCMP_LESSEQUAL = 4,
    D3DCMP_NEVER = 1,
    D3DCMP_NOTEQUAL = 6,
    D3DCOLORWRITEENABLE_ALPHA = 8,
    D3DCOLORWRITEENABLE_BLUE = 4,
    D3DCOLORWRITEENABLE_GREEN = 2,
    D3DCOLORWRITEENABLE_RED = 1,
    D3DCREATE_ADAPTERGROUP_DEVICE = 0x200,
    D3DCREATE_DISABLE_DRIVER_MANAGEMENT = 0x100,
    D3DCREATE_DISABLE_DRIVER_MANAGEMENT_EX = 0x400,
    D3DCREATE_FPU_PRESERVE = 0x2,
    D3DCREATE_HARDWARE_VERTEXPROCESSING = 0x40,
    D3DCREATE_MIXED_VERTEXPROCESSING = 0x80,
    D3DCREATE_MULTITHREADED = 0x4,
    D3DCREATE_NOWINDOWCHANGES = 0x800,
    D3DCREATE_PUREDEVICE = 0x10,
    D3DCREATE_SOFTWARE_VERTEXPROCESSING = 0x20,
    D3DCS_ALL = 0xFFF,
    D3DCS_BACK = 0x020,
    D3DCS_BOTTOM = 0x008,
    D3DCS_FRONT = 0x010,
    D3DCS_LEFT = 0x001,
    D3DCS_PLANE0 = 0x040,
    D3DCS_PLANE1 = 0x080,
    D3DCS_PLANE2 = 0x100,
    D3DCS_PLANE3 = 0x200,
    D3DCS_PLANE4 = 0x400,
    D3DCS_PLANE5 = 0x800,
    D3DCS_RIGHT = 0x002,
    D3DCS_TOP = 0x004,
    D3DCUBEMAP_FACE_NEGATIVE_X = 1,
    D3DCUBEMAP_FACE_NEGATIVE_Y = 3,
    D3DCUBEMAP_FACE_NEGATIVE_Z = 5,
    D3DCUBEMAP_FACE_POSITIVE_X = 0,
    D3DCUBEMAP_FACE_POSITIVE_Y = 2,
    D3DCUBEMAP_FACE_POSITIVE_Z = 4,
    D3DCULL_CCW = 3,
    D3DCULL_CW = 2,
    D3DCULL_NONE = 1,
    D3DCURSORCAPS_COLOR = 0x00000001,
    D3DCURSORCAPS_LOWRES = 0x00000002,
    D3DCURSOR_IMMEDIATE_UPDATE = 1,
    D3DDEVCAPS_CANBLTSYSTONONLOCAL = 0x00020000,
    D3DDEVCAPS_CANRENDERAFTERFLIP = 0x00000800,
    D3DDEVCAPS_DRAWPRIMITIVES2 = 0x00002000,
    D3DDEVCAPS_DRAWPRIMITIVES2EX = 0x00008000,
    D3DDEVCAPS_DRAWPRIMTLVERTEX = 0x00000400,
    D3DDEVCAPS_EXECUTESYSTEMMEMORY = 0x00000010,
    D3DDEVCAPS_EXECUTEVIDEOMEMORY = 0x00000020,
    D3DDEVCAPS_FLOATTLVERTEX = 0x00000001,
    D3DDEVCAPS_HWRASTERIZATION = 0x00080000,
    D3DDEVCAPS_HWTRANSFORMANDLIGHT = 0x00010000,
    D3DDEVCAPS_NPATCHES = 0x01000000,
    D3DDEVCAPS_PUREDEVICE = 0x00100000,
    D3DDEVCAPS_QUINTICRTPATCHES = 0x00200000,
    D3DDEVCAPS_RTPATCHES = 0x00400000,
    D3DDEVCAPS_RTPATCHHANDLEZERO = 0x00800000,
    D3DDEVCAPS_SEPARATETEXTUREMEMORIES = 0x00004000,
    D3DDEVCAPS_SORTDECREASINGZ = 0x00000004,
    D3DDEVCAPS_SORTEXACT = 0x00000008,
    D3DDEVCAPS_SORTINCREASINGZ = 0x00000002,
    D3DDEVCAPS_TEXTURENONLOCALVIDMEM = 0x00001000,
    D3DDEVCAPS_TEXTURESYSTEMMEMORY = 0x00000100,
    D3DDEVCAPS_TEXTUREVIDEOMEMORY = 0x00000200,
    D3DDEVCAPS_TLVERTEXSYSTEMMEMORY = 0x00000040,
    D3DDEVCAPS_TLVERTEXVIDEOMEMORY = 0x00000080,
    D3DDEVTYPE_HAL = 1,
    D3DDEVTYPE_NULLREF     = 4,
    D3DDEVTYPE_REF = 2,
    D3DDEVTYPE_SW = 3,
    D3DDMT_DISABLE = 1,
    D3DDMT_ENABLE = 0,
    D3DDP_MAXTEXCOORD = 8,
    D3DERR_BADMAJORVERSION = 0x887602BC,
    D3DERR_BADMINORVERSION = 0x887602BD,
    D3DERR_COLORKEYATTACHED = 0x88760802,
    D3DERR_CONFLICTINGRENDERSTATE = 0x88760821,
    D3DERR_CONFLICTINGTEXTUREFILTER = 0x8876081E,
    D3DERR_CONFLICTINGTEXTUREPALETTE = 0x88760826,
    D3DERR_DEVICEAGGREGATED = 0x887602C3,
    D3DERR_DEVICELOST = 0x88760868,
    D3DERR_DEVICENOTRESET = 0x88760869,
    D3DERR_DRIVERINTERNALERROR = 0x88760827,
    D3DERR_DRIVERINVALIDCALL = 0x8876086D,
    D3DERR_EXECUTE_CLIPPED_FAILED = 0x887602CD,
    D3DERR_EXECUTE_CREATE_FAILED = 0x887602C6,
    D3DERR_EXECUTE_DESTROY_FAILED = 0x887602C7,
    D3DERR_EXECUTE_FAILED = 0x887602CC,
    D3DERR_EXECUTE_LOCKED = 0x887602CA,
    D3DERR_EXECUTE_LOCK_FAILED = 0x887602C8,
    D3DERR_EXECUTE_NOT_LOCKED = 0x887602CB,
    D3DERR_EXECUTE_UNLOCK_FAILED = 0x887602C9,
    D3DERR_INBEGIN = 0x88760302,
    D3DERR_INBEGINSTATEBLOCK = 0x88760835,
    D3DERR_INITFAILED = 0x887602C2,
    D3DERR_INVALIDCALL = 0x8876086C,
    D3DERR_INVALIDCURRENTVIEWPORT = 0x887602DF,
    D3DERR_INVALIDDEVICE = 0x8876086B,
    D3DERR_INVALIDMATRIX = 0x88760824,
    D3DERR_INVALIDPALETTE = 0x887602E8,
    D3DERR_INVALIDPRIMITIVETYPE = 0x887602E0,
    D3DERR_INVALIDRAMPTEXTURE = 0x887602E3,
    D3DERR_INVALIDSTATEBLOCK = 0x88760834,
    D3DERR_INVALIDVERTEXFORMAT = 0x88760800,
    D3DERR_INVALIDVERTEXTYPE = 0x887602E1,
    D3DERR_INVALID_DEVICE = 0x887602C1,
    D3DERR_LIGHTHASVIEWPORT = 0x887602EF,
    D3DERR_LIGHTNOTINTHISVIEWPORT = 0x887602F0,
    D3DERR_LIGHT_SET_FAILED = 0x887602EE,
    D3DERR_MATERIAL_CREATE_FAILED = 0x887602E4,
    D3DERR_MATERIAL_DESTROY_FAILED = 0x887602E5,
    D3DERR_MATERIAL_GETDATA_FAILED = 0x887602E7,
    D3DERR_MATERIAL_SETDATA_FAILED = 0x887602E6,
    D3DERR_MATRIX_CREATE_FAILED = 0x887602DA,
    D3DERR_MATRIX_DESTROY_FAILED = 0x887602DB,
    D3DERR_MATRIX_GETDATA_FAILED = 0x887602DD,
    D3DERR_MATRIX_SETDATA_FAILED = 0x887602DC,
    D3DERR_MOREDATA = 0x88760867,
    D3DERR_NOCURRENTVIEWPORT = 0x88760307,
    D3DERR_NOTAVAILABLE = 0x8876086A,
    D3DERR_NOTFOUND = 0x88760866,
    D3DERR_NOTINBEGIN = 0x88760303,
    D3DERR_NOTINBEGINSTATEBLOCK = 0x88760836,
    D3DERR_NOVIEWPORTS = 0x88760304,
    D3DERR_OUTOFVIDEOMEMORY = 0x8876017C,
    D3DERR_SCENE_BEGIN_FAILED = 0x887602FA,
    D3DERR_SCENE_END_FAILED = 0x887602FB,
    D3DERR_SCENE_IN_SCENE = 0x887602F8,
    D3DERR_SCENE_NOT_IN_SCENE = 0x887602F9,
    D3DERR_SETVIEWPORTDATA_FAILED = 0x887602DE,
    D3DERR_STENCILBUFFER_NOTPRESENT = 0x88760817,
    D3DERR_SURFACENOTINVIDMEM = 0x887602EB,
    D3DERR_TEXTURE_BADSIZE = 0x887602E2,
    D3DERR_TEXTURE_CREATE_FAILED = 0x887602D1,
    D3DERR_TEXTURE_DESTROY_FAILED = 0x887602D2,
    D3DERR_TEXTURE_GETSURF_FAILED = 0x887602D9,
    D3DERR_TEXTURE_LOAD_FAILED = 0x887602D5,
    D3DERR_TEXTURE_LOCKED = 0x887602D7,
    D3DERR_TEXTURE_LOCK_FAILED = 0x887602D3,
    D3DERR_TEXTURE_NOT_LOCKED = 0x887602D8,
    D3DERR_TEXTURE_NO_SUPPORT = 0x887602D0,
    D3DERR_TEXTURE_SWAP_FAILED = 0x887602D6,
    D3DERR_TEXTURE_UNLOCK_FAILED = 0x887602D4,
    D3DERR_TOOMANYOPERATIONS = 0x8876081D,
    D3DERR_TOOMANYPRIMITIVES = 0x88760823,
    D3DERR_TOOMANYVERTICES = 0x88760825,
    D3DERR_UNSUPPORTEDALPHAARG = 0x8876081C,
    D3DERR_UNSUPPORTEDALPHAOPERATION = 0x8876081B,
    D3DERR_UNSUPPORTEDCOLORARG = 0x8876081A,
    D3DERR_UNSUPPORTEDCOLOROPERATION = 0x88760819,
    D3DERR_UNSUPPORTEDFACTORVALUE = 0x8876081F,
    D3DERR_UNSUPPORTEDTEXTUREFILTER = 0x88760822,
    D3DERR_VBUF_CREATE_FAILED = 0x8876080D,
    D3DERR_VERTEXBUFFERLOCKED = 0x8876080E,
    D3DERR_VERTEXBUFFEROPTIMIZED = 0x8876080C,
    D3DERR_VERTEXBUFFERUNLOCKFAILED = 0x8876080F,
    D3DERR_VIEWPORTDATANOTSET = 0x88760305,
    D3DERR_VIEWPORTHASNODEVICE = 0x88760306,
    D3DERR_WRONGTEXTUREFORMAT = 0x88760818,
    D3DERR_ZBUFFER_NOTPRESENT = 0x88760816,
    D3DERR_ZBUFF_NEEDS_SYSTEMMEMORY = 0x887602E9,
    D3DERR_ZBUFF_NEEDS_VIDEOMEMORY = 0x887602EA,
		D3DERR_WASSTILLDRAWING = 0x8876021c,
		D3DOK_NOAUTOGEN = 0x0876086f,
    D3DFILL_POINT = 1,
    D3DFILL_SOLID = 3,
    D3DFILL_WIREFRAME = 2,
    D3DFMT_A16B16G16R16         = 36,
    D3DFMT_A16B16G16R16F        = 113,
    D3DFMT_A1R5G5B5 = 25,
    D3DFMT_A2B10G10R10          = 31,
    D3DFMT_A2R10G10B10          = 35,
    D3DFMT_A2W10V10U10          = 67,
    D3DFMT_A32B32G32R32F        = 116,
    D3DFMT_A4L4 = 52,
    D3DFMT_A4R4G4B4 = 26,
    D3DFMT_A8 = 28,
    D3DFMT_A8B8G8R8             = 32,
    D3DFMT_A8L8 = 51,
    D3DFMT_A8P8 = 40,
    D3DFMT_A8R3G3B2 = 29,
    D3DFMT_A8R8G8B8 = 21,
    D3DFMT_CxV8U8               = 117,
    D3DFMT_D15S1 = 73,
    D3DFMT_D16 = 80,
    D3DFMT_D16_LOCKABLE = 70,
    D3DFMT_D24FS8               = 83,
    D3DFMT_D24S8 = 75,
    D3DFMT_D24X4S4 = 79,
    D3DFMT_D24X8 = 77,
    D3DFMT_D32 = 71,
    D3DFMT_D32F_LOCKABLE        = 82,
    D3DFMT_DXT1 = 0x31545844,
    D3DFMT_DXT2 = 0x32545844,
    D3DFMT_DXT3 = 0x33545844,
    D3DFMT_DXT4 = 0x34545844,
    D3DFMT_DXT5 = 0x35545844,
    D3DFMT_G16R16               = 34,
    D3DFMT_G16R16F              = 112,
    D3DFMT_G32R32F              = 115,
    D3DFMT_G8R8_G8B8            = 0x42475247,
    D3DFMT_INDEX16 = 101,
    D3DFMT_INDEX32 = 102,
    D3DFMT_L16                  = 81,
    D3DFMT_L6V5U5 = 61,
    D3DFMT_L8 = 50,
    D3DFMT_MULTI2_ARGB8         = 0x3154454d,
    D3DFMT_P8 = 41,
    D3DFMT_Q16W16V16U16         =110,
    D3DFMT_Q8W8V8U8 = 63,
    D3DFMT_R16F                 = 111,
    D3DFMT_R32F                 = 114,
    D3DFMT_R3G3B2 = 27,
    D3DFMT_R5G6B5 = 23,
    D3DFMT_R8G8B8 = 20,
    D3DFMT_R8G8_B8G8            = 0x47424752,
    D3DFMT_UNKNOWN = 0,
    D3DFMT_UYVY = 0x59565955,
    D3DFMT_V16U16 = 64,
    D3DFMT_V8U8 = 60,
    D3DFMT_VERTEXDATA = 100,
    D3DFMT_W11V11U10 = 65,
    D3DFMT_X1R5G5B5 = 24,
    D3DFMT_X4R4G4B4 = 30,
    D3DFMT_X8B8G8R8             = 33,
    D3DFMT_X8L8V8U8 = 62,
    D3DFMT_X8R8G8B8 = 22,
    D3DFMT_YUY2 = 0x32595559,
    D3DFOG_EXP = 1,
    D3DFOG_EXP2 = 2,
    D3DFOG_LINEAR = 3,
    D3DFOG_NONE = 0,
    D3DFVFCAPS_DONOTSTRIPELEMENTS = 0x00080000,
    D3DFVFCAPS_PSIZE = 0x00100000,
    D3DFVFCAPS_TEXCOORDCOUNTMASK = 0x0000ffff,
    D3DFVF_DIFFUSE = 0x040,
    D3DFVF_LASTBETA_D3DCOLOR = 0x8000,
    D3DFVF_LASTBETA_UBYTE4 = 0x1000,
    D3DFVF_LVERTEX = 0x1e2,
    D3DFVF_NORMAL = 0x010,
    D3DFVF_POSITION_MASK = 0x00E,
    D3DFVF_PSIZE = 0x020,
    D3DFVF_RESERVED0 = 0x001,
    D3DFVF_SPECULAR = 0x080,
    D3DFVF_TEX0 = 0x000,
    D3DFVF_TEX1 = 0x100,
    D3DFVF_TEX2 = 0x200,
    D3DFVF_TEX3 = 0x300,
    D3DFVF_TEX4 = 0x400,
    D3DFVF_TEX5 = 0x500,
    D3DFVF_TEX6 = 0x600,
    D3DFVF_TEX7 = 0x700,
    D3DFVF_TEX8 = 0x800,
    D3DFVF_TEXCOUNT_MASK = 0xf00,
    D3DFVF_TEXCOUNT_SHIFT = 8,
    D3DFVF_TEXTUREFORMAT1 = 3,
    D3DFVF_TEXTUREFORMAT2 = 0,
    D3DFVF_TEXTUREFORMAT3 = 1,
    D3DFVF_TEXTUREFORMAT4 = 2,
    D3DFVF_TLVERTEX = 0x1c4,
    D3DFVF_VERTEX = 0x112,
    D3DFVF_XYZ = 0x002,
    D3DFVF_XYZB1 = 0x006,
    D3DFVF_XYZB2 = 0x008,
    D3DFVF_XYZB3 = 0x00a,
    D3DFVF_XYZB4 = 0x00c,
    D3DFVF_XYZB5 = 0x00e,
    D3DFVF_XYZRHW = 0x004,
		D3DFVF_RESERVED2 = 0xE000,
    D3DLIGHT_DIRECTIONAL = 3,
    D3DLIGHT_POINT = 1,
    D3DLIGHT_SPOT = 2,
    D3DLINECAPS_ALPHACMP = 0x00000008,
    D3DLINECAPS_ANTIALIAS = 0x00000020,
    D3DLINECAPS_BLEND = 0x00000004,
    D3DLINECAPS_FOG = 0x00000010,
    D3DLINECAPS_TEXTURE = 0x00000001,
    D3DLINECAPS_ZTEST = 0x00000002,
    D3DLOCK_DISCARD = 0x00002000,
    D3DLOCK_DONOTWAIT = 0x00004000,
    D3DLOCK_NOOVERWRITE = 0x00001000,
    D3DLOCK_NOSYSLOCK = 0x00000800,
    D3DLOCK_NO_DIRTY_UPDATE = 0x00008000,
    D3DLOCK_READONLY = 0x00000010,
    D3DMAXUSERCLIPPLANES = 32,
    D3DMCS_COLOR1 = 1,
    D3DMCS_COLOR2 = 2,
    D3DMCS_MATERIAL = 0,
    D3DMULTISAMPLE_10_SAMPLES = 10,
    D3DMULTISAMPLE_11_SAMPLES = 11,
    D3DMULTISAMPLE_12_SAMPLES = 12,
    D3DMULTISAMPLE_13_SAMPLES = 13,
    D3DMULTISAMPLE_14_SAMPLES = 14,
    D3DMULTISAMPLE_15_SAMPLES = 15,
    D3DMULTISAMPLE_16_SAMPLES = 16,
    D3DMULTISAMPLE_2_SAMPLES = 2,
    D3DMULTISAMPLE_3_SAMPLES = 3,
    D3DMULTISAMPLE_4_SAMPLES = 4,
    D3DMULTISAMPLE_5_SAMPLES = 5,
    D3DMULTISAMPLE_6_SAMPLES = 6,
    D3DMULTISAMPLE_7_SAMPLES = 7,
    D3DMULTISAMPLE_8_SAMPLES = 8,
    D3DMULTISAMPLE_9_SAMPLES = 9,
    D3DMULTISAMPLE_NONE = 0,
    D3DMULTISAMPLE_NONMASKABLE     =  1,
    D3DPATCHEDGE_CONTINUOUS = 1,
    D3DPATCHEDGE_DISCRETE = 0,
    D3DPBLENDCAPS_BLENDFACTOR = 0x00002000,
    D3DPBLENDCAPS_BOTHINVSRCALPHA = 0x00001000,
    D3DPBLENDCAPS_BOTHSRCALPHA = 0x00000800,
    D3DPBLENDCAPS_DESTALPHA = 0x00000040,
    D3DPBLENDCAPS_DESTCOLOR = 0x00000100,
    D3DPBLENDCAPS_INVDESTALPHA = 0x00000080,
    D3DPBLENDCAPS_INVDESTCOLOR = 0x00000200,
    D3DPBLENDCAPS_INVSRCALPHA = 0x00000020,
    D3DPBLENDCAPS_INVSRCCOLOR = 0x00000008,
    D3DPBLENDCAPS_ONE = 0x00000002,
    D3DPBLENDCAPS_SRCALPHA = 0x00000010,
    D3DPBLENDCAPS_SRCALPHASAT = 0x00000400,
    D3DPBLENDCAPS_SRCCOLOR = 0x00000004,
    D3DPBLENDCAPS_ZERO = 0x00000001,
    D3DPCMPCAPS_ALWAYS = 0x00000080,
    D3DPCMPCAPS_EQUAL = 0x00000004,
    D3DPCMPCAPS_GREATER = 0x00000010,
    D3DPCMPCAPS_GREATEREQUAL = 0x00000040,
    D3DPCMPCAPS_LESS = 0x00000002,
    D3DPCMPCAPS_LESSEQUAL = 0x00000008,
    D3DPCMPCAPS_NEVER = 0x00000001,
    D3DPCMPCAPS_NOTEQUAL = 0x00000020,
    D3DPMISCCAPS_BLENDOP = 0x00000800,
    D3DPMISCCAPS_CLIPPLANESCALEDPOINTS = 0x00000100,
    D3DPMISCCAPS_CLIPTLVERTS = 0x00000200,
    D3DPMISCCAPS_COLORWRITEENABLE = 0x00000080,
    D3DPMISCCAPS_CONFORMANT = 0x00000008,
    D3DPMISCCAPS_CULLCCW = 0x00000040,
    D3DPMISCCAPS_CULLCW = 0x00000020,
    D3DPMISCCAPS_CULLNONE = 0x00000010,
    D3DPMISCCAPS_FOGANDSPECULARALPHA = 0x00010000,
    D3DPMISCCAPS_FOGVERTEXCLAMPED = 0x00100000,
    D3DPMISCCAPS_INDEPENDENTWRITEMASKS = 0x00004000,
    D3DPMISCCAPS_LINEPATTERNREP = 0x00000004,
    D3DPMISCCAPS_MASKPLANES = 0x00000001,
    D3DPMISCCAPS_MASKZ = 0x00000002,
    D3DPMISCCAPS_MRTINDEPENDENTBITDEPTHS = 0x00040000,
    D3DPMISCCAPS_MRTPOSTPIXELSHADERBLENDING = 0x00080000,
    D3DPMISCCAPS_NULLREFERENCE = 0x00001000,
    D3DPMISCCAPS_PERSTAGECONSTANT = 0x00008000,
    D3DPMISCCAPS_SEPARATEALPHABLEND = 0x00020000,
    D3DPMISCCAPS_TSSARGTEMP = 0x00000400,
    D3DPOOL_DEFAULT = 0,
    D3DPOOL_MANAGED = 1,
    D3DPOOL_SCRATCH                 = 3,
    D3DPOOL_SYSTEMMEM = 2,
    D3DPRASTERCAPS_ANISOTROPY = 0x00020000,
    D3DPRASTERCAPS_ANTIALIASEDGES = 0x00001000,
    D3DPRASTERCAPS_ANTIALIASSORTDEPENDENT = 0x00000400,
    D3DPRASTERCAPS_ANTIALIASSORTINDEPENDENT = 0x00000800,
    D3DPRASTERCAPS_COLORPERSPECTIVE = 0x00400000,
    D3DPRASTERCAPS_DEPTHBIAS = 0x04000000,
    D3DPRASTERCAPS_DITHER = 0x00000001,
    D3DPRASTERCAPS_FOGRANGE = 0x00010000,
    D3DPRASTERCAPS_FOGTABLE = 0x00000100,
    D3DPRASTERCAPS_FOGVERTEX = 0x00000080,
    D3DPRASTERCAPS_MIPMAPLODBIAS = 0x00002000,
    D3DPRASTERCAPS_MULTISAMPLE_TOGGLE = 0x08000000,
    D3DPRASTERCAPS_PAT = 0x00000008,
    D3DPRASTERCAPS_ROP2 = 0x00000002,
    D3DPRASTERCAPS_SCISSORTEST = 0x01000000,
    D3DPRASTERCAPS_SLOPESCALEDEPTHBIAS = 0x02000000,
    D3DPRASTERCAPS_STIPPLE = 0x00000200,
    D3DPRASTERCAPS_STRETCHBLTMULTISAMPLE = 0x00800000,
    D3DPRASTERCAPS_SUBPIXEL = 0x00000020,
    D3DPRASTERCAPS_SUBPIXELX = 0x00000040,
    D3DPRASTERCAPS_TRANSLUCENTSORTINDEPENDENT = 0x00080000,
    D3DPRASTERCAPS_WBUFFER = 0x00040000,
    D3DPRASTERCAPS_WFOG = 0x00100000,
    D3DPRASTERCAPS_XOR = 0x00000004,
    D3DPRASTERCAPS_ZBIAS = 0x00004000,
    D3DPRASTERCAPS_ZBUFFERLESSHSR = 0x00008000,
    D3DPRASTERCAPS_ZFOG = 0x00200000,
    D3DPRASTERCAPS_ZTEST = 0x00000010,
    D3DPRESENTFLAG_DEVICECLIP = 0x00000004,
    D3DPRESENTFLAG_DISCARD_DEPTHSTENCIL = 0x00000002,
    D3DPRESENTFLAG_LOCKABLE_BACKBUFFER = 0x00000001,
    D3DPRESENTFLAG_VIDEO = 0x00000010,
    D3DPRESENT_INTERVAL_DEFAULT = 0x00000000,
    D3DPRESENT_INTERVAL_FOUR = 0x00000008,
    D3DPRESENT_INTERVAL_IMMEDIATE = 0x80000000,
    D3DPRESENT_INTERVAL_ONE = 0x00000001,
    D3DPRESENT_INTERVAL_THREE = 0x00000004,
    D3DPRESENT_INTERVAL_TWO = 0x00000002,
    D3DPRESENT_RATE_DEFAULT = 0x00000000,
    D3DPRESENT_RATE_UNLIMITED = 0x7fffffff,
    D3DPSHADECAPS_ALPHAFLATBLEND = 0x00001000,
    D3DPSHADECAPS_ALPHAFLATSTIPPLED = 0x00002000,
    D3DPSHADECAPS_ALPHAGOURAUDBLEND = 0x00004000,
    D3DPSHADECAPS_ALPHAGOURAUDSTIPPLED = 0x00008000,
    D3DPSHADECAPS_ALPHAPHONGBLEND = 0x00010000,
    D3DPSHADECAPS_ALPHAPHONGSTIPPLED = 0x00020000,
    D3DPSHADECAPS_COLORFLATMONO = 0x00000001,
    D3DPSHADECAPS_COLORFLATRGB = 0x00000002,
    D3DPSHADECAPS_COLORGOURAUDMONO = 0x00000004,
    D3DPSHADECAPS_COLORGOURAUDRGB = 0x00000008,
    D3DPSHADECAPS_COLORPHONGMONO = 0x00000010,
    D3DPSHADECAPS_COLORPHONGRGB = 0x00000020,
    D3DPSHADECAPS_FOGFLAT = 0x00040000,
    D3DPSHADECAPS_FOGGOURAUD = 0x00080000,
    D3DPSHADECAPS_FOGPHONG = 0x00100000,
    D3DPSHADECAPS_SPECULARFLATMONO = 0x00000040,
    D3DPSHADECAPS_SPECULARFLATRGB = 0x00000080,
    D3DPSHADECAPS_SPECULARGOURAUDMONO = 0x00000100,
    D3DPSHADECAPS_SPECULARGOURAUDRGB = 0x00000200,
    D3DPSHADECAPS_SPECULARPHONGMONO = 0x00000400,
    D3DPSHADECAPS_SPECULARPHONGRGB = 0x00000800,
    D3DPTADDRESSCAPS_BORDER = 0x00000008,
    D3DPTADDRESSCAPS_CLAMP = 0x00000004,
    D3DPTADDRESSCAPS_INDEPENDENTUV = 0x00000010,
    D3DPTADDRESSCAPS_MIRROR = 0x00000002,
    D3DPTADDRESSCAPS_MIRRORONCE = 0x00000020,
    D3DPTADDRESSCAPS_WRAP = 0x00000001,
    D3DPTEXTURECAPS_ALPHA = 0x00000004,
    D3DPTEXTURECAPS_ALPHAPALETTE = 0x00000080,
    D3DPTEXTURECAPS_BORDER = 0x00000010,
    D3DPTEXTURECAPS_COLORKEYBLEND = 0x00001000,
    D3DPTEXTURECAPS_CUBEMAP = 0x00000800,
    D3DPTEXTURECAPS_CUBEMAP_POW2 = 0x00020000,
    D3DPTEXTURECAPS_MIPCUBEMAP = 0x00010000,
    D3DPTEXTURECAPS_MIPMAP = 0x00004000,
    D3DPTEXTURECAPS_MIPVOLUMEMAP = 0x00008000,
    D3DPTEXTURECAPS_NONPOW2CONDITIONAL = 0x00000100,
    D3DPTEXTURECAPS_NOPROJECTEDBUMPENV = 0x00200000,
    D3DPTEXTURECAPS_PERSPECTIVE = 0x00000001,
    D3DPTEXTURECAPS_POW2 = 0x00000002,
    D3DPTEXTURECAPS_PROJECTED = 0x00000400,
    D3DPTEXTURECAPS_SQUAREONLY = 0x00000020,
    D3DPTEXTURECAPS_TEXREPEATNOTSCALEDBYSIZE = 0x00000040,
    D3DPTEXTURECAPS_TRANSPARENCY = 0x00000008,
    D3DPTEXTURECAPS_VOLUMEMAP = 0x00002000,
    D3DPTEXTURECAPS_VOLUMEMAP_POW2 = 0x00040000,

    D3DPTFILTERCAPS_NEAREST = 0x00000001,
    D3DPTFILTERCAPS_LINEAR = 0x00000002,
    D3DPTFILTERCAPS_MIPNEAREST = 0x00000004,
    D3DPTFILTERCAPS_MIPLINEAR = 0x00000008,
    D3DPTFILTERCAPS_LINEARMIPNEAREST = 0x00000010,
    D3DPTFILTERCAPS_LINEARMIPLINEAR = 0x00000020,
		D3DPTFILTERCAPS_MINFPOINT = 0x00000100,
		D3DPTFILTERCAPS_MINFLINEAR = 0x00000200,
		D3DPTFILTERCAPS_MINFANISOTROPIC = 0x00000400,
		D3DPTFILTERCAPS_MINFPYRAMIDALQUAD = 0x00000800,
		D3DPTFILTERCAPS_MINFGAUSSIANQUAD = 0x00001000,
		D3DPTFILTERCAPS_MIPFPOINT = 0x00010000,
		D3DPTFILTERCAPS_MIPFLINEAR = 0x00020000,
		D3DPTFILTERCAPS_MAGFPOINT = 0x01000000,
		D3DPTFILTERCAPS_MAGFLINEAR = 0x02000000,
		D3DPTFILTERCAPS_MAGFANISOTROPIC = 0x04000000,
		D3DPTFILTERCAPS_MAGFPYRAMIDALQUAD = 0x08000000,
    D3DPTFILTERCAPS_MAGFAFLATCUBIC = 0x08000000,
		D3DPTFILTERCAPS_MAGFGAUSSIANQUAD = 0x10000000,
    D3DPTFILTERCAPS_MAGFGAUSSIANCUBIC = 0x10000000,

    D3DPT_LINELIST = 2,
    D3DPT_LINESTRIP = 3,
    D3DPT_POINTLIST = 1,
    D3DPT_TRIANGLEFAN = 6,
    D3DPT_TRIANGLELIST = 4,
    D3DPT_TRIANGLESTRIP = 5,
    D3DPV_DONOTCOPYDATA = 1,
    D3DRENDERSTATE_WRAPBIAS = 128,
    D3DRS_ADAPTIVETESS_W            = 183,
    D3DRS_ADAPTIVETESS_X            = 180,
    D3DRS_ADAPTIVETESS_Y            = 181,
    D3DRS_ADAPTIVETESS_Z            = 182,
    D3DRS_ALPHABLENDENABLE = 27,
    D3DRS_ALPHAFUNC = 25,
    D3DRS_ALPHAREF = 24,
    D3DRS_ALPHATESTENABLE = 15,
    D3DRS_AMBIENT = 139,
    D3DRS_AMBIENTMATERIALSOURCE = 147,
    D3DRS_ANTIALIAS = 2,
    D3DRS_ANTIALIASEDLINEENABLE     = 176,
    D3DRS_BLENDFACTOR               = 193,
    D3DRS_BLENDOP = 171,
    D3DRS_BLENDOPALPHA              = 209,
    D3DRS_CCW_STENCILFAIL           = 186,
    D3DRS_CCW_STENCILFUNC           = 189,
    D3DRS_CCW_STENCILPASS           = 188,
    D3DRS_CCW_STENCILZFAIL          = 187,
    D3DRS_CLIPPING = 136,
    D3DRS_CLIPPLANEENABLE = 152,
    D3DRS_COLORKEYENABLE = 41,
    D3DRS_COLORVERTEX = 141,
    D3DRS_COLORWRITEENABLE = 168,
    D3DRS_COLORWRITEENABLE1         = 190,
    D3DRS_COLORWRITEENABLE2         = 191,
    D3DRS_COLORWRITEENABLE3         = 192,
    D3DRS_CULLMODE = 22,
		D3DRS_EXTENTS = 138,
    D3DRS_DEBUGMONITORTOKEN = 165,
    D3DRS_DEPTHBIAS                 = 195,
    D3DRS_DESTBLEND = 20,
    D3DRS_DESTBLENDALPHA            = 208,
    D3DRS_DIFFUSEMATERIALSOURCE = 145,
    D3DRS_DITHERENABLE = 26,
    D3DRS_EDGEANTIALIAS = 40,
    D3DRS_EMISSIVEMATERIALSOURCE = 148,
    D3DRS_ENABLEADAPTIVETESSELLATION = 184,
    D3DRS_FILLMODE = 8,
    D3DRS_FOGCOLOR = 34,
    D3DRS_FOGDENSITY = 38,
    D3DRS_FOGENABLE = 28,
    D3DRS_FOGEND = 37,
    D3DRS_FOGSTART = 36,
    D3DRS_FOGTABLEMODE = 35,
    D3DRS_FOGVERTEXMODE = 140,
    D3DRS_INDEXEDVERTEXBLENDENABLE = 167,
    D3DRS_LASTPIXEL = 16,
    D3DRS_LIGHTING = 137,
    D3DRS_LINEPATTERN = 10,
    D3DRS_LOCALVIEWER = 142,
    D3DRS_MAXTESSELLATIONLEVEL      = 179,
    D3DRS_MINTESSELLATIONLEVEL      = 178,
    D3DRS_MULTISAMPLEANTIALIAS = 161,
    D3DRS_MULTISAMPLEMASK = 162,
    D3DRS_NORMALDEGREE              = 173,
    D3DRS_NORMALIZENORMALS = 143,
    D3DRS_PATCHEDGESTYLE = 163,
    D3DRS_PATCHSEGMENTS = 164,
    D3DRS_POINTSCALEENABLE = 157,
    D3DRS_POINTSCALE_A = 158,
    D3DRS_POINTSCALE_B = 159,
    D3DRS_POINTSCALE_C = 160,
    D3DRS_POINTSIZE = 154,
    D3DRS_POINTSIZE_MAX = 166,
    D3DRS_POINTSIZE_MIN = 155,
    D3DRS_POINTSPRITEENABLE = 156,
    D3DRS_POSITIONDEGREE            = 172,
    D3DRS_RANGEFOGENABLE = 48,
    D3DRS_SCISSORTESTENABLE         = 174,
    D3DRS_SEPARATEALPHABLENDENABLE  = 206,
    D3DRS_SHADEMODE = 9,
    D3DRS_SLOPESCALEDEPTHBIAS       = 175,
    D3DRS_SOFTWAREVERTEXPROCESSING = 153,
    D3DRS_SPECULARENABLE = 29,
    D3DRS_SPECULARMATERIALSOURCE = 146,
    D3DRS_SRCBLEND = 19,
    D3DRS_SRCBLENDALPHA             = 207,
    D3DRS_SRGBWRITEENABLE           = 194,
    D3DRS_STENCILENABLE = 52,
    D3DRS_STENCILFAIL = 53,
    D3DRS_STENCILFUNC = 56,
    D3DRS_FOGTABLESTART      = 36,
    D3DRS_FOGTABLEEND        = 37,
    D3DRS_FOGTABLEDENSITY    = 38,
    D3DRS_TEXTUREHANDLE      = 1,
    D3DRS_TEXTUREADDRESS     = 3,
    D3DRS_WRAPU              = 5,
    D3DRS_WRAPV              = 6,
    D3DRS_MONOENABLE         = 11,
    D3DRS_ROP2               = 12,
    D3DRS_PLANEMASK          = 13,
    D3DRS_TEXTUREMAG         = 17,
    D3DRS_TEXTUREMIN         = 18,
    D3DRS_TEXTUREMAPBLEND    = 21,
    D3DRS_SUBPIXEL           = 31,
    D3DRS_SUBPIXELX          = 32,
    D3DRS_STIPPLEENABLE      = 39,
    D3DRS_BORDERCOLOR        = 43,
    D3DRS_TEXTUREADDRESSU    = 44,
    D3DRS_TEXTUREADDRESSV    = 45,
    D3DRS_MIPMAPLODBIAS      = 46,
    D3DRS_ANISOTROPY         = 49,
    D3DRS_FLUSHBATCH         = 50,
    D3DRS_TRANSLUCENTSORTINDEPENDENT = 51,
    D3DRS_STIPPLEPATTERN00   = 64,
    D3DRS_STIPPLEPATTERN01   = 65,
    D3DRS_STIPPLEPATTERN02   = 66,
    D3DRS_STIPPLEPATTERN03   = 67,
    D3DRS_STIPPLEPATTERN04   = 68,
    D3DRS_STIPPLEPATTERN05   = 69,
    D3DRS_STIPPLEPATTERN06   = 70,
    D3DRS_STIPPLEPATTERN07   = 71,
    D3DRS_STIPPLEPATTERN08   = 72,
    D3DRS_STIPPLEPATTERN09   = 73,
    D3DRS_STIPPLEPATTERN10   = 74,
    D3DRS_STIPPLEPATTERN11   = 75,
    D3DRS_STIPPLEPATTERN12   = 76,
    D3DRS_STIPPLEPATTERN13   = 77,
    D3DRS_STIPPLEPATTERN14   = 78,
    D3DRS_STIPPLEPATTERN15   = 79,
    D3DRS_STIPPLEPATTERN16   = 80,
    D3DRS_STIPPLEPATTERN17   = 81,
    D3DRS_STIPPLEPATTERN18   = 82,
    D3DRS_STIPPLEPATTERN19   = 83,
    D3DRS_STIPPLEPATTERN20   = 84,
    D3DRS_STIPPLEPATTERN21   = 85,
    D3DRS_STIPPLEPATTERN22   = 86,
    D3DRS_STIPPLEPATTERN23   = 87,
    D3DRS_STIPPLEPATTERN24   = 88,
    D3DRS_STIPPLEPATTERN25   = 89,
    D3DRS_STIPPLEPATTERN26   = 90,
    D3DRS_STIPPLEPATTERN27   = 91,
    D3DRS_STIPPLEPATTERN28   = 92,
    D3DRS_STIPPLEPATTERN29   = 93,
    D3DRS_STIPPLEPATTERN30   = 94,
    D3DRS_STIPPLEPATTERN31   = 95,
		D3DRS_BLENDENABLE = 27,
    D3DRS_COLORKEYBLENDENABLE = 144,
    D3DRS_STENCILMASK = 58,
    D3DRS_STENCILPASS = 55,
    D3DRS_STENCILREF = 57,
    D3DRS_STENCILWRITEMASK = 59,
    D3DRS_STENCILZFAIL = 54,
    D3DRS_STIPPLEDALPHA = 33,
    D3DRS_TEXTUREFACTOR = 60,
    D3DRS_TEXTUREPERSPECTIVE = 4,
    D3DRS_TWEENFACTOR = 170,
    D3DRS_TWOSIDEDSTENCILMODE       = 185,
    D3DRS_VERTEXBLEND = 151,
    D3DRS_WRAP0 = 128,
    D3DRS_WRAP1 = 129,
    D3DRS_WRAP10                    = 200,
    D3DRS_WRAP11                    = 201,
    D3DRS_WRAP12                    = 202,
    D3DRS_WRAP13                    = 203,
    D3DRS_WRAP14                    = 204,
    D3DRS_WRAP15                    = 205,
    D3DRS_WRAP2 = 130,
    D3DRS_WRAP3 = 131,
    D3DRS_WRAP4 = 132,
    D3DRS_WRAP5 = 133,
    D3DRS_WRAP6 = 134,
    D3DRS_WRAP7 = 135,
    D3DRS_WRAP8                     = 198,
    D3DRS_WRAP9                     = 199,
    D3DRS_ZBIAS = 47,
    D3DRS_ZENABLE = 7,
    D3DRS_ZFUNC = 23,
    D3DRS_ZVISIBLE = 30,
    D3DRS_ZWRITEENABLE = 14,
    D3DRTYPE_CUBETEXTURE = 5,
    D3DRTYPE_INDEXBUFFER = 7,
    D3DRTYPE_SURFACE = 1,
    D3DRTYPE_TEXTURE = 3,
    D3DRTYPE_VERTEXBUFFER = 6,
    D3DRTYPE_VOLUME = 2,
    D3DRTYPE_VOLUMETEXTURE = 4,
    D3DSBT_ALL = 1,
    D3DSBT_PIXELSTATE = 2,
    D3DSBT_VERTEXSTATE = 3,
    D3DSGR_CALIBRATE = 1,
    D3DSGR_NO_CALIBRATION = 0,
    D3DSHADE_FLAT = 1,
    D3DSHADE_GOURAUD = 2,
    D3DSHADE_PHONG = 3,
    D3DSIO_ABS = 35,
    D3DSIO_ADD = 2,
    D3DSIO_BEM = 89,
    D3DSIO_BREAK = 44,
    D3DSIO_BREAKC = 45,
    D3DSIO_BREAKP = 96,
    D3DSIO_CALL = 25,
    D3DSIO_CALLNZ = 26,
    D3DSIO_CMP = 88,
    D3DSIO_CND = 80,
    D3DSIO_COMMENT      = 0xFFFE,
    D3DSIO_CRS = 33,
    D3DSIO_DCL = 31,
    D3DSIO_DEF = 81,
    D3DSIO_DEFB = 47,
    D3DSIO_DEFI = 48,
    D3DSIO_DP2ADD = 90,
    D3DSIO_DP3 = 8,
    D3DSIO_DP4 = 9,
    D3DSIO_DST = 17,
    D3DSIO_DSX = 91,
    D3DSIO_DSY = 92,
    D3DSIO_ELSE = 42,
    D3DSIO_END          = 0xFFFF,
    D3DSIO_ENDIF = 43,
    D3DSIO_ENDLOOP = 29,
    D3DSIO_ENDREP = 39,
    D3DSIO_EXP = 14,
    D3DSIO_EXPP = 78,
    D3DSIO_FRC = 19,
    D3DSIO_IF = 40,
    D3DSIO_IFC = 41,
    D3DSIO_LABEL = 30,
    D3DSIO_LIT = 16,
    D3DSIO_LOG = 15,
    D3DSIO_LOGP = 79,
    D3DSIO_LOOP = 27,
    D3DSIO_LRP = 18,
    D3DSIO_M3x2 = 24,
    D3DSIO_M3x3 = 23,
    D3DSIO_M3x4 = 22,
    D3DSIO_M4x3 = 21,
    D3DSIO_M4x4 = 20,
    D3DSIO_MAD = 4,
    D3DSIO_MAX = 11,
    D3DSIO_MIN = 10,
    D3DSIO_MOV = 1,
    D3DSIO_MOVA = 46,
    D3DSIO_MUL = 5,
    D3DSIO_NOP = 0,
    D3DSIO_NRM = 36,
    D3DSIO_PHASE        = 0xFFFD,
    D3DSIO_POW = 32,
    D3DSIO_RCP = 6,
    D3DSIO_REP = 38,
    D3DSIO_RET = 28,
    D3DSIO_RSQ = 7,
    D3DSIO_SETP = 94,
    D3DSIO_SGE = 13,
    D3DSIO_SGN = 34,
    D3DSIO_SINCOS = 37,
    D3DSIO_SLT = 12,
    D3DSIO_SUB = 3,
    D3DSIO_TEX = 66,
    D3DSIO_TEXBEM = 67,
    D3DSIO_TEXBEML = 68,
    D3DSIO_TEXCOORD = 64,
    D3DSIO_TEXDEPTH = 87,
    D3DSIO_TEXDP3 = 85,
    D3DSIO_TEXDP3TEX = 83,
    D3DSIO_TEXKILL = 65,
    D3DSIO_TEXLDD = 93,
    D3DSIO_TEXLDL = 95,
    D3DSIO_TEXM3x2DEPTH = 84,
    D3DSIO_TEXM3x2PAD = 71,
    D3DSIO_TEXM3x2TEX = 72,
    D3DSIO_TEXM3x3 = 86,
    D3DSIO_TEXM3x3DIFF = 75,
    D3DSIO_TEXM3x3PAD = 73,
    D3DSIO_TEXM3x3SPEC = 76,
    D3DSIO_TEXM3x3TEX = 74,
    D3DSIO_TEXM3x3VSPEC = 77,
    D3DSIO_TEXREG2AR = 69,
    D3DSIO_TEXREG2GB = 70,
    D3DSIO_TEXREG2RGB = 82,
    D3DSI_COISSUE = 0x40000000,
    D3DSI_COMMENTSIZE_MASK = 0x7FFF0000,
    D3DSI_COMMENTSIZE_SHIFT = 16,
    D3DSI_OPCODE_MASK       = 0x0000FFFF,
    D3DSPDM_MSAMPCENTROID = 0x400000,
    D3DSPDM_NONE = 0,
    D3DSPDM_PARTIALPRECISION = 0x200000,
    D3DSPDM_SATURATE = 0x100000,
    D3DSPD_IUNKNOWN = 1,
    D3DSPR_TEMP           = 0x000000000,
    D3DSPR_INPUT          = 0x010000000,
    D3DSPR_CONST          = 0x020000000,
    D3DSPR_ADDR           = 0x030000000,
    D3DSPR_TEXTURE        = 0x030000000,
    D3DSPR_RASTOUT        = 0x040000000,
    D3DSPR_ATTROUT        = 0x050000000,
    D3DSPR_TEXCRDOUT      = 0x060000000,
    D3DSPR_OUTPUT         = 0x060000000,
    D3DSPR_CONSTINT       = 0x070000000,
    D3DSPR_COLOROUT       = 0x080000000,
    D3DSPR_DEPTHOUT       = 0x090000000,
    D3DSPR_SAMPLER        = 0x0A0000000,
    D3DSPR_CONST2         = 0x0B0000000,
    D3DSPR_CONST3         = 0x0C0000000,
    D3DSPR_CONST4         = 0x0D0000000,
    D3DSPR_CONSTBOOL      = 0x0E0000000,
    D3DSPR_LOOP           = 0x0F0000000,
    // D3DSPR_TEMPFLOAT16    = 0x100000000,
    // D3DSPR_MISCTYPE       = 0x110000000,
    // D3DSPR_LABEL          = 0x120000000,
    // D3DSPR_PREDICATE      = 0x130000000,
    D3DSPSM_ABS     = 0xB000000,
    D3DSPSM_ABSNEG  = 0xC000000,
    D3DSPSM_BIAS = 0x2000000,
    D3DSPSM_BIASNEG = 0x3000000,
    D3DSPSM_COMP = 0x6000000,
    D3DSPSM_DW      = 0xA000000,
    D3DSPSM_DZ      = 0x9000000,
    D3DSPSM_NEG = 0x1000000,
    D3DSPSM_NONE = 0,
    D3DSPSM_NOT     = 0xD000000,
    D3DSPSM_SIGN = 0x4000000,
    D3DSPSM_SIGNNEG = 0x5000000,
    D3DSPSM_X2      = 0x7000000,
    D3DSPSM_X2NEG   = 0x8000000,
    D3DSP_DSTMOD_MASK = 0x00F00000,
    D3DSP_DSTMOD_SHIFT = 20,
    D3DSP_DSTSHIFT_MASK = 0x0F000000,
    D3DSP_DSTSHIFT_SHIFT = 24,
    D3DSP_NOSWIZZLE = 0xE40000,
    D3DSP_REGNUM_MASK = 0x00000FFF,
    D3DSP_REGTYPE_MASK = 0x70000000,
    D3DSP_REGTYPE_MASK2 = 0x00001800,
    D3DSP_REGTYPE_SHIFT = 28,
    D3DSP_REGTYPE_SHIFT2 = 8,
    D3DSP_REPLICATEALPHA = 0xFF0000,
    D3DSP_SRCMOD_MASK = 0x0F000000,
    D3DSP_SRCMOD_SHIFT = 24,
    D3DSP_SWIZZLE_MASK = 0x00FF0000,
    D3DSP_SWIZZLE_SHIFT = 16,
    D3DSP_WRITEMASK_0 = 0x00010000,
    D3DSP_WRITEMASK_1 = 0x00020000,
    D3DSP_WRITEMASK_2 = 0x00040000,
    D3DSP_WRITEMASK_3 = 0x00080000,
    D3DSP_WRITEMASK_ALL = 0x000F0000,
    D3DSRO_FOG = 1,
    D3DSRO_POINT_SIZE = 2,
    D3DSRO_POSITION = 0,
    D3DSTENCILCAPS_DECR = 0x00000080,
    D3DSTENCILCAPS_DECRSAT = 0x00000010,
    D3DSTENCILCAPS_INCR = 0x00000040,
    D3DSTENCILCAPS_INCRSAT = 0x00000008,
    D3DSTENCILCAPS_INVERT = 0x00000020,
    D3DSTENCILCAPS_KEEP = 0x00000001,
    D3DSTENCILCAPS_REPLACE = 0x00000004,
    D3DSTENCILCAPS_TWOSIDED = 0x00000100,
    D3DSTENCILCAPS_ZERO = 0x00000002,
    D3DSTENCILOP_DECR = 8,
    D3DSTENCILOP_DECRSAT = 5,
    D3DSTENCILOP_INCR = 7,
    D3DSTENCILOP_INCRSAT = 4,
    D3DSTENCILOP_INVERT = 6,
    D3DSTENCILOP_KEEP = 1,
    D3DSTENCILOP_REPLACE = 3,
    D3DSTENCILOP_ZERO = 2,
    D3DSWAPEFFECT_COPY = 3,
    D3DSWAPEFFECT_COPY_VSYNC = 4,
    D3DSWAPEFFECT_DISCARD = 1,
    D3DSWAPEFFECT_FLIP = 2,
    D3DTADDRESS_BORDER = 4,
    D3DTADDRESS_CLAMP = 3,
    D3DTADDRESS_MIRROR = 2,
    D3DTADDRESS_MIRRORONCE = 5,
    D3DTADDRESS_WRAP = 1,
    D3DTA_ALPHAREPLICATE = 0x00000020,
    D3DTA_COMPLEMENT = 0x00000010,
    D3DTA_CONSTANT = 0x00000006,
    D3DTA_CURRENT = 0x00000001,
    D3DTA_DIFFUSE = 0x00000000,
    D3DTA_SELECTMASK = 0x0000000f,
    D3DTA_SPECULAR = 0x00000004,
    D3DTA_TEMP = 0x00000005,
    D3DTA_TEXTURE = 0x00000002,
    D3DTA_TFACTOR = 0x00000003,
    D3DTEXF_ANISOTROPIC = 3,
    D3DTEXF_FLATCUBIC = 4,
    D3DTEXF_GAUSSIANCUBIC = 5,
    D3DTEXF_GAUSSIANQUAD    = 7,
    D3DTEXF_LINEAR = 2,
    D3DTEXF_NONE = 0,
    D3DTEXF_POINT = 1,
    D3DTEXF_PYRAMIDALQUAD   = 6,
    D3DTEXOPCAPS_ADD = 0x00000040,
    D3DTEXOPCAPS_ADDSIGNED = 0x00000080,
    D3DTEXOPCAPS_ADDSIGNED2X = 0x00000100,
    D3DTEXOPCAPS_ADDSMOOTH = 0x00000400,
    D3DTEXOPCAPS_BLENDCURRENTALPHA = 0x00008000,
    D3DTEXOPCAPS_BLENDDIFFUSEALPHA = 0x00000800,
    D3DTEXOPCAPS_BLENDFACTORALPHA = 0x00002000,
    D3DTEXOPCAPS_BLENDTEXTUREALPHA = 0x00001000,
    D3DTEXOPCAPS_BLENDTEXTUREALPHAPM = 0x00004000,
    D3DTEXOPCAPS_BUMPENVMAP = 0x00200000,
    D3DTEXOPCAPS_BUMPENVMAPLUMINANCE = 0x00400000,
    D3DTEXOPCAPS_DISABLE = 0x00000001,
    D3DTEXOPCAPS_DOTPRODUCT3 = 0x00800000,
    D3DTEXOPCAPS_LERP = 0x02000000,
    D3DTEXOPCAPS_MODULATE = 0x00000008,
    D3DTEXOPCAPS_MODULATE2X = 0x00000010,
    D3DTEXOPCAPS_MODULATE4X = 0x00000020,
    D3DTEXOPCAPS_MODULATEALPHA_ADDCOLOR = 0x00020000,
    D3DTEXOPCAPS_MODULATECOLOR_ADDALPHA = 0x00040000,
    D3DTEXOPCAPS_MODULATEINVALPHA_ADDCOLOR = 0x00080000,
    D3DTEXOPCAPS_MODULATEINVCOLOR_ADDALPHA = 0x00100000,
    D3DTEXOPCAPS_MULTIPLYADD = 0x01000000,
    D3DTEXOPCAPS_PREMODULATE = 0x00010000,
    D3DTEXOPCAPS_SELECTARG1 = 0x00000002,
    D3DTEXOPCAPS_SELECTARG2 = 0x00000004,
    D3DTEXOPCAPS_SUBTRACT = 0x00000200,
    D3DTOP_ADD = 7,
    D3DTOP_ADDSIGNED = 8,
    D3DTOP_ADDSIGNED2X = 9,
    D3DTOP_ADDSMOOTH = 11,
    D3DTOP_BLENDCURRENTALPHA = 16,
    D3DTOP_BLENDDIFFUSEALPHA = 12,
    D3DTOP_BLENDFACTORALPHA = 14,
    D3DTOP_BLENDTEXTUREALPHA = 13,
    D3DTOP_BLENDTEXTUREALPHAPM = 15,
    D3DTOP_BUMPENVMAP = 22,
    D3DTOP_BUMPENVMAPLUMINANCE = 23,
    D3DTOP_DISABLE = 1,
    D3DTOP_DOTPRODUCT3 = 24,
    D3DTOP_LERP = 26,
    D3DTOP_MODULATE = 4,
    D3DTOP_MODULATE2X = 5,
    D3DTOP_MODULATE4X = 6,
    D3DTOP_MODULATEALPHA_ADDCOLOR = 18,
    D3DTOP_MODULATECOLOR_ADDALPHA = 19,
    D3DTOP_MODULATEINVALPHA_ADDCOLOR = 20,
    D3DTOP_MODULATEINVCOLOR_ADDALPHA = 21,
    D3DTOP_MULTIPLYADD = 25,
    D3DTOP_PREMODULATE = 17,
    D3DTOP_SELECTARG1 = 2,
    D3DTOP_SELECTARG2 = 3,
    D3DTOP_SUBTRACT = 10,
    D3DTSS_ADDRESS = 12,
    D3DTSS_ADDRESSU = 13,
    D3DTSS_ADDRESSV = 14,
    D3DTSS_ADDRESSW = 25,
    D3DTSS_ALPHAARG0 = 27,
    D3DTSS_ALPHAARG1 = 5,
    D3DTSS_ALPHAARG2 = 6,
    D3DTSS_ALPHAOP = 4,
    D3DTSS_BORDERCOLOR = 15,
    D3DTSS_BUMPENVLOFFSET = 23,
    D3DTSS_BUMPENVLSCALE = 22,
    D3DTSS_BUMPENVMAT00 = 7,
    D3DTSS_BUMPENVMAT01 = 8,
    D3DTSS_BUMPENVMAT10 = 9,
    D3DTSS_BUMPENVMAT11 = 10,
    D3DTSS_COLORARG0      = 26,
    D3DTSS_COLORARG1 = 2,
    D3DTSS_COLORARG2 = 3,
    D3DTSS_COLOROP = 1,
    D3DTSS_CONSTANT       = 32,
    D3DTSS_MAGFILTER = 16,
    D3DTSS_MAXANISOTROPY = 21,
    D3DTSS_MAXMIPLEVEL = 20,
    D3DTSS_MINFILTER = 17,
    D3DTSS_MIPFILTER = 18,
    D3DTSS_MIPMAPLODBIAS = 19,
    D3DTSS_RESULTARG      = 28,
    D3DTSS_TCI_CAMERASPACENORMAL = 0x10000,
    D3DTSS_TCI_CAMERASPACEPOSITION = 0x20000,
    D3DTSS_TCI_CAMERASPACEREFLECTIONVECTOR = 0x30000,
    D3DTSS_TCI_PASSTHRU = 0x00000,
    D3DTSS_TCI_SPHEREMAP = 0x00040000,
    D3DTSS_TEXCOORDINDEX = 11,
    D3DTSS_TEXTURETRANSFORMFLAGS = 24,
    D3DTS_PROJECTION = 3,
    D3DTS_TEXTURE0 = 16,
    D3DTS_TEXTURE1 = 17,
    D3DTS_TEXTURE2 = 18,
    D3DTS_TEXTURE3 = 19,
    D3DTS_TEXTURE4 = 20,
    D3DTS_TEXTURE5 = 21,
    D3DTS_TEXTURE6 = 22,
    D3DTS_TEXTURE7 = 23,
    D3DTS_VIEW = 2,
    D3DTS_WORLD = 256,
    D3DTS_WORLD1 = 257,
    D3DTS_WORLD2 = 258,
    D3DTS_WORLD3 = 259,
    D3DTTFF_COUNT1 = 1,
    D3DTTFF_COUNT2 = 2,
    D3DTTFF_COUNT3 = 3,
    D3DTTFF_COUNT4 = 4,
    D3DTTFF_DISABLE = 0,
    D3DTTFF_PROJECTED = 256,
    D3DUSAGE_AUTOGENMIPMAP = 0x00000400,
    D3DUSAGE_DEPTHSTENCIL = 0x2,
    D3DUSAGE_DMAP = 0x00004000,
    D3DUSAGE_DONOTCLIP = 0x00000020,
    D3DUSAGE_DYNAMIC = 0x00000200,
    D3DUSAGE_NPATCHES = 0x00000100,
    D3DUSAGE_POINTS = 0x00000040,
    D3DUSAGE_QUERY_FILTER = 0x00020000,
    D3DUSAGE_QUERY_LEGACYBUMPMAP = 0x00008000,
    D3DUSAGE_QUERY_POSTPIXELSHADER_BLENDING = 0x00080000,
    D3DUSAGE_QUERY_SRGBREAD = 0x00010000,
    D3DUSAGE_QUERY_SRGBWRITE = 0x00040000,
    D3DUSAGE_QUERY_VERTEXTEXTURE = 0x00100000,
    D3DUSAGE_QUERY_WRAPANDMIP = 0x00200000,
    D3DUSAGE_RENDERTARGET = 0x1,
    D3DUSAGE_RTPATCHES = 0x00000080,
    D3DUSAGE_SOFTWAREPROCESSING = 0x00000010,
    D3DUSAGE_WRITEONLY = 0x8,
    D3DVBF_0WEIGHTS = 256,
    D3DVBF_1WEIGHTS = 1,
    D3DVBF_2WEIGHTS = 2,
    D3DVBF_3WEIGHTS = 3,
    D3DVBF_DISABLE = 0,
    D3DVBF_TWEENING = 255,
    D3DVS_ADDRESSMODE_MASK = 0x2000,
    D3DVS_ADDRESSMODE_SHIFT = 13,
    D3DVS_ADDRMODE_ABSOLUTE = 0,
    D3DVS_ADDRMODE_RELATIVE = 0x2000,
    D3DVS_NOSWIZZLE = 0xE40000,
    D3DVS_SWIZZLE_MASK = 0x00FF0000,
    D3DVS_SWIZZLE_SHIFT = 16,
    D3DVS_W_W = 0xC00000,
    D3DVS_W_X = 0,
    D3DVS_W_Y = 0x400000,
    D3DVS_W_Z = 0x800000,
    D3DVS_X_W = 0x30000,
    D3DVS_X_X = 0,
    D3DVS_X_Y = 0x10000,
    D3DVS_X_Z = 0x20000,
    D3DVS_Y_W = 0xC0000,
    D3DVS_Y_X = 0,
    D3DVS_Y_Y = 0x40000,
    D3DVS_Y_Z = 0x80000,
    D3DVS_Z_W = 0x300000,
    D3DVS_Z_X = 0,
    D3DVS_Z_Y = 0x100000,
    D3DVS_Z_Z = 0x200000,
    D3DVTXPCAPS_DIRECTIONALLIGHTS = 0x00000008,
    D3DVTXPCAPS_LOCALVIEWER = 0x00000020,
    D3DVTXPCAPS_MATERIALSOURCE7 = 0x00000002,
    D3DVTXPCAPS_NO_TEXGEN_NONLOCALVIEWER = 0x00000200,
    D3DVTXPCAPS_NO_VSDT_UBYTE4 = 0x00000080,
    D3DVTXPCAPS_POSITIONALLIGHTS = 0x00000010,
    D3DVTXPCAPS_TEXGEN = 0x00000001,
    D3DVTXPCAPS_TEXGEN_SPHEREMAP = 0x00000100,
    D3DVTXPCAPS_TWEENING = 0x00000040,
    D3DVTXPCAPS_VERTEXFOG = 0x00000004,
    D3DWRAPCOORD_0 = 1,
    D3DWRAPCOORD_1 = 2,
    D3DWRAPCOORD_2 = 4,
    D3DWRAPCOORD_3 = 8,
    D3DWRAP_U = 1,
    D3DWRAP_V = 2,
    D3DWRAP_W = 4,
    D3DZB_FALSE = 0,
    D3DZB_TRUE = 1,
    D3DZB_USEW = 2,
    D3D_OK = 0,
    MAX_DEVICE_IDENTIFIER_STRING = 512
	};

	typedef struct D3DVECTOR {
    union {  float x;  float dvX;  };
    union {  float y;  float dvY;  };
    union {  float z;  float dvZ;  };
	} D3DVECTOR;

	typedef struct D3DXVECTOR4 {
        float x, y, z, w;
	} D3DXVECTOR4, *LPD3DXVECTOR4;

	typedef struct D3DCOLORVALUE {
    union {  float r;  float dvR;  };
    union {  float g;  float dvG;  };
    union {  float b;  float dvB;  };
    union {  float a;  float dvA;  };
	} D3DCOLORVALUE;

	typedef struct D3DRECT {
    union {  int32_t x1;  int32_t lX1;  };
    union {  int32_t y1;  int32_t lY1;  };
    union {  int32_t x2;  int32_t lX2;  };
    union {  int32_t y2;  int32_t lY2;  };
	} D3DRECT;

	typedef union D3DMATRIX {
		struct {
			float _11, _12, _13, _14;
			float _21, _22, _23, _24;
			float _31, _32, _33, _34;
			float _41, _42, _43, _44;
		};
		float m[4][4];
	} D3DMATRIX, D3DXMATRIX;

	typedef struct D3DGAMMARAMP { uint16_t red[256], green[256], blue[256]; } D3DGAMMARAMP;
	typedef struct D3DLINEPATTERN { uint16_t wRepeatFactor, wLinePattern; } D3DLINEPATTERN;
	typedef struct D3DDISPLAYMODE { uint32_t Width, Height, RefreshRate; D3Denum Format; } D3DDISPLAYMODE;
	typedef struct D3DBOX { uint32_t Left, Top, Right, Bottom, Front, Back; } D3DBOX;
	typedef struct D3DLOCKED_RECT { int32_t Pitch; void* pBits; } D3DLOCKED_RECT;
	typedef struct D3DLOCKED_BOX { int32_t RowPitch, SlicePitch; void* pBits; } D3DLOCKED_BOX;
	typedef struct D3DRANGE { uint32_t Offset, Size; } D3DRANGE;
	typedef struct D3DRASTER_STATUS {  bool32 InVBlank; uint32_t ScanLine; } D3DRASTER_STATUS;

    typedef LPCSTR D3DXHANDLE;

]]