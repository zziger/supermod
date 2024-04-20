---@meta
---@moduleTitle Graphics
---@moduleDesc Этот модуль позволяет рендерить текстуры и текст на экран. Эти функции нужно вызывать внутри `render` или своих хуков.

---@class graphics
local M = {}

---Устанавливает текущую текстуру для рендера
---@param asset Asset?
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

---Устанавливает проекцию рендера
---@param size vector2
---@param near number
---@param far number
function M.setRenderProjection(size, near, far) end

---Сбрасывает проекцию рендера до 800x600
function M.resetRenderProjection() end

---Устанавливает трансформацию рендера
---@param pos vector2
function M.setRenderTransform(pos) end

---Сбрасывает трансформацию рендера до 0, 0
function M.resetRenderTransform() end

return M