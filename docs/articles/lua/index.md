# SuperMod Lua API

## Глобальные элементы

### ~~Функция `game.isGameLoaded`~~

#### Сигнатура

```lua
function game.isGameLoaded()
```

### Функция `game.world.getCamPos`

#### Сигнатура

```lua
function game.world.getCamPos()
  -> vector2
```

#### Возвращает

- `vector2` 

### Функция `game.world.getCamWorldRect`

#### Сигнатура

```lua
function game.world.getCamWorldRect()
  -> rect
```

#### Возвращает

- `rect` 

### Функция `game.world.getCamZoom`

#### Сигнатура

```lua
function game.world.getCamZoom()
  -> number
```

#### Возвращает

- `number` 

### Функция `game.world.getWorldProjectionSize`

#### Сигнатура

```lua
function game.world.getWorldProjectionSize()
  -> vector2
```

#### Возвращает

- `vector2` 

### Функция `game.world.screenToWorld`

#### Сигнатура

```lua
function game.world.screenToWorld()
  -> vector2
```

#### Возвращает

- `vector2` 

### Функция `game.world.worldToScreen`

#### Сигнатура

```lua
function game.world.worldToScreen(coords: vector2)
  -> boolean
  2. vector2
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
  </tbody>
</table>

#### Возвращает

- `boolean` 

- `vector2` 

### Функция `log.debug`

#### Сигнатура

```lua
function log.debug(msg: string)
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>msg</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td>Текст лога</td>
    </tr>
  </tbody>
</table>

### Функция `log.error`

#### Сигнатура

```lua
function log.error(msg: string)
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>msg</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td>Текст лога</td>
    </tr>
  </tbody>
</table>

### ~~Функция `log.game`~~ (устарела)

#### Сигнатура

```lua
function log.game(msg: string)
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>msg</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td>Текст лога</td>
    </tr>
  </tbody>
</table>

### Функция `log.info`

#### Сигнатура

```lua
function log.info(msg: string)
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>msg</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td>Текст лога</td>
    </tr>
  </tbody>
</table>

### Функция `log.warn`

#### Сигнатура

```lua
function log.warn(msg: string)
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>msg</code></td>
      <td><code>string</code></td>
      <td>да</td>
      <td>Текст лога</td>
    </tr>
  </tbody>
</table>

### Функция `math.clamp`

#### Сигнатура

```lua
function math.clamp(val: number, from: number, to: number)
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
      <td><code>val</code></td>
      <td><code>number</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>from</code></td>
      <td><code>number</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>to</code></td>
      <td><code>number</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Поле `currentMod`

**Тип**: `ModInfo`

### Функция `currentTimestamp`

#### Сигнатура

```lua
function currentTimestamp()
  -> number
```

#### Возвращает

- `number` 

### Функция `findPattern`

#### Сигнатура

```lua
function findPattern(cache: boolean, pat: string)
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
      <td><code>cache</code></td>
      <td><code>boolean</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>pat</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Функция `rect`

#### Сигнатура

```lua
function rect(left: number, top: number, right: number, bottom: number)
  -> rect
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
      <td><code>left</code></td>
      <td><code>number</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>top</code></td>
      <td><code>number</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>right</code></td>
      <td><code>number</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>bottom</code></td>
      <td><code>number</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `rect` 

### Функция `rgba`

#### Сигнатура

```lua
function rgba(r: number, g: number, b: number, a: number)
  -> rgba
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
      <td><code>number</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>g</code></td>
      <td><code>number</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>b</code></td>
      <td><code>number</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>a</code></td>
      <td><code>number</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `rgba` 

### Функция `vector2`

#### Сигнатура

```lua
function vector2(x: number, y: number)
  -> vector2
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
      <td><code>x</code></td>
      <td><code>number</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>y</code></td>
      <td><code>number</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `vector2` 

### Функция `vector3`

#### Сигнатура

```lua
function vector3(x: number, y: number, z: number)
  -> vector3
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
      <td><code>x</code></td>
      <td><code>number</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>y</code></td>
      <td><code>number</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>z</code></td>
      <td><code>number</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `vector3` 

---

## Класс `ModInfo`

### Поле `ModInfo.author`

**Тип**: `string`

### Поле `ModInfo.basePath`

**Тип**: `string`

### Поле `ModInfo.compatible`

**Тип**: `boolean`

### Поле `ModInfo.gameVersions`

**Тип**: `number[]`

### Поле `ModInfo.id`

**Тип**: `string`

### Поле `ModInfo.internal`

**Тип**: `boolean`

### Поле `ModInfo.luaScript`

**Тип**: `string`

### Поле `ModInfo.title`

**Тип**: `string`

### Поле `ModInfo.version`

**Тип**: `string`

---

## Класс `rect`

### Поле `rect.bottom`

**Тип**: `number`

### Поле `rect.left`

**Тип**: `number`

### Поле `rect.right`

**Тип**: `number`

### Поле `rect.top`

**Тип**: `number`

---

## Класс `rgba`

### Поле `rgba.a`

**Тип**: `number`

### Поле `rgba.b`

**Тип**: `number`

### Поле `rgba.g`

**Тип**: `number`

### Поле `rgba.r`

**Тип**: `number`

---

## Класс `vector2`

### Поле `vector2.x`

**Тип**: `number`

### Поле `vector2.y`

**Тип**: `number`

---

## Класс `vector3`

*Наследуется от `vector2`*

### Поле `vector3.x`

**Тип**: `number`

### Поле `vector3.y`

**Тип**: `number`

### Поле `vector3.z`

**Тип**: `number`

