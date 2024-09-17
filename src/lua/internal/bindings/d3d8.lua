local ffi = require 'ffi'
local com = require 'winapi.com'

ffi.cdef [[

	enum {
		D3D8SDK_VERSION = 220,
    D3DVSD_TOKEN_NOP = 0,
    D3DVSD_TOKEN_STREAM = 1,
    D3DVSD_TOKEN_STREAMDATA = 2,
    D3DVSD_TOKEN_TESSELLATOR = 3,
    D3DVSD_TOKEN_CONSTMEM = 4,
    D3DVSD_TOKEN_EXT = 5,
    D3DVSD_TOKEN_END = 7,
		D3DVSD_TOKENTYPESHIFT = 29,
		D3DVSD_TOKENTYPEMASK = 0xE0000000,
		D3DVSD_STREAMNUMBERSHIFT = 0,
		D3DVSD_STREAMNUMBERMASK = 0xF,
		D3DVSD_DATALOADTYPESHIFT = 28,
		D3DVSD_DATALOADTYPEMASK = 0x10000000,
		D3DVSD_DATATYPESHIFT = 16,
		D3DVSD_DATATYPEMASK = 0xF0000,
		D3DVSD_SKIPCOUNTSHIFT = 16,
		D3DVSD_SKIPCOUNTMASK = 0xF0000,
		D3DVSD_VERTEXREGSHIFT = 0,
		D3DVSD_VERTEXREGMASK = 0x1F,
		D3DVSD_VERTEXREGINSHIFT = 20,
		D3DVSD_VERTEXREGINMASK = 0xF00000,
		D3DVSD_CONSTCOUNTSHIFT = 25,
		D3DVSD_CONSTCOUNTMASK = 0x1E000000,
		D3DVSD_CONSTADDRESSSHIFT = 0,
		D3DVSD_CONSTADDRESSMASK = 0x7F,
		D3DVSD_CONSTRSSHIFT = 16,
		D3DVSD_CONSTRSMASK = 0x1FFF0000,
		D3DVSD_EXTCOUNTSHIFT = 24,
		D3DVSD_EXTCOUNTMASK = 0x1F000000,
		D3DVSD_EXTINFOSHIFT = 0,
		D3DVSD_EXTINFOMASK = 0xFFFFFF,
		D3DORDER_LINEAR = 1,
		D3DORDER_CUBIC = 3,
		D3DORDER_QUINTIC = 5,
		D3DCURRENT_DISPLAY_MODE = 0xEFFFFF,
		D3DENUM_NO_WHQL_LEVEL = 2,
		D3DVSDT_FLOAT1      = 0x00,
		D3DVSDT_FLOAT2      = 0x01,
		D3DVSDT_FLOAT3      = 0x02,
		D3DVSDT_FLOAT4      = 0x03,
		D3DVSDT_D3DCOLOR    = 0x04,
		D3DVSDT_UBYTE4      = 0x05,
		D3DVSDT_SHORT2      = 0x06,
		D3DVSDT_SHORT4      = 0x07,
		D3DVSDE_POSITION        = 0,
		D3DVSDE_BLENDWEIGHT     = 1,
		D3DVSDE_BLENDINDICES    = 2,
		D3DVSDE_NORMAL          = 3,
		D3DVSDE_PSIZE           = 4,
		D3DVSDE_DIFFUSE         = 5,
		D3DVSDE_SPECULAR        = 6,
		D3DVSDE_TEXCOORD0       = 7,
		D3DVSDE_TEXCOORD1       = 8,
		D3DVSDE_TEXCOORD2       = 9,
		D3DVSDE_TEXCOORD3       = 10,
		D3DVSDE_TEXCOORD4       = 11,
		D3DVSDE_TEXCOORD5       = 12,
		D3DVSDE_TEXCOORD6       = 13,
		D3DVSDE_TEXCOORD7       = 14,
		D3DVSDE_POSITION2       = 15,
		D3DVSDE_NORMAL2         = 16,
		D3DVSD_STREAMTESSSHIFT = 28,
		D3DVSD_STREAMTESSMASK = 0x10000000,
    D3D8SPR_TEMP = 0,
    D3D8SPR_INPUT8 = 0x10000000,
    D3D8SPR_CONST8 = 0x20000000,
    D3D8SPR_ADDR8 = 0x30000000,
    D3D8SPR_TEXTURE8 = 0x30000000,
    D3D8SPR_RASTOUT8 = 0x40000000,
    D3D8SPR_ATTROUT8 = 0x50000000,
    D3D8SPR_TEXCRDOUT8 = 0x60000000
	};

	typedef struct { uint32_t X, Y, Width, Height; float MinZ, MaxZ; } D3DVIEWPORT8;
	typedef struct { uint32_t ClipUnion, ClipIntersection; } D3DCLIPSTATUS8;
	typedef struct { D3DCOLORVALUE Diffuse, Ambient, Specular, Emissive; float Power; } D3DMATERIAL8;
	typedef struct {
		D3Denum Type;
		D3DCOLORVALUE Diffuse, Specular, Ambient;
		D3DVECTOR Position, Direction;
		float Range, Falloff, Attenuation0, Attenuation1, Attenuation2, Theta, Phi;
	} D3DLIGHT8;
	typedef struct { uint32_t AdapterOrdinal; D3Denum DeviceType; HWND hFocusWindow; uint32_t BehaviorFlags; } D3DDEVICE_CREATION_PARAMETERS;

	// NOTE: renamed to avoid conflict with D3D9's
	typedef struct D3D8PRESENT_PARAMETERS {
    uint32_t BackBufferWidth, BackBufferHeight;
    D3Denum BackBufferFormat;
    uint32_t BackBufferCount;
    D3Denum MultiSampleType;
    D3Denum SwapEffect;
    HWND hDeviceWindow;
    bool32 Windowed;
    bool32 EnableAutoDepthStencil;
    D3Denum AutoDepthStencilFormat;
    uint32_t Flags;
    uint32_t FullScreen_RefreshRateInHz;
    uint32_t FullScreen_PresentationInterval;
	} D3D8PRESENT_PARAMETERS;

	typedef struct {
		D3Denum Format, Type;
		uint32_t Usage;
		D3Denum Pool;
		uint32_t Size;
		uint32_t FVF;
	} D3DVERTEXBUFFER_DESC;

	typedef struct {
		D3Denum Format, Type;
		uint32_t Usage;
		D3Denum Pool;
		uint32_t Size;
	} D3DINDEXBUFFER_DESC;

	typedef struct {
		D3Denum Format, Type;
		uint32_t Usage;
		D3Denum Pool;
		uint32_t Size;
		D3Denum MultiSampleType;
		uint32_t Width, Height;
	} D3DSURFACE_DESC;

	typedef struct {
		D3Denum Format, Type;
		uint32_t Usage;
		D3Denum Pool;
		uint32_t Size, Width, Height, Depth;
	} D3DVOLUME_DESC;

	typedef struct {
		uint32_t StartVertexOffsetWidth, StartVertexOffsetHeight, Width, Height, Stride;
		D3Denum Basis, Order;
	} D3DRECTPATCH_INFO;

	typedef struct { uint32_t StartVertexOffset, NumVertices; D3Denum Basis, Order; } D3DTRIPATCH_INFO;

	typedef struct {
		char Driver[MAX_DEVICE_IDENTIFIER_STRING], Description[MAX_DEVICE_IDENTIFIER_STRING];
		int64_t DriverVersion;
		uint32_t VendorId, DeviceId, SubSysId, Revision;
		GUID DeviceIdentifier;
		uint32_t WHQLLevel;
	} D3DADAPTER_IDENTIFIER8;

	typedef struct D3DCAPS8 {
		D3Denum  DeviceType;
		uint32_t AdapterOrdinal, Caps, Caps2, Caps3, PresentationIntervals, CursorCaps, DevCaps,
			PrimitiveMiscCaps, RasterCaps, ZCmpCaps, SrcBlendCaps, DestBlendCaps, AlphaCmpCaps,
			ShadeCaps, TextureCaps, TextureFilterCaps, CubeTextureFilterCaps, VolumeTextureFilterCaps,
			TextureAddressCaps, VolumeTextureAddressCaps, LineCaps;
		uint32_t MaxTextureWidth, MaxTextureHeight, MaxVolumeExtent, MaxTextureRepeat,
			MaxTextureAspectRatio, MaxAnisotropy;
		float MaxVertexW;
		float GuardBandLeft, GuardBandTop, GuardBandRight, GuardBandBottom;
		float ExtentsAdjust;
		uint32_t StencilCaps, FVFCaps, TextureOpCaps;
		uint32_t MaxTextureBlendStages, MaxSimultaneousTextures;
		uint32_t VertexProcessingCaps;
		uint32_t MaxActiveLights, MaxUserClipPlanes, MaxVertexBlendMatrices, MaxVertexBlendMatrixIndex;
		float MaxPointSize;
		uint32_t MaxPrimitiveCount, MaxVertexIndex, MaxStreams, MaxStreamStride;
		uint32_t VertexShaderVersion, MaxVertexShaderConst, PixelShaderVersion;
		float MaxPixelShaderValue;
	} D3DCAPS8;

]]

