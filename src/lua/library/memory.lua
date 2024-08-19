---@moduleTitle Memory
---@moduleDesc Этот модуль предоставляет доступ к памяти игры, позволяет читать и писать данные в память, а также создавать хуки на функции.

local ffi = require "ffi"
local imgui = require "imgui"
local events = require "events"

ffi.cdef [[
    bool __stdcall VirtualProtect(int32_t, size_t, int32_t, int32_t*);
]]

local protectionBuf = ffi.new("int32_t[1]")

local backup = {
    list = {},
    map = {}
}

---@class memory
local M = {}
M.__index = M

---@class Memory
---@field addr number
---@field unsafe boolean
---@field backup table
---@priority 1
local Memory = {}
Memory.__index = Memory

---@private
---@param location string | number Паттерн или адрес в памяти
---@param cache boolean Использовать кеширование
---@return number addr
function M.resolveLocation(location, cache)
    local addr = 0

    if type(location) == "string" then
        addr = findPattern(cache, location)
    elseif type(location) == "number" then
        addr = location
    end

    if addr == 0 then
        error(location .. " не найден")
    end

    return addr
end

---@class MemoryParams
---@field unsafe boolean? Отключить защиту памяти
---@field cache boolean? Использовать кеширование паттернов (нужно если паттерн указывает больше чем на одно место в памяти)

---Создает новый обьект Memory
---@param location string | number Паттерн или адрес в памяти
---@param params? MemoryParams Параметры
---@return Memory mem --- Обьект Memory
function M.at(location, params)
    local unsafe = false
    local cache = true

    if type(params) == "boolean" then
        unsafe = params --[[@as boolean]]
    elseif type(params) == "table" then
        if params.unsafe ~= nil then
            unsafe = params.unsafe --[[@as boolean]]
        end
        if params.cache ~= nil then
            cache = params.cache --[[@as boolean]]
        end
    end

    local instance = setmetatable({}, Memory)
    instance.addr = M.resolveLocation(location, cache)
    instance.unsafe = unsafe
    return instance
end

---Возвращает текущий модуль, но привязанный к выбранному хранилищу бекапов
---@return memory
---@deprecated
function M.withBackup(backup)
    return M
    --if not backup["map"] then
    --    backup["map"] = {}
    --end
    --if not backup["list"] then
    --    backup["list"] = {}
    --end
    --
    --local mt = {}
    --mt.__index = mt;
    --setmetatable(mt, {__index = M})
    --
    --function mt.at(location, params)
    --    print("call fake at")
    --    local instance = M.at(location, params)
    --    instance.backup = backup
    --    return instance
    --end
    --
    --local mem = {}
    --setmetatable(mem, mt)
    --return mem
end

---Восстанавливает оригинальные байты из бекапа
function M.restoreBackups()
    if not backup["list"] then
        return
    end

    local backupList = backup["list"]
    for i = #backupList, 1, -1 do
        local entry = backupList[i]
        local res = ffi.C.VirtualProtect(entry[1], entry[3], 0x40, protectionBuf)
        if res then
            ffi.copy(ffi.cast("void*", entry[1]), entry[2], entry[3])
        else
            print("Не удалось получить доступ к " .. entry[1] .. " для восстановления состояния памяти")
        end
        ffi.C.VirtualProtect(entry[1], entry[3], protectionBuf[0], protectionBuf)
    end

    backup["list"] = {}
    backup["map"] = {}
end

---@private
---@param addr number Адрес
---@param size number Кол-во памяти
function Memory:writeBackup(addr, size)
    if not backup["map"] or (backup["map"][addr] and backup["map"][addr] >= size) then
        return
    end

    local buf = ffi.new("uint8_t[?]", size)

    ffi.copy(buf, ffi.cast("void*", addr), size)
    table.insert(backup["list"], { addr, buf, size })
    backup["map"][addr] = size
end

---@private
---@param size number Размер защищённой памяти
---@return number? Старый уровень доступа
function Memory:protect(size)
    if backup then
        self:writeBackup(self.addr, size)
    end
    
    if self.unsafe then
        return nil
    end
    
    local res = ffi.C.VirtualProtect(self.addr, size, 0x40, protectionBuf)
    
    if not res then
        error("Не удалось получить доступ к " .. self.addr)
    end
    
    return protectionBuf[0]
end

---@private
---@param size number Размер защищённой памяти
---@param rights number? Старый уровень доступа
function Memory:unprotect(size, rights)
    if self.unsafe or rights == nil then
        return
    end 
    
    ffi.C.VirtualProtect(self.addr, size, rights, protectionBuf)
end

