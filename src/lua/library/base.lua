---@meta

---@param val number
---@param from number
---@param to number
function math.clamp(val, from, to) 
    return math.min(math.max(val, from), to)
end

local function _print(...)
    local printResult = ""
    for i,v in ipairs({...}) do
        printResult = printResult .. tostring(v) .. "\t"
    end
    log.info(printResult)
end
print = _print