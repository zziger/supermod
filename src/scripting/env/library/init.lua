---@meta

---@package
CURRENT_DLL_PATH = ""

MOD_PATH = ""

---@class ModInfo
---@field id string
---@field title string
---@field author string
---@field version string
---@field basePath string
---@field luaScript string
---@field gameVersions number[]
---@field compatible boolean
---@field internal boolean

---@param pat string
---@return number
function findPattern(pat) end

---Возвращает текущее время в миллисекундах
---@return number
function currentTimestamp() end

log = {}

---@param msg string Текст лога
function log:info(msg) end

---@param msg string Текст лога
function log:debug(msg) end

---@param msg string Текст лога
function log:warn(msg) end

---@param msg string Текст лога
function log:error(msg) end

---@param msg string Текст лога
function log:game(msg) end

--- Вызывается модом каждый кадр игры. Можно использовать ImGui API
function render() end

--- Вызывается модом каждый кадр, когда в главном меню выбран текущий мод. Можно использовать ImGui API
function renderUi() end