---Возвращает новый обьект Memory добавляя указанный оффсет к адресу
---@param offset number Оффсет от прошлого адреса (в байтах)
---@return Memory
function Memory:add(offset)
    return M.at(self.addr + offset)
end

---Возвращает функцию по текущему адресу
---@param functionType ffi.ct* Тип функции в виде C-декларации
---@return function
function Memory:getFunction(functionType)
    return ffi.cast(functionType, self.addr) --[[@as function]]
end

---Возвращает поинтер в виде указанного типа
---@param type ffi.ct* Тип данных в виде C-декларации
function Memory:getAs(type)
    return ffi.cast(type, self.addr)
end

---Вызывает функцию по текущему адресу
---@param functionType ffi.ct* Тип функции в виде C-декларации
---@param ... any Аргументы функции
---@return any Результат функции
function Memory:call(functionType, ...)
    return self:getFunction(functionType)(unpack(arg))
end

--#region Функции чтения

---Читает данные по адресу используя указанный тип
---@param type ffi.ct* Тип данных в виде C-декларации
function Memory:readAs(type)
    return ffi.cast(ffi.typeof("$*", ffi.typeof(type)), self.addr)[0]
end

---Читает адрес (int32) по текущему адресу, и возвращает обьект Memory с новым адресом
---@return Memory
function Memory:readOffset()
    return M.at(self:readInt32())
end

---Читает инструкцию вызова по относительному адресу (opcode E8), и возвращает обьект Memory с адресом вызываемой функции
---@return Memory
function Memory:readNearCall()
    local addr = self.addr
    return M.at(self:add(1):readInt32() + addr + 5)
end

---Читает int64 по текущему адресу (8 байт)
---@return number
function Memory:readInt64()
    return ffi.cast("__int64*", self.addr)[0]
end
Memory.readLong = Memory.readInt64

---Читает int32 по текущему адресу (4 байта)
---@return number
function Memory:readInt32()
    return ffi.cast("__int32*", self.addr)[0]
end
Memory.readInt = Memory.readInt32
Memory.readDword = Memory.readInt32

---Читает int16 по текущему адресу (2 байта)
---@return number
function Memory:readInt16()
    return ffi.cast("__int16*", self.addr)[0]
end
Memory.readShort = Memory.readInt16
Memory.readWord = Memory.readInt16

---Читает int8 по текущему адресу (1 байт)
---@return number
function Memory:readInt8()
    return ffi.cast("__int8*", self.addr)[0]
end
Memory.readByte = Memory.readInt8
Memory.readChar = Memory.readInt8

---Читает float по текущему адресу (4 байта)
---@return number
function Memory:readFloat()
    return ffi.cast("float*", self.addr)[0]
end
Memory.readSingle = Memory.readFloat

---Читает double по текущему адресу (8 байт)
---@return number
function Memory:readDouble()
    return ffi.cast("double*", self.addr)[0]
end

---Читает bool по текущему адресу (4 байта)
---@return boolean
function Memory:readBool()
    return self:readInt32() ~= 0
end

---Читает короткий bool по текущему адресу (1 байт)
---@return boolean
function Memory:readSBool()
    return self:readInt8() ~= 0
end


---Читает строку по текущему адресу
---@param length number? Длина строки, если не указана - читает до NULL байта
---@return string
function Memory:readString(length)
    if length == nil then
        return ffi.string(ffi.cast("char*", self.addr))
    else
        return ffi.string(ffi.cast("char*", self.addr), length)
    end
end

--#endregion

--#region Функции записи

---Записывает инструкцию вызова по относительному адресу (opcode E8)
---@param value number
function Memory:writeNearCall(value)
    local rights = self:protect(5)
    local addr = self.addr
    ffi.cast("__int8*", self.addr)[0] = 0xE8
    ffi.cast("__int32*", self.addr + 1)[0] = value - self.addr - 5
    self:unprotect(5, rights)
end

---Записывает int64 по текущему адресу (8 байт)
---@param value number
function Memory:writeInt64(value)
    local rights = self:protect(8)
    ffi.cast("__int64*", self.addr)[0] = value
    self:unprotect(8, rights)
end
Memory.writeLong = Memory.writeInt64

---Записывает int32 по текущему адресу (4 байта)
---@param value number
function Memory:writeInt32(value)
    local rights = self:protect(4)
    ffi.cast("__int32*", self.addr)[0] = value
    self:unprotect(4, rights)
end
Memory.writeInt = Memory.writeInt32
Memory.writeDword = Memory.writeInt32

---Записывает int16 по текущему адресу (2 байта)
---@param value number
function Memory:writeInt16(value)
    local rights = self:protect(2)
    ffi.cast("__int16*", self.addr)[0] = value
    self:unprotect(2, rights)
