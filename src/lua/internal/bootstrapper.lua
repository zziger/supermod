local package, setmetatable, error, ipairs, tostring, type, t_concat
    = package, setmetatable, error, ipairs, tostring, type, table.concat

---@class ModPackage
---@field id string
---@field path string
---@field cpath string
---@field fenv table
---@field loaded table
---@field builtin table
---@field module any

---@diagnostic disable-next-line: undefined-global
local modPackages = __modPackages --[[@as table<string, ModPackage>]]
---@diagnostic disable-next-line: undefined-global
local currentModPackage = modPackages[__currentModId --[[@as string]]]

---@param s any
local function checkstring(s)
    local t = type(s)
    if t == "string" then
        return s
    elseif t == "number" then
        return tostring(s)
    else
        error("bad argument #1 to 'require' (string expected, got "..t..")", 3)
    end
end

local function errhandler() error("the require() sentinel can't be indexed or updated", 2) end
local sentinel = setmetatable({}, {__index = errhandler, __newindex = errhandler, __metatable = false})

---@param name string
---@param modPackage ModPackage
local function require_internal(name, modPackage)
    name = checkstring(name)
    local globalLoaded = package.loaded
    local loaded = modPackage.loaded
    local builtin = modPackage.builtin

    if loaded[name] == sentinel then
        error("loop or previous error loading module '"..name.."'", 2)
    end

    local module = loaded[name]
    if module then
        return module
    end

    if globalLoaded[name] then
        local proxy = setmetatable({}, {__index = globalLoaded[name]})
        loaded[name] = proxy
        return proxy
    end

    package.path = modPackage.path
    package.cpath = modPackage.cpath
    local msg = {}

    ---@type nil | fun(name: string): any
    local loader

    if builtin[name] then
        if modPackage ~= currentModPackage then
            error("Cannot import built-in module of another mod")
        end
        loader = function(_) return builtin[name] end
    else
        msg[#msg + 1] = "\n\tno built-in module '" .. name .. "'"
    end

    if loader == nil then
        for _, searcher in ipairs(package.loaders) do
            loader = searcher(name)
            if type(loader) == "function" then break end
            if type(loader) == "string" then
                -- `loader` is actually an error message
                msg[#msg + 1] = loader
            end
            loader = nil
        end
    end

    if loader == nil then
        error("module '" .. name .. "' not found: "..t_concat(msg), 2)
    end

    loaded[name] = sentinel
    package.path = modPackage.path
    package.cpath = modPackage.cpath
    local ok, err = pcall(setfenv, loader, getfenv())
    if not ok then
        local is_preload = package.preload ~= nil
        log[is_preload and "trace" or "warn"]("Failed to setfenv for module " .. name .. ": " .. tostring(err))
        if is_preload then
            log.trace("This is normal for built-in modules")
        end
    end

    local res = loader(name)
    if res ~= nil then
        module = res
    elseif loaded[name] == sentinel or not loaded[name] then
        module = true
    else
	    module = loaded[name]
    end

    loaded[name] = module
    return module
end

---@param name string
function require(name)
    local modPackage = currentModPackage
    local modName, path = name:match("^@([a-zA-Z-_]+)%.(.*)")

    if modName ~= nil then
        modPackage = modPackages[modName]
        if not modPackage then
            error("Failed to find mod " .. modName)
        end
        name = path
    elseif name:sub(1, 1) == "@" then
        modName = name:sub(2)
        modPackage = modPackages[modName]
        if not modPackage then
            error("Failed to find mod " .. name:sub(2))
        end
        return modPackage.module
    end

    setfenv(require_internal, modPackage.fenv)
    return require_internal(name, modPackage)
end