# Модуль Timers

Этот модуль позволяет создавать таймеры, которые будут вызывать функции через определённое время или с определённым интервалом.

## Импорт модуля

Для импорта модуля используйте следующий код:

```lua
local timers = require("timers")
```

## Элементы модуля

### Функция `timers.clearTimer`

#### Сигнатура

```lua
function timers.clearTimer(id: any)
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
      <td><code>id</code></td>
      <td><code>any</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

### Функция `timers.setInterval`

Выполняет функцию fn каждые delay миллисекунд

#### Сигнатура

```lua
function timers.setInterval(fn: any, delay: number)
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
      <td><code>fn</code></td>
      <td><code>any</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>delay</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>количество миллисекунд</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `timers.setTimeout`

Выполняет функцию fn через delay миллисекунд

#### Сигнатура

```lua
function timers.setTimeout(fn: any, delay: number)
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
      <td><code>fn</code></td>
      <td><code>any</code></td>
      <td>да</td>
      <td></td>
    </tr>
    <tr>
      <td><code>delay</code></td>
      <td><code>number</code></td>
      <td>да</td>
      <td>количество миллисекунд</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

---

## Класс `Timer`

### Поле `Timer.at`

**Тип**: `number`

### Поле `Timer.delay`

**Тип**: `number`

### Поле `Timer.fn`

**Тип**: `fun()`

### Поле `Timer.once`

**Тип**: `boolean`

