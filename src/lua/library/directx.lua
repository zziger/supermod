---@meta
---@moduleTitle DirectX
---@moduleDesc Этот модуль позволяет обращаться к методам DirectX 8 и DirectX 9

---@class directx
local M = {}

--- Возвращает указатель на IDirect3DDevice9
---@return ffi.ct* IDirect3DDevice9*
function M.getD3D9() end

--- Возвращает указатель на IDirect3DDevice8
---@return ffi.ct* IDirect3DDevice8*
function M.getD3D8() end

--- Обьект, предоставляющий доступ к некоторым API D3DX9, полезным для загрузки и создания различных DirectX обьектов
M.d3dx9 = {}

---@type ffi.ct* D3DXCompileShaderFromFileW
---https://learn.microsoft.com/en-us/windows/win32/direct3d9/d3dxcompileshader
M.d3dx9.D3DXCompileShaderFromFileW = nil

---@type ffi.ct* D3DXCompileShaderFromFileA
---https://learn.microsoft.com/en-us/windows/win32/direct3d9/d3dxcompileshader
M.d3dx9.D3DXCompileShaderFromFileA = nil

---@type ffi.ct* D3DXCreateEffectFromFileW
---https://learn.microsoft.com/en-us/windows/win32/direct3d9/d3dxcreateeffectfromfile
M.d3dx9.D3DXCreateEffectFromFileW = nil

---@type ffi.ct* D3DXCreateEffectFromFileA
---https://learn.microsoft.com/en-us/windows/win32/direct3d9/d3dxcreateeffectfromfile
M.d3dx9.D3DXCreateEffectFromFileA = nil

return M