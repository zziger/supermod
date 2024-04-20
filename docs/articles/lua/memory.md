# Модуль Memory

Этот модуль предоставляет доступ к памяти игры, позволяет читать и писать данные в память, а также создавать хуки на функции.

## Импорт модуля

Для импорта модуля используйте следующий код:

```lua
local memory = require("memory")
```

## Элементы модуля

### Функция `memory.at`

Создает новый обьект Memory

#### Сигнатура

```lua
function memory.at(location: string|number, params?: MemoryParams)
  -> mem: Memory
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>location</code></td>
      <td><code>string</code> или <code>number</code></td>
      <td>да</td>
      <td>Паттерн или адрес в памяти</td>
    </tr>
    <tr>
      <td><code>params</code></td>
      <td><code>MemoryParams</code></td>
      <td>нет</td>
      <td>Параметры</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `Memory`  - - Обьект Memory

### Функция `memory.restoreBackups`

Восстанавливает оригинальные байты из бекапа

#### Сигнатура

```lua
function memory.restoreBackups(backup: table)
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
      <td><code>backup</code></td>
      <td><code>table</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

### Функция `memory.withBackup`

Возвращает текущий модуль, но привязанный к выбранному хранилищу бекапов

#### Сигнатура

```lua
function memory.withBackup(backup: any)
  -> memory
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
      <td><code>backup</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `memory` 

---

## Класс `Memory`

### Функция `Memory.toStr`

Конвертирует строку (char*) в луа формат

#### Сигнатура

```lua
function Memory.toStr(cstr: ffi.cdata*)
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
      <td><code>cstr</code></td>
      <td><code>ffi.cdata*</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `string` 

### Функция `Memory.toU16`

Конвертирует UTF8 строку (char*) в UTF16 строку (wchar_t*)

#### Сигнатура

```lua
function Memory.toU16(str: string|ffi.cdata*)
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
      <td><code>str</code></td>
      <td><code>string</code> или <code>ffi.cdata*</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Функция `Memory.toU16Array`

Конвертирует UTF8 строку (char*) в массив UTF-16 байтов (полезно для ffi.new с wchar_t)

#### Сигнатура

```lua
function Memory.toU16Array(str: string|ffi.cdata*)
  -> number[]
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
      <td><code>string</code> или <code>ffi.cdata*</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number[]` 

### Функция `Memory.toU8`

Конвертирует UTF16 строку (wchar_t*) в UTF8 строку (char*)

#### Сигнатура

```lua
function Memory.toU8(wstr: ffi.cdata*)
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
      <td><code>wstr</code></td>
      <td><code>ffi.cdata*</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Метод `Memory:add`

Возвращает новый обьект Memory добавляя указанный оффсет к адресу

#### Сигнатура

```lua
Memory:add(offset: number)
  -> Memory
```

#### Аргументы

<table>
  <thead>
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
      <td>да</td>
      <td>Оффсет от прошлого адреса (в байтах)</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `Memory` 

### Метод `Memory:call`

Вызывает функцию по текущему адресу

#### Сигнатура

