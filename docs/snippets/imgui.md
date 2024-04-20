Этот модуль дает доступ к Dear ImGui. Dear ImGui - это библиотека для создания графического интерфейса.
Используемая версия ImGui - `1.90.4-docking`

## Использование API ImGui

### Подключение библиотеки
```lua
local imgui = require("imgui")
```

### Формат названия функций

#### Функции `ImGui::*`
Функции `ImGui::FunctionName` (C++) доступны в Lua как `imgui.FunctionName` <br/><br/>
C++:
```c++
ImGui::Button("Click me");
```
Lua:
```lua
imgui.Button("Click me")
```

#### Энумерации
Энумы `ImGuiEnumName_EnumMember` (C++) доступны в Lua как `imgui.EnumName.EnumMember` <br/><br/>
C++
```c++
ImGui::Begin("Window", nullptr, ImGuiWindowFlags_NoTitleBar);
```
Lua:
```lua
imgui.Begin("Window", nil, imgui.WindowFlags.NoTitleBar)
```

#### Структуры
Структуры `ImStruct` (C++) доступны в Lua как `imgui.ImStruct` <br/>
Создание структур происходит через вызов. Например:<br/><br/>
C++:
```c++
auto vec = ImVec2(10, 10);
```
Lua:
```lua
local vec = imgui.ImVec2(10, 10)
```

#### Функции структур
Функции `struct.MethodName` (C++) доступны в Lua как `struct:MethodName` <br/><br/>
C++:
```c++
auto drawList = ImGui::GetWindowDrawList();
drawList->AddRectFilled(ImGui::GetItemRectMin(), ImGui::GetItemRectMax(), 0xFFFFFFFF);
```
Lua:
```lua
local drawList = imgui.GetWindowDrawList()
drawList:AddRectFilled(imgui.GetItemRectMin(), imgui.GetItemRectMax(), 0xFFFFFFFF);
```

### Интерфейс мода

Для отрисовки интерфейса внутри окна мода, объявите функцию `renderUi` и вызывайте методы ImGui внутри неё. Пример:
```lua
function renderUi()
    if (imgui.Button("Click me")) then
        print("Button clicked!")
    end
end
```

### Свой интерфейс

Для отрисовки своих окон, обьявите функцию `render` и используйте `imgui.Begin` и `imgui.End` для создания окна. Пример:
```lua
function render()
    if imgui.Begin("My Window") then
        imgui.Text("Hello, world!")
    end
    imgui.End()
end
```