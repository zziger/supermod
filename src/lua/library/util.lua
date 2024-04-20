---@class util
local M = {}

---@generic T : table
---@param table T
function M.readOnly(table)
  return setmetatable({}, {
    __index = table,
    __newindex = function() error("Attempt to modify read-only table", 2) end,
    __metatable = false
  })
end

return M