end
Memory.writeShort = Memory.writeInt16
Memory.writeWord = Memory.writeInt16

---Записывает int8 по текущему адресу (1 байт)
---@param value number
function Memory:writeInt8(value)
    local rights = self:protect(1)
    ffi.cast("__int8*", self.addr)[0] = value
    self:unprotect(1, rights)
end
Memory.writeByte = Memory.writeInt8
Memory.writeChar = Memory.writeInt8

---Записывает float по текущему адресу (4 байта)
---@param value number
function Memory:writeFloat(value)
    local rights = self:protect(4)
    ffi.cast("float*", self.addr)[0] = value
    self:unprotect(4, rights)
end
Memory.writeSingle = Memory.writeFloat

---Записывает double по текущему адресу (4 байта)
---@param value number
function Memory:writeDouble(value)
    local rights = self:protect(8)
    ffi.cast("double*", self.addr)[0] = value
    self:unprotect(8, rights)
end
---Записывает NOP по текущему адресу (opcode 0x90)
---@param size number
function Memory:writeNop(size)
    local rights = self:protect(size)
    for i = 0, size - 1 do
        ffi.cast("__int8*", self.addr + i)[0] = 0x90
    end
    self:unprotect(size, rights)
end


function Memory:writeString(string)
    local length = string:len() + 1
    local rights = self:protect(length)
    ffi.copy(ffi.cast("char*", self.addr), string)
    self:unprotect(length, rights)
end

--#endregion

--#region Конвертация данных

---Конвертирует UTF8 строку (char*) в UTF16 строку (wchar_t*)
---@param str string | ffi.cdata*
---@return ffi.cdata*
function Memory.toU16(str)
    return imgui.FromUTF(str)
end

---Конвертирует UTF8 строку (char*) в массив UTF-16 байтов (полезно для ffi.new с wchar_t)
---@param str string | ffi.cdata*
---@return number[]
function Memory.toU16Array(str)
    local u16 = imgui.FromUTF(str)
    local arr = {}
    for i = 0, str:len(), 1 do
        table.insert(arr, u16[i])
    end
    return arr
end

---Конвертирует UTF16 строку (wchar_t*) в UTF8 строку (char*)
---@param wstr ffi.cdata*
---@return ffi.cdata*
function Memory.toU8(wstr)
    return imgui.ToUTF(wstr)
end

---Конвертирует строку (char*) в луа формат
---@param cstr ffi.cdata*
---@return string
function Memory.toStr(cstr)
    return ffi.string(cstr)
end

--#endregion

--#region Хуки

local createHook = __createHook --[[@as fun(addr: number, cb: number, orig: number)]]
local removeHook = __removeHook --[[@as fun(addr: string)]]
local createdHooks = {}

---@class Hook
---@field destroyed boolean Был ли хук удалён
---@field orig function Оригинальная функция
---@field destroy fun() Деактивировать и удалить хук

---@class HookParams
---@field jit boolean Включить JIT-компиляцию функции (ускоряет выполнение, но ломается если внутри оригинальной функции есть другие Lua хуки. Рекомендуется для частовыполняемых функций)

---Регистрирует хук-функцию на текущий адрес
---@param fnType ffi.ct* С-тип хукаемой функции
---@param fn function Функция хука
---@param params? HookParams Параметры хука
---@returns Hook
function Memory:hook(fnType, fn, params)
    if self.addr == 0 then error("Адрес хука не может быть 0") end
    if type(params) ~= "table" or not params.jit then
        jit.off(fn)
    end

    local origBuf = ffi.new(ffi.typeof("$[1]", ffi.typeof(fnType)), {nil})
    local fenv = getfenv()

    local function wrapper(...)
        setfenv(fn, fenv)
        local status, result = pcall(fn, ...)
        if status then
            return result
        else
            log.error("Ошибка в обработчике хука: " .. result)
            return 0
        end
    end

    local callback = ffi.cast(fnType, wrapper)

    local id = createHook(self.addr, tonumber(ffi.cast("uint32_t", callback)), tonumber(ffi.cast("uint32_t", origBuf)))

    local res = {}
    res.destroyed = false
    res.orig = origBuf[0];
    res.id = id

    function res.destroy()
        if res.destroyed then return end
        res.destroyed = true
        removeHook(self.addr, res.id)
        ---@diagnostic disable-next-line: undefined-field
        callback:free()
    end

    table.insert(createdHooks, res)

    return res
end

events.on("_unload", function ()
    for _, v in ipairs(createdHooks) do
        v.destroy()
    end
    createdHooks = {}
    M.restoreBackups()
end)

--#endregion

return M
