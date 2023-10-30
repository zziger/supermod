---@meta

M = {}

---Устанавливает текущую текстуру для рендера
---@param asset Asset
function M.setRenderAsset(asset) end

---Устанавливает цвет текста
---@param color rgba
function M.setTextColor(color) end

---Рендерит текущую текстуру на экран
---@param coords vector2
---@param size vector2
---@param uv rect?
---@param color rgba?
function M.render(coords, size, uv, color) end

---Рендерит текст на экран
---@param coords vector2
---@param size number
---@param text string
function M.renderText(coords, size, text) end

return M