com.def {
	{'IDirect3D8', final=true;
		methods = {
			{'RegisterSoftwareDevice', 'void* initfunc'};
			{'GetAdapterCount', ret='uint32_t'};
			{'GetAdapterIdentifier', 'uint32_t adapter, uint32_t flags, D3DADAPTER_IDENTIFIER8* out_identifier'};
			{'GetAdapterModeCount', 'uint32_t adapter', ret='uint32_t'};
			{'EnumAdapterModes', 'uint32_t adapter, uint32_t mode, D3DDISPLAYMODE* out_mode'};
			{'GetAdapterDisplayMode', 'uint32_t adapter, D3DDISPLAYMODE* out_mode'};
			{'CheckDeviceType', 'uint32_t adapter, D3Denum checktype, D3Denum displayformat, D3Denum backbufferformat, bool32 windowed'};
			{'CheckDeviceFormat', 'uint32_t adapter, D3Denum devicetype, D3Denum adapterformat, uint32_t usage, D3Denum resourcetype, D3Denum checkformat'};
			{'CheckDeviceMultiSampleType', 'uint32_t adapter, D3Denum devicetype, D3Denum surfaceformat, bool32 windowed, D3Denum multisampletype'};
			{'CheckDepthStencilMatch', 'uint32_t adapter, D3Denum devicetype, D3Denum adapterformat, D3Denum rendertargetformat, D3Denum depthstencilformat'};
			{'GetDeviceCaps', 'uint32_t adapter, D3Denum devicetype, D3DCAPS8* out_caps'};
			{'GetAdapterMonitor', 'uint32_t adapter', ret='HMONITOR'};
			{'CreateDevice', 'uint32_t adapter, D3Denum devicetype, HWND focuswindow, uint32_t behaviorflags, D3D8PRESENT_PARAMETERS*, IDirect3DDevice8** out_device'};
		};
		iid = '1dd9e8da-1c77-4d40-b0cf-98fefdff9512';
	};
	{'IDirect3DDevice8', final=true;
		methods = {
			{'TestCooperativeLevel'};
			{'GetAvailableTextureMem', ret='uint32_t'};
			{'ResourceManagerDiscardBytes', 'uint32_t bytes'};
			{'GetDirect3D', 'IDirect3D8** out_direct3D'};
			{'GetDeviceCaps', 'D3DCAPS8* out_caps'};
			{'GetDisplayMode', 'D3DDISPLAYMODE* out_mode'};
			{'GetCreationParameters', 'D3DDEVICE_CREATION_PARAMETERS* out_params'};
			{'SetCursorProperties', 'uint32_t hotspotx, uint32_t hotspoty, IDirect3DSurface8* cursor_bitmap'};
			{'SetCursorPosition', 'uint32_t x, uint32_t y, uint32_t flags', ret='void'};
			{'ShowCursor', 'bool32 show', ret='bool32'};
			{'CreateAdditionalSwapChain', 'D3D8PRESENT_PARAMETERS* params, IDirect3DSwapChain8** out_swapchain'};
			{'Reset', 'D3D8PRESENT_PARAMETERS* params'};
			{'Present', 'const RECT* sourcerect, const RECT* destrect, HWND overridewindow, const RGNDATA* dirtyregion'};
			{'GetBackBuffer', 'uint32_t which, D3Denum type, IDirect3DSurface8** out_surface'};
			{'GetRasterStatus', 'D3DRASTER_STATUS* out_status'};
			{'SetGammaRamp', 'uint32_t flags, const D3DGAMMARAMP* ramp', ret='void'};
			{'GetGammaRamp', 'D3DGAMMARAMP* out_ramp', ret='void'};
			{'CreateTexture', [[
				uint32_t width, uint32_t height, uint32_t levels, uint32_t usage, D3Denum format, D3Denum pool, IDirect3DTexture8** out_texture]]};
			{'CreateVolumeTexture', [[
				uint32_t width, uint32_t height, uint32_t depth, uint32_t levels, uint32_t usage, D3Denum format, D3Denum pool, IDirect3DVolumeTexture8** out_texture]]};
			{'CreateCubeTexture', [[
				uint32_t edgelength, uint32_t levels, uint32_t usage, D3Denum format, D3Denum pool, IDirect3DCubeTexture8** out_texture]]};
			{'CreateVertexBuffer', [[
				uint32_t length, uint32_t usage, uint32_t fvf, D3Denum pool, IDirect3DVertexBuffer8** out_buffer]]};
			{'CreateIndexBuffer', [[
				uint32_t length, uint32_t usage, D3Denum format, D3Denum pool, IDirect3DIndexBuffer8** out_buffer]]};
			{'CreateRenderTarget', [[
				uint32_t width, uint32_t height, D3Denum format, D3Denum multisample, bool32 lockable, IDirect3DSurface8** out_surface]]};
			{'CreateDepthStencilSurface', [[
				uint32_t width, uint32_t height, D3Denum format, D3Denum multisample, IDirect3DSurface8** out_surface]]};
			{'CreateImageSurface', [[
				uint32_t width, uint32_t height, D3Denum format, IDirect3DSurface8** out_surface]]};
			{'CopyRects', 'IDirect3DSurface8* src, const RECT* src_rects, uint32_t count, IDirect3DSurface8* dst, const POINT* dst_points'};
			{'UpdateTexture', 'IDirect3DBaseTexture8* pSourceTexture, IDirect3DBaseTexture8* pDestinationTexture'};
			{'GetFrontBuffer', 'IDirect3DSurface8* pDestSurface'};
			{'SetRenderTarget', 'IDirect3DSurface8* pRenderTarget, IDirect3DSurface8* pNewZStencil'};
			{'GetRenderTarget', 'IDirect3DSurface8** out_surface'};
			{'GetDepthStencilSurface', 'IDirect3DSurface8** out_surface'};
			{'BeginScene'};
			{'EndScene'};
			{'Clear', 'uint32_t count, const D3DRECT* rects_array, uint32_t flags, uint32_t color, float Z, uint32_t Stencil'};
			{'SetTransform', 'D3Denum State, const D3DMATRIX* pMatrix'};
			{'GetTransform', 'D3Denum State, D3DMATRIX* pMatrix'};
			{'MultiplyTransform', 'D3Denum, const D3DMATRIX*'};
			{'SetViewport', 'const D3DVIEWPORT8* viewport'};
			{'GetViewport', 'D3DVIEWPORT8* out_viewport'};
			{'SetMaterial', 'const D3DMATERIAL8* material'};
			{'GetMaterial', 'D3DMATERIAL8* out_material'};
			{'SetLight', 'uint32_t index, const D3DLIGHT8* light'};
			{'GetLight', 'uint32_t index, D3DLIGHT8* out_light'};
			{'LightEnable', 'uint32_t index, bool32 enable'};
			{'GetLightEnable', 'uint32_t index, bool32* enable'};
			{'SetClipPlane', 'uint32_t index, const float* plane'};
			{'GetClipPlane', 'uint32_t index, float* out_plane'};
			{'SetRenderState', 'D3Denum State, uint32_t Value'};
			{'GetRenderState', 'D3Denum State, uint32_t* pValue'};
			{'BeginStateBlock'};
			{'EndStateBlock', 'uint32_t* out_token'};
			{'ApplyStateBlock', 'uint32_t token'};
			{'CaptureStateBlock', 'uint32_t token'};
			{'DeleteStateBlock', 'uint32_t token'};
			{'CreateStateBlock', 'D3Denum Type, uint32_t* out_token'};
			{'SetClipStatus', 'const D3DCLIPSTATUS8* status'};
			{'GetClipStatus', 'D3DCLIPSTATUS8* out_status'};
			{'GetTexture', 'uint32_t stage, IDirect3DBaseTexture8** out_texture'};
			{'SetTexture', 'uint32_t stage, IDirect3DBaseTexture8* texture'};
			{'GetTextureStageState', 'uint32_t stage, D3Denum type, uint32_t* out_value'};
			{'SetTextureStageState', 'uint32_t stage, D3Denum type, uint32_t value'};
			{'ValidateDevice', 'uint32_t* numpasses'};
			{'GetInfo', 'uint32_t DevInfoID, void* pDevInfoStruct, uint32_t DevInfoStructSize'};
			{'SetPaletteEntries', 'uint32_t PaletteNumber, const PALETTEENTRY* pEntries'};
			{'GetPaletteEntries', 'uint32_t PaletteNumber, PALETTEENTRY* pEntries'};
			{'SetCurrentTexturePalette', 'uint32_t palettenumber'};
			{'GetCurrentTexturePalette', 'uint32_t* out_palettenumber'};
			{'DrawPrimitive', 'D3Denum PrimitiveType, uint32_t StartVertex, uint32_t PrimitiveCount'};
			{'DrawIndexedPrimitive', 'D3Denum, uint32_t minIndex, uint32_t NumVertices, uint32_t startIndex, uint32_t primCount'};
			{'DrawPrimitiveUP', 'D3Denum PrimitiveType, uint32_t PrimitiveCount, const void* pVertexStreamZeroData, uint32_t VertexStreamZeroStride'};
			{'DrawIndexedPrimitiveUP', [[
				D3Denum PrimitiveType, uint32_t MinVertexIndex, uint32_t NumVertexIndices, uint32_t PrimitiveCount,
				const void* pIndexData, D3Denum IndexDataFormat, const void* pVertexStreamZeroData, uint32_t VertexStreamZeroStride]]};
			{'ProcessVertices', 'uint32_t SrcStartIndex, uint32_t DestIndex, uint32_t VertexCount, IDirect3DVertexBuffer8* pDestBuffer, uint32_t flags'};
			{'CreateVertexShader', 'const uint32_t* pDeclaration, const uint32_t* pFunction, uint32_t* out_handle, uint32_t Usage'};
			{'SetVertexShader', 'uint32_t handle'};
			{'GetVertexShader', 'uint32_t* out_handle'};
			{'DeleteVertexShader', 'uint32_t handle'};
			{'SetVertexShaderConstant', 'uint32_t Register, const void* data, uint32_t ConstantCount'};
			{'GetVertexShaderConstant', 'uint32_t Register, void* out_data, uint32_t ConstantCount'};
			{'GetVertexShaderDeclaration', 'uint32_t handle, void* pData, uint32_t* pSizeOfData'};
			{'GetVertexShaderFunction', 'uint32_t handle, void* pData, uint32_t* pSizeOfData'};
			{'SetStreamSource', 'uint32_t StreamNumber, IDirect3DVertexBuffer8* pStreamData, uint32_t Stride'};
			{'GetStreamSource', 'uint32_t StreamNumber, IDirect3DVertexBuffer8** ppStreamData, uint32_t* pStride'};
			{'SetIndices', 'IDirect3DIndexBuffer8* pIndexData, uint32_t BaseVertexIndex'};
			{'GetIndices', 'IDirect3DIndexBuffer8** ppIndexData, uint32_t* pBaseVertexIndex'};
			{'CreatePixelShader', 'const uint32_t* pFunction, uint32_t* out_handle'};
			{'SetPixelShader', 'uint32_t handle'};
			{'GetPixelShader', 'uint32_t* out_handle'};
			{'DeletePixelShader', 'uint32_t handle'};
			{'SetPixelShaderConstant', 'uint32_t Register, const void* pConstantData, uint32_t ConstantCount'};
			{'GetPixelShaderConstant', 'uint32_t Register, void* pConstantData, uint32_t ConstantCount'};
			{'GetPixelShaderFunction', 'uint32_t handle, void* pData, uint32_t* pSizeOfData'};
			{'DrawRectPatch', 'uint32_t handle, const float* pNumSegs, const D3DRECTPATCH_INFO* pRectPatchInfo'};
			{'DrawTriPatch', 'uint32_t handle, const float* pNumSegs, const D3DTRIPATCH_INFO* pTriPatchInfo'};
			{'DeletePatch', 'uint32_t handle'};
		};
		iid = '7385e5df-8fe8-41d5-86b6-d7b48547b6cf';
	};
	{'IDirect3DSwapChain8', final=true;
		methods = {
			{'Present', 'const RECT* sourcerect, const RECT* destrect, HWND destwindowoverride, const RGNDATA* dirty_rection'};
			{'GetBackBuffer', 'uint32_t backbuffer, D3Denum type, IDirect3DSurface8** out_backbuffer'};
		};
		iid = '928c088b-76b9-4c6b-a536-a590853876cd';
	};
	{'IDirect3DResource8';
		methods = {
			{'GetDevice', 'IDirect3DDevice8** out_device'};
			{'SetPrivateData', 'GUID* guid, const void* data, uint32_t size, uint32_t flags'};
			{'GetPrivateData', 'GUID* guid, void* data, uint32_t* out_size'};
			{'FreePrivateData', 'GUID* guid'};
			{'SetPriority', 'uint32_t priority', ret='uint32_t'};
			{'GetPriority', ret='uint32_t'};
			{'PreLoad', ret='void'};
			{'GetType', ret='D3Denum'};
		};
		iid = '1b36bb7b-09b7-410a-b445-7d1430d7b33f';
	};
	{'IDirect3DBaseTexture8', inherits='IDirect3DResource8';
		methods = {
			{'SetLOD', 'uint32_t lod', ret='uint32_t'};
			{'GetLOD', ret='uint32_t'};
			{'GetLevelCount', ret='uint32_t'};
		};
		iid = 'b4211cfa-51b9-4a9f-ab78-db99b2bb678e';
	};
	{'IDirect3DTexture8', inherits='IDirect3DBaseTexture8', final=true;
		methods = {
			{'GetLevelDesc', 'uint32_t Level, D3DSURFACE_DESC* pDesc'};
			{'GetSurfaceLevel', 'uint32_t Level, IDirect3DSurface8** ppSurfaceLevel'};
			{'LockRect', 'uint32_t Level, D3DLOCKED_RECT* pLockedRect, const RECT* rect, uint32_t flags'};
			{'UnlockRect', 'uint32_t Level'};
			{'AddDirtyRect', 'const RECT* pDirtyRect'};
		};
		iid = 'e4cdd575-2866-4f01-b12e-7eece1ec9358';
	};
	{'IDirect3DVolumeTexture8', inherits='IDirect3DBaseTexture8', final=true;
		methods = {
			{'GetLevelDesc', 'uint32_t Level, D3DVOLUME_DESC* pDesc'};
			{'GetVolumeLevel', 'uint32_t Level, IDirect3DVolume8** ppVolumeLevel'};
			{'LockBox', 'uint32_t Level, D3DLOCKED_BOX* pLockedVolume, const D3DBOX* pBox, uint32_t flags'};
			{'UnlockBox', 'uint32_t Level'};
			{'AddDirtyBox', 'const D3DBOX* pDirtyBox'};
		};
		iid = '4b8aaafa-140f-42ba-9131-597eafaa2ead';
	};
	{'IDirect3DCubeTexture8', inherits='IDirect3DBaseTexture8', final=true;
		methods = {
			{'GetLevelDesc', 'uint32_t level, D3DSURFACE_DESC* out_desc'};
			{'GetCubeMapSurface', 'D3Denum facetype, uint32_t level, IDirect3DSurface8** out_surface'};
			{'LockRect', 'D3Denum facetype, uint32_t level, D3DLOCKED_RECT* out_lockedrect, const RECT* rect, uint32_t flags'};
			{'UnlockRect', 'D3Denum facetype, uint32_t level'};
			{'AddDirtyRect', 'D3Denum facetype, const RECT* dirtyrect'};
		};
		iid = '3ee5b968-2aca-4c34-8bb5-7e0c3d19b750';
	};
	{'IDirect3DVertexBuffer8', inherits='IDirect3DResource8', final=true;
		methods = {
			{'Lock', 'uint32_t offset, uint32_t size, uint8_t** out_data, uint32_t flags'};
			{'Unlock'};
			{'GetDesc', 'D3DVERTEXBUFFER_DESC* out_desc'};
		};
		iid = '8aeeeac7-05f9-44d4-b591-000b0df1cb95';
	};
	{'IDirect3DIndexBuffer8', inherits='IDirect3DResource8', final=true;
		methods = {
			{'Lock', 'uint32_t offset, uint32_t size, uint8_t** out_ptr, uint32_t flags'};
			{'Unlock'};
			{'GetDesc', 'D3DINDEXBUFFER_DESC* out_desc'};
		};
		iid = '0e689c9a-053d-44a0-9d92-db0e3d750f86';
	};
	{'IDirect3DSurface8', final=true;
		methods = {
			{'GetDevice', 'IDirect3DDevice8** out_device'};
			{'SetPrivateData', 'GUID* guid, const void* data, uint32_t size, uint32_t flags'};
			{'GetPrivateData', 'GUID* guid, void* out_data, uint32_t* out_size'};
			{'FreePrivateData', 'GUID* guid'};
			{'GetContainer', 'GUID* guid, void** out_container'};
			{'GetDesc', 'D3DSURFACE_DESC* out_desc'};
			{'LockRect', 'D3DLOCKED_RECT* out_lockedrect, const RECT* rect, uint32_t flags'};
			{'UnlockRect'};
		};
		iid = 'b96eebca-b326-4ea5-882f-2ff5bae021dd';
	};
	{'IDirect3DVolume8', final=true;
		methods = {
			{'GetDevice', 'IDirect3DDevice8** out_device'};
			{'SetPrivateData', 'GUID* guid, const void* data, uint32_t size, uint32_t flags'};
			{'GetPrivateData', 'GUID* guid, void* out_data, uint32_t* out_size'};
			{'FreePrivateData', 'GUID* guid'};
			{'GetContainer', 'GUID* guid, void** out_container'};
			{'GetDesc', 'D3DVOLUME_DESC* out_desc'};
			{'LockBox', 'D3DLOCKED_BOX* pLockedVolume, const D3DBOX* box, uint32_t flags'};
			{'UnlockBox'};
		};
		iid = 'bd7349f5-14f1-42e4-9c79-972380db40c0';
	};
}

ffi.cdef [[

	IDirect3D8* Direct3DCreate8(uint32_t sdkversion);

]]

ffi.load 'd3d8'
