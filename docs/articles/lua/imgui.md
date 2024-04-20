# Модуль imgui

### Функция `imgui.AcceptDragDropPayload`

---------------------------------------------------

#### Сигнатура

```lua
function imgui.AcceptDragDropPayload(type: string, flags?: DragDropFlags)
  -> const: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>type</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>DragDropFlags</code></td>
      <td>нет</td>
      <td>-----------------------DragDropFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.ActivateItemByID`

#### Сигнатура

```lua
function imgui.ActivateItemByID(id: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.AddContextHook`

#### Сигнатура

```lua
function imgui.AddContextHook(context: ffi.cdata*|ffi.cdecl*|ffi.ctype*, hook: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> ImGuiID: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>context</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiContext*</td>
    </tr>
    <tr>
      <td><code>hook</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImGuiContextHook*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.AddDrawListToDrawDataEx`

#### Сигнатура

```lua
function imgui.AddDrawListToDrawDataEx(draw_data: ffi.cdata*|ffi.cdecl*|ffi.ctype*, out_list: ffi.cdata*|ffi.cdecl*|ffi.ctype*, draw_list: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>draw_data</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImDrawData*</td>
    </tr>
    <tr>
      <td><code>out_list</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImVector_ImDrawListPtr*</td>
    </tr>
    <tr>
      <td><code>draw_list</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImDrawList*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.AddSettingsHandler`

#### Сигнатура

```lua
function imgui.AddSettingsHandler(handler: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>handler</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImGuiSettingsHandler*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.AlignTextToFramePadding`

#### Сигнатура

```lua
function imgui.AlignTextToFramePadding()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.ArrowButton`

#### Сигнатура

```lua
function imgui.ArrowButton(str_id: string, dir: Dir)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>str_id</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>dir</code></td>
      <td><code>Dir</code></td>
      <td>да</td>
      <td>-----------------------Dir----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.ArrowButtonEx`

#### Сигнатура

```lua
function imgui.ArrowButtonEx(str_id: string, dir: Dir, size_arg: ImVec2, flags?: ButtonFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>str_id</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>dir</code></td>
      <td><code>Dir</code></td>
      <td>да</td>
      <td>-----------------------Dir----------------------------</td>
    </tr>
    <tr>
      <td><code>size_arg</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>ButtonFlags</code></td>
      <td>нет</td>
      <td>-----------------------ButtonFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.Begin`

#### Сигнатура

```lua
function imgui.Begin(name: string, p_open?: ffi.cdata*|ffi.cdecl*|ffi.ctype*, flags?: WindowFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>name</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>p_open</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>bool*</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>WindowFlags</code></td>
      <td>нет</td>
      <td>-----------------------WindowFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### ~~Функция `imgui.BeginChild`~~

 generic version

#### Сигнатура

```lua
function imgui.BeginChild(a1: any, a2: any, a3: any, a4: any)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a3</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a4</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.BeginChildEx`

#### Сигнатура

```lua
function imgui.BeginChildEx(name: string, id: number, size_arg: ImVec2, child_flags: ChildFlags, window_flags: WindowFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>name</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>size_arg</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>child_flags</code></td>
      <td><code>ChildFlags</code></td>
      <td>да</td>
      <td>-----------------------ChildFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>window_flags</code></td>
      <td><code>WindowFlags</code></td>
      <td>да</td>
      <td>-----------------------WindowFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.BeginChild_ID`

#### Сигнатура

```lua
function imgui.BeginChild_ID(id: number, size?: ImVec2, child_flags?: ChildFlags, window_flags?: WindowFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>size</code></td>
      <td><code>ImVec2</code></td>
      <td>нет</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>child_flags</code></td>
      <td><code>ChildFlags</code></td>
      <td>нет</td>
      <td>-----------------------ChildFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>window_flags</code></td>
      <td><code>WindowFlags</code></td>
      <td>нет</td>
      <td>-----------------------WindowFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.BeginChild_Str`

#### Сигнатура

```lua
function imgui.BeginChild_Str(str_id: string, size?: ImVec2, child_flags?: ChildFlags, window_flags?: WindowFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>str_id</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>size</code></td>
      <td><code>ImVec2</code></td>
      <td>нет</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>child_flags</code></td>
      <td><code>ChildFlags</code></td>
      <td>нет</td>
      <td>-----------------------ChildFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>window_flags</code></td>
      <td><code>WindowFlags</code></td>
      <td>нет</td>
      <td>-----------------------WindowFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.BeginColumns`

#### Сигнатура

```lua
function imgui.BeginColumns(str_id: string, count: number, flags?: OldColumnFlags)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>str_id</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>count</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>OldColumnFlags</code></td>
      <td>нет</td>
      <td>-----------------------OldColumnFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.BeginCombo`

#### Сигнатура

```lua
function imgui.BeginCombo(label: string, preview_value: string, flags?: ComboFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>preview_value</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>ComboFlags</code></td>
      <td>нет</td>
      <td>-----------------------ComboFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.BeginComboPopup`

#### Сигнатура

```lua
function imgui.BeginComboPopup(popup_id: number, bb: ImRect, flags: ComboFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>popup_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>bb</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>ComboFlags</code></td>
      <td>да</td>
      <td>-----------------------ComboFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.BeginComboPreview`

#### Сигнатура

```lua
function imgui.BeginComboPreview()
  -> boolean
```

#### Возвращает

- `boolean` 

### Функция `imgui.BeginDisabled`

#### Сигнатура

```lua
function imgui.BeginDisabled(disabled?: boolean)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>disabled</code></td>
      <td><code>boolean</code></td>
      <td>нет</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.BeginDockableDragDropSource`

#### Сигнатура

```lua
function imgui.BeginDockableDragDropSource(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.BeginDockableDragDropTarget`

#### Сигнатура

```lua
function imgui.BeginDockableDragDropTarget(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.BeginDocked`

#### Сигнатура

```lua
function imgui.BeginDocked(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, p_open: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>p_open</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>bool*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.BeginDragDropSource`

#### Сигнатура

```lua
function imgui.BeginDragDropSource(flags?: DragDropFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>flags</code></td>
      <td><code>DragDropFlags</code></td>
      <td>нет</td>
      <td>-----------------------DragDropFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.BeginDragDropTarget`

#### Сигнатура

```lua
function imgui.BeginDragDropTarget()
  -> boolean
```

#### Возвращает

- `boolean` 

### Функция `imgui.BeginDragDropTargetCustom`

#### Сигнатура

```lua
function imgui.BeginDragDropTargetCustom(bb: ImRect, id: number)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>bb</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.BeginGroup`

#### Сигнатура

```lua
function imgui.BeginGroup()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.BeginItemTooltip`

#### Сигнатура

```lua
function imgui.BeginItemTooltip()
  -> boolean
```

#### Возвращает

- `boolean` 

### Функция `imgui.BeginListBox`

#### Сигнатура

```lua
function imgui.BeginListBox(label: string, size?: ImVec2)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>size</code></td>
      <td><code>ImVec2</code></td>
      <td>нет</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.BeginMainMenuBar`

#### Сигнатура

```lua
function imgui.BeginMainMenuBar()
  -> boolean
```

#### Возвращает

- `boolean` 

### Функция `imgui.BeginMenu`

#### Сигнатура

```lua
function imgui.BeginMenu(label: string, enabled?: boolean)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>enabled</code></td>
      <td><code>boolean</code></td>
      <td>нет</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.BeginMenuBar`

#### Сигнатура

```lua
function imgui.BeginMenuBar()
  -> boolean
```

#### Возвращает

- `boolean` 

### Функция `imgui.BeginMenuEx`

#### Сигнатура

```lua
function imgui.BeginMenuEx(label: string, icon: string, enabled?: boolean)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>icon</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>enabled</code></td>
      <td><code>boolean</code></td>
      <td>нет</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.BeginPopup`

#### Сигнатура

```lua
function imgui.BeginPopup(str_id: string, flags?: WindowFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>str_id</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>WindowFlags</code></td>
      <td>нет</td>
      <td>-----------------------WindowFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.BeginPopupContextItem`

#### Сигнатура

```lua
function imgui.BeginPopupContextItem(str_id?: string, popup_flags?: PopupFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>str_id</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>popup_flags</code></td>
      <td><code>PopupFlags</code></td>
      <td>нет</td>
      <td>-----------------------PopupFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.BeginPopupContextVoid`

#### Сигнатура

```lua
function imgui.BeginPopupContextVoid(str_id?: string, popup_flags?: PopupFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>str_id</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>popup_flags</code></td>
      <td><code>PopupFlags</code></td>
      <td>нет</td>
      <td>-----------------------PopupFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.BeginPopupContextWindow`

#### Сигнатура

```lua
function imgui.BeginPopupContextWindow(str_id?: string, popup_flags?: PopupFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>str_id</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>popup_flags</code></td>
      <td><code>PopupFlags</code></td>
      <td>нет</td>
      <td>-----------------------PopupFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.BeginPopupEx`

#### Сигнатура

```lua
function imgui.BeginPopupEx(id: number, extra_flags: WindowFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>extra_flags</code></td>
      <td><code>WindowFlags</code></td>
      <td>да</td>
      <td>-----------------------WindowFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.BeginPopupModal`

#### Сигнатура

```lua
function imgui.BeginPopupModal(name: string, p_open?: ffi.cdata*|ffi.cdecl*|ffi.ctype*, flags?: WindowFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>name</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>p_open</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>bool*</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>WindowFlags</code></td>
      <td>нет</td>
      <td>-----------------------WindowFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.BeginTabBar`

#### Сигнатура

```lua
function imgui.BeginTabBar(str_id: string, flags?: TabBarFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>str_id</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>TabBarFlags</code></td>
      <td>нет</td>
      <td>-----------------------TabBarFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.BeginTabBarEx`

#### Сигнатура

```lua
function imgui.BeginTabBarEx(tab_bar: ffi.cdata*|ffi.cdecl*|ffi.ctype*, bb: ImRect, flags: TabBarFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>tab_bar</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTabBar*</td>
    </tr>
    <tr>
      <td><code>bb</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>TabBarFlags</code></td>
      <td>да</td>
      <td>-----------------------TabBarFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.BeginTabItem`

#### Сигнатура

```lua
function imgui.BeginTabItem(label: string, p_open?: ffi.cdata*|ffi.cdecl*|ffi.ctype*, flags?: TabItemFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>p_open</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>bool*</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>TabItemFlags</code></td>
      <td>нет</td>
      <td>-----------------------TabItemFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.BeginTable`

#### Сигнатура

```lua
function imgui.BeginTable(str_id: string, column: number, flags?: TableFlags, outer_size?: ImVec2, inner_width?: number)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>str_id</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>column</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>TableFlags</code></td>
      <td>нет</td>
      <td>-----------------------TableFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>outer_size</code></td>
      <td><code>ImVec2</code></td>
      <td>нет</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>inner_width</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.BeginTableEx`

#### Сигнатура

```lua
function imgui.BeginTableEx(name: string, id: number, columns_count: number, flags?: TableFlags, outer_size?: ImVec2, inner_width?: number)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>name</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>columns_count</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>TableFlags</code></td>
      <td>нет</td>
      <td>-----------------------TableFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>outer_size</code></td>
      <td><code>ImVec2</code></td>
      <td>нет</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>inner_width</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.BeginTooltip`

#### Сигнатура

```lua
function imgui.BeginTooltip()
  -> boolean
```

#### Возвращает

- `boolean` 

### Функция `imgui.BeginTooltipEx`

#### Сигнатура

```lua
function imgui.BeginTooltipEx(tooltip_flags: TooltipFlags, extra_window_flags: WindowFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>tooltip_flags</code></td>
      <td><code>TooltipFlags</code></td>
      <td>да</td>
      <td>-----------------------TooltipFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>extra_window_flags</code></td>
      <td><code>WindowFlags</code></td>
      <td>да</td>
      <td>-----------------------WindowFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.BeginTooltipHidden`

#### Сигнатура

```lua
function imgui.BeginTooltipHidden()
  -> boolean
```

#### Возвращает

- `boolean` 

### Функция `imgui.BeginViewportSideBar`

#### Сигнатура

```lua
function imgui.BeginViewportSideBar(name: string, viewport: ffi.cdata*|ffi.cdecl*|ffi.ctype*, dir: Dir, size: number, window_flags: WindowFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>name</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>viewport</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiViewport*</td>
    </tr>
    <tr>
      <td><code>dir</code></td>
      <td><code>Dir</code></td>
      <td>да</td>
      <td>-----------------------Dir----------------------------</td>
    </tr>
    <tr>
      <td><code>size</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>window_flags</code></td>
      <td><code>WindowFlags</code></td>
      <td>да</td>
      <td>-----------------------WindowFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.BringWindowToDisplayBack`

#### Сигнатура

```lua
function imgui.BringWindowToDisplayBack(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.BringWindowToDisplayBehind`

#### Сигнатура

```lua
function imgui.BringWindowToDisplayBehind(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, above_window: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>above_window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.BringWindowToDisplayFront`

#### Сигнатура

```lua
function imgui.BringWindowToDisplayFront(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.BringWindowToFocusFront`

#### Сигнатура

```lua
function imgui.BringWindowToFocusFront(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.Bullet`

#### Сигнатура

```lua
function imgui.Bullet()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.BulletText`

#### Сигнатура

```lua
function imgui.BulletText(fmt: string, ...any)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>fmt</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>...</code></td>
      <td><code>unknown</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.BulletTextV`

#### Сигнатура

```lua
function imgui.BulletTextV(fmt: string, args: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>fmt</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>args</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>va_list</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.Button`

#### Сигнатура

```lua
function imgui.Button(label: string, size?: ImVec2)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>size</code></td>
      <td><code>ImVec2</code></td>
      <td>нет</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.ButtonBehavior`

#### Сигнатура

```lua
function imgui.ButtonBehavior(bb: ImRect, id: number, out_hovered: ffi.cdata*|ffi.cdecl*|ffi.ctype*, out_held: ffi.cdata*|ffi.cdecl*|ffi.ctype*, flags?: ButtonFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>bb</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>out_hovered</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>bool*</td>
    </tr>
    <tr>
      <td><code>out_held</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>bool*</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>ButtonFlags</code></td>
      <td>нет</td>
      <td>-----------------------ButtonFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.ButtonEx`

#### Сигнатура

```lua
function imgui.ButtonEx(label: string, size_arg?: ImVec2, flags?: ButtonFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>size_arg</code></td>
      <td><code>ImVec2</code></td>
      <td>нет</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>ButtonFlags</code></td>
      <td>нет</td>
      <td>-----------------------ButtonFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.CalcItemSize`

#### Сигнатура

```lua
function imgui.CalcItemSize(size: ImVec2, default_w: number, default_h: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>size</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>default_w</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>default_h</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.CalcItemWidth`

#### Сигнатура

```lua
function imgui.CalcItemWidth()
  -> float: number
```

#### Возвращает

- `number` 

### Функция `imgui.CalcRoundingFlagsForRectInRect`

#### Сигнатура

```lua
function imgui.CalcRoundingFlagsForRectInRect(r_in: ImRect, r_outer: ImRect, threshold: number)
  -> ImDrawFlags
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>r_in</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
    <tr>
      <td><code>r_outer</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
    <tr>
      <td><code>threshold</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ImDrawFlags` 

### Функция `imgui.CalcTextSize`

#### Сигнатура

```lua
function imgui.CalcTextSize(text: string, text_end?: string, hide_text_after_double_hash?: boolean, wrap_width?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>text</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>text_end</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>hide_text_after_double_hash</code></td>
      <td><code>boolean</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>wrap_width</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.CalcTypematicRepeatAmount`

#### Сигнатура

```lua
function imgui.CalcTypematicRepeatAmount(t0: number, t1: number, repeat_delay: number, repeat_rate: number)
  -> int: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>t0</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>t1</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>repeat_delay</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>repeat_rate</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.CalcWindowNextAutoFitSize`

#### Сигнатура

```lua
function imgui.CalcWindowNextAutoFitSize(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.CalcWrapWidthForPos`

#### Сигнатура

```lua
function imgui.CalcWrapWidthForPos(pos: ImVec2, wrap_pos_x: number)
  -> float: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>pos</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>wrap_pos_x</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.CallContextHooks`

#### Сигнатура

```lua
function imgui.CallContextHooks(context: ffi.cdata*|ffi.cdecl*|ffi.ctype*, type: ContextHookType)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>context</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiContext*</td>
    </tr>
    <tr>
      <td><code>type</code></td>
      <td><code>ContextHookType</code></td>
      <td>да</td>
      <td>-----------------------ContextHookType----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.Checkbox`

#### Сигнатура

```lua
function imgui.Checkbox(label: string, v: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>bool*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### ~~Функция `imgui.CheckboxFlags`~~

 generic version

#### Сигнатура

```lua
function imgui.CheckboxFlags(a1: any, a2: any, a3: any)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a3</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.CheckboxFlags_IntPtr`

#### Сигнатура

```lua
function imgui.CheckboxFlags_IntPtr(label: string, flags: ffi.cdata*|ffi.cdecl*|ffi.ctype*, flags_value: number)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>int*</td>
    </tr>
    <tr>
      <td><code>flags_value</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.CheckboxFlags_S64Ptr`

#### Сигнатура

```lua
function imgui.CheckboxFlags_S64Ptr(label: string, flags: ffi.cdata*|ffi.cdecl*|ffi.ctype*, flags_value: number)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImS64*</td>
    </tr>
    <tr>
      <td><code>flags_value</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImS64</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.CheckboxFlags_U64Ptr`

#### Сигнатура

```lua
function imgui.CheckboxFlags_U64Ptr(label: string, flags: ffi.cdata*|ffi.cdecl*|ffi.ctype*, flags_value: number)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImU64*</td>
    </tr>
    <tr>
      <td><code>flags_value</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU64</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.CheckboxFlags_UintPtr`

#### Сигнатура

```lua
function imgui.CheckboxFlags_UintPtr(label: string, flags: ffi.cdata*|ffi.cdecl*|ffi.ctype*, flags_value: number)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>unsigned int*</td>
    </tr>
    <tr>
      <td><code>flags_value</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>unsigned int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.ClearActiveID`

#### Сигнатура

```lua
function imgui.ClearActiveID()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.ClearDragDrop`

#### Сигнатура

```lua
function imgui.ClearDragDrop()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.ClearIniSettings`

#### Сигнатура

```lua
function imgui.ClearIniSettings()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.ClearWindowSettings`

#### Сигнатура

```lua
function imgui.ClearWindowSettings(name: string)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>name</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.CloseButton`

#### Сигнатура

```lua
function imgui.CloseButton(id: number, pos: ImVec2)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>pos</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.CloseCurrentPopup`

#### Сигнатура

```lua
function imgui.CloseCurrentPopup()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.ClosePopupToLevel`

#### Сигнатура

```lua
function imgui.ClosePopupToLevel(remaining: number, restore_focus_to_window_under_popup: boolean)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>remaining</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>restore_focus_to_window_under_popup</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ClosePopupsExceptModals`

#### Сигнатура

```lua
function imgui.ClosePopupsExceptModals()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.ClosePopupsOverWindow`

#### Сигнатура

```lua
function imgui.ClosePopupsOverWindow(ref_window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, restore_focus_to_window_under_popup: boolean)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ref_window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>restore_focus_to_window_under_popup</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.CollapseButton`

#### Сигнатура

```lua
function imgui.CollapseButton(id: number, pos: ImVec2, dock_node: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>pos</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>dock_node</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiDockNode*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### ~~Функция `imgui.CollapsingHeader`~~

 generic version

#### Сигнатура

```lua
function imgui.CollapsingHeader(a1: any, a2: any, a3: any)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a3</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.CollapsingHeader_BoolPtr`

#### Сигнатура

```lua
function imgui.CollapsingHeader_BoolPtr(label: string, p_visible: ffi.cdata*|ffi.cdecl*|ffi.ctype*, flags?: TreeNodeFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>p_visible</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>bool*</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>TreeNodeFlags</code></td>
      <td>нет</td>
      <td>-----------------------TreeNodeFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.CollapsingHeader_TreeNodeFlags`

#### Сигнатура

```lua
function imgui.CollapsingHeader_TreeNodeFlags(label: string, flags?: TreeNodeFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>TreeNodeFlags</code></td>
      <td>нет</td>
      <td>-----------------------TreeNodeFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.ColorButton`

#### Сигнатура

```lua
function imgui.ColorButton(desc_id: string, col: ffi.cdata*|ffi.cdecl*|ffi.ctype*, flags?: ColorEditFlags, size?: ImVec2)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>desc_id</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImVec4</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>ColorEditFlags</code></td>
      <td>нет</td>
      <td>-----------------------ColorEditFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>size</code></td>
      <td><code>ImVec2</code></td>
      <td>нет</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.ColorConvertFloat4ToU32`

#### Сигнатура

```lua
function imgui.ColorConvertFloat4ToU32(_in: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> ImU32: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>_in</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImVec4</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ColorConvertHSVtoRGB`

#### Сигнатура

```lua
function imgui.ColorConvertHSVtoRGB(h: number, s: number, v: number, out_r: ffi.cdata*|ffi.cdecl*|ffi.ctype*, out_g: ffi.cdata*|ffi.cdecl*|ffi.ctype*, out_b: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>h</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>s</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>out_r</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>float*</td>
    </tr>
    <tr>
      <td><code>out_g</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>float*</td>
    </tr>
    <tr>
      <td><code>out_b</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>float*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ColorConvertRGBtoHSV`

#### Сигнатура

```lua
function imgui.ColorConvertRGBtoHSV(r: number, g: number, b: number, out_h: ffi.cdata*|ffi.cdecl*|ffi.ctype*, out_s: ffi.cdata*|ffi.cdecl*|ffi.ctype*, out_v: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>r</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>g</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>b</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>out_h</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>float*</td>
    </tr>
    <tr>
      <td><code>out_s</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>float*</td>
    </tr>
    <tr>
      <td><code>out_v</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>float*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ColorConvertU32ToFloat4`

#### Сигнатура

```lua
function imgui.ColorConvertU32ToFloat4(_in: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>_in</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ColorEdit3`

#### Сигнатура

```lua
function imgui.ColorEdit3(label: string, col: ffi.cdata*|ffi.cdecl*|ffi.ctype*, flags?: ColorEditFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>float[3]</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>ColorEditFlags</code></td>
      <td>нет</td>
      <td>-----------------------ColorEditFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.ColorEdit4`

#### Сигнатура

```lua
function imgui.ColorEdit4(label: string, col: ffi.cdata*|ffi.cdecl*|ffi.ctype*, flags?: ColorEditFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>float[4]</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>ColorEditFlags</code></td>
      <td>нет</td>
      <td>-----------------------ColorEditFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.ColorEditOptionsPopup`

#### Сигнатура

```lua
function imgui.ColorEditOptionsPopup(col: ffi.cdata*|ffi.cdecl*|ffi.ctype*, flags: ColorEditFlags)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>col</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const float*</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>ColorEditFlags</code></td>
      <td>да</td>
      <td>-----------------------ColorEditFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ColorPicker3`

#### Сигнатура

```lua
function imgui.ColorPicker3(label: string, col: ffi.cdata*|ffi.cdecl*|ffi.ctype*, flags?: ColorEditFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>float[3]</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>ColorEditFlags</code></td>
      <td>нет</td>
      <td>-----------------------ColorEditFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.ColorPicker4`

#### Сигнатура

```lua
function imgui.ColorPicker4(label: string, col: ffi.cdata*|ffi.cdecl*|ffi.ctype*, flags?: ColorEditFlags, ref_col?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>float[4]</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>ColorEditFlags</code></td>
      <td>нет</td>
      <td>-----------------------ColorEditFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>ref_col</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>const float*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.ColorPickerOptionsPopup`

#### Сигнатура

```lua
function imgui.ColorPickerOptionsPopup(ref_col: ffi.cdata*|ffi.cdecl*|ffi.ctype*, flags: ColorEditFlags)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ref_col</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const float*</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>ColorEditFlags</code></td>
      <td>да</td>
      <td>-----------------------ColorEditFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ColorTooltip`

#### Сигнатура

```lua
function imgui.ColorTooltip(text: string, col: ffi.cdata*|ffi.cdecl*|ffi.ctype*, flags: ColorEditFlags)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>text</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const float*</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>ColorEditFlags</code></td>
      <td>да</td>
      <td>-----------------------ColorEditFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.Columns`

#### Сигнатура

```lua
function imgui.Columns(count?: number, id?: string, border?: boolean)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>count</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>id</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>border</code></td>
      <td><code>boolean</code></td>
      <td>нет</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### ~~Функция `imgui.Combo`~~

 generic version

#### Сигнатура

```lua
function imgui.Combo(a1: any, a2: any, a3: any, a4: any, a5: any, a6: any)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a3</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a4</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a5</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a6</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.Combo_FnStrPtr`

#### Сигнатура

```lua
function imgui.Combo_FnStrPtr(label: string, current_item: ffi.cdata*|ffi.cdecl*|ffi.ctype*, getter: ffi.cdata*|ffi.cdecl*|ffi.ctype*, user_data: ffi.cdata*|ffi.cdecl*|ffi.ctype*, items_count: number, popup_max_height_in_items?: number)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>current_item</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>int*</td>
    </tr>
    <tr>
      <td><code>getter</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const char*(*)(void* user_data,int idx)</td>
    </tr>
    <tr>
      <td><code>user_data</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>void*</td>
    </tr>
    <tr>
      <td><code>items_count</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>popup_max_height_in_items</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.Combo_Str`

#### Сигнатура

```lua
function imgui.Combo_Str(label: string, current_item: ffi.cdata*|ffi.cdecl*|ffi.ctype*, items_separated_by_zeros: string, popup_max_height_in_items?: number)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>current_item</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>int*</td>
    </tr>
    <tr>
      <td><code>items_separated_by_zeros</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>popup_max_height_in_items</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.Combo_Str_arr`

#### Сигнатура

```lua
function imgui.Combo_Str_arr(label: string, current_item: ffi.cdata*|ffi.cdecl*|ffi.ctype*, items: ffi.cdata*|ffi.cdecl*|ffi.ctype*, items_count: number, popup_max_height_in_items?: number)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>current_item</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>int*</td>
    </tr>
    <tr>
      <td><code>items</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const char* const[]</td>
    </tr>
    <tr>
      <td><code>items_count</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>popup_max_height_in_items</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.ConvertSingleModFlagToKey`

#### Сигнатура

```lua
function imgui.ConvertSingleModFlagToKey(ctx: ffi.cdata*|ffi.cdecl*|ffi.ctype*, key: Key)
  -> Key
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctx</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiContext*</td>
    </tr>
    <tr>
      <td><code>key</code></td>
      <td><code>Key</code></td>
      <td>да</td>
      <td>-----------------------Key----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `Key` 

### Функция `imgui.CreateContext`

#### Сигнатура

```lua
function imgui.CreateContext(shared_font_atlas?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> ImGuiContext*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>shared_font_atlas</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>ImFontAtlas*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.CreateNewWindowSettings`

#### Сигнатура

```lua
function imgui.CreateNewWindowSettings(name: string)
  -> ImGuiWindowSettings*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>name</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.DataTypeApplyFromText`

#### Сигнатура

```lua
function imgui.DataTypeApplyFromText(buf: string, data_type: DataType, p_data: ffi.cdata*|ffi.cdecl*|ffi.ctype*, format: string)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>buf</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>data_type</code></td>
      <td><code>DataType</code></td>
      <td>да</td>
      <td>-----------------------DataType----------------------------</td>
    </tr>
    <tr>
      <td><code>p_data</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>void*</td>
    </tr>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.DataTypeApplyOp`

#### Сигнатура

```lua
function imgui.DataTypeApplyOp(data_type: DataType, op: number, output: ffi.cdata*|ffi.cdecl*|ffi.ctype*, arg_1: ffi.cdata*|ffi.cdecl*|ffi.ctype*, arg_2: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>data_type</code></td>
      <td><code>DataType</code></td>
      <td>да</td>
      <td>-----------------------DataType----------------------------</td>
    </tr>
    <tr>
      <td><code>op</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>output</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>void*</td>
    </tr>
    <tr>
      <td><code>arg_1</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const void*</td>
    </tr>
    <tr>
      <td><code>arg_2</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const void*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DataTypeClamp`

#### Сигнатура

```lua
function imgui.DataTypeClamp(data_type: DataType, p_data: ffi.cdata*|ffi.cdecl*|ffi.ctype*, p_min: ffi.cdata*|ffi.cdecl*|ffi.ctype*, p_max: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>data_type</code></td>
      <td><code>DataType</code></td>
      <td>да</td>
      <td>-----------------------DataType----------------------------</td>
    </tr>
    <tr>
      <td><code>p_data</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>void*</td>
    </tr>
    <tr>
      <td><code>p_min</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const void*</td>
    </tr>
    <tr>
      <td><code>p_max</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const void*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.DataTypeCompare`

#### Сигнатура

```lua
function imgui.DataTypeCompare(data_type: DataType, arg_1: ffi.cdata*|ffi.cdecl*|ffi.ctype*, arg_2: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> int: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>data_type</code></td>
      <td><code>DataType</code></td>
      <td>да</td>
      <td>-----------------------DataType----------------------------</td>
    </tr>
    <tr>
      <td><code>arg_1</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const void*</td>
    </tr>
    <tr>
      <td><code>arg_2</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const void*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.DataTypeFormatString`

#### Сигнатура

```lua
function imgui.DataTypeFormatString(buf: ffi.cdata*|ffi.cdecl*|ffi.ctype*, buf_size: number, data_type: DataType, p_data: ffi.cdata*|ffi.cdecl*|ffi.ctype*, format: string)
  -> int: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>buf</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>char*</td>
    </tr>
    <tr>
      <td><code>buf_size</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>data_type</code></td>
      <td><code>DataType</code></td>
      <td>да</td>
      <td>-----------------------DataType----------------------------</td>
    </tr>
    <tr>
      <td><code>p_data</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const void*</td>
    </tr>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.DataTypeGetInfo`

#### Сигнатура

```lua
function imgui.DataTypeGetInfo(data_type: DataType)
  -> const: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>data_type</code></td>
      <td><code>DataType</code></td>
      <td>да</td>
      <td>-----------------------DataType----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.DebugAllocHook`

#### Сигнатура

```lua
function imgui.DebugAllocHook(info: ffi.cdata*|ffi.cdecl*|ffi.ctype*, frame_count: number, ptr: ffi.cdata*|ffi.cdecl*|ffi.ctype*, size: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>info</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiDebugAllocInfo*</td>
    </tr>
    <tr>
      <td><code>frame_count</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>ptr</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>void*</td>
    </tr>
    <tr>
      <td><code>size</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>size_t</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DebugBreakButton`

#### Сигнатура

```lua
function imgui.DebugBreakButton(label: string, description_of_location: string)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>description_of_location</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.DebugBreakButtonTooltip`

#### Сигнатура

```lua
function imgui.DebugBreakButtonTooltip(keyboard_only: boolean, description_of_location: string)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>keyboard_only</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>description_of_location</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DebugBreakClearData`

#### Сигнатура

```lua
function imgui.DebugBreakClearData()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.DebugCheckVersionAndDataLayout`

#### Сигнатура

```lua
function imgui.DebugCheckVersionAndDataLayout(version_str: string, sz_io: number, sz_style: number, sz_vec2: number, sz_vec4: number, sz_drawvert: number, sz_drawidx: number)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>version_str</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>sz_io</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>size_t</td>
    </tr>
    <tr>
      <td><code>sz_style</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>size_t</td>
    </tr>
    <tr>
      <td><code>sz_vec2</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>size_t</td>
    </tr>
    <tr>
      <td><code>sz_vec4</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>size_t</td>
    </tr>
    <tr>
      <td><code>sz_drawvert</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>size_t</td>
    </tr>
    <tr>
      <td><code>sz_drawidx</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>size_t</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.DebugDrawCursorPos`

#### Сигнатура

```lua
function imgui.DebugDrawCursorPos(col?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>ImU32</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DebugDrawItemRect`

#### Сигнатура

```lua
function imgui.DebugDrawItemRect(col?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>ImU32</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DebugDrawLineExtents`

#### Сигнатура

```lua
function imgui.DebugDrawLineExtents(col?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>ImU32</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DebugFlashStyleColor`

#### Сигнатура

```lua
function imgui.DebugFlashStyleColor(idx: Col)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>idx</code></td>
      <td><code>Col</code></td>
      <td>да</td>
      <td>-----------------------Col----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DebugHookIdInfo`

#### Сигнатура

```lua
function imgui.DebugHookIdInfo(id: number, data_type: DataType, data_id: ffi.cdata*|ffi.cdecl*|ffi.ctype*, data_id_end: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>data_type</code></td>
      <td><code>DataType</code></td>
      <td>да</td>
      <td>-----------------------DataType----------------------------</td>
    </tr>
    <tr>
      <td><code>data_id</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const void*</td>
    </tr>
    <tr>
      <td><code>data_id_end</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const void*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DebugLocateItem`

#### Сигнатура

```lua
function imgui.DebugLocateItem(target_id: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>target_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DebugLocateItemOnHover`

#### Сигнатура

```lua
function imgui.DebugLocateItemOnHover(target_id: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>target_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DebugLocateItemResolveWithLastItem`

#### Сигнатура

```lua
function imgui.DebugLocateItemResolveWithLastItem()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.DebugLog`

#### Сигнатура

```lua
function imgui.DebugLog(fmt: string, ...any)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>fmt</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>...</code></td>
      <td><code>unknown</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DebugLogV`

#### Сигнатура

```lua
function imgui.DebugLogV(fmt: string, args: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>fmt</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>args</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>va_list</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DebugNodeColumns`

#### Сигнатура

```lua
function imgui.DebugNodeColumns(columns: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>columns</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiOldColumns*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DebugNodeDockNode`

#### Сигнатура

```lua
function imgui.DebugNodeDockNode(node: ffi.cdata*|ffi.cdecl*|ffi.ctype*, label: string)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>node</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiDockNode*</td>
    </tr>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DebugNodeDrawCmdShowMeshAndBoundingBox`

#### Сигнатура

```lua
function imgui.DebugNodeDrawCmdShowMeshAndBoundingBox(out_draw_list: ffi.cdata*|ffi.cdecl*|ffi.ctype*, draw_list: ffi.cdata*|ffi.cdecl*|ffi.ctype*, draw_cmd: ffi.cdata*|ffi.cdecl*|ffi.ctype*, show_mesh: boolean, show_aabb: boolean)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>out_draw_list</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImDrawList*</td>
    </tr>
    <tr>
      <td><code>draw_list</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImDrawList*</td>
    </tr>
    <tr>
      <td><code>draw_cmd</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImDrawCmd*</td>
    </tr>
    <tr>
      <td><code>show_mesh</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>show_aabb</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DebugNodeDrawList`

#### Сигнатура

```lua
function imgui.DebugNodeDrawList(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, viewport: ffi.cdata*|ffi.cdecl*|ffi.ctype*, draw_list: ffi.cdata*|ffi.cdecl*|ffi.ctype*, label: string)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>viewport</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiViewportP*</td>
    </tr>
    <tr>
      <td><code>draw_list</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImDrawList*</td>
    </tr>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DebugNodeFont`

#### Сигнатура

```lua
function imgui.DebugNodeFont(font: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>font</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImFont*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DebugNodeFontGlyph`

#### Сигнатура

```lua
function imgui.DebugNodeFontGlyph(font: ffi.cdata*|ffi.cdecl*|ffi.ctype*, glyph: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>font</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImFont*</td>
    </tr>
    <tr>
      <td><code>glyph</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImFontGlyph*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DebugNodeInputTextState`

#### Сигнатура

```lua
function imgui.DebugNodeInputTextState(state: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>state</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiInputTextState*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DebugNodeStorage`

#### Сигнатура

```lua
function imgui.DebugNodeStorage(storage: ffi.cdata*|ffi.cdecl*|ffi.ctype*, label: string)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>storage</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiStorage*</td>
    </tr>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DebugNodeTabBar`

#### Сигнатура

```lua
function imgui.DebugNodeTabBar(tab_bar: ffi.cdata*|ffi.cdecl*|ffi.ctype*, label: string)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>tab_bar</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTabBar*</td>
    </tr>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DebugNodeTable`

#### Сигнатура

```lua
function imgui.DebugNodeTable(table: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>table</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTable*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DebugNodeTableSettings`

#### Сигнатура

```lua
function imgui.DebugNodeTableSettings(settings: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>settings</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTableSettings*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DebugNodeTypingSelectState`

#### Сигнатура

```lua
function imgui.DebugNodeTypingSelectState(state: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>state</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTypingSelectState*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DebugNodeViewport`

#### Сигнатура

```lua
function imgui.DebugNodeViewport(viewport: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>viewport</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiViewportP*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DebugNodeWindow`

#### Сигнатура

```lua
function imgui.DebugNodeWindow(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, label: string)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DebugNodeWindowSettings`

#### Сигнатура

```lua
function imgui.DebugNodeWindowSettings(settings: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>settings</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindowSettings*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DebugNodeWindowsList`

#### Сигнатура

```lua
function imgui.DebugNodeWindowsList(windows: ffi.cdata*|ffi.cdecl*|ffi.ctype*, label: string)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>windows</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImVector_ImGuiWindowPtr*</td>
    </tr>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DebugNodeWindowsListByBeginStackParent`

#### Сигнатура

```lua
function imgui.DebugNodeWindowsListByBeginStackParent(windows: ffi.cdata*|ffi.cdecl*|ffi.ctype*, windows_size: number, parent_in_begin_stack: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>windows</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow**</td>
    </tr>
    <tr>
      <td><code>windows_size</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>parent_in_begin_stack</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DebugRenderKeyboardPreview`

#### Сигнатура

```lua
function imgui.DebugRenderKeyboardPreview(draw_list: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>draw_list</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImDrawList*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DebugRenderViewportThumbnail`

#### Сигнатура

```lua
function imgui.DebugRenderViewportThumbnail(draw_list: ffi.cdata*|ffi.cdecl*|ffi.ctype*, viewport: ffi.cdata*|ffi.cdecl*|ffi.ctype*, bb: ImRect)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>draw_list</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImDrawList*</td>
    </tr>
    <tr>
      <td><code>viewport</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiViewportP*</td>
    </tr>
    <tr>
      <td><code>bb</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DebugStartItemPicker`

#### Сигнатура

```lua
function imgui.DebugStartItemPicker()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.DebugTextEncoding`

#### Сигнатура

```lua
function imgui.DebugTextEncoding(text: string)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>text</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DestroyContext`

#### Сигнатура

```lua
function imgui.DestroyContext(ctx?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctx</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>ImGuiContext*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DestroyPlatformWindow`

#### Сигнатура

```lua
function imgui.DestroyPlatformWindow(viewport: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>viewport</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiViewportP*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DestroyPlatformWindows`

#### Сигнатура

```lua
function imgui.DestroyPlatformWindows()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.DockBuilderAddNode`

#### Сигнатура

```lua
function imgui.DockBuilderAddNode(node_id?: number, flags?: DockNodeFlags)
  -> ImGuiID: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>node_id</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>DockNodeFlags</code></td>
      <td>нет</td>
      <td>-----------------------DockNodeFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.DockBuilderCopyDockSpace`

#### Сигнатура

```lua
function imgui.DockBuilderCopyDockSpace(src_dockspace_id: number, dst_dockspace_id: number, in_window_remap_pairs: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>src_dockspace_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>dst_dockspace_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>in_window_remap_pairs</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImVector_const_charPtr*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DockBuilderCopyNode`

#### Сигнатура

```lua
function imgui.DockBuilderCopyNode(src_node_id: number, dst_node_id: number, out_node_remap_pairs: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>src_node_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>dst_node_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>out_node_remap_pairs</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImVector_ImGuiID*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DockBuilderCopyWindowSettings`

#### Сигнатура

```lua
function imgui.DockBuilderCopyWindowSettings(src_name: string, dst_name: string)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>src_name</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>dst_name</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DockBuilderDockWindow`

#### Сигнатура

```lua
function imgui.DockBuilderDockWindow(window_name: string, node_id: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window_name</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>node_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DockBuilderFinish`

#### Сигнатура

```lua
function imgui.DockBuilderFinish(node_id: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>node_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DockBuilderGetCentralNode`

#### Сигнатура

```lua
function imgui.DockBuilderGetCentralNode(node_id: number)
  -> ImGuiDockNode*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>node_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.DockBuilderGetNode`

#### Сигнатура

```lua
function imgui.DockBuilderGetNode(node_id: number)
  -> ImGuiDockNode*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>node_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.DockBuilderRemoveNode`

#### Сигнатура

```lua
function imgui.DockBuilderRemoveNode(node_id: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>node_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DockBuilderRemoveNodeChildNodes`

#### Сигнатура

```lua
function imgui.DockBuilderRemoveNodeChildNodes(node_id: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>node_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DockBuilderRemoveNodeDockedWindows`

#### Сигнатура

```lua
function imgui.DockBuilderRemoveNodeDockedWindows(node_id: number, clear_settings_refs?: boolean)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>node_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>clear_settings_refs</code></td>
      <td><code>boolean</code></td>
      <td>нет</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DockBuilderSetNodePos`

#### Сигнатура

```lua
function imgui.DockBuilderSetNodePos(node_id: number, pos: ImVec2)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>node_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>pos</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DockBuilderSetNodeSize`

#### Сигнатура

```lua
function imgui.DockBuilderSetNodeSize(node_id: number, size: ImVec2)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>node_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>size</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DockBuilderSplitNode`

#### Сигнатура

```lua
function imgui.DockBuilderSplitNode(node_id: number, split_dir: Dir, size_ratio_for_node_at_dir: number, out_id_at_dir: ffi.cdata*|ffi.cdecl*|ffi.ctype*, out_id_at_opposite_dir: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> ImGuiID: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>node_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>split_dir</code></td>
      <td><code>Dir</code></td>
      <td>да</td>
      <td>-----------------------Dir----------------------------</td>
    </tr>
    <tr>
      <td><code>size_ratio_for_node_at_dir</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>out_id_at_dir</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiID*</td>
    </tr>
    <tr>
      <td><code>out_id_at_opposite_dir</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiID*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.DockContextCalcDropPosForDocking`

#### Сигнатура

```lua
function imgui.DockContextCalcDropPosForDocking(target: ffi.cdata*|ffi.cdecl*|ffi.ctype*, target_node: ffi.cdata*|ffi.cdecl*|ffi.ctype*, payload_window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, payload_node: ffi.cdata*|ffi.cdecl*|ffi.ctype*, split_dir: Dir, split_outer: boolean, out_pos: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>target</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>target_node</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiDockNode*</td>
    </tr>
    <tr>
      <td><code>payload_window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>payload_node</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiDockNode*</td>
    </tr>
    <tr>
      <td><code>split_dir</code></td>
      <td><code>Dir</code></td>
      <td>да</td>
      <td>-----------------------Dir----------------------------</td>
    </tr>
    <tr>
      <td><code>split_outer</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>out_pos</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImVec2*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.DockContextClearNodes`

#### Сигнатура

```lua
function imgui.DockContextClearNodes(ctx: ffi.cdata*|ffi.cdecl*|ffi.ctype*, root_id: number, clear_settings_refs: boolean)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctx</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiContext*</td>
    </tr>
    <tr>
      <td><code>root_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>clear_settings_refs</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DockContextEndFrame`

#### Сигнатура

```lua
function imgui.DockContextEndFrame(ctx: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctx</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiContext*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DockContextFindNodeByID`

#### Сигнатура

```lua
function imgui.DockContextFindNodeByID(ctx: ffi.cdata*|ffi.cdecl*|ffi.ctype*, id: number)
  -> ImGuiDockNode*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctx</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiContext*</td>
    </tr>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.DockContextGenNodeID`

#### Сигнатура

```lua
function imgui.DockContextGenNodeID(ctx: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> ImGuiID: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctx</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiContext*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.DockContextInitialize`

#### Сигнатура

```lua
function imgui.DockContextInitialize(ctx: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctx</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiContext*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DockContextNewFrameUpdateDocking`

#### Сигнатура

```lua
function imgui.DockContextNewFrameUpdateDocking(ctx: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctx</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiContext*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DockContextNewFrameUpdateUndocking`

#### Сигнатура

```lua
function imgui.DockContextNewFrameUpdateUndocking(ctx: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctx</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiContext*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DockContextProcessUndockNode`

#### Сигнатура

```lua
function imgui.DockContextProcessUndockNode(ctx: ffi.cdata*|ffi.cdecl*|ffi.ctype*, node: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctx</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiContext*</td>
    </tr>
    <tr>
      <td><code>node</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiDockNode*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DockContextProcessUndockWindow`

#### Сигнатура

```lua
function imgui.DockContextProcessUndockWindow(ctx: ffi.cdata*|ffi.cdecl*|ffi.ctype*, window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, clear_persistent_docking_ref?: boolean)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctx</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiContext*</td>
    </tr>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>clear_persistent_docking_ref</code></td>
      <td><code>boolean</code></td>
      <td>нет</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DockContextQueueDock`

#### Сигнатура

```lua
function imgui.DockContextQueueDock(ctx: ffi.cdata*|ffi.cdecl*|ffi.ctype*, target: ffi.cdata*|ffi.cdecl*|ffi.ctype*, target_node: ffi.cdata*|ffi.cdecl*|ffi.ctype*, payload: ffi.cdata*|ffi.cdecl*|ffi.ctype*, split_dir: Dir, split_ratio: number, split_outer: boolean)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctx</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiContext*</td>
    </tr>
    <tr>
      <td><code>target</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>target_node</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiDockNode*</td>
    </tr>
    <tr>
      <td><code>payload</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>split_dir</code></td>
      <td><code>Dir</code></td>
      <td>да</td>
      <td>-----------------------Dir----------------------------</td>
    </tr>
    <tr>
      <td><code>split_ratio</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>split_outer</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DockContextQueueUndockNode`

#### Сигнатура

```lua
function imgui.DockContextQueueUndockNode(ctx: ffi.cdata*|ffi.cdecl*|ffi.ctype*, node: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctx</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiContext*</td>
    </tr>
    <tr>
      <td><code>node</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiDockNode*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DockContextQueueUndockWindow`

#### Сигнатура

```lua
function imgui.DockContextQueueUndockWindow(ctx: ffi.cdata*|ffi.cdecl*|ffi.ctype*, window: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctx</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiContext*</td>
    </tr>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DockContextRebuildNodes`

#### Сигнатура

```lua
function imgui.DockContextRebuildNodes(ctx: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctx</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiContext*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DockContextShutdown`

#### Сигнатура

```lua
function imgui.DockContextShutdown(ctx: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctx</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiContext*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DockNodeBeginAmendTabBar`

#### Сигнатура

```lua
function imgui.DockNodeBeginAmendTabBar(node: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>node</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiDockNode*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.DockNodeEndAmendTabBar`

#### Сигнатура

```lua
function imgui.DockNodeEndAmendTabBar()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.DockNodeGetDepth`

#### Сигнатура

```lua
function imgui.DockNodeGetDepth(node: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> int: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>node</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImGuiDockNode*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.DockNodeGetRootNode`

#### Сигнатура

```lua
function imgui.DockNodeGetRootNode(node: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> ImGuiDockNode*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>node</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiDockNode*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.DockNodeGetWindowMenuButtonId`

#### Сигнатура

```lua
function imgui.DockNodeGetWindowMenuButtonId(node: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> ImGuiID: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>node</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImGuiDockNode*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.DockNodeIsInHierarchyOf`

#### Сигнатура

```lua
function imgui.DockNodeIsInHierarchyOf(node: ffi.cdata*|ffi.cdecl*|ffi.ctype*, parent: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>node</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiDockNode*</td>
    </tr>
    <tr>
      <td><code>parent</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiDockNode*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.DockNodeWindowMenuHandler_Default`

#### Сигнатура

```lua
function imgui.DockNodeWindowMenuHandler_Default(ctx: ffi.cdata*|ffi.cdecl*|ffi.ctype*, node: ffi.cdata*|ffi.cdecl*|ffi.ctype*, tab_bar: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctx</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiContext*</td>
    </tr>
    <tr>
      <td><code>node</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiDockNode*</td>
    </tr>
    <tr>
      <td><code>tab_bar</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTabBar*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.DockSpace`

#### Сигнатура

```lua
function imgui.DockSpace(id: number, size?: ImVec2, flags?: DockNodeFlags, window_class?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> ImGuiID: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>size</code></td>
      <td><code>ImVec2</code></td>
      <td>нет</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>DockNodeFlags</code></td>
      <td>нет</td>
      <td>-----------------------DockNodeFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>window_class</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>const ImGuiWindowClass*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.DockSpaceOverViewport`

#### Сигнатура

```lua
function imgui.DockSpaceOverViewport(viewport?: ffi.cdata*|ffi.cdecl*|ffi.ctype*, flags?: DockNodeFlags, window_class?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> ImGuiID: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>viewport</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>const ImGuiViewport*</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>DockNodeFlags</code></td>
      <td>нет</td>
      <td>-----------------------DockNodeFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>window_class</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>const ImGuiWindowClass*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.DragBehavior`

#### Сигнатура

```lua
function imgui.DragBehavior(id: number, data_type: DataType, p_v: ffi.cdata*|ffi.cdecl*|ffi.ctype*, v_speed: number, p_min: ffi.cdata*|ffi.cdecl*|ffi.ctype*, p_max: ffi.cdata*|ffi.cdecl*|ffi.ctype*, format: string, flags: SliderFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>data_type</code></td>
      <td><code>DataType</code></td>
      <td>да</td>
      <td>-----------------------DataType----------------------------</td>
    </tr>
    <tr>
      <td><code>p_v</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>void*</td>
    </tr>
    <tr>
      <td><code>v_speed</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>p_min</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const void*</td>
    </tr>
    <tr>
      <td><code>p_max</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const void*</td>
    </tr>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>SliderFlags</code></td>
      <td>да</td>
      <td>-----------------------SliderFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.DragFloat`

#### Сигнатура

```lua
function imgui.DragFloat(label: string, v: ffi.cdata*|ffi.cdecl*|ffi.ctype*, v_speed?: number, v_min?: number, v_max?: number, format?: string, flags?: SliderFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>float*</td>
    </tr>
    <tr>
      <td><code>v_speed</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>v_min</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>v_max</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>SliderFlags</code></td>
      <td>нет</td>
      <td>-----------------------SliderFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.DragFloat2`

#### Сигнатура

```lua
function imgui.DragFloat2(label: string, v: ffi.cdata*|ffi.cdecl*|ffi.ctype*, v_speed?: number, v_min?: number, v_max?: number, format?: string, flags?: SliderFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>float[2]</td>
    </tr>
    <tr>
      <td><code>v_speed</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>v_min</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>v_max</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>SliderFlags</code></td>
      <td>нет</td>
      <td>-----------------------SliderFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.DragFloat3`

#### Сигнатура

```lua
function imgui.DragFloat3(label: string, v: ffi.cdata*|ffi.cdecl*|ffi.ctype*, v_speed?: number, v_min?: number, v_max?: number, format?: string, flags?: SliderFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>float[3]</td>
    </tr>
    <tr>
      <td><code>v_speed</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>v_min</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>v_max</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>SliderFlags</code></td>
      <td>нет</td>
      <td>-----------------------SliderFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.DragFloat4`

#### Сигнатура

```lua
function imgui.DragFloat4(label: string, v: ffi.cdata*|ffi.cdecl*|ffi.ctype*, v_speed?: number, v_min?: number, v_max?: number, format?: string, flags?: SliderFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>float[4]</td>
    </tr>
    <tr>
      <td><code>v_speed</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>v_min</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>v_max</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>SliderFlags</code></td>
      <td>нет</td>
      <td>-----------------------SliderFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.DragFloatRange2`

#### Сигнатура

```lua
function imgui.DragFloatRange2(label: string, v_current_min: ffi.cdata*|ffi.cdecl*|ffi.ctype*, v_current_max: ffi.cdata*|ffi.cdecl*|ffi.ctype*, v_speed?: number, v_min?: number, v_max?: number, format?: string, format_max?: string, flags?: SliderFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>v_current_min</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>float*</td>
    </tr>
    <tr>
      <td><code>v_current_max</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>float*</td>
    </tr>
    <tr>
      <td><code>v_speed</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>v_min</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>v_max</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>format_max</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>SliderFlags</code></td>
      <td>нет</td>
      <td>-----------------------SliderFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.DragInt`

#### Сигнатура

```lua
function imgui.DragInt(label: string, v: ffi.cdata*|ffi.cdecl*|ffi.ctype*, v_speed?: number, v_min?: number, v_max?: number, format?: string, flags?: SliderFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>int*</td>
    </tr>
    <tr>
      <td><code>v_speed</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>v_min</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>v_max</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>SliderFlags</code></td>
      <td>нет</td>
      <td>-----------------------SliderFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.DragInt2`

#### Сигнатура

```lua
function imgui.DragInt2(label: string, v: ffi.cdata*|ffi.cdecl*|ffi.ctype*, v_speed?: number, v_min?: number, v_max?: number, format?: string, flags?: SliderFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>int[2]</td>
    </tr>
    <tr>
      <td><code>v_speed</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>v_min</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>v_max</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>SliderFlags</code></td>
      <td>нет</td>
      <td>-----------------------SliderFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.DragInt3`

#### Сигнатура

```lua
function imgui.DragInt3(label: string, v: ffi.cdata*|ffi.cdecl*|ffi.ctype*, v_speed?: number, v_min?: number, v_max?: number, format?: string, flags?: SliderFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>int[3]</td>
    </tr>
    <tr>
      <td><code>v_speed</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>v_min</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>v_max</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>SliderFlags</code></td>
      <td>нет</td>
      <td>-----------------------SliderFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.DragInt4`

#### Сигнатура

```lua
function imgui.DragInt4(label: string, v: ffi.cdata*|ffi.cdecl*|ffi.ctype*, v_speed?: number, v_min?: number, v_max?: number, format?: string, flags?: SliderFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>int[4]</td>
    </tr>
    <tr>
      <td><code>v_speed</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>v_min</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>v_max</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>SliderFlags</code></td>
      <td>нет</td>
      <td>-----------------------SliderFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.DragIntRange2`

#### Сигнатура

```lua
function imgui.DragIntRange2(label: string, v_current_min: ffi.cdata*|ffi.cdecl*|ffi.ctype*, v_current_max: ffi.cdata*|ffi.cdecl*|ffi.ctype*, v_speed?: number, v_min?: number, v_max?: number, format?: string, format_max?: string, flags?: SliderFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>v_current_min</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>int*</td>
    </tr>
    <tr>
      <td><code>v_current_max</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>int*</td>
    </tr>
    <tr>
      <td><code>v_speed</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>v_min</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>v_max</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>format_max</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>SliderFlags</code></td>
      <td>нет</td>
      <td>-----------------------SliderFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.DragScalar`

#### Сигнатура

```lua
function imgui.DragScalar(label: string, data_type: DataType, p_data: ffi.cdata*|ffi.cdecl*|ffi.ctype*, v_speed?: number, p_min?: ffi.cdata*|ffi.cdecl*|ffi.ctype*, p_max?: ffi.cdata*|ffi.cdecl*|ffi.ctype*, format?: string, flags?: SliderFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>data_type</code></td>
      <td><code>DataType</code></td>
      <td>да</td>
      <td>-----------------------DataType----------------------------</td>
    </tr>
    <tr>
      <td><code>p_data</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>void*</td>
    </tr>
    <tr>
      <td><code>v_speed</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>p_min</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>const void*</td>
    </tr>
    <tr>
      <td><code>p_max</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>const void*</td>
    </tr>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>SliderFlags</code></td>
      <td>нет</td>
      <td>-----------------------SliderFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.DragScalarN`

#### Сигнатура

```lua
function imgui.DragScalarN(label: string, data_type: DataType, p_data: ffi.cdata*|ffi.cdecl*|ffi.ctype*, components: number, v_speed?: number, p_min?: ffi.cdata*|ffi.cdecl*|ffi.ctype*, p_max?: ffi.cdata*|ffi.cdecl*|ffi.ctype*, format?: string, flags?: SliderFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>data_type</code></td>
      <td><code>DataType</code></td>
      <td>да</td>
      <td>-----------------------DataType----------------------------</td>
    </tr>
    <tr>
      <td><code>p_data</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>void*</td>
    </tr>
    <tr>
      <td><code>components</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>v_speed</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>p_min</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>const void*</td>
    </tr>
    <tr>
      <td><code>p_max</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>const void*</td>
    </tr>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>SliderFlags</code></td>
      <td>нет</td>
      <td>-----------------------SliderFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.Dummy`

#### Сигнатура

```lua
function imgui.Dummy(size: ImVec2)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>size</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.End`

#### Сигнатура

```lua
function imgui.End()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.EndChild`

#### Сигнатура

```lua
function imgui.EndChild()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.EndColumns`

#### Сигнатура

```lua
function imgui.EndColumns()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.EndCombo`

#### Сигнатура

```lua
function imgui.EndCombo()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.EndComboPreview`

#### Сигнатура

```lua
function imgui.EndComboPreview()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.EndDisabled`

#### Сигнатура

```lua
function imgui.EndDisabled()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.EndDragDropSource`

#### Сигнатура

```lua
function imgui.EndDragDropSource()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.EndDragDropTarget`

#### Сигнатура

```lua
function imgui.EndDragDropTarget()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.EndFrame`

#### Сигнатура

```lua
function imgui.EndFrame()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.EndGroup`

#### Сигнатура

```lua
function imgui.EndGroup()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.EndListBox`

#### Сигнатура

```lua
function imgui.EndListBox()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.EndMainMenuBar`

#### Сигнатура

```lua
function imgui.EndMainMenuBar()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.EndMenu`

#### Сигнатура

```lua
function imgui.EndMenu()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.EndMenuBar`

#### Сигнатура

```lua
function imgui.EndMenuBar()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.EndPopup`

#### Сигнатура

```lua
function imgui.EndPopup()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.EndTabBar`

#### Сигнатура

```lua
function imgui.EndTabBar()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.EndTabItem`

#### Сигнатура

```lua
function imgui.EndTabItem()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.EndTable`

#### Сигнатура

```lua
function imgui.EndTable()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.EndTooltip`

#### Сигнатура

```lua
function imgui.EndTooltip()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.ErrorCheckEndFrameRecover`

#### Сигнатура

```lua
function imgui.ErrorCheckEndFrameRecover(log_callback: ffi.cdata*|ffi.cdecl*|ffi.ctype*, user_data?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>log_callback</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiErrorLogCallback</td>
    </tr>
    <tr>
      <td><code>user_data</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>void*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ErrorCheckEndWindowRecover`

#### Сигнатура

```lua
function imgui.ErrorCheckEndWindowRecover(log_callback: ffi.cdata*|ffi.cdecl*|ffi.ctype*, user_data?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>log_callback</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiErrorLogCallback</td>
    </tr>
    <tr>
      <td><code>user_data</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>void*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ErrorCheckUsingSetCursorPosToExtendParentBoundaries`

#### Сигнатура

```lua
function imgui.ErrorCheckUsingSetCursorPosToExtendParentBoundaries()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.FindBestWindowPosForPopup`

#### Сигнатура

```lua
function imgui.FindBestWindowPosForPopup(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.FindBestWindowPosForPopupEx`

#### Сигнатура

```lua
function imgui.FindBestWindowPosForPopupEx(ref_pos: ImVec2, size: ImVec2, last_dir: ffi.cdata*|ffi.cdecl*|ffi.ctype*, r_outer: ImRect, r_avoid: ImRect, policy: PopupPositionPolicy)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ref_pos</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>size</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>last_dir</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiDir*</td>
    </tr>
    <tr>
      <td><code>r_outer</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
    <tr>
      <td><code>r_avoid</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
    <tr>
      <td><code>policy</code></td>
      <td><code>PopupPositionPolicy</code></td>
      <td>да</td>
      <td>-----------------------PopupPositionPolicy----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.FindBlockingModal`

#### Сигнатура

```lua
function imgui.FindBlockingModal(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> ImGuiWindow*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.FindBottomMostVisibleWindowWithinBeginStack`

#### Сигнатура

```lua
function imgui.FindBottomMostVisibleWindowWithinBeginStack(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> ImGuiWindow*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.FindHoveredViewportFromPlatformWindowStack`

#### Сигнатура

```lua
function imgui.FindHoveredViewportFromPlatformWindowStack(mouse_platform_pos: ImVec2)
  -> ImGuiViewportP*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>mouse_platform_pos</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.FindOrCreateColumns`

#### Сигнатура

```lua
function imgui.FindOrCreateColumns(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, id: number)
  -> ImGuiOldColumns*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.FindRenderedTextEnd`

#### Сигнатура

```lua
function imgui.FindRenderedTextEnd(text: string, text_end?: string)
  -> string
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>text</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>text_end</code></td>
      <td><code>string</code></td>
      <td>нет</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `string` 

### Функция `imgui.FindSettingsHandler`

#### Сигнатура

```lua
function imgui.FindSettingsHandler(type_name: string)
  -> ImGuiSettingsHandler*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>type_name</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.FindViewportByID`

#### Сигнатура

```lua
function imgui.FindViewportByID(id: number)
  -> ImGuiViewport*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.FindViewportByPlatformHandle`

#### Сигнатура

```lua
function imgui.FindViewportByPlatformHandle(platform_handle: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> ImGuiViewport*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>platform_handle</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>void*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.FindWindowByID`

#### Сигнатура

```lua
function imgui.FindWindowByID(id: number)
  -> ImGuiWindow*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.FindWindowByName`

#### Сигнатура

```lua
function imgui.FindWindowByName(name: string)
  -> ImGuiWindow*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>name</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.FindWindowDisplayIndex`

#### Сигнатура

```lua
function imgui.FindWindowDisplayIndex(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> int: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.FindWindowSettingsByID`

#### Сигнатура

```lua
function imgui.FindWindowSettingsByID(id: number)
  -> ImGuiWindowSettings*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.FindWindowSettingsByWindow`

#### Сигнатура

```lua
function imgui.FindWindowSettingsByWindow(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> ImGuiWindowSettings*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.FixNextPopupModal`

#### Сигнатура

```lua
function imgui.FixNextPopupModal(center?: bool)
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>center</code></td>
      <td><code>bool</code></td>
      <td>нет</td>
      <td>Should next modal be centered in main viewport? Default is true.</td>
    </tr>
  </tbody>
</table>

### Функция `imgui.FixupKeyChord`

#### Сигнатура

```lua
function imgui.FixupKeyChord(ctx: ffi.cdata*|ffi.cdecl*|ffi.ctype*, key_chord: number)
  -> ImGuiKeyChord: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctx</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiContext*</td>
    </tr>
    <tr>
      <td><code>key_chord</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiKeyChord</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.FocusItem`

#### Сигнатура

```lua
function imgui.FocusItem()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.FocusTopMostWindowUnderOne`

#### Сигнатура

```lua
function imgui.FocusTopMostWindowUnderOne(under_this_window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, ignore_window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, filter_viewport: ffi.cdata*|ffi.cdecl*|ffi.ctype*, flags: FocusRequestFlags)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>under_this_window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>ignore_window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>filter_viewport</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiViewport*</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>FocusRequestFlags</code></td>
      <td>да</td>
      <td>-----------------------FocusRequestFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.FocusWindow`

#### Сигнатура

```lua
function imgui.FocusWindow(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, flags?: FocusRequestFlags)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>FocusRequestFlags</code></td>
      <td>нет</td>
      <td>-----------------------FocusRequestFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### ~~Функция `imgui.FromUTF`~~

#### Сигнатура

```lua
function imgui.FromUTF(utf_str: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>utf_str</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Функция `imgui.GcAwakeTransientWindowBuffers`

#### Сигнатура

```lua
function imgui.GcAwakeTransientWindowBuffers(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.GcCompactTransientMiscBuffers`

#### Сигнатура

```lua
function imgui.GcCompactTransientMiscBuffers()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.GcCompactTransientWindowBuffers`

#### Сигнатура

```lua
function imgui.GcCompactTransientWindowBuffers(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.GetActiveID`

#### Сигнатура

```lua
function imgui.GetActiveID()
  -> ImGuiID: number
```

#### Возвращает

- `number` 

### Функция `imgui.GetAllocatorFunctions`

#### Сигнатура

```lua
function imgui.GetAllocatorFunctions(p_alloc_func: ffi.cdata*|ffi.cdecl*|ffi.ctype*, p_free_func: ffi.cdata*|ffi.cdecl*|ffi.ctype*, p_user_data: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>p_alloc_func</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiMemAllocFunc*</td>
    </tr>
    <tr>
      <td><code>p_free_func</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiMemFreeFunc*</td>
    </tr>
    <tr>
      <td><code>p_user_data</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>void**</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### ~~Функция `imgui.GetBackgroundDrawList`~~

 generic version

#### Сигнатура

```lua
function imgui.GetBackgroundDrawList(a1: any)
  -> ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.GetBackgroundDrawList_Nil`

#### Сигнатура

```lua
function imgui.GetBackgroundDrawList_Nil()
  -> ImDrawList*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.GetBackgroundDrawList_ViewportPtr`

#### Сигнатура

```lua
function imgui.GetBackgroundDrawList_ViewportPtr(viewport: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> ImDrawList*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>viewport</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiViewport*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.GetClipboardText`

#### Сигнатура

```lua
function imgui.GetClipboardText()
  -> string
```

#### Возвращает

- `string` 

### ~~Функция `imgui.GetColorU32`~~

 generic version

#### Сигнатура

```lua
function imgui.GetColorU32(a1: any, a2: any)
  -> number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.GetColorU32_Col`

#### Сигнатура

```lua
function imgui.GetColorU32_Col(idx: Col, alpha_mul?: number)
  -> ImU32: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>idx</code></td>
      <td><code>Col</code></td>
      <td>да</td>
      <td>-----------------------Col----------------------------</td>
    </tr>
    <tr>
      <td><code>alpha_mul</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.GetColorU32_U32`

#### Сигнатура

```lua
function imgui.GetColorU32_U32(col: number, alpha_mul?: number)
  -> ImU32: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
    <tr>
      <td><code>alpha_mul</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.GetColorU32_Vec4`

#### Сигнатура

```lua
function imgui.GetColorU32_Vec4(col: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> ImU32: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>col</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImVec4</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.GetColumnIndex`

#### Сигнатура

```lua
function imgui.GetColumnIndex()
  -> int: number
```

#### Возвращает

- `number` 

### Функция `imgui.GetColumnNormFromOffset`

#### Сигнатура

```lua
function imgui.GetColumnNormFromOffset(columns: ffi.cdata*|ffi.cdecl*|ffi.ctype*, offset: number)
  -> float: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>columns</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImGuiOldColumns*</td>
    </tr>
    <tr>
      <td><code>offset</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.GetColumnOffset`

#### Сигнатура

```lua
function imgui.GetColumnOffset(column_index?: number)
  -> float: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>column_index</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.GetColumnOffsetFromNorm`

#### Сигнатура

```lua
function imgui.GetColumnOffsetFromNorm(columns: ffi.cdata*|ffi.cdecl*|ffi.ctype*, offset_norm: number)
  -> float: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>columns</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImGuiOldColumns*</td>
    </tr>
    <tr>
      <td><code>offset_norm</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.GetColumnWidth`

#### Сигнатура

```lua
function imgui.GetColumnWidth(column_index?: number)
  -> float: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>column_index</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.GetColumnsCount`

#### Сигнатура

```lua
function imgui.GetColumnsCount()
  -> int: number
```

#### Возвращает

- `number` 

### Функция `imgui.GetColumnsID`

#### Сигнатура

```lua
function imgui.GetColumnsID(str_id: string, count: number)
  -> ImGuiID: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>str_id</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>count</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.GetContentRegionAvail`

#### Сигнатура

```lua
function imgui.GetContentRegionAvail()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.GetContentRegionMax`

#### Сигнатура

```lua
function imgui.GetContentRegionMax()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.GetContentRegionMaxAbs`

#### Сигнатура

```lua
function imgui.GetContentRegionMaxAbs()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.GetCurrentContext`

#### Сигнатура

```lua
function imgui.GetCurrentContext()
  -> ImGuiContext*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.GetCurrentFocusScope`

#### Сигнатура

```lua
function imgui.GetCurrentFocusScope()
  -> ImGuiID: number
```

#### Возвращает

- `number` 

### Функция `imgui.GetCurrentTabBar`

#### Сигнатура

```lua
function imgui.GetCurrentTabBar()
  -> ImGuiTabBar*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.GetCurrentTable`

#### Сигнатура

```lua
function imgui.GetCurrentTable()
  -> ImGuiTable*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.GetCurrentWindow`

#### Сигнатура

```lua
function imgui.GetCurrentWindow()
  -> ImGuiWindow*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.GetCurrentWindowRead`

#### Сигнатура

```lua
function imgui.GetCurrentWindowRead()
  -> ImGuiWindow*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.GetCursorPos`

#### Сигнатура

```lua
function imgui.GetCursorPos()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.GetCursorPosX`

#### Сигнатура

```lua
function imgui.GetCursorPosX()
  -> float: number
```

#### Возвращает

- `number` 

### Функция `imgui.GetCursorPosY`

#### Сигнатура

```lua
function imgui.GetCursorPosY()
  -> float: number
```

#### Возвращает

- `number` 

### Функция `imgui.GetCursorScreenPos`

#### Сигнатура

```lua
function imgui.GetCursorScreenPos()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.GetCursorStartPos`

#### Сигнатура

```lua
function imgui.GetCursorStartPos()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.GetDefaultFont`

#### Сигнатура

```lua
function imgui.GetDefaultFont()
  -> ImFont*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.GetDragDropPayload`

#### Сигнатура

```lua
function imgui.GetDragDropPayload()
  -> const: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.GetDrawData`

#### Сигнатура

```lua
function imgui.GetDrawData()
  -> ImDrawData*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.GetDrawListSharedData`

#### Сигнатура

```lua
function imgui.GetDrawListSharedData()
  -> ImDrawListSharedData*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.GetFocusID`

#### Сигнатура

```lua
function imgui.GetFocusID()
  -> ImGuiID: number
```

#### Возвращает

- `number` 

### Функция `imgui.GetFont`

#### Сигнатура

```lua
function imgui.GetFont()
  -> ImFont*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.GetFontSize`

#### Сигнатура

```lua
function imgui.GetFontSize()
  -> float: number
```

#### Возвращает

- `number` 

### Функция `imgui.GetFontTexUvWhitePixel`

#### Сигнатура

```lua
function imgui.GetFontTexUvWhitePixel()
  -> nil
```

#### Возвращает

- `nil` 

### ~~Функция `imgui.GetForegroundDrawList`~~

 generic version

#### Сигнатура

```lua
function imgui.GetForegroundDrawList(a1: any)
  -> ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.GetForegroundDrawList_Nil`

#### Сигнатура

```lua
function imgui.GetForegroundDrawList_Nil()
  -> ImDrawList*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.GetForegroundDrawList_ViewportPtr`

#### Сигнатура

```lua
function imgui.GetForegroundDrawList_ViewportPtr(viewport: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> ImDrawList*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>viewport</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiViewport*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.GetForegroundDrawList_WindowPtr`

#### Сигнатура

```lua
function imgui.GetForegroundDrawList_WindowPtr(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> ImDrawList*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.GetFrameCount`

#### Сигнатура

```lua
function imgui.GetFrameCount()
  -> int: number
```

#### Возвращает

- `number` 

### Функция `imgui.GetFrameHeight`

#### Сигнатура

```lua
function imgui.GetFrameHeight()
  -> float: number
```

#### Возвращает

- `number` 

### Функция `imgui.GetFrameHeightWithSpacing`

#### Сигнатура

```lua
function imgui.GetFrameHeightWithSpacing()
  -> float: number
```

#### Возвращает

- `number` 

### Функция `imgui.GetHoveredID`

#### Сигнатура

```lua
function imgui.GetHoveredID()
  -> ImGuiID: number
```

#### Возвращает

- `number` 

### ~~Функция `imgui.GetID`~~

 generic version

#### Сигнатура

```lua
function imgui.GetID(a1: any, a2: any)
  -> number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### ~~Функция `imgui.GetIDWithSeed`~~

 generic version

#### Сигнатура

```lua
function imgui.GetIDWithSeed(a1: any, a2: any, a3: any)
  -> number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a3</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.GetIDWithSeed_Int`

#### Сигнатура

```lua
function imgui.GetIDWithSeed_Int(n: number, seed: number)
  -> ImGuiID: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>n</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>seed</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.GetIDWithSeed_Str`

#### Сигнатура

```lua
function imgui.GetIDWithSeed_Str(str_id_begin: string, str_id_end: string, seed: number)
  -> ImGuiID: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>str_id_begin</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>str_id_end</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>seed</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.GetID_Ptr`

#### Сигнатура

```lua
function imgui.GetID_Ptr(ptr_id: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> ImGuiID: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ptr_id</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const void*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.GetID_Str`

#### Сигнатура

```lua
function imgui.GetID_Str(str_id: string)
  -> ImGuiID: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>str_id</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.GetID_StrStr`

#### Сигнатура

```lua
function imgui.GetID_StrStr(str_id_begin: string, str_id_end: string)
  -> ImGuiID: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>str_id_begin</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>str_id_end</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.GetIO`

#### Сигнатура

```lua
function imgui.GetIO()
  -> ImGuiIO*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.GetInputTextState`

#### Сигнатура

```lua
function imgui.GetInputTextState(id: number)
  -> ImGuiInputTextState*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.GetItemFlags`

#### Сигнатура

```lua
function imgui.GetItemFlags()
  -> ItemFlags
```

#### Возвращает

- `ItemFlags` 

### Функция `imgui.GetItemID`

#### Сигнатура

```lua
function imgui.GetItemID()
  -> ImGuiID: number
```

#### Возвращает

- `number` 

### Функция `imgui.GetItemRectMax`

#### Сигнатура

```lua
function imgui.GetItemRectMax()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.GetItemRectMin`

#### Сигнатура

```lua
function imgui.GetItemRectMin()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.GetItemRectSize`

#### Сигнатура

```lua
function imgui.GetItemRectSize()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.GetItemStatusFlags`

#### Сигнатура

```lua
function imgui.GetItemStatusFlags()
  -> ItemStatusFlags
```

#### Возвращает

- `ItemStatusFlags` 

### Функция `imgui.GetKeyChordName`

#### Сигнатура

```lua
function imgui.GetKeyChordName(key_chord: number)
  -> string
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key_chord</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiKeyChord</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `string` 

### ~~Функция `imgui.GetKeyData`~~

 generic version

#### Сигнатура

```lua
function imgui.GetKeyData(a1: any, a2: any)
  -> ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.GetKeyData_ContextPtr`

#### Сигнатура

```lua
function imgui.GetKeyData_ContextPtr(ctx: ffi.cdata*|ffi.cdecl*|ffi.ctype*, key: Key)
  -> ImGuiKeyData*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctx</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiContext*</td>
    </tr>
    <tr>
      <td><code>key</code></td>
      <td><code>Key</code></td>
      <td>да</td>
      <td>-----------------------Key----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.GetKeyData_Key`

#### Сигнатура

```lua
function imgui.GetKeyData_Key(key: Key)
  -> ImGuiKeyData*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>Key</code></td>
      <td>да</td>
      <td>-----------------------Key----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.GetKeyIndex`

#### Сигнатура

```lua
function imgui.GetKeyIndex(key: Key)
  -> Key
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>Key</code></td>
      <td>да</td>
      <td>-----------------------Key----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `Key` 

### Функция `imgui.GetKeyMagnitude2d`

#### Сигнатура

```lua
function imgui.GetKeyMagnitude2d(key_left: Key, key_right: Key, key_up: Key, key_down: Key)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key_left</code></td>
      <td><code>Key</code></td>
      <td>да</td>
      <td>-----------------------Key----------------------------</td>
    </tr>
    <tr>
      <td><code>key_right</code></td>
      <td><code>Key</code></td>
      <td>да</td>
      <td>-----------------------Key----------------------------</td>
    </tr>
    <tr>
      <td><code>key_up</code></td>
      <td><code>Key</code></td>
      <td>да</td>
      <td>-----------------------Key----------------------------</td>
    </tr>
    <tr>
      <td><code>key_down</code></td>
      <td><code>Key</code></td>
      <td>да</td>
      <td>-----------------------Key----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.GetKeyName`

#### Сигнатура

```lua
function imgui.GetKeyName(key: Key)
  -> string
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>Key</code></td>
      <td>да</td>
      <td>-----------------------Key----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `string` 

### Функция `imgui.GetKeyOwner`

#### Сигнатура

```lua
function imgui.GetKeyOwner(key: Key)
  -> ImGuiID: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>Key</code></td>
      <td>да</td>
      <td>-----------------------Key----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.GetKeyOwnerData`

#### Сигнатура

```lua
function imgui.GetKeyOwnerData(ctx: ffi.cdata*|ffi.cdecl*|ffi.ctype*, key: Key)
  -> ImGuiKeyOwnerData*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctx</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiContext*</td>
    </tr>
    <tr>
      <td><code>key</code></td>
      <td><code>Key</code></td>
      <td>да</td>
      <td>-----------------------Key----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.GetKeyPressedAmount`

#### Сигнатура

```lua
function imgui.GetKeyPressedAmount(key: Key, repeat_delay: number, rate: number)
  -> int: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>Key</code></td>
      <td>да</td>
      <td>-----------------------Key----------------------------</td>
    </tr>
    <tr>
      <td><code>repeat_delay</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>rate</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.GetMainViewport`

#### Сигнатура

```lua
function imgui.GetMainViewport()
  -> ImGuiViewport*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.GetMouseClickedCount`

#### Сигнатура

```lua
function imgui.GetMouseClickedCount(button: MouseButton)
  -> int: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>button</code></td>
      <td><code>MouseButton</code></td>
      <td>да</td>
      <td>-----------------------MouseButton----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.GetMouseCursor`

#### Сигнатура

```lua
function imgui.GetMouseCursor()
  -> MouseCursor
```

#### Возвращает

- `MouseCursor` 

### Функция `imgui.GetMouseDragDelta`

#### Сигнатура

```lua
function imgui.GetMouseDragDelta(button?: MouseButton, lock_threshold?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>button</code></td>
      <td><code>MouseButton</code></td>
      <td>нет</td>
      <td>-----------------------MouseButton----------------------------</td>
    </tr>
    <tr>
      <td><code>lock_threshold</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.GetMousePos`

#### Сигнатура

```lua
function imgui.GetMousePos()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.GetMousePosOnOpeningCurrentPopup`

#### Сигнатура

```lua
function imgui.GetMousePosOnOpeningCurrentPopup()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.GetNavTweakPressedAmount`

#### Сигнатура

```lua
function imgui.GetNavTweakPressedAmount(axis: Axis)
  -> float: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>axis</code></td>
      <td><code>Axis</code></td>
      <td>да</td>
      <td>-----------------------Axis----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.GetPlatformIO`

#### Сигнатура

```lua
function imgui.GetPlatformIO()
  -> ImGuiPlatformIO*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.GetPopupAllowedExtentRect`

#### Сигнатура

```lua
function imgui.GetPopupAllowedExtentRect(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.GetScrollMaxX`

#### Сигнатура

```lua
function imgui.GetScrollMaxX()
  -> float: number
```

#### Возвращает

- `number` 

### Функция `imgui.GetScrollMaxY`

#### Сигнатура

```lua
function imgui.GetScrollMaxY()
  -> float: number
```

#### Возвращает

- `number` 

### Функция `imgui.GetScrollX`

#### Сигнатура

```lua
function imgui.GetScrollX()
  -> float: number
```

#### Возвращает

- `number` 

### Функция `imgui.GetScrollY`

#### Сигнатура

```lua
function imgui.GetScrollY()
  -> float: number
```

#### Возвращает

- `number` 

### Функция `imgui.GetShortcutRoutingData`

#### Сигнатура

```lua
function imgui.GetShortcutRoutingData(key_chord: number)
  -> ImGuiKeyRoutingData*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key_chord</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiKeyChord</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.GetStateStorage`

#### Сигнатура

```lua
function imgui.GetStateStorage()
  -> ImGuiStorage*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.GetStyle`

#### Сигнатура

```lua
function imgui.GetStyle()
  -> ImGuiStyle*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.GetStyleColorName`

#### Сигнатура

```lua
function imgui.GetStyleColorName(idx: Col)
  -> string
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>idx</code></td>
      <td><code>Col</code></td>
      <td>да</td>
      <td>-----------------------Col----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `string` 

### Функция `imgui.GetStyleColorVec4`

#### Сигнатура

```lua
function imgui.GetStyleColorVec4(idx: Col)
  -> const: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>idx</code></td>
      <td><code>Col</code></td>
      <td>да</td>
      <td>-----------------------Col----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.GetStyleVarInfo`

#### Сигнатура

```lua
function imgui.GetStyleVarInfo(idx: StyleVar)
  -> const: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>idx</code></td>
      <td><code>StyleVar</code></td>
      <td>да</td>
      <td>-----------------------StyleVar----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.GetTextLineHeight`

#### Сигнатура

```lua
function imgui.GetTextLineHeight()
  -> float: number
```

#### Возвращает

- `number` 

### Функция `imgui.GetTextLineHeightWithSpacing`

#### Сигнатура

```lua
function imgui.GetTextLineHeightWithSpacing()
  -> float: number
```

#### Возвращает

- `number` 

### Функция `imgui.GetTime`

#### Сигнатура

```lua
function imgui.GetTime()
  -> double: number
```

#### Возвращает

- `number` 

### Функция `imgui.GetTopMostAndVisiblePopupModal`

#### Сигнатура

```lua
function imgui.GetTopMostAndVisiblePopupModal()
  -> ImGuiWindow*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.GetTopMostPopupModal`

#### Сигнатура

```lua
function imgui.GetTopMostPopupModal()
  -> ImGuiWindow*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.GetTreeNodeToLabelSpacing`

#### Сигнатура

```lua
function imgui.GetTreeNodeToLabelSpacing()
  -> float: number
```

#### Возвращает

- `number` 

### Функция `imgui.GetTypematicRepeatRate`

#### Сигнатура

```lua
function imgui.GetTypematicRepeatRate(flags: InputFlags, repeat_delay: ffi.cdata*|ffi.cdecl*|ffi.ctype*, repeat_rate: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>flags</code></td>
      <td><code>InputFlags</code></td>
      <td>да</td>
      <td>-----------------------InputFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>repeat_delay</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>float*</td>
    </tr>
    <tr>
      <td><code>repeat_rate</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>float*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.GetTypingSelectRequest`

#### Сигнатура

```lua
function imgui.GetTypingSelectRequest(flags?: TypingSelectFlags)
  -> ImGuiTypingSelectRequest*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>flags</code></td>
      <td><code>TypingSelectFlags</code></td>
      <td>нет</td>
      <td>-----------------------TypingSelectFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.GetVersion`

#### Сигнатура

```lua
function imgui.GetVersion()
  -> string
```

#### Возвращает

- `string` 

### Функция `imgui.GetViewportPlatformMonitor`

#### Сигнатура

```lua
function imgui.GetViewportPlatformMonitor(viewport: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> const: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>viewport</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiViewport*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.GetWindowAlwaysWantOwnTabBar`

#### Сигнатура

```lua
function imgui.GetWindowAlwaysWantOwnTabBar(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.GetWindowContentRegionMax`

#### Сигнатура

```lua
function imgui.GetWindowContentRegionMax()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.GetWindowContentRegionMin`

#### Сигнатура

```lua
function imgui.GetWindowContentRegionMin()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.GetWindowDockID`

#### Сигнатура

```lua
function imgui.GetWindowDockID()
  -> ImGuiID: number
```

#### Возвращает

- `number` 

### Функция `imgui.GetWindowDockNode`

#### Сигнатура

```lua
function imgui.GetWindowDockNode()
  -> ImGuiDockNode*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.GetWindowDpiScale`

#### Сигнатура

```lua
function imgui.GetWindowDpiScale()
  -> float: number
```

#### Возвращает

- `number` 

### Функция `imgui.GetWindowDrawList`

#### Сигнатура

```lua
function imgui.GetWindowDrawList()
  -> ImDrawList*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.GetWindowHeight`

#### Сигнатура

```lua
function imgui.GetWindowHeight()
  -> float: number
```

#### Возвращает

- `number` 

### Функция `imgui.GetWindowPos`

#### Сигнатура

```lua
function imgui.GetWindowPos()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.GetWindowResizeBorderID`

#### Сигнатура

```lua
function imgui.GetWindowResizeBorderID(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, dir: Dir)
  -> ImGuiID: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>dir</code></td>
      <td><code>Dir</code></td>
      <td>да</td>
      <td>-----------------------Dir----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.GetWindowResizeCornerID`

#### Сигнатура

```lua
function imgui.GetWindowResizeCornerID(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, n: number)
  -> ImGuiID: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>n</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.GetWindowScrollbarID`

#### Сигнатура

```lua
function imgui.GetWindowScrollbarID(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, axis: Axis)
  -> ImGuiID: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>axis</code></td>
      <td><code>Axis</code></td>
      <td>да</td>
      <td>-----------------------Axis----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.GetWindowScrollbarRect`

#### Сигнатура

```lua
function imgui.GetWindowScrollbarRect(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, axis: Axis)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>axis</code></td>
      <td><code>Axis</code></td>
      <td>да</td>
      <td>-----------------------Axis----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.GetWindowSize`

#### Сигнатура

```lua
function imgui.GetWindowSize()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.GetWindowViewport`

#### Сигнатура

```lua
function imgui.GetWindowViewport()
  -> ImGuiViewport*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.GetWindowWidth`

#### Сигнатура

```lua
function imgui.GetWindowWidth()
  -> float: number
```

#### Возвращает

- `number` 

### Функция `imgui.HelpMarker`

--------Custom widgets

#### Сигнатура

```lua
function imgui.HelpMarker(desc: any, icon: any)
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>desc</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>icon</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

### ~~Функция `imgui.ImAbs`~~

 generic version

#### Сигнатура

```lua
function imgui.ImAbs(a1: any)
  -> number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImAbs_Float`

#### Сигнатура

```lua
function imgui.ImAbs_Float(x: number)
  -> float: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>x</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImAbs_Int`

#### Сигнатура

```lua
function imgui.ImAbs_Int(x: number)
  -> int: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>x</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImAbs_double`

#### Сигнатура

```lua
function imgui.ImAbs_double(x: number)
  -> double: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>x</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>double</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImAlphaBlendColors`

#### Сигнатура

```lua
function imgui.ImAlphaBlendColors(col_a: number, col_b: number)
  -> ImU32: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>col_a</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
    <tr>
      <td><code>col_b</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImBezierCubicCalc`

#### Сигнатура

```lua
function imgui.ImBezierCubicCalc(p1: ImVec2, p2: ImVec2, p3: ImVec2, p4: ImVec2, t: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>p1</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p2</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p3</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p4</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>t</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ImBezierCubicClosestPoint`

#### Сигнатура

```lua
function imgui.ImBezierCubicClosestPoint(p1: ImVec2, p2: ImVec2, p3: ImVec2, p4: ImVec2, p: ImVec2, num_segments: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>p1</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p2</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p3</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p4</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>num_segments</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ImBezierCubicClosestPointCasteljau`

#### Сигнатура

```lua
function imgui.ImBezierCubicClosestPointCasteljau(p1: ImVec2, p2: ImVec2, p3: ImVec2, p4: ImVec2, p: ImVec2, tess_tol: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>p1</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p2</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p3</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p4</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>tess_tol</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ImBezierQuadraticCalc`

#### Сигнатура

```lua
function imgui.ImBezierQuadraticCalc(p1: ImVec2, p2: ImVec2, p3: ImVec2, t: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>p1</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p2</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p3</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>t</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ImBitArrayClearAllBits`

#### Сигнатура

```lua
function imgui.ImBitArrayClearAllBits(arr: ffi.cdata*|ffi.cdecl*|ffi.ctype*, bitcount: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>arr</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImU32*</td>
    </tr>
    <tr>
      <td><code>bitcount</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ImBitArrayClearBit`

#### Сигнатура

```lua
function imgui.ImBitArrayClearBit(arr: ffi.cdata*|ffi.cdecl*|ffi.ctype*, n: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>arr</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImU32*</td>
    </tr>
    <tr>
      <td><code>n</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ImBitArrayGetStorageSizeInBytes`

#### Сигнатура

```lua
function imgui.ImBitArrayGetStorageSizeInBytes(bitcount: number)
  -> size_t: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>bitcount</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImBitArraySetBit`

#### Сигнатура

```lua
function imgui.ImBitArraySetBit(arr: ffi.cdata*|ffi.cdecl*|ffi.ctype*, n: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>arr</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImU32*</td>
    </tr>
    <tr>
      <td><code>n</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ImBitArraySetBitRange`

#### Сигнатура

```lua
function imgui.ImBitArraySetBitRange(arr: ffi.cdata*|ffi.cdecl*|ffi.ctype*, n: number, n2: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>arr</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImU32*</td>
    </tr>
    <tr>
      <td><code>n</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>n2</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ImBitArrayTestBit`

#### Сигнатура

```lua
function imgui.ImBitArrayTestBit(arr: ffi.cdata*|ffi.cdecl*|ffi.ctype*, n: number)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>arr</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImU32*</td>
    </tr>
    <tr>
      <td><code>n</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.ImCharIsBlankA`

#### Сигнатура

```lua
function imgui.ImCharIsBlankA(c: number)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>c</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>char</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.ImCharIsBlankW`

#### Сигнатура

```lua
function imgui.ImCharIsBlankW(c: number)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>c</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>unsigned int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.ImClamp`

#### Сигнатура

```lua
function imgui.ImClamp(v: ImVec2, mn: ImVec2, mx: ImVec2)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>v</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>mn</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>mx</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ImColor_HSV`

#### Сигнатура

```lua
function imgui.ImColor_HSV(h: number, s: number, v: number, a?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>h</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>s</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>a</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ImDot`

#### Сигнатура

```lua
function imgui.ImDot(a: ImVec2, b: ImVec2)
  -> float: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>b</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImExponentialMovingAverage`

#### Сигнатура

```lua
function imgui.ImExponentialMovingAverage(avg: number, sample: number, n: number)
  -> float: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>avg</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>sample</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>n</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImFileClose`

#### Сигнатура

```lua
function imgui.ImFileClose(file: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>file</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImFileHandle</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.ImFileGetSize`

#### Сигнатура

```lua
function imgui.ImFileGetSize(file: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> ImU64: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>file</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImFileHandle</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImFileLoadToMemory`

#### Сигнатура

```lua
function imgui.ImFileLoadToMemory(filename: string, mode: string, out_file_size?: ffi.cdata*|ffi.cdecl*|ffi.ctype*, padding_bytes?: number)
  -> void*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>filename</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>mode</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>out_file_size</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>size_t*</td>
    </tr>
    <tr>
      <td><code>padding_bytes</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.ImFileOpen`

#### Сигнатура

```lua
function imgui.ImFileOpen(filename: string, mode: string)
  -> ImFileHandle: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>filename</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>mode</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.ImFileRead`

#### Сигнатура

```lua
function imgui.ImFileRead(data: ffi.cdata*|ffi.cdecl*|ffi.ctype*, size: number, count: number, file: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> ImU64: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>data</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>void*</td>
    </tr>
    <tr>
      <td><code>size</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU64</td>
    </tr>
    <tr>
      <td><code>count</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU64</td>
    </tr>
    <tr>
      <td><code>file</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImFileHandle</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImFileWrite`

#### Сигнатура

```lua
function imgui.ImFileWrite(data: ffi.cdata*|ffi.cdecl*|ffi.ctype*, size: number, count: number, file: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> ImU64: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>data</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const void*</td>
    </tr>
    <tr>
      <td><code>size</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU64</td>
    </tr>
    <tr>
      <td><code>count</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU64</td>
    </tr>
    <tr>
      <td><code>file</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImFileHandle</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### ~~Функция `imgui.ImFloor`~~

 generic version

#### Сигнатура

```lua
function imgui.ImFloor(a1: any, a2: any)
  -> number|nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` или `nil` 

### Функция `imgui.ImFloor_Float`

#### Сигнатура

```lua
function imgui.ImFloor_Float(f: number)
  -> float: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>f</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImFloor_Vec2`

#### Сигнатура

```lua
function imgui.ImFloor_Vec2(v: ImVec2)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>v</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ImFontAtlasBuildFinish`

#### Сигнатура

```lua
function imgui.ImFontAtlasBuildFinish(atlas: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>atlas</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImFontAtlas*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ImFontAtlasBuildInit`

#### Сигнатура

```lua
function imgui.ImFontAtlasBuildInit(atlas: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>atlas</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImFontAtlas*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ImFontAtlasBuildMultiplyCalcLookupTable`

#### Сигнатура

```lua
function imgui.ImFontAtlasBuildMultiplyCalcLookupTable(out_table: ffi.cdata*|ffi.cdecl*|ffi.ctype*, in_multiply_factor: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>out_table</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>unsigned char[256]</td>
    </tr>
    <tr>
      <td><code>in_multiply_factor</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ImFontAtlasBuildMultiplyRectAlpha8`

#### Сигнатура

```lua
function imgui.ImFontAtlasBuildMultiplyRectAlpha8(table: ffi.cdata*|ffi.cdecl*|ffi.ctype*, pixels: ffi.cdata*|ffi.cdecl*|ffi.ctype*, x: number, y: number, w: number, h: number, stride: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>table</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const unsigned char[256]</td>
    </tr>
    <tr>
      <td><code>pixels</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>unsigned char*</td>
    </tr>
    <tr>
      <td><code>x</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>y</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>w</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>h</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>stride</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ImFontAtlasBuildPackCustomRects`

#### Сигнатура

```lua
function imgui.ImFontAtlasBuildPackCustomRects(atlas: ffi.cdata*|ffi.cdecl*|ffi.ctype*, stbrp_context_opaque: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>atlas</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImFontAtlas*</td>
    </tr>
    <tr>
      <td><code>stbrp_context_opaque</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>void*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ImFontAtlasBuildRender32bppRectFromString`

#### Сигнатура

```lua
function imgui.ImFontAtlasBuildRender32bppRectFromString(atlas: ffi.cdata*|ffi.cdecl*|ffi.ctype*, x: number, y: number, w: number, h: number, in_str: string, in_marker_char: number, in_marker_pixel_value: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>atlas</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImFontAtlas*</td>
    </tr>
    <tr>
      <td><code>x</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>y</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>w</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>h</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>in_str</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>in_marker_char</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>char</td>
    </tr>
    <tr>
      <td><code>in_marker_pixel_value</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>unsigned int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ImFontAtlasBuildRender8bppRectFromString`

#### Сигнатура

```lua
function imgui.ImFontAtlasBuildRender8bppRectFromString(atlas: ffi.cdata*|ffi.cdecl*|ffi.ctype*, x: number, y: number, w: number, h: number, in_str: string, in_marker_char: number, in_marker_pixel_value: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>atlas</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImFontAtlas*</td>
    </tr>
    <tr>
      <td><code>x</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>y</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>w</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>h</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>in_str</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>in_marker_char</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>char</td>
    </tr>
    <tr>
      <td><code>in_marker_pixel_value</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>unsigned char</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ImFontAtlasBuildSetupFont`

#### Сигнатура

```lua
function imgui.ImFontAtlasBuildSetupFont(atlas: ffi.cdata*|ffi.cdecl*|ffi.ctype*, font: ffi.cdata*|ffi.cdecl*|ffi.ctype*, font_config: ffi.cdata*|ffi.cdecl*|ffi.ctype*, ascent: number, descent: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>atlas</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImFontAtlas*</td>
    </tr>
    <tr>
      <td><code>font</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImFont*</td>
    </tr>
    <tr>
      <td><code>font_config</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImFontConfig*</td>
    </tr>
    <tr>
      <td><code>ascent</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>descent</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ImFontAtlasGetBuilderForStbTruetype`

#### Сигнатура

```lua
function imgui.ImFontAtlasGetBuilderForStbTruetype()
  -> const: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.ImFontAtlasUpdateConfigDataPointers`

#### Сигнатура

```lua
function imgui.ImFontAtlasUpdateConfigDataPointers(atlas: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>atlas</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImFontAtlas*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ImFormatString`

#### Сигнатура

```lua
function imgui.ImFormatString(buf: ffi.cdata*|ffi.cdecl*|ffi.ctype*, buf_size: number, fmt: string, ...any)
  -> int: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>buf</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>char*</td>
    </tr>
    <tr>
      <td><code>buf_size</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>size_t</td>
    </tr>
    <tr>
      <td><code>fmt</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>...</code></td>
      <td><code>unknown</code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImFormatStringToTempBuffer`

#### Сигнатура

```lua
function imgui.ImFormatStringToTempBuffer(out_buf: ffi.cdata*|ffi.cdecl*|ffi.ctype*, out_buf_end: ffi.cdata*|ffi.cdecl*|ffi.ctype*, fmt: string, ...any)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>out_buf</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const char**</td>
    </tr>
    <tr>
      <td><code>out_buf_end</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const char**</td>
    </tr>
    <tr>
      <td><code>fmt</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>...</code></td>
      <td><code>unknown</code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ImFormatStringToTempBufferV`

#### Сигнатура

```lua
function imgui.ImFormatStringToTempBufferV(out_buf: ffi.cdata*|ffi.cdecl*|ffi.ctype*, out_buf_end: ffi.cdata*|ffi.cdecl*|ffi.ctype*, fmt: string, args: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>out_buf</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const char**</td>
    </tr>
    <tr>
      <td><code>out_buf_end</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const char**</td>
    </tr>
    <tr>
      <td><code>fmt</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>args</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>va_list</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ImFormatStringV`

#### Сигнатура

```lua
function imgui.ImFormatStringV(buf: ffi.cdata*|ffi.cdecl*|ffi.ctype*, buf_size: number, fmt: string, args: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> int: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>buf</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>char*</td>
    </tr>
    <tr>
      <td><code>buf_size</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>size_t</td>
    </tr>
    <tr>
      <td><code>fmt</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>args</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>va_list</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImGuiListClipperRange_FromIndices`

#### Сигнатура

```lua
function imgui.ImGuiListClipperRange_FromIndices(min: number, max: number)
  -> ImGuiListClipperRange
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>min</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>max</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ImGuiListClipperRange` 

### Функция `imgui.ImGuiListClipperRange_FromPositions`

#### Сигнатура

```lua
function imgui.ImGuiListClipperRange_FromPositions(y1: number, y2: number, off_min: number, off_max: number)
  -> ImGuiListClipperRange
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>y1</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>y2</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>off_min</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>off_max</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ImGuiListClipperRange` 

### Функция `imgui.ImHashData`

#### Сигнатура

```lua
function imgui.ImHashData(data: ffi.cdata*|ffi.cdecl*|ffi.ctype*, data_size: number, seed?: number)
  -> ImGuiID: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>data</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const void*</td>
    </tr>
    <tr>
      <td><code>data_size</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>size_t</td>
    </tr>
    <tr>
      <td><code>seed</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImHashStr`

#### Сигнатура

```lua
function imgui.ImHashStr(data: string, data_size?: number, seed?: number)
  -> ImGuiID: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>data</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>data_size</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>size_t</td>
    </tr>
    <tr>
      <td><code>seed</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImInvLength`

#### Сигнатура

```lua
function imgui.ImInvLength(lhs: ImVec2, fail_value: number)
  -> float: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>lhs</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>fail_value</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImIsFloatAboveGuaranteedIntegerPrecision`

#### Сигнатура

```lua
function imgui.ImIsFloatAboveGuaranteedIntegerPrecision(f: number)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>f</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### ~~Функция `imgui.ImIsPowerOfTwo`~~

 generic version

#### Сигнатура

```lua
function imgui.ImIsPowerOfTwo(a1: any)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.ImIsPowerOfTwo_Int`

#### Сигнатура

```lua
function imgui.ImIsPowerOfTwo_Int(v: number)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>v</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.ImIsPowerOfTwo_U64`

#### Сигнатура

```lua
function imgui.ImIsPowerOfTwo_U64(v: number)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>v</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU64</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### ~~Функция `imgui.ImLengthSqr`~~

 generic version

#### Сигнатура

```lua
function imgui.ImLengthSqr(a1: any)
  -> number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImLengthSqr_Vec2`

#### Сигнатура

```lua
function imgui.ImLengthSqr_Vec2(lhs: ImVec2)
  -> float: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>lhs</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImLengthSqr_Vec4`

#### Сигнатура

```lua
function imgui.ImLengthSqr_Vec4(lhs: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> float: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>lhs</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImVec4</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### ~~Функция `imgui.ImLerp`~~

 generic version

#### Сигнатура

```lua
function imgui.ImLerp(a2: any, a3: any, a4: any)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a3</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a4</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ImLerp_Vec2Float`

#### Сигнатура

```lua
function imgui.ImLerp_Vec2Float(a: ImVec2, b: ImVec2, t: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>b</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>t</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ImLerp_Vec2Vec2`

#### Сигнатура

```lua
function imgui.ImLerp_Vec2Vec2(a: ImVec2, b: ImVec2, t: ImVec2)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>b</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>t</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ImLerp_Vec4`

#### Сигнатура

```lua
function imgui.ImLerp_Vec4(a: ffi.cdata*|ffi.cdecl*|ffi.ctype*, b: ffi.cdata*|ffi.cdecl*|ffi.ctype*, t: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImVec4</td>
    </tr>
    <tr>
      <td><code>b</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImVec4</td>
    </tr>
    <tr>
      <td><code>t</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ImLineClosestPoint`

#### Сигнатура

```lua
function imgui.ImLineClosestPoint(a: ImVec2, b: ImVec2, p: ImVec2)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>b</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ImLinearSweep`

#### Сигнатура

```lua
function imgui.ImLinearSweep(current: number, target: number, speed: number)
  -> float: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>current</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>target</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>speed</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### ~~Функция `imgui.ImLog`~~

 generic version

#### Сигнатура

```lua
function imgui.ImLog(a1: any)
  -> number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImLog_Float`

#### Сигнатура

```lua
function imgui.ImLog_Float(x: number)
  -> float: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>x</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImLog_double`

#### Сигнатура

```lua
function imgui.ImLog_double(x: number)
  -> double: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>x</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>double</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImMax`

#### Сигнатура

```lua
function imgui.ImMax(lhs: ImVec2, rhs: ImVec2)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>lhs</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>rhs</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ImMin`

#### Сигнатура

```lua
function imgui.ImMin(lhs: ImVec2, rhs: ImVec2)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>lhs</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>rhs</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ImModPositive`

#### Сигнатура

```lua
function imgui.ImModPositive(a: number, b: number)
  -> int: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>b</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImMul`

#### Сигнатура

```lua
function imgui.ImMul(lhs: ImVec2, rhs: ImVec2)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>lhs</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>rhs</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ImParseFormatFindEnd`

#### Сигнатура

```lua
function imgui.ImParseFormatFindEnd(format: string)
  -> string
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `string` 

### Функция `imgui.ImParseFormatFindStart`

#### Сигнатура

```lua
function imgui.ImParseFormatFindStart(format: string)
  -> string
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `string` 

### Функция `imgui.ImParseFormatPrecision`

#### Сигнатура

```lua
function imgui.ImParseFormatPrecision(format: string, default_value: number)
  -> int: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>default_value</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImParseFormatSanitizeForPrinting`

#### Сигнатура

```lua
function imgui.ImParseFormatSanitizeForPrinting(fmt_in: string, fmt_out: ffi.cdata*|ffi.cdecl*|ffi.ctype*, fmt_out_size: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>fmt_in</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>fmt_out</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>char*</td>
    </tr>
    <tr>
      <td><code>fmt_out_size</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>size_t</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ImParseFormatSanitizeForScanning`

#### Сигнатура

```lua
function imgui.ImParseFormatSanitizeForScanning(fmt_in: string, fmt_out: ffi.cdata*|ffi.cdecl*|ffi.ctype*, fmt_out_size: number)
  -> string
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>fmt_in</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>fmt_out</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>char*</td>
    </tr>
    <tr>
      <td><code>fmt_out_size</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>size_t</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `string` 

### Функция `imgui.ImParseFormatTrimDecorations`

#### Сигнатура

```lua
function imgui.ImParseFormatTrimDecorations(format: string, buf: ffi.cdata*|ffi.cdecl*|ffi.ctype*, buf_size: number)
  -> string
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>buf</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>char*</td>
    </tr>
    <tr>
      <td><code>buf_size</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>size_t</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `string` 

### ~~Функция `imgui.ImPow`~~

 generic version

#### Сигнатура

```lua
function imgui.ImPow(a1: any, a2: any)
  -> number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImPow_Float`

#### Сигнатура

```lua
function imgui.ImPow_Float(x: number, y: number)
  -> float: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>x</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>y</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImPow_double`

#### Сигнатура

```lua
function imgui.ImPow_double(x: number, y: number)
  -> double: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>x</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>double</td>
    </tr>
    <tr>
      <td><code>y</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>double</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImQsort`

#### Сигнатура

```lua
function imgui.ImQsort(base: ffi.cdata*|ffi.cdecl*|ffi.ctype*, count: number, size_of_element: number, compare_func: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>base</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>void*</td>
    </tr>
    <tr>
      <td><code>count</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>size_t</td>
    </tr>
    <tr>
      <td><code>size_of_element</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>size_t</td>
    </tr>
    <tr>
      <td><code>compare_func</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>int(*)(void const*,void const*)</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ImRotate`

#### Сигнатура

```lua
function imgui.ImRotate(v: ImVec2, cos_a: number, sin_a: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>v</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>cos_a</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>sin_a</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### ~~Функция `imgui.ImRsqrt`~~

 generic version

#### Сигнатура

```lua
function imgui.ImRsqrt(a1: any)
  -> number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImRsqrt_Float`

#### Сигнатура

```lua
function imgui.ImRsqrt_Float(x: number)
  -> float: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>x</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImRsqrt_double`

#### Сигнатура

```lua
function imgui.ImRsqrt_double(x: number)
  -> double: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>x</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>double</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImSaturate`

#### Сигнатура

```lua
function imgui.ImSaturate(f: number)
  -> float: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>f</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### ~~Функция `imgui.ImSign`~~

 generic version

#### Сигнатура

```lua
function imgui.ImSign(a1: any)
  -> number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImSign_Float`

#### Сигнатура

```lua
function imgui.ImSign_Float(x: number)
  -> float: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>x</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImSign_double`

#### Сигнатура

```lua
function imgui.ImSign_double(x: number)
  -> double: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>x</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>double</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImStrSkipBlank`

#### Сигнатура

```lua
function imgui.ImStrSkipBlank(str: string)
  -> string
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>str</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `string` 

### Функция `imgui.ImStrTrimBlanks`

#### Сигнатура

```lua
function imgui.ImStrTrimBlanks(str: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>str</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>char*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ImStrbolW`

#### Сигнатура

```lua
function imgui.ImStrbolW(buf_mid_line: ffi.cdata*|ffi.cdecl*|ffi.ctype*, buf_begin: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> const: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>buf_mid_line</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImWchar*</td>
    </tr>
    <tr>
      <td><code>buf_begin</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImWchar*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.ImStrchrRange`

#### Сигнатура

```lua
function imgui.ImStrchrRange(str_begin: string, str_end: string, c: number)
  -> string
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>str_begin</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>str_end</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>c</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>char</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `string` 

### Функция `imgui.ImStrdup`

#### Сигнатура

```lua
function imgui.ImStrdup(str: string)
  -> char*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>str</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.ImStrdupcpy`

#### Сигнатура

```lua
function imgui.ImStrdupcpy(dst: ffi.cdata*|ffi.cdecl*|ffi.ctype*, p_dst_size: ffi.cdata*|ffi.cdecl*|ffi.ctype*, str: string)
  -> char*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>dst</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>char*</td>
    </tr>
    <tr>
      <td><code>p_dst_size</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>size_t*</td>
    </tr>
    <tr>
      <td><code>str</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.ImStreolRange`

#### Сигнатура

```lua
function imgui.ImStreolRange(str: string, str_end: string)
  -> string
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>str</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>str_end</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `string` 

### Функция `imgui.ImStricmp`

#### Сигнатура

```lua
function imgui.ImStricmp(str1: string, str2: string)
  -> int: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>str1</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>str2</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImStristr`

#### Сигнатура

```lua
function imgui.ImStristr(haystack: string, haystack_end: string, needle: string, needle_end: string)
  -> string
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>haystack</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>haystack_end</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>needle</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>needle_end</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `string` 

### Функция `imgui.ImStrlenW`

#### Сигнатура

```lua
function imgui.ImStrlenW(str: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> int: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>str</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImWchar*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImStrncpy`

#### Сигнатура

```lua
function imgui.ImStrncpy(dst: ffi.cdata*|ffi.cdecl*|ffi.ctype*, src: string, count: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>dst</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>char*</td>
    </tr>
    <tr>
      <td><code>src</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>count</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>size_t</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ImStrnicmp`

#### Сигнатура

```lua
function imgui.ImStrnicmp(str1: string, str2: string, count: number)
  -> int: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>str1</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>str2</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>count</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>size_t</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImTextCharFromUtf8`

#### Сигнатура

```lua
function imgui.ImTextCharFromUtf8(out_char: ffi.cdata*|ffi.cdecl*|ffi.ctype*, in_text: string, in_text_end: string)
  -> int: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>out_char</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>unsigned int*</td>
    </tr>
    <tr>
      <td><code>in_text</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>in_text_end</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImTextCharToUtf8`

#### Сигнатура

```lua
function imgui.ImTextCharToUtf8(out_buf: ffi.cdata*|ffi.cdecl*|ffi.ctype*, c: number)
  -> string
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>out_buf</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>char[5]</td>
    </tr>
    <tr>
      <td><code>c</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>unsigned int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `string` 

### Функция `imgui.ImTextCountCharsFromUtf8`

#### Сигнатура

```lua
function imgui.ImTextCountCharsFromUtf8(in_text: string, in_text_end: string)
  -> int: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>in_text</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>in_text_end</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImTextCountUtf8BytesFromChar`

#### Сигнатура

```lua
function imgui.ImTextCountUtf8BytesFromChar(in_text: string, in_text_end: string)
  -> int: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>in_text</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>in_text_end</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImTextCountUtf8BytesFromStr`

#### Сигнатура

```lua
function imgui.ImTextCountUtf8BytesFromStr(in_text: ffi.cdata*|ffi.cdecl*|ffi.ctype*, in_text_end: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> int: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>in_text</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImWchar*</td>
    </tr>
    <tr>
      <td><code>in_text_end</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImWchar*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImTextFindPreviousUtf8Codepoint`

#### Сигнатура

```lua
function imgui.ImTextFindPreviousUtf8Codepoint(in_text_start: string, in_text_curr: string)
  -> string
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>in_text_start</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>in_text_curr</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `string` 

### Функция `imgui.ImTextStrFromUtf8`

#### Сигнатура

```lua
function imgui.ImTextStrFromUtf8(out_buf: ffi.cdata*|ffi.cdecl*|ffi.ctype*, out_buf_size: number, in_text: string, in_text_end: string, in_remaining?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> int: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>out_buf</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImWchar*</td>
    </tr>
    <tr>
      <td><code>out_buf_size</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>in_text</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>in_text_end</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>in_remaining</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>const char**</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImTextStrToUtf8`

#### Сигнатура

```lua
function imgui.ImTextStrToUtf8(out_buf: ffi.cdata*|ffi.cdecl*|ffi.ctype*, out_buf_size: number, in_text: ffi.cdata*|ffi.cdecl*|ffi.ctype*, in_text_end: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> int: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>out_buf</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>char*</td>
    </tr>
    <tr>
      <td><code>out_buf_size</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>in_text</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImWchar*</td>
    </tr>
    <tr>
      <td><code>in_text_end</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImWchar*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImToUpper`

#### Сигнатура

```lua
function imgui.ImToUpper(c: number)
  -> char: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>c</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>char</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImTriangleArea`

#### Сигнатура

```lua
function imgui.ImTriangleArea(a: ImVec2, b: ImVec2, c: ImVec2)
  -> float: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>b</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>c</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImTriangleBarycentricCoords`

#### Сигнатура

```lua
function imgui.ImTriangleBarycentricCoords(a: ImVec2, b: ImVec2, c: ImVec2, p: ImVec2, out_u: ffi.cdata*|ffi.cdecl*|ffi.ctype*, out_v: ffi.cdata*|ffi.cdecl*|ffi.ctype*, out_w: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>b</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>c</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>out_u</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>float*</td>
    </tr>
    <tr>
      <td><code>out_v</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>float*</td>
    </tr>
    <tr>
      <td><code>out_w</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>float*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ImTriangleClosestPoint`

#### Сигнатура

```lua
function imgui.ImTriangleClosestPoint(a: ImVec2, b: ImVec2, c: ImVec2, p: ImVec2)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>b</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>c</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ImTriangleContainsPoint`

#### Сигнатура

```lua
function imgui.ImTriangleContainsPoint(a: ImVec2, b: ImVec2, c: ImVec2, p: ImVec2)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>b</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>c</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### ~~Функция `imgui.ImTrunc`~~

 generic version

#### Сигнатура

```lua
function imgui.ImTrunc(a1: any, a2: any)
  -> number|nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` или `nil` 

### Функция `imgui.ImTrunc_Float`

#### Сигнатура

```lua
function imgui.ImTrunc_Float(f: number)
  -> float: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>f</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.ImTrunc_Vec2`

#### Сигнатура

```lua
function imgui.ImTrunc_Vec2(v: ImVec2)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>v</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ImUpperPowerOfTwo`

#### Сигнатура

```lua
function imgui.ImUpperPowerOfTwo(v: number)
  -> int: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>v</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.Image`

#### Сигнатура

```lua
function imgui.Image(user_texture_id: number, image_size: ImVec2, uv0?: ImVec2, uv1?: ImVec2, tint_col?: ffi.cdata*|ffi.cdecl*|ffi.ctype*, border_col?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>user_texture_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImTextureID</td>
    </tr>
    <tr>
      <td><code>image_size</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>uv0</code></td>
      <td><code>ImVec2</code></td>
      <td>нет</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>uv1</code></td>
      <td><code>ImVec2</code></td>
      <td>нет</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>tint_col</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>const ImVec4</td>
    </tr>
    <tr>
      <td><code>border_col</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>const ImVec4</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ImageButton`

#### Сигнатура

```lua
function imgui.ImageButton(str_id: string, user_texture_id: number, image_size: ImVec2, uv0?: ImVec2, uv1?: ImVec2, bg_col?: ffi.cdata*|ffi.cdecl*|ffi.ctype*, tint_col?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>str_id</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>user_texture_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImTextureID</td>
    </tr>
    <tr>
      <td><code>image_size</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>uv0</code></td>
      <td><code>ImVec2</code></td>
      <td>нет</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>uv1</code></td>
      <td><code>ImVec2</code></td>
      <td>нет</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>bg_col</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>const ImVec4</td>
    </tr>
    <tr>
      <td><code>tint_col</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>const ImVec4</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.ImageButtonEx`

#### Сигнатура

```lua
function imgui.ImageButtonEx(id: number, texture_id: number, image_size: ImVec2, uv0: ImVec2, uv1: ImVec2, bg_col: ffi.cdata*|ffi.cdecl*|ffi.ctype*, tint_col: ffi.cdata*|ffi.cdecl*|ffi.ctype*, flags?: ButtonFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>texture_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImTextureID</td>
    </tr>
    <tr>
      <td><code>image_size</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>uv0</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>uv1</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>bg_col</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImVec4</td>
    </tr>
    <tr>
      <td><code>tint_col</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImVec4</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>ButtonFlags</code></td>
      <td>нет</td>
      <td>-----------------------ButtonFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.Indent`

#### Сигнатура

```lua
function imgui.Indent(indent_w?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>indent_w</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.Initialize`

#### Сигнатура

```lua
function imgui.Initialize()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.InputDouble`

#### Сигнатура

```lua
function imgui.InputDouble(label: string, v: ffi.cdata*|ffi.cdecl*|ffi.ctype*, step?: number, step_fast?: number, format?: string, flags?: InputTextFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>double*</td>
    </tr>
    <tr>
      <td><code>step</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>double</td>
    </tr>
    <tr>
      <td><code>step_fast</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>double</td>
    </tr>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>InputTextFlags</code></td>
      <td>нет</td>
      <td>-----------------------InputTextFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.InputFloat`

#### Сигнатура

```lua
function imgui.InputFloat(label: string, v: ffi.cdata*|ffi.cdecl*|ffi.ctype*, step?: number, step_fast?: number, format?: string, flags?: InputTextFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>float*</td>
    </tr>
    <tr>
      <td><code>step</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>step_fast</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>InputTextFlags</code></td>
      <td>нет</td>
      <td>-----------------------InputTextFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.InputFloat2`

#### Сигнатура

```lua
function imgui.InputFloat2(label: string, v: ffi.cdata*|ffi.cdecl*|ffi.ctype*, format?: string, flags?: InputTextFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>float[2]</td>
    </tr>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>InputTextFlags</code></td>
      <td>нет</td>
      <td>-----------------------InputTextFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.InputFloat3`

#### Сигнатура

```lua
function imgui.InputFloat3(label: string, v: ffi.cdata*|ffi.cdecl*|ffi.ctype*, format?: string, flags?: InputTextFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>float[3]</td>
    </tr>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>InputTextFlags</code></td>
      <td>нет</td>
      <td>-----------------------InputTextFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.InputFloat4`

#### Сигнатура

```lua
function imgui.InputFloat4(label: string, v: ffi.cdata*|ffi.cdecl*|ffi.ctype*, format?: string, flags?: InputTextFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>float[4]</td>
    </tr>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>InputTextFlags</code></td>
      <td>нет</td>
      <td>-----------------------InputTextFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.InputInt`

#### Сигнатура

```lua
function imgui.InputInt(label: string, v: ffi.cdata*|ffi.cdecl*|ffi.ctype*, step?: number, step_fast?: number, flags?: InputTextFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>int*</td>
    </tr>
    <tr>
      <td><code>step</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>step_fast</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>InputTextFlags</code></td>
      <td>нет</td>
      <td>-----------------------InputTextFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.InputInt2`

#### Сигнатура

```lua
function imgui.InputInt2(label: string, v: ffi.cdata*|ffi.cdecl*|ffi.ctype*, flags?: InputTextFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>int[2]</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>InputTextFlags</code></td>
      <td>нет</td>
      <td>-----------------------InputTextFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.InputInt3`

#### Сигнатура

```lua
function imgui.InputInt3(label: string, v: ffi.cdata*|ffi.cdecl*|ffi.ctype*, flags?: InputTextFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>int[3]</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>InputTextFlags</code></td>
      <td>нет</td>
      <td>-----------------------InputTextFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.InputInt4`

#### Сигнатура

```lua
function imgui.InputInt4(label: string, v: ffi.cdata*|ffi.cdecl*|ffi.ctype*, flags?: InputTextFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>int[4]</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>InputTextFlags</code></td>
      <td>нет</td>
      <td>-----------------------InputTextFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.InputScalar`

#### Сигнатура

```lua
function imgui.InputScalar(label: string, data_type: DataType, p_data: ffi.cdata*|ffi.cdecl*|ffi.ctype*, p_step?: ffi.cdata*|ffi.cdecl*|ffi.ctype*, p_step_fast?: ffi.cdata*|ffi.cdecl*|ffi.ctype*, format?: string, flags?: InputTextFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>data_type</code></td>
      <td><code>DataType</code></td>
      <td>да</td>
      <td>-----------------------DataType----------------------------</td>
    </tr>
    <tr>
      <td><code>p_data</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>void*</td>
    </tr>
    <tr>
      <td><code>p_step</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>const void*</td>
    </tr>
    <tr>
      <td><code>p_step_fast</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>const void*</td>
    </tr>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>InputTextFlags</code></td>
      <td>нет</td>
      <td>-----------------------InputTextFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.InputScalarN`

#### Сигнатура

```lua
function imgui.InputScalarN(label: string, data_type: DataType, p_data: ffi.cdata*|ffi.cdecl*|ffi.ctype*, components: number, p_step?: ffi.cdata*|ffi.cdecl*|ffi.ctype*, p_step_fast?: ffi.cdata*|ffi.cdecl*|ffi.ctype*, format?: string, flags?: InputTextFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>data_type</code></td>
      <td><code>DataType</code></td>
      <td>да</td>
      <td>-----------------------DataType----------------------------</td>
    </tr>
    <tr>
      <td><code>p_data</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>void*</td>
    </tr>
    <tr>
      <td><code>components</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>p_step</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>const void*</td>
    </tr>
    <tr>
      <td><code>p_step_fast</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>const void*</td>
    </tr>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>InputTextFlags</code></td>
      <td>нет</td>
      <td>-----------------------InputTextFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.InputText`

#### Сигнатура

```lua
function imgui.InputText(label: string, buf: ffi.cdata*|ffi.cdecl*|ffi.ctype*, buf_size: number, flags?: InputTextFlags, callback?: ffi.cdata*|ffi.cdecl*|ffi.ctype*, user_data?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>buf</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>char*</td>
    </tr>
    <tr>
      <td><code>buf_size</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>size_t</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>InputTextFlags</code></td>
      <td>нет</td>
      <td>-----------------------InputTextFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>callback</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>ImGuiInputTextCallback</td>
    </tr>
    <tr>
      <td><code>user_data</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>void*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.InputTextDeactivateHook`

#### Сигнатура

```lua
function imgui.InputTextDeactivateHook(id: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.InputTextEx`

#### Сигнатура

```lua
function imgui.InputTextEx(label: string, hint: string, buf: ffi.cdata*|ffi.cdecl*|ffi.ctype*, buf_size: number, size_arg: ImVec2, flags: InputTextFlags, callback?: ffi.cdata*|ffi.cdecl*|ffi.ctype*, user_data?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>hint</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>buf</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>char*</td>
    </tr>
    <tr>
      <td><code>buf_size</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>size_arg</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>InputTextFlags</code></td>
      <td>да</td>
      <td>-----------------------InputTextFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>callback</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>ImGuiInputTextCallback</td>
    </tr>
    <tr>
      <td><code>user_data</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>void*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.InputTextMultiline`

#### Сигнатура

```lua
function imgui.InputTextMultiline(label: string, buf: ffi.cdata*|ffi.cdecl*|ffi.ctype*, buf_size: number, size?: ImVec2, flags?: InputTextFlags, callback?: ffi.cdata*|ffi.cdecl*|ffi.ctype*, user_data?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>buf</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>char*</td>
    </tr>
    <tr>
      <td><code>buf_size</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>size_t</td>
    </tr>
    <tr>
      <td><code>size</code></td>
      <td><code>ImVec2</code></td>
      <td>нет</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>InputTextFlags</code></td>
      <td>нет</td>
      <td>-----------------------InputTextFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>callback</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>ImGuiInputTextCallback</td>
    </tr>
    <tr>
      <td><code>user_data</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>void*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.InputTextWithHint`

#### Сигнатура

```lua
function imgui.InputTextWithHint(label: string, hint: string, buf: ffi.cdata*|ffi.cdecl*|ffi.ctype*, buf_size: number, flags?: InputTextFlags, callback?: ffi.cdata*|ffi.cdecl*|ffi.ctype*, user_data?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>hint</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>buf</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>char*</td>
    </tr>
    <tr>
      <td><code>buf_size</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>size_t</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>InputTextFlags</code></td>
      <td>нет</td>
      <td>-----------------------InputTextFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>callback</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>ImGuiInputTextCallback</td>
    </tr>
    <tr>
      <td><code>user_data</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>void*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.InvisibleButton`

#### Сигнатура

```lua
function imgui.InvisibleButton(str_id: string, size: ImVec2, flags?: ButtonFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>str_id</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>size</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>ButtonFlags</code></td>
      <td>нет</td>
      <td>-----------------------ButtonFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsActiveIdUsingNavDir`

#### Сигнатура

```lua
function imgui.IsActiveIdUsingNavDir(dir: Dir)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>dir</code></td>
      <td><code>Dir</code></td>
      <td>да</td>
      <td>-----------------------Dir----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsAliasKey`

#### Сигнатура

```lua
function imgui.IsAliasKey(key: Key)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>Key</code></td>
      <td>да</td>
      <td>-----------------------Key----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsAnyItemActive`

#### Сигнатура

```lua
function imgui.IsAnyItemActive()
  -> boolean
```

#### Возвращает

- `boolean` 

### Функция `imgui.IsAnyItemFocused`

#### Сигнатура

```lua
function imgui.IsAnyItemFocused()
  -> boolean
```

#### Возвращает

- `boolean` 

### Функция `imgui.IsAnyItemHovered`

#### Сигнатура

```lua
function imgui.IsAnyItemHovered()
  -> boolean
```

#### Возвращает

- `boolean` 

### Функция `imgui.IsAnyMouseDown`

#### Сигнатура

```lua
function imgui.IsAnyMouseDown()
  -> boolean
```

#### Возвращает

- `boolean` 

### Функция `imgui.IsClippedEx`

#### Сигнатура

```lua
function imgui.IsClippedEx(bb: ImRect, id: number)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>bb</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsDragDropActive`

#### Сигнатура

```lua
function imgui.IsDragDropActive()
  -> boolean
```

#### Возвращает

- `boolean` 

### Функция `imgui.IsDragDropPayloadBeingAccepted`

#### Сигнатура

```lua
function imgui.IsDragDropPayloadBeingAccepted()
  -> boolean
```

#### Возвращает

- `boolean` 

### Функция `imgui.IsGamepadKey`

#### Сигнатура

```lua
function imgui.IsGamepadKey(key: Key)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>Key</code></td>
      <td>да</td>
      <td>-----------------------Key----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsItemActivated`

#### Сигнатура

```lua
function imgui.IsItemActivated()
  -> boolean
```

#### Возвращает

- `boolean` 

### Функция `imgui.IsItemActive`

#### Сигнатура

```lua
function imgui.IsItemActive()
  -> boolean
```

#### Возвращает

- `boolean` 

### Функция `imgui.IsItemClicked`

#### Сигнатура

```lua
function imgui.IsItemClicked(mouse_button?: MouseButton)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>mouse_button</code></td>
      <td><code>MouseButton</code></td>
      <td>нет</td>
      <td>-----------------------MouseButton----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsItemDeactivated`

#### Сигнатура

```lua
function imgui.IsItemDeactivated()
  -> boolean
```

#### Возвращает

- `boolean` 

### Функция `imgui.IsItemDeactivatedAfterEdit`

#### Сигнатура

```lua
function imgui.IsItemDeactivatedAfterEdit()
  -> boolean
```

#### Возвращает

- `boolean` 

### Функция `imgui.IsItemEdited`

#### Сигнатура

```lua
function imgui.IsItemEdited()
  -> boolean
```

#### Возвращает

- `boolean` 

### Функция `imgui.IsItemFocused`

#### Сигнатура

```lua
function imgui.IsItemFocused()
  -> boolean
```

#### Возвращает

- `boolean` 

### Функция `imgui.IsItemHovered`

#### Сигнатура

```lua
function imgui.IsItemHovered(flags?: HoveredFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>flags</code></td>
      <td><code>HoveredFlags</code></td>
      <td>нет</td>
      <td>-----------------------HoveredFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsItemToggledOpen`

#### Сигнатура

```lua
function imgui.IsItemToggledOpen()
  -> boolean
```

#### Возвращает

- `boolean` 

### Функция `imgui.IsItemToggledSelection`

#### Сигнатура

```lua
function imgui.IsItemToggledSelection()
  -> boolean
```

#### Возвращает

- `boolean` 

### Функция `imgui.IsItemVisible`

#### Сигнатура

```lua
function imgui.IsItemVisible()
  -> boolean
```

#### Возвращает

- `boolean` 

### ~~Функция `imgui.IsKeyChordPressed`~~

 generic version

#### Сигнатура

```lua
function imgui.IsKeyChordPressed(a1: any, a2: any, a3: any)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a3</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsKeyChordPressed_ID`

#### Сигнатура

```lua
function imgui.IsKeyChordPressed_ID(key_chord: number, owner_id: number, flags?: InputFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key_chord</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiKeyChord</td>
    </tr>
    <tr>
      <td><code>owner_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>InputFlags</code></td>
      <td>нет</td>
      <td>-----------------------InputFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsKeyChordPressed_Nil`

#### Сигнатура

```lua
function imgui.IsKeyChordPressed_Nil(key_chord: number)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key_chord</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiKeyChord</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### ~~Функция `imgui.IsKeyDown`~~

 generic version

#### Сигнатура

```lua
function imgui.IsKeyDown(a1: any, a2: any)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsKeyDown_ID`

#### Сигнатура

```lua
function imgui.IsKeyDown_ID(key: Key, owner_id: number)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>Key</code></td>
      <td>да</td>
      <td>-----------------------Key----------------------------</td>
    </tr>
    <tr>
      <td><code>owner_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsKeyDown_Nil`

#### Сигнатура

```lua
function imgui.IsKeyDown_Nil(key: Key)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>Key</code></td>
      <td>да</td>
      <td>-----------------------Key----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### ~~Функция `imgui.IsKeyPressed`~~

 generic version

#### Сигнатура

```lua
function imgui.IsKeyPressed(a1: any, a2: any, a3: any)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a3</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsKeyPressed_Bool`

#### Сигнатура

```lua
function imgui.IsKeyPressed_Bool(key: Key, _repeat: boolean)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>Key</code></td>
      <td>да</td>
      <td>-----------------------Key----------------------------</td>
    </tr>
    <tr>
      <td><code>_repeat</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsKeyPressed_ID`

#### Сигнатура

```lua
function imgui.IsKeyPressed_ID(key: Key, owner_id: number, flags?: InputFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>Key</code></td>
      <td>да</td>
      <td>-----------------------Key----------------------------</td>
    </tr>
    <tr>
      <td><code>owner_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>InputFlags</code></td>
      <td>нет</td>
      <td>-----------------------InputFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### ~~Функция `imgui.IsKeyReleased`~~

 generic version

#### Сигнатура

```lua
function imgui.IsKeyReleased(a1: any, a2: any)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsKeyReleased_ID`

#### Сигнатура

```lua
function imgui.IsKeyReleased_ID(key: Key, owner_id: number)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>Key</code></td>
      <td>да</td>
      <td>-----------------------Key----------------------------</td>
    </tr>
    <tr>
      <td><code>owner_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsKeyReleased_Nil`

#### Сигнатура

```lua
function imgui.IsKeyReleased_Nil(key: Key)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>Key</code></td>
      <td>да</td>
      <td>-----------------------Key----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsKeyboardKey`

#### Сигнатура

```lua
function imgui.IsKeyboardKey(key: Key)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>Key</code></td>
      <td>да</td>
      <td>-----------------------Key----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsLegacyKey`

#### Сигнатура

```lua
function imgui.IsLegacyKey(key: Key)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>Key</code></td>
      <td>да</td>
      <td>-----------------------Key----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsModKey`

#### Сигнатура

```lua
function imgui.IsModKey(key: Key)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>Key</code></td>
      <td>да</td>
      <td>-----------------------Key----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### ~~Функция `imgui.IsMouseClicked`~~

 generic version

#### Сигнатура

```lua
function imgui.IsMouseClicked(a1: any, a2: any, a3: any)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a3</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsMouseClicked_Bool`

#### Сигнатура

```lua
function imgui.IsMouseClicked_Bool(button: MouseButton, _repeat: boolean)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>button</code></td>
      <td><code>MouseButton</code></td>
      <td>да</td>
      <td>-----------------------MouseButton----------------------------</td>
    </tr>
    <tr>
      <td><code>_repeat</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsMouseClicked_ID`

#### Сигнатура

```lua
function imgui.IsMouseClicked_ID(button: MouseButton, owner_id: number, flags?: InputFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>button</code></td>
      <td><code>MouseButton</code></td>
      <td>да</td>
      <td>-----------------------MouseButton----------------------------</td>
    </tr>
    <tr>
      <td><code>owner_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>InputFlags</code></td>
      <td>нет</td>
      <td>-----------------------InputFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### ~~Функция `imgui.IsMouseDoubleClicked`~~

 generic version

#### Сигнатура

```lua
function imgui.IsMouseDoubleClicked(a1: any, a2: any)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsMouseDoubleClicked_ID`

#### Сигнатура

```lua
function imgui.IsMouseDoubleClicked_ID(button: MouseButton, owner_id: number)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>button</code></td>
      <td><code>MouseButton</code></td>
      <td>да</td>
      <td>-----------------------MouseButton----------------------------</td>
    </tr>
    <tr>
      <td><code>owner_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsMouseDoubleClicked_Nil`

#### Сигнатура

```lua
function imgui.IsMouseDoubleClicked_Nil(button: MouseButton)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>button</code></td>
      <td><code>MouseButton</code></td>
      <td>да</td>
      <td>-----------------------MouseButton----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### ~~Функция `imgui.IsMouseDown`~~

 generic version

#### Сигнатура

```lua
function imgui.IsMouseDown(a1: any, a2: any)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsMouseDown_ID`

#### Сигнатура

```lua
function imgui.IsMouseDown_ID(button: MouseButton, owner_id: number)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>button</code></td>
      <td><code>MouseButton</code></td>
      <td>да</td>
      <td>-----------------------MouseButton----------------------------</td>
    </tr>
    <tr>
      <td><code>owner_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsMouseDown_Nil`

#### Сигнатура

```lua
function imgui.IsMouseDown_Nil(button: MouseButton)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>button</code></td>
      <td><code>MouseButton</code></td>
      <td>да</td>
      <td>-----------------------MouseButton----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsMouseDragPastThreshold`

#### Сигнатура

```lua
function imgui.IsMouseDragPastThreshold(button: MouseButton, lock_threshold?: number)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>button</code></td>
      <td><code>MouseButton</code></td>
      <td>да</td>
      <td>-----------------------MouseButton----------------------------</td>
    </tr>
    <tr>
      <td><code>lock_threshold</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsMouseDragging`

#### Сигнатура

```lua
function imgui.IsMouseDragging(button: MouseButton, lock_threshold?: number)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>button</code></td>
      <td><code>MouseButton</code></td>
      <td>да</td>
      <td>-----------------------MouseButton----------------------------</td>
    </tr>
    <tr>
      <td><code>lock_threshold</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsMouseHoveringRect`

#### Сигнатура

```lua
function imgui.IsMouseHoveringRect(r_min: ImVec2, r_max: ImVec2, clip?: boolean)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>r_min</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>r_max</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>clip</code></td>
      <td><code>boolean</code></td>
      <td>нет</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsMouseKey`

#### Сигнатура

```lua
function imgui.IsMouseKey(key: Key)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>Key</code></td>
      <td>да</td>
      <td>-----------------------Key----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsMousePosValid`

#### Сигнатура

```lua
function imgui.IsMousePosValid(mouse_pos?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>mouse_pos</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>const ImVec2*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### ~~Функция `imgui.IsMouseReleased`~~

 generic version

#### Сигнатура

```lua
function imgui.IsMouseReleased(a1: any, a2: any)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsMouseReleased_ID`

#### Сигнатура

```lua
function imgui.IsMouseReleased_ID(button: MouseButton, owner_id: number)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>button</code></td>
      <td><code>MouseButton</code></td>
      <td>да</td>
      <td>-----------------------MouseButton----------------------------</td>
    </tr>
    <tr>
      <td><code>owner_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsMouseReleased_Nil`

#### Сигнатура

```lua
function imgui.IsMouseReleased_Nil(button: MouseButton)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>button</code></td>
      <td><code>MouseButton</code></td>
      <td>да</td>
      <td>-----------------------MouseButton----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsNamedKey`

#### Сигнатура

```lua
function imgui.IsNamedKey(key: Key)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>Key</code></td>
      <td>да</td>
      <td>-----------------------Key----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsNamedKeyOrModKey`

#### Сигнатура

```lua
function imgui.IsNamedKeyOrModKey(key: Key)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>Key</code></td>
      <td>да</td>
      <td>-----------------------Key----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### ~~Функция `imgui.IsPopupOpen`~~

 generic version

#### Сигнатура

```lua
function imgui.IsPopupOpen(a1: any, a2: any)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsPopupOpen_ID`

#### Сигнатура

```lua
function imgui.IsPopupOpen_ID(id: number, popup_flags: PopupFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>popup_flags</code></td>
      <td><code>PopupFlags</code></td>
      <td>да</td>
      <td>-----------------------PopupFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsPopupOpen_Str`

#### Сигнатура

```lua
function imgui.IsPopupOpen_Str(str_id: string, flags?: PopupFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>str_id</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>PopupFlags</code></td>
      <td>нет</td>
      <td>-----------------------PopupFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### ~~Функция `imgui.IsRectVisible`~~

 generic version

#### Сигнатура

```lua
function imgui.IsRectVisible(a1: any, a2: any)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsRectVisible_Nil`

#### Сигнатура

```lua
function imgui.IsRectVisible_Nil(size: ImVec2)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>size</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsRectVisible_Vec2`

#### Сигнатура

```lua
function imgui.IsRectVisible_Vec2(rect_min: ImVec2, rect_max: ImVec2)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>rect_min</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>rect_max</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsWindowAbove`

#### Сигнатура

```lua
function imgui.IsWindowAbove(potential_above: ffi.cdata*|ffi.cdecl*|ffi.ctype*, potential_below: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>potential_above</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>potential_below</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsWindowAppearing`

#### Сигнатура

```lua
function imgui.IsWindowAppearing()
  -> boolean
```

#### Возвращает

- `boolean` 

### Функция `imgui.IsWindowChildOf`

#### Сигнатура

```lua
function imgui.IsWindowChildOf(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, potential_parent: ffi.cdata*|ffi.cdecl*|ffi.ctype*, popup_hierarchy: boolean, dock_hierarchy: boolean)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>potential_parent</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>popup_hierarchy</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>dock_hierarchy</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsWindowCollapsed`

#### Сигнатура

```lua
function imgui.IsWindowCollapsed()
  -> boolean
```

#### Возвращает

- `boolean` 

### Функция `imgui.IsWindowContentHoverable`

#### Сигнатура

```lua
function imgui.IsWindowContentHoverable(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, flags?: HoveredFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>HoveredFlags</code></td>
      <td>нет</td>
      <td>-----------------------HoveredFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsWindowDocked`

#### Сигнатура

```lua
function imgui.IsWindowDocked()
  -> boolean
```

#### Возвращает

- `boolean` 

### Функция `imgui.IsWindowFocused`

#### Сигнатура

```lua
function imgui.IsWindowFocused(flags?: FocusedFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>flags</code></td>
      <td><code>FocusedFlags</code></td>
      <td>нет</td>
      <td>-----------------------FocusedFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsWindowHovered`

#### Сигнатура

```lua
function imgui.IsWindowHovered(flags?: HoveredFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>flags</code></td>
      <td><code>HoveredFlags</code></td>
      <td>нет</td>
      <td>-----------------------HoveredFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsWindowNavFocusable`

#### Сигнатура

```lua
function imgui.IsWindowNavFocusable(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.IsWindowWithinBeginStackOf`

#### Сигнатура

```lua
function imgui.IsWindowWithinBeginStackOf(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, potential_parent: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>potential_parent</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.ItemAdd`

#### Сигнатура

```lua
function imgui.ItemAdd(bb: ImRect, id: number, nav_bb?: ffi.cdata*|ffi.cdecl*|ffi.ctype*, extra_flags?: ItemFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>bb</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>nav_bb</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>const ImRect*</td>
    </tr>
    <tr>
      <td><code>extra_flags</code></td>
      <td><code>ItemFlags</code></td>
      <td>нет</td>
      <td>-----------------------ItemFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.ItemHoverable`

#### Сигнатура

```lua
function imgui.ItemHoverable(bb: ImRect, id: number, item_flags: ItemFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>bb</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>item_flags</code></td>
      <td><code>ItemFlags</code></td>
      <td>да</td>
      <td>-----------------------ItemFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### ~~Функция `imgui.ItemSize`~~

 generic version

#### Сигнатура

```lua
function imgui.ItemSize(a1: any, a2: any)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ItemSize_Rect`

#### Сигнатура

```lua
function imgui.ItemSize_Rect(bb: ImRect, text_baseline_y?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>bb</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
    <tr>
      <td><code>text_baseline_y</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ItemSize_Vec2`

#### Сигнатура

```lua
function imgui.ItemSize_Vec2(size: ImVec2, text_baseline_y?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>size</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>text_baseline_y</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.KeepAliveID`

#### Сигнатура

```lua
function imgui.KeepAliveID(id: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.LabelText`

#### Сигнатура

```lua
function imgui.LabelText(label: string, fmt: string, ...any)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>fmt</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>...</code></td>
      <td><code>unknown</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.LabelTextV`

#### Сигнатура

```lua
function imgui.LabelTextV(label: string, fmt: string, args: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>fmt</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>args</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>va_list</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### ~~Функция `imgui.ListBox`~~

 generic version

#### Сигнатура

```lua
function imgui.ListBox(a1: any, a2: any, a3: any, a4: any, a5: any, a6: any)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a3</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a4</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a5</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a6</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.ListBox_FnStrPtr`

#### Сигнатура

```lua
function imgui.ListBox_FnStrPtr(label: string, current_item: ffi.cdata*|ffi.cdecl*|ffi.ctype*, getter: ffi.cdata*|ffi.cdecl*|ffi.ctype*, user_data: ffi.cdata*|ffi.cdecl*|ffi.ctype*, items_count: number, height_in_items?: number)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>current_item</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>int*</td>
    </tr>
    <tr>
      <td><code>getter</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const char*(*)(void* user_data,int idx)</td>
    </tr>
    <tr>
      <td><code>user_data</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>void*</td>
    </tr>
    <tr>
      <td><code>items_count</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>height_in_items</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.ListBox_Str_arr`

#### Сигнатура

```lua
function imgui.ListBox_Str_arr(label: string, current_item: ffi.cdata*|ffi.cdecl*|ffi.ctype*, items: ffi.cdata*|ffi.cdecl*|ffi.ctype*, items_count: number, height_in_items?: number)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>current_item</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>int*</td>
    </tr>
    <tr>
      <td><code>items</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const char* const[]</td>
    </tr>
    <tr>
      <td><code>items_count</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>height_in_items</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.LoadIniSettingsFromDisk`

#### Сигнатура

```lua
function imgui.LoadIniSettingsFromDisk(ini_filename: string)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ini_filename</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.LoadIniSettingsFromMemory`

#### Сигнатура

```lua
function imgui.LoadIniSettingsFromMemory(ini_data: string, ini_size?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ini_data</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>ini_size</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>size_t</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.LocalizeGetMsg`

#### Сигнатура

```lua
function imgui.LocalizeGetMsg(key: LocKey)
  -> string
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>LocKey</code></td>
      <td>да</td>
      <td>-----------------------LocKey----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `string` 

### Функция `imgui.LocalizeRegisterEntries`

#### Сигнатура

```lua
function imgui.LocalizeRegisterEntries(entries: ffi.cdata*|ffi.cdecl*|ffi.ctype*, count: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>entries</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImGuiLocEntry*</td>
    </tr>
    <tr>
      <td><code>count</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.LogBegin`

#### Сигнатура

```lua
function imgui.LogBegin(type: LogType, auto_open_depth: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>type</code></td>
      <td><code>LogType</code></td>
      <td>да</td>
      <td>-----------------------LogType----------------------------</td>
    </tr>
    <tr>
      <td><code>auto_open_depth</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.LogButtons`

#### Сигнатура

```lua
function imgui.LogButtons()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.LogFinish`

#### Сигнатура

```lua
function imgui.LogFinish()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.LogRenderedText`

#### Сигнатура

```lua
function imgui.LogRenderedText(ref_pos: ffi.cdata*|ffi.cdecl*|ffi.ctype*, text: string, text_end?: string)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ref_pos</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImVec2*</td>
    </tr>
    <tr>
      <td><code>text</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>text_end</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.LogSetNextTextDecoration`

#### Сигнатура

```lua
function imgui.LogSetNextTextDecoration(prefix: string, suffix: string)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>prefix</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>suffix</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.LogText`

#### Сигнатура

```lua
function imgui.LogText(fmt: string, ...any)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>fmt</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>...</code></td>
      <td><code>unknown</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.LogTextV`

#### Сигнатура

```lua
function imgui.LogTextV(fmt: string, args: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>fmt</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>args</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>va_list</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.LogToBuffer`

#### Сигнатура

```lua
function imgui.LogToBuffer(auto_open_depth?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>auto_open_depth</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.LogToClipboard`

#### Сигнатура

```lua
function imgui.LogToClipboard(auto_open_depth?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>auto_open_depth</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.LogToFile`

#### Сигнатура

```lua
function imgui.LogToFile(auto_open_depth?: number, filename?: string)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>auto_open_depth</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>filename</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.LogToTTY`

#### Сигнатура

```lua
function imgui.LogToTTY(auto_open_depth?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>auto_open_depth</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### ~~Функция `imgui.MarkIniSettingsDirty`~~

 generic version

#### Сигнатура

```lua
function imgui.MarkIniSettingsDirty(a1: any)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.MarkIniSettingsDirty_Nil`

#### Сигнатура

```lua
function imgui.MarkIniSettingsDirty_Nil()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.MarkIniSettingsDirty_WindowPtr`

#### Сигнатура

```lua
function imgui.MarkIniSettingsDirty_WindowPtr(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.MarkItemEdited`

#### Сигнатура

```lua
function imgui.MarkItemEdited(id: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.MemAlloc`

#### Сигнатура

```lua
function imgui.MemAlloc(size: number)
  -> void*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>size</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>size_t</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.MemFree`

#### Сигнатура

```lua
function imgui.MemFree(ptr: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ptr</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>void*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### ~~Функция `imgui.MenuItem`~~

 generic version

#### Сигнатура

```lua
function imgui.MenuItem(a1: any, a2: any, a3: any, a4: any)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a3</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a4</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.MenuItemEx`

#### Сигнатура

```lua
function imgui.MenuItemEx(label: string, icon: string, shortcut?: string, selected?: boolean, enabled?: boolean)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>icon</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>shortcut</code></td>
      <td><code>string</code></td>
      <td>нет</td>
    </tr>
    <tr>
      <td><code>selected</code></td>
      <td><code>boolean</code></td>
      <td>нет</td>
    </tr>
    <tr>
      <td><code>enabled</code></td>
      <td><code>boolean</code></td>
      <td>нет</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.MenuItem_Bool`

#### Сигнатура

```lua
function imgui.MenuItem_Bool(label: string, shortcut?: string, selected?: boolean, enabled?: boolean)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>shortcut</code></td>
      <td><code>string</code></td>
      <td>нет</td>
    </tr>
    <tr>
      <td><code>selected</code></td>
      <td><code>boolean</code></td>
      <td>нет</td>
    </tr>
    <tr>
      <td><code>enabled</code></td>
      <td><code>boolean</code></td>
      <td>нет</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.MenuItem_BoolPtr`

#### Сигнатура

```lua
function imgui.MenuItem_BoolPtr(label: string, shortcut: string, p_selected: ffi.cdata*|ffi.cdecl*|ffi.ctype*, enabled?: boolean)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>shortcut</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>p_selected</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>bool*</td>
    </tr>
    <tr>
      <td><code>enabled</code></td>
      <td><code>boolean</code></td>
      <td>нет</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.MouseButtonToKey`

#### Сигнатура

```lua
function imgui.MouseButtonToKey(button: MouseButton)
  -> Key
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>button</code></td>
      <td><code>MouseButton</code></td>
      <td>да</td>
      <td>-----------------------MouseButton----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `Key` 

### Функция `imgui.NavClearPreferredPosForAxis`

#### Сигнатура

```lua
function imgui.NavClearPreferredPosForAxis(axis: Axis)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>axis</code></td>
      <td><code>Axis</code></td>
      <td>да</td>
      <td>-----------------------Axis----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.NavHighlightActivated`

#### Сигнатура

```lua
function imgui.NavHighlightActivated(id: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.NavInitRequestApplyResult`

#### Сигнатура

```lua
function imgui.NavInitRequestApplyResult()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.NavInitWindow`

#### Сигнатура

```lua
function imgui.NavInitWindow(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, force_reinit: boolean)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>force_reinit</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.NavMoveRequestApplyResult`

#### Сигнатура

```lua
function imgui.NavMoveRequestApplyResult()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.NavMoveRequestButNoResultYet`

#### Сигнатура

```lua
function imgui.NavMoveRequestButNoResultYet()
  -> boolean
```

#### Возвращает

- `boolean` 

### Функция `imgui.NavMoveRequestCancel`

#### Сигнатура

```lua
function imgui.NavMoveRequestCancel()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.NavMoveRequestForward`

#### Сигнатура

```lua
function imgui.NavMoveRequestForward(move_dir: Dir, clip_dir: Dir, move_flags: NavMoveFlags, scroll_flags: ScrollFlags)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>move_dir</code></td>
      <td><code>Dir</code></td>
      <td>да</td>
      <td>-----------------------Dir----------------------------</td>
    </tr>
    <tr>
      <td><code>clip_dir</code></td>
      <td><code>Dir</code></td>
      <td>да</td>
      <td>-----------------------Dir----------------------------</td>
    </tr>
    <tr>
      <td><code>move_flags</code></td>
      <td><code>NavMoveFlags</code></td>
      <td>да</td>
      <td>-----------------------NavMoveFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>scroll_flags</code></td>
      <td><code>ScrollFlags</code></td>
      <td>да</td>
      <td>-----------------------ScrollFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.NavMoveRequestResolveWithLastItem`

#### Сигнатура

```lua
function imgui.NavMoveRequestResolveWithLastItem(result: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>result</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiNavItemData*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.NavMoveRequestResolveWithPastTreeNode`

#### Сигнатура

```lua
function imgui.NavMoveRequestResolveWithPastTreeNode(result: ffi.cdata*|ffi.cdecl*|ffi.ctype*, tree_node_data: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>result</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiNavItemData*</td>
    </tr>
    <tr>
      <td><code>tree_node_data</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiNavTreeNodeData*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.NavMoveRequestSubmit`

#### Сигнатура

```lua
function imgui.NavMoveRequestSubmit(move_dir: Dir, clip_dir: Dir, move_flags: NavMoveFlags, scroll_flags: ScrollFlags)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>move_dir</code></td>
      <td><code>Dir</code></td>
      <td>да</td>
      <td>-----------------------Dir----------------------------</td>
    </tr>
    <tr>
      <td><code>clip_dir</code></td>
      <td><code>Dir</code></td>
      <td>да</td>
      <td>-----------------------Dir----------------------------</td>
    </tr>
    <tr>
      <td><code>move_flags</code></td>
      <td><code>NavMoveFlags</code></td>
      <td>да</td>
      <td>-----------------------NavMoveFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>scroll_flags</code></td>
      <td><code>ScrollFlags</code></td>
      <td>да</td>
      <td>-----------------------ScrollFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.NavMoveRequestTryWrapping`

#### Сигнатура

```lua
function imgui.NavMoveRequestTryWrapping(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, move_flags: NavMoveFlags)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>move_flags</code></td>
      <td><code>NavMoveFlags</code></td>
      <td>да</td>
      <td>-----------------------NavMoveFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.NavRestoreHighlightAfterMove`

#### Сигнатура

```lua
function imgui.NavRestoreHighlightAfterMove()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.NavUpdateCurrentWindowIsScrollPushableX`

#### Сигнатура

```lua
function imgui.NavUpdateCurrentWindowIsScrollPushableX()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.NewFrame`

#### Сигнатура

```lua
function imgui.NewFrame()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.NewLine`

#### Сигнатура

```lua
function imgui.NewLine()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.NextColumn`

#### Сигнатура

```lua
function imgui.NextColumn()
  -> nil
```

#### Возвращает

- `nil` 

### ~~Функция `imgui.OpenPopup`~~

 generic version

#### Сигнатура

```lua
function imgui.OpenPopup(a1: any, a2: any)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.OpenPopupEx`

#### Сигнатура

```lua
function imgui.OpenPopupEx(id: number, popup_flags?: PopupFlags)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>popup_flags</code></td>
      <td><code>PopupFlags</code></td>
      <td>нет</td>
      <td>-----------------------PopupFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.OpenPopupOnItemClick`

#### Сигнатура

```lua
function imgui.OpenPopupOnItemClick(str_id?: string, popup_flags?: PopupFlags)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>str_id</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>popup_flags</code></td>
      <td><code>PopupFlags</code></td>
      <td>нет</td>
      <td>-----------------------PopupFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.OpenPopup_ID`

#### Сигнатура

```lua
function imgui.OpenPopup_ID(id: number, popup_flags?: PopupFlags)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>popup_flags</code></td>
      <td><code>PopupFlags</code></td>
      <td>нет</td>
      <td>-----------------------PopupFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.OpenPopup_Str`

#### Сигнатура

```lua
function imgui.OpenPopup_Str(str_id: string, popup_flags?: PopupFlags)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>str_id</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>popup_flags</code></td>
      <td><code>PopupFlags</code></td>
      <td>нет</td>
      <td>-----------------------PopupFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.PlotEx`

#### Сигнатура

```lua
function imgui.PlotEx(plot_type: PlotType, label: string, values_getter: ffi.cdata*|ffi.cdecl*|ffi.ctype*, data: ffi.cdata*|ffi.cdecl*|ffi.ctype*, values_count: number, values_offset: number, overlay_text: string, scale_min: number, scale_max: number, size_arg: ImVec2)
  -> int: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>plot_type</code></td>
      <td><code>PlotType</code></td>
      <td>да</td>
      <td>-----------------------PlotType----------------------------</td>
    </tr>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>values_getter</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>float(*)(void* data,int idx)</td>
    </tr>
    <tr>
      <td><code>data</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>void*</td>
    </tr>
    <tr>
      <td><code>values_count</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>values_offset</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>overlay_text</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>scale_min</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>scale_max</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>size_arg</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### ~~Функция `imgui.PlotHistogram`~~

 generic version

#### Сигнатура

```lua
function imgui.PlotHistogram(a1: any, a2: any, a3: any, a4: any, a5: any, a6: any, a7: any, a8: any, a9: any)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a3</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a4</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a5</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a6</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a7</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a8</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a9</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.PlotHistogram_FloatPtr`

#### Сигнатура

```lua
function imgui.PlotHistogram_FloatPtr(label: string, values: ffi.cdata*|ffi.cdecl*|ffi.ctype*, values_count: number, values_offset?: number, overlay_text?: string, scale_min?: number, scale_max?: number, graph_size?: ImVec2, stride?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>values</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const float*</td>
    </tr>
    <tr>
      <td><code>values_count</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>values_offset</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>overlay_text</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>scale_min</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>scale_max</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>graph_size</code></td>
      <td><code>ImVec2</code></td>
      <td>нет</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>stride</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.PlotHistogram_FnFloatPtr`

#### Сигнатура

```lua
function imgui.PlotHistogram_FnFloatPtr(label: string, values_getter: ffi.cdata*|ffi.cdecl*|ffi.ctype*, data: ffi.cdata*|ffi.cdecl*|ffi.ctype*, values_count: number, values_offset?: number, overlay_text?: string, scale_min?: number, scale_max?: number, graph_size?: ImVec2)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>values_getter</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>float(*)(void* data,int idx)</td>
    </tr>
    <tr>
      <td><code>data</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>void*</td>
    </tr>
    <tr>
      <td><code>values_count</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>values_offset</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>overlay_text</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>scale_min</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>scale_max</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>graph_size</code></td>
      <td><code>ImVec2</code></td>
      <td>нет</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### ~~Функция `imgui.PlotLines`~~

 generic version

#### Сигнатура

```lua
function imgui.PlotLines(a1: any, a2: any, a3: any, a4: any, a5: any, a6: any, a7: any, a8: any, a9: any)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a3</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a4</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a5</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a6</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a7</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a8</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a9</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.PlotLines_FloatPtr`

#### Сигнатура

```lua
function imgui.PlotLines_FloatPtr(label: string, values: ffi.cdata*|ffi.cdecl*|ffi.ctype*, values_count: number, values_offset?: number, overlay_text?: string, scale_min?: number, scale_max?: number, graph_size?: ImVec2, stride?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>values</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const float*</td>
    </tr>
    <tr>
      <td><code>values_count</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>values_offset</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>overlay_text</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>scale_min</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>scale_max</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>graph_size</code></td>
      <td><code>ImVec2</code></td>
      <td>нет</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>stride</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.PlotLines_FnFloatPtr`

#### Сигнатура

```lua
function imgui.PlotLines_FnFloatPtr(label: string, values_getter: ffi.cdata*|ffi.cdecl*|ffi.ctype*, data: ffi.cdata*|ffi.cdecl*|ffi.ctype*, values_count: number, values_offset?: number, overlay_text?: string, scale_min?: number, scale_max?: number, graph_size?: ImVec2)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>values_getter</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>float(*)(void* data,int idx)</td>
    </tr>
    <tr>
      <td><code>data</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>void*</td>
    </tr>
    <tr>
      <td><code>values_count</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>values_offset</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>overlay_text</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>scale_min</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>scale_max</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>graph_size</code></td>
      <td><code>ImVec2</code></td>
      <td>нет</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.PopButtonRepeat`

#### Сигнатура

```lua
function imgui.PopButtonRepeat()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.PopClipRect`

#### Сигнатура

```lua
function imgui.PopClipRect()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.PopColumnsBackground`

#### Сигнатура

```lua
function imgui.PopColumnsBackground()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.PopFocusScope`

#### Сигнатура

```lua
function imgui.PopFocusScope()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.PopFont`

#### Сигнатура

```lua
function imgui.PopFont()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.PopID`

#### Сигнатура

```lua
function imgui.PopID()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.PopItemFlag`

#### Сигнатура

```lua
function imgui.PopItemFlag()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.PopItemWidth`

#### Сигнатура

```lua
function imgui.PopItemWidth()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.PopStyleColor`

#### Сигнатура

```lua
function imgui.PopStyleColor(count?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>count</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.PopStyleVar`

#### Сигнатура

```lua
function imgui.PopStyleVar(count?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>count</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.PopTabStop`

#### Сигнатура

```lua
function imgui.PopTabStop()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.PopTextWrapPos`

#### Сигнатура

```lua
function imgui.PopTextWrapPos()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.ProgressBar`

#### Сигнатура

```lua
function imgui.ProgressBar(fraction: number, size_arg?: ImVec2, overlay?: string)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>fraction</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>size_arg</code></td>
      <td><code>ImVec2</code></td>
      <td>нет</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>overlay</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.PushButtonRepeat`

#### Сигнатура

```lua
function imgui.PushButtonRepeat(_repeat: boolean)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>_repeat</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.PushClipRect`

#### Сигнатура

```lua
function imgui.PushClipRect(clip_rect_min: ImVec2, clip_rect_max: ImVec2, intersect_with_current_clip_rect: boolean)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>clip_rect_min</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>clip_rect_max</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>intersect_with_current_clip_rect</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.PushColumnClipRect`

#### Сигнатура

```lua
function imgui.PushColumnClipRect(column_index: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>column_index</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.PushColumnsBackground`

#### Сигнатура

```lua
function imgui.PushColumnsBackground()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.PushFocusScope`

#### Сигнатура

```lua
function imgui.PushFocusScope(id: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.PushFont`

#### Сигнатура

```lua
function imgui.PushFont(font: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>font</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImFont*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### ~~Функция `imgui.PushID`~~

 generic version

#### Сигнатура

```lua
function imgui.PushID(a1: any, a2: any)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.PushID_Int`

#### Сигнатура

```lua
function imgui.PushID_Int(int_id: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>int_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.PushID_Ptr`

#### Сигнатура

```lua
function imgui.PushID_Ptr(ptr_id: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ptr_id</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const void*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.PushID_Str`

#### Сигнатура

```lua
function imgui.PushID_Str(str_id: string)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>str_id</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.PushID_StrStr`

#### Сигнатура

```lua
function imgui.PushID_StrStr(str_id_begin: string, str_id_end: string)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>str_id_begin</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>str_id_end</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.PushItemFlag`

#### Сигнатура

```lua
function imgui.PushItemFlag(option: ItemFlags, enabled: boolean)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>option</code></td>
      <td><code>ItemFlags</code></td>
      <td>да</td>
      <td>-----------------------ItemFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>enabled</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.PushItemWidth`

#### Сигнатура

```lua
function imgui.PushItemWidth(item_width: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>item_width</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.PushMultiItemsWidths`

#### Сигнатура

```lua
function imgui.PushMultiItemsWidths(components: number, width_full: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>components</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>width_full</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.PushOverrideID`

#### Сигнатура

```lua
function imgui.PushOverrideID(id: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### ~~Функция `imgui.PushStyleColor`~~

 generic version

#### Сигнатура

```lua
function imgui.PushStyleColor(a1: any, a2: any)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.PushStyleColor_U32`

#### Сигнатура

```lua
function imgui.PushStyleColor_U32(idx: Col, col: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>idx</code></td>
      <td><code>Col</code></td>
      <td>да</td>
      <td>-----------------------Col----------------------------</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.PushStyleColor_Vec4`

#### Сигнатура

```lua
function imgui.PushStyleColor_Vec4(idx: Col, col: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>idx</code></td>
      <td><code>Col</code></td>
      <td>да</td>
      <td>-----------------------Col----------------------------</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImVec4</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### ~~Функция `imgui.PushStyleVar`~~

 generic version

#### Сигнатура

```lua
function imgui.PushStyleVar(a1: any, a2: any)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.PushStyleVar_Float`

#### Сигнатура

```lua
function imgui.PushStyleVar_Float(idx: StyleVar, val: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>idx</code></td>
      <td><code>StyleVar</code></td>
      <td>да</td>
      <td>-----------------------StyleVar----------------------------</td>
    </tr>
    <tr>
      <td><code>val</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.PushStyleVar_Vec2`

#### Сигнатура

```lua
function imgui.PushStyleVar_Vec2(idx: StyleVar, val: ImVec2)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>idx</code></td>
      <td><code>StyleVar</code></td>
      <td>да</td>
      <td>-----------------------StyleVar----------------------------</td>
    </tr>
    <tr>
      <td><code>val</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.PushTabStop`

#### Сигнатура

```lua
function imgui.PushTabStop(tab_stop: boolean)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>tab_stop</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.PushTextWrapPos`

#### Сигнатура

```lua
function imgui.PushTextWrapPos(wrap_local_pos_x?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>wrap_local_pos_x</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### ~~Функция `imgui.RadioButton`~~

 generic version

#### Сигнатура

```lua
function imgui.RadioButton(a1: any, a2: any, a3: any)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a3</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.RadioButton_Bool`

#### Сигнатура

```lua
function imgui.RadioButton_Bool(label: string, active: boolean)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>active</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.RadioButton_IntPtr`

#### Сигнатура

```lua
function imgui.RadioButton_IntPtr(label: string, v: ffi.cdata*|ffi.cdecl*|ffi.ctype*, v_button: number)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>int*</td>
    </tr>
    <tr>
      <td><code>v_button</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.RemoveContextHook`

#### Сигнатура

```lua
function imgui.RemoveContextHook(context: ffi.cdata*|ffi.cdecl*|ffi.ctype*, hook_to_remove: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>context</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiContext*</td>
    </tr>
    <tr>
      <td><code>hook_to_remove</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.RemoveSettingsHandler`

#### Сигнатура

```lua
function imgui.RemoveSettingsHandler(type_name: string)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>type_name</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.Render`

#### Сигнатура

```lua
function imgui.Render()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.RenderArrow`

#### Сигнатура

```lua
function imgui.RenderArrow(draw_list: ffi.cdata*|ffi.cdecl*|ffi.ctype*, pos: ImVec2, col: number, dir: Dir, scale?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>draw_list</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImDrawList*</td>
    </tr>
    <tr>
      <td><code>pos</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
    <tr>
      <td><code>dir</code></td>
      <td><code>Dir</code></td>
      <td>да</td>
      <td>-----------------------Dir----------------------------</td>
    </tr>
    <tr>
      <td><code>scale</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.RenderArrowDockMenu`

#### Сигнатура

```lua
function imgui.RenderArrowDockMenu(draw_list: ffi.cdata*|ffi.cdecl*|ffi.ctype*, p_min: ImVec2, sz: number, col: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>draw_list</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImDrawList*</td>
    </tr>
    <tr>
      <td><code>p_min</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>sz</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.RenderArrowPointingAt`

#### Сигнатура

```lua
function imgui.RenderArrowPointingAt(draw_list: ffi.cdata*|ffi.cdecl*|ffi.ctype*, pos: ImVec2, half_sz: ImVec2, direction: Dir, col: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>draw_list</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImDrawList*</td>
    </tr>
    <tr>
      <td><code>pos</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>half_sz</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>direction</code></td>
      <td><code>Dir</code></td>
      <td>да</td>
      <td>-----------------------Dir----------------------------</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.RenderBullet`

#### Сигнатура

```lua
function imgui.RenderBullet(draw_list: ffi.cdata*|ffi.cdecl*|ffi.ctype*, pos: ImVec2, col: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>draw_list</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImDrawList*</td>
    </tr>
    <tr>
      <td><code>pos</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.RenderCheckMark`

#### Сигнатура

```lua
function imgui.RenderCheckMark(draw_list: ffi.cdata*|ffi.cdecl*|ffi.ctype*, pos: ImVec2, col: number, sz: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>draw_list</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImDrawList*</td>
    </tr>
    <tr>
      <td><code>pos</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
    <tr>
      <td><code>sz</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.RenderColorRectWithAlphaCheckerboard`

#### Сигнатура

```lua
function imgui.RenderColorRectWithAlphaCheckerboard(draw_list: ffi.cdata*|ffi.cdecl*|ffi.ctype*, p_min: ImVec2, p_max: ImVec2, fill_col: number, grid_step: number, grid_off: ImVec2, rounding?: number, flags?: ImDrawFlags)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>draw_list</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImDrawList*</td>
    </tr>
    <tr>
      <td><code>p_min</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p_max</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>fill_col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
    <tr>
      <td><code>grid_step</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>grid_off</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>rounding</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>ImDrawFlags</code></td>
      <td>нет</td>
      <td>-----------------------ImDrawFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.RenderDragDropTargetRect`

#### Сигнатура

```lua
function imgui.RenderDragDropTargetRect(bb: ImRect, item_clip_rect: ImRect)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>bb</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
    <tr>
      <td><code>item_clip_rect</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.RenderFrame`

#### Сигнатура

```lua
function imgui.RenderFrame(p_min: ImVec2, p_max: ImVec2, fill_col: number, border?: boolean, rounding?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>p_min</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p_max</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>fill_col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
    <tr>
      <td><code>border</code></td>
      <td><code>boolean</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>rounding</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.RenderFrameBorder`

#### Сигнатура

```lua
function imgui.RenderFrameBorder(p_min: ImVec2, p_max: ImVec2, rounding?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>p_min</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p_max</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>rounding</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.RenderMouseCursor`

#### Сигнатура

```lua
function imgui.RenderMouseCursor(pos: ImVec2, scale: number, mouse_cursor: MouseCursor, col_fill: number, col_border: number, col_shadow: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>pos</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>scale</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>mouse_cursor</code></td>
      <td><code>MouseCursor</code></td>
      <td>да</td>
      <td>-----------------------MouseCursor----------------------------</td>
    </tr>
    <tr>
      <td><code>col_fill</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
    <tr>
      <td><code>col_border</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
    <tr>
      <td><code>col_shadow</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.RenderNavHighlight`

#### Сигнатура

```lua
function imgui.RenderNavHighlight(bb: ImRect, id: number, flags?: NavHighlightFlags)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>bb</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>NavHighlightFlags</code></td>
      <td>нет</td>
      <td>-----------------------NavHighlightFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.RenderPlatformWindowsDefault`

#### Сигнатура

```lua
function imgui.RenderPlatformWindowsDefault(platform_render_arg?: ffi.cdata*|ffi.cdecl*|ffi.ctype*, renderer_render_arg?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>platform_render_arg</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>void*</td>
    </tr>
    <tr>
      <td><code>renderer_render_arg</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>void*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.RenderRectFilledRangeH`

#### Сигнатура

```lua
function imgui.RenderRectFilledRangeH(draw_list: ffi.cdata*|ffi.cdecl*|ffi.ctype*, rect: ImRect, col: number, x_start_norm: number, x_end_norm: number, rounding: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>draw_list</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImDrawList*</td>
    </tr>
    <tr>
      <td><code>rect</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
    <tr>
      <td><code>x_start_norm</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>x_end_norm</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>rounding</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.RenderRectFilledWithHole`

#### Сигнатура

```lua
function imgui.RenderRectFilledWithHole(draw_list: ffi.cdata*|ffi.cdecl*|ffi.ctype*, outer: ImRect, inner: ImRect, col: number, rounding: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>draw_list</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImDrawList*</td>
    </tr>
    <tr>
      <td><code>outer</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
    <tr>
      <td><code>inner</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
    <tr>
      <td><code>rounding</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.RenderText`

#### Сигнатура

```lua
function imgui.RenderText(pos: ImVec2, text: string, text_end?: string, hide_text_after_hash?: boolean)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>pos</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>text</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>text_end</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>hide_text_after_hash</code></td>
      <td><code>boolean</code></td>
      <td>нет</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.RenderTextClipped`

#### Сигнатура

```lua
function imgui.RenderTextClipped(pos_min: ImVec2, pos_max: ImVec2, text: string, text_end: string, text_size_if_known: ffi.cdata*|ffi.cdecl*|ffi.ctype*, align?: ImVec2, clip_rect?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>pos_min</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>pos_max</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>text</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>text_end</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>text_size_if_known</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImVec2*</td>
    </tr>
    <tr>
      <td><code>align</code></td>
      <td><code>ImVec2</code></td>
      <td>нет</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>clip_rect</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>const ImRect*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.RenderTextClippedEx`

#### Сигнатура

```lua
function imgui.RenderTextClippedEx(draw_list: ffi.cdata*|ffi.cdecl*|ffi.ctype*, pos_min: ImVec2, pos_max: ImVec2, text: string, text_end: string, text_size_if_known: ffi.cdata*|ffi.cdecl*|ffi.ctype*, align?: ImVec2, clip_rect?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>draw_list</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImDrawList*</td>
    </tr>
    <tr>
      <td><code>pos_min</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>pos_max</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>text</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>text_end</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>text_size_if_known</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImVec2*</td>
    </tr>
    <tr>
      <td><code>align</code></td>
      <td><code>ImVec2</code></td>
      <td>нет</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>clip_rect</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>const ImRect*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.RenderTextEllipsis`

#### Сигнатура

```lua
function imgui.RenderTextEllipsis(draw_list: ffi.cdata*|ffi.cdecl*|ffi.ctype*, pos_min: ImVec2, pos_max: ImVec2, clip_max_x: number, ellipsis_max_x: number, text: string, text_end: string, text_size_if_known: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>draw_list</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImDrawList*</td>
    </tr>
    <tr>
      <td><code>pos_min</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>pos_max</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>clip_max_x</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>ellipsis_max_x</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>text</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>text_end</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>text_size_if_known</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImVec2*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.RenderTextWrapped`

#### Сигнатура

```lua
function imgui.RenderTextWrapped(pos: ImVec2, text: string, text_end: string, wrap_width: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>pos</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>text</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>text_end</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>wrap_width</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ResetMouseDragDelta`

#### Сигнатура

```lua
function imgui.ResetMouseDragDelta(button?: MouseButton)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>button</code></td>
      <td><code>MouseButton</code></td>
      <td>нет</td>
      <td>-----------------------MouseButton----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SameLine`

#### Сигнатура

```lua
function imgui.SameLine(offset_from_start_x?: number, spacing?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>offset_from_start_x</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>spacing</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SaveIniSettingsToDisk`

#### Сигнатура

```lua
function imgui.SaveIniSettingsToDisk(ini_filename: string)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ini_filename</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SaveIniSettingsToMemory`

#### Сигнатура

```lua
function imgui.SaveIniSettingsToMemory(out_ini_size?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> string
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>out_ini_size</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>size_t*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `string` 

### Функция `imgui.ScaleWindowsInViewport`

#### Сигнатура

```lua
function imgui.ScaleWindowsInViewport(viewport: ffi.cdata*|ffi.cdecl*|ffi.ctype*, scale: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>viewport</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiViewportP*</td>
    </tr>
    <tr>
      <td><code>scale</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ScrollToBringRectIntoView`

#### Сигнатура

```lua
function imgui.ScrollToBringRectIntoView(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, rect: ImRect)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>rect</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ScrollToItem`

#### Сигнатура

```lua
function imgui.ScrollToItem(flags?: ScrollFlags)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>flags</code></td>
      <td><code>ScrollFlags</code></td>
      <td>нет</td>
      <td>-----------------------ScrollFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ScrollToRect`

#### Сигнатура

```lua
function imgui.ScrollToRect(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, rect: ImRect, flags?: ScrollFlags)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>rect</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>ScrollFlags</code></td>
      <td>нет</td>
      <td>-----------------------ScrollFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ScrollToRectEx`

#### Сигнатура

```lua
function imgui.ScrollToRectEx(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, rect: ImRect, flags?: ScrollFlags)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>rect</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>ScrollFlags</code></td>
      <td>нет</td>
      <td>-----------------------ScrollFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.Scrollbar`

#### Сигнатура

```lua
function imgui.Scrollbar(axis: Axis)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>axis</code></td>
      <td><code>Axis</code></td>
      <td>да</td>
      <td>-----------------------Axis----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ScrollbarEx`

#### Сигнатура

```lua
function imgui.ScrollbarEx(bb: ImRect, id: number, axis: Axis, p_scroll_v: ffi.cdata*|ffi.cdecl*|ffi.ctype*, avail_v: number, contents_v: number, flags: ImDrawFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>bb</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>axis</code></td>
      <td><code>Axis</code></td>
      <td>да</td>
      <td>-----------------------Axis----------------------------</td>
    </tr>
    <tr>
      <td><code>p_scroll_v</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImS64*</td>
    </tr>
    <tr>
      <td><code>avail_v</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImS64</td>
    </tr>
    <tr>
      <td><code>contents_v</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImS64</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>ImDrawFlags</code></td>
      <td>да</td>
      <td>-----------------------ImDrawFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### ~~Функция `imgui.Selectable`~~

 generic version

#### Сигнатура

```lua
function imgui.Selectable(a1: any, a2: any, a3: any, a4: any)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a3</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a4</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.Selectable_Bool`

#### Сигнатура

```lua
function imgui.Selectable_Bool(label: string, selected?: boolean, flags?: SelectableFlags, size?: ImVec2)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>selected</code></td>
      <td><code>boolean</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>SelectableFlags</code></td>
      <td>нет</td>
      <td>-----------------------SelectableFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>size</code></td>
      <td><code>ImVec2</code></td>
      <td>нет</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.Selectable_BoolPtr`

#### Сигнатура

```lua
function imgui.Selectable_BoolPtr(label: string, p_selected: ffi.cdata*|ffi.cdecl*|ffi.ctype*, flags?: SelectableFlags, size?: ImVec2)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>p_selected</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>bool*</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>SelectableFlags</code></td>
      <td>нет</td>
      <td>-----------------------SelectableFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>size</code></td>
      <td><code>ImVec2</code></td>
      <td>нет</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.Separator`

#### Сигнатура

```lua
function imgui.Separator()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.SeparatorEx`

#### Сигнатура

```lua
function imgui.SeparatorEx(flags: SeparatorFlags, thickness?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>flags</code></td>
      <td><code>SeparatorFlags</code></td>
      <td>да</td>
      <td>-----------------------SeparatorFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>thickness</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SeparatorText`

#### Сигнатура

```lua
function imgui.SeparatorText(label: string)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SeparatorTextEx`

#### Сигнатура

```lua
function imgui.SeparatorTextEx(id: number, label: string, label_end: string, extra_width: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>label_end</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>extra_width</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetActiveID`

#### Сигнатура

```lua
function imgui.SetActiveID(id: number, window: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetActiveIdUsingAllKeyboardKeys`

#### Сигнатура

```lua
function imgui.SetActiveIdUsingAllKeyboardKeys()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.SetAllocatorFunctions`

#### Сигнатура

```lua
function imgui.SetAllocatorFunctions(alloc_func: ffi.cdata*|ffi.cdecl*|ffi.ctype*, free_func: ffi.cdata*|ffi.cdecl*|ffi.ctype*, user_data?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>alloc_func</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiMemAllocFunc</td>
    </tr>
    <tr>
      <td><code>free_func</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiMemFreeFunc</td>
    </tr>
    <tr>
      <td><code>user_data</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>void*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetClipboardText`

#### Сигнатура

```lua
function imgui.SetClipboardText(text: string)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>text</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetColorEditOptions`

#### Сигнатура

```lua
function imgui.SetColorEditOptions(flags: ColorEditFlags)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>flags</code></td>
      <td><code>ColorEditFlags</code></td>
      <td>да</td>
      <td>-----------------------ColorEditFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetColumnOffset`

#### Сигнатура

```lua
function imgui.SetColumnOffset(column_index: number, offset_x: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>column_index</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>offset_x</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetColumnWidth`

#### Сигнатура

```lua
function imgui.SetColumnWidth(column_index: number, width: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>column_index</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>width</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetCurrentContext`

#### Сигнатура

```lua
function imgui.SetCurrentContext(ctx: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctx</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiContext*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetCurrentFont`

#### Сигнатура

```lua
function imgui.SetCurrentFont(font: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>font</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImFont*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetCurrentViewport`

#### Сигнатура

```lua
function imgui.SetCurrentViewport(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, viewport: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>viewport</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiViewportP*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetCursorPos`

#### Сигнатура

```lua
function imgui.SetCursorPos(local_pos: ImVec2)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>local_pos</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetCursorPosX`

#### Сигнатура

```lua
function imgui.SetCursorPosX(local_x: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>local_x</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetCursorPosY`

#### Сигнатура

```lua
function imgui.SetCursorPosY(local_y: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>local_y</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetCursorScreenPos`

#### Сигнатура

```lua
function imgui.SetCursorScreenPos(pos: ImVec2)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>pos</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetDragDropPayload`

#### Сигнатура

```lua
function imgui.SetDragDropPayload(type: string, data: ffi.cdata*|ffi.cdecl*|ffi.ctype*, sz: number, cond?: Cond)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>type</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>data</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const void*</td>
    </tr>
    <tr>
      <td><code>sz</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>size_t</td>
    </tr>
    <tr>
      <td><code>cond</code></td>
      <td><code>Cond</code></td>
      <td>нет</td>
      <td>-----------------------Cond----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.SetFocusID`

#### Сигнатура

```lua
function imgui.SetFocusID(id: number, window: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetHoveredID`

#### Сигнатура

```lua
function imgui.SetHoveredID(id: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetItemDefaultFocus`

#### Сигнатура

```lua
function imgui.SetItemDefaultFocus()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.SetItemKeyOwner`

#### Сигнатура

```lua
function imgui.SetItemKeyOwner(key: Key, flags?: InputFlags)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>Key</code></td>
      <td>да</td>
      <td>-----------------------Key----------------------------</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>InputFlags</code></td>
      <td>нет</td>
      <td>-----------------------InputFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetItemTooltip`

#### Сигнатура

```lua
function imgui.SetItemTooltip(fmt: string, ...any)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>fmt</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>...</code></td>
      <td><code>unknown</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetItemTooltipV`

#### Сигнатура

```lua
function imgui.SetItemTooltipV(fmt: string, args: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>fmt</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>args</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>va_list</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetKeyOwner`

#### Сигнатура

```lua
function imgui.SetKeyOwner(key: Key, owner_id: number, flags?: InputFlags)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>Key</code></td>
      <td>да</td>
      <td>-----------------------Key----------------------------</td>
    </tr>
    <tr>
      <td><code>owner_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>InputFlags</code></td>
      <td>нет</td>
      <td>-----------------------InputFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetKeyOwnersForKeyChord`

#### Сигнатура

```lua
function imgui.SetKeyOwnersForKeyChord(key: number, owner_id: number, flags?: InputFlags)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiKeyChord</td>
    </tr>
    <tr>
      <td><code>owner_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>InputFlags</code></td>
      <td>нет</td>
      <td>-----------------------InputFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetKeyboardFocusHere`

#### Сигнатура

```lua
function imgui.SetKeyboardFocusHere(offset?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>offset</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetLastItemData`

#### Сигнатура

```lua
function imgui.SetLastItemData(item_id: number, in_flags: ItemFlags, status_flags: ItemStatusFlags, item_rect: ImRect)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>item_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>in_flags</code></td>
      <td><code>ItemFlags</code></td>
      <td>да</td>
      <td>-----------------------ItemFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>status_flags</code></td>
      <td><code>ItemStatusFlags</code></td>
      <td>да</td>
      <td>-----------------------ItemStatusFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>item_rect</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetMouseCursor`

#### Сигнатура

```lua
function imgui.SetMouseCursor(cursor_type: MouseCursor)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>cursor_type</code></td>
      <td><code>MouseCursor</code></td>
      <td>да</td>
      <td>-----------------------MouseCursor----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetNavFocusScope`

#### Сигнатура

```lua
function imgui.SetNavFocusScope(focus_scope_id: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>focus_scope_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetNavID`

#### Сигнатура

```lua
function imgui.SetNavID(id: number, nav_layer: NavLayer, focus_scope_id: number, rect_rel: ImRect)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>nav_layer</code></td>
      <td><code>NavLayer</code></td>
      <td>да</td>
      <td>-----------------------NavLayer----------------------------</td>
    </tr>
    <tr>
      <td><code>focus_scope_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>rect_rel</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetNavWindow`

#### Сигнатура

```lua
function imgui.SetNavWindow(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetNextFrameWantCaptureKeyboard`

#### Сигнатура

```lua
function imgui.SetNextFrameWantCaptureKeyboard(want_capture_keyboard: boolean)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>want_capture_keyboard</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetNextFrameWantCaptureMouse`

#### Сигнатура

```lua
function imgui.SetNextFrameWantCaptureMouse(want_capture_mouse: boolean)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>want_capture_mouse</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetNextItemAllowOverlap`

#### Сигнатура

```lua
function imgui.SetNextItemAllowOverlap()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.SetNextItemOpen`

#### Сигнатура

```lua
function imgui.SetNextItemOpen(is_open: boolean, cond?: Cond)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>is_open</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>cond</code></td>
      <td><code>Cond</code></td>
      <td>нет</td>
      <td>-----------------------Cond----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetNextItemSelectionUserData`

#### Сигнатура

```lua
function imgui.SetNextItemSelectionUserData(selection_user_data: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>selection_user_data</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiSelectionUserData</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetNextItemShortcut`

#### Сигнатура

```lua
function imgui.SetNextItemShortcut(key_chord: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key_chord</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiKeyChord</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetNextItemWidth`

#### Сигнатура

```lua
function imgui.SetNextItemWidth(item_width: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>item_width</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetNextWindowBgAlpha`

#### Сигнатура

```lua
function imgui.SetNextWindowBgAlpha(alpha: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>alpha</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetNextWindowClass`

#### Сигнатура

```lua
function imgui.SetNextWindowClass(window_class: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window_class</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImGuiWindowClass*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetNextWindowCollapsed`

#### Сигнатура

```lua
function imgui.SetNextWindowCollapsed(collapsed: boolean, cond?: Cond)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>collapsed</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>cond</code></td>
      <td><code>Cond</code></td>
      <td>нет</td>
      <td>-----------------------Cond----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetNextWindowContentSize`

#### Сигнатура

```lua
function imgui.SetNextWindowContentSize(size: ImVec2)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>size</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetNextWindowDockID`

#### Сигнатура

```lua
function imgui.SetNextWindowDockID(dock_id: number, cond?: Cond)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>dock_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>cond</code></td>
      <td><code>Cond</code></td>
      <td>нет</td>
      <td>-----------------------Cond----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetNextWindowFocus`

#### Сигнатура

```lua
function imgui.SetNextWindowFocus()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.SetNextWindowPos`

#### Сигнатура

```lua
function imgui.SetNextWindowPos(pos: ImVec2, cond?: Cond, pivot?: ImVec2)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>pos</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>cond</code></td>
      <td><code>Cond</code></td>
      <td>нет</td>
      <td>-----------------------Cond----------------------------</td>
    </tr>
    <tr>
      <td><code>pivot</code></td>
      <td><code>ImVec2</code></td>
      <td>нет</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetNextWindowScroll`

#### Сигнатура

```lua
function imgui.SetNextWindowScroll(scroll: ImVec2)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>scroll</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetNextWindowSize`

#### Сигнатура

```lua
function imgui.SetNextWindowSize(size: ImVec2, cond?: Cond)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>size</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>cond</code></td>
      <td><code>Cond</code></td>
      <td>нет</td>
      <td>-----------------------Cond----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetNextWindowSizeConstraints`

#### Сигнатура

```lua
function imgui.SetNextWindowSizeConstraints(size_min: ImVec2, size_max: ImVec2, custom_callback?: ffi.cdata*|ffi.cdecl*|ffi.ctype*, custom_callback_data?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>size_min</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>size_max</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>custom_callback</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>ImGuiSizeCallback</td>
    </tr>
    <tr>
      <td><code>custom_callback_data</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>void*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetNextWindowViewport`

#### Сигнатура

```lua
function imgui.SetNextWindowViewport(viewport_id: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>viewport_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### ~~Функция `imgui.SetScrollFromPosX`~~

 generic version

#### Сигнатура

```lua
function imgui.SetScrollFromPosX(a1: any, a2: any, a3: any)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a3</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetScrollFromPosX_Float`

#### Сигнатура

```lua
function imgui.SetScrollFromPosX_Float(local_x: number, center_x_ratio?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>local_x</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>center_x_ratio</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetScrollFromPosX_WindowPtr`

#### Сигнатура

```lua
function imgui.SetScrollFromPosX_WindowPtr(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, local_x: number, center_x_ratio: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>local_x</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>center_x_ratio</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### ~~Функция `imgui.SetScrollFromPosY`~~

 generic version

#### Сигнатура

```lua
function imgui.SetScrollFromPosY(a1: any, a2: any, a3: any)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a3</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetScrollFromPosY_Float`

#### Сигнатура

```lua
function imgui.SetScrollFromPosY_Float(local_y: number, center_y_ratio?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>local_y</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>center_y_ratio</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetScrollFromPosY_WindowPtr`

#### Сигнатура

```lua
function imgui.SetScrollFromPosY_WindowPtr(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, local_y: number, center_y_ratio: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>local_y</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>center_y_ratio</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetScrollHereX`

#### Сигнатура

```lua
function imgui.SetScrollHereX(center_x_ratio?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>center_x_ratio</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetScrollHereY`

#### Сигнатура

```lua
function imgui.SetScrollHereY(center_y_ratio?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>center_y_ratio</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### ~~Функция `imgui.SetScrollX`~~

 generic version

#### Сигнатура

```lua
function imgui.SetScrollX(a1: any, a2: any)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetScrollX_Float`

#### Сигнатура

```lua
function imgui.SetScrollX_Float(scroll_x: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>scroll_x</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetScrollX_WindowPtr`

#### Сигнатура

```lua
function imgui.SetScrollX_WindowPtr(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, scroll_x: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>scroll_x</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### ~~Функция `imgui.SetScrollY`~~

 generic version

#### Сигнатура

```lua
function imgui.SetScrollY(a1: any, a2: any)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetScrollY_Float`

#### Сигнатура

```lua
function imgui.SetScrollY_Float(scroll_y: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>scroll_y</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetScrollY_WindowPtr`

#### Сигнатура

```lua
function imgui.SetScrollY_WindowPtr(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, scroll_y: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>scroll_y</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetShortcutRouting`

#### Сигнатура

```lua
function imgui.SetShortcutRouting(key_chord: number, owner_id: number, flags?: InputFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key_chord</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiKeyChord</td>
    </tr>
    <tr>
      <td><code>owner_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>InputFlags</code></td>
      <td>нет</td>
      <td>-----------------------InputFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.SetStateStorage`

#### Сигнатура

```lua
function imgui.SetStateStorage(storage: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>storage</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiStorage*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetTabItemClosed`

#### Сигнатура

```lua
function imgui.SetTabItemClosed(tab_or_docked_window_label: string)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>tab_or_docked_window_label</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetTooltip`

#### Сигнатура

```lua
function imgui.SetTooltip(fmt: string, ...any)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>fmt</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>...</code></td>
      <td><code>unknown</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetTooltipV`

#### Сигнатура

```lua
function imgui.SetTooltipV(fmt: string, args: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>fmt</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>args</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>va_list</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetWindowClipRectBeforeSetChannel`

#### Сигнатура

```lua
function imgui.SetWindowClipRectBeforeSetChannel(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, clip_rect: ImRect)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>clip_rect</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### ~~Функция `imgui.SetWindowCollapsed`~~

 generic version

#### Сигнатура

```lua
function imgui.SetWindowCollapsed(a1: any, a2: any, a3: any)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a3</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetWindowCollapsed_Bool`

#### Сигнатура

```lua
function imgui.SetWindowCollapsed_Bool(collapsed: boolean, cond?: Cond)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>collapsed</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>cond</code></td>
      <td><code>Cond</code></td>
      <td>нет</td>
      <td>-----------------------Cond----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetWindowCollapsed_Str`

#### Сигнатура

```lua
function imgui.SetWindowCollapsed_Str(name: string, collapsed: boolean, cond?: Cond)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>name</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>collapsed</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>cond</code></td>
      <td><code>Cond</code></td>
      <td>нет</td>
      <td>-----------------------Cond----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetWindowCollapsed_WindowPtr`

#### Сигнатура

```lua
function imgui.SetWindowCollapsed_WindowPtr(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, collapsed: boolean, cond?: Cond)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>collapsed</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>cond</code></td>
      <td><code>Cond</code></td>
      <td>нет</td>
      <td>-----------------------Cond----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetWindowDock`

#### Сигнатура

```lua
function imgui.SetWindowDock(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, dock_id: number, cond: Cond)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>dock_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>cond</code></td>
      <td><code>Cond</code></td>
      <td>да</td>
      <td>-----------------------Cond----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### ~~Функция `imgui.SetWindowFocus`~~

 generic version

#### Сигнатура

```lua
function imgui.SetWindowFocus(a1: any)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetWindowFocus_Nil`

#### Сигнатура

```lua
function imgui.SetWindowFocus_Nil()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.SetWindowFocus_Str`

#### Сигнатура

```lua
function imgui.SetWindowFocus_Str(name: string)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>name</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetWindowFontScale`

#### Сигнатура

```lua
function imgui.SetWindowFontScale(scale: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>scale</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetWindowHiddenAndSkipItemsForCurrentFrame`

#### Сигнатура

```lua
function imgui.SetWindowHiddenAndSkipItemsForCurrentFrame(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetWindowHitTestHole`

#### Сигнатура

```lua
function imgui.SetWindowHitTestHole(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, pos: ImVec2, size: ImVec2)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>pos</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>size</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetWindowParentWindowForFocusRoute`

#### Сигнатура

```lua
function imgui.SetWindowParentWindowForFocusRoute(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, parent_window: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>parent_window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### ~~Функция `imgui.SetWindowPos`~~

 generic version

#### Сигнатура

```lua
function imgui.SetWindowPos(a1: any, a2: any, a3: any)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a3</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetWindowPos_Str`

#### Сигнатура

```lua
function imgui.SetWindowPos_Str(name: string, pos: ImVec2, cond?: Cond)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>name</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>pos</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>cond</code></td>
      <td><code>Cond</code></td>
      <td>нет</td>
      <td>-----------------------Cond----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetWindowPos_Vec2`

#### Сигнатура

```lua
function imgui.SetWindowPos_Vec2(pos: ImVec2, cond?: Cond)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>pos</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>cond</code></td>
      <td><code>Cond</code></td>
      <td>нет</td>
      <td>-----------------------Cond----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetWindowPos_WindowPtr`

#### Сигнатура

```lua
function imgui.SetWindowPos_WindowPtr(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, pos: ImVec2, cond?: Cond)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>pos</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>cond</code></td>
      <td><code>Cond</code></td>
      <td>нет</td>
      <td>-----------------------Cond----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### ~~Функция `imgui.SetWindowSize`~~

 generic version

#### Сигнатура

```lua
function imgui.SetWindowSize(a1: any, a2: any, a3: any)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a3</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetWindowSize_Str`

#### Сигнатура

```lua
function imgui.SetWindowSize_Str(name: string, size: ImVec2, cond?: Cond)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>name</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>size</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>cond</code></td>
      <td><code>Cond</code></td>
      <td>нет</td>
      <td>-----------------------Cond----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetWindowSize_Vec2`

#### Сигнатура

```lua
function imgui.SetWindowSize_Vec2(size: ImVec2, cond?: Cond)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>size</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>cond</code></td>
      <td><code>Cond</code></td>
      <td>нет</td>
      <td>-----------------------Cond----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetWindowSize_WindowPtr`

#### Сигнатура

```lua
function imgui.SetWindowSize_WindowPtr(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, size: ImVec2, cond?: Cond)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>size</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>cond</code></td>
      <td><code>Cond</code></td>
      <td>нет</td>
      <td>-----------------------Cond----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.SetWindowViewport`

#### Сигнатура

```lua
function imgui.SetWindowViewport(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, viewport: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>viewport</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiViewportP*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ShadeVertsLinearColorGradientKeepAlpha`

#### Сигнатура

```lua
function imgui.ShadeVertsLinearColorGradientKeepAlpha(draw_list: ffi.cdata*|ffi.cdecl*|ffi.ctype*, vert_start_idx: number, vert_end_idx: number, gradient_p0: ImVec2, gradient_p1: ImVec2, col0: number, col1: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>draw_list</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImDrawList*</td>
    </tr>
    <tr>
      <td><code>vert_start_idx</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>vert_end_idx</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>gradient_p0</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>gradient_p1</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>col0</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
    <tr>
      <td><code>col1</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ShadeVertsLinearUV`

#### Сигнатура

```lua
function imgui.ShadeVertsLinearUV(draw_list: ffi.cdata*|ffi.cdecl*|ffi.ctype*, vert_start_idx: number, vert_end_idx: number, a: ImVec2, b: ImVec2, uv_a: ImVec2, uv_b: ImVec2, clamp: boolean)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>draw_list</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImDrawList*</td>
    </tr>
    <tr>
      <td><code>vert_start_idx</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>vert_end_idx</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>a</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>b</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>uv_a</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>uv_b</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>clamp</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ShadeVertsTransformPos`

#### Сигнатура

```lua
function imgui.ShadeVertsTransformPos(draw_list: ffi.cdata*|ffi.cdecl*|ffi.ctype*, vert_start_idx: number, vert_end_idx: number, pivot_in: ImVec2, cos_a: number, sin_a: number, pivot_out: ImVec2)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>draw_list</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImDrawList*</td>
    </tr>
    <tr>
      <td><code>vert_start_idx</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>vert_end_idx</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>pivot_in</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>cos_a</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>sin_a</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>pivot_out</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.Shortcut`

#### Сигнатура

```lua
function imgui.Shortcut(key_chord: number, owner_id?: number, flags?: InputFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key_chord</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiKeyChord</td>
    </tr>
    <tr>
      <td><code>owner_id</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>InputFlags</code></td>
      <td>нет</td>
      <td>-----------------------InputFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.ShowAboutWindow`

#### Сигнатура

```lua
function imgui.ShowAboutWindow(p_open?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>p_open</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>bool*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ShowDebugLogWindow`

#### Сигнатура

```lua
function imgui.ShowDebugLogWindow(p_open?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>p_open</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>bool*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ShowDemoWindow`

#### Сигнатура

```lua
function imgui.ShowDemoWindow(p_open?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>p_open</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>bool*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ShowFontAtlas`

#### Сигнатура

```lua
function imgui.ShowFontAtlas(atlas: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>atlas</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImFontAtlas*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ShowFontSelector`

#### Сигнатура

```lua
function imgui.ShowFontSelector(label: string)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ShowIDStackToolWindow`

#### Сигнатура

```lua
function imgui.ShowIDStackToolWindow(p_open?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>p_open</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>bool*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ShowMetricsWindow`

#### Сигнатура

```lua
function imgui.ShowMetricsWindow(p_open?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>p_open</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>bool*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ShowStyleEditor`

#### Сигнатура

```lua
function imgui.ShowStyleEditor(ref?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ref</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>ImGuiStyle*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.ShowStyleSelector`

#### Сигнатура

```lua
function imgui.ShowStyleSelector(label: string)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.ShowUserGuide`

#### Сигнатура

```lua
function imgui.ShowUserGuide()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.ShrinkWidths`

#### Сигнатура

```lua
function imgui.ShrinkWidths(items: ffi.cdata*|ffi.cdecl*|ffi.ctype*, count: number, width_excess: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>items</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiShrinkWidthItem*</td>
    </tr>
    <tr>
      <td><code>count</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>width_excess</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.Shutdown`

#### Сигнатура

```lua
function imgui.Shutdown()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.SliderAngle`

#### Сигнатура

```lua
function imgui.SliderAngle(label: string, v_rad: ffi.cdata*|ffi.cdecl*|ffi.ctype*, v_degrees_min?: number, v_degrees_max?: number, format?: string, flags?: SliderFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>v_rad</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>float*</td>
    </tr>
    <tr>
      <td><code>v_degrees_min</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>v_degrees_max</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>SliderFlags</code></td>
      <td>нет</td>
      <td>-----------------------SliderFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.SliderBehavior`

#### Сигнатура

```lua
function imgui.SliderBehavior(bb: ImRect, id: number, data_type: DataType, p_v: ffi.cdata*|ffi.cdecl*|ffi.ctype*, p_min: ffi.cdata*|ffi.cdecl*|ffi.ctype*, p_max: ffi.cdata*|ffi.cdecl*|ffi.ctype*, format: string, flags: SliderFlags, out_grab_bb: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>bb</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>data_type</code></td>
      <td><code>DataType</code></td>
      <td>да</td>
      <td>-----------------------DataType----------------------------</td>
    </tr>
    <tr>
      <td><code>p_v</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>void*</td>
    </tr>
    <tr>
      <td><code>p_min</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const void*</td>
    </tr>
    <tr>
      <td><code>p_max</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const void*</td>
    </tr>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>SliderFlags</code></td>
      <td>да</td>
      <td>-----------------------SliderFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>out_grab_bb</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImRect*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.SliderFloat`

#### Сигнатура

```lua
function imgui.SliderFloat(label: string, v: ffi.cdata*|ffi.cdecl*|ffi.ctype*, v_min: number, v_max: number, format?: string, flags?: SliderFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>float*</td>
    </tr>
    <tr>
      <td><code>v_min</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>v_max</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>SliderFlags</code></td>
      <td>нет</td>
      <td>-----------------------SliderFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.SliderFloat2`

#### Сигнатура

```lua
function imgui.SliderFloat2(label: string, v: ffi.cdata*|ffi.cdecl*|ffi.ctype*, v_min: number, v_max: number, format?: string, flags?: SliderFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>float[2]</td>
    </tr>
    <tr>
      <td><code>v_min</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>v_max</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>SliderFlags</code></td>
      <td>нет</td>
      <td>-----------------------SliderFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.SliderFloat3`

#### Сигнатура

```lua
function imgui.SliderFloat3(label: string, v: ffi.cdata*|ffi.cdecl*|ffi.ctype*, v_min: number, v_max: number, format?: string, flags?: SliderFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>float[3]</td>
    </tr>
    <tr>
      <td><code>v_min</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>v_max</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>SliderFlags</code></td>
      <td>нет</td>
      <td>-----------------------SliderFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.SliderFloat4`

#### Сигнатура

```lua
function imgui.SliderFloat4(label: string, v: ffi.cdata*|ffi.cdecl*|ffi.ctype*, v_min: number, v_max: number, format?: string, flags?: SliderFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>float[4]</td>
    </tr>
    <tr>
      <td><code>v_min</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>v_max</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>SliderFlags</code></td>
      <td>нет</td>
      <td>-----------------------SliderFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.SliderInt`

#### Сигнатура

```lua
function imgui.SliderInt(label: string, v: ffi.cdata*|ffi.cdecl*|ffi.ctype*, v_min: number, v_max: number, format?: string, flags?: SliderFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>int*</td>
    </tr>
    <tr>
      <td><code>v_min</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>v_max</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>SliderFlags</code></td>
      <td>нет</td>
      <td>-----------------------SliderFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.SliderInt2`

#### Сигнатура

```lua
function imgui.SliderInt2(label: string, v: ffi.cdata*|ffi.cdecl*|ffi.ctype*, v_min: number, v_max: number, format?: string, flags?: SliderFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>int[2]</td>
    </tr>
    <tr>
      <td><code>v_min</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>v_max</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>SliderFlags</code></td>
      <td>нет</td>
      <td>-----------------------SliderFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.SliderInt3`

#### Сигнатура

```lua
function imgui.SliderInt3(label: string, v: ffi.cdata*|ffi.cdecl*|ffi.ctype*, v_min: number, v_max: number, format?: string, flags?: SliderFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>int[3]</td>
    </tr>
    <tr>
      <td><code>v_min</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>v_max</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>SliderFlags</code></td>
      <td>нет</td>
      <td>-----------------------SliderFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.SliderInt4`

#### Сигнатура

```lua
function imgui.SliderInt4(label: string, v: ffi.cdata*|ffi.cdecl*|ffi.ctype*, v_min: number, v_max: number, format?: string, flags?: SliderFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>int[4]</td>
    </tr>
    <tr>
      <td><code>v_min</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>v_max</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>SliderFlags</code></td>
      <td>нет</td>
      <td>-----------------------SliderFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.SliderScalar`

#### Сигнатура

```lua
function imgui.SliderScalar(label: string, data_type: DataType, p_data: ffi.cdata*|ffi.cdecl*|ffi.ctype*, p_min: ffi.cdata*|ffi.cdecl*|ffi.ctype*, p_max: ffi.cdata*|ffi.cdecl*|ffi.ctype*, format?: string, flags?: SliderFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>data_type</code></td>
      <td><code>DataType</code></td>
      <td>да</td>
      <td>-----------------------DataType----------------------------</td>
    </tr>
    <tr>
      <td><code>p_data</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>void*</td>
    </tr>
    <tr>
      <td><code>p_min</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const void*</td>
    </tr>
    <tr>
      <td><code>p_max</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const void*</td>
    </tr>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>SliderFlags</code></td>
      <td>нет</td>
      <td>-----------------------SliderFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.SliderScalarN`

#### Сигнатура

```lua
function imgui.SliderScalarN(label: string, data_type: DataType, p_data: ffi.cdata*|ffi.cdecl*|ffi.ctype*, components: number, p_min: ffi.cdata*|ffi.cdecl*|ffi.ctype*, p_max: ffi.cdata*|ffi.cdecl*|ffi.ctype*, format?: string, flags?: SliderFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>data_type</code></td>
      <td><code>DataType</code></td>
      <td>да</td>
      <td>-----------------------DataType----------------------------</td>
    </tr>
    <tr>
      <td><code>p_data</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>void*</td>
    </tr>
    <tr>
      <td><code>components</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>p_min</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const void*</td>
    </tr>
    <tr>
      <td><code>p_max</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const void*</td>
    </tr>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>SliderFlags</code></td>
      <td>нет</td>
      <td>-----------------------SliderFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.SmallButton`

#### Сигнатура

```lua
function imgui.SmallButton(label: string)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.Spacing`

#### Сигнатура

```lua
function imgui.Spacing()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.SplitterBehavior`

#### Сигнатура

```lua
function imgui.SplitterBehavior(bb: ImRect, id: number, axis: Axis, size1: ffi.cdata*|ffi.cdecl*|ffi.ctype*, size2: ffi.cdata*|ffi.cdecl*|ffi.ctype*, min_size1: number, min_size2: number, hover_extend?: number, hover_visibility_delay?: number, bg_col?: number)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>bb</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>axis</code></td>
      <td><code>Axis</code></td>
      <td>да</td>
      <td>-----------------------Axis----------------------------</td>
    </tr>
    <tr>
      <td><code>size1</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>float*</td>
    </tr>
    <tr>
      <td><code>size2</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>float*</td>
    </tr>
    <tr>
      <td><code>min_size1</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>min_size2</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>hover_extend</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>hover_visibility_delay</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>bg_col</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>ImU32</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.StartMouseMovingWindow`

#### Сигнатура

```lua
function imgui.StartMouseMovingWindow(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.StartMouseMovingWindowOrNode`

#### Сигнатура

```lua
function imgui.StartMouseMovingWindowOrNode(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, node: ffi.cdata*|ffi.cdecl*|ffi.ctype*, undock: boolean)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>node</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiDockNode*</td>
    </tr>
    <tr>
      <td><code>undock</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.StyleColorsClassic`

#### Сигнатура

```lua
function imgui.StyleColorsClassic(dst?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>dst</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>ImGuiStyle*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.StyleColorsDark`

#### Сигнатура

```lua
function imgui.StyleColorsDark(dst?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>dst</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>ImGuiStyle*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.StyleColorsLight`

#### Сигнатура

```lua
function imgui.StyleColorsLight(dst?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>dst</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>ImGuiStyle*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TabBarAddTab`

#### Сигнатура

```lua
function imgui.TabBarAddTab(tab_bar: ffi.cdata*|ffi.cdecl*|ffi.ctype*, tab_flags: TabItemFlags, window: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>tab_bar</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTabBar*</td>
    </tr>
    <tr>
      <td><code>tab_flags</code></td>
      <td><code>TabItemFlags</code></td>
      <td>да</td>
      <td>-----------------------TabItemFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TabBarCloseTab`

#### Сигнатура

```lua
function imgui.TabBarCloseTab(tab_bar: ffi.cdata*|ffi.cdecl*|ffi.ctype*, tab: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>tab_bar</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTabBar*</td>
    </tr>
    <tr>
      <td><code>tab</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTabItem*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TabBarFindMostRecentlySelectedTabForActiveWindow`

#### Сигнатура

```lua
function imgui.TabBarFindMostRecentlySelectedTabForActiveWindow(tab_bar: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> ImGuiTabItem*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>tab_bar</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTabBar*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.TabBarFindTabByID`

#### Сигнатура

```lua
function imgui.TabBarFindTabByID(tab_bar: ffi.cdata*|ffi.cdecl*|ffi.ctype*, tab_id: number)
  -> ImGuiTabItem*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>tab_bar</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTabBar*</td>
    </tr>
    <tr>
      <td><code>tab_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.TabBarFindTabByOrder`

#### Сигнатура

```lua
function imgui.TabBarFindTabByOrder(tab_bar: ffi.cdata*|ffi.cdecl*|ffi.ctype*, order: number)
  -> ImGuiTabItem*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>tab_bar</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTabBar*</td>
    </tr>
    <tr>
      <td><code>order</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.TabBarGetCurrentTab`

#### Сигнатура

```lua
function imgui.TabBarGetCurrentTab(tab_bar: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> ImGuiTabItem*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>tab_bar</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTabBar*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.TabBarGetTabName`

#### Сигнатура

```lua
function imgui.TabBarGetTabName(tab_bar: ffi.cdata*|ffi.cdecl*|ffi.ctype*, tab: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> string
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>tab_bar</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTabBar*</td>
    </tr>
    <tr>
      <td><code>tab</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTabItem*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `string` 

### Функция `imgui.TabBarGetTabOrder`

#### Сигнатура

```lua
function imgui.TabBarGetTabOrder(tab_bar: ffi.cdata*|ffi.cdecl*|ffi.ctype*, tab: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> int: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>tab_bar</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTabBar*</td>
    </tr>
    <tr>
      <td><code>tab</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTabItem*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.TabBarProcessReorder`

#### Сигнатура

```lua
function imgui.TabBarProcessReorder(tab_bar: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>tab_bar</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTabBar*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.TabBarQueueFocus`

#### Сигнатура

```lua
function imgui.TabBarQueueFocus(tab_bar: ffi.cdata*|ffi.cdecl*|ffi.ctype*, tab: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>tab_bar</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTabBar*</td>
    </tr>
    <tr>
      <td><code>tab</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTabItem*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TabBarQueueReorder`

#### Сигнатура

```lua
function imgui.TabBarQueueReorder(tab_bar: ffi.cdata*|ffi.cdecl*|ffi.ctype*, tab: ffi.cdata*|ffi.cdecl*|ffi.ctype*, offset: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>tab_bar</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTabBar*</td>
    </tr>
    <tr>
      <td><code>tab</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTabItem*</td>
    </tr>
    <tr>
      <td><code>offset</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TabBarQueueReorderFromMousePos`

#### Сигнатура

```lua
function imgui.TabBarQueueReorderFromMousePos(tab_bar: ffi.cdata*|ffi.cdecl*|ffi.ctype*, tab: ffi.cdata*|ffi.cdecl*|ffi.ctype*, mouse_pos: ImVec2)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>tab_bar</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTabBar*</td>
    </tr>
    <tr>
      <td><code>tab</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTabItem*</td>
    </tr>
    <tr>
      <td><code>mouse_pos</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TabBarRemoveTab`

#### Сигнатура

```lua
function imgui.TabBarRemoveTab(tab_bar: ffi.cdata*|ffi.cdecl*|ffi.ctype*, tab_id: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>tab_bar</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTabBar*</td>
    </tr>
    <tr>
      <td><code>tab_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TabItemBackground`

#### Сигнатура

```lua
function imgui.TabItemBackground(draw_list: ffi.cdata*|ffi.cdecl*|ffi.ctype*, bb: ImRect, flags: TabItemFlags, col: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>draw_list</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImDrawList*</td>
    </tr>
    <tr>
      <td><code>bb</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>TabItemFlags</code></td>
      <td>да</td>
      <td>-----------------------TabItemFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TabItemButton`

#### Сигнатура

```lua
function imgui.TabItemButton(label: string, flags?: TabItemFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>TabItemFlags</code></td>
      <td>нет</td>
      <td>-----------------------TabItemFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### ~~Функция `imgui.TabItemCalcSize`~~

 generic version

#### Сигнатура

```lua
function imgui.TabItemCalcSize(a2: any, a3: any)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a3</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TabItemCalcSize_Str`

#### Сигнатура

```lua
function imgui.TabItemCalcSize_Str(label: string, has_close_button_or_unsaved_marker: boolean)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>has_close_button_or_unsaved_marker</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TabItemCalcSize_WindowPtr`

#### Сигнатура

```lua
function imgui.TabItemCalcSize_WindowPtr(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TabItemEx`

#### Сигнатура

```lua
function imgui.TabItemEx(tab_bar: ffi.cdata*|ffi.cdecl*|ffi.ctype*, label: string, p_open: ffi.cdata*|ffi.cdecl*|ffi.ctype*, flags: TabItemFlags, docked_window: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>tab_bar</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTabBar*</td>
    </tr>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>p_open</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>bool*</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>TabItemFlags</code></td>
      <td>да</td>
      <td>-----------------------TabItemFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>docked_window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.TabItemLabelAndCloseButton`

#### Сигнатура

```lua
function imgui.TabItemLabelAndCloseButton(draw_list: ffi.cdata*|ffi.cdecl*|ffi.ctype*, bb: ImRect, flags: TabItemFlags, frame_padding: ImVec2, label: string, tab_id: number, close_button_id: number, is_contents_visible: boolean, out_just_closed: ffi.cdata*|ffi.cdecl*|ffi.ctype*, out_text_clipped: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>draw_list</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImDrawList*</td>
    </tr>
    <tr>
      <td><code>bb</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>TabItemFlags</code></td>
      <td>да</td>
      <td>-----------------------TabItemFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>frame_padding</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>tab_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>close_button_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>is_contents_visible</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>out_just_closed</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>bool*</td>
    </tr>
    <tr>
      <td><code>out_text_clipped</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>bool*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TableAngledHeadersRow`

#### Сигнатура

```lua
function imgui.TableAngledHeadersRow()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.TableAngledHeadersRowEx`

#### Сигнатура

```lua
function imgui.TableAngledHeadersRowEx(angle: number, max_label_width?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>angle</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>max_label_width</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TableBeginApplyRequests`

#### Сигнатура

```lua
function imgui.TableBeginApplyRequests(table: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>table</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTable*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TableBeginCell`

#### Сигнатура

```lua
function imgui.TableBeginCell(table: ffi.cdata*|ffi.cdecl*|ffi.ctype*, column_n: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>table</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTable*</td>
    </tr>
    <tr>
      <td><code>column_n</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TableBeginContextMenuPopup`

#### Сигнатура

```lua
function imgui.TableBeginContextMenuPopup(table: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>table</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTable*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.TableBeginInitMemory`

#### Сигнатура

```lua
function imgui.TableBeginInitMemory(table: ffi.cdata*|ffi.cdecl*|ffi.ctype*, columns_count: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>table</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTable*</td>
    </tr>
    <tr>
      <td><code>columns_count</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TableBeginRow`

#### Сигнатура

```lua
function imgui.TableBeginRow(table: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>table</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTable*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TableDrawBorders`

#### Сигнатура

```lua
function imgui.TableDrawBorders(table: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>table</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTable*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TableDrawDefaultContextMenu`

#### Сигнатура

```lua
function imgui.TableDrawDefaultContextMenu(table: ffi.cdata*|ffi.cdecl*|ffi.ctype*, flags_for_section_to_display: TableFlags)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>table</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTable*</td>
    </tr>
    <tr>
      <td><code>flags_for_section_to_display</code></td>
      <td><code>TableFlags</code></td>
      <td>да</td>
      <td>-----------------------TableFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TableEndCell`

#### Сигнатура

```lua
function imgui.TableEndCell(table: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>table</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTable*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TableEndRow`

#### Сигнатура

```lua
function imgui.TableEndRow(table: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>table</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTable*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TableFindByID`

#### Сигнатура

```lua
function imgui.TableFindByID(id: number)
  -> ImGuiTable*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.TableFixColumnSortDirection`

#### Сигнатура

```lua
function imgui.TableFixColumnSortDirection(table: ffi.cdata*|ffi.cdecl*|ffi.ctype*, column: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>table</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTable*</td>
    </tr>
    <tr>
      <td><code>column</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTableColumn*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TableGcCompactSettings`

#### Сигнатура

```lua
function imgui.TableGcCompactSettings()
  -> nil
```

#### Возвращает

- `nil` 

### ~~Функция `imgui.TableGcCompactTransientBuffers`~~

 generic version

#### Сигнатура

```lua
function imgui.TableGcCompactTransientBuffers(a1: any)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TableGcCompactTransientBuffers_TablePtr`

#### Сигнатура

```lua
function imgui.TableGcCompactTransientBuffers_TablePtr(table: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>table</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTable*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TableGcCompactTransientBuffers_TableTempDataPtr`

#### Сигнатура

```lua
function imgui.TableGcCompactTransientBuffers_TableTempDataPtr(table: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>table</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTableTempData*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TableGetBoundSettings`

#### Сигнатура

```lua
function imgui.TableGetBoundSettings(table: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> ImGuiTableSettings*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>table</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTable*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.TableGetCellBgRect`

#### Сигнатура

```lua
function imgui.TableGetCellBgRect(table: ffi.cdata*|ffi.cdecl*|ffi.ctype*, column_n: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>table</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImGuiTable*</td>
    </tr>
    <tr>
      <td><code>column_n</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TableGetColumnCount`

#### Сигнатура

```lua
function imgui.TableGetColumnCount()
  -> int: number
```

#### Возвращает

- `number` 

### Функция `imgui.TableGetColumnFlags`

#### Сигнатура

```lua
function imgui.TableGetColumnFlags(column_n?: number)
  -> TableColumnFlags
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>column_n</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `TableColumnFlags` 

### Функция `imgui.TableGetColumnIndex`

#### Сигнатура

```lua
function imgui.TableGetColumnIndex()
  -> int: number
```

#### Возвращает

- `number` 

### ~~Функция `imgui.TableGetColumnName`~~

 generic version

#### Сигнатура

```lua
function imgui.TableGetColumnName(a1: any, a2: any)
  -> string
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `string` 

### Функция `imgui.TableGetColumnName_Int`

#### Сигнатура

```lua
function imgui.TableGetColumnName_Int(column_n?: number)
  -> string
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>column_n</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `string` 

### Функция `imgui.TableGetColumnName_TablePtr`

#### Сигнатура

```lua
function imgui.TableGetColumnName_TablePtr(table: ffi.cdata*|ffi.cdecl*|ffi.ctype*, column_n: number)
  -> string
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>table</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImGuiTable*</td>
    </tr>
    <tr>
      <td><code>column_n</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `string` 

### Функция `imgui.TableGetColumnNextSortDirection`

#### Сигнатура

```lua
function imgui.TableGetColumnNextSortDirection(column: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> SortDirection
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>column</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTableColumn*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `SortDirection` 

### Функция `imgui.TableGetColumnResizeID`

#### Сигнатура

```lua
function imgui.TableGetColumnResizeID(table: ffi.cdata*|ffi.cdecl*|ffi.ctype*, column_n: number, instance_no?: number)
  -> ImGuiID: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>table</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTable*</td>
    </tr>
    <tr>
      <td><code>column_n</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>instance_no</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.TableGetColumnWidthAuto`

#### Сигнатура

```lua
function imgui.TableGetColumnWidthAuto(table: ffi.cdata*|ffi.cdecl*|ffi.ctype*, column: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> float: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>table</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTable*</td>
    </tr>
    <tr>
      <td><code>column</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTableColumn*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.TableGetHeaderAngledMaxLabelWidth`

#### Сигнатура

```lua
function imgui.TableGetHeaderAngledMaxLabelWidth()
  -> float: number
```

#### Возвращает

- `number` 

### Функция `imgui.TableGetHeaderRowHeight`

#### Сигнатура

```lua
function imgui.TableGetHeaderRowHeight()
  -> float: number
```

#### Возвращает

- `number` 

### Функция `imgui.TableGetHoveredColumn`

#### Сигнатура

```lua
function imgui.TableGetHoveredColumn()
  -> int: number
```

#### Возвращает

- `number` 

### Функция `imgui.TableGetHoveredRow`

#### Сигнатура

```lua
function imgui.TableGetHoveredRow()
  -> int: number
```

#### Возвращает

- `number` 

### Функция `imgui.TableGetInstanceData`

#### Сигнатура

```lua
function imgui.TableGetInstanceData(table: ffi.cdata*|ffi.cdecl*|ffi.ctype*, instance_no: number)
  -> ImGuiTableInstanceData*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>table</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTable*</td>
    </tr>
    <tr>
      <td><code>instance_no</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.TableGetInstanceID`

#### Сигнатура

```lua
function imgui.TableGetInstanceID(table: ffi.cdata*|ffi.cdecl*|ffi.ctype*, instance_no: number)
  -> ImGuiID: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>table</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTable*</td>
    </tr>
    <tr>
      <td><code>instance_no</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.TableGetMaxColumnWidth`

#### Сигнатура

```lua
function imgui.TableGetMaxColumnWidth(table: ffi.cdata*|ffi.cdecl*|ffi.ctype*, column_n: number)
  -> float: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>table</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImGuiTable*</td>
    </tr>
    <tr>
      <td><code>column_n</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.TableGetRowIndex`

#### Сигнатура

```lua
function imgui.TableGetRowIndex()
  -> int: number
```

#### Возвращает

- `number` 

### Функция `imgui.TableGetSortSpecs`

#### Сигнатура

```lua
function imgui.TableGetSortSpecs()
  -> ImGuiTableSortSpecs*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.TableHeader`

#### Сигнатура

```lua
function imgui.TableHeader(label: string)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TableHeadersRow`

#### Сигнатура

```lua
function imgui.TableHeadersRow()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.TableLoadSettings`

#### Сигнатура

```lua
function imgui.TableLoadSettings(table: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>table</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTable*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TableMergeDrawChannels`

#### Сигнатура

```lua
function imgui.TableMergeDrawChannels(table: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>table</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTable*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TableNextColumn`

#### Сигнатура

```lua
function imgui.TableNextColumn()
  -> boolean
```

#### Возвращает

- `boolean` 

### Функция `imgui.TableNextRow`

#### Сигнатура

```lua
function imgui.TableNextRow(row_flags?: TableRowFlags, min_row_height?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>row_flags</code></td>
      <td><code>TableRowFlags</code></td>
      <td>нет</td>
      <td>-----------------------TableRowFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>min_row_height</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TableOpenContextMenu`

#### Сигнатура

```lua
function imgui.TableOpenContextMenu(column_n?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>column_n</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TablePopBackgroundChannel`

#### Сигнатура

```lua
function imgui.TablePopBackgroundChannel()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.TablePushBackgroundChannel`

#### Сигнатура

```lua
function imgui.TablePushBackgroundChannel()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.TableRemove`

#### Сигнатура

```lua
function imgui.TableRemove(table: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>table</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTable*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TableResetSettings`

#### Сигнатура

```lua
function imgui.TableResetSettings(table: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>table</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTable*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TableSaveSettings`

#### Сигнатура

```lua
function imgui.TableSaveSettings(table: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>table</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTable*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TableSetBgColor`

#### Сигнатура

```lua
function imgui.TableSetBgColor(target: TableBgTarget, color: number, column_n?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>target</code></td>
      <td><code>TableBgTarget</code></td>
      <td>да</td>
      <td>-----------------------TableBgTarget----------------------------</td>
    </tr>
    <tr>
      <td><code>color</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
    <tr>
      <td><code>column_n</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TableSetColumnEnabled`

#### Сигнатура

```lua
function imgui.TableSetColumnEnabled(column_n: number, v: boolean)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>column_n</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TableSetColumnIndex`

#### Сигнатура

```lua
function imgui.TableSetColumnIndex(column_n: number)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>column_n</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.TableSetColumnSortDirection`

#### Сигнатура

```lua
function imgui.TableSetColumnSortDirection(column_n: number, sort_direction: SortDirection, append_to_sort_specs: boolean)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>column_n</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>sort_direction</code></td>
      <td><code>SortDirection</code></td>
      <td>да</td>
      <td>-----------------------SortDirection----------------------------</td>
    </tr>
    <tr>
      <td><code>append_to_sort_specs</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TableSetColumnWidth`

#### Сигнатура

```lua
function imgui.TableSetColumnWidth(column_n: number, width: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>column_n</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>width</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TableSetColumnWidthAutoAll`

#### Сигнатура

```lua
function imgui.TableSetColumnWidthAutoAll(table: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>table</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTable*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TableSetColumnWidthAutoSingle`

#### Сигнатура

```lua
function imgui.TableSetColumnWidthAutoSingle(table: ffi.cdata*|ffi.cdecl*|ffi.ctype*, column_n: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>table</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTable*</td>
    </tr>
    <tr>
      <td><code>column_n</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TableSettingsAddSettingsHandler`

#### Сигнатура

```lua
function imgui.TableSettingsAddSettingsHandler()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.TableSettingsCreate`

#### Сигнатура

```lua
function imgui.TableSettingsCreate(id: number, columns_count: number)
  -> ImGuiTableSettings*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>columns_count</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.TableSettingsFindByID`

#### Сигнатура

```lua
function imgui.TableSettingsFindByID(id: number)
  -> ImGuiTableSettings*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `imgui.TableSetupColumn`

#### Сигнатура

```lua
function imgui.TableSetupColumn(label: string, flags?: TableColumnFlags, init_width_or_weight?: number, user_id?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>TableColumnFlags</code></td>
      <td>нет</td>
      <td>-----------------------TableColumnFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>init_width_or_weight</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>user_id</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TableSetupDrawChannels`

#### Сигнатура

```lua
function imgui.TableSetupDrawChannels(table: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>table</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTable*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TableSetupScrollFreeze`

#### Сигнатура

```lua
function imgui.TableSetupScrollFreeze(cols: number, rows: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>cols</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>rows</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TableSortSpecsBuild`

#### Сигнатура

```lua
function imgui.TableSortSpecsBuild(table: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>table</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTable*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TableSortSpecsSanitize`

#### Сигнатура

```lua
function imgui.TableSortSpecsSanitize(table: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>table</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTable*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TableUpdateBorders`

#### Сигнатура

```lua
function imgui.TableUpdateBorders(table: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>table</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTable*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TableUpdateColumnsWeightFromWidth`

#### Сигнатура

```lua
function imgui.TableUpdateColumnsWeightFromWidth(table: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>table</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTable*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TableUpdateLayout`

#### Сигнатура

```lua
function imgui.TableUpdateLayout(table: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>table</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTable*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TeleportMousePos`

#### Сигнатура

```lua
function imgui.TeleportMousePos(pos: ImVec2)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>pos</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TempInputIsActive`

#### Сигнатура

```lua
function imgui.TempInputIsActive(id: number)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.TempInputScalar`

#### Сигнатура

```lua
function imgui.TempInputScalar(bb: ImRect, id: number, label: string, data_type: DataType, p_data: ffi.cdata*|ffi.cdecl*|ffi.ctype*, format: string, p_clamp_min?: ffi.cdata*|ffi.cdecl*|ffi.ctype*, p_clamp_max?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>bb</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>data_type</code></td>
      <td><code>DataType</code></td>
      <td>да</td>
      <td>-----------------------DataType----------------------------</td>
    </tr>
    <tr>
      <td><code>p_data</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>void*</td>
    </tr>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>p_clamp_min</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>const void*</td>
    </tr>
    <tr>
      <td><code>p_clamp_max</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>const void*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.TempInputText`

#### Сигнатура

```lua
function imgui.TempInputText(bb: ImRect, id: number, label: string, buf: ffi.cdata*|ffi.cdecl*|ffi.ctype*, buf_size: number, flags: InputTextFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>bb</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>buf</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>char*</td>
    </tr>
    <tr>
      <td><code>buf_size</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>InputTextFlags</code></td>
      <td>да</td>
      <td>-----------------------InputTextFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.TestKeyOwner`

#### Сигнатура

```lua
function imgui.TestKeyOwner(key: Key, owner_id: number)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>Key</code></td>
      <td>да</td>
      <td>-----------------------Key----------------------------</td>
    </tr>
    <tr>
      <td><code>owner_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.TestShortcutRouting`

#### Сигнатура

```lua
function imgui.TestShortcutRouting(key_chord: number, owner_id: number)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key_chord</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiKeyChord</td>
    </tr>
    <tr>
      <td><code>owner_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.Text`

#### Сигнатура

```lua
function imgui.Text(fmt: string, ...any)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>fmt</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>...</code></td>
      <td><code>unknown</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TextColored`

#### Сигнатура

```lua
function imgui.TextColored(col: ffi.cdata*|ffi.cdecl*|ffi.ctype*, fmt: string, ...any)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>col</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImVec4</td>
    </tr>
    <tr>
      <td><code>fmt</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>...</code></td>
      <td><code>unknown</code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TextColoredV`

#### Сигнатура

```lua
function imgui.TextColoredV(col: ffi.cdata*|ffi.cdecl*|ffi.ctype*, fmt: string, args: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>col</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImVec4</td>
    </tr>
    <tr>
      <td><code>fmt</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>args</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>va_list</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TextDisabled`

#### Сигнатура

```lua
function imgui.TextDisabled(fmt: string, ...any)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>fmt</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>...</code></td>
      <td><code>unknown</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TextDisabledV`

#### Сигнатура

```lua
function imgui.TextDisabledV(fmt: string, args: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>fmt</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>args</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>va_list</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TextEx`

#### Сигнатура

```lua
function imgui.TextEx(text: string, text_end?: string, flags?: TextFlags)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>text</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>text_end</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>TextFlags</code></td>
      <td>нет</td>
      <td>-----------------------TextFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TextUnformatted`

#### Сигнатура

```lua
function imgui.TextUnformatted(text: string, text_end?: string)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>text</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>text_end</code></td>
      <td><code>string</code></td>
      <td>нет</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TextV`

#### Сигнатура

```lua
function imgui.TextV(fmt: string, args: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>fmt</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>args</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>va_list</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TextWrapped`

#### Сигнатура

```lua
function imgui.TextWrapped(fmt: string, ...any)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>fmt</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>...</code></td>
      <td><code>unknown</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TextWrappedV`

#### Сигнатура

```lua
function imgui.TextWrappedV(fmt: string, args: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>fmt</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>args</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>va_list</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### ~~Функция `imgui.ToUTF`~~

#### Сигнатура

```lua
function imgui.ToUTF(unc_str: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>unc_str</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Функция `imgui.TranslateWindowsInViewport`

#### Сигнатура

```lua
function imgui.TranslateWindowsInViewport(viewport: ffi.cdata*|ffi.cdecl*|ffi.ctype*, old_pos: ImVec2, new_pos: ImVec2)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>viewport</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiViewportP*</td>
    </tr>
    <tr>
      <td><code>old_pos</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>new_pos</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### ~~Функция `imgui.TreeNode`~~

 generic version

#### Сигнатура

```lua
function imgui.TreeNode(a1: any, a2: any, ...any)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>...</code></td>
      <td><code>unknown</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.TreeNodeBehavior`

#### Сигнатура

```lua
function imgui.TreeNodeBehavior(id: number, flags: TreeNodeFlags, label: string, label_end?: string)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>TreeNodeFlags</code></td>
      <td>да</td>
      <td>-----------------------TreeNodeFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>label_end</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### ~~Функция `imgui.TreeNodeEx`~~

 generic version

#### Сигнатура

```lua
function imgui.TreeNodeEx(a1: any, a2: any, a3: any, ...any)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a3</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>...</code></td>
      <td><code>unknown</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### ~~Функция `imgui.TreeNodeExV`~~

 generic version

#### Сигнатура

```lua
function imgui.TreeNodeExV(a1: any, a2: any, a3: any, a4: any)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a3</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a4</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.TreeNodeExV_Ptr`

#### Сигнатура

```lua
function imgui.TreeNodeExV_Ptr(ptr_id: ffi.cdata*|ffi.cdecl*|ffi.ctype*, flags: TreeNodeFlags, fmt: string, args: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ptr_id</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const void*</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>TreeNodeFlags</code></td>
      <td>да</td>
      <td>-----------------------TreeNodeFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>fmt</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>args</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>va_list</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.TreeNodeExV_Str`

#### Сигнатура

```lua
function imgui.TreeNodeExV_Str(str_id: string, flags: TreeNodeFlags, fmt: string, args: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>str_id</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>TreeNodeFlags</code></td>
      <td>да</td>
      <td>-----------------------TreeNodeFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>fmt</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>args</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>va_list</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.TreeNodeEx_Ptr`

#### Сигнатура

```lua
function imgui.TreeNodeEx_Ptr(ptr_id: ffi.cdata*|ffi.cdecl*|ffi.ctype*, flags: TreeNodeFlags, fmt: string, ...any)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ptr_id</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const void*</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>TreeNodeFlags</code></td>
      <td>да</td>
      <td>-----------------------TreeNodeFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>fmt</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>...</code></td>
      <td><code>unknown</code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.TreeNodeEx_Str`

#### Сигнатура

```lua
function imgui.TreeNodeEx_Str(label: string, flags?: TreeNodeFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>TreeNodeFlags</code></td>
      <td>нет</td>
      <td>-----------------------TreeNodeFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.TreeNodeEx_StrStr`

#### Сигнатура

```lua
function imgui.TreeNodeEx_StrStr(str_id: string, flags: TreeNodeFlags, fmt: string, ...any)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>str_id</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>TreeNodeFlags</code></td>
      <td>да</td>
      <td>-----------------------TreeNodeFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>fmt</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>...</code></td>
      <td><code>unknown</code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.TreeNodeSetOpen`

#### Сигнатура

```lua
function imgui.TreeNodeSetOpen(id: number, open: boolean)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>open</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TreeNodeUpdateNextOpen`

#### Сигнатура

```lua
function imgui.TreeNodeUpdateNextOpen(id: number, flags: TreeNodeFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>TreeNodeFlags</code></td>
      <td>да</td>
      <td>-----------------------TreeNodeFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### ~~Функция `imgui.TreeNodeV`~~

 generic version

#### Сигнатура

```lua
function imgui.TreeNodeV(a1: any, a2: any, a3: any)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a3</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.TreeNodeV_Ptr`

#### Сигнатура

```lua
function imgui.TreeNodeV_Ptr(ptr_id: ffi.cdata*|ffi.cdecl*|ffi.ctype*, fmt: string, args: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ptr_id</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const void*</td>
    </tr>
    <tr>
      <td><code>fmt</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>args</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>va_list</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.TreeNodeV_Str`

#### Сигнатура

```lua
function imgui.TreeNodeV_Str(str_id: string, fmt: string, args: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>str_id</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>fmt</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>args</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>va_list</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.TreeNode_Ptr`

#### Сигнатура

```lua
function imgui.TreeNode_Ptr(ptr_id: ffi.cdata*|ffi.cdecl*|ffi.ctype*, fmt: string, ...any)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ptr_id</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const void*</td>
    </tr>
    <tr>
      <td><code>fmt</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>...</code></td>
      <td><code>unknown</code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.TreeNode_Str`

#### Сигнатура

```lua
function imgui.TreeNode_Str(label: string)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.TreeNode_StrStr`

#### Сигнатура

```lua
function imgui.TreeNode_StrStr(str_id: string, fmt: string, ...any)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>str_id</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>fmt</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>...</code></td>
      <td><code>unknown</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.TreePop`

#### Сигнатура

```lua
function imgui.TreePop()
  -> nil
```

#### Возвращает

- `nil` 

### ~~Функция `imgui.TreePush`~~

 generic version

#### Сигнатура

```lua
function imgui.TreePush(a1: any)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TreePushOverrideID`

#### Сигнатура

```lua
function imgui.TreePushOverrideID(id: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TreePush_Ptr`

#### Сигнатура

```lua
function imgui.TreePush_Ptr(ptr_id: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ptr_id</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const void*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TreePush_Str`

#### Сигнатура

```lua
function imgui.TreePush_Str(str_id: string)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>str_id</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.TypingSelectFindBestLeadingMatch`

#### Сигнатура

```lua
function imgui.TypingSelectFindBestLeadingMatch(req: ffi.cdata*|ffi.cdecl*|ffi.ctype*, items_count: number, get_item_name_func: ffi.cdata*|ffi.cdecl*|ffi.ctype*, user_data: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> int: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>req</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTypingSelectRequest*</td>
    </tr>
    <tr>
      <td><code>items_count</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>get_item_name_func</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const char*(*)(void*,int)</td>
    </tr>
    <tr>
      <td><code>user_data</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>void*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.TypingSelectFindMatch`

#### Сигнатура

```lua
function imgui.TypingSelectFindMatch(req: ffi.cdata*|ffi.cdecl*|ffi.ctype*, items_count: number, get_item_name_func: ffi.cdata*|ffi.cdecl*|ffi.ctype*, user_data: ffi.cdata*|ffi.cdecl*|ffi.ctype*, nav_item_idx: number)
  -> int: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>req</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTypingSelectRequest*</td>
    </tr>
    <tr>
      <td><code>items_count</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>get_item_name_func</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const char*(*)(void*,int)</td>
    </tr>
    <tr>
      <td><code>user_data</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>void*</td>
    </tr>
    <tr>
      <td><code>nav_item_idx</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.TypingSelectFindNextSingleCharMatch`

#### Сигнатура

```lua
function imgui.TypingSelectFindNextSingleCharMatch(req: ffi.cdata*|ffi.cdecl*|ffi.ctype*, items_count: number, get_item_name_func: ffi.cdata*|ffi.cdecl*|ffi.ctype*, user_data: ffi.cdata*|ffi.cdecl*|ffi.ctype*, nav_item_idx: number)
  -> int: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>req</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiTypingSelectRequest*</td>
    </tr>
    <tr>
      <td><code>items_count</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>get_item_name_func</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const char*(*)(void*,int)</td>
    </tr>
    <tr>
      <td><code>user_data</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>void*</td>
    </tr>
    <tr>
      <td><code>nav_item_idx</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `imgui.Unindent`

#### Сигнатура

```lua
function imgui.Unindent(indent_w?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>indent_w</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.UpdateHoveredWindowAndCaptureFlags`

#### Сигнатура

```lua
function imgui.UpdateHoveredWindowAndCaptureFlags()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.UpdateInputEvents`

#### Сигнатура

```lua
function imgui.UpdateInputEvents(trickle_fast_inputs: boolean)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>trickle_fast_inputs</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.UpdateMouseMovingWindowEndFrame`

#### Сигнатура

```lua
function imgui.UpdateMouseMovingWindowEndFrame()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.UpdateMouseMovingWindowNewFrame`

#### Сигнатура

```lua
function imgui.UpdateMouseMovingWindowNewFrame()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.UpdatePlatformWindows`

#### Сигнатура

```lua
function imgui.UpdatePlatformWindows()
  -> nil
```

#### Возвращает

- `nil` 

### Функция `imgui.UpdateWindowParentAndRootLinks`

#### Сигнатура

```lua
function imgui.UpdateWindowParentAndRootLinks(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, flags: WindowFlags, parent_window: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>WindowFlags</code></td>
      <td>да</td>
      <td>-----------------------WindowFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>parent_window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.VSliderFloat`

#### Сигнатура

```lua
function imgui.VSliderFloat(label: string, size: ImVec2, v: ffi.cdata*|ffi.cdecl*|ffi.ctype*, v_min: number, v_max: number, format?: string, flags?: SliderFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>size</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>float*</td>
    </tr>
    <tr>
      <td><code>v_min</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>v_max</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>SliderFlags</code></td>
      <td>нет</td>
      <td>-----------------------SliderFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.VSliderInt`

#### Сигнатура

```lua
function imgui.VSliderInt(label: string, size: ImVec2, v: ffi.cdata*|ffi.cdecl*|ffi.ctype*, v_min: number, v_max: number, format?: string, flags?: SliderFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>size</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>int*</td>
    </tr>
    <tr>
      <td><code>v_min</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>v_max</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>SliderFlags</code></td>
      <td>нет</td>
      <td>-----------------------SliderFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Функция `imgui.VSliderScalar`

#### Сигнатура

```lua
function imgui.VSliderScalar(label: string, size: ImVec2, data_type: DataType, p_data: ffi.cdata*|ffi.cdecl*|ffi.ctype*, p_min: ffi.cdata*|ffi.cdecl*|ffi.ctype*, p_max: ffi.cdata*|ffi.cdecl*|ffi.ctype*, format?: string, flags?: SliderFlags)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>size</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>data_type</code></td>
      <td><code>DataType</code></td>
      <td>да</td>
      <td>-----------------------DataType----------------------------</td>
    </tr>
    <tr>
      <td><code>p_data</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>void*</td>
    </tr>
    <tr>
      <td><code>p_min</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const void*</td>
    </tr>
    <tr>
      <td><code>p_max</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const void*</td>
    </tr>
    <tr>
      <td><code>format</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>SliderFlags</code></td>
      <td>нет</td>
      <td>-----------------------SliderFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### ~~Функция `imgui.Value`~~

 generic version

#### Сигнатура

```lua
function imgui.Value(a1: any, a2: any, a3: any)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a3</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.Value_Bool`

#### Сигнатура

```lua
function imgui.Value_Bool(prefix: string, b: boolean)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>prefix</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>b</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.Value_Float`

#### Сигнатура

```lua
function imgui.Value_Float(prefix: string, v: number, float_format?: string)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>prefix</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>float_format</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.Value_Int`

#### Сигнатура

```lua
function imgui.Value_Int(prefix: string, v: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>prefix</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.Value_Uint`

#### Сигнатура

```lua
function imgui.Value_Uint(prefix: string, v: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>prefix</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>unsigned int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.WindowPosRelToAbs`

#### Сигнатура

```lua
function imgui.WindowPosRelToAbs(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, p: ImVec2)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>p</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.WindowRectAbsToRel`

#### Сигнатура

```lua
function imgui.WindowRectAbsToRel(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, r: ImRect)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>r</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Функция `imgui.WindowRectRelToAbs`

#### Сигнатура

```lua
function imgui.WindowRectRelToAbs(window: ffi.cdata*|ffi.cdecl*|ffi.ctype*, r: ImRect)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>window</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiWindow*</td>
    </tr>
    <tr>
      <td><code>r</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Энумерация `ActivateFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ActivateFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>ActivateFlags.PreferInput</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>ActivateFlags.PreferTweak</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>ActivateFlags.TryToPreserveState</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>ActivateFlags.FromTabbing</code></td>
      <td><code>8</code></td>
    </tr>
    <tr>
      <td><code>ActivateFlags.FromShortcut</code></td>
      <td><code>16</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `Axis`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>Axis.None</code></td>
      <td><code>-1</code></td>
    </tr>
    <tr>
      <td><code>Axis.X</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>Axis.Y</code></td>
      <td><code>1</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `BackendFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>BackendFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>BackendFlags.HasGamepad</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>BackendFlags.HasMouseCursors</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>BackendFlags.HasSetMousePos</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>BackendFlags.RendererHasVtxOffset</code></td>
      <td><code>8</code></td>
    </tr>
    <tr>
      <td><code>BackendFlags.PlatformHasViewports</code></td>
      <td><code>1024</code></td>
    </tr>
    <tr>
      <td><code>BackendFlags.HasMouseHoveredViewport</code></td>
      <td><code>2048</code></td>
    </tr>
    <tr>
      <td><code>BackendFlags.RendererHasViewports</code></td>
      <td><code>4096</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `ButtonFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ButtonFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>ButtonFlags.MouseButtonDefault_</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>ButtonFlags.MouseButtonLeft</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>ButtonFlags.MouseButtonRight</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>ButtonFlags.MouseButtonMiddle</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>ButtonFlags.MouseButtonMask_</code></td>
      <td><code>7</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `ButtonFlagsPrivate`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ButtonFlagsPrivate.PressedOnClick</code></td>
      <td><code>16</code></td>
    </tr>
    <tr>
      <td><code>ButtonFlagsPrivate.PressedOnClickRelease</code></td>
      <td><code>32</code></td>
    </tr>
    <tr>
      <td><code>ButtonFlagsPrivate.PressedOnDefault_</code></td>
      <td><code>32</code></td>
    </tr>
    <tr>
      <td><code>ButtonFlagsPrivate.PressedOnClickReleaseAnywhere</code></td>
      <td><code>64</code></td>
    </tr>
    <tr>
      <td><code>ButtonFlagsPrivate.PressedOnRelease</code></td>
      <td><code>128</code></td>
    </tr>
    <tr>
      <td><code>ButtonFlagsPrivate.PressedOnDoubleClick</code></td>
      <td><code>256</code></td>
    </tr>
    <tr>
      <td><code>ButtonFlagsPrivate.PressedOnDragDropHold</code></td>
      <td><code>512</code></td>
    </tr>
    <tr>
      <td><code>ButtonFlagsPrivate.PressedOnMask_</code></td>
      <td><code>1008</code></td>
    </tr>
    <tr>
      <td><code>ButtonFlagsPrivate.Repeat</code></td>
      <td><code>1024</code></td>
    </tr>
    <tr>
      <td><code>ButtonFlagsPrivate.FlattenChildren</code></td>
      <td><code>2048</code></td>
    </tr>
    <tr>
      <td><code>ButtonFlagsPrivate.AllowOverlap</code></td>
      <td><code>4096</code></td>
    </tr>
    <tr>
      <td><code>ButtonFlagsPrivate.DontClosePopups</code></td>
      <td><code>8192</code></td>
    </tr>
    <tr>
      <td><code>ButtonFlagsPrivate.AlignTextBaseLine</code></td>
      <td><code>32768</code></td>
    </tr>
    <tr>
      <td><code>ButtonFlagsPrivate.NoKeyModifiers</code></td>
      <td><code>65536</code></td>
    </tr>
    <tr>
      <td><code>ButtonFlagsPrivate.NoHoldingActiveId</code></td>
      <td><code>131072</code></td>
    </tr>
    <tr>
      <td><code>ButtonFlagsPrivate.NoNavFocus</code></td>
      <td><code>262144</code></td>
    </tr>
    <tr>
      <td><code>ButtonFlagsPrivate.NoHoveredOnFocus</code></td>
      <td><code>524288</code></td>
    </tr>
    <tr>
      <td><code>ButtonFlagsPrivate.NoSetKeyOwner</code></td>
      <td><code>1048576</code></td>
    </tr>
    <tr>
      <td><code>ButtonFlagsPrivate.NoTestKeyOwner</code></td>
      <td><code>2097152</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `ChildFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ChildFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>ChildFlags.Border</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>ChildFlags.AlwaysUseWindowPadding</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>ChildFlags.ResizeX</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>ChildFlags.ResizeY</code></td>
      <td><code>8</code></td>
    </tr>
    <tr>
      <td><code>ChildFlags.AutoResizeX</code></td>
      <td><code>16</code></td>
    </tr>
    <tr>
      <td><code>ChildFlags.AutoResizeY</code></td>
      <td><code>32</code></td>
    </tr>
    <tr>
      <td><code>ChildFlags.AlwaysAutoResize</code></td>
      <td><code>64</code></td>
    </tr>
    <tr>
      <td><code>ChildFlags.FrameStyle</code></td>
      <td><code>128</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `Col`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>Col.Text</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>Col.TextDisabled</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>Col.WindowBg</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>Col.ChildBg</code></td>
      <td><code>3</code></td>
    </tr>
    <tr>
      <td><code>Col.PopupBg</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>Col.Border</code></td>
      <td><code>5</code></td>
    </tr>
    <tr>
      <td><code>Col.BorderShadow</code></td>
      <td><code>6</code></td>
    </tr>
    <tr>
      <td><code>Col.FrameBg</code></td>
      <td><code>7</code></td>
    </tr>
    <tr>
      <td><code>Col.FrameBgHovered</code></td>
      <td><code>8</code></td>
    </tr>
    <tr>
      <td><code>Col.FrameBgActive</code></td>
      <td><code>9</code></td>
    </tr>
    <tr>
      <td><code>Col.TitleBg</code></td>
      <td><code>10</code></td>
    </tr>
    <tr>
      <td><code>Col.TitleBgActive</code></td>
      <td><code>11</code></td>
    </tr>
    <tr>
      <td><code>Col.TitleBgCollapsed</code></td>
      <td><code>12</code></td>
    </tr>
    <tr>
      <td><code>Col.MenuBarBg</code></td>
      <td><code>13</code></td>
    </tr>
    <tr>
      <td><code>Col.ScrollbarBg</code></td>
      <td><code>14</code></td>
    </tr>
    <tr>
      <td><code>Col.ScrollbarGrab</code></td>
      <td><code>15</code></td>
    </tr>
    <tr>
      <td><code>Col.ScrollbarGrabHovered</code></td>
      <td><code>16</code></td>
    </tr>
    <tr>
      <td><code>Col.ScrollbarGrabActive</code></td>
      <td><code>17</code></td>
    </tr>
    <tr>
      <td><code>Col.CheckMark</code></td>
      <td><code>18</code></td>
    </tr>
    <tr>
      <td><code>Col.SliderGrab</code></td>
      <td><code>19</code></td>
    </tr>
    <tr>
      <td><code>Col.SliderGrabActive</code></td>
      <td><code>20</code></td>
    </tr>
    <tr>
      <td><code>Col.Button</code></td>
      <td><code>21</code></td>
    </tr>
    <tr>
      <td><code>Col.ButtonHovered</code></td>
      <td><code>22</code></td>
    </tr>
    <tr>
      <td><code>Col.ButtonActive</code></td>
      <td><code>23</code></td>
    </tr>
    <tr>
      <td><code>Col.Header</code></td>
      <td><code>24</code></td>
    </tr>
    <tr>
      <td><code>Col.HeaderHovered</code></td>
      <td><code>25</code></td>
    </tr>
    <tr>
      <td><code>Col.HeaderActive</code></td>
      <td><code>26</code></td>
    </tr>
    <tr>
      <td><code>Col.Separator</code></td>
      <td><code>27</code></td>
    </tr>
    <tr>
      <td><code>Col.SeparatorHovered</code></td>
      <td><code>28</code></td>
    </tr>
    <tr>
      <td><code>Col.SeparatorActive</code></td>
      <td><code>29</code></td>
    </tr>
    <tr>
      <td><code>Col.ResizeGrip</code></td>
      <td><code>30</code></td>
    </tr>
    <tr>
      <td><code>Col.ResizeGripHovered</code></td>
      <td><code>31</code></td>
    </tr>
    <tr>
      <td><code>Col.ResizeGripActive</code></td>
      <td><code>32</code></td>
    </tr>
    <tr>
      <td><code>Col.Tab</code></td>
      <td><code>33</code></td>
    </tr>
    <tr>
      <td><code>Col.TabHovered</code></td>
      <td><code>34</code></td>
    </tr>
    <tr>
      <td><code>Col.TabActive</code></td>
      <td><code>35</code></td>
    </tr>
    <tr>
      <td><code>Col.TabUnfocused</code></td>
      <td><code>36</code></td>
    </tr>
    <tr>
      <td><code>Col.TabUnfocusedActive</code></td>
      <td><code>37</code></td>
    </tr>
    <tr>
      <td><code>Col.DockingPreview</code></td>
      <td><code>38</code></td>
    </tr>
    <tr>
      <td><code>Col.DockingEmptyBg</code></td>
      <td><code>39</code></td>
    </tr>
    <tr>
      <td><code>Col.PlotLines</code></td>
      <td><code>40</code></td>
    </tr>
    <tr>
      <td><code>Col.PlotLinesHovered</code></td>
      <td><code>41</code></td>
    </tr>
    <tr>
      <td><code>Col.PlotHistogram</code></td>
      <td><code>42</code></td>
    </tr>
    <tr>
      <td><code>Col.PlotHistogramHovered</code></td>
      <td><code>43</code></td>
    </tr>
    <tr>
      <td><code>Col.TableHeaderBg</code></td>
      <td><code>44</code></td>
    </tr>
    <tr>
      <td><code>Col.TableBorderStrong</code></td>
      <td><code>45</code></td>
    </tr>
    <tr>
      <td><code>Col.TableBorderLight</code></td>
      <td><code>46</code></td>
    </tr>
    <tr>
      <td><code>Col.TableRowBg</code></td>
      <td><code>47</code></td>
    </tr>
    <tr>
      <td><code>Col.TableRowBgAlt</code></td>
      <td><code>48</code></td>
    </tr>
    <tr>
      <td><code>Col.TextSelectedBg</code></td>
      <td><code>49</code></td>
    </tr>
    <tr>
      <td><code>Col.DragDropTarget</code></td>
      <td><code>50</code></td>
    </tr>
    <tr>
      <td><code>Col.NavHighlight</code></td>
      <td><code>51</code></td>
    </tr>
    <tr>
      <td><code>Col.NavWindowingHighlight</code></td>
      <td><code>52</code></td>
    </tr>
    <tr>
      <td><code>Col.NavWindowingDimBg</code></td>
      <td><code>53</code></td>
    </tr>
    <tr>
      <td><code>Col.ModalWindowDimBg</code></td>
      <td><code>54</code></td>
    </tr>
    <tr>
      <td><code>Col.COUNT</code></td>
      <td><code>55</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `ColorEditFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ColorEditFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>ColorEditFlags.NoAlpha</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>ColorEditFlags.NoPicker</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>ColorEditFlags.NoOptions</code></td>
      <td><code>8</code></td>
    </tr>
    <tr>
      <td><code>ColorEditFlags.NoSmallPreview</code></td>
      <td><code>16</code></td>
    </tr>
    <tr>
      <td><code>ColorEditFlags.NoInputs</code></td>
      <td><code>32</code></td>
    </tr>
    <tr>
      <td><code>ColorEditFlags.NoTooltip</code></td>
      <td><code>64</code></td>
    </tr>
    <tr>
      <td><code>ColorEditFlags.NoLabel</code></td>
      <td><code>128</code></td>
    </tr>
    <tr>
      <td><code>ColorEditFlags.NoSidePreview</code></td>
      <td><code>256</code></td>
    </tr>
    <tr>
      <td><code>ColorEditFlags.NoDragDrop</code></td>
      <td><code>512</code></td>
    </tr>
    <tr>
      <td><code>ColorEditFlags.NoBorder</code></td>
      <td><code>1024</code></td>
    </tr>
    <tr>
      <td><code>ColorEditFlags.AlphaBar</code></td>
      <td><code>65536</code></td>
    </tr>
    <tr>
      <td><code>ColorEditFlags.AlphaPreview</code></td>
      <td><code>131072</code></td>
    </tr>
    <tr>
      <td><code>ColorEditFlags.AlphaPreviewHalf</code></td>
      <td><code>262144</code></td>
    </tr>
    <tr>
      <td><code>ColorEditFlags.HDR</code></td>
      <td><code>524288</code></td>
    </tr>
    <tr>
      <td><code>ColorEditFlags.DisplayRGB</code></td>
      <td><code>1048576</code></td>
    </tr>
    <tr>
      <td><code>ColorEditFlags.DisplayHSV</code></td>
      <td><code>2097152</code></td>
    </tr>
    <tr>
      <td><code>ColorEditFlags.DisplayHex</code></td>
      <td><code>4194304</code></td>
    </tr>
    <tr>
      <td><code>ColorEditFlags.DisplayMask_</code></td>
      <td><code>7340032</code></td>
    </tr>
    <tr>
      <td><code>ColorEditFlags.Uint8</code></td>
      <td><code>8388608</code></td>
    </tr>
    <tr>
      <td><code>ColorEditFlags.Float</code></td>
      <td><code>16777216</code></td>
    </tr>
    <tr>
      <td><code>ColorEditFlags.DataTypeMask_</code></td>
      <td><code>25165824</code></td>
    </tr>
    <tr>
      <td><code>ColorEditFlags.PickerHueBar</code></td>
      <td><code>33554432</code></td>
    </tr>
    <tr>
      <td><code>ColorEditFlags.PickerHueWheel</code></td>
      <td><code>67108864</code></td>
    </tr>
    <tr>
      <td><code>ColorEditFlags.PickerMask_</code></td>
      <td><code>100663296</code></td>
    </tr>
    <tr>
      <td><code>ColorEditFlags.InputRGB</code></td>
      <td><code>134217728</code></td>
    </tr>
    <tr>
      <td><code>ColorEditFlags.DefaultOptions_</code></td>
      <td><code>177209344</code></td>
    </tr>
    <tr>
      <td><code>ColorEditFlags.InputHSV</code></td>
      <td><code>268435456</code></td>
    </tr>
    <tr>
      <td><code>ColorEditFlags.InputMask_</code></td>
      <td><code>402653184</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `ComboFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ComboFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>ComboFlags.PopupAlignLeft</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>ComboFlags.HeightSmall</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>ComboFlags.HeightRegular</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>ComboFlags.HeightLarge</code></td>
      <td><code>8</code></td>
    </tr>
    <tr>
      <td><code>ComboFlags.HeightLargest</code></td>
      <td><code>16</code></td>
    </tr>
    <tr>
      <td><code>ComboFlags.HeightMask_</code></td>
      <td><code>30</code></td>
    </tr>
    <tr>
      <td><code>ComboFlags.NoArrowButton</code></td>
      <td><code>32</code></td>
    </tr>
    <tr>
      <td><code>ComboFlags.NoPreview</code></td>
      <td><code>64</code></td>
    </tr>
    <tr>
      <td><code>ComboFlags.WidthFitPreview</code></td>
      <td><code>128</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `ComboFlagsPrivate`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ComboFlagsPrivate.CustomPreview</code></td>
      <td><code>1048576</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `Cond`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>Cond.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>Cond.Always</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>Cond.Once</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>Cond.FirstUseEver</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>Cond.Appearing</code></td>
      <td><code>8</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `ConfigFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ConfigFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>ConfigFlags.NavEnableKeyboard</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>ConfigFlags.NavEnableGamepad</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>ConfigFlags.NavEnableSetMousePos</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>ConfigFlags.NavNoCaptureKeyboard</code></td>
      <td><code>8</code></td>
    </tr>
    <tr>
      <td><code>ConfigFlags.NoMouse</code></td>
      <td><code>16</code></td>
    </tr>
    <tr>
      <td><code>ConfigFlags.NoMouseCursorChange</code></td>
      <td><code>32</code></td>
    </tr>
    <tr>
      <td><code>ConfigFlags.DockingEnable</code></td>
      <td><code>64</code></td>
    </tr>
    <tr>
      <td><code>ConfigFlags.ViewportsEnable</code></td>
      <td><code>1024</code></td>
    </tr>
    <tr>
      <td><code>ConfigFlags.DpiEnableScaleViewports</code></td>
      <td><code>16384</code></td>
    </tr>
    <tr>
      <td><code>ConfigFlags.DpiEnableScaleFonts</code></td>
      <td><code>32768</code></td>
    </tr>
    <tr>
      <td><code>ConfigFlags.IsSRGB</code></td>
      <td><code>1048576</code></td>
    </tr>
    <tr>
      <td><code>ConfigFlags.IsTouchScreen</code></td>
      <td><code>2097152</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `ContextHookType`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ContextHookType.NewFramePre</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>ContextHookType.NewFramePost</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>ContextHookType.EndFramePre</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>ContextHookType.EndFramePost</code></td>
      <td><code>3</code></td>
    </tr>
    <tr>
      <td><code>ContextHookType.RenderPre</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>ContextHookType.RenderPost</code></td>
      <td><code>5</code></td>
    </tr>
    <tr>
      <td><code>ContextHookType.Shutdown</code></td>
      <td><code>6</code></td>
    </tr>
    <tr>
      <td><code>ContextHookType.PendingRemoval_</code></td>
      <td><code>7</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `DataAuthority`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>DataAuthority.Auto</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>DataAuthority.DockNode</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>DataAuthority.Window</code></td>
      <td><code>2</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `DataType`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>DataType.S8</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>DataType.U8</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>DataType.S16</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>DataType.U16</code></td>
      <td><code>3</code></td>
    </tr>
    <tr>
      <td><code>DataType.S32</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>DataType.U32</code></td>
      <td><code>5</code></td>
    </tr>
    <tr>
      <td><code>DataType.S64</code></td>
      <td><code>6</code></td>
    </tr>
    <tr>
      <td><code>DataType.U64</code></td>
      <td><code>7</code></td>
    </tr>
    <tr>
      <td><code>DataType.Float</code></td>
      <td><code>8</code></td>
    </tr>
    <tr>
      <td><code>DataType.Double</code></td>
      <td><code>9</code></td>
    </tr>
    <tr>
      <td><code>DataType.COUNT</code></td>
      <td><code>10</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `DataTypePrivate`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>DataTypePrivate.String</code></td>
      <td><code>11</code></td>
    </tr>
    <tr>
      <td><code>DataTypePrivate.Pointer</code></td>
      <td><code>12</code></td>
    </tr>
    <tr>
      <td><code>DataTypePrivate.ID</code></td>
      <td><code>13</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `DebugLogFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>DebugLogFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>DebugLogFlags.EventActiveId</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>DebugLogFlags.EventFocus</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>DebugLogFlags.EventPopup</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>DebugLogFlags.EventNav</code></td>
      <td><code>8</code></td>
    </tr>
    <tr>
      <td><code>DebugLogFlags.EventClipper</code></td>
      <td><code>16</code></td>
    </tr>
    <tr>
      <td><code>DebugLogFlags.EventSelection</code></td>
      <td><code>32</code></td>
    </tr>
    <tr>
      <td><code>DebugLogFlags.EventIO</code></td>
      <td><code>64</code></td>
    </tr>
    <tr>
      <td><code>DebugLogFlags.EventInputRouting</code></td>
      <td><code>128</code></td>
    </tr>
    <tr>
      <td><code>DebugLogFlags.EventDocking</code></td>
      <td><code>256</code></td>
    </tr>
    <tr>
      <td><code>DebugLogFlags.EventViewport</code></td>
      <td><code>512</code></td>
    </tr>
    <tr>
      <td><code>DebugLogFlags.EventMask_</code></td>
      <td><code>1023</code></td>
    </tr>
    <tr>
      <td><code>DebugLogFlags.OutputToTTY</code></td>
      <td><code>1048576</code></td>
    </tr>
    <tr>
      <td><code>DebugLogFlags.OutputToTestEngine</code></td>
      <td><code>2097152</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `Dir`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>Dir.None</code></td>
      <td><code>-1</code></td>
    </tr>
    <tr>
      <td><code>Dir.Left</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>Dir.Right</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>Dir.Up</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>Dir.Down</code></td>
      <td><code>3</code></td>
    </tr>
    <tr>
      <td><code>Dir.COUNT</code></td>
      <td><code>4</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `DockNodeFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>DockNodeFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>DockNodeFlags.KeepAliveOnly</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>DockNodeFlags.NoDockingOverCentralNode</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>DockNodeFlags.PassthruCentralNode</code></td>
      <td><code>8</code></td>
    </tr>
    <tr>
      <td><code>DockNodeFlags.NoDockingSplit</code></td>
      <td><code>16</code></td>
    </tr>
    <tr>
      <td><code>DockNodeFlags.NoResize</code></td>
      <td><code>32</code></td>
    </tr>
    <tr>
      <td><code>DockNodeFlags.AutoHideTabBar</code></td>
      <td><code>64</code></td>
    </tr>
    <tr>
      <td><code>DockNodeFlags.NoUndocking</code></td>
      <td><code>128</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `DockNodeFlagsPrivate`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>DockNodeFlagsPrivate.SharedFlagsInheritMask_</code></td>
      <td><code>-1</code></td>
    </tr>
    <tr>
      <td><code>DockNodeFlagsPrivate.DockSpace</code></td>
      <td><code>1024</code></td>
    </tr>
    <tr>
      <td><code>DockNodeFlagsPrivate.CentralNode</code></td>
      <td><code>2048</code></td>
    </tr>
    <tr>
      <td><code>DockNodeFlagsPrivate.NoTabBar</code></td>
      <td><code>4096</code></td>
    </tr>
    <tr>
      <td><code>DockNodeFlagsPrivate.HiddenTabBar</code></td>
      <td><code>8192</code></td>
    </tr>
    <tr>
      <td><code>DockNodeFlagsPrivate.NoWindowMenuButton</code></td>
      <td><code>16384</code></td>
    </tr>
    <tr>
      <td><code>DockNodeFlagsPrivate.NoCloseButton</code></td>
      <td><code>32768</code></td>
    </tr>
    <tr>
      <td><code>DockNodeFlagsPrivate.NoResizeX</code></td>
      <td><code>65536</code></td>
    </tr>
    <tr>
      <td><code>DockNodeFlagsPrivate.NoResizeY</code></td>
      <td><code>131072</code></td>
    </tr>
    <tr>
      <td><code>DockNodeFlagsPrivate.NoResizeFlagsMask_</code></td>
      <td><code>196640</code></td>
    </tr>
    <tr>
      <td><code>DockNodeFlagsPrivate.LocalFlagsTransferMask_</code></td>
      <td><code>260208</code></td>
    </tr>
    <tr>
      <td><code>DockNodeFlagsPrivate.SavedFlagsMask_</code></td>
      <td><code>261152</code></td>
    </tr>
    <tr>
      <td><code>DockNodeFlagsPrivate.DockedWindowsInFocusRoute</code></td>
      <td><code>262144</code></td>
    </tr>
    <tr>
      <td><code>DockNodeFlagsPrivate.NoDockingSplitOther</code></td>
      <td><code>524288</code></td>
    </tr>
    <tr>
      <td><code>DockNodeFlagsPrivate.NoDockingOverMe</code></td>
      <td><code>1048576</code></td>
    </tr>
    <tr>
      <td><code>DockNodeFlagsPrivate.NoDockingOverOther</code></td>
      <td><code>2097152</code></td>
    </tr>
    <tr>
      <td><code>DockNodeFlagsPrivate.NoDockingOverEmpty</code></td>
      <td><code>4194304</code></td>
    </tr>
    <tr>
      <td><code>DockNodeFlagsPrivate.NoDocking</code></td>
      <td><code>7864336</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `DockNodeState`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>DockNodeState.Unknown</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>DockNodeState.HostWindowHiddenBecauseSingleWindow</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>DockNodeState.HostWindowHiddenBecauseWindowsAreResizing</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>DockNodeState.HostWindowVisible</code></td>
      <td><code>3</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `DragDropFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>DragDropFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>DragDropFlags.SourceNoPreviewTooltip</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>DragDropFlags.SourceNoDisableHover</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>DragDropFlags.SourceNoHoldToOpenOthers</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>DragDropFlags.SourceAllowNullID</code></td>
      <td><code>8</code></td>
    </tr>
    <tr>
      <td><code>DragDropFlags.SourceExtern</code></td>
      <td><code>16</code></td>
    </tr>
    <tr>
      <td><code>DragDropFlags.SourceAutoExpirePayload</code></td>
      <td><code>32</code></td>
    </tr>
    <tr>
      <td><code>DragDropFlags.AcceptBeforeDelivery</code></td>
      <td><code>1024</code></td>
    </tr>
    <tr>
      <td><code>DragDropFlags.AcceptNoDrawDefaultRect</code></td>
      <td><code>2048</code></td>
    </tr>
    <tr>
      <td><code>DragDropFlags.AcceptPeekOnly</code></td>
      <td><code>3072</code></td>
    </tr>
    <tr>
      <td><code>DragDropFlags.AcceptNoPreviewTooltip</code></td>
      <td><code>4096</code></td>
    </tr>
  </tbody>
</table>

### Поле `imgui.FLT_MAX`

**Тип**: `unknown`

### Поле `imgui.FLT_MIN`

**Тип**: `unknown`

### Энумерация `FocusRequestFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>FocusRequestFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>FocusRequestFlags.RestoreFocusedChild</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>FocusRequestFlags.UnlessBelowModal</code></td>
      <td><code>2</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `FocusedFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>FocusedFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>FocusedFlags.ChildWindows</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>FocusedFlags.RootWindow</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>FocusedFlags.RootAndChildWindows</code></td>
      <td><code>3</code></td>
    </tr>
    <tr>
      <td><code>FocusedFlags.AnyWindow</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>FocusedFlags.NoPopupHierarchy</code></td>
      <td><code>8</code></td>
    </tr>
    <tr>
      <td><code>FocusedFlags.DockHierarchy</code></td>
      <td><code>16</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `HoveredFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>HoveredFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>HoveredFlags.ChildWindows</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>HoveredFlags.RootWindow</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>HoveredFlags.RootAndChildWindows</code></td>
      <td><code>3</code></td>
    </tr>
    <tr>
      <td><code>HoveredFlags.AnyWindow</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>HoveredFlags.NoPopupHierarchy</code></td>
      <td><code>8</code></td>
    </tr>
    <tr>
      <td><code>HoveredFlags.DockHierarchy</code></td>
      <td><code>16</code></td>
    </tr>
    <tr>
      <td><code>HoveredFlags.AllowWhenBlockedByPopup</code></td>
      <td><code>32</code></td>
    </tr>
    <tr>
      <td><code>HoveredFlags.AllowWhenBlockedByActiveItem</code></td>
      <td><code>128</code></td>
    </tr>
    <tr>
      <td><code>HoveredFlags.AllowWhenOverlappedByItem</code></td>
      <td><code>256</code></td>
    </tr>
    <tr>
      <td><code>HoveredFlags.AllowWhenOverlappedByWindow</code></td>
      <td><code>512</code></td>
    </tr>
    <tr>
      <td><code>HoveredFlags.AllowWhenOverlapped</code></td>
      <td><code>768</code></td>
    </tr>
    <tr>
      <td><code>HoveredFlags.RectOnly</code></td>
      <td><code>928</code></td>
    </tr>
    <tr>
      <td><code>HoveredFlags.AllowWhenDisabled</code></td>
      <td><code>1024</code></td>
    </tr>
    <tr>
      <td><code>HoveredFlags.NoNavOverride</code></td>
      <td><code>2048</code></td>
    </tr>
    <tr>
      <td><code>HoveredFlags.ForTooltip</code></td>
      <td><code>4096</code></td>
    </tr>
    <tr>
      <td><code>HoveredFlags.Stationary</code></td>
      <td><code>8192</code></td>
    </tr>
    <tr>
      <td><code>HoveredFlags.DelayNone</code></td>
      <td><code>16384</code></td>
    </tr>
    <tr>
      <td><code>HoveredFlags.DelayShort</code></td>
      <td><code>32768</code></td>
    </tr>
    <tr>
      <td><code>HoveredFlags.DelayNormal</code></td>
      <td><code>65536</code></td>
    </tr>
    <tr>
      <td><code>HoveredFlags.NoSharedDelay</code></td>
      <td><code>131072</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `HoveredFlagsPrivate`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>HoveredFlagsPrivate.AllowedMaskForIsWindowHovered</code></td>
      <td><code>12479</code></td>
    </tr>
    <tr>
      <td><code>HoveredFlagsPrivate.DelayMask_</code></td>
      <td><code>245760</code></td>
    </tr>
    <tr>
      <td><code>HoveredFlagsPrivate.AllowedMaskForIsItemHovered</code></td>
      <td><code>262048</code></td>
    </tr>
  </tbody>
</table>

### Поле `imgui.ImBitVector`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImColor`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImDrawCmd`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImDrawData`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImDrawDataBuilder`

**Тип**: `ffi.ctype*`

### Энумерация `ImDrawFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ImDrawFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>ImDrawFlags.Closed</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>ImDrawFlags.RoundCornersTopLeft</code></td>
      <td><code>16</code></td>
    </tr>
    <tr>
      <td><code>ImDrawFlags.RoundCornersTopRight</code></td>
      <td><code>32</code></td>
    </tr>
    <tr>
      <td><code>ImDrawFlags.RoundCornersTop</code></td>
      <td><code>48</code></td>
    </tr>
    <tr>
      <td><code>ImDrawFlags.RoundCornersBottomLeft</code></td>
      <td><code>64</code></td>
    </tr>
    <tr>
      <td><code>ImDrawFlags.RoundCornersLeft</code></td>
      <td><code>80</code></td>
    </tr>
    <tr>
      <td><code>ImDrawFlags.RoundCornersBottomRight</code></td>
      <td><code>128</code></td>
    </tr>
    <tr>
      <td><code>ImDrawFlags.RoundCornersRight</code></td>
      <td><code>160</code></td>
    </tr>
    <tr>
      <td><code>ImDrawFlags.RoundCornersBottom</code></td>
      <td><code>192</code></td>
    </tr>
    <tr>
      <td><code>ImDrawFlags.RoundCornersAll</code></td>
      <td><code>240</code></td>
    </tr>
    <tr>
      <td><code>ImDrawFlags.RoundCornersDefault_</code></td>
      <td><code>240</code></td>
    </tr>
    <tr>
      <td><code>ImDrawFlags.RoundCornersNone</code></td>
      <td><code>256</code></td>
    </tr>
    <tr>
      <td><code>ImDrawFlags.RoundCornersMask_</code></td>
      <td><code>496</code></td>
    </tr>
  </tbody>
</table>

### Поле `imgui.ImDrawList`

**Тип**: `ffi.ctype*`

### Энумерация `ImDrawListFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ImDrawListFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>ImDrawListFlags.AntiAliasedLines</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>ImDrawListFlags.AntiAliasedLinesUseTex</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>ImDrawListFlags.AntiAliasedFill</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>ImDrawListFlags.AllowVtxOffset</code></td>
      <td><code>8</code></td>
    </tr>
  </tbody>
</table>

### Поле `imgui.ImDrawListSharedData`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImDrawListSplitter`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImFont`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImFontAtlas`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImFontAtlasCustomRect`

**Тип**: `ffi.ctype*`

### Энумерация `ImFontAtlasFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ImFontAtlasFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>ImFontAtlasFlags.NoPowerOfTwoHeight</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>ImFontAtlasFlags.NoMouseCursors</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>ImFontAtlasFlags.NoBakedLines</code></td>
      <td><code>4</code></td>
    </tr>
  </tbody>
</table>

### Поле `imgui.ImFontConfig`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImFontGlyphRangesBuilder`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiComboPreviewData`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiContext`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiContextHook`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiDataVarInfo`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiDebugAllocInfo`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiDockContext`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiDockNode`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiIDStackTool`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiIO`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiInputEvent`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiInputTextCallbackData`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiInputTextDeactivatedState`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiInputTextState`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiKeyOwnerData`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiKeyRoutingData`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiKeyRoutingTable`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiLastItemData`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiListClipper`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiListClipperData`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiListClipperRange`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiMenuColumns`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiNavItemData`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiNextItemData`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiNextWindowData`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiOldColumnData`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiOldColumns`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiOnceUponAFrame`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiPayload`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiPlatformIO`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiPlatformImeData`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiPlatformMonitor`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiPopupData`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiPtrOrIndex`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiSettingsHandler`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiStackLevelInfo`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiStackSizes`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiStorage`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiStoragePair`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiStyle`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiStyleMod`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiTabBar`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiTabItem`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiTable`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiTableColumn`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiTableColumnSettings`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiTableColumnSortSpecs`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiTableInstanceData`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiTableSettings`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiTableSortSpecs`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiTableTempData`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiTextBuffer`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiTextFilter`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiTextIndex`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiTextRange`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiTypingSelectState`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiViewport`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiViewportP`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiWindow`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiWindowClass`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImGuiWindowSettings`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImRect`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImVec1`

**Тип**: `ffi.ctype*`

### Поле `imgui.ImVec2ih`

**Тип**: `ffi.ctype*`

### Энумерация `InputEventType`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>InputEventType.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>InputEventType.MousePos</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>InputEventType.MouseWheel</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>InputEventType.MouseButton</code></td>
      <td><code>3</code></td>
    </tr>
    <tr>
      <td><code>InputEventType.MouseViewport</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>InputEventType.Key</code></td>
      <td><code>5</code></td>
    </tr>
    <tr>
      <td><code>InputEventType.Text</code></td>
      <td><code>6</code></td>
    </tr>
    <tr>
      <td><code>InputEventType.Focus</code></td>
      <td><code>7</code></td>
    </tr>
    <tr>
      <td><code>InputEventType.COUNT</code></td>
      <td><code>8</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `InputFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>InputFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>InputFlags.Repeat</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>InputFlags.SupportedByIsMouseClicked</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>InputFlags.RepeatRateDefault</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>InputFlags.RepeatRateNavMove</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>InputFlags.RepeatRateNavTweak</code></td>
      <td><code>8</code></td>
    </tr>
    <tr>
      <td><code>InputFlags.RepeatRateMask_</code></td>
      <td><code>14</code></td>
    </tr>
    <tr>
      <td><code>InputFlags.RepeatUntilRelease</code></td>
      <td><code>16</code></td>
    </tr>
    <tr>
      <td><code>InputFlags.RepeatUntilKeyModsChange</code></td>
      <td><code>32</code></td>
    </tr>
    <tr>
      <td><code>InputFlags.RepeatUntilKeyModsChangeFromNone</code></td>
      <td><code>64</code></td>
    </tr>
    <tr>
      <td><code>InputFlags.RepeatUntilOtherKeyPress</code></td>
      <td><code>128</code></td>
    </tr>
    <tr>
      <td><code>InputFlags.RepeatUntilMask_</code></td>
      <td><code>240</code></td>
    </tr>
    <tr>
      <td><code>InputFlags.RepeatMask_</code></td>
      <td><code>255</code></td>
    </tr>
    <tr>
      <td><code>InputFlags.SupportedByIsKeyPressed</code></td>
      <td><code>255</code></td>
    </tr>
    <tr>
      <td><code>InputFlags.CondHovered</code></td>
      <td><code>256</code></td>
    </tr>
    <tr>
      <td><code>InputFlags.CondActive</code></td>
      <td><code>512</code></td>
    </tr>
    <tr>
      <td><code>InputFlags.CondDefault_</code></td>
      <td><code>768</code></td>
    </tr>
    <tr>
      <td><code>InputFlags.CondMask_</code></td>
      <td><code>768</code></td>
    </tr>
    <tr>
      <td><code>InputFlags.LockThisFrame</code></td>
      <td><code>1024</code></td>
    </tr>
    <tr>
      <td><code>InputFlags.LockUntilRelease</code></td>
      <td><code>2048</code></td>
    </tr>
    <tr>
      <td><code>InputFlags.SupportedBySetKeyOwner</code></td>
      <td><code>3072</code></td>
    </tr>
    <tr>
      <td><code>InputFlags.SupportedBySetItemKeyOwner</code></td>
      <td><code>3840</code></td>
    </tr>
    <tr>
      <td><code>InputFlags.RouteFocused</code></td>
      <td><code>4096</code></td>
    </tr>
    <tr>
      <td><code>InputFlags.RouteGlobalLow</code></td>
      <td><code>8192</code></td>
    </tr>
    <tr>
      <td><code>InputFlags.RouteGlobal</code></td>
      <td><code>16384</code></td>
    </tr>
    <tr>
      <td><code>InputFlags.RouteGlobalHigh</code></td>
      <td><code>32768</code></td>
    </tr>
    <tr>
      <td><code>InputFlags.RouteMask_</code></td>
      <td><code>61440</code></td>
    </tr>
    <tr>
      <td><code>InputFlags.RouteAlways</code></td>
      <td><code>65536</code></td>
    </tr>
    <tr>
      <td><code>InputFlags.RouteUnlessBgFocused</code></td>
      <td><code>131072</code></td>
    </tr>
    <tr>
      <td><code>InputFlags.SupportedByShortcut</code></td>
      <td><code>258303</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `InputSource`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>InputSource.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>InputSource.Mouse</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>InputSource.Keyboard</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>InputSource.Gamepad</code></td>
      <td><code>3</code></td>
    </tr>
    <tr>
      <td><code>InputSource.Clipboard</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>InputSource.COUNT</code></td>
      <td><code>5</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `InputTextFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>InputTextFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>InputTextFlags.CharsDecimal</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>InputTextFlags.CharsHexadecimal</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>InputTextFlags.CharsUppercase</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>InputTextFlags.CharsNoBlank</code></td>
      <td><code>8</code></td>
    </tr>
    <tr>
      <td><code>InputTextFlags.AutoSelectAll</code></td>
      <td><code>16</code></td>
    </tr>
    <tr>
      <td><code>InputTextFlags.EnterReturnsTrue</code></td>
      <td><code>32</code></td>
    </tr>
    <tr>
      <td><code>InputTextFlags.CallbackCompletion</code></td>
      <td><code>64</code></td>
    </tr>
    <tr>
      <td><code>InputTextFlags.CallbackHistory</code></td>
      <td><code>128</code></td>
    </tr>
    <tr>
      <td><code>InputTextFlags.CallbackAlways</code></td>
      <td><code>256</code></td>
    </tr>
    <tr>
      <td><code>InputTextFlags.CallbackCharFilter</code></td>
      <td><code>512</code></td>
    </tr>
    <tr>
      <td><code>InputTextFlags.AllowTabInput</code></td>
      <td><code>1024</code></td>
    </tr>
    <tr>
      <td><code>InputTextFlags.CtrlEnterForNewLine</code></td>
      <td><code>2048</code></td>
    </tr>
    <tr>
      <td><code>InputTextFlags.NoHorizontalScroll</code></td>
      <td><code>4096</code></td>
    </tr>
    <tr>
      <td><code>InputTextFlags.AlwaysOverwrite</code></td>
      <td><code>8192</code></td>
    </tr>
    <tr>
      <td><code>InputTextFlags.ReadOnly</code></td>
      <td><code>16384</code></td>
    </tr>
    <tr>
      <td><code>InputTextFlags.Password</code></td>
      <td><code>32768</code></td>
    </tr>
    <tr>
      <td><code>InputTextFlags.NoUndoRedo</code></td>
      <td><code>65536</code></td>
    </tr>
    <tr>
      <td><code>InputTextFlags.CharsScientific</code></td>
      <td><code>131072</code></td>
    </tr>
    <tr>
      <td><code>InputTextFlags.CallbackResize</code></td>
      <td><code>262144</code></td>
    </tr>
    <tr>
      <td><code>InputTextFlags.CallbackEdit</code></td>
      <td><code>524288</code></td>
    </tr>
    <tr>
      <td><code>InputTextFlags.EscapeClearsAll</code></td>
      <td><code>1048576</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `InputTextFlagsPrivate`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>InputTextFlagsPrivate.Multiline</code></td>
      <td><code>67108864</code></td>
    </tr>
    <tr>
      <td><code>InputTextFlagsPrivate.NoMarkEdited</code></td>
      <td><code>134217728</code></td>
    </tr>
    <tr>
      <td><code>InputTextFlagsPrivate.MergedItem</code></td>
      <td><code>268435456</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `ItemFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ItemFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>ItemFlags.NoTabStop</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>ItemFlags.ButtonRepeat</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>ItemFlags.Disabled</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>ItemFlags.NoNav</code></td>
      <td><code>8</code></td>
    </tr>
    <tr>
      <td><code>ItemFlags.NoNavDefaultFocus</code></td>
      <td><code>16</code></td>
    </tr>
    <tr>
      <td><code>ItemFlags.SelectableDontClosePopup</code></td>
      <td><code>32</code></td>
    </tr>
    <tr>
      <td><code>ItemFlags.MixedValue</code></td>
      <td><code>64</code></td>
    </tr>
    <tr>
      <td><code>ItemFlags.ReadOnly</code></td>
      <td><code>128</code></td>
    </tr>
    <tr>
      <td><code>ItemFlags.NoWindowHoverableCheck</code></td>
      <td><code>256</code></td>
    </tr>
    <tr>
      <td><code>ItemFlags.AllowOverlap</code></td>
      <td><code>512</code></td>
    </tr>
    <tr>
      <td><code>ItemFlags.Inputable</code></td>
      <td><code>1024</code></td>
    </tr>
    <tr>
      <td><code>ItemFlags.HasSelectionUserData</code></td>
      <td><code>2048</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `ItemStatusFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ItemStatusFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>ItemStatusFlags.HoveredRect</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>ItemStatusFlags.HasDisplayRect</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>ItemStatusFlags.Edited</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>ItemStatusFlags.ToggledSelection</code></td>
      <td><code>8</code></td>
    </tr>
    <tr>
      <td><code>ItemStatusFlags.ToggledOpen</code></td>
      <td><code>16</code></td>
    </tr>
    <tr>
      <td><code>ItemStatusFlags.HasDeactivated</code></td>
      <td><code>32</code></td>
    </tr>
    <tr>
      <td><code>ItemStatusFlags.Deactivated</code></td>
      <td><code>64</code></td>
    </tr>
    <tr>
      <td><code>ItemStatusFlags.HoveredWindow</code></td>
      <td><code>128</code></td>
    </tr>
    <tr>
      <td><code>ItemStatusFlags.Visible</code></td>
      <td><code>256</code></td>
    </tr>
    <tr>
      <td><code>ItemStatusFlags.HasClipRect</code></td>
      <td><code>512</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `Key`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>Key.ImGuiMod_None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>Key.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>Key.KeysData_SIZE</code></td>
      <td><code>154</code></td>
    </tr>
    <tr>
      <td><code>Key.NamedKey_COUNT</code></td>
      <td><code>154</code></td>
    </tr>
    <tr>
      <td><code>Key.KeysData_OFFSET</code></td>
      <td><code>512</code></td>
    </tr>
    <tr>
      <td><code>Key.NamedKey_BEGIN</code></td>
      <td><code>512</code></td>
    </tr>
    <tr>
      <td><code>Key.Tab</code></td>
      <td><code>512</code></td>
    </tr>
    <tr>
      <td><code>Key.LeftArrow</code></td>
      <td><code>513</code></td>
    </tr>
    <tr>
      <td><code>Key.RightArrow</code></td>
      <td><code>514</code></td>
    </tr>
    <tr>
      <td><code>Key.UpArrow</code></td>
      <td><code>515</code></td>
    </tr>
    <tr>
      <td><code>Key.DownArrow</code></td>
      <td><code>516</code></td>
    </tr>
    <tr>
      <td><code>Key.PageUp</code></td>
      <td><code>517</code></td>
    </tr>
    <tr>
      <td><code>Key.PageDown</code></td>
      <td><code>518</code></td>
    </tr>
    <tr>
      <td><code>Key.Home</code></td>
      <td><code>519</code></td>
    </tr>
    <tr>
      <td><code>Key.End</code></td>
      <td><code>520</code></td>
    </tr>
    <tr>
      <td><code>Key.Insert</code></td>
      <td><code>521</code></td>
    </tr>
    <tr>
      <td><code>Key.Delete</code></td>
      <td><code>522</code></td>
    </tr>
    <tr>
      <td><code>Key.Backspace</code></td>
      <td><code>523</code></td>
    </tr>
    <tr>
      <td><code>Key.Space</code></td>
      <td><code>524</code></td>
    </tr>
    <tr>
      <td><code>Key.Enter</code></td>
      <td><code>525</code></td>
    </tr>
    <tr>
      <td><code>Key.Escape</code></td>
      <td><code>526</code></td>
    </tr>
    <tr>
      <td><code>Key.LeftCtrl</code></td>
      <td><code>527</code></td>
    </tr>
    <tr>
      <td><code>Key.LeftShift</code></td>
      <td><code>528</code></td>
    </tr>
    <tr>
      <td><code>Key.LeftAlt</code></td>
      <td><code>529</code></td>
    </tr>
    <tr>
      <td><code>Key.LeftSuper</code></td>
      <td><code>530</code></td>
    </tr>
    <tr>
      <td><code>Key.RightCtrl</code></td>
      <td><code>531</code></td>
    </tr>
    <tr>
      <td><code>Key.RightShift</code></td>
      <td><code>532</code></td>
    </tr>
    <tr>
      <td><code>Key.RightAlt</code></td>
      <td><code>533</code></td>
    </tr>
    <tr>
      <td><code>Key.RightSuper</code></td>
      <td><code>534</code></td>
    </tr>
    <tr>
      <td><code>Key.Menu</code></td>
      <td><code>535</code></td>
    </tr>
    <tr>
      <td><code>Key._0</code></td>
      <td><code>536</code></td>
    </tr>
    <tr>
      <td><code>Key._1</code></td>
      <td><code>537</code></td>
    </tr>
    <tr>
      <td><code>Key._2</code></td>
      <td><code>538</code></td>
    </tr>
    <tr>
      <td><code>Key._3</code></td>
      <td><code>539</code></td>
    </tr>
    <tr>
      <td><code>Key._4</code></td>
      <td><code>540</code></td>
    </tr>
    <tr>
      <td><code>Key._5</code></td>
      <td><code>541</code></td>
    </tr>
    <tr>
      <td><code>Key._6</code></td>
      <td><code>542</code></td>
    </tr>
    <tr>
      <td><code>Key._7</code></td>
      <td><code>543</code></td>
    </tr>
    <tr>
      <td><code>Key._8</code></td>
      <td><code>544</code></td>
    </tr>
    <tr>
      <td><code>Key._9</code></td>
      <td><code>545</code></td>
    </tr>
    <tr>
      <td><code>Key.A</code></td>
      <td><code>546</code></td>
    </tr>
    <tr>
      <td><code>Key.B</code></td>
      <td><code>547</code></td>
    </tr>
    <tr>
      <td><code>Key.C</code></td>
      <td><code>548</code></td>
    </tr>
    <tr>
      <td><code>Key.D</code></td>
      <td><code>549</code></td>
    </tr>
    <tr>
      <td><code>Key.E</code></td>
      <td><code>550</code></td>
    </tr>
    <tr>
      <td><code>Key.F</code></td>
      <td><code>551</code></td>
    </tr>
    <tr>
      <td><code>Key.G</code></td>
      <td><code>552</code></td>
    </tr>
    <tr>
      <td><code>Key.H</code></td>
      <td><code>553</code></td>
    </tr>
    <tr>
      <td><code>Key.I</code></td>
      <td><code>554</code></td>
    </tr>
    <tr>
      <td><code>Key.J</code></td>
      <td><code>555</code></td>
    </tr>
    <tr>
      <td><code>Key.K</code></td>
      <td><code>556</code></td>
    </tr>
    <tr>
      <td><code>Key.L</code></td>
      <td><code>557</code></td>
    </tr>
    <tr>
      <td><code>Key.M</code></td>
      <td><code>558</code></td>
    </tr>
    <tr>
      <td><code>Key.N</code></td>
      <td><code>559</code></td>
    </tr>
    <tr>
      <td><code>Key.O</code></td>
      <td><code>560</code></td>
    </tr>
    <tr>
      <td><code>Key.P</code></td>
      <td><code>561</code></td>
    </tr>
    <tr>
      <td><code>Key.Q</code></td>
      <td><code>562</code></td>
    </tr>
    <tr>
      <td><code>Key.R</code></td>
      <td><code>563</code></td>
    </tr>
    <tr>
      <td><code>Key.S</code></td>
      <td><code>564</code></td>
    </tr>
    <tr>
      <td><code>Key.T</code></td>
      <td><code>565</code></td>
    </tr>
    <tr>
      <td><code>Key.U</code></td>
      <td><code>566</code></td>
    </tr>
    <tr>
      <td><code>Key.V</code></td>
      <td><code>567</code></td>
    </tr>
    <tr>
      <td><code>Key.W</code></td>
      <td><code>568</code></td>
    </tr>
    <tr>
      <td><code>Key.X</code></td>
      <td><code>569</code></td>
    </tr>
    <tr>
      <td><code>Key.Y</code></td>
      <td><code>570</code></td>
    </tr>
    <tr>
      <td><code>Key.Z</code></td>
      <td><code>571</code></td>
    </tr>
    <tr>
      <td><code>Key.F1</code></td>
      <td><code>572</code></td>
    </tr>
    <tr>
      <td><code>Key.F2</code></td>
      <td><code>573</code></td>
    </tr>
    <tr>
      <td><code>Key.F3</code></td>
      <td><code>574</code></td>
    </tr>
    <tr>
      <td><code>Key.F4</code></td>
      <td><code>575</code></td>
    </tr>
    <tr>
      <td><code>Key.F5</code></td>
      <td><code>576</code></td>
    </tr>
    <tr>
      <td><code>Key.F6</code></td>
      <td><code>577</code></td>
    </tr>
    <tr>
      <td><code>Key.F7</code></td>
      <td><code>578</code></td>
    </tr>
    <tr>
      <td><code>Key.F8</code></td>
      <td><code>579</code></td>
    </tr>
    <tr>
      <td><code>Key.F9</code></td>
      <td><code>580</code></td>
    </tr>
    <tr>
      <td><code>Key.F10</code></td>
      <td><code>581</code></td>
    </tr>
    <tr>
      <td><code>Key.F11</code></td>
      <td><code>582</code></td>
    </tr>
    <tr>
      <td><code>Key.F12</code></td>
      <td><code>583</code></td>
    </tr>
    <tr>
      <td><code>Key.F13</code></td>
      <td><code>584</code></td>
    </tr>
    <tr>
      <td><code>Key.F14</code></td>
      <td><code>585</code></td>
    </tr>
    <tr>
      <td><code>Key.F15</code></td>
      <td><code>586</code></td>
    </tr>
    <tr>
      <td><code>Key.F16</code></td>
      <td><code>587</code></td>
    </tr>
    <tr>
      <td><code>Key.F17</code></td>
      <td><code>588</code></td>
    </tr>
    <tr>
      <td><code>Key.F18</code></td>
      <td><code>589</code></td>
    </tr>
    <tr>
      <td><code>Key.F19</code></td>
      <td><code>590</code></td>
    </tr>
    <tr>
      <td><code>Key.F20</code></td>
      <td><code>591</code></td>
    </tr>
    <tr>
      <td><code>Key.F21</code></td>
      <td><code>592</code></td>
    </tr>
    <tr>
      <td><code>Key.F22</code></td>
      <td><code>593</code></td>
    </tr>
    <tr>
      <td><code>Key.F23</code></td>
      <td><code>594</code></td>
    </tr>
    <tr>
      <td><code>Key.F24</code></td>
      <td><code>595</code></td>
    </tr>
    <tr>
      <td><code>Key.Apostrophe</code></td>
      <td><code>596</code></td>
    </tr>
    <tr>
      <td><code>Key.Comma</code></td>
      <td><code>597</code></td>
    </tr>
    <tr>
      <td><code>Key.Minus</code></td>
      <td><code>598</code></td>
    </tr>
    <tr>
      <td><code>Key.Period</code></td>
      <td><code>599</code></td>
    </tr>
    <tr>
      <td><code>Key.Slash</code></td>
      <td><code>600</code></td>
    </tr>
    <tr>
      <td><code>Key.Semicolon</code></td>
      <td><code>601</code></td>
    </tr>
    <tr>
      <td><code>Key.Equal</code></td>
      <td><code>602</code></td>
    </tr>
    <tr>
      <td><code>Key.LeftBracket</code></td>
      <td><code>603</code></td>
    </tr>
    <tr>
      <td><code>Key.Backslash</code></td>
      <td><code>604</code></td>
    </tr>
    <tr>
      <td><code>Key.RightBracket</code></td>
      <td><code>605</code></td>
    </tr>
    <tr>
      <td><code>Key.GraveAccent</code></td>
      <td><code>606</code></td>
    </tr>
    <tr>
      <td><code>Key.CapsLock</code></td>
      <td><code>607</code></td>
    </tr>
    <tr>
      <td><code>Key.ScrollLock</code></td>
      <td><code>608</code></td>
    </tr>
    <tr>
      <td><code>Key.NumLock</code></td>
      <td><code>609</code></td>
    </tr>
    <tr>
      <td><code>Key.PrintScreen</code></td>
      <td><code>610</code></td>
    </tr>
    <tr>
      <td><code>Key.Pause</code></td>
      <td><code>611</code></td>
    </tr>
    <tr>
      <td><code>Key.Keypad0</code></td>
      <td><code>612</code></td>
    </tr>
    <tr>
      <td><code>Key.Keypad1</code></td>
      <td><code>613</code></td>
    </tr>
    <tr>
      <td><code>Key.Keypad2</code></td>
      <td><code>614</code></td>
    </tr>
    <tr>
      <td><code>Key.Keypad3</code></td>
      <td><code>615</code></td>
    </tr>
    <tr>
      <td><code>Key.Keypad4</code></td>
      <td><code>616</code></td>
    </tr>
    <tr>
      <td><code>Key.Keypad5</code></td>
      <td><code>617</code></td>
    </tr>
    <tr>
      <td><code>Key.Keypad6</code></td>
      <td><code>618</code></td>
    </tr>
    <tr>
      <td><code>Key.Keypad7</code></td>
      <td><code>619</code></td>
    </tr>
    <tr>
      <td><code>Key.Keypad8</code></td>
      <td><code>620</code></td>
    </tr>
    <tr>
      <td><code>Key.Keypad9</code></td>
      <td><code>621</code></td>
    </tr>
    <tr>
      <td><code>Key.KeypadDecimal</code></td>
      <td><code>622</code></td>
    </tr>
    <tr>
      <td><code>Key.KeypadDivide</code></td>
      <td><code>623</code></td>
    </tr>
    <tr>
      <td><code>Key.KeypadMultiply</code></td>
      <td><code>624</code></td>
    </tr>
    <tr>
      <td><code>Key.KeypadSubtract</code></td>
      <td><code>625</code></td>
    </tr>
    <tr>
      <td><code>Key.KeypadAdd</code></td>
      <td><code>626</code></td>
    </tr>
    <tr>
      <td><code>Key.KeypadEnter</code></td>
      <td><code>627</code></td>
    </tr>
    <tr>
      <td><code>Key.KeypadEqual</code></td>
      <td><code>628</code></td>
    </tr>
    <tr>
      <td><code>Key.AppBack</code></td>
      <td><code>629</code></td>
    </tr>
    <tr>
      <td><code>Key.AppForward</code></td>
      <td><code>630</code></td>
    </tr>
    <tr>
      <td><code>Key.GamepadStart</code></td>
      <td><code>631</code></td>
    </tr>
    <tr>
      <td><code>Key.GamepadBack</code></td>
      <td><code>632</code></td>
    </tr>
    <tr>
      <td><code>Key.GamepadFaceLeft</code></td>
      <td><code>633</code></td>
    </tr>
    <tr>
      <td><code>Key.GamepadFaceRight</code></td>
      <td><code>634</code></td>
    </tr>
    <tr>
      <td><code>Key.GamepadFaceUp</code></td>
      <td><code>635</code></td>
    </tr>
    <tr>
      <td><code>Key.GamepadFaceDown</code></td>
      <td><code>636</code></td>
    </tr>
    <tr>
      <td><code>Key.GamepadDpadLeft</code></td>
      <td><code>637</code></td>
    </tr>
    <tr>
      <td><code>Key.GamepadDpadRight</code></td>
      <td><code>638</code></td>
    </tr>
    <tr>
      <td><code>Key.GamepadDpadUp</code></td>
      <td><code>639</code></td>
    </tr>
    <tr>
      <td><code>Key.GamepadDpadDown</code></td>
      <td><code>640</code></td>
    </tr>
    <tr>
      <td><code>Key.GamepadL1</code></td>
      <td><code>641</code></td>
    </tr>
    <tr>
      <td><code>Key.GamepadR1</code></td>
      <td><code>642</code></td>
    </tr>
    <tr>
      <td><code>Key.GamepadL2</code></td>
      <td><code>643</code></td>
    </tr>
    <tr>
      <td><code>Key.GamepadR2</code></td>
      <td><code>644</code></td>
    </tr>
    <tr>
      <td><code>Key.GamepadL3</code></td>
      <td><code>645</code></td>
    </tr>
    <tr>
      <td><code>Key.GamepadR3</code></td>
      <td><code>646</code></td>
    </tr>
    <tr>
      <td><code>Key.GamepadLStickLeft</code></td>
      <td><code>647</code></td>
    </tr>
    <tr>
      <td><code>Key.GamepadLStickRight</code></td>
      <td><code>648</code></td>
    </tr>
    <tr>
      <td><code>Key.GamepadLStickUp</code></td>
      <td><code>649</code></td>
    </tr>
    <tr>
      <td><code>Key.GamepadLStickDown</code></td>
      <td><code>650</code></td>
    </tr>
    <tr>
      <td><code>Key.GamepadRStickLeft</code></td>
      <td><code>651</code></td>
    </tr>
    <tr>
      <td><code>Key.GamepadRStickRight</code></td>
      <td><code>652</code></td>
    </tr>
    <tr>
      <td><code>Key.GamepadRStickUp</code></td>
      <td><code>653</code></td>
    </tr>
    <tr>
      <td><code>Key.GamepadRStickDown</code></td>
      <td><code>654</code></td>
    </tr>
    <tr>
      <td><code>Key.MouseLeft</code></td>
      <td><code>655</code></td>
    </tr>
    <tr>
      <td><code>Key.MouseRight</code></td>
      <td><code>656</code></td>
    </tr>
    <tr>
      <td><code>Key.MouseMiddle</code></td>
      <td><code>657</code></td>
    </tr>
    <tr>
      <td><code>Key.MouseX1</code></td>
      <td><code>658</code></td>
    </tr>
    <tr>
      <td><code>Key.MouseX2</code></td>
      <td><code>659</code></td>
    </tr>
    <tr>
      <td><code>Key.MouseWheelX</code></td>
      <td><code>660</code></td>
    </tr>
    <tr>
      <td><code>Key.MouseWheelY</code></td>
      <td><code>661</code></td>
    </tr>
    <tr>
      <td><code>Key.ReservedForModCtrl</code></td>
      <td><code>662</code></td>
    </tr>
    <tr>
      <td><code>Key.ReservedForModShift</code></td>
      <td><code>663</code></td>
    </tr>
    <tr>
      <td><code>Key.ReservedForModAlt</code></td>
      <td><code>664</code></td>
    </tr>
    <tr>
      <td><code>Key.ReservedForModSuper</code></td>
      <td><code>665</code></td>
    </tr>
    <tr>
      <td><code>Key.COUNT</code></td>
      <td><code>666</code></td>
    </tr>
    <tr>
      <td><code>Key.NamedKey_END</code></td>
      <td><code>666</code></td>
    </tr>
    <tr>
      <td><code>Key.ImGuiMod_Shortcut</code></td>
      <td><code>2048</code></td>
    </tr>
    <tr>
      <td><code>Key.ImGuiMod_Ctrl</code></td>
      <td><code>4096</code></td>
    </tr>
    <tr>
      <td><code>Key.ImGuiMod_Shift</code></td>
      <td><code>8192</code></td>
    </tr>
    <tr>
      <td><code>Key.ImGuiMod_Alt</code></td>
      <td><code>16384</code></td>
    </tr>
    <tr>
      <td><code>Key.ImGuiMod_Super</code></td>
      <td><code>32768</code></td>
    </tr>
    <tr>
      <td><code>Key.ImGuiMod_Mask_</code></td>
      <td><code>63488</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `LayoutType`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>LayoutType.Horizontal</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>LayoutType.Vertical</code></td>
      <td><code>1</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `LocKey`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>LocKey.VersionStr</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>LocKey.TableSizeOne</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>LocKey.TableSizeAllFit</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>LocKey.TableSizeAllDefault</code></td>
      <td><code>3</code></td>
    </tr>
    <tr>
      <td><code>LocKey.TableResetOrder</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>LocKey.WindowingMainMenuBar</code></td>
      <td><code>5</code></td>
    </tr>
    <tr>
      <td><code>LocKey.WindowingPopup</code></td>
      <td><code>6</code></td>
    </tr>
    <tr>
      <td><code>LocKey.WindowingUntitled</code></td>
      <td><code>7</code></td>
    </tr>
    <tr>
      <td><code>LocKey.DockingHideTabBar</code></td>
      <td><code>8</code></td>
    </tr>
    <tr>
      <td><code>LocKey.DockingHoldShiftToDock</code></td>
      <td><code>9</code></td>
    </tr>
    <tr>
      <td><code>LocKey.DockingDragToUndockOrMoveNode</code></td>
      <td><code>10</code></td>
    </tr>
    <tr>
      <td><code>LocKey.COUNT</code></td>
      <td><code>11</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `LogType`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>LogType.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>LogType.TTY</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>LogType.File</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>LogType.Buffer</code></td>
      <td><code>3</code></td>
    </tr>
    <tr>
      <td><code>LogType.Clipboard</code></td>
      <td><code>4</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `MouseButton`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>MouseButton.Left</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>MouseButton.Right</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>MouseButton.Middle</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>MouseButton.COUNT</code></td>
      <td><code>5</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `MouseCursor`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>MouseCursor.None</code></td>
      <td><code>-1</code></td>
    </tr>
    <tr>
      <td><code>MouseCursor.Arrow</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>MouseCursor.TextInput</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>MouseCursor.ResizeAll</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>MouseCursor.ResizeNS</code></td>
      <td><code>3</code></td>
    </tr>
    <tr>
      <td><code>MouseCursor.ResizeEW</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>MouseCursor.ResizeNESW</code></td>
      <td><code>5</code></td>
    </tr>
    <tr>
      <td><code>MouseCursor.ResizeNWSE</code></td>
      <td><code>6</code></td>
    </tr>
    <tr>
      <td><code>MouseCursor.Hand</code></td>
      <td><code>7</code></td>
    </tr>
    <tr>
      <td><code>MouseCursor.NotAllowed</code></td>
      <td><code>8</code></td>
    </tr>
    <tr>
      <td><code>MouseCursor.COUNT</code></td>
      <td><code>9</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `MouseSource`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>MouseSource.Mouse</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>MouseSource.TouchScreen</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>MouseSource.Pen</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>MouseSource.COUNT</code></td>
      <td><code>3</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `NavHighlightFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>NavHighlightFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>NavHighlightFlags.Compact</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>NavHighlightFlags.AlwaysDraw</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>NavHighlightFlags.NoRounding</code></td>
      <td><code>8</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `NavLayer`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>NavLayer.Main</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>NavLayer.Menu</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>NavLayer.COUNT</code></td>
      <td><code>2</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `NavMoveFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>NavMoveFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>NavMoveFlags.LoopX</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>NavMoveFlags.LoopY</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>NavMoveFlags.WrapX</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>NavMoveFlags.WrapY</code></td>
      <td><code>8</code></td>
    </tr>
    <tr>
      <td><code>NavMoveFlags.WrapMask_</code></td>
      <td><code>15</code></td>
    </tr>
    <tr>
      <td><code>NavMoveFlags.AllowCurrentNavId</code></td>
      <td><code>16</code></td>
    </tr>
    <tr>
      <td><code>NavMoveFlags.AlsoScoreVisibleSet</code></td>
      <td><code>32</code></td>
    </tr>
    <tr>
      <td><code>NavMoveFlags.ScrollToEdgeY</code></td>
      <td><code>64</code></td>
    </tr>
    <tr>
      <td><code>NavMoveFlags.Forwarded</code></td>
      <td><code>128</code></td>
    </tr>
    <tr>
      <td><code>NavMoveFlags.DebugNoResult</code></td>
      <td><code>256</code></td>
    </tr>
    <tr>
      <td><code>NavMoveFlags.FocusApi</code></td>
      <td><code>512</code></td>
    </tr>
    <tr>
      <td><code>NavMoveFlags.IsTabbing</code></td>
      <td><code>1024</code></td>
    </tr>
    <tr>
      <td><code>NavMoveFlags.IsPageMove</code></td>
      <td><code>2048</code></td>
    </tr>
    <tr>
      <td><code>NavMoveFlags.Activate</code></td>
      <td><code>4096</code></td>
    </tr>
    <tr>
      <td><code>NavMoveFlags.NoSelect</code></td>
      <td><code>8192</code></td>
    </tr>
    <tr>
      <td><code>NavMoveFlags.NoSetNavHighlight</code></td>
      <td><code>16384</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `NextItemDataFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>NextItemDataFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>NextItemDataFlags.HasWidth</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>NextItemDataFlags.HasOpen</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>NextItemDataFlags.HasShortcut</code></td>
      <td><code>4</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `NextWindowDataFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>NextWindowDataFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>NextWindowDataFlags.HasPos</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>NextWindowDataFlags.HasSize</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>NextWindowDataFlags.HasContentSize</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>NextWindowDataFlags.HasCollapsed</code></td>
      <td><code>8</code></td>
    </tr>
    <tr>
      <td><code>NextWindowDataFlags.HasSizeConstraint</code></td>
      <td><code>16</code></td>
    </tr>
    <tr>
      <td><code>NextWindowDataFlags.HasFocus</code></td>
      <td><code>32</code></td>
    </tr>
    <tr>
      <td><code>NextWindowDataFlags.HasBgAlpha</code></td>
      <td><code>64</code></td>
    </tr>
    <tr>
      <td><code>NextWindowDataFlags.HasScroll</code></td>
      <td><code>128</code></td>
    </tr>
    <tr>
      <td><code>NextWindowDataFlags.HasChildFlags</code></td>
      <td><code>256</code></td>
    </tr>
    <tr>
      <td><code>NextWindowDataFlags.HasViewport</code></td>
      <td><code>512</code></td>
    </tr>
    <tr>
      <td><code>NextWindowDataFlags.HasDock</code></td>
      <td><code>1024</code></td>
    </tr>
    <tr>
      <td><code>NextWindowDataFlags.HasWindowClass</code></td>
      <td><code>2048</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `OldColumnFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>OldColumnFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>OldColumnFlags.NoBorder</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>OldColumnFlags.NoResize</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>OldColumnFlags.NoPreserveWidths</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>OldColumnFlags.NoForceWithinWindow</code></td>
      <td><code>8</code></td>
    </tr>
    <tr>
      <td><code>OldColumnFlags.GrowParentContentsSize</code></td>
      <td><code>16</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `PlotType`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>PlotType.Lines</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>PlotType.Histogram</code></td>
      <td><code>1</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `PopupFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>PopupFlags.MouseButtonLeft</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>PopupFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>PopupFlags.MouseButtonDefault_</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>PopupFlags.MouseButtonRight</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>PopupFlags.MouseButtonMiddle</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>PopupFlags.MouseButtonMask_</code></td>
      <td><code>31</code></td>
    </tr>
    <tr>
      <td><code>PopupFlags.NoReopen</code></td>
      <td><code>32</code></td>
    </tr>
    <tr>
      <td><code>PopupFlags.NoOpenOverExistingPopup</code></td>
      <td><code>128</code></td>
    </tr>
    <tr>
      <td><code>PopupFlags.NoOpenOverItems</code></td>
      <td><code>256</code></td>
    </tr>
    <tr>
      <td><code>PopupFlags.AnyPopupId</code></td>
      <td><code>1024</code></td>
    </tr>
    <tr>
      <td><code>PopupFlags.AnyPopupLevel</code></td>
      <td><code>2048</code></td>
    </tr>
    <tr>
      <td><code>PopupFlags.AnyPopup</code></td>
      <td><code>3072</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `PopupPositionPolicy`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>PopupPositionPolicy.Default</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>PopupPositionPolicy.ComboBox</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>PopupPositionPolicy.Tooltip</code></td>
      <td><code>2</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `ScrollFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ScrollFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>ScrollFlags.KeepVisibleEdgeX</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>ScrollFlags.KeepVisibleEdgeY</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>ScrollFlags.KeepVisibleCenterX</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>ScrollFlags.KeepVisibleCenterY</code></td>
      <td><code>8</code></td>
    </tr>
    <tr>
      <td><code>ScrollFlags.AlwaysCenterX</code></td>
      <td><code>16</code></td>
    </tr>
    <tr>
      <td><code>ScrollFlags.MaskX_</code></td>
      <td><code>21</code></td>
    </tr>
    <tr>
      <td><code>ScrollFlags.AlwaysCenterY</code></td>
      <td><code>32</code></td>
    </tr>
    <tr>
      <td><code>ScrollFlags.MaskY_</code></td>
      <td><code>42</code></td>
    </tr>
    <tr>
      <td><code>ScrollFlags.NoScrollParent</code></td>
      <td><code>64</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `SelectableFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>SelectableFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>SelectableFlags.DontClosePopups</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>SelectableFlags.SpanAllColumns</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>SelectableFlags.AllowDoubleClick</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>SelectableFlags.Disabled</code></td>
      <td><code>8</code></td>
    </tr>
    <tr>
      <td><code>SelectableFlags.AllowOverlap</code></td>
      <td><code>16</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `SelectableFlagsPrivate`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>SelectableFlagsPrivate.NoHoldingActiveID</code></td>
      <td><code>1048576</code></td>
    </tr>
    <tr>
      <td><code>SelectableFlagsPrivate.SelectOnNav</code></td>
      <td><code>2097152</code></td>
    </tr>
    <tr>
      <td><code>SelectableFlagsPrivate.SelectOnClick</code></td>
      <td><code>4194304</code></td>
    </tr>
    <tr>
      <td><code>SelectableFlagsPrivate.SelectOnRelease</code></td>
      <td><code>8388608</code></td>
    </tr>
    <tr>
      <td><code>SelectableFlagsPrivate.SpanAvailWidth</code></td>
      <td><code>16777216</code></td>
    </tr>
    <tr>
      <td><code>SelectableFlagsPrivate.SetNavIdOnHover</code></td>
      <td><code>33554432</code></td>
    </tr>
    <tr>
      <td><code>SelectableFlagsPrivate.NoPadWithHalfSpacing</code></td>
      <td><code>67108864</code></td>
    </tr>
    <tr>
      <td><code>SelectableFlagsPrivate.NoSetKeyOwner</code></td>
      <td><code>134217728</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `SeparatorFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>SeparatorFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>SeparatorFlags.Horizontal</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>SeparatorFlags.Vertical</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>SeparatorFlags.SpanAllColumns</code></td>
      <td><code>4</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `SliderFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>SliderFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>SliderFlags.AlwaysClamp</code></td>
      <td><code>16</code></td>
    </tr>
    <tr>
      <td><code>SliderFlags.Logarithmic</code></td>
      <td><code>32</code></td>
    </tr>
    <tr>
      <td><code>SliderFlags.NoRoundToFormat</code></td>
      <td><code>64</code></td>
    </tr>
    <tr>
      <td><code>SliderFlags.NoInput</code></td>
      <td><code>128</code></td>
    </tr>
    <tr>
      <td><code>SliderFlags.InvalidMask_</code></td>
      <td><code>1879048207</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `SliderFlagsPrivate`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>SliderFlagsPrivate.Vertical</code></td>
      <td><code>1048576</code></td>
    </tr>
    <tr>
      <td><code>SliderFlagsPrivate.ReadOnly</code></td>
      <td><code>2097152</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `SortDirection`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>SortDirection.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>SortDirection.Ascending</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>SortDirection.Descending</code></td>
      <td><code>2</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `StyleVar`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>StyleVar.Alpha</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>StyleVar.DisabledAlpha</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>StyleVar.WindowPadding</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>StyleVar.WindowRounding</code></td>
      <td><code>3</code></td>
    </tr>
    <tr>
      <td><code>StyleVar.WindowBorderSize</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>StyleVar.WindowMinSize</code></td>
      <td><code>5</code></td>
    </tr>
    <tr>
      <td><code>StyleVar.WindowTitleAlign</code></td>
      <td><code>6</code></td>
    </tr>
    <tr>
      <td><code>StyleVar.ChildRounding</code></td>
      <td><code>7</code></td>
    </tr>
    <tr>
      <td><code>StyleVar.ChildBorderSize</code></td>
      <td><code>8</code></td>
    </tr>
    <tr>
      <td><code>StyleVar.PopupRounding</code></td>
      <td><code>9</code></td>
    </tr>
    <tr>
      <td><code>StyleVar.PopupBorderSize</code></td>
      <td><code>10</code></td>
    </tr>
    <tr>
      <td><code>StyleVar.FramePadding</code></td>
      <td><code>11</code></td>
    </tr>
    <tr>
      <td><code>StyleVar.FrameRounding</code></td>
      <td><code>12</code></td>
    </tr>
    <tr>
      <td><code>StyleVar.FrameBorderSize</code></td>
      <td><code>13</code></td>
    </tr>
    <tr>
      <td><code>StyleVar.ItemSpacing</code></td>
      <td><code>14</code></td>
    </tr>
    <tr>
      <td><code>StyleVar.ItemInnerSpacing</code></td>
      <td><code>15</code></td>
    </tr>
    <tr>
      <td><code>StyleVar.IndentSpacing</code></td>
      <td><code>16</code></td>
    </tr>
    <tr>
      <td><code>StyleVar.CellPadding</code></td>
      <td><code>17</code></td>
    </tr>
    <tr>
      <td><code>StyleVar.ScrollbarSize</code></td>
      <td><code>18</code></td>
    </tr>
    <tr>
      <td><code>StyleVar.ScrollbarRounding</code></td>
      <td><code>19</code></td>
    </tr>
    <tr>
      <td><code>StyleVar.GrabMinSize</code></td>
      <td><code>20</code></td>
    </tr>
    <tr>
      <td><code>StyleVar.GrabRounding</code></td>
      <td><code>21</code></td>
    </tr>
    <tr>
      <td><code>StyleVar.TabRounding</code></td>
      <td><code>22</code></td>
    </tr>
    <tr>
      <td><code>StyleVar.TabBarBorderSize</code></td>
      <td><code>23</code></td>
    </tr>
    <tr>
      <td><code>StyleVar.ButtonTextAlign</code></td>
      <td><code>24</code></td>
    </tr>
    <tr>
      <td><code>StyleVar.SelectableTextAlign</code></td>
      <td><code>25</code></td>
    </tr>
    <tr>
      <td><code>StyleVar.SeparatorTextBorderSize</code></td>
      <td><code>26</code></td>
    </tr>
    <tr>
      <td><code>StyleVar.SeparatorTextAlign</code></td>
      <td><code>27</code></td>
    </tr>
    <tr>
      <td><code>StyleVar.SeparatorTextPadding</code></td>
      <td><code>28</code></td>
    </tr>
    <tr>
      <td><code>StyleVar.DockingSeparatorSize</code></td>
      <td><code>29</code></td>
    </tr>
    <tr>
      <td><code>StyleVar.COUNT</code></td>
      <td><code>30</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `TabBarFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>TabBarFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>TabBarFlags.Reorderable</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>TabBarFlags.AutoSelectNewTabs</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>TabBarFlags.TabListPopupButton</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>TabBarFlags.NoCloseWithMiddleMouseButton</code></td>
      <td><code>8</code></td>
    </tr>
    <tr>
      <td><code>TabBarFlags.NoTabListScrollingButtons</code></td>
      <td><code>16</code></td>
    </tr>
    <tr>
      <td><code>TabBarFlags.NoTooltip</code></td>
      <td><code>32</code></td>
    </tr>
    <tr>
      <td><code>TabBarFlags.FittingPolicyDefault_</code></td>
      <td><code>64</code></td>
    </tr>
    <tr>
      <td><code>TabBarFlags.FittingPolicyResizeDown</code></td>
      <td><code>64</code></td>
    </tr>
    <tr>
      <td><code>TabBarFlags.FittingPolicyScroll</code></td>
      <td><code>128</code></td>
    </tr>
    <tr>
      <td><code>TabBarFlags.FittingPolicyMask_</code></td>
      <td><code>192</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `TabBarFlagsPrivate`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>TabBarFlagsPrivate.DockNode</code></td>
      <td><code>1048576</code></td>
    </tr>
    <tr>
      <td><code>TabBarFlagsPrivate.IsFocused</code></td>
      <td><code>2097152</code></td>
    </tr>
    <tr>
      <td><code>TabBarFlagsPrivate.SaveSettings</code></td>
      <td><code>4194304</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `TabItemFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>TabItemFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>TabItemFlags.UnsavedDocument</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>TabItemFlags.SetSelected</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>TabItemFlags.NoCloseWithMiddleMouseButton</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>TabItemFlags.NoPushId</code></td>
      <td><code>8</code></td>
    </tr>
    <tr>
      <td><code>TabItemFlags.NoTooltip</code></td>
      <td><code>16</code></td>
    </tr>
    <tr>
      <td><code>TabItemFlags.NoReorder</code></td>
      <td><code>32</code></td>
    </tr>
    <tr>
      <td><code>TabItemFlags.Leading</code></td>
      <td><code>64</code></td>
    </tr>
    <tr>
      <td><code>TabItemFlags.Trailing</code></td>
      <td><code>128</code></td>
    </tr>
    <tr>
      <td><code>TabItemFlags.NoAssumedClosure</code></td>
      <td><code>256</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `TabItemFlagsPrivate`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>TabItemFlagsPrivate.SectionMask_</code></td>
      <td><code>192</code></td>
    </tr>
    <tr>
      <td><code>TabItemFlagsPrivate.NoCloseButton</code></td>
      <td><code>1048576</code></td>
    </tr>
    <tr>
      <td><code>TabItemFlagsPrivate.Button</code></td>
      <td><code>2097152</code></td>
    </tr>
    <tr>
      <td><code>TabItemFlagsPrivate.Unsorted</code></td>
      <td><code>4194304</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `TableBgTarget`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>TableBgTarget.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>TableBgTarget.RowBg0</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>TableBgTarget.RowBg1</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>TableBgTarget.CellBg</code></td>
      <td><code>3</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `TableColumnFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>TableColumnFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>TableColumnFlags.Disabled</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>TableColumnFlags.DefaultHide</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>TableColumnFlags.DefaultSort</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>TableColumnFlags.WidthStretch</code></td>
      <td><code>8</code></td>
    </tr>
    <tr>
      <td><code>TableColumnFlags.WidthFixed</code></td>
      <td><code>16</code></td>
    </tr>
    <tr>
      <td><code>TableColumnFlags.WidthMask_</code></td>
      <td><code>24</code></td>
    </tr>
    <tr>
      <td><code>TableColumnFlags.NoResize</code></td>
      <td><code>32</code></td>
    </tr>
    <tr>
      <td><code>TableColumnFlags.NoReorder</code></td>
      <td><code>64</code></td>
    </tr>
    <tr>
      <td><code>TableColumnFlags.NoHide</code></td>
      <td><code>128</code></td>
    </tr>
    <tr>
      <td><code>TableColumnFlags.NoClip</code></td>
      <td><code>256</code></td>
    </tr>
    <tr>
      <td><code>TableColumnFlags.NoSort</code></td>
      <td><code>512</code></td>
    </tr>
    <tr>
      <td><code>TableColumnFlags.NoSortAscending</code></td>
      <td><code>1024</code></td>
    </tr>
    <tr>
      <td><code>TableColumnFlags.NoSortDescending</code></td>
      <td><code>2048</code></td>
    </tr>
    <tr>
      <td><code>TableColumnFlags.NoHeaderLabel</code></td>
      <td><code>4096</code></td>
    </tr>
    <tr>
      <td><code>TableColumnFlags.NoHeaderWidth</code></td>
      <td><code>8192</code></td>
    </tr>
    <tr>
      <td><code>TableColumnFlags.PreferSortAscending</code></td>
      <td><code>16384</code></td>
    </tr>
    <tr>
      <td><code>TableColumnFlags.PreferSortDescending</code></td>
      <td><code>32768</code></td>
    </tr>
    <tr>
      <td><code>TableColumnFlags.IndentEnable</code></td>
      <td><code>65536</code></td>
    </tr>
    <tr>
      <td><code>TableColumnFlags.IndentDisable</code></td>
      <td><code>131072</code></td>
    </tr>
    <tr>
      <td><code>TableColumnFlags.IndentMask_</code></td>
      <td><code>196608</code></td>
    </tr>
    <tr>
      <td><code>TableColumnFlags.AngledHeader</code></td>
      <td><code>262144</code></td>
    </tr>
    <tr>
      <td><code>TableColumnFlags.IsEnabled</code></td>
      <td><code>16777216</code></td>
    </tr>
    <tr>
      <td><code>TableColumnFlags.IsVisible</code></td>
      <td><code>33554432</code></td>
    </tr>
    <tr>
      <td><code>TableColumnFlags.IsSorted</code></td>
      <td><code>67108864</code></td>
    </tr>
    <tr>
      <td><code>TableColumnFlags.IsHovered</code></td>
      <td><code>134217728</code></td>
    </tr>
    <tr>
      <td><code>TableColumnFlags.StatusMask_</code></td>
      <td><code>251658240</code></td>
    </tr>
    <tr>
      <td><code>TableColumnFlags.NoDirectResize_</code></td>
      <td><code>1073741824</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `TableFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>TableFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>TableFlags.Resizable</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>TableFlags.Reorderable</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>TableFlags.Hideable</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>TableFlags.Sortable</code></td>
      <td><code>8</code></td>
    </tr>
    <tr>
      <td><code>TableFlags.NoSavedSettings</code></td>
      <td><code>16</code></td>
    </tr>
    <tr>
      <td><code>TableFlags.ContextMenuInBody</code></td>
      <td><code>32</code></td>
    </tr>
    <tr>
      <td><code>TableFlags.RowBg</code></td>
      <td><code>64</code></td>
    </tr>
    <tr>
      <td><code>TableFlags.BordersInnerH</code></td>
      <td><code>128</code></td>
    </tr>
    <tr>
      <td><code>TableFlags.BordersOuterH</code></td>
      <td><code>256</code></td>
    </tr>
    <tr>
      <td><code>TableFlags.BordersH</code></td>
      <td><code>384</code></td>
    </tr>
    <tr>
      <td><code>TableFlags.BordersInnerV</code></td>
      <td><code>512</code></td>
    </tr>
    <tr>
      <td><code>TableFlags.BordersInner</code></td>
      <td><code>640</code></td>
    </tr>
    <tr>
      <td><code>TableFlags.BordersOuterV</code></td>
      <td><code>1024</code></td>
    </tr>
    <tr>
      <td><code>TableFlags.BordersOuter</code></td>
      <td><code>1280</code></td>
    </tr>
    <tr>
      <td><code>TableFlags.BordersV</code></td>
      <td><code>1536</code></td>
    </tr>
    <tr>
      <td><code>TableFlags.Borders</code></td>
      <td><code>1920</code></td>
    </tr>
    <tr>
      <td><code>TableFlags.NoBordersInBody</code></td>
      <td><code>2048</code></td>
    </tr>
    <tr>
      <td><code>TableFlags.NoBordersInBodyUntilResize</code></td>
      <td><code>4096</code></td>
    </tr>
    <tr>
      <td><code>TableFlags.SizingFixedFit</code></td>
      <td><code>8192</code></td>
    </tr>
    <tr>
      <td><code>TableFlags.SizingFixedSame</code></td>
      <td><code>16384</code></td>
    </tr>
    <tr>
      <td><code>TableFlags.SizingStretchProp</code></td>
      <td><code>24576</code></td>
    </tr>
    <tr>
      <td><code>TableFlags.SizingStretchSame</code></td>
      <td><code>32768</code></td>
    </tr>
    <tr>
      <td><code>TableFlags.SizingMask_</code></td>
      <td><code>57344</code></td>
    </tr>
    <tr>
      <td><code>TableFlags.NoHostExtendX</code></td>
      <td><code>65536</code></td>
    </tr>
    <tr>
      <td><code>TableFlags.NoHostExtendY</code></td>
      <td><code>131072</code></td>
    </tr>
    <tr>
      <td><code>TableFlags.NoKeepColumnsVisible</code></td>
      <td><code>262144</code></td>
    </tr>
    <tr>
      <td><code>TableFlags.PreciseWidths</code></td>
      <td><code>524288</code></td>
    </tr>
    <tr>
      <td><code>TableFlags.NoClip</code></td>
      <td><code>1048576</code></td>
    </tr>
    <tr>
      <td><code>TableFlags.PadOuterX</code></td>
      <td><code>2097152</code></td>
    </tr>
    <tr>
      <td><code>TableFlags.NoPadOuterX</code></td>
      <td><code>4194304</code></td>
    </tr>
    <tr>
      <td><code>TableFlags.NoPadInnerX</code></td>
      <td><code>8388608</code></td>
    </tr>
    <tr>
      <td><code>TableFlags.ScrollX</code></td>
      <td><code>16777216</code></td>
    </tr>
    <tr>
      <td><code>TableFlags.ScrollY</code></td>
      <td><code>33554432</code></td>
    </tr>
    <tr>
      <td><code>TableFlags.SortMulti</code></td>
      <td><code>67108864</code></td>
    </tr>
    <tr>
      <td><code>TableFlags.SortTristate</code></td>
      <td><code>134217728</code></td>
    </tr>
    <tr>
      <td><code>TableFlags.HighlightHoveredColumn</code></td>
      <td><code>268435456</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `TableRowFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>TableRowFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>TableRowFlags.Headers</code></td>
      <td><code>1</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `TextFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>TextFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>TextFlags.NoWidthForLargeClippedText</code></td>
      <td><code>1</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `TooltipFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>TooltipFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>TooltipFlags.OverridePrevious</code></td>
      <td><code>2</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `TreeNodeFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>TreeNodeFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>TreeNodeFlags.Selected</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>TreeNodeFlags.Framed</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>TreeNodeFlags.AllowOverlap</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>TreeNodeFlags.NoTreePushOnOpen</code></td>
      <td><code>8</code></td>
    </tr>
    <tr>
      <td><code>TreeNodeFlags.NoAutoOpenOnLog</code></td>
      <td><code>16</code></td>
    </tr>
    <tr>
      <td><code>TreeNodeFlags.CollapsingHeader</code></td>
      <td><code>26</code></td>
    </tr>
    <tr>
      <td><code>TreeNodeFlags.DefaultOpen</code></td>
      <td><code>32</code></td>
    </tr>
    <tr>
      <td><code>TreeNodeFlags.OpenOnDoubleClick</code></td>
      <td><code>64</code></td>
    </tr>
    <tr>
      <td><code>TreeNodeFlags.OpenOnArrow</code></td>
      <td><code>128</code></td>
    </tr>
    <tr>
      <td><code>TreeNodeFlags.Leaf</code></td>
      <td><code>256</code></td>
    </tr>
    <tr>
      <td><code>TreeNodeFlags.Bullet</code></td>
      <td><code>512</code></td>
    </tr>
    <tr>
      <td><code>TreeNodeFlags.FramePadding</code></td>
      <td><code>1024</code></td>
    </tr>
    <tr>
      <td><code>TreeNodeFlags.SpanAvailWidth</code></td>
      <td><code>2048</code></td>
    </tr>
    <tr>
      <td><code>TreeNodeFlags.SpanFullWidth</code></td>
      <td><code>4096</code></td>
    </tr>
    <tr>
      <td><code>TreeNodeFlags.SpanAllColumns</code></td>
      <td><code>8192</code></td>
    </tr>
    <tr>
      <td><code>TreeNodeFlags.NavLeftJumpsBackHere</code></td>
      <td><code>16384</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `TreeNodeFlagsPrivate`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>TreeNodeFlagsPrivate.ClipLabelForTrailingButton</code></td>
      <td><code>1048576</code></td>
    </tr>
    <tr>
      <td><code>TreeNodeFlagsPrivate.UpsideDownArrow</code></td>
      <td><code>2097152</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `TypingSelectFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>TypingSelectFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>TypingSelectFlags.AllowBackspace</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>TypingSelectFlags.AllowSingleCharMode</code></td>
      <td><code>2</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `ViewportFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ViewportFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>ViewportFlags.IsPlatformWindow</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>ViewportFlags.IsPlatformMonitor</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>ViewportFlags.OwnedByApp</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>ViewportFlags.NoDecoration</code></td>
      <td><code>8</code></td>
    </tr>
    <tr>
      <td><code>ViewportFlags.NoTaskBarIcon</code></td>
      <td><code>16</code></td>
    </tr>
    <tr>
      <td><code>ViewportFlags.NoFocusOnAppearing</code></td>
      <td><code>32</code></td>
    </tr>
    <tr>
      <td><code>ViewportFlags.NoFocusOnClick</code></td>
      <td><code>64</code></td>
    </tr>
    <tr>
      <td><code>ViewportFlags.NoInputs</code></td>
      <td><code>128</code></td>
    </tr>
    <tr>
      <td><code>ViewportFlags.NoRendererClear</code></td>
      <td><code>256</code></td>
    </tr>
    <tr>
      <td><code>ViewportFlags.NoAutoMerge</code></td>
      <td><code>512</code></td>
    </tr>
    <tr>
      <td><code>ViewportFlags.TopMost</code></td>
      <td><code>1024</code></td>
    </tr>
    <tr>
      <td><code>ViewportFlags.CanHostOtherWindows</code></td>
      <td><code>2048</code></td>
    </tr>
    <tr>
      <td><code>ViewportFlags.IsMinimized</code></td>
      <td><code>4096</code></td>
    </tr>
    <tr>
      <td><code>ViewportFlags.IsFocused</code></td>
      <td><code>8192</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `WindowDockStyleCol`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>WindowDockStyleCol.Text</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>WindowDockStyleCol.Tab</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>WindowDockStyleCol.TabHovered</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>WindowDockStyleCol.TabActive</code></td>
      <td><code>3</code></td>
    </tr>
    <tr>
      <td><code>WindowDockStyleCol.TabUnfocused</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>WindowDockStyleCol.TabUnfocusedActive</code></td>
      <td><code>5</code></td>
    </tr>
    <tr>
      <td><code>WindowDockStyleCol.COUNT</code></td>
      <td><code>6</code></td>
    </tr>
  </tbody>
</table>

### Энумерация `WindowFlags`

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Значение</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>WindowFlags.None</code></td>
      <td><code>0</code></td>
    </tr>
    <tr>
      <td><code>WindowFlags.NoTitleBar</code></td>
      <td><code>1</code></td>
    </tr>
    <tr>
      <td><code>WindowFlags.NoResize</code></td>
      <td><code>2</code></td>
    </tr>
    <tr>
      <td><code>WindowFlags.NoMove</code></td>
      <td><code>4</code></td>
    </tr>
    <tr>
      <td><code>WindowFlags.NoScrollbar</code></td>
      <td><code>8</code></td>
    </tr>
    <tr>
      <td><code>WindowFlags.NoScrollWithMouse</code></td>
      <td><code>16</code></td>
    </tr>
    <tr>
      <td><code>WindowFlags.NoCollapse</code></td>
      <td><code>32</code></td>
    </tr>
    <tr>
      <td><code>WindowFlags.NoDecoration</code></td>
      <td><code>43</code></td>
    </tr>
    <tr>
      <td><code>WindowFlags.AlwaysAutoResize</code></td>
      <td><code>64</code></td>
    </tr>
    <tr>
      <td><code>WindowFlags.NoBackground</code></td>
      <td><code>128</code></td>
    </tr>
    <tr>
      <td><code>WindowFlags.NoSavedSettings</code></td>
      <td><code>256</code></td>
    </tr>
    <tr>
      <td><code>WindowFlags.NoMouseInputs</code></td>
      <td><code>512</code></td>
    </tr>
    <tr>
      <td><code>WindowFlags.MenuBar</code></td>
      <td><code>1024</code></td>
    </tr>
    <tr>
      <td><code>WindowFlags.HorizontalScrollbar</code></td>
      <td><code>2048</code></td>
    </tr>
    <tr>
      <td><code>WindowFlags.NoFocusOnAppearing</code></td>
      <td><code>4096</code></td>
    </tr>
    <tr>
      <td><code>WindowFlags.NoBringToFrontOnFocus</code></td>
      <td><code>8192</code></td>
    </tr>
    <tr>
      <td><code>WindowFlags.AlwaysVerticalScrollbar</code></td>
      <td><code>16384</code></td>
    </tr>
    <tr>
      <td><code>WindowFlags.AlwaysHorizontalScrollbar</code></td>
      <td><code>32768</code></td>
    </tr>
    <tr>
      <td><code>WindowFlags.NoNavInputs</code></td>
      <td><code>65536</code></td>
    </tr>
    <tr>
      <td><code>WindowFlags.NoNavFocus</code></td>
      <td><code>131072</code></td>
    </tr>
    <tr>
      <td><code>WindowFlags.NoNav</code></td>
      <td><code>196608</code></td>
    </tr>
    <tr>
      <td><code>WindowFlags.NoInputs</code></td>
      <td><code>197120</code></td>
    </tr>
    <tr>
      <td><code>WindowFlags.UnsavedDocument</code></td>
      <td><code>262144</code></td>
    </tr>
    <tr>
      <td><code>WindowFlags.NoDocking</code></td>
      <td><code>524288</code></td>
    </tr>
    <tr>
      <td><code>WindowFlags.NavFlattened</code></td>
      <td><code>8388608</code></td>
    </tr>
    <tr>
      <td><code>WindowFlags.ChildWindow</code></td>
      <td><code>16777216</code></td>
    </tr>
    <tr>
      <td><code>WindowFlags.Tooltip</code></td>
      <td><code>33554432</code></td>
    </tr>
    <tr>
      <td><code>WindowFlags.Popup</code></td>
      <td><code>67108864</code></td>
    </tr>
    <tr>
      <td><code>WindowFlags.Modal</code></td>
      <td><code>134217728</code></td>
    </tr>
    <tr>
      <td><code>WindowFlags.ChildMenu</code></td>
      <td><code>268435456</code></td>
    </tr>
    <tr>
      <td><code>WindowFlags.DockNodeHost</code></td>
      <td><code>536870912</code></td>
    </tr>
  </tbody>
</table>

---

## Класс `ImBitVector`

### Метод `ImBitVector:Clear`

#### Сигнатура

```lua
ImBitVector:Clear()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImBitVector:ClearBit`

#### Сигнатура

```lua
ImBitVector:ClearBit(n: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>n</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImBitVector:Create`

#### Сигнатура

```lua
ImBitVector:Create(sz: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>sz</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImBitVector:SetBit`

#### Сигнатура

```lua
ImBitVector:SetBit(n: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>n</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImBitVector:TestBit`

#### Сигнатура

```lua
ImBitVector:TestBit(n: number)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>n</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

---

## Класс `ImColor`

### ~~Функция `ImColor.ImColor_Float`~~

#### Сигнатура

```lua
function ImColor.ImColor_Float(r: any, g: any, b: any, a: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>r</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>g</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>b</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### ~~Функция `ImColor.ImColor_Int`~~

#### Сигнатура

```lua
function ImColor.ImColor_Int(r: any, g: any, b: any, a: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>r</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>g</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>b</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### ~~Функция `ImColor.ImColor_Nil`~~

#### Сигнатура

```lua
function ImColor.ImColor_Nil()
  -> ffi.cdata*
```

#### Возвращает

- `ffi.cdata*` 

### ~~Функция `ImColor.ImColor_U32`~~

#### Сигнатура

```lua
function ImColor.ImColor_U32(rgba: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>rgba</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### ~~Функция `ImColor.ImColor_Vec4`~~

#### Сигнатура

```lua
function ImColor.ImColor_Vec4(col: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>col</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### ~~Функция `ImColor.__new`~~

 generic version

#### Сигнатура

```lua
function ImColor.__new(ctype: any, a1: any, a2: any, a3: any, a4: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a3</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a4</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Метод `ImColor:SetHSV`

#### Сигнатура

```lua
ImColor:SetHSV(h: number, s: number, v: number, a?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>h</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>s</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>a</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

---

## Класс `ImDrawCmd`

### ~~Функция `ImDrawCmd.__new`~~

#### Сигнатура

```lua
function ImDrawCmd.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Метод `ImDrawCmd:GetTexID`

#### Сигнатура

```lua
ImDrawCmd:GetTexID()
  -> ImTextureID: number
```

#### Возвращает

- `number` 

---

## Класс `ImDrawData`

### ~~Функция `ImDrawData.__new`~~

#### Сигнатура

```lua
function ImDrawData.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Метод `ImDrawData:AddDrawList`

#### Сигнатура

```lua
ImDrawData:AddDrawList(draw_list: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>draw_list</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImDrawList*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawData:Clear`

#### Сигнатура

```lua
ImDrawData:Clear()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImDrawData:DeIndexAllBuffers`

#### Сигнатура

```lua
ImDrawData:DeIndexAllBuffers()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImDrawData:ScaleClipRects`

#### Сигнатура

```lua
ImDrawData:ScaleClipRects(fb_scale: ImVec2)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>fb_scale</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

---

## Класс `ImDrawDataBuilder`

### ~~Функция `ImDrawDataBuilder.__new`~~

#### Сигнатура

```lua
function ImDrawDataBuilder.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

---

## Класс `ImDrawList`

### ~~Функция `ImDrawList.__new`~~

#### Сигнатура

```lua
function ImDrawList.__new(ctype: any, shared_data: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>shared_data</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Метод `ImDrawList:AddBezierCubic`

#### Сигнатура

```lua
ImDrawList:AddBezierCubic(p1: ImVec2, p2: ImVec2, p3: ImVec2, p4: ImVec2, col: number, thickness: number, num_segments?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>p1</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p2</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p3</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p4</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
    <tr>
      <td><code>thickness</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>num_segments</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:AddBezierQuadratic`

#### Сигнатура

```lua
ImDrawList:AddBezierQuadratic(p1: ImVec2, p2: ImVec2, p3: ImVec2, col: number, thickness: number, num_segments?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>p1</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p2</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p3</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
    <tr>
      <td><code>thickness</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>num_segments</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:AddCallback`

#### Сигнатура

```lua
ImDrawList:AddCallback(callback: ffi.cdata*|ffi.cdecl*|ffi.ctype*, callback_data: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>callback</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImDrawCallback</td>
    </tr>
    <tr>
      <td><code>callback_data</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>void*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:AddCircle`

#### Сигнатура

```lua
ImDrawList:AddCircle(center: ImVec2, radius: number, col: number, num_segments?: number, thickness?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>center</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>radius</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
    <tr>
      <td><code>num_segments</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>thickness</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:AddCircleFilled`

#### Сигнатура

```lua
ImDrawList:AddCircleFilled(center: ImVec2, radius: number, col: number, num_segments?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>center</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>radius</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
    <tr>
      <td><code>num_segments</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:AddConvexPolyFilled`

#### Сигнатура

```lua
ImDrawList:AddConvexPolyFilled(points: ffi.cdata*|ffi.cdecl*|ffi.ctype*, num_points: number, col: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>points</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImVec2*</td>
    </tr>
    <tr>
      <td><code>num_points</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:AddDrawCmd`

#### Сигнатура

```lua
ImDrawList:AddDrawCmd()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImDrawList:AddEllipse`

#### Сигнатура

```lua
ImDrawList:AddEllipse(center: ImVec2, radius_x: number, radius_y: number, col: number, rot?: number, num_segments?: number, thickness?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>center</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>radius_x</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>radius_y</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
    <tr>
      <td><code>rot</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>num_segments</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>thickness</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:AddEllipseFilled`

#### Сигнатура

```lua
ImDrawList:AddEllipseFilled(center: ImVec2, radius_x: number, radius_y: number, col: number, rot?: number, num_segments?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>center</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>radius_x</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>radius_y</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
    <tr>
      <td><code>rot</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>num_segments</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:AddImage`

#### Сигнатура

```lua
ImDrawList:AddImage(user_texture_id: number, p_min: ImVec2, p_max: ImVec2, uv_min?: ImVec2, uv_max?: ImVec2, col?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>user_texture_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImTextureID</td>
    </tr>
    <tr>
      <td><code>p_min</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p_max</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>uv_min</code></td>
      <td><code>ImVec2</code></td>
      <td>нет</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>uv_max</code></td>
      <td><code>ImVec2</code></td>
      <td>нет</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>ImU32</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:AddImageQuad`

#### Сигнатура

```lua
ImDrawList:AddImageQuad(user_texture_id: number, p1: ImVec2, p2: ImVec2, p3: ImVec2, p4: ImVec2, uv1?: ImVec2, uv2?: ImVec2, uv3?: ImVec2, uv4?: ImVec2, col?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>user_texture_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImTextureID</td>
    </tr>
    <tr>
      <td><code>p1</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p2</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p3</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p4</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>uv1</code></td>
      <td><code>ImVec2</code></td>
      <td>нет</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>uv2</code></td>
      <td><code>ImVec2</code></td>
      <td>нет</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>uv3</code></td>
      <td><code>ImVec2</code></td>
      <td>нет</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>uv4</code></td>
      <td><code>ImVec2</code></td>
      <td>нет</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>ImU32</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:AddImageRounded`

#### Сигнатура

```lua
ImDrawList:AddImageRounded(user_texture_id: number, p_min: ImVec2, p_max: ImVec2, uv_min: ImVec2, uv_max: ImVec2, col: number, rounding: number, flags?: ImDrawFlags)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>user_texture_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImTextureID</td>
    </tr>
    <tr>
      <td><code>p_min</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p_max</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>uv_min</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>uv_max</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
    <tr>
      <td><code>rounding</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>ImDrawFlags</code></td>
      <td>нет</td>
      <td>-----------------------ImDrawFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:AddLine`

#### Сигнатура

```lua
ImDrawList:AddLine(p1: ImVec2, p2: ImVec2, col: number, thickness?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>p1</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p2</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
    <tr>
      <td><code>thickness</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:AddNgon`

#### Сигнатура

```lua
ImDrawList:AddNgon(center: ImVec2, radius: number, col: number, num_segments: number, thickness?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>center</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>radius</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
    <tr>
      <td><code>num_segments</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>thickness</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:AddNgonFilled`

#### Сигнатура

```lua
ImDrawList:AddNgonFilled(center: ImVec2, radius: number, col: number, num_segments: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>center</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>radius</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
    <tr>
      <td><code>num_segments</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:AddPolyline`

#### Сигнатура

```lua
ImDrawList:AddPolyline(points: ffi.cdata*|ffi.cdecl*|ffi.ctype*, num_points: number, col: number, flags: ImDrawFlags, thickness: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>points</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImVec2*</td>
    </tr>
    <tr>
      <td><code>num_points</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>ImDrawFlags</code></td>
      <td>да</td>
      <td>-----------------------ImDrawFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>thickness</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:AddQuad`

#### Сигнатура

```lua
ImDrawList:AddQuad(p1: ImVec2, p2: ImVec2, p3: ImVec2, p4: ImVec2, col: number, thickness?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>p1</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p2</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p3</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p4</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
    <tr>
      <td><code>thickness</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:AddQuadFilled`

#### Сигнатура

```lua
ImDrawList:AddQuadFilled(p1: ImVec2, p2: ImVec2, p3: ImVec2, p4: ImVec2, col: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>p1</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p2</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p3</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p4</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:AddRect`

#### Сигнатура

```lua
ImDrawList:AddRect(p_min: ImVec2, p_max: ImVec2, col: number, rounding?: number, flags?: ImDrawFlags, thickness?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>p_min</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p_max</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
    <tr>
      <td><code>rounding</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>ImDrawFlags</code></td>
      <td>нет</td>
      <td>-----------------------ImDrawFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>thickness</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:AddRectFilled`

#### Сигнатура

```lua
ImDrawList:AddRectFilled(p_min: ImVec2, p_max: ImVec2, col: number, rounding?: number, flags?: ImDrawFlags)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>p_min</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p_max</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
    <tr>
      <td><code>rounding</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>ImDrawFlags</code></td>
      <td>нет</td>
      <td>-----------------------ImDrawFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:AddRectFilledMultiColor`

#### Сигнатура

```lua
ImDrawList:AddRectFilledMultiColor(p_min: ImVec2, p_max: ImVec2, col_upr_left: number, col_upr_right: number, col_bot_right: number, col_bot_left: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>p_min</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p_max</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>col_upr_left</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
    <tr>
      <td><code>col_upr_right</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
    <tr>
      <td><code>col_bot_right</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
    <tr>
      <td><code>col_bot_left</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### ~~Метод `ImDrawList:AddText`~~

 generic version

#### Сигнатура

```lua
ImDrawList:AddText(a2: any, a3: any, a4: any, a5: any, a6: any, a7: any, a8: any, a9: any)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a3</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a4</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a5</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a6</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a7</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a8</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a9</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:AddText_FontPtr`

#### Сигнатура

```lua
ImDrawList:AddText_FontPtr(font: ffi.cdata*|ffi.cdecl*|ffi.ctype*, font_size: number, pos: ImVec2, col: number, text_begin: string, text_end?: string, wrap_width?: number, cpu_fine_clip_rect?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>font</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImFont*</td>
    </tr>
    <tr>
      <td><code>font_size</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>pos</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
    <tr>
      <td><code>text_begin</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>text_end</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>wrap_width</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>cpu_fine_clip_rect</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>const ImVec4*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:AddText_Vec2`

#### Сигнатура

```lua
ImDrawList:AddText_Vec2(pos: ImVec2, col: number, text_begin: string, text_end?: string)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>pos</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
    <tr>
      <td><code>text_begin</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>text_end</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:AddTriangle`

#### Сигнатура

```lua
ImDrawList:AddTriangle(p1: ImVec2, p2: ImVec2, p3: ImVec2, col: number, thickness?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>p1</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p2</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p3</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
    <tr>
      <td><code>thickness</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:AddTriangleFilled`

#### Сигнатура

```lua
ImDrawList:AddTriangleFilled(p1: ImVec2, p2: ImVec2, p3: ImVec2, col: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>p1</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p2</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p3</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:ChannelsMerge`

#### Сигнатура

```lua
ImDrawList:ChannelsMerge()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImDrawList:ChannelsSetCurrent`

#### Сигнатура

```lua
ImDrawList:ChannelsSetCurrent(n: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>n</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:ChannelsSplit`

#### Сигнатура

```lua
ImDrawList:ChannelsSplit(count: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>count</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:CloneOutput`

#### Сигнатура

```lua
ImDrawList:CloneOutput()
  -> ImDrawList*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Метод `ImDrawList:GetClipRectMax`

#### Сигнатура

```lua
ImDrawList:GetClipRectMax()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImDrawList:GetClipRectMin`

#### Сигнатура

```lua
ImDrawList:GetClipRectMin()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImDrawList:PathArcTo`

#### Сигнатура

```lua
ImDrawList:PathArcTo(center: ImVec2, radius: number, a_min: number, a_max: number, num_segments?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>center</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>radius</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>a_min</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>a_max</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>num_segments</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:PathArcToFast`

#### Сигнатура

```lua
ImDrawList:PathArcToFast(center: ImVec2, radius: number, a_min_of_12: number, a_max_of_12: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>center</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>radius</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>a_min_of_12</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>a_max_of_12</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:PathBezierCubicCurveTo`

#### Сигнатура

```lua
ImDrawList:PathBezierCubicCurveTo(p2: ImVec2, p3: ImVec2, p4: ImVec2, num_segments?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>p2</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p3</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p4</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>num_segments</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:PathBezierQuadraticCurveTo`

#### Сигнатура

```lua
ImDrawList:PathBezierQuadraticCurveTo(p2: ImVec2, p3: ImVec2, num_segments?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>p2</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>p3</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>num_segments</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:PathClear`

#### Сигнатура

```lua
ImDrawList:PathClear()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImDrawList:PathEllipticalArcTo`

#### Сигнатура

```lua
ImDrawList:PathEllipticalArcTo(center: ImVec2, radius_x: number, radius_y: number, rot: number, a_min: number, a_max: number, num_segments?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>center</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>radius_x</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>radius_y</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>rot</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>a_min</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>a_max</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>num_segments</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:PathFillConvex`

#### Сигнатура

```lua
ImDrawList:PathFillConvex(col: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:PathLineTo`

#### Сигнатура

```lua
ImDrawList:PathLineTo(pos: ImVec2)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>pos</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:PathLineToMergeDuplicate`

#### Сигнатура

```lua
ImDrawList:PathLineToMergeDuplicate(pos: ImVec2)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>pos</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:PathRect`

#### Сигнатура

```lua
ImDrawList:PathRect(rect_min: ImVec2, rect_max: ImVec2, rounding?: number, flags?: ImDrawFlags)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>rect_min</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>rect_max</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>rounding</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>ImDrawFlags</code></td>
      <td>нет</td>
      <td>-----------------------ImDrawFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:PathStroke`

#### Сигнатура

```lua
ImDrawList:PathStroke(col: number, flags?: ImDrawFlags, thickness?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
    <tr>
      <td><code>flags</code></td>
      <td><code>ImDrawFlags</code></td>
      <td>нет</td>
      <td>-----------------------ImDrawFlags----------------------------</td>
    </tr>
    <tr>
      <td><code>thickness</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:PopClipRect`

#### Сигнатура

```lua
ImDrawList:PopClipRect()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImDrawList:PopTextureID`

#### Сигнатура

```lua
ImDrawList:PopTextureID()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImDrawList:PrimQuadUV`

#### Сигнатура

```lua
ImDrawList:PrimQuadUV(a: ImVec2, b: ImVec2, c: ImVec2, d: ImVec2, uv_a: ImVec2, uv_b: ImVec2, uv_c: ImVec2, uv_d: ImVec2, col: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>b</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>c</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>d</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>uv_a</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>uv_b</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>uv_c</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>uv_d</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:PrimRect`

#### Сигнатура

```lua
ImDrawList:PrimRect(a: ImVec2, b: ImVec2, col: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>b</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:PrimRectUV`

#### Сигнатура

```lua
ImDrawList:PrimRectUV(a: ImVec2, b: ImVec2, uv_a: ImVec2, uv_b: ImVec2, col: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>b</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>uv_a</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>uv_b</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:PrimReserve`

#### Сигнатура

```lua
ImDrawList:PrimReserve(idx_count: number, vtx_count: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>idx_count</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>vtx_count</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:PrimUnreserve`

#### Сигнатура

```lua
ImDrawList:PrimUnreserve(idx_count: number, vtx_count: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>idx_count</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>vtx_count</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:PrimVtx`

#### Сигнатура

```lua
ImDrawList:PrimVtx(pos: ImVec2, uv: ImVec2, col: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>pos</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>uv</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:PrimWriteIdx`

#### Сигнатура

```lua
ImDrawList:PrimWriteIdx(idx: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>idx</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImDrawIdx</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:PrimWriteVtx`

#### Сигнатура

```lua
ImDrawList:PrimWriteVtx(pos: ImVec2, uv: ImVec2, col: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>pos</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>uv</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:PushClipRect`

#### Сигнатура

```lua
ImDrawList:PushClipRect(clip_rect_min: ImVec2, clip_rect_max: ImVec2, intersect_with_current_clip_rect?: boolean)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>clip_rect_min</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>clip_rect_max</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>intersect_with_current_clip_rect</code></td>
      <td><code>boolean</code></td>
      <td>нет</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:PushClipRectFullScreen`

#### Сигнатура

```lua
ImDrawList:PushClipRectFullScreen()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImDrawList:PushTextureID`

#### Сигнатура

```lua
ImDrawList:PushTextureID(texture_id: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>texture_id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImTextureID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:_CalcCircleAutoSegmentCount`

#### Сигнатура

```lua
ImDrawList:_CalcCircleAutoSegmentCount(radius: number)
  -> int: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>radius</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Метод `ImDrawList:_ClearFreeMemory`

#### Сигнатура

```lua
ImDrawList:_ClearFreeMemory()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImDrawList:_OnChangedClipRect`

#### Сигнатура

```lua
ImDrawList:_OnChangedClipRect()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImDrawList:_OnChangedTextureID`

#### Сигнатура

```lua
ImDrawList:_OnChangedTextureID()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImDrawList:_OnChangedVtxOffset`

#### Сигнатура

```lua
ImDrawList:_OnChangedVtxOffset()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImDrawList:_PathArcToFastEx`

#### Сигнатура

```lua
ImDrawList:_PathArcToFastEx(center: ImVec2, radius: number, a_min_sample: number, a_max_sample: number, a_step: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>center</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>radius</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>a_min_sample</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>a_max_sample</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>a_step</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:_PathArcToN`

#### Сигнатура

```lua
ImDrawList:_PathArcToN(center: ImVec2, radius: number, a_min: number, a_max: number, num_segments: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>center</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>radius</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>a_min</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>a_max</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>num_segments</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawList:_PopUnusedDrawCmd`

#### Сигнатура

```lua
ImDrawList:_PopUnusedDrawCmd()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImDrawList:_ResetForNewFrame`

#### Сигнатура

```lua
ImDrawList:_ResetForNewFrame()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImDrawList:_TryMergeDrawCmds`

#### Сигнатура

```lua
ImDrawList:_TryMergeDrawCmds()
  -> nil
```

#### Возвращает

- `nil` 

---

## Класс `ImDrawListSharedData`

### ~~Функция `ImDrawListSharedData.__new`~~

#### Сигнатура

```lua
function ImDrawListSharedData.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Метод `ImDrawListSharedData:SetCircleTessellationMaxError`

#### Сигнатура

```lua
ImDrawListSharedData:SetCircleTessellationMaxError(max_error: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>max_error</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

---

## Класс `ImDrawListSplitter`

### ~~Функция `ImDrawListSplitter.__new`~~

#### Сигнатура

```lua
function ImDrawListSplitter.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Метод `ImDrawListSplitter:Clear`

#### Сигнатура

```lua
ImDrawListSplitter:Clear()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImDrawListSplitter:ClearFreeMemory`

#### Сигнатура

```lua
ImDrawListSplitter:ClearFreeMemory()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImDrawListSplitter:Merge`

#### Сигнатура

```lua
ImDrawListSplitter:Merge(draw_list: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>draw_list</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImDrawList*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawListSplitter:SetCurrentChannel`

#### Сигнатура

```lua
ImDrawListSplitter:SetCurrentChannel(draw_list: ffi.cdata*|ffi.cdecl*|ffi.ctype*, channel_idx: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>draw_list</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImDrawList*</td>
    </tr>
    <tr>
      <td><code>channel_idx</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImDrawListSplitter:Split`

#### Сигнатура

```lua
ImDrawListSplitter:Split(draw_list: ffi.cdata*|ffi.cdecl*|ffi.ctype*, count: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>draw_list</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImDrawList*</td>
    </tr>
    <tr>
      <td><code>count</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

---

## Класс `ImFont`

### ~~Функция `ImFont.__new`~~

#### Сигнатура

```lua
function ImFont.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Метод `ImFont:AddGlyph`

#### Сигнатура

```lua
ImFont:AddGlyph(src_cfg: ffi.cdata*|ffi.cdecl*|ffi.ctype*, c: number, x0: number, y0: number, x1: number, y1: number, u0: number, v0: number, u1: number, v1: number, advance_x: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>src_cfg</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImFontConfig*</td>
    </tr>
    <tr>
      <td><code>c</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImWchar</td>
    </tr>
    <tr>
      <td><code>x0</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>y0</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>x1</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>y1</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>u0</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>v0</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>u1</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>v1</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>advance_x</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImFont:AddRemapChar`

#### Сигнатура

```lua
ImFont:AddRemapChar(dst: number, src: number, overwrite_dst?: boolean)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>dst</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImWchar</td>
    </tr>
    <tr>
      <td><code>src</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImWchar</td>
    </tr>
    <tr>
      <td><code>overwrite_dst</code></td>
      <td><code>boolean</code></td>
      <td>нет</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImFont:BuildLookupTable`

#### Сигнатура

```lua
ImFont:BuildLookupTable()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImFont:CalcTextSizeA`

#### Сигнатура

```lua
ImFont:CalcTextSizeA(size: number, max_width: number, wrap_width: number, text_begin: string, text_end?: string, remaining?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>size</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>max_width</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>wrap_width</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>text_begin</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>text_end</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>remaining</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>const char**</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImFont:CalcWordWrapPositionA`

#### Сигнатура

```lua
ImFont:CalcWordWrapPositionA(scale: number, text: string, text_end: string, wrap_width: number)
  -> string
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>scale</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>text</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>text_end</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>wrap_width</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `string` 

### Метод `ImFont:ClearOutputData`

#### Сигнатура

```lua
ImFont:ClearOutputData()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImFont:FindGlyph`

#### Сигнатура

```lua
ImFont:FindGlyph(c: number)
  -> const: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>c</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImWchar</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Метод `ImFont:FindGlyphNoFallback`

#### Сигнатура

```lua
ImFont:FindGlyphNoFallback(c: number)
  -> const: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>c</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImWchar</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Метод `ImFont:GetCharAdvance`

#### Сигнатура

```lua
ImFont:GetCharAdvance(c: number)
  -> float: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>c</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImWchar</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Метод `ImFont:GetDebugName`

#### Сигнатура

```lua
ImFont:GetDebugName()
  -> string
```

#### Возвращает

- `string` 

### Метод `ImFont:GrowIndex`

#### Сигнатура

```lua
ImFont:GrowIndex(new_size: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>new_size</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImFont:IsGlyphRangeUnused`

#### Сигнатура

```lua
ImFont:IsGlyphRangeUnused(c_begin: number, c_last: number)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>c_begin</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>unsigned int</td>
    </tr>
    <tr>
      <td><code>c_last</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>unsigned int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Метод `ImFont:IsLoaded`

#### Сигнатура

```lua
ImFont:IsLoaded()
  -> boolean
```

#### Возвращает

- `boolean` 

### Метод `ImFont:RenderChar`

#### Сигнатура

```lua
ImFont:RenderChar(draw_list: ffi.cdata*|ffi.cdecl*|ffi.ctype*, size: number, pos: ImVec2, col: number, c: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>draw_list</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImDrawList*</td>
    </tr>
    <tr>
      <td><code>size</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>pos</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
    <tr>
      <td><code>c</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImWchar</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImFont:RenderText`

#### Сигнатура

```lua
ImFont:RenderText(draw_list: ffi.cdata*|ffi.cdecl*|ffi.ctype*, size: number, pos: ImVec2, col: number, clip_rect: ffi.cdata*|ffi.cdecl*|ffi.ctype*, text_begin: string, text_end: string, wrap_width?: number, cpu_fine_clip?: boolean)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>draw_list</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImDrawList*</td>
    </tr>
    <tr>
      <td><code>size</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>pos</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>col</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImU32</td>
    </tr>
    <tr>
      <td><code>clip_rect</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImVec4</td>
    </tr>
    <tr>
      <td><code>text_begin</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>text_end</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>wrap_width</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>cpu_fine_clip</code></td>
      <td><code>boolean</code></td>
      <td>нет</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImFont:SetGlyphVisible`

#### Сигнатура

```lua
ImFont:SetGlyphVisible(c: number, visible: boolean)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>c</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImWchar</td>
    </tr>
    <tr>
      <td><code>visible</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

---

## Класс `ImFontAtlas`

### ~~Функция `ImFontAtlas.__new`~~

#### Сигнатура

```lua
function ImFontAtlas.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Метод `ImFontAtlas:AddCustomRectFontGlyph`

#### Сигнатура

```lua
ImFontAtlas:AddCustomRectFontGlyph(font: ffi.cdata*|ffi.cdecl*|ffi.ctype*, id: number, width: number, height: number, advance_x: number, offset?: ImVec2)
  -> int: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>font</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImFont*</td>
    </tr>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImWchar</td>
    </tr>
    <tr>
      <td><code>width</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>height</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>advance_x</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>offset</code></td>
      <td><code>ImVec2</code></td>
      <td>нет</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Метод `ImFontAtlas:AddCustomRectRegular`

#### Сигнатура

```lua
ImFontAtlas:AddCustomRectRegular(width: number, height: number)
  -> int: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>width</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>height</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Метод `ImFontAtlas:AddFont`

#### Сигнатура

```lua
ImFontAtlas:AddFont(font_cfg: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> ImFont*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>font_cfg</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImFontConfig*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Метод `ImFontAtlas:AddFontDefault`

#### Сигнатура

```lua
ImFontAtlas:AddFontDefault(font_cfg?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> ImFont*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>font_cfg</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>const ImFontConfig*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Метод `ImFontAtlas:AddFontFromFileTTF`

#### Сигнатура

```lua
ImFontAtlas:AddFontFromFileTTF(filename: string, size_pixels: number, font_cfg?: ffi.cdata*|ffi.cdecl*|ffi.ctype*, glyph_ranges?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> ImFont*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>filename</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>size_pixels</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>font_cfg</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>const ImFontConfig*</td>
    </tr>
    <tr>
      <td><code>glyph_ranges</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>const ImWchar*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Метод `ImFontAtlas:AddFontFromMemoryCompressedBase85TTF`

#### Сигнатура

```lua
ImFontAtlas:AddFontFromMemoryCompressedBase85TTF(compressed_font_data_base85: string, size_pixels: number, font_cfg?: ffi.cdata*|ffi.cdecl*|ffi.ctype*, glyph_ranges?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> ImFont*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>compressed_font_data_base85</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>size_pixels</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>font_cfg</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>const ImFontConfig*</td>
    </tr>
    <tr>
      <td><code>glyph_ranges</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>const ImWchar*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Метод `ImFontAtlas:AddFontFromMemoryCompressedTTF`

#### Сигнатура

```lua
ImFontAtlas:AddFontFromMemoryCompressedTTF(compressed_font_data: ffi.cdata*|ffi.cdecl*|ffi.ctype*, compressed_font_data_size: number, size_pixels: number, font_cfg?: ffi.cdata*|ffi.cdecl*|ffi.ctype*, glyph_ranges?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> ImFont*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>compressed_font_data</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const void*</td>
    </tr>
    <tr>
      <td><code>compressed_font_data_size</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>size_pixels</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>font_cfg</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>const ImFontConfig*</td>
    </tr>
    <tr>
      <td><code>glyph_ranges</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>const ImWchar*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Метод `ImFontAtlas:AddFontFromMemoryTTF`

#### Сигнатура

```lua
ImFontAtlas:AddFontFromMemoryTTF(font_data: ffi.cdata*|ffi.cdecl*|ffi.ctype*, font_data_size: number, size_pixels: number, font_cfg?: ffi.cdata*|ffi.cdecl*|ffi.ctype*, glyph_ranges?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> ImFont*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>font_data</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>void*</td>
    </tr>
    <tr>
      <td><code>font_data_size</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>size_pixels</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>font_cfg</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>const ImFontConfig*</td>
    </tr>
    <tr>
      <td><code>glyph_ranges</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>const ImWchar*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Метод `ImFontAtlas:Build`

#### Сигнатура

```lua
ImFontAtlas:Build()
  -> boolean
```

#### Возвращает

- `boolean` 

### Метод `ImFontAtlas:CalcCustomRectUV`

#### Сигнатура

```lua
ImFontAtlas:CalcCustomRectUV(rect: ffi.cdata*|ffi.cdecl*|ffi.ctype*, out_uv_min: ffi.cdata*|ffi.cdecl*|ffi.ctype*, out_uv_max: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>rect</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImFontAtlasCustomRect*</td>
    </tr>
    <tr>
      <td><code>out_uv_min</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImVec2*</td>
    </tr>
    <tr>
      <td><code>out_uv_max</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImVec2*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImFontAtlas:Clear`

#### Сигнатура

```lua
ImFontAtlas:Clear()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImFontAtlas:ClearFonts`

#### Сигнатура

```lua
ImFontAtlas:ClearFonts()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImFontAtlas:ClearInputData`

#### Сигнатура

```lua
ImFontAtlas:ClearInputData()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImFontAtlas:ClearTexData`

#### Сигнатура

```lua
ImFontAtlas:ClearTexData()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImFontAtlas:GetCustomRectByIndex`

#### Сигнатура

```lua
ImFontAtlas:GetCustomRectByIndex(index: number)
  -> ImFontAtlasCustomRect*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>index</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Метод `ImFontAtlas:GetGlyphRangesChineseFull`

#### Сигнатура

```lua
ImFontAtlas:GetGlyphRangesChineseFull()
  -> const: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Метод `ImFontAtlas:GetGlyphRangesChineseSimplifiedCommon`

#### Сигнатура

```lua
ImFontAtlas:GetGlyphRangesChineseSimplifiedCommon()
  -> const: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Метод `ImFontAtlas:GetGlyphRangesCyrillic`

#### Сигнатура

```lua
ImFontAtlas:GetGlyphRangesCyrillic()
  -> const: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Метод `ImFontAtlas:GetGlyphRangesDefault`

#### Сигнатура

```lua
ImFontAtlas:GetGlyphRangesDefault()
  -> const: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Метод `ImFontAtlas:GetGlyphRangesGreek`

#### Сигнатура

```lua
ImFontAtlas:GetGlyphRangesGreek()
  -> const: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Метод `ImFontAtlas:GetGlyphRangesJapanese`

#### Сигнатура

```lua
ImFontAtlas:GetGlyphRangesJapanese()
  -> const: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Метод `ImFontAtlas:GetGlyphRangesKorean`

#### Сигнатура

```lua
ImFontAtlas:GetGlyphRangesKorean()
  -> const: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Метод `ImFontAtlas:GetGlyphRangesThai`

#### Сигнатура

```lua
ImFontAtlas:GetGlyphRangesThai()
  -> const: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Метод `ImFontAtlas:GetGlyphRangesVietnamese`

#### Сигнатура

```lua
ImFontAtlas:GetGlyphRangesVietnamese()
  -> const: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Метод `ImFontAtlas:GetMouseCursorTexData`

#### Сигнатура

```lua
ImFontAtlas:GetMouseCursorTexData(cursor: MouseCursor, out_offset: ffi.cdata*|ffi.cdecl*|ffi.ctype*, out_size: ffi.cdata*|ffi.cdecl*|ffi.ctype*, out_uv_border: ffi.cdata*|ffi.cdecl*|ffi.ctype*, out_uv_fill: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>cursor</code></td>
      <td><code>MouseCursor</code></td>
      <td>да</td>
      <td>-----------------------MouseCursor----------------------------</td>
    </tr>
    <tr>
      <td><code>out_offset</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImVec2*</td>
    </tr>
    <tr>
      <td><code>out_size</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImVec2*</td>
    </tr>
    <tr>
      <td><code>out_uv_border</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImVec2[2]</td>
    </tr>
    <tr>
      <td><code>out_uv_fill</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImVec2[2]</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Метод `ImFontAtlas:GetTexDataAsAlpha8`

#### Сигнатура

```lua
ImFontAtlas:GetTexDataAsAlpha8(out_pixels: ffi.cdata*|ffi.cdecl*|ffi.ctype*, out_width: ffi.cdata*|ffi.cdecl*|ffi.ctype*, out_height: ffi.cdata*|ffi.cdecl*|ffi.ctype*, out_bytes_per_pixel?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>out_pixels</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>unsigned char**</td>
    </tr>
    <tr>
      <td><code>out_width</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>int*</td>
    </tr>
    <tr>
      <td><code>out_height</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>int*</td>
    </tr>
    <tr>
      <td><code>out_bytes_per_pixel</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>int*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImFontAtlas:GetTexDataAsRGBA32`

#### Сигнатура

```lua
ImFontAtlas:GetTexDataAsRGBA32(out_pixels: ffi.cdata*|ffi.cdecl*|ffi.ctype*, out_width: ffi.cdata*|ffi.cdecl*|ffi.ctype*, out_height: ffi.cdata*|ffi.cdecl*|ffi.ctype*, out_bytes_per_pixel?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>out_pixels</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>unsigned char**</td>
    </tr>
    <tr>
      <td><code>out_width</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>int*</td>
    </tr>
    <tr>
      <td><code>out_height</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>int*</td>
    </tr>
    <tr>
      <td><code>out_bytes_per_pixel</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>int*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImFontAtlas:IsBuilt`

#### Сигнатура

```lua
ImFontAtlas:IsBuilt()
  -> boolean
```

#### Возвращает

- `boolean` 

### Метод `ImFontAtlas:SetTexID`

#### Сигнатура

```lua
ImFontAtlas:SetTexID(id: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImTextureID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

---

## Класс `ImFontAtlasCustomRect`

### ~~Функция `ImFontAtlasCustomRect.__new`~~

#### Сигнатура

```lua
function ImFontAtlasCustomRect.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Метод `ImFontAtlasCustomRect:IsPacked`

#### Сигнатура

```lua
ImFontAtlasCustomRect:IsPacked()
  -> boolean
```

#### Возвращает

- `boolean` 

---

## Класс `ImFontConfig`

### ~~Функция `ImFontConfig.__new`~~

#### Сигнатура

```lua
function ImFontConfig.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

---

## Класс `ImFontGlyphRangesBuilder`

### ~~Функция `ImFontGlyphRangesBuilder.__new`~~

#### Сигнатура

```lua
function ImFontGlyphRangesBuilder.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Метод `ImFontGlyphRangesBuilder:AddChar`

#### Сигнатура

```lua
ImFontGlyphRangesBuilder:AddChar(c: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>c</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImWchar</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImFontGlyphRangesBuilder:AddRanges`

#### Сигнатура

```lua
ImFontGlyphRangesBuilder:AddRanges(ranges: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ranges</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const ImWchar*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImFontGlyphRangesBuilder:AddText`

#### Сигнатура

```lua
ImFontGlyphRangesBuilder:AddText(text: string, text_end?: string)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>text</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>text_end</code></td>
      <td><code>string</code></td>
      <td>нет</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImFontGlyphRangesBuilder:BuildRanges`

#### Сигнатура

```lua
ImFontGlyphRangesBuilder:BuildRanges(out_ranges: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>out_ranges</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImVector_ImWchar*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImFontGlyphRangesBuilder:Clear`

#### Сигнатура

```lua
ImFontGlyphRangesBuilder:Clear()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImFontGlyphRangesBuilder:GetBit`

#### Сигнатура

```lua
ImFontGlyphRangesBuilder:GetBit(n: number)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>n</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>size_t</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Метод `ImFontGlyphRangesBuilder:SetBit`

#### Сигнатура

```lua
ImFontGlyphRangesBuilder:SetBit(n: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>n</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>size_t</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

---

## Класс `ImGuiComboPreviewData`

### ~~Функция `ImGuiComboPreviewData.__new`~~

#### Сигнатура

```lua
function ImGuiComboPreviewData.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

---

## Класс `ImGuiContext`

### ~~Функция `ImGuiContext.__new`~~

#### Сигнатура

```lua
function ImGuiContext.__new(ctype: any, shared_font_atlas: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>shared_font_atlas</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

---

## Класс `ImGuiContextHook`

### ~~Функция `ImGuiContextHook.__new`~~

#### Сигнатура

```lua
function ImGuiContextHook.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

---

## Класс `ImGuiDataVarInfo`

### Метод `ImGuiDataVarInfo:GetVarPtr`

#### Сигнатура

```lua
ImGuiDataVarInfo:GetVarPtr(parent: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> void*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>parent</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>void*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

---

## Класс `ImGuiDebugAllocInfo`

### ~~Функция `ImGuiDebugAllocInfo.__new`~~

#### Сигнатура

```lua
function ImGuiDebugAllocInfo.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

---

## Класс `ImGuiDockContext`

### ~~Функция `ImGuiDockContext.__new`~~

#### Сигнатура

```lua
function ImGuiDockContext.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

---

## Класс `ImGuiDockNode`

### ~~Функция `ImGuiDockNode.__new`~~

#### Сигнатура

```lua
function ImGuiDockNode.__new(ctype: any, id: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>id</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Метод `ImGuiDockNode:IsCentralNode`

#### Сигнатура

```lua
ImGuiDockNode:IsCentralNode()
  -> boolean
```

#### Возвращает

- `boolean` 

### Метод `ImGuiDockNode:IsDockSpace`

#### Сигнатура

```lua
ImGuiDockNode:IsDockSpace()
  -> boolean
```

#### Возвращает

- `boolean` 

### Метод `ImGuiDockNode:IsEmpty`

#### Сигнатура

```lua
ImGuiDockNode:IsEmpty()
  -> boolean
```

#### Возвращает

- `boolean` 

### Метод `ImGuiDockNode:IsFloatingNode`

#### Сигнатура

```lua
ImGuiDockNode:IsFloatingNode()
  -> boolean
```

#### Возвращает

- `boolean` 

### Метод `ImGuiDockNode:IsHiddenTabBar`

#### Сигнатура

```lua
ImGuiDockNode:IsHiddenTabBar()
  -> boolean
```

#### Возвращает

- `boolean` 

### Метод `ImGuiDockNode:IsLeafNode`

#### Сигнатура

```lua
ImGuiDockNode:IsLeafNode()
  -> boolean
```

#### Возвращает

- `boolean` 

### Метод `ImGuiDockNode:IsNoTabBar`

#### Сигнатура

```lua
ImGuiDockNode:IsNoTabBar()
  -> boolean
```

#### Возвращает

- `boolean` 

### Метод `ImGuiDockNode:IsRootNode`

#### Сигнатура

```lua
ImGuiDockNode:IsRootNode()
  -> boolean
```

#### Возвращает

- `boolean` 

### Метод `ImGuiDockNode:IsSplitNode`

#### Сигнатура

```lua
ImGuiDockNode:IsSplitNode()
  -> boolean
```

#### Возвращает

- `boolean` 

### Метод `ImGuiDockNode:Rect`

#### Сигнатура

```lua
ImGuiDockNode:Rect()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImGuiDockNode:SetLocalFlags`

#### Сигнатура

```lua
ImGuiDockNode:SetLocalFlags(flags: DockNodeFlags)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>flags</code></td>
      <td><code>DockNodeFlags</code></td>
      <td>да</td>
      <td>-----------------------DockNodeFlags----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImGuiDockNode:UpdateMergedFlags`

#### Сигнатура

```lua
ImGuiDockNode:UpdateMergedFlags()
  -> nil
```

#### Возвращает

- `nil` 

---

## Класс `ImGuiIDStackTool`

### ~~Функция `ImGuiIDStackTool.__new`~~

#### Сигнатура

```lua
function ImGuiIDStackTool.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

---

## Класс `ImGuiIO`

### ~~Функция `ImGuiIO.__new`~~

#### Сигнатура

```lua
function ImGuiIO.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Метод `ImGuiIO:AddFocusEvent`

#### Сигнатура

```lua
ImGuiIO:AddFocusEvent(focused: boolean)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>focused</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImGuiIO:AddInputCharacter`

#### Сигнатура

```lua
ImGuiIO:AddInputCharacter(c: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>c</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>unsigned int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImGuiIO:AddInputCharacterUTF16`

#### Сигнатура

```lua
ImGuiIO:AddInputCharacterUTF16(c: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>c</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImWchar16</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImGuiIO:AddInputCharactersUTF8`

#### Сигнатура

```lua
ImGuiIO:AddInputCharactersUTF8(str: string)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>str</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImGuiIO:AddKeyAnalogEvent`

#### Сигнатура

```lua
ImGuiIO:AddKeyAnalogEvent(key: Key, down: boolean, v: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>Key</code></td>
      <td>да</td>
      <td>-----------------------Key----------------------------</td>
    </tr>
    <tr>
      <td><code>down</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImGuiIO:AddKeyEvent`

#### Сигнатура

```lua
ImGuiIO:AddKeyEvent(key: Key, down: boolean)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>Key</code></td>
      <td>да</td>
      <td>-----------------------Key----------------------------</td>
    </tr>
    <tr>
      <td><code>down</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImGuiIO:AddMouseButtonEvent`

#### Сигнатура

```lua
ImGuiIO:AddMouseButtonEvent(button: number, down: boolean)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>button</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>down</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImGuiIO:AddMousePosEvent`

#### Сигнатура

```lua
ImGuiIO:AddMousePosEvent(x: number, y: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>x</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>y</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImGuiIO:AddMouseSourceEvent`

#### Сигнатура

```lua
ImGuiIO:AddMouseSourceEvent(source: MouseSource)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>source</code></td>
      <td><code>MouseSource</code></td>
      <td>да</td>
      <td>-----------------------MouseSource----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImGuiIO:AddMouseViewportEvent`

#### Сигнатура

```lua
ImGuiIO:AddMouseViewportEvent(id: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>id</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImGuiIO:AddMouseWheelEvent`

#### Сигнатура

```lua
ImGuiIO:AddMouseWheelEvent(wheel_x: number, wheel_y: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>wheel_x</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>wheel_y</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImGuiIO:ClearEventsQueue`

#### Сигнатура

```lua
ImGuiIO:ClearEventsQueue()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImGuiIO:ClearInputKeys`

#### Сигнатура

```lua
ImGuiIO:ClearInputKeys()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImGuiIO:SetAppAcceptingEvents`

#### Сигнатура

```lua
ImGuiIO:SetAppAcceptingEvents(accepting_events: boolean)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>accepting_events</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImGuiIO:SetKeyEventNativeData`

#### Сигнатура

```lua
ImGuiIO:SetKeyEventNativeData(key: Key, native_keycode: number, native_scancode: number, native_legacy_index?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>Key</code></td>
      <td>да</td>
      <td>-----------------------Key----------------------------</td>
    </tr>
    <tr>
      <td><code>native_keycode</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>native_scancode</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>native_legacy_index</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

---

## Класс `ImGuiInputEvent`

### ~~Функция `ImGuiInputEvent.__new`~~

#### Сигнатура

```lua
function ImGuiInputEvent.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

---

## Класс `ImGuiInputTextCallbackData`

### ~~Функция `ImGuiInputTextCallbackData.__new`~~

#### Сигнатура

```lua
function ImGuiInputTextCallbackData.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Метод `ImGuiInputTextCallbackData:ClearSelection`

#### Сигнатура

```lua
ImGuiInputTextCallbackData:ClearSelection()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImGuiInputTextCallbackData:DeleteChars`

#### Сигнатура

```lua
ImGuiInputTextCallbackData:DeleteChars(pos: number, bytes_count: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>pos</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>bytes_count</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImGuiInputTextCallbackData:HasSelection`

#### Сигнатура

```lua
ImGuiInputTextCallbackData:HasSelection()
  -> boolean
```

#### Возвращает

- `boolean` 

### Метод `ImGuiInputTextCallbackData:InsertChars`

#### Сигнатура

```lua
ImGuiInputTextCallbackData:InsertChars(pos: number, text: string, text_end?: string)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>pos</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>text</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>text_end</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImGuiInputTextCallbackData:SelectAll`

#### Сигнатура

```lua
ImGuiInputTextCallbackData:SelectAll()
  -> nil
```

#### Возвращает

- `nil` 

---

## Класс `ImGuiInputTextDeactivatedState`

### ~~Функция `ImGuiInputTextDeactivatedState.__new`~~

#### Сигнатура

```lua
function ImGuiInputTextDeactivatedState.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Метод `ImGuiInputTextDeactivatedState:ClearFreeMemory`

#### Сигнатура

```lua
ImGuiInputTextDeactivatedState:ClearFreeMemory()
  -> nil
```

#### Возвращает

- `nil` 

---

## Класс `ImGuiInputTextState`

### ~~Функция `ImGuiInputTextState.__new`~~

#### Сигнатура

```lua
function ImGuiInputTextState.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Метод `ImGuiInputTextState:ClearFreeMemory`

#### Сигнатура

```lua
ImGuiInputTextState:ClearFreeMemory()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImGuiInputTextState:ClearSelection`

#### Сигнатура

```lua
ImGuiInputTextState:ClearSelection()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImGuiInputTextState:ClearText`

#### Сигнатура

```lua
ImGuiInputTextState:ClearText()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImGuiInputTextState:CursorAnimReset`

#### Сигнатура

```lua
ImGuiInputTextState:CursorAnimReset()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImGuiInputTextState:CursorClamp`

#### Сигнатура

```lua
ImGuiInputTextState:CursorClamp()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImGuiInputTextState:GetCursorPos`

#### Сигнатура

```lua
ImGuiInputTextState:GetCursorPos()
  -> int: number
```

#### Возвращает

- `number` 

### Метод `ImGuiInputTextState:GetRedoAvailCount`

#### Сигнатура

```lua
ImGuiInputTextState:GetRedoAvailCount()
  -> int: number
```

#### Возвращает

- `number` 

### Метод `ImGuiInputTextState:GetSelectionEnd`

#### Сигнатура

```lua
ImGuiInputTextState:GetSelectionEnd()
  -> int: number
```

#### Возвращает

- `number` 

### Метод `ImGuiInputTextState:GetSelectionStart`

#### Сигнатура

```lua
ImGuiInputTextState:GetSelectionStart()
  -> int: number
```

#### Возвращает

- `number` 

### Метод `ImGuiInputTextState:GetUndoAvailCount`

#### Сигнатура

```lua
ImGuiInputTextState:GetUndoAvailCount()
  -> int: number
```

#### Возвращает

- `number` 

### Метод `ImGuiInputTextState:HasSelection`

#### Сигнатура

```lua
ImGuiInputTextState:HasSelection()
  -> boolean
```

#### Возвращает

- `boolean` 

### Метод `ImGuiInputTextState:OnKeyPressed`

#### Сигнатура

```lua
ImGuiInputTextState:OnKeyPressed(key: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImGuiInputTextState:ReloadUserBufAndKeepSelection`

#### Сигнатура

```lua
ImGuiInputTextState:ReloadUserBufAndKeepSelection()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImGuiInputTextState:ReloadUserBufAndMoveToEnd`

#### Сигнатура

```lua
ImGuiInputTextState:ReloadUserBufAndMoveToEnd()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImGuiInputTextState:ReloadUserBufAndSelectAll`

#### Сигнатура

```lua
ImGuiInputTextState:ReloadUserBufAndSelectAll()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImGuiInputTextState:SelectAll`

#### Сигнатура

```lua
ImGuiInputTextState:SelectAll()
  -> nil
```

#### Возвращает

- `nil` 

---

## Класс `ImGuiKeyOwnerData`

### ~~Функция `ImGuiKeyOwnerData.__new`~~

#### Сигнатура

```lua
function ImGuiKeyOwnerData.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

---

## Класс `ImGuiKeyRoutingData`

### ~~Функция `ImGuiKeyRoutingData.__new`~~

#### Сигнатура

```lua
function ImGuiKeyRoutingData.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

---

## Класс `ImGuiKeyRoutingTable`

### ~~Функция `ImGuiKeyRoutingTable.__new`~~

#### Сигнатура

```lua
function ImGuiKeyRoutingTable.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Метод `ImGuiKeyRoutingTable:Clear`

#### Сигнатура

```lua
ImGuiKeyRoutingTable:Clear()
  -> nil
```

#### Возвращает

- `nil` 

---

## Класс `ImGuiLastItemData`

### ~~Функция `ImGuiLastItemData.__new`~~

#### Сигнатура

```lua
function ImGuiLastItemData.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

---

## Класс `ImGuiListClipper`

### ~~Функция `ImGuiListClipper.__new`~~

#### Сигнатура

```lua
function ImGuiListClipper.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Метод `ImGuiListClipper:Begin`

#### Сигнатура

```lua
ImGuiListClipper:Begin(items_count: number, items_height?: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>items_count</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>items_height</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImGuiListClipper:End`

#### Сигнатура

```lua
ImGuiListClipper:End()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImGuiListClipper:IncludeItemByIndex`

#### Сигнатура

```lua
ImGuiListClipper:IncludeItemByIndex(item_index: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>item_index</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImGuiListClipper:IncludeItemsByIndex`

#### Сигнатура

```lua
ImGuiListClipper:IncludeItemsByIndex(item_begin: number, item_end: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>item_begin</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>item_end</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImGuiListClipper:Step`

#### Сигнатура

```lua
ImGuiListClipper:Step()
  -> boolean
```

#### Возвращает

- `boolean` 

---

## Класс `ImGuiListClipperData`

### ~~Функция `ImGuiListClipperData.__new`~~

#### Сигнатура

```lua
function ImGuiListClipperData.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Метод `ImGuiListClipperData:Reset`

#### Сигнатура

```lua
ImGuiListClipperData:Reset(clipper: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>clipper</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiListClipper*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

---

## Класс `ImGuiListClipperRange`

---

## Класс `ImGuiMenuColumns`

### ~~Функция `ImGuiMenuColumns.__new`~~

#### Сигнатура

```lua
function ImGuiMenuColumns.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Метод `ImGuiMenuColumns:CalcNextTotalWidth`

#### Сигнатура

```lua
ImGuiMenuColumns:CalcNextTotalWidth(update_offsets: boolean)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>update_offsets</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImGuiMenuColumns:DeclColumns`

#### Сигнатура

```lua
ImGuiMenuColumns:DeclColumns(w_icon: number, w_label: number, w_shortcut: number, w_mark: number)
  -> float: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>w_icon</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>w_label</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>w_shortcut</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>w_mark</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Метод `ImGuiMenuColumns:Update`

#### Сигнатура

```lua
ImGuiMenuColumns:Update(spacing: number, window_reappearing: boolean)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>spacing</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
    <tr>
      <td><code>window_reappearing</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

---

## Класс `ImGuiNavItemData`

### ~~Функция `ImGuiNavItemData.__new`~~

#### Сигнатура

```lua
function ImGuiNavItemData.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Метод `ImGuiNavItemData:Clear`

#### Сигнатура

```lua
ImGuiNavItemData:Clear()
  -> nil
```

#### Возвращает

- `nil` 

---

## Класс `ImGuiNextItemData`

### ~~Функция `ImGuiNextItemData.__new`~~

#### Сигнатура

```lua
function ImGuiNextItemData.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Метод `ImGuiNextItemData:ClearFlags`

#### Сигнатура

```lua
ImGuiNextItemData:ClearFlags()
  -> nil
```

#### Возвращает

- `nil` 

---

## Класс `ImGuiNextWindowData`

### ~~Функция `ImGuiNextWindowData.__new`~~

#### Сигнатура

```lua
function ImGuiNextWindowData.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Метод `ImGuiNextWindowData:ClearFlags`

#### Сигнатура

```lua
ImGuiNextWindowData:ClearFlags()
  -> nil
```

#### Возвращает

- `nil` 

---

## Класс `ImGuiOldColumnData`

### ~~Функция `ImGuiOldColumnData.__new`~~

#### Сигнатура

```lua
function ImGuiOldColumnData.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

---

## Класс `ImGuiOldColumns`

### ~~Функция `ImGuiOldColumns.__new`~~

#### Сигнатура

```lua
function ImGuiOldColumns.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

---

## Класс `ImGuiOnceUponAFrame`

### ~~Функция `ImGuiOnceUponAFrame.__new`~~

#### Сигнатура

```lua
function ImGuiOnceUponAFrame.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

---

## Класс `ImGuiPayload`

### ~~Функция `ImGuiPayload.__new`~~

#### Сигнатура

```lua
function ImGuiPayload.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Метод `ImGuiPayload:Clear`

#### Сигнатура

```lua
ImGuiPayload:Clear()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImGuiPayload:IsDataType`

#### Сигнатура

```lua
ImGuiPayload:IsDataType(type: string)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>type</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Метод `ImGuiPayload:IsDelivery`

#### Сигнатура

```lua
ImGuiPayload:IsDelivery()
  -> boolean
```

#### Возвращает

- `boolean` 

### Метод `ImGuiPayload:IsPreview`

#### Сигнатура

```lua
ImGuiPayload:IsPreview()
  -> boolean
```

#### Возвращает

- `boolean` 

---

## Класс `ImGuiPlatformIO`

### ~~Функция `ImGuiPlatformIO.__new`~~

#### Сигнатура

```lua
function ImGuiPlatformIO.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

---

## Класс `ImGuiPlatformImeData`

### ~~Функция `ImGuiPlatformImeData.__new`~~

#### Сигнатура

```lua
function ImGuiPlatformImeData.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

---

## Класс `ImGuiPlatformMonitor`

### ~~Функция `ImGuiPlatformMonitor.__new`~~

#### Сигнатура

```lua
function ImGuiPlatformMonitor.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

---

## Класс `ImGuiPopupData`

### ~~Функция `ImGuiPopupData.__new`~~

#### Сигнатура

```lua
function ImGuiPopupData.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

---

## Класс `ImGuiPtrOrIndex`

### ~~Функция `ImGuiPtrOrIndex.ImGuiPtrOrIndex_Int`~~

#### Сигнатура

```lua
function ImGuiPtrOrIndex.ImGuiPtrOrIndex_Int(index: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>index</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### ~~Функция `ImGuiPtrOrIndex.ImGuiPtrOrIndex_Ptr`~~

#### Сигнатура

```lua
function ImGuiPtrOrIndex.ImGuiPtrOrIndex_Ptr(ptr: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ptr</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### ~~Функция `ImGuiPtrOrIndex.__new`~~

 generic version

#### Сигнатура

```lua
function ImGuiPtrOrIndex.__new(ctype: any, a1: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

---

## Класс `ImGuiSettingsHandler`

### ~~Функция `ImGuiSettingsHandler.__new`~~

#### Сигнатура

```lua
function ImGuiSettingsHandler.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

---

## Класс `ImGuiStackLevelInfo`

### ~~Функция `ImGuiStackLevelInfo.__new`~~

#### Сигнатура

```lua
function ImGuiStackLevelInfo.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

---

## Класс `ImGuiStackSizes`

### ~~Функция `ImGuiStackSizes.__new`~~

#### Сигнатура

```lua
function ImGuiStackSizes.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Метод `ImGuiStackSizes:CompareWithContextState`

#### Сигнатура

```lua
ImGuiStackSizes:CompareWithContextState(ctx: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctx</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiContext*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImGuiStackSizes:SetToContextState`

#### Сигнатура

```lua
ImGuiStackSizes:SetToContextState(ctx: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctx</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImGuiContext*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

---

## Класс `ImGuiStorage`

### Метод `ImGuiStorage:BuildSortByKey`

#### Сигнатура

```lua
ImGuiStorage:BuildSortByKey()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImGuiStorage:Clear`

#### Сигнатура

```lua
ImGuiStorage:Clear()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImGuiStorage:GetBool`

#### Сигнатура

```lua
ImGuiStorage:GetBool(key: number, default_val?: boolean)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>default_val</code></td>
      <td><code>boolean</code></td>
      <td>нет</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Метод `ImGuiStorage:GetBoolRef`

#### Сигнатура

```lua
ImGuiStorage:GetBoolRef(key: number, default_val?: boolean)
  -> bool*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>default_val</code></td>
      <td><code>boolean</code></td>
      <td>нет</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Метод `ImGuiStorage:GetFloat`

#### Сигнатура

```lua
ImGuiStorage:GetFloat(key: number, default_val?: number)
  -> float: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>default_val</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Метод `ImGuiStorage:GetFloatRef`

#### Сигнатура

```lua
ImGuiStorage:GetFloatRef(key: number, default_val?: number)
  -> float*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>default_val</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Метод `ImGuiStorage:GetInt`

#### Сигнатура

```lua
ImGuiStorage:GetInt(key: number, default_val?: number)
  -> int: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>default_val</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Метод `ImGuiStorage:GetIntRef`

#### Сигнатура

```lua
ImGuiStorage:GetIntRef(key: number, default_val?: number)
  -> int*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>default_val</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Метод `ImGuiStorage:GetVoidPtr`

#### Сигнатура

```lua
ImGuiStorage:GetVoidPtr(key: number)
  -> void*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Метод `ImGuiStorage:GetVoidPtrRef`

#### Сигнатура

```lua
ImGuiStorage:GetVoidPtrRef(key: number, default_val?: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> void**: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>default_val</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>нет</td>
      <td>void*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Метод `ImGuiStorage:SetAllInt`

#### Сигнатура

```lua
ImGuiStorage:SetAllInt(val: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>val</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImGuiStorage:SetBool`

#### Сигнатура

```lua
ImGuiStorage:SetBool(key: number, val: boolean)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>val</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImGuiStorage:SetFloat`

#### Сигнатура

```lua
ImGuiStorage:SetFloat(key: number, val: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>val</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImGuiStorage:SetInt`

#### Сигнатура

```lua
ImGuiStorage:SetInt(key: number, val: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>val</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImGuiStorage:SetVoidPtr`

#### Сигнатура

```lua
ImGuiStorage:SetVoidPtr(key: number, val: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>ImGuiID</td>
    </tr>
    <tr>
      <td><code>val</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>void*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

---

## Класс `ImGuiStoragePair`

### ~~Функция `ImGuiStoragePair.ImGuiStoragePair_Float`~~

#### Сигнатура

```lua
function ImGuiStoragePair.ImGuiStoragePair_Float(_key: any, _val: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>_key</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>_val</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### ~~Функция `ImGuiStoragePair.ImGuiStoragePair_Int`~~

#### Сигнатура

```lua
function ImGuiStoragePair.ImGuiStoragePair_Int(_key: any, _val: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>_key</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>_val</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### ~~Функция `ImGuiStoragePair.ImGuiStoragePair_Ptr`~~

#### Сигнатура

```lua
function ImGuiStoragePair.ImGuiStoragePair_Ptr(_key: any, _val: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>_key</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>_val</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### ~~Функция `ImGuiStoragePair.__new`~~

 generic version

#### Сигнатура

```lua
function ImGuiStoragePair.__new(ctype: any, a1: any, a2: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

---

## Класс `ImGuiStyle`

### ~~Функция `ImGuiStyle.__new`~~

#### Сигнатура

```lua
function ImGuiStyle.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Метод `ImGuiStyle:ScaleAllSizes`

#### Сигнатура

```lua
ImGuiStyle:ScaleAllSizes(scale_factor: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>scale_factor</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

---

## Класс `ImGuiStyleMod`

### ~~Функция `ImGuiStyleMod.ImGuiStyleMod_Float`~~

#### Сигнатура

```lua
function ImGuiStyleMod.ImGuiStyleMod_Float(idx: any, v: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>idx</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### ~~Функция `ImGuiStyleMod.ImGuiStyleMod_Int`~~

#### Сигнатура

```lua
function ImGuiStyleMod.ImGuiStyleMod_Int(idx: any, v: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>idx</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### ~~Функция `ImGuiStyleMod.ImGuiStyleMod_Vec2`~~

#### Сигнатура

```lua
function ImGuiStyleMod.ImGuiStyleMod_Vec2(idx: any, v: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>idx</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>v</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### ~~Функция `ImGuiStyleMod.__new`~~

 generic version

#### Сигнатура

```lua
function ImGuiStyleMod.__new(ctype: any, a1: any, a2: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

---

## Класс `ImGuiTabBar`

### ~~Функция `ImGuiTabBar.__new`~~

#### Сигнатура

```lua
function ImGuiTabBar.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

---

## Класс `ImGuiTabItem`

### ~~Функция `ImGuiTabItem.__new`~~

#### Сигнатура

```lua
function ImGuiTabItem.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

---

## Класс `ImGuiTable`

### ~~Функция `ImGuiTable.__new`~~

#### Сигнатура

```lua
function ImGuiTable.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

---

## Класс `ImGuiTableColumn`

### ~~Функция `ImGuiTableColumn.__new`~~

#### Сигнатура

```lua
function ImGuiTableColumn.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

---

## Класс `ImGuiTableColumnSettings`

### ~~Функция `ImGuiTableColumnSettings.__new`~~

#### Сигнатура

```lua
function ImGuiTableColumnSettings.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

---

## Класс `ImGuiTableColumnSortSpecs`

### ~~Функция `ImGuiTableColumnSortSpecs.__new`~~

#### Сигнатура

```lua
function ImGuiTableColumnSortSpecs.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

---

## Класс `ImGuiTableInstanceData`

### ~~Функция `ImGuiTableInstanceData.__new`~~

#### Сигнатура

```lua
function ImGuiTableInstanceData.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

---

## Класс `ImGuiTableSettings`

### ~~Функция `ImGuiTableSettings.__new`~~

#### Сигнатура

```lua
function ImGuiTableSettings.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Метод `ImGuiTableSettings:GetColumnSettings`

#### Сигнатура

```lua
ImGuiTableSettings:GetColumnSettings()
  -> ImGuiTableColumnSettings*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

---

## Класс `ImGuiTableSortSpecs`

### ~~Функция `ImGuiTableSortSpecs.__new`~~

#### Сигнатура

```lua
function ImGuiTableSortSpecs.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

---

## Класс `ImGuiTableTempData`

### ~~Функция `ImGuiTableTempData.__new`~~

#### Сигнатура

```lua
function ImGuiTableTempData.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

---

## Класс `ImGuiTextBuffer`

### ~~Функция `ImGuiTextBuffer.__new`~~

#### Сигнатура

```lua
function ImGuiTextBuffer.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Метод `ImGuiTextBuffer:_end`

#### Сигнатура

```lua
ImGuiTextBuffer:_end()
  -> string
```

#### Возвращает

- `string` 

### Метод `ImGuiTextBuffer:append`

#### Сигнатура

```lua
ImGuiTextBuffer:append(str: string, str_end?: string)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>str</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>str_end</code></td>
      <td><code>string</code></td>
      <td>нет</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImGuiTextBuffer:appendf`

#### Сигнатура

```lua
ImGuiTextBuffer:appendf(fmt: string, ...any)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>fmt</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>...</code></td>
      <td><code>unknown</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImGuiTextBuffer:appendfv`

#### Сигнатура

```lua
ImGuiTextBuffer:appendfv(fmt: string, args: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>fmt</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>args</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>va_list</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImGuiTextBuffer:begin`

#### Сигнатура

```lua
ImGuiTextBuffer:begin()
  -> string
```

#### Возвращает

- `string` 

### Метод `ImGuiTextBuffer:c_str`

#### Сигнатура

```lua
ImGuiTextBuffer:c_str()
  -> string
```

#### Возвращает

- `string` 

### Метод `ImGuiTextBuffer:clear`

#### Сигнатура

```lua
ImGuiTextBuffer:clear()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImGuiTextBuffer:empty`

#### Сигнатура

```lua
ImGuiTextBuffer:empty()
  -> boolean
```

#### Возвращает

- `boolean` 

### Метод `ImGuiTextBuffer:reserve`

#### Сигнатура

```lua
ImGuiTextBuffer:reserve(capacity: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>capacity</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImGuiTextBuffer:size`

#### Сигнатура

```lua
ImGuiTextBuffer:size()
  -> int: number
```

#### Возвращает

- `number` 

---

## Класс `ImGuiTextFilter`

### ~~Функция `ImGuiTextFilter.__new`~~

#### Сигнатура

```lua
function ImGuiTextFilter.__new(ctype: any, default_filter: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>default_filter</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Метод `ImGuiTextFilter:Build`

#### Сигнатура

```lua
ImGuiTextFilter:Build()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImGuiTextFilter:Clear`

#### Сигнатура

```lua
ImGuiTextFilter:Clear()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImGuiTextFilter:Draw`

#### Сигнатура

```lua
ImGuiTextFilter:Draw(label?: string, width?: number)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>label</code></td>
      <td><code>string</code></td>
      <td>нет</td>
      <td></td>
    </tr>
    <tr>
      <td><code>width</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Метод `ImGuiTextFilter:IsActive`

#### Сигнатура

```lua
ImGuiTextFilter:IsActive()
  -> boolean
```

#### Возвращает

- `boolean` 

### Метод `ImGuiTextFilter:PassFilter`

#### Сигнатура

```lua
ImGuiTextFilter:PassFilter(text: string, text_end?: string)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>text</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>text_end</code></td>
      <td><code>string</code></td>
      <td>нет</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

---

## Класс `ImGuiTextIndex`

### Метод `ImGuiTextIndex:append`

#### Сигнатура

```lua
ImGuiTextIndex:append(base: string, old_size: number, new_size: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>base</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>old_size</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
    <tr>
      <td><code>new_size</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImGuiTextIndex:clear`

#### Сигнатура

```lua
ImGuiTextIndex:clear()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImGuiTextIndex:get_line_begin`

#### Сигнатура

```lua
ImGuiTextIndex:get_line_begin(base: string, n: number)
  -> string
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>base</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>n</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `string` 

### Метод `ImGuiTextIndex:get_line_end`

#### Сигнатура

```lua
ImGuiTextIndex:get_line_end(base: string, n: number)
  -> string
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>base</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>n</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `string` 

### Метод `ImGuiTextIndex:size`

#### Сигнатура

```lua
ImGuiTextIndex:size()
  -> int: number
```

#### Возвращает

- `number` 

---

## Класс `ImGuiTextRange`

### ~~Функция `ImGuiTextRange.ImGuiTextRange_Nil`~~

#### Сигнатура

```lua
function ImGuiTextRange.ImGuiTextRange_Nil()
  -> ffi.cdata*
```

#### Возвращает

- `ffi.cdata*` 

### ~~Функция `ImGuiTextRange.ImGuiTextRange_Str`~~

#### Сигнатура

```lua
function ImGuiTextRange.ImGuiTextRange_Str(_b: any, _e: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>_b</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>_e</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### ~~Функция `ImGuiTextRange.__new`~~

 generic version

#### Сигнатура

```lua
function ImGuiTextRange.__new(ctype: any, a1: any, a2: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Метод `ImGuiTextRange:empty`

#### Сигнатура

```lua
ImGuiTextRange:empty()
  -> boolean
```

#### Возвращает

- `boolean` 

### Метод `ImGuiTextRange:split`

#### Сигнатура

```lua
ImGuiTextRange:split(separator: number, out: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>separator</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>char</td>
    </tr>
    <tr>
      <td><code>out</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>ImVector_ImGuiTextRange*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

---

## Класс `ImGuiTypingSelectState`

### ~~Функция `ImGuiTypingSelectState.__new`~~

#### Сигнатура

```lua
function ImGuiTypingSelectState.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Метод `ImGuiTypingSelectState:Clear`

#### Сигнатура

```lua
ImGuiTypingSelectState:Clear()
  -> nil
```

#### Возвращает

- `nil` 

---

## Класс `ImGuiViewport`

### ~~Функция `ImGuiViewport.__new`~~

#### Сигнатура

```lua
function ImGuiViewport.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Метод `ImGuiViewport:GetCenter`

#### Сигнатура

```lua
ImGuiViewport:GetCenter()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImGuiViewport:GetWorkCenter`

#### Сигнатура

```lua
ImGuiViewport:GetWorkCenter()
  -> nil
```

#### Возвращает

- `nil` 

---

## Класс `ImGuiViewportP`

### ~~Функция `ImGuiViewportP.__new`~~

#### Сигнатура

```lua
function ImGuiViewportP.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Метод `ImGuiViewportP:CalcWorkRectPos`

#### Сигнатура

```lua
ImGuiViewportP:CalcWorkRectPos(off_min: ImVec2)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>off_min</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImGuiViewportP:CalcWorkRectSize`

#### Сигнатура

```lua
ImGuiViewportP:CalcWorkRectSize(off_min: ImVec2, off_max: ImVec2)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>off_min</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>off_max</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImGuiViewportP:ClearRequestFlags`

#### Сигнатура

```lua
ImGuiViewportP:ClearRequestFlags()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImGuiViewportP:GetBuildWorkRect`

#### Сигнатура

```lua
ImGuiViewportP:GetBuildWorkRect()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImGuiViewportP:GetMainRect`

#### Сигнатура

```lua
ImGuiViewportP:GetMainRect()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImGuiViewportP:GetWorkRect`

#### Сигнатура

```lua
ImGuiViewportP:GetWorkRect()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImGuiViewportP:UpdateWorkRect`

#### Сигнатура

```lua
ImGuiViewportP:UpdateWorkRect()
  -> nil
```

#### Возвращает

- `nil` 

---

## Класс `ImGuiWindow`

### ~~Функция `ImGuiWindow.__new`~~

#### Сигнатура

```lua
function ImGuiWindow.__new(ctype: any, context: any, name: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>context</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>name</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Метод `ImGuiWindow:CalcFontSize`

#### Сигнатура

```lua
ImGuiWindow:CalcFontSize()
  -> float: number
```

#### Возвращает

- `number` 

### ~~Метод `ImGuiWindow:GetID`~~

 generic version

#### Сигнатура

```lua
ImGuiWindow:GetID(a2: any, a3: any)
  -> number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a3</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Метод `ImGuiWindow:GetIDFromRectangle`

#### Сигнатура

```lua
ImGuiWindow:GetIDFromRectangle(r_abs: ImRect)
  -> ImGuiID: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>r_abs</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Метод `ImGuiWindow:GetID_Int`

#### Сигнатура

```lua
ImGuiWindow:GetID_Int(n: number)
  -> ImGuiID: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>n</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>int</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Метод `ImGuiWindow:GetID_Ptr`

#### Сигнатура

```lua
ImGuiWindow:GetID_Ptr(ptr: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> ImGuiID: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ptr</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>const void*</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Метод `ImGuiWindow:GetID_Str`

#### Сигнатура

```lua
ImGuiWindow:GetID_Str(str: string, str_end?: string)
  -> ImGuiID: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>str</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>str_end</code></td>
      <td><code>string</code></td>
      <td>нет</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Метод `ImGuiWindow:MenuBarHeight`

#### Сигнатура

```lua
ImGuiWindow:MenuBarHeight()
  -> float: number
```

#### Возвращает

- `number` 

### Метод `ImGuiWindow:MenuBarRect`

#### Сигнатура

```lua
ImGuiWindow:MenuBarRect()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImGuiWindow:Rect`

#### Сигнатура

```lua
ImGuiWindow:Rect()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImGuiWindow:TitleBarHeight`

#### Сигнатура

```lua
ImGuiWindow:TitleBarHeight()
  -> float: number
```

#### Возвращает

- `number` 

### Метод `ImGuiWindow:TitleBarRect`

#### Сигнатура

```lua
ImGuiWindow:TitleBarRect()
  -> nil
```

#### Возвращает

- `nil` 

---

## Класс `ImGuiWindowClass`

### ~~Функция `ImGuiWindowClass.__new`~~

#### Сигнатура

```lua
function ImGuiWindowClass.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

---

## Класс `ImGuiWindowSettings`

### ~~Функция `ImGuiWindowSettings.__new`~~

#### Сигнатура

```lua
function ImGuiWindowSettings.__new(ctype: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Метод `ImGuiWindowSettings:GetName`

#### Сигнатура

```lua
ImGuiWindowSettings:GetName()
  -> char*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

---

## Класс `ImRect`

### ~~Функция `ImRect.ImRect_Float`~~

#### Сигнатура

```lua
function ImRect.ImRect_Float(x1: any, y1: any, x2: any, y2: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>x1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>y1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>x2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>y2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### ~~Функция `ImRect.ImRect_Nil`~~

#### Сигнатура

```lua
function ImRect.ImRect_Nil()
  -> ffi.cdata*
```

#### Возвращает

- `ffi.cdata*` 

### ~~Функция `ImRect.ImRect_Vec2`~~

#### Сигнатура

```lua
function ImRect.ImRect_Vec2(min: any, max: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>min</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>max</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### ~~Функция `ImRect.ImRect_Vec4`~~

#### Сигнатура

```lua
function ImRect.ImRect_Vec4(v: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>v</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### ~~Функция `ImRect.__new`~~

 generic version

#### Сигнатура

```lua
function ImRect.__new(ctype: any, a1: any, a2: any, a3: any, a4: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a3</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a4</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### ~~Метод `ImRect:Add`~~

 generic version

#### Сигнатура

```lua
ImRect:Add(a2: any)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImRect:Add_Rect`

#### Сигнатура

```lua
ImRect:Add_Rect(r: ImRect)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>r</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImRect:Add_Vec2`

#### Сигнатура

```lua
ImRect:Add_Vec2(p: ImVec2)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>p</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImRect:ClipWith`

#### Сигнатура

```lua
ImRect:ClipWith(r: ImRect)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>r</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImRect:ClipWithFull`

#### Сигнатура

```lua
ImRect:ClipWithFull(r: ImRect)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>r</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### ~~Метод `ImRect:Contains`~~

 generic version

#### Сигнатура

```lua
ImRect:Contains(a2: any)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Метод `ImRect:ContainsWithPad`

#### Сигнатура

```lua
ImRect:ContainsWithPad(p: ImVec2, pad: ImVec2)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>p</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
    <tr>
      <td><code>pad</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Метод `ImRect:Contains_Rect`

#### Сигнатура

```lua
ImRect:Contains_Rect(r: ImRect)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>r</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Метод `ImRect:Contains_Vec2`

#### Сигнатура

```lua
ImRect:Contains_Vec2(p: ImVec2)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>p</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### ~~Метод `ImRect:Expand`~~

 generic version

#### Сигнатура

```lua
ImRect:Expand(a2: any)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImRect:Expand_Float`

#### Сигнатура

```lua
ImRect:Expand_Float(amount: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>amount</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>const float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImRect:Expand_Vec2`

#### Сигнатура

```lua
ImRect:Expand_Vec2(amount: ImVec2)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>amount</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImRect:Floor`

#### Сигнатура

```lua
ImRect:Floor()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImRect:GetArea`

#### Сигнатура

```lua
ImRect:GetArea()
  -> float: number
```

#### Возвращает

- `number` 

### Метод `ImRect:GetBL`

#### Сигнатура

```lua
ImRect:GetBL()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImRect:GetBR`

#### Сигнатура

```lua
ImRect:GetBR()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImRect:GetCenter`

#### Сигнатура

```lua
ImRect:GetCenter()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImRect:GetHeight`

#### Сигнатура

```lua
ImRect:GetHeight()
  -> float: number
```

#### Возвращает

- `number` 

### Метод `ImRect:GetSize`

#### Сигнатура

```lua
ImRect:GetSize()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImRect:GetTL`

#### Сигнатура

```lua
ImRect:GetTL()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImRect:GetTR`

#### Сигнатура

```lua
ImRect:GetTR()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImRect:GetWidth`

#### Сигнатура

```lua
ImRect:GetWidth()
  -> float: number
```

#### Возвращает

- `number` 

### Метод `ImRect:IsInverted`

#### Сигнатура

```lua
ImRect:IsInverted()
  -> boolean
```

#### Возвращает

- `boolean` 

### Метод `ImRect:Overlaps`

#### Сигнатура

```lua
ImRect:Overlaps(r: ImRect)
  -> boolean
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>r</code></td>
      <td><code>ImRect</code></td>
      <td>да</td>
      <td>-----------------------ImRect----------------------------</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Метод `ImRect:ToVec4`

#### Сигнатура

```lua
ImRect:ToVec4()
  -> nil
```

#### Возвращает

- `nil` 

### Метод `ImRect:Translate`

#### Сигнатура

```lua
ImRect:Translate(d: ImVec2)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>d</code></td>
      <td><code>ImVec2</code></td>
      <td>да</td>
      <td>--------ImVec2 definition</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImRect:TranslateX`

#### Сигнатура

```lua
ImRect:TranslateX(dx: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>dx</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

### Метод `ImRect:TranslateY`

#### Сигнатура

```lua
ImRect:TranslateY(dy: number)
  -> nil
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>dy</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>float</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `nil` 

---

## Класс `ImVec1`

### ~~Функция `ImVec1.ImVec1_Float`~~

#### Сигнатура

```lua
function ImVec1.ImVec1_Float(_x: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>_x</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### ~~Функция `ImVec1.ImVec1_Nil`~~

#### Сигнатура

```lua
function ImVec1.ImVec1_Nil()
  -> ffi.cdata*
```

#### Возвращает

- `ffi.cdata*` 

### ~~Функция `ImVec1.__new`~~

 generic version

#### Сигнатура

```lua
function ImVec1.__new(ctype: any, a1: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

---

## Класс `ImVec2`

*Наследуется от `ffi.ctype*`*

---

## Класс `ImVec2ih`

### ~~Функция `ImVec2ih.ImVec2ih_Nil`~~

#### Сигнатура

```lua
function ImVec2ih.ImVec2ih_Nil()
  -> ffi.cdata*
```

#### Возвращает

- `ffi.cdata*` 

### ~~Функция `ImVec2ih.ImVec2ih_Vec2`~~

#### Сигнатура

```lua
function ImVec2ih.ImVec2ih_Vec2(rhs: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>rhs</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### ~~Функция `ImVec2ih.ImVec2ih_short`~~

#### Сигнатура

```lua
function ImVec2ih.ImVec2ih_short(_x: any, _y: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>_x</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>_y</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### ~~Функция `ImVec2ih.__new`~~

 generic version

#### Сигнатура

```lua
function ImVec2ih.__new(ctype: any, a1: any, a2: any)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>ctype</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a1</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a2</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

