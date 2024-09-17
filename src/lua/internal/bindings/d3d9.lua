local ffi = require 'ffi'
local com = require 'winapi.com'

ffi.cdef [[

	enum {
		D3D9SDK_VERSION = 32,
		D3DENUM_WHQL_LEVEL = 2,
		D3DPRESENT_DONOTWAIT = 1,
		D3DPRESENT_LINEAR_CONTENT = 2,
		D3DDEVCAPS2_STREAMOFFSET = 0x00000001,
		D3DDEVCAPS2_DMAPNPATCH = 0x00000002,
		D3DDEVCAPS2_ADAPTIVETESSRTPATCH = 0x00000004,
		D3DDEVCAPS2_ADAPTIVETESSNPATCH = 0x00000008,
		D3DDEVCAPS2_CAN_STRETCHRECT_FROM_TEXTURES = 0x00000010,
		D3DDEVCAPS2_PRESAMPLEDDMAPNPATCH = 0x00000020,
		D3DDEVCAPS2_VERTEXELEMENTSCANSHARESTREAMOFFSET = 0x00000040,
		D3DDTCAPS_UBYTE4 = 0x00000001,
		D3DDTCAPS_UBYTE4N = 0x00000002,
		D3DDTCAPS_SHORT2N = 0x00000004,
		D3DDTCAPS_SHORT4N = 0x00000008,
		D3DDTCAPS_USHORT2N = 0x00000010,
		D3DDTCAPS_USHORT4N = 0x00000020,
		D3DDTCAPS_UDEC3 = 0x00000040,
		D3DDTCAPS_DEC3N = 0x00000080,
		D3DDTCAPS_FLOAT16_2 = 0x00000100,
		D3DDTCAPS_FLOAT16_4 = 0x00000200,
		D3D_MAX_SIMULTANEOUS_RENDERTARGETS = 4,
    D3DSAMP_ADDRESSU       = 1,
    D3DSAMP_ADDRESSV       = 2,
    D3DSAMP_ADDRESSW       = 3,
    D3DSAMP_BORDERCOLOR    = 4,
    D3DSAMP_MAGFILTER      = 5,
    D3DSAMP_MINFILTER      = 6,
    D3DSAMP_MIPFILTER      = 7,
    D3DSAMP_MIPMAPLODBIAS  = 8,
    D3DSAMP_MAXMIPLEVEL    = 9,
    D3DSAMP_MAXANISOTROPY  = 10,
    D3DSAMP_SRGBTEXTURE    = 11,
    D3DSAMP_ELEMENTINDEX   = 12,
    D3DSAMP_DMAPOFFSET     = 13,
		D3DDMAPSAMPLER = 256,
		D3DVERTEXTEXTURESAMPLER0 = 257,
		D3DVERTEXTEXTURESAMPLER1 = 258,
		D3DVERTEXTEXTURESAMPLER2 = 259,
		D3DVERTEXTEXTURESAMPLER3 = 260,
    D3DDECLUSAGE_POSITION = 0,
    D3DDECLUSAGE_BLENDWEIGHT = 1,
    D3DDECLUSAGE_BLENDINDICES = 2,
    D3DDECLUSAGE_NORMAL = 3,
    D3DDECLUSAGE_PSIZE = 4,
    D3DDECLUSAGE_TEXCOORD = 5,
    D3DDECLUSAGE_TANGENT = 6,
    D3DDECLUSAGE_BINORMAL = 7,
    D3DDECLUSAGE_TESSFACTOR = 8,
    D3DDECLUSAGE_POSITIONT = 9,
    D3DDECLUSAGE_COLOR = 10,
    D3DDECLUSAGE_FOG = 11,
    D3DDECLUSAGE_DEPTH = 12,
    D3DDECLUSAGE_SAMPLE = 13,
		MAXD3DDECLUSAGE = D3DDECLUSAGE_SAMPLE,
		MAXD3DDECLUSAGEINDEX = 15,
		MAXD3DDECLLENGTH = 64,
    D3DDECLMETHOD_DEFAULT = 0,
    D3DDECLMETHOD_PARTIALU = 1,
    D3DDECLMETHOD_PARTIALV = 2,
    D3DDECLMETHOD_CROSSUV = 3,
    D3DDECLMETHOD_UV = 4,
    D3DDECLMETHOD_LOOKUP = 5,
    D3DDECLMETHOD_LOOKUPPRESAMPLED = 6,
		MAXD3DDECLMETHOD = D3DDECLMETHOD_LOOKUPPRESAMPLED,
    D3DDECLTYPE_FLOAT1    =  0,
    D3DDECLTYPE_FLOAT2    =  1,
    D3DDECLTYPE_FLOAT3    =  2,
    D3DDECLTYPE_FLOAT4    =  3,
    D3DDECLTYPE_D3DCOLOR  =  4,
    D3DDECLTYPE_UBYTE4    =  5,
    D3DDECLTYPE_SHORT2    =  6,
    D3DDECLTYPE_SHORT4    =  7,
    D3DDECLTYPE_UBYTE4N   =  8,
    D3DDECLTYPE_SHORT2N   =  9,
    D3DDECLTYPE_SHORT4N   = 10,
    D3DDECLTYPE_USHORT2N  = 11,
    D3DDECLTYPE_USHORT4N  = 12,
    D3DDECLTYPE_UDEC3     = 13,
    D3DDECLTYPE_DEC3N     = 14,
    D3DDECLTYPE_FLOAT16_2 = 15,
    D3DDECLTYPE_FLOAT16_4 = 16,
    D3DDECLTYPE_UNUSED    = 17,
		MAXD3DDECLTYPE = D3DDECLTYPE_UNUSED,
		D3DSTREAMSOURCE_INDEXEDDATA = 0x40000000,
		D3DSTREAMSOURCE_INSTANCEDATA = 0x80000000,
		D3DSI_INSTLENGTH_MASK   = 0x0F000000,
		D3DSI_INSTLENGTH_SHIFT  = 24,
		D3DSP_OPCODESPECIFICCONTROL_MASK = 0x00ff0000,
		D3DSP_OPCODESPECIFICCONTROL_SHIFT = 16,
		D3DSI_TEXLD_PROJECT = 0x10000,
		D3DSI_TEXLD_BIAS = 0x20000,
    D3DSPC_RESERVED0= 0,
    D3DSPC_GT       = 1,
    D3DSPC_EQ       = 2,
    D3DSPC_GE       = 3,
    D3DSPC_LT       = 4,
    D3DSPC_NE       = 5,
    D3DSPC_LE       = 6,
    D3DSPC_RESERVED1 = 7,
		D3DSHADER_COMPARISON_SHIFT = 16,
		D3DSHADER_COMPARISON_MASK = 0x70000,
		D3DSHADER_INSTRUCTION_PREDICATED = 0x10000000,
		D3DSP_DCL_USAGE_SHIFT = 0,
		D3DSP_DCL_USAGE_MASK = 0x0000000f,
		D3DSP_DCL_USAGEINDEX_SHIFT = 16,
		D3DSP_DCL_USAGEINDEX_MASK = 0x000f0000,
		D3DSP_TEXTURETYPE_SHIFT = 27,
		D3DSP_TEXTURETYPE_MASK = 0x78000000,
    D3DSTT_UNKNOWN = 0,
    D3DSTT_2D      = 0x10000000,
    D3DSTT_CUBE    = 0x18000000,
    D3DSTT_VOLUME  = 0x20000000,
    D3DSMO_POSITION  = 0,
    D3DSMO_FACE = 1,
		D3DSHADER_ADDRESSMODE_SHIFT = 13,
		D3DSHADER_ADDRESSMODE_MASK = 0x2000,
    D3DSHADER_ADDRMODE_ABSOLUTE  = 0,
    D3DSHADER_ADDRMODE_RELATIVE  = 0x2000,
		D3DSP_REPLICATERED = 0,
		D3DSP_REPLICATEGREEN = 0x550000,
		D3DSP_REPLICATEBLUE = 0xAA0000,
		D3DDEGREE_LINEAR      = 1,
		D3DDEGREE_QUADRATIC   = 2,
		D3DDEGREE_CUBIC       = 3,
		D3DDEGREE_QUINTIC     = 5,
    D3DQUERYTYPE_VCACHE                 = 4,
    D3DQUERYTYPE_RESOURCEMANAGER        = 5,
    D3DQUERYTYPE_VERTEXSTATS            = 6,
    D3DQUERYTYPE_EVENT                  = 8,
    D3DQUERYTYPE_OCCLUSION              = 9,
    D3DQUERYTYPE_TIMESTAMP              = 10,
    D3DQUERYTYPE_TIMESTAMPDISJOINT      = 11,
    D3DQUERYTYPE_TIMESTAMPFREQ          = 12,
    D3DQUERYTYPE_PIPELINETIMINGS        = 13,
    D3DQUERYTYPE_INTERFACETIMINGS       = 14,
    D3DQUERYTYPE_VERTEXTIMINGS          = 15,
    D3DQUERYTYPE_PIXELTIMINGS           = 16,
    D3DQUERYTYPE_BANDWIDTHTIMINGS       = 17,
    D3DQUERYTYPE_CACHEUTILIZATION       = 18,
		D3DISSUE_END = 1,
		D3DISSUE_BEGIN = 2,
		D3DGETDATA_FLUSH = 1,
		D3DVS20CAPS_PREDICATION = 1,
		D3DVS20_MAX_DYNAMICFLOWCONTROLDEPTH  = 24,
		D3DVS20_MIN_DYNAMICFLOWCONTROLDEPTH  = 0,
		D3DVS20_MAX_NUMTEMPS    = 32,
		D3DVS20_MIN_NUMTEMPS    = 12,
		D3DVS20_MAX_STATICFLOWCONTROLDEPTH    = 4,
		D3DVS20_MIN_STATICFLOWCONTROLDEPTH    = 1,
		D3DPS20CAPS_ARBITRARYSWIZZLE = 1,
		D3DPS20CAPS_GRADIENTINSTRUCTIONS = 2,
		D3DPS20CAPS_PREDICATION = 4,
		D3DPS20CAPS_NODEPENDENTREADLIMIT = 8,
		D3DPS20CAPS_NOTEXINSTRUCTIONLIMIT = 16,
		D3DPS20_MAX_DYNAMICFLOWCONTROLDEPTH    = 24,
		D3DPS20_MIN_DYNAMICFLOWCONTROLDEPTH    = 0,
		D3DPS20_MAX_NUMTEMPS    = 32,
		D3DPS20_MIN_NUMTEMPS    = 12,
		D3DPS20_MAX_STATICFLOWCONTROLDEPTH    = 4,
		D3DPS20_MIN_STATICFLOWCONTROLDEPTH    = 0,
		D3DPS20_MAX_NUMINSTRUCTIONSLOTS    = 512,
		D3DPS20_MIN_NUMINSTRUCTIONSLOTS    = 96,
		D3DMIN30SHADERINSTRUCTIONS = 512,
		D3DMAX30SHADERINSTRUCTIONS = 32768,
		D3DRTYPECOUNT = 8
	};

	typedef struct D3DVIEWPORT9 {
		uint32_t X, Y, Width, Height;
		float MinZ, MaxZ;
	} D3DVIEWPORT9;

	typedef struct D3DCLIPSTATUS9 {
		uint32_t ClipUnion;
		uint32_t ClipIntersection;
	} D3DCLIPSTATUS9;

	typedef struct D3DMATERIAL9 {
    D3DCOLORVALUE Diffuse, Ambient, Specular, Emissive;
    float Power;
	} D3DMATERIAL9;

	typedef struct D3DLIGHT9 {
    D3Denum Type;
    D3DCOLORVALUE Diffuse, Specular, Ambient;
    D3DVECTOR Position, Direction;
    float Range, Falloff, Attenuation0, Attenuation1, Attenuation2, Theta, Phi;
	} D3DLIGHT9;

	typedef struct D3DVERTEXELEMENT9 {
    uint16_t Stream, Offset;
		uint8_t Type, Method, Usage, UsageIndex;
	} D3DVERTEXELEMENT9;

	typedef struct D3DDEVICE_CREATION_PARAMETERS {
    uint32_t AdapterOrdinal;
    D3Denum DeviceType;
    HWND hFocusWindow;
    uint32_t BehaviorFlags;
	} D3DDEVICE_CREATION_PARAMETERS;

	// NOTE: renamed to avoid conflict with D3D8's
	typedef struct D3D9PRESENT_PARAMETERS {
    uint32_t BackBufferWidth, BackBufferHeight;
    D3Denum BackBufferFormat;
    uint32_t BackBufferCount;
    D3Denum MultiSampleType;
    uint32_t MultiSampleQuality;
    D3Denum SwapEffect;
    HWND hDeviceWindow;
    bool32 Windowed;
    bool32 EnableAutoDepthStencil;
    D3Denum AutoDepthStencilFormat;
    uint32_t Flags;
    uint32_t FullScreen_RefreshRateInHz;
    uint32_t PresentationInterval;
	} D3D9PRESENT_PARAMETERS;

	typedef struct D3DVERTEXBUFFER_DESC {
    D3Denum Format;
    D3Denum Type;
    uint32_t Usage;
    D3Denum Pool;
    uint32_t Size, FVF;
	} D3DVERTEXBUFFER_DESC;

	typedef struct D3DINDEXBUFFER_DESC {
    D3Denum Format;
    D3Denum Type;
    uint32_t Usage;
    D3Denum Pool;
    uint32_t Size;
	} D3DINDEXBUFFER_DESC;

	typedef struct D3DSURFACE_DESC {
    D3Denum Format;
    D3Denum Type;
    uint32_t Usage;
    D3Denum Pool;
    D3Denum MultiSampleType;
    uint32_t MultiSampleQuality;
    uint32_t Width, Height;
	} D3DSURFACE_DESC;

	typedef struct D3DVOLUME_DESC {
    D3Denum Format;
    D3Denum Type;
    uint32_t Usage;
    D3Denum Pool;
    uint32_t Width, Height, Depth;
	} D3DVOLUME_DESC;

	typedef struct D3DRECTPATCH_INFO {
    uint32_t StartVertexOffsetWidth, StartVertexOffsetHeight;
    uint32_t Width, Height, Stride;
    D3Denum Basis;
    D3Denum Degree;
	} D3DRECTPATCH_INFO;

	typedef struct D3DTRIPATCH_INFO {
    uint32_t StartVertexOffset;
    uint32_t NumVertices;
    D3Denum Basis;
    D3Denum Degree;
	} D3DTRIPATCH_INFO;

	typedef struct D3DADAPTER_IDENTIFIER9 {
    char Driver[MAX_DEVICE_IDENTIFIER_STRING];
    char Description[MAX_DEVICE_IDENTIFIER_STRING];
    char DeviceName[32];
		union {
			int64_t DriverVersion;
			struct {
				uint32_t DriverVersionLowPart;
				uint32_t DriverVersionHighPart;
			};
		};
    uint32_t VendorId, DeviceId, SubSysId, Revision;
    GUID DeviceIdentifier;
    uint32_t WHQLLevel;
	} D3DADAPTER_IDENTIFIER9;

	typedef struct D3DRESOURCESTATS	{
    bool32 bThrashing;
    uint32_t ApproxBytesDownloaded, NumEvicts, NumVidCreates, LastPri, NumUsed, NumUsedInVidMem;
    uint32_t WorkingSet, WorkingSetBytes, TotalManaged, TotalBytes;
	} D3DRESOURCESTATS;

	typedef struct D3DDEVINFO_RESOURCEMANAGER {
    D3DRESOURCESTATS stats[D3DRTYPECOUNT];
	} D3DDEVINFO_RESOURCEMANAGER;

	typedef struct D3DDEVINFO_D3DVERTEXSTATS {
    uint32_t NumRenderedTriangles, NumExtraClippingTriangles;
	} D3DDEVINFO_D3DVERTEXSTATS;

	typedef struct D3DDEVINFO_VCACHE { uint32_t Pattern, OptMethod, CacheSize, MagicNumber; } D3DDEVINFO_VCACHE;

	typedef struct D3DDEVINFO_D3D9PIPELINETIMINGS {
    float VertexProcessingTimePercent, PixelProcessingTimePercent, OtherGPUProcessingTimePercent, GPUIdleTimePercent;
	} D3DDEVINFO_D3D9PIPELINETIMINGS;

	typedef struct D3DDEVINFO_D3D9INTERFACETIMINGS {
    float WaitingForGPUToUseApplicationResourceTimePercent;
    float WaitingForGPUToAcceptMoreCommandsTimePercent;
    float WaitingForGPUToStayWithinLatencyTimePercent;
    float WaitingForGPUExclusiveResourceTimePercent;
    float WaitingForGPUOtherTimePercent;
	} D3DDEVINFO_D3D9INTERFACETIMINGS;

	typedef struct D3DDEVINFO_D3D9STAGETIMINGS {
    float MemoryProcessingPercent, ComputationProcessingPercent;
	} D3DDEVINFO_D3D9STAGETIMINGS;

	typedef struct D3DDEVINFO_D3D9BANDWIDTHTIMINGS {
		float MaxBandwidthUtilized, FrontEndUploadMemoryUtilizedPercent, VertexRateUtilizedPercent;
		float TriangleSetupRateUtilizedPercent, FillRateUtilizedPercent;
	} D3DDEVINFO_D3D9BANDWIDTHTIMINGS;

	typedef struct D3DDEVINFO_D3D9CACHEUTILIZATION {
		float TextureCacheHitRate, PostTransformVertexCacheHitRate;
	} D3DDEVINFO_D3D9CACHEUTILIZATION;

#pragma pack(4)

	typedef struct D3DVSHADERCAPS2_0 {
		uint32_t Caps;
		int32_t DynamicFlowControlDepth;
		int32_t NumTemps;
		int32_t StaticFlowControlDepth;
	} D3DVSHADERCAPS2_0;

	typedef struct D3DPSHADERCAPS2_0 {
    uint32_t Caps;
    int32_t DynamicFlowControlDepth;
    int32_t NumTemps;
    int32_t StaticFlowControlDepth;
    int32_t NumInstructionSlots;
	} D3DPSHADERCAPS2_0;

	typedef struct D3DCAPS9 {
    D3Denum  DeviceType;
    uint32_t AdapterOrdinal, Caps, Caps2, Caps3, PresentationIntervals, CursorCaps, DevCaps;
    uint32_t PrimitiveMiscCaps, RasterCaps, ZCmpCaps, SrcBlendCaps, DestBlendCaps, AlphaCmpCaps;
    uint32_t ShadeCaps, TextureCaps, TextureFilterCaps, CubeTextureFilterCaps, VolumeTextureFilterCaps;
    uint32_t TextureAddressCaps, VolumeTextureAddressCaps, LineCaps;
    uint32_t MaxTextureWidth, MaxTextureHeight, MaxVolumeExtent, MaxTextureRepeat;
    uint32_t MaxTextureAspectRatio, MaxAnisotropy;
    float MaxVertexW;
    float GuardBandLeft, GuardBandTop, GuardBandRight, GuardBandBottom;
    float   ExtentsAdjust;
    uint32_t   StencilCaps;
    uint32_t   FVFCaps;
    uint32_t   TextureOpCaps;
    uint32_t   MaxTextureBlendStages;
    uint32_t   MaxSimultaneousTextures;
    uint32_t   VertexProcessingCaps;
    uint32_t   MaxActiveLights;
    uint32_t   MaxUserClipPlanes;
    uint32_t   MaxVertexBlendMatrices;
    uint32_t   MaxVertexBlendMatrixIndex;
    float   MaxPointSize;
    uint32_t   MaxPrimitiveCount;          // max number of primitives per DrawPrimitive call
    uint32_t   MaxVertexIndex;
    uint32_t   MaxStreams;
    uint32_t   MaxStreamStride;            // max stride for SetStreamSource
    uint32_t   VertexShaderVersion;
    uint32_t   MaxVertexShaderConst;       // number of vertex shader constant registers

    uint32_t   PixelShaderVersion;
    float   PixelShader1xMaxValue;      // max value storable in registers of ps.1.x shaders
    uint32_t   DevCaps2;
    float   MaxNpatchTessellationLevel;
    uint32_t   Reserved5;
    uint32_t    MasterAdapterOrdinal;       // ordinal of master adaptor for adapter group
    uint32_t    AdapterOrdinalInGroup;      // ordinal inside the adapter group
    uint32_t    NumberOfAdaptersInGroup;    // number of adapters in this adapter group (only if master)
    uint32_t   DeclTypes;                  // Data types, supported in vertex declarations
    uint32_t   NumSimultaneousRTs;         // Will be at least 1
    uint32_t   StretchRectFilterCaps;      // Filter caps supported by StretchRect
    D3DVSHADERCAPS2_0 VS20Caps;
		D3DPSHADERCAPS2_0 PS20Caps;
    uint32_t VertexTextureFilterCaps, MaxVShaderInstructionsExecuted, MaxPShaderInstructionsExecuted;
    uint32_t MaxVertexShader30InstructionSlots, MaxPixelShader30InstructionSlots;
	} D3DCAPS9;

    typedef enum _D3DXPARAMETER_CLASS
    {
        D3DXPC_SCALAR,
        D3DXPC_VECTOR,
        D3DXPC_MATRIX_ROWS,
        D3DXPC_MATRIX_COLUMNS,
        D3DXPC_OBJECT,
        D3DXPC_STRUCT,

        // force 32-bit size enum
        D3DXPC_FORCE_DWORD = 0x7fffffff

    } D3DXPARAMETER_CLASS, *LPD3DXPARAMETER_CLASS;

    typedef enum _D3DXPARAMETER_TYPE
    {
        D3DXPT_VOID,
        D3DXPT_BOOL,
        D3DXPT_INT,
        D3DXPT_FLOAT,
        D3DXPT_STRING,
        D3DXPT_TEXTURE,
        D3DXPT_TEXTURE1D,
        D3DXPT_TEXTURE2D,
        D3DXPT_TEXTURE3D,
        D3DXPT_TEXTURECUBE,
        D3DXPT_SAMPLER,
        D3DXPT_SAMPLER1D,
        D3DXPT_SAMPLER2D,
        D3DXPT_SAMPLER3D,
        D3DXPT_SAMPLERCUBE,
        D3DXPT_PIXELSHADER,
        D3DXPT_VERTEXSHADER,
        D3DXPT_PIXELFRAGMENT,
        D3DXPT_VERTEXFRAGMENT,
        D3DXPT_UNSUPPORTED,

        // force 32-bit size enum
        D3DXPT_FORCE_DWORD = 0x7fffffff

    } D3DXPARAMETER_TYPE, *LPD3DXPARAMETER_TYPE;

	typedef struct _D3DXEFFECT_DESC
    {
        LPCSTR Creator;                     // Creator string
        UINT Parameters;                    // Number of parameters
        UINT Techniques;                    // Number of techniques
        UINT Functions;                     // Number of function entrypoints

    } D3DXEFFECT_DESC;

    typedef struct _D3DXPARAMETER_DESC
    {
        LPCSTR Name;                        // Parameter name
        LPCSTR Semantic;                    // Parameter semantic
        D3DXPARAMETER_CLASS Class;          // Class
        D3DXPARAMETER_TYPE Type;            // Component type
        UINT Rows;                          // Number of rows
        UINT Columns;                       // Number of columns
        UINT Elements;                      // Number of array elements
        UINT Annotations;                   // Number of annotations
        UINT StructMembers;                 // Number of structure member sub-parameters
        DWORD Flags;                        // D3DX_PARAMETER_* flags
        UINT Bytes;                         // Parameter size, in bytes

    } D3DXPARAMETER_DESC;


    typedef struct _D3DXTECHNIQUE_DESC
    {
        LPCSTR Name;                        // Technique name
        UINT Passes;                        // Number of passes
        UINT Annotations;                   // Number of annotations

    } D3DXTECHNIQUE_DESC;

    typedef struct _D3DXPASS_DESC
    {
        LPCSTR Name;                        // Pass name
        UINT Annotations;                   // Number of annotations

        const DWORD *pVertexShaderFunction; // Vertex shader function
        const DWORD *pPixelShaderFunction;  // Pixel shader function

    } D3DXPASS_DESC;

    typedef struct _D3DXFUNCTION_DESC
    {
        LPCSTR Name;                        // Function name
        UINT Annotations;                   // Number of annotations

    } D3DXFUNCTION_DESC;

#pragma pack()

]]

