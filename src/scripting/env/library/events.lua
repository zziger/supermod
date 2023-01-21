local ffi = require "ffi"

local events = {}

local registeredEvents = {}
local reverseMap = {}
local lastId = 0

local enableEvent = __enableEvent --[[@as fun(event: string)]]
local disableEvent = __disableEvent --[[@as fun(event: string)]]

---@class Event

---@class CancellableEvent : Event
---@field cancel fun(self: Event) Отменить ивент
---@field isCancelled fun(self: Event): boolean Проверить отменён ли ивент

---@class ResolveFileEvent : Event
---@field absolutePath string Абсолютный путь к текущему файлу
---@field getResolvedPath fun(self: Event): string | nil Получить обработанный путь
---@field setResolvedPath fun(self: Event, path: string) Установить новый обработанный путь
---@field clearResolvedPath fun(self: Event) Сбрсоить обработанный путь (использовать путь по-умолчанию)

---@class ModEvent : Event
---@field modInfo ModInfo Информация о моде

---@class WindowEvent : CancellableEvent
---@field hWnd number Ссылка на окно ивента (int*)
---@field msg number Идентификатор ивента
---@field lParam number Параметр L (зависит от ивента)
---@field wParam number Параметр W (зависит от ивента)

---@alias eventHandler<T> fun(event: T) | fun()

---Подписывает функцию на ивент
---@param eventName string название ивента
---@param fn eventHandler<Event>
---@return number id ID подписанного ивента для отписи через events.off
---@overload fun(eventName: "gameLoaded", fn: eventHandler<Event>)
---@overload fun(eventName: "resolveFile", fn: eventHandler<ResolveFileEvent>)
---@overload fun(eventName: "soundsLoaded", fn: eventHandler<Event>)
---@overload fun(eventName: "beforeTick", fn: eventHandler<Event>)
---@overload fun(eventName: "afterTick", fn: eventHandler<Event>)
---@overload fun(eventName: "uiRender", fn: eventHandler<Event>)
---@overload fun(eventName: "modLoad", fn: eventHandler<ModEvent>)
---@overload fun(eventName: "modUnload", fn: eventHandler<ModEvent>)
---@overload fun(eventName: "windowEvent", fn: eventHandler<WindowEvent>)
---@overload fun(eventName: "_unload", fn: eventHandler<Event>)
function events.on(eventName, fn)
    if type(eventName) ~= "string" then error("Аргумент eventName должен быть строкой") end
    if type(fn) ~= "function" then error("Аргумент fn должен быть функцией") end
    if not registeredEvents[eventName] then
        registeredEvents[eventName] = {}
        enableEvent(eventName)
    end
    local id = lastId + 1
    lastId = id
    registeredEvents[eventName][id] = fn
    reverseMap[id] = eventName
    return id
end

---Отписывает функцию от ивента
---@param id number ID подписанного ивента
function events.off(id)
    if type(id) ~= "number" then error("Аргумент id должен быть числом") end
    local eventName = reverseMap[id]
    if not eventName or not registeredEvents[eventName] then return end
    registeredEvents[eventName][id] = nil
    reverseMap[id] = nil
    if next(registeredEvents[eventName]) == nil then
        registeredEvents[eventName] = nil
        disableEvent(eventName)
    end
end

function __handleEvent(eventName, eventObj)
    local currEvents = registeredEvents[eventName]
    if not currEvents then return end
    for _, v in next, currEvents do
        local status, result = pcall(v, eventObj)
        if not status then
            print("Ошибка в обработчике ивента " .. eventName .. ": " .. result)
        end
    end
end

return events