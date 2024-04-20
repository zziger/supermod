---@meta assetPool

---@class AssetMeta
---@field notFound boolean
---@field origDir string
---@field origName string
---@field canvasSizeMultiplier vector2
---@field loadedManually boolean

---@class Asset
---@field name string
---@field meta AssetMeta
---@field width number
---@field height number
---@field texture userdata
---@field hasAlpha boolean
---@field isPoolDefault boolean
---@field format number

---@class assetPool
local M = {}

---Возвращает все ассеты из пула
---@return Asset[] 
function M.getAssets() end

---Возвращает ассет по имени
---@param name string
---@return Asset?
function M.getAssetByName(name) end

---Возвращает неизвестный ассет (фиолетово-чёрная шашка)
---@return Asset
function M.getUnknownAsset() end

---Загружает ассет по правилам загрузки ассетов игры (пробует разные расширения файлов и т.д.) от текущей папки
---@param path string
---@param loadFallback boolean?
---@param canvasSizeMultiplier vector2?
---@return Asset?
function M.loadGameAsset(path, loadFallback, canvasSizeMultiplier) end

---Загружает ассет по правилам загрузки ассетов игры (пробует разные расширения файлов и т.д.) от папки data
---@param path string
---@param loadFallback boolean?
---@param canvasSizeMultiplier vector2?
---@return Asset?
function M.loadGameAssetFromData(path, loadFallback, canvasSizeMultiplier) end

---Загружает ассет по точному пути к файлу от текущей папки
---@param path string
---@param key string
---@param loadFallback boolean?
---@param canvasSizeMultiplier vector2?
---@return Asset?
function M.loadAsset(path, key, loadFallback, canvasSizeMultiplier) end

---Удаляет ассет из пула и выгружает из памяти
---@param asset Asset
function M.removeAsset(asset) end

return M