com.def {
    { 'IDirect3D9',
        methods = {
            { 'RegisterSoftwareDevice', 'void* initfunc' },
            { 'GetAdapterCount',        ret = 'uint32_t' },
            { 'GetAdapterIdentifier',   'uint32_t adapter, uint32_t flags, D3DADAPTER_IDENTIFIER9* out_identifier' },
            { 'GetAdapterModeCount',    'uint32_t adapter, D3Denum format',                                                                           ret = 'uint32_t' },
            { 'EnumAdapterModes',       'uint32_t adapter, D3Denum format, uint32_t mode, D3DDISPLAYMODE* out_mode' },
            { 'GetAdapterDisplayMode',  'uint32_t adapter, D3DDISPLAYMODE* out_mode' },
            { 'CheckDeviceType',        'uint32_t adapter, D3Denum devicetype, D3Denum adapterfmt, D3Denum backbufferfmt, bool32 windowed' },
            { 'CheckDeviceFormat',      'uint32_t adapter, D3Denum devicetype,D3Denum AdapterFormat,uint32_t Usage,D3Denum RType,D3Denum CheckFormat' },
            { 'CheckDeviceMultiSampleType', [[
				uint32_t adapter, D3Denum devicetype, D3Denum surfacefmt, bool32 windowed, D3Denum multisampletype, uint32_t* qualitylevels]] },
            { 'CheckDepthStencilMatch',      'uint32_t Adapter,D3Denum DeviceType,D3Denum AdapterFormat,D3Denum RenderTargetFormat,D3Denum DepthStencilFormat' },
            { 'CheckDeviceFormatConversion', 'uint32_t Adapter,D3Denum DeviceType,D3Denum SourceFormat,D3Denum TargetFormat' },
            { 'GetDeviceCaps',               'uint32_t Adapter,D3Denum DeviceType,D3DCAPS9* pCaps' },
            { 'GetAdapterMonitor',           'uint32_t Adapter',                                                                                                                 ret = 'HMONITOR' },
            { 'CreateDevice',                'uint32_t adapter, D3Denum devicetype, HWND window, uint32_t BehaviorFlags, D3D9PRESENT_PARAMETERS*, IDirect3DDevice9** out_device' },
        },
        fields = [[
			wchar_t* Version;
		]],
        iid = '81bdcbca-64d4-426d-ae8d-ad0147f4275c',
    },
    { 'IDirect3DDevice9',
        methods = {
            { 'TestCooperativeLevel' },
            { 'GetAvailableTextureMem',      ret = 'uint32_t' },
            { 'EvictManagedResources' },
            { 'GetDirect3D',                 'IDirect3D9** ppD3D9' },
            { 'GetDeviceCaps',               'D3DCAPS9* pCaps' },
            { 'GetDisplayMode',              'uint32_t iSwapChain,D3DDISPLAYMODE* pMode' },
            { 'GetCreationParameters',       'D3DDEVICE_CREATION_PARAMETERS *pParameters' },
            { 'SetCursorProperties',         'uint32_t XHotSpot,uint32_t YHotSpot,IDirect3DSurface9* pCursorBitmap' },
            { 'SetCursorPosition',           'int X,int Y,uint32_t Flags',                                                                                                                                                                                 ret = 'void' },
            { 'ShowCursor',                  'bool32 bShow',                                                                                                                                                                                               ret = 'bool32' },
            { 'CreateAdditionalSwapChain',   'D3D9PRESENT_PARAMETERS* pPresentationParameters,IDirect3DSwapChain9** pSwapChain' },
            { 'GetSwapChain',                'uint32_t iSwapChain, IDirect3DSwapChain9** pSwapChain' },
            { 'GetNumberOfSwapChains',       ret = 'uint32_t' },
            { 'Reset',                       'D3D9PRESENT_PARAMETERS* pPresentationParameters' },
            { 'Present',                     'const RECT* pSourceRect,const RECT* pDestRect,HWND hDestWindowOverride,const RGNDATA* pDirtyRegion' },
            { 'GetBackBuffer',               'uint32_t swapchain_idx, uint32_t backbuffer_idx, D3Denum backbuffer_type, IDirect3DSurface9** out_backbuffer' },
            { 'GetRasterStatus',             'uint32_t swapchain_idx, D3DRASTER_STATUS* out_status' },
            { 'SetDialogBoxMode',            'bool32 bEnableDialogs' },
            { 'SetGammaRamp',                'uint32_t iSwapChain,uint32_t Flags,const D3DGAMMARAMP* pRamp',                                                                                                                                               ret = 'void' },
            { 'GetGammaRamp',                'uint32_t iSwapChain,D3DGAMMARAMP* pRamp',                                                                                                                                                                    ret = 'void' },
            { 'CreateTexture',               'uint32_t Width,uint32_t Height,uint32_t Levels,uint32_t Usage,D3Denum Format,D3Denum Pool,IDirect3DTexture9** ppTexture,HANDLE* pSharedHandle' },
            { 'CreateVolumeTexture',         'uint32_t Width,uint32_t Height,uint32_t Depth,uint32_t Levels,uint32_t Usage,D3Denum Format,D3Denum Pool,IDirect3DVolumeTexture9** ppVolumeTexture,HANDLE* pSharedHandle' },
            { 'CreateCubeTexture',           'uint32_t EdgeLength,uint32_t Levels,uint32_t Usage,D3Denum Format,D3Denum Pool,IDirect3DCubeTexture9** ppCubeTexture,HANDLE* pSharedHandle' },
            { 'CreateVertexBuffer',          'uint32_t length, uint32_t usage, uint32_t fvf, D3Denum pool, IDirect3DVertexBuffer9** out_buffer, HANDLE* out_handle' },
            { 'CreateIndexBuffer',           'uint32_t Length,uint32_t Usage,D3Denum Format,D3Denum Pool,IDirect3DIndexBuffer9** ppIndexBuffer,HANDLE* pSharedHandle' },
            { 'CreateRenderTarget',          'uint32_t Width,uint32_t Height,D3Denum Format,D3Denum MultiSample,uint32_t MultisampleQuality,bool32 Lockable,IDirect3DSurface9** ppSurface,HANDLE* pSharedHandle' },
            { 'CreateDepthStencilSurface',   'uint32_t Width,uint32_t Height,D3Denum Format,D3Denum MultiSample,uint32_t MultisampleQuality,bool32 Discard,IDirect3DSurface9** ppSurface,HANDLE* pSharedHandle' },
            { 'UpdateSurface',               'IDirect3DSurface9* pSourceSurface,const RECT* pSourceRect,IDirect3DSurface9* pDestinationSurface,const POINT* pDestPoint' },
            { 'UpdateTexture',               'IDirect3DBaseTexture9* pSourceTexture,IDirect3DBaseTexture9* pDestinationTexture' },
            { 'GetRenderTargetData',         'IDirect3DSurface9* pRenderTarget,IDirect3DSurface9* pDestSurface' },
            { 'GetFrontBufferData',          'uint32_t iSwapChain,IDirect3DSurface9* pDestSurface' },
            { 'StretchRect',                 'IDirect3DSurface9* pSourceSurface,const RECT* pSourceRect,IDirect3DSurface9* pDestSurface,const RECT* pDestRect,D3Denum Filter' },
            { 'ColorFill',                   'IDirect3DSurface9* pSurface,const RECT* pRect,uint32_t color' },
            { 'CreateOffscreenPlainSurface', 'uint32_t Width,uint32_t Height,D3Denum Format,D3Denum Pool,IDirect3DSurface9** ppSurface,HANDLE* pSharedHandle' },
            { 'SetRenderTarget',             'uint32_t RenderTargetIndex,IDirect3DSurface9* pRenderTarget' },
            { 'GetRenderTarget',             'uint32_t RenderTargetIndex,IDirect3DSurface9** ppRenderTarget' },
            { 'SetDepthStencilSurface',      'IDirect3DSurface9* pNewZStencil' },
            { 'GetDepthStencilSurface',      'IDirect3DSurface9** ppZStencilSurface' },
            { 'BeginScene' },
            { 'EndScene' },
            { 'Clear',                       'uint32_t Count,const D3DRECT* pRects,uint32_t Flags,uint32_t Color,float Z,uint32_t Stencil' },
            { 'SetTransform',                'D3Denum State,const D3DMATRIX* pMatrix' },
            { 'GetTransform',                'D3Denum State,D3DMATRIX* pMatrix' },
            { 'MultiplyTransform',           'D3Denum,const D3DMATRIX*' },
            { 'SetViewport',                 'const D3DVIEWPORT9* pViewport' },
            { 'GetViewport',                 'D3DVIEWPORT9* pViewport' },
            { 'SetMaterial',                 'const D3DMATERIAL9* pMaterial' },
            { 'GetMaterial',                 'D3DMATERIAL9* pMaterial' },
            { 'SetLight',                    'uint32_t Index,const D3DLIGHT9*' },
            { 'GetLight',                    'uint32_t Index,D3DLIGHT9*' },
            { 'LightEnable',                 'uint32_t Index,bool32 Enable' },
            { 'GetLightEnable',              'uint32_t Index,bool32* pEnable' },
            { 'SetClipPlane',                'uint32_t Index,const float* pPlane' },
            { 'GetClipPlane',                'uint32_t Index,float* pPlane' },
            { 'SetRenderState',              'D3Denum State,uint32_t Value' },
            { 'GetRenderState',              'D3Denum State,uint32_t* pValue' },
            { 'CreateStateBlock',            'D3Denum Type,IDirect3DStateBlock9** ppSB' },
            { 'BeginStateBlock' },
            { 'EndStateBlock',               'IDirect3DStateBlock9** ppSB' },
            { 'SetClipStatus',               'const D3DCLIPSTATUS9* pClipStatus' },
            { 'GetClipStatus',               'D3DCLIPSTATUS9* pClipStatus' },
            { 'GetTexture',                  'uint32_t Stage,IDirect3DBaseTexture9** ppTexture' },
            { 'SetTexture',                  'uint32_t Stage,IDirect3DBaseTexture9* pTexture' },
            { 'GetTextureStageState',        'uint32_t Stage,D3Denum Type,uint32_t* pValue' },
            { 'SetTextureStageState',        'uint32_t Stage,D3Denum Type,uint32_t Value' },
            { 'GetSamplerState',             'uint32_t Sampler,D3Denum Type,uint32_t* pValue' },
            { 'SetSamplerState',             'uint32_t Sampler,D3Denum Type,uint32_t Value' },
            { 'ValidateDevice',              'uint32_t* pNumPasses' },
            { 'SetPaletteEntries',           'uint32_t PaletteNumber,const PALETTEENTRY* pEntries' },
            { 'GetPaletteEntries',           'uint32_t PaletteNumber,PALETTEENTRY* pEntries' },
            { 'SetCurrentTexturePalette',    'uint32_t PaletteNumber' },
            { 'GetCurrentTexturePalette',    'uint32_t *PaletteNumber' },
            { 'SetScissorRect',              'const RECT* pRect' },
            { 'GetScissorRect',              'RECT* pRect' },
            { 'SetSoftwareVertexProcessing', 'bool32 bSoftware' },
            { 'GetSoftwareVertexProcessing', ret = 'bool32' },
            { 'SetNPatchMode',               'float nSegments' },
            { 'GetNPatchMode',               ret = 'float' },
            { 'DrawPrimitive',               'D3Denum PrimitiveType,uint32_t StartVertex,uint32_t PrimitiveCount' },
            { 'DrawIndexedPrimitive',        'D3Denum,int32_t BaseVertexIndex,uint32_t MinVertexIndex,uint32_t NumVertices,uint32_t startIndex,uint32_t primCount' },
            { 'DrawPrimitiveUP',             'D3Denum PrimitiveType,uint32_t PrimitiveCount,const void* pVertexStreamZeroData,uint32_t VertexStreamZeroStride' },
            { 'DrawIndexedPrimitiveUP',      'D3Denum PrimitiveType,uint32_t MinVertexIndex,uint32_t NumVertices,uint32_t PrimitiveCount,const void* pIndexData,D3Denum IndexDataFormat,const void* pVertexStreamZeroData,uint32_t VertexStreamZeroStride' },
            { 'ProcessVertices',             'uint32_t SrcStartIndex,uint32_t DestIndex,uint32_t VertexCount,IDirect3DVertexBuffer9* pDestBuffer,IDirect3DVertexDeclaration9* pVertexDecl,uint32_t Flags' },
            { 'CreateVertexDeclaration',     'const D3DVERTEXELEMENT9* pVertexElements,IDirect3DVertexDeclaration9** ppDecl' },
            { 'SetVertexDeclaration',        'IDirect3DVertexDeclaration9* pDecl' },
            { 'GetVertexDeclaration',        'IDirect3DVertexDeclaration9** ppDecl' },
            { 'SetFVF',                      'uint32_t fvf' },
            { 'GetFVF',                      'uint32_t* out_fvf' },
            { 'CreateVertexShader',          'const uint32_t* pFunction,IDirect3DVertexShader9** ppShader' },
            { 'SetVertexShader',             'IDirect3DVertexShader9* pShader' },
            { 'GetVertexShader',             'IDirect3DVertexShader9** ppShader' },
            { 'SetVertexShaderConstantF',    'uint32_t StartRegister,const float* pConstantData,uint32_t Vector4fCount' },
            { 'GetVertexShaderConstantF',    'uint32_t StartRegister,float* pConstantData,uint32_t Vector4fCount' },
            { 'SetVertexShaderConstantI',    'uint32_t StartRegister,const int* pConstantData,uint32_t Vector4iCount' },
            { 'GetVertexShaderConstantI',    'uint32_t StartRegister,int* pConstantData,uint32_t Vector4iCount' },
            { 'SetVertexShaderConstantB',    'uint32_t StartRegister,const bool32* pConstantData,uint32_t  BoolCount' },
            { 'GetVertexShaderConstantB',    'uint32_t StartRegister,bool32* pConstantData,uint32_t BoolCount' },
            { 'SetStreamSource',             'uint32_t StreamNumber,IDirect3DVertexBuffer9* pStreamData,uint32_t OffsetInBytes,uint32_t Stride' },
            { 'GetStreamSource',             'uint32_t StreamNumber,IDirect3DVertexBuffer9** ppStreamData,uint32_t* pOffsetInBytes,uint32_t* pStride' },
            { 'SetStreamSourceFreq',         'uint32_t StreamNumber,uint32_t Setting' },
            { 'GetStreamSourceFreq',         'uint32_t StreamNumber,uint32_t* pSetting' },
            { 'SetIndices',                  'IDirect3DIndexBuffer9* pIndexData' },
            { 'GetIndices',                  'IDirect3DIndexBuffer9** ppIndexData' },
            { 'CreatePixelShader',           'const uint32_t* pFunction,IDirect3DPixelShader9** ppShader' },
            { 'SetPixelShader',              'IDirect3DPixelShader9* pShader' },
            { 'GetPixelShader',              'IDirect3DPixelShader9** ppShader' },
            { 'SetPixelShaderConstantF',     'uint32_t StartRegister, const float* constantdata, uint32_t count' },
            { 'GetPixelShaderConstantF',     'uint32_t StartRegister, float* constantdata, uint32_t count' },
            { 'SetPixelShaderConstantI',     'uint32_t StartRegister, const int* constantdata, uint32_t count' },
            { 'GetPixelShaderConstantI',     'uint32_t StartRegister, int* constantdata, uint32_t count' },
            { 'SetPixelShaderConstantB',     'uint32_t StartRegister, const bool32* constantdata, uint32_t count' },
            { 'GetPixelShaderConstantB',     'uint32_t StartRegister, bool32* constantdata, uint32_t count' },
            { 'DrawRectPatch',               'uint32_t Handle,const float* pNumSegs,const D3DRECTPATCH_INFO* pRectPatchInfo' },
            { 'DrawTriPatch',                'uint32_t Handle,const float* pNumSegs,const D3DTRIPATCH_INFO* pTriPatchInfo' },
            { 'DeletePatch',                 'uint32_t Handle' },
            { 'CreateQuery',                 'D3Denum Type,IDirect3DQuery9** ppQuery' },
        },
        fields = [[
			D3DDEVICE_CREATION_PARAMETERS CreationParameters;
			D3D9PRESENT_PARAMETERS PresentParameters;
			D3DDISPLAYMODE DisplayMode;
			D3DCAPS9 Caps;

			uint32_t AvailableTextureMem;
			uint32_t SwapChains;
			uint32_t Textures;
			uint32_t VertexBuffers;
			uint32_t IndexBuffers;
			uint32_t VertexShaders;
			uint32_t PixelShaders;

			D3DVIEWPORT9 Viewport;
			D3DMATRIX ProjectionMatrix;
			D3DMATRIX ViewMatrix;
			D3DMATRIX WorldMatrix;
			D3DMATRIX TextureMatrices[8];

			uint32_t FVF;
			uint32_t VertexSize;
			uint32_t VertexShaderVersion;
			uint32_t PixelShaderVersion;
			bool32 SoftwareVertexProcessing;

			D3DMATERIAL9 Material;
			D3DLIGHT9 Lights[16];
			bool32 LightsEnabled[16];

			D3DGAMMARAMP GammaRamp;
			RECT ScissorRect;
			bool32 DialogBoxMode;
    ]],
        iid = 'd0223b96-bf7a-43fd-92bd-a43b0d82b9eb',
    },
    { 'IDirect3DStateBlock9',
        methods = {
            { 'GetDevice', 'IDirect3DDevice9** ppDevice' },
            { 'Capture' },
            { 'Apply' },
        },
        fields = [[
			wchar_t* CreationCallStack;
    ]],
        iid = 'b07c4fe5-310d-4ba8-a23c-4f0f206f218b',
    },
    { 'IDirect3DSwapChain9',
        methods = {
            { 'Present',              'const RECT* src_rect, const RECT* dst_rect, HWND overridewindow, const RGNDATA* dirtyregion, uint32_t flags' },
            { 'GetFrontBufferData',   'IDirect3DSurface9* dest' },
            { 'GetBackBuffer',        'uint32_t i, D3Denum type, IDirect3DSurface9** out_backbuffer' },
            { 'GetRasterStatus',      'D3DRASTER_STATUS* out_status' },
            { 'GetDisplayMode',       'D3DDISPLAYMODE* out_mode' },
            { 'GetDevice',            'IDirect3DDevice9** out_device' },
            { 'GetPresentParameters', 'D3D9PRESENT_PARAMETERS* out_params' },
        },
        fields = [[
			D3D9PRESENT_PARAMETERS PresentParameters;
			D3DDISPLAYMODE DisplayMode;
			wchar_t* CreationCallStack;
    ]],
        iid = '794950f2-adfc-458a-905e-10a10b0b503b',
    },
    { 'IDirect3DResource9',
        methods = {
            { 'GetDevice',       'IDirect3DDevice9** out_device' },
            { 'SetPrivateData',  'GUID* refguid,const void* pData,uint32_t SizeOfData,uint32_t Flags' },
            { 'GetPrivateData',  'GUID* refguid,void* pData,uint32_t* pSizeOfData' },
            { 'FreePrivateData', 'GUID* refguid' },
            { 'SetPriority',     'uint32_t PriorityNew',                                              ret = 'uint32_t' },
            { 'GetPriority',     ret = 'uint32_t' },
            { 'PreLoad',         ret = 'void' },
            { 'GetType',         ret = 'D3Denum' },
        },
        iid = '05eec05d-8f7d-4362-b999-d1baf357c704',
    },
    { 'IDirect3DVertexDeclaration9',
        methods = {
            { 'GetDevice',      'IDirect3DDevice9** ppDevice' },
            { 'GetDeclaration', 'D3DVERTEXELEMENT9* pElement,uint32_t* pNumElements' },
        },
        fields = [[
			wchar_t* CreationCallStack;
		]],
        iid = 'dd13c59c-36fa-4098-a8fb-c7ed39dc8546',
    },
    { 'IDirect3DVertexShader9',
        methods = {
            { 'GetDevice',   'IDirect3DDevice9** ppDevice' },
            { 'GetFunction', 'void*,uint32_t* pSizeOfData' },
        },
        fields = [[
			uint32_t Version;
			wchar_t* CreationCallStack;
		]],
        iid = 'efc5557e-6265-4613-8a94-43857889eb36',
    },
    { 'IDirect3DPixelShader9',
        methods = {
            { 'GetDevice',   'IDirect3DDevice9** out_device' },
            { 'GetFunction', 'void*, uint32_t* pSizeOfData' },
        },
        fields = [[
			uint32_t Version;
			wchar_t* CreationCallStack;
    ]],
        iid = '6d3bdbdc-5b02-4415-b852-ce5e8bccb289',
    },
    { 'IDirect3DBaseTexture9', inherits = 'IDirect3DResource9',
        methods = {
            { 'SetLOD',               'uint32_t lod',      ret = 'uint32_t' },
            { 'GetLOD',               ret = 'uint32_t' },
            { 'GetLevelCount',        ret = 'uint32_t' },
            { 'SetAutoGenFilterType', 'D3Denum filtertype' },
            { 'GetAutoGenFilterType', ret = 'D3Denum' },
            { 'GenerateMipSubLevels', ret = 'void' },
        },
        iid = '580ca87e-1d3c-4d54-991d-b7d3e3c298ce',
    },
    { 'IDirect3DTexture9', inherits = 'IDirect3DBaseTexture9',
        methods = {
            { 'GetLevelDesc',    'uint32_t level,D3DSURFACE_DESC *pDesc' },
            { 'GetSurfaceLevel', 'uint32_t level,IDirect3DSurface9** ppSurfaceLevel' },
            { 'LockRect',        'uint32_t level,D3DLOCKED_RECT* pLockedRect,const RECT* pRect,uint32_t Flags' },
            { 'UnlockRect',      'uint32_t level' },
            { 'AddDirtyRect',    'const RECT* dirtyrect' },
        },
        fields = [[
			wchar_t* Name;
			uint32_t Width;
			uint32_t Height;
			uint32_t Levels;
			uint32_t Usage;
			D3Denum Format;
			D3Denum Pool;
			uint32_t Priority;
			uint32_t LOD;
			D3Denum FilterType;
			uint32_t LockCount;
			wchar_t* CreationCallStack;
    ]],
        iid = '85c31227-3de5-4f00-9b3a-f11ac38c18b5',
    },
    { 'IDirect3DVolumeTexture9', inherits = 'IDirect3DBaseTexture9',
        methods = {
            { 'GetLevelDesc',   'uint32_t Level,D3DVOLUME_DESC *pDesc' },
            { 'GetVolumeLevel', 'uint32_t Level,IDirect3DVolume9** ppVolumeLevel' },
            { 'LockBox',        'uint32_t Level,D3DLOCKED_BOX* pLockedVolume,const D3DBOX* pBox,uint32_t Flags' },
            { 'UnlockBox',      'uint32_t Level' },
            { 'AddDirtyBox',    'const D3DBOX* pDirtyBox' },
        },
        fields = [[
			wchar_t* Name;
			uint32_t Width;
			uint32_t Height;
			uint32_t Depth;
			uint32_t Levels;
			uint32_t Usage;
			D3Denum Format;
			D3Denum Pool;
			uint32_t Priority;
			uint32_t LOD;
			D3Denum FilterType;
			uint32_t LockCount;
			wchar_t* CreationCallStack;
		]],
        iid = '2518526c-e789-4111-a7b9-47ef328d13e6',
    },
    { 'IDirect3DCubeTexture9', inherits = 'IDirect3DBaseTexture9',
        methods = {
            { 'GetLevelDesc',      'uint32_t Level,D3DSURFACE_DESC *pDesc' },
            { 'GetCubeMapSurface', 'D3Denum FaceType,uint32_t Level,IDirect3DSurface9** ppCubeMapSurface' },
            { 'LockRect',          'D3Denum FaceType,uint32_t Level,D3DLOCKED_RECT* pLockedRect,const RECT* pRect,uint32_t Flags' },
            { 'UnlockRect',        'D3Denum FaceType,uint32_t Level' },
            { 'AddDirtyRect',      'D3Denum FaceType,const RECT* pDirtyRect' },
        },
        fields = [[
			wchar_t* Name;
			uint32_t Width;
			uint32_t Height;
			uint32_t Levels;
			uint32_t Usage;
			D3Denum Format;
			D3Denum Pool;
			uint32_t Priority;
			uint32_t LOD;
			D3Denum FilterType;
			uint32_t LockCount;
			wchar_t* CreationCallStack;
		]],
        iid = 'fff32f81-d953-473a-9223-93d652aba93f',
    },
    { 'IDirect3DVertexBuffer9', inherits = 'IDirect3DResource9',
        methods = {
            { 'Lock',    'uint32_t OffsetToLock, uint32_t SizeToLock, void** ppbData, uint32_t Flags' },
            { 'Unlock' },
            { 'GetDesc', 'D3DVERTEXBUFFER_DESC *pDesc' },
        },
        fields = [[
			wchar_t* Name;
			uint32_t Length;
			uint32_t Usage;
			uint32_t FVF;
			D3Denum Pool;
			uint32_t Priority;
			uint32_t LockCount;
			wchar_t* CreationCallStack;
		]],
        iid = 'b64bb1b5-fd70-4df6-bf91-19d0a12455e3'
    },
    { 'IDirect3DIndexBuffer9', inherits = 'IDirect3DResource9',
        methods = {
            { 'Lock',    'uint32_t OffsetToLock,uint32_t SizeToLock,void** ppbData,uint32_t Flags' },
            { 'Unlock' },
            { 'GetDesc', 'D3DINDEXBUFFER_DESC *pDesc' },
        },
        fields = [[
			wchar_t* Name;
			uint32_t Length;
			uint32_t Usage;
			D3Denum Format;
			D3Denum Pool;
			uint32_t Priority;
			uint32_t LockCount;
			wchar_t* CreationCallStack;
    ]],
        iid = '7c9dd65e-d3f7-4529-acee-785830acde35',
    },
    { 'IDirect3DSurface9', inherits = 'IDirect3DResource9',
        methods = {
            { 'GetContainer', 'GUID* iid, void** out_container' },
            { 'GetDesc',      'D3DSURFACE_DESC*' },
            { 'LockRect',     'D3DLOCKED_RECT* out_locked, const RECT*, uint32_t flags' },
            { 'UnlockRect' },
            { 'GetDC',        'HDC *phdc' },
            { 'ReleaseDC',    'HDC hdc' },
        },
        fields = [[
			wchar_t* Name;
			uint32_t Width;
			uint32_t Height;
			uint32_t Usage;
			D3Denum Format;
			D3Denum Pool;
			D3Denum MultiSampleType;
			uint32_t MultiSampleQuality;
			uint32_t Priority;
			uint32_t LockCount;
			uint32_t DCCount;
			wchar_t* CreationCallStack;
		]],
        iid = '0cfbaf3a-9ff6-429a-99b3-a2796af8b89b',
    },
    { 'IDirect3DVolume9',
        methods = {
            { 'GetDevice',       'IDirect3DDevice9** ppDevice' },
            { 'SetPrivateData',  'GUID* refguid,const void* pData,uint32_t SizeOfData,uint32_t Flags' },
            { 'GetPrivateData',  'GUID* refguid,void* pData,uint32_t* pSizeOfData' },
            { 'FreePrivateData', 'GUID* refguid' },
            { 'GetContainer',    'GUID* riid,void** ppContainer' },
            { 'GetDesc',         'D3DVOLUME_DESC *pDesc' },
            { 'LockBox',         'D3DLOCKED_BOX * pLockedVolume,const D3DBOX* pBox,uint32_t Flags' },
            { 'UnlockBox' },
        },
        fields = [[
			wchar_t* Name;
			uint32_t Width;
			uint32_t Height;
			uint32_t Depth;
			uint32_t Usage;
			D3Denum Format;
			D3Denum Pool;
			uint32_t LockCount;
			wchar_t* CreationCallStack;
    ]],
        iid = '24f416e6-1f67-4aa7-b88e-d33f6f3128a1',
    },
    { 'IDirect3DQuery9',
        methods = {
            { 'GetDevice',   'IDirect3DDevice9** ppDevice' },
            { 'GetType',     ret = 'D3Denum' },
            { 'GetDataSize', ret = 'uint32_t' },
            { 'Issue',       'uint32_t dwIssueFlags' },
            { 'GetData',     'void* pData,uint32_t dwSize,uint32_t dwGetDataFlags' },
        },
        fields = [[
			D3Denum Type;
			uint32_t DataSize;
			wchar_t* CreationCallStack;
		]],
        iid = 'd9771460-a695-4f26-bbd3-27b840b541cc',
    },
    { 'ID3DXBuffer',
        methods = {
            { 'GetBufferPointer', ret = 'void*' },
            { 'GetBufferSize',    ret = 'uint32_t' },
        },
        iid = '8ba5fb08-5195-40e2-ac58-0d989c3a0102',
    },
    {
        'ID3DXConstantTable',
        methods = {
            { 'GetBufferPointer',               ret = 'void*' },
            { 'GetBufferSize',                  ret = 'uint32_t' },
            { 'GetDesc',                        'void *pDesc' },
            { 'GetConstantDesc',                'void* hConstant, void *pConstantDesc, uint32_t *pCount' },
            { 'GetSamplerIndex',                'void* hConstant',                                                                        ret = 'uint32_t' },
            { 'GetConstant',                    'void* hConstant, uint32_t Index',                                                        ret = 'void*' },
            { 'GetConstantByName',              'void* hConstant, const char* pName',                                                     ret = 'void*' },
            { 'GetConstantElement',             'void* hConstant, uint32_t Index',                                                        ret = 'void*' },
            { 'SetDefaults',                    'IDirect3DDevice9* pDevice' },
            { 'SetValue',                       'IDirect3DDevice9* pDevice, const void* hConstant, const void* pData, uint32_t Bytes' },
            { 'SetBool',                        'IDirect3DDevice9* pDevice, const void* hConstant, bool b' },
            { 'SetBoolArray',                   'IDirect3DDevice9* pDevice, const void* hConstant, const bool* pb, uint32_t Count' },
            { 'SetInt',                         'IDirect3DDevice9* pDevice, const void* hConstant, int32_t n' },
            { 'SetIntArray',                    'IDirect3DDevice9* pDevice, const void* hConstant, const int32_t* pn, uint32_t Count' },
            { 'SetFloat',                       'IDirect3DDevice9* pDevice, const void* hConstant, float f' },
            { 'SetFloatArray',                  'IDirect3DDevice9* pDevice, const void* hConstant, const float* pf, uint32_t Count' },
            { 'SetVector',                      'IDirect3DDevice9* pDevice, const void* hConstant, const D3DXVECTOR4* pVector' },
            { 'SetVectorArray',                 'IDirect3DDevice9* pDevice, const void* hConstant, const D3DXVECTOR4* pVector, uint32_t Count' },
            { 'SetMatrix',                      'IDirect3DDevice9* pDevice, const void* hConstant, const D3DXMATRIX* pMatrix' },
            { 'SetMatrixArray',                 'IDirect3DDevice9* pDevice, const void* hConstant, const D3DXMATRIX* pMatrix, uint32_t Count' },
            { 'SetMatrixPointerArray',          'IDirect3DDevice9* pDevice, const void* hConstant, const D3DXMATRIX** ppMatrix, uint32_t Count' },
            { 'SetMatrixTranspose',             'IDirect3DDevice9* pDevice, const void* hConstant, const D3DXMATRIX* pMatrix' },
            { 'SetMatrixTransposeArray',        'IDirect3DDevice9* pDevice, const void* hConstant, const D3DXMATRIX* pMatrix, uint32_t Count' },
            { 'SetMatrixTransposePointerArray', 'IDirect3DDevice9* pDevice, const void* hConstant, const D3DXMATRIX** ppMatrix, uint32_t Count' }
        },
        iid = 'ab3c758f-093e-4356-b762-4db18f1b3a01'
    },
    { 'ID3DXEffectPool', inherits = 'IUnknown',
        methods = {
        },
        iid = '9537ab04-3250-412e-8213-fcd2f8677933'
    },
    { 'ID3DXBaseEffect', inherits = 'IUnknown',
        methods = {
            { 'GetDesc',                        'D3DXEFFECT_DESC* pDesc' },
            { 'GetParameterDesc',               'D3DXHANDLE hParameter, D3DXPARAMETER_DESC* pDesc' },
            { 'GetTechniqueDesc',               'D3DXHANDLE hTechnique, D3DXTECHNIQUE_DESC* pDesc' },
            { 'GetPassDesc',                    'D3DXHANDLE hPass, D3DXPASS_DESC* pDesc' },
            { 'GetFunctionDesc',                'D3DXHANDLE hShader, D3DXFUNCTION_DESC* pDesc' },
            { 'GetParameter',                   'D3DXHANDLE hParameter, UINT Index',                             ret = 'D3DXHANDLE' },
            { 'GetParameterByName',             'D3DXHANDLE hParameter, LPCSTR pName',                           ret = 'D3DXHANDLE' },
            { 'GetParameterBySemantic',         'D3DXHANDLE hParameter, LPCSTR pSemantic',                       ret = 'D3DXHANDLE' },
            { 'GetParameterElement',            'D3DXHANDLE hParameter, UINT Index',                             ret = 'D3DXHANDLE' },
            { 'GetTechnique',                   'UINT Index',                                                    ret = 'D3DXHANDLE' },
            { 'GetTechniqueByName',             'LPCSTR pName',                                                  ret = 'D3DXHANDLE' },
            { 'GetPass',                        'D3DXHANDLE hTechnique, UINT Index',                             ret = 'D3DXHANDLE' },
            { 'GetPassByName',                  'D3DXHANDLE hTechnique, LPCSTR pName',                           ret = 'D3DXHANDLE' },
            { 'GetFunction',                    'UINT Index',                                                    ret = 'D3DXHANDLE' },
            { 'GetFunctionByName',              'LPCSTR pName',                                                  ret = 'D3DXHANDLE' },
            { 'GetAnnotation',                  'D3DXHANDLE hObject, UINT Index',                                ret = 'D3DXHANDLE' },
            { 'GetAnnotationByName',            'D3DXHANDLE hObject, LPCSTR pName',                              ret = 'D3DXHANDLE' },
            { 'SetValue',                       'D3DXHANDLE hParameter, LPCVOID pData, UINT Bytes' },
            { 'GetValue',                       'D3DXHANDLE hParameter, LPVOID pData, UINT Bytes' },
            { 'SetBool',                        'D3DXHANDLE hParameter, BOOL b' },
            { 'GetBool',                        'D3DXHANDLE hParameter, BOOL* pb' },
            { 'SetBoolArray',                   'D3DXHANDLE hParameter, const BOOL* pb, UINT Count' },
            { 'GetBoolArray',                   'D3DXHANDLE hParameter, BOOL* pb, UINT Count' },
            { 'SetInt',                         'D3DXHANDLE hParameter, INT n' },
            { 'GetInt',                         'D3DXHANDLE hParameter, INT* pn' },
            { 'SetIntArray',                    'D3DXHANDLE hParameter, const INT* pn, UINT Count' },
            { 'GetIntArray',                    'D3DXHANDLE hParameter, INT* pn, UINT Count' },
            { 'SetFloat',                       'D3DXHANDLE hParameter, FLOAT f' },
            { 'GetFloat',                       'D3DXHANDLE hParameter, FLOAT* pf' },
            { 'SetFloatArray',                  'D3DXHANDLE hParameter, const FLOAT* pf, UINT Count' },
            { 'GetFloatArray',                  'D3DXHANDLE hParameter, FLOAT* pf, UINT Count' },
            { 'SetVector',                      'D3DXHANDLE hParameter, const D3DXVECTOR4* pVector' },
            { 'GetVector',                      'D3DXHANDLE hParameter, D3DXVECTOR4* pVector' },
            { 'SetVectorArray',                 'D3DXHANDLE hParameter, const D3DXVECTOR4* pVector, UINT Count' },
            { 'GetVectorArray',                 'D3DXHANDLE hParameter, D3DXVECTOR4* pVector, UINT Count' },
            { 'SetMatrix',                      'D3DXHANDLE hParameter, const D3DXMATRIX* pMatrix' },
            { 'GetMatrix',                      'D3DXHANDLE hParameter, D3DXMATRIX* pMatrix' },
            { 'SetMatrixArray',                 'D3DXHANDLE hParameter, const D3DXMATRIX* pMatrix, UINT Count' },
            { 'GetMatrixArray',                 'D3DXHANDLE hParameter, D3DXMATRIX* pMatrix, UINT Count' },
            { 'SetMatrixPointerArray',          'D3DXHANDLE hParameter, const D3DXMATRIX** ppMatrix, UINT Count' },
            { 'GetMatrixPointerArray',          'D3DXHANDLE hParameter, D3DXMATRIX** ppMatrix, UINT Count' },
            { 'SetMatrixTranspose',             'D3DXHANDLE hParameter, const D3DXMATRIX* pMatrix' },
            { 'GetMatrixTranspose',             'D3DXHANDLE hParameter, D3DXMATRIX* pMatrix' },
            { 'SetMatrixTransposeArray',        'D3DXHANDLE hParameter, const D3DXMATRIX* pMatrix, UINT Count' },
            { 'GetMatrixTransposeArray',        'D3DXHANDLE hParameter, D3DXMATRIX* pMatrix, UINT Count' },
            { 'SetMatrixTransposePointerArray', 'D3DXHANDLE hParameter, const D3DXMATRIX** ppMatrix, UINT Count' },
            { 'GetMatrixTransposePointerArray', 'D3DXHANDLE hParameter, D3DXMATRIX** ppMatrix, UINT Count' },
            { 'SetString',                      'D3DXHANDLE hParameter, LPCSTR pString' },
            { 'GetString',                      'D3DXHANDLE hParameter, LPCSTR* ppString' },
            { 'SetTexture',                     'D3DXHANDLE hParameter, IDirect3DBaseTexture9* pTexture' },
            { 'GetTexture',                     'D3DXHANDLE hParameter, IDirect3DBaseTexture9* *ppTexture' },
            { 'GetPixelShader',                 'D3DXHANDLE hParameter, IDirect3DPixelShader9* *ppPShader' },
            { 'GetVertexShader',                'D3DXHANDLE hParameter, IDirect3DVertexShader9* *ppVShader' },
            { 'SetArrayRange',                  'D3DXHANDLE hParameter, UINT uStart, UINT uEnd' },
        },
        iid = '017c18ac-103f-4417-8c51-6bf6ef1e56be'
    },
    { 'ID3DXEffectStateManager', inherits = 'IUnknown',
        methods = {
            { 'SetTransform',             'D3Denum State, const D3DMATRIX *pMatrix' },
            { 'SetMaterial',              'const D3DMATERIAL9 *pMaterial' },
            { 'SetLight',                 'DWORD Index, const D3DLIGHT9 *pLight' },
            { 'LightEnable',              'DWORD Index, BOOL Enable' },
            { 'SetRenderState',           'D3Denum State, DWORD Value' },
            { 'SetTexture',               'DWORD Stage, IDirect3DBaseTexture9* pTexture' },
            { 'SetTextureStageState',     'DWORD Stage, D3Denum Type, DWORD Value' },
            { 'SetSamplerState',          'DWORD Sampler, D3Denum Type, DWORD Value' },
            { 'SetNPatchMode',            'FLOAT NumSegments' },
            { 'SetFVF',                   'DWORD FVF' },
            { 'SetVertexShader',          'IDirect3DVertexShader9* pShader' },
            { 'SetVertexShaderConstantF', 'UINT RegisterIndex, const FLOAT *pConstantData, UINT RegisterCount' },
            { 'SetVertexShaderConstantI', 'UINT RegisterIndex, const INT *pConstantData, UINT RegisterCount' },
            { 'SetVertexShaderConstantB', 'UINT RegisterIndex, const BOOL *pConstantData, UINT RegisterCount' },
            { 'SetPixelShader',           'IDirect3DPixelShader9* pShader' },
            { 'SetPixelShaderConstantF',  'UINT RegisterIndex, const FLOAT *pConstantData, UINT RegisterCount' },
            { 'SetPixelShaderConstantI',  'UINT RegisterIndex, const INT *pConstantData, UINT RegisterCount' },
            { 'SetPixelShaderConstantB',  'UINT RegisterIndex, const BOOL *pConstantData, UINT RegisterCount' },
        },
        iid = '79aab587-6dbc-4fa7-82de-37fa1781c5ce'
    },
    { 'ID3DXEffect', inherits = 'ID3DXBaseEffect',
        methods = {
            { 'GetPool',                'ID3DXEffectPool** ppPool' },
            { 'SetTechnique',           'D3DXHANDLE hTechnique' },
            { 'GetCurrentTechnique',    ret = 'D3DXHANDLE' },
            { 'ValidateTechnique',      'D3DXHANDLE hTechnique' },
            { 'FindNextValidTechnique', 'D3DXHANDLE hTechnique, D3DXHANDLE *pTechnique' },
            { 'IsParameterUsed',        'D3DXHANDLE hParameter, D3DXHANDLE hTechnique',                     ret = 'BOOL' },
            { 'Begin',                  'UINT *pPasses, DWORD Flags' },
            { 'BeginPass',              'UINT Pass' },
            { 'CommitChanges' },
            { 'EndPass' },
            { 'End' },
            { 'GetDevice',              'IDirect3DDevice9** ppDevice' },
            { 'OnLostDevice' },
            { 'OnResetDevice' },
            { 'SetStateManager',        'ID3DXEffectStateManager* pManager' },
            { 'GetStateManager',        'ID3DXEffectStateManager* *ppManager' },
            { 'BeginParameterBlock' },
            { 'EndParameterBlock',      ret = 'D3DXHANDLE' },
            { 'ApplyParameterBlock',    'D3DXHANDLE hParameterBlock' },
            { 'DeleteParameterBlock',   'D3DXHANDLE hParameterBlock' },
            { 'CloneEffect',            'IDirect3DDevice9* pDevice, ID3DXEffect* ppEffect' },
            { 'SetRawValue',            'D3DXHANDLE hParameter, LPCVOID pData, UINT ByteOffset, UINT Bytes' },
        },
        iid = 'f6ceb4b3-4e4c-40dd-b883-8d8de5ea0cd5'
    },
    { 'ID3DXEffectCompiler', inherits = 'ID3DXBaseEffect',
        methods = {
            { 'SetLiteral',    'D3DXHANDLE hParameter, BOOL Literal' },
            { 'GetLiteral',    'D3DXHANDLE hParameter, BOOL *pLiteral' },
            { 'CompileEffect', 'DWORD Flags, ID3DXBuffer* ppEffect, ID3DXBuffer* ppErrorMsgs' },
            { 'CompileShader', 'D3DXHANDLE hFunction, LPCSTR pTarget, DWORD Flags, ID3DXBuffer* ppShader, ID3DXBuffer* ppErrorMsgs, ID3DXConstantTable* ppConstantTable' },
        },
        iid = '51b8a949-1a31-47e6-bea0-4b30db53f1e0'
    },


}

