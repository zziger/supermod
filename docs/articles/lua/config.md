# Модуль Config

Этот модуль предоставляет доступ к постоянному хранилищу данных, которое сохраняется между сессиями игры.

## Импорт модуля

Для импорта модуля используйте следующий код:

```lua
local config = require("config")
```

## Элементы модуля

### Функция `config.save`

Сохраняет конфиг файл на диск

#### Сигнатура

```lua
function config.save()
```

### Поле `config.mod`

Обьект конфигурации текущего мода

**Тип**: `Config`

---

## Класс `Config`

### Метод `Config:getBool`

Получает булево значение по указанному ключу

#### Сигнатура

```lua
Config:getBool(key: string)
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
      <td><code>key</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Метод `Config:getNumber`

Получает численное значение по указанному ключу

#### Сигнатура

```lua
Config:getNumber(key: string)
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
      <td><code>key</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `number` 

### Метод `Config:getObject`

Получает вложенный обьект по указанному ключу

#### Сигнатура

```lua
Config:getObject(key: string)
  -> table
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `table` 

### Метод `Config:getString`

Получает строковое значение по указанному ключу

#### Сигнатура

```lua
Config:getString(key: string)
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
      <td><code>key</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `string` 

### Метод `Config:has`

Возвращает существует ли указанный ключ

#### Сигнатура

```lua
Config:has(key: string)
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
      <td><code>key</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

### Метод `Config:set`

Устанавливает значение по указанному ключу

#### Сигнатура

```lua
Config:set(key: string, value: boolean|string|number)
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>key</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>value</code></td>
      <td><code>boolean</code> или <code>string</code> или <code>number</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

