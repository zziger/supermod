# Модуль Graphics

Этот модуль позволяет рендерить текстуры и текст на экран. Эти функции нужно вызывать внутри `render` или своих хуков.

## Импорт модуля

Для импорта модуля используйте следующий код:

```lua
local graphics = require("graphics")
```

## Элементы модуля

### Функция `graphics.render`

Рендерит текущую текстуру на экран

#### Сигнатура

```lua
function graphics.render(coords: vector2, size: vector2, uv?: rect, color?: rgba)
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
      <td><code>coords</code></td>
      <td><code>vector2</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>size</code></td>
      <td><code>vector2</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>uv</code></td>
      <td><code>rect</code></td>
      <td>нет</td>
    </tr>
    <tr>
      <td><code>color</code></td>
      <td><code>rgba</code></td>
      <td>нет</td>
    </tr>
  </tbody>
</table>

### Функция `graphics.renderText`

Рендерит текст на экран

#### Сигнатура

```lua
function graphics.renderText(coords: vector2, size: number, text: string)
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
      <td><code>coords</code></td>
      <td><code>vector2</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>size</code></td>
      <td><code>number</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>text</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

### Функция `graphics.resetRenderProjection`

Сбрасывает проекцию рендера до 800x600

#### Сигнатура

```lua
function graphics.resetRenderProjection()
```

### Функция `graphics.resetRenderTransform`

Сбрасывает трансформацию рендера до 0, 0

#### Сигнатура

```lua
function graphics.resetRenderTransform()
```

### Функция `graphics.setRenderAsset`

Устанавливает текущую текстуру для рендера

#### Сигнатура

```lua
function graphics.setRenderAsset(asset?: Asset)
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
      <td><code>asset</code></td>
      <td><code>Asset</code></td>
      <td>нет</td>
    </tr>
  </tbody>
</table>

### Функция `graphics.setRenderProjection`

Устанавливает проекцию рендера

#### Сигнатура

```lua
function graphics.setRenderProjection(size: vector2, near: number, far: number)
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
      <td><code>vector2</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>near</code></td>
      <td><code>number</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>far</code></td>
      <td><code>number</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

### Функция `graphics.setRenderTransform`

Устанавливает трансформацию рендера

#### Сигнатура

```lua
function graphics.setRenderTransform(pos: vector2)
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
      <td><code>pos</code></td>
      <td><code>vector2</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

### Функция `graphics.setTextColor`

Устанавливает цвет текста

#### Сигнатура

```lua
function graphics.setTextColor(color: rgba)
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
      <td><code>color</code></td>
      <td><code>rgba</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