ffi.cdef [[

	IDirect3D9* Direct3DCreate9(uint32_t sdkversion);

	int D3DPERF_BeginEvent(uint32_t col, wchar_t* name);
	int D3DPERF_EndEvent();
	void D3DPERF_SetMarker(uint32_t col, wchar_t* name);
	void D3DPERF_SetRegion(uint32_t col, wchar_t* name);
	bool32 D3DPERF_QueryRepeatFrame();

	void D3DPERF_SetOptions(uint32_t options);
	uint32_t D3DPERF_GetStatus();

    typedef int (__stdcall *D3DXCompileShaderFromFileW)(
        const wchar_t* srcFile,
        void* defines,
        void* include,
        const wchar_t* functionName,
        const wchar_t* profile,
        unsigned long flags,
        ID3DXBuffer** ppShader,
        ID3DXBuffer** ppErrorMsgs,
        ID3DXConstantTable* * ppConstantTable
    );

    typedef int (__stdcall *D3DXCompileShaderFromFileA)(
        const char* srcFile,
        void* defines,
        void* include,
        const char* functionName,
        const char* profile,
        unsigned long flags,
        ID3DXBuffer** ppShader,
        ID3DXBuffer** ppErrorMsgs,
        ID3DXConstantTable** ppConstantTable
    );

    typedef int (__stdcall *D3DXCreateEffectFromFileA)(
        IDirect3DDevice9* device,
        const char* srcFile,
        void* defines,
        void* include,
        DWORD flags,
        ID3DXEffectPool* pool,
        ID3DXEffect** ppEffect,
        ID3DXBuffer** ppErrorMsgs
    );

    typedef int (__stdcall *D3DXCreateEffectFromFileW)(
        IDirect3DDevice9* device,
        const wchar_t* srcFile,
        void* defines,
        void* include,
        DWORD flags,
        ID3DXEffectPool* pool,
        ID3DXEffect** ppEffect,
        ID3DXBuffer** ppErrorMsgs
    );
]]

ffi.load 'd3d9'
