# Модуль DirectX

Этот модуль позволяет обращаться к методам DirectX 8 и DirectX 9

## Импорт модуля

Для импорта модуля используйте следующий код:

```lua
local directx = require("directx")
```

## Элементы модуля

### Функция `directx.getD3D8`

 Возвращает указатель на IDirect3DDevice8

#### Сигнатура

```lua
function directx.getD3D8()
  -> IDirect3DDevice8*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Функция `directx.getD3D9`

 Возвращает указатель на IDirect3DDevice9

#### Сигнатура

```lua
function directx.getD3D9()
  -> IDirect3DDevice9*: ffi.cdata*|ffi.cdecl*|ffi.ctype*
```

#### Возвращает

- `ffi.cdata*` или `ffi.cdecl*` или `ffi.ctype*` 

### Поле `directx.d3dx9`

 Обьект, предоставляющий доступ к некоторым API D3DX9, полезным для загрузки и создания различных DirectX обьектов

**Тип**: `table`