```lua
Memory:call(functionType: ffi.cdata*|ffi.cdecl*|ffi.ctype*, ...any)
  -> Результат: any
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>functionType</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>Тип функции в виде C-декларации</td>
    </tr>
    <tr>
      <td><code>...</code></td>
      <td><code>any</code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `any` 

### Метод `Memory:getAs`

Возвращает поинтер в виде указанного типа

#### Сигнатура

```lua
Memory:getAs(type: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> ffi.cdata*
```

#### Аргументы

<table>
  <thead>
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
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>Тип данных в виде C-декларации</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `ffi.cdata*` 

### Метод `Memory:getFunction`

Возвращает функцию по текущему адресу

#### Сигнатура

```lua
Memory:getFunction(functionType: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> function
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>functionType</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>Тип функции в виде C-декларации</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `function` 

### Метод `Memory:hook`

Регистрирует хук-функцию на текущий адрес

#### Сигнатура

```lua
Memory:hook(fnType: ffi.cdata*|ffi.cdecl*|ffi.ctype*, fn: function, params?: HookParams)
  -> table
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>fnType</code></td>
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>С-тип хукаемой функции</td>
    </tr>
    <tr>
      <td><code>fn</code></td>
      <td><code>function</code></td>
      <td>да</td>
      <td>Функция хука</td>
    </tr>
    <tr>
      <td><code>params</code></td>
      <td><code>HookParams</code></td>
      <td>нет</td>
      <td>Параметры хука</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `table` 

### Метод `Memory:readAs`

Читает данные по адресу используя указанный тип

#### Сигнатура

```lua
Memory:readAs(type: ffi.cdata*|ffi.cdecl*|ffi.ctype*)
  -> unknown
```

#### Аргументы

<table>
  <thead>
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
      <td><code>ffi.cdata*</code> или <code>ffi.cdecl*</code> или <code>ffi.ctype*</code></td>
      <td>да</td>
      <td>Тип данных в виде C-декларации</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `unknown` 

### Метод `Memory:readBool`

Читает bool по текущему адресу (4 байта)

#### Сигнатура

```lua
Memory:readBool()
  -> boolean
```

#### Возвращает

- `boolean` 

### Метод `Memory:readDouble`

Читает double по текущему адресу (8 байт)

#### Сигнатура

```lua
Memory:readDouble()
  -> number
```

#### Возвращает

- `number` 

### Метод `Memory:readFloat`

Читает float по текущему адресу (4 байта)

#### Сигнатура

```lua
Memory:readFloat()
  -> number
```

#### Возвращает

- `number` 

#### Алиасы

- `Memory:readSingle`

### Метод `Memory:readInt16`

Читает int16 по текущему адресу (2 байта)

#### Сигнатура

```lua
Memory:readInt16()
  -> number
```

#### Возвращает

- `number` 

#### Алиасы

- `Memory:readShort`

- `Memory:readWord`

### Метод `Memory:readInt32`

Читает int32 по текущему адресу (4 байта)

#### Сигнатура

```lua
Memory:readInt32()
  -> number
```

#### Возвращает

- `number` 

#### Алиасы

- `Memory:readDword`

- `Memory:readInt`

### Метод `Memory:readInt64`

Читает int64 по текущему адресу (8 байт)

#### Сигнатура

```lua
Memory:readInt64()
  -> number
```

#### Возвращает

- `number` 

#### Алиасы

- `Memory:readLong`

### Метод `Memory:readInt8`

Читает int8 по текущему адресу (1 байт)

#### Сигнатура

```lua
Memory:readInt8()
  -> number
```

#### Возвращает

- `number` 

#### Алиасы

- `Memory:readByte`

- `Memory:readChar`

### Метод `Memory:readNearCall`

Читает инструкцию вызова по относительному адресу (opcode E8), и возвращает обьект Memory с адресом вызываемой функции

#### Сигнатура

```lua
Memory:readNearCall()
  -> Memory
```

#### Возвращает

- `Memory` 

### Метод `Memory:readOffset`

Читает адрес (int32) по текущему адресу, и возвращает обьект Memory с новым адресом

#### Сигнатура

```lua
Memory:readOffset()
  -> Memory
```

#### Возвращает

- `Memory` 

### Метод `Memory:readSBool`

Читает короткий bool по текущему адресу (1 байт)

#### Сигнатура

```lua
Memory:readSBool()
  -> boolean
```

#### Возвращает

- `boolean` 

### Метод `Memory:readString`

Читает строку по текущему адресу

#### Сигнатура

```lua
Memory:readString(length?: number)
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
      <td><code>length</code></td>
      <td><code>number</code></td>
      <td>нет</td>
      <td>Длина строки, если не указана - читает до NULL байта</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `string` 

### Метод `Memory:writeDouble`

Записывает double по текущему адресу (4 байта)

#### Сигнатура

```lua
Memory:writeDouble(value: number)
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
      <td><code>value</code></td>
      <td><code>number</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

### Метод `Memory:writeFloat`

Записывает float по текущему адресу (4 байта)

#### Сигнатура

```lua
Memory:writeFloat(value: number)
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
      <td><code>value</code></td>
      <td><code>number</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Алиасы

- `Memory:writeSingle`

### Метод `Memory:writeInt16`

Записывает int16 по текущему адресу (2 байта)

#### Сигнатура

```lua
Memory:writeInt16(value: number)
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
      <td><code>value</code></td>
      <td><code>number</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Алиасы

- `Memory:writeShort`

- `Memory:writeWord`

### Метод `Memory:writeInt32`

Записывает int32 по текущему адресу (4 байта)

#### Сигнатура

```lua
Memory:writeInt32(value: number)
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
      <td><code>value</code></td>
      <td><code>number</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Алиасы

- `Memory:writeDword`

- `Memory:writeInt`

### Метод `Memory:writeInt64`

Записывает int64 по текущему адресу (8 байт)

#### Сигнатура

```lua
Memory:writeInt64(value: number)
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
      <td><code>value</code></td>
      <td><code>number</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Алиасы

- `Memory:writeLong`

### Метод `Memory:writeInt8`

Записывает int8 по текущему адресу (1 байт)

#### Сигнатура

```lua
Memory:writeInt8(value: number)
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
      <td><code>value</code></td>
      <td><code>number</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Алиасы

- `Memory:writeByte`

- `Memory:writeChar`

### Метод `Memory:writeNearCall`

Записывает инструкцию вызова по относительному адресу (opcode E8)

#### Сигнатура

```lua
Memory:writeNearCall(value: number)
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
      <td><code>value</code></td>
      <td><code>number</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

### Метод `Memory:writeNop`

Записывает NOP по текущему адресу (opcode 0x90)

#### Сигнатура

```lua
Memory:writeNop(size: number)
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
      <td><code>size</code></td>
      <td><code>number</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

### Метод `Memory:writeString`

#### Сигнатура

```lua
Memory:writeString(string: any)
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
      <td><code>string</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

### Поле `Memory.addr`

**Тип**: `number`

### Поле `Memory.backup`

**Тип**: `table`

### Поле `Memory.unsafe`

**Тип**: `boolean`

---

## Класс `Hook`

### Поле `Hook.destroy`

Деактивировать и удалить хук

**Тип**: `fun()`

### Поле `Hook.destroyed`

Был ли хук удалён

**Тип**: `boolean`

### Поле `Hook.orig`

Оригинальная функция

**Тип**: `function`

---

## Класс `HookParams`

### Поле `HookParams.jit`

Включить JIT-компиляцию функции (ускоряет выполнение, но ломается если внутри оригинальной функции есть другие Lua хуки. Рекомендуется для частовыполняемых функций)

**Тип**: `boolean`

---

## Класс `MemoryParams`

### Поле `MemoryParams.cache`

Использовать кеширование паттернов (нужно если паттерн указывает больше чем на одно место в памяти)

**Тип**: `boolean`

### Поле `MemoryParams.unsafe`

Отключить защиту памяти

**Тип**: `boolean`

