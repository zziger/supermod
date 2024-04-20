local getModConfig = __getModConfig --[[@as fun(): userdata]]
local configKeyExists = __configKeyExists --[[@as fun(cfg: userdata, key: string): boolean]]
local configGetString = __configGetString --[[@as fun(cfg: userdata, key: string): string]]
local configGetDouble = __configGetDouble --[[@as fun(cfg: userdata, key: string): number]]
local configGetBool = __configGetBool --[[@as fun(cfg: userdata, key: string): boolean]]
local configGetNested = __configGetNested --[[@as fun(cfg: userdata, key: string): userdata]]
local configSet = __configSet --[[@as fun(cfg: userdata, val: any, key: string): userdata]]
local configSave = __configSave --[[@as fun()]]

---@class config
local config = {}

---@private
function config.fromHandle(handle)
    local instance = setmetatable({}, config)
    instance.handle = handle
    return instance
end

---Сохраняет конфиг файл на диск
function config.save()
    configSave()
end

---Обьект конфигурации текущего мода
---@type Config
config.mod = config.fromHandle(getModConfig())

---@class Config
---@field private handle userdata
local Config = {}

---Получает строковое значение по указанному ключу
---@param key string
function Config:getString(key)
    return configGetString(self.handle, key)
end

---Получает численное значение по указанному ключу
---@param key string
function Config:getNumber(key)
    return configGetDouble(self.handle, key)
end

---Получает булево значение по указанному ключу
---@param key string
function Config:getBool(key)
    return configGetBool(self.handle, key)
end

---Получает вложенный обьект по указанному ключу
---@param key string
function Config:getObject(key)
    return config.fromHandle(configGetNested(self.handle, key))
end

---Возвращает существует ли указанный ключ
---@param key string
function Config:has(key)
    return configKeyExists(self.handle, key)
end

---Устанавливает значение по указанному ключу
---@param key string
---@param value number | string | boolean
function Config:set(key, value)
    configSet(self.handle, value, key)
end

return Config
