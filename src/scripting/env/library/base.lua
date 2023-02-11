---@meta

---@param val number
---@param from number
---@param to number
function math.clamp(val, from, to) 
    return math.min(math.max(val, from), to)
end