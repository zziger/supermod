# Модуль Events

Этот модуль позволяет подписываться на события игры и SuperMod

## Импорт модуля

Для импорта модуля используйте следующий код:

```lua
local events = require("events")
```

## Элементы модуля

### Функция `events.off`

Отписывает функцию от ивента

#### Сигнатура

```lua
function events.off(id: number)
```

#### Аргументы

<table>
  <thead>
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
      <td>ID подписанного ивента</td>
    </tr>
  </tbody>
</table>

### Функция `events.on`

Подписывает функцию на ивент

#### Сигнатура

```lua
function events.on(eventName: string, fn: eventHandler<Event>)
  -> id: number
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>eventName</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td>название ивента</td>
    </tr>
    <tr>
      <td><code>fn</code></td>
      <td><code>eventHandler&lt;Event></code></td>
      <td>да</td>
      <td></td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

---

## Класс `CancellableEvent`

*Наследуется от `Event`*

### Поле `CancellableEvent.cancel`

Отменить ивент

**Тип**: `fun(self: Event)`

### Поле `CancellableEvent.isCancelled`

Проверить отменён ли ивент

**Тип**: `fun(self: Event): boolean`

---

## Класс `Event`

---

## Класс `ModEvent`

*Наследуется от `Event`*

### Поле `ModEvent.modInfo`

Информация о моде

**Тип**: `ModInfo`

---

## Класс `ResolutionEvent`

*Наследуется от `Event`*

### Поле `ResolutionEvent.x`

Новая ширина рендера

**Тип**: `number`

### Поле `ResolutionEvent.y`

Новая высота рендера

**Тип**: `number`

---

## Класс `ResolveFileEvent`

*Наследуется от `Event`*

### Поле `ResolveFileEvent.absolutePath`

Абсолютный путь к текущему файлу

**Тип**: `string`

### Поле `ResolveFileEvent.clearResolvedPath`

Сбрсоить обработанный путь (использовать путь по-умолчанию)

**Тип**: `fun(self: Event)`

### Поле `ResolveFileEvent.getResolvedPath`

Получить обработанный путь

**Тип**: `fun(self: Event): string` или `nil`

### Поле `ResolveFileEvent.setResolvedPath`

Установить новый обработанный путь

**Тип**: `fun(self: Event, path: string)`

---

## Класс `WindowEvent`

*Наследуется от `CancellableEvent`*

### Поле `WindowEvent.cancel`

Отменить ивент

**Тип**: `fun(self: Event)`

### Поле `WindowEvent.hWnd`

Ссылка на окно ивента (int*)

**Тип**: `number`

### Поле `WindowEvent.isCancelled`

Проверить отменён ли ивент

**Тип**: `fun(self: Event): boolean`

### Поле `WindowEvent.lParam`

Параметр L (зависит от ивента)

**Тип**: `number`

### Поле `WindowEvent.msg`

Идентификатор ивента

**Тип**: `number`

### Поле `WindowEvent.wParam`

Параметр W (зависит от ивента)

**Тип**: `number`

