---@moduleTitle Timers
---@moduleDesc Этот модуль позволяет создавать таймеры, которые будут вызывать функции через определённое время или с определённым интервалом.

local registeredTimers = {}
local lastId = 1
local activeTimers = 0

---@package
---@class Timer
---@field fn fun()
---@field at number
---@field delay number
---@field once boolean

---@class timers
local timers = {}

---Выполняет функцию fn через delay миллисекунд
---@param delay number количество миллисекунд
---@return number id
function timers.setTimeout(fn, delay)
    if type(fn) ~= "function" then error("Аргумент fn должен быть функцией") end
    if type(delay) ~= "number" then error("Аргумент delay должен быть числом") end
    local id = lastId + 1
    lastId = id
    registeredTimers[lastId] = { fn = fn, delay = delay, at = currentTimestamp() + delay, once = true }
    activeTimers = activeTimers + 1
    return id
end

---Выполняет функцию fn каждые delay миллисекунд
---@param delay number количество миллисекунд
---@return number id
function timers.setInterval(fn, delay)
    if type(fn) ~= "function" then error("Аргумент fn должен быть функцией") end
    if type(delay) ~= "number" then error("Аргумент delay должен быть числом") end
    local id = lastId + 1
    lastId = id
    registeredTimers[lastId] = { fn = fn, delay = delay, at = currentTimestamp() + delay, once = false }
    activeTimers = activeTimers + 1
    return id
end

function timers.clearTimer(id)
    if type(id) ~= "number" then error("Аргумент id должен быть числом") end
    if not registeredTimers[id] then return end
    activeTimers = activeTimers - 1
    registeredTimers[id] = nil
end

---@package
function __tick()
    if activeTimers == 0 then return end
    local timestamp = currentTimestamp()
    for k, v in next, registeredTimers do
        if timestamp > v.at then

            local status, result = pcall(v.fn)
            if not status then
                log.error("Ошибка в обработчике таймера: " .. result)
            end

            if v.once then
                timers.clearTimer(k)
            else
                v.at = timestamp + v.delay
            end
        end
    end
end

return timers