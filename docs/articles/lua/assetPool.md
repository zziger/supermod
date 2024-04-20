# Модуль assetPool

### Функция `assetPool.getAssetByName`

Возвращает ассет по имени

#### Сигнатура

```lua
function assetPool.getAssetByName(name: string)
  -> Asset?
```

#### Аргументы

<table>
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

- `Asset` 

### Функция `assetPool.getAssets`

Возвращает все ассеты из пула

#### Сигнатура

```lua
function assetPool.getAssets()
  -> Asset[]
```

#### Возвращает

- `Asset[]` 

### Функция `assetPool.getUnknownAsset`

Возвращает неизвестный ассет (фиолетово-чёрная шашка)

#### Сигнатура

```lua
function assetPool.getUnknownAsset()
  -> Asset
```

#### Возвращает

- `Asset` 

### Функция `assetPool.loadAsset`

Загружает ассет по точному пути к файлу от текущей папки

#### Сигнатура

```lua
function assetPool.loadAsset(path: string, key: string, loadFallback?: boolean, canvasSizeMultiplier?: vector2)
  -> Asset?
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>path</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>key</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>loadFallback</code></td>
      <td><code>boolean</code></td>
      <td>нет</td>
    </tr>
    <tr>
      <td><code>canvasSizeMultiplier</code></td>
      <td><code>vector2</code></td>
      <td>нет</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `Asset` 

### Функция `assetPool.loadGameAsset`

Загружает ассет по правилам загрузки ассетов игры (пробует разные расширения файлов и т.д.) от текущей папки

#### Сигнатура

```lua
function assetPool.loadGameAsset(path: string, loadFallback?: boolean, canvasSizeMultiplier?: vector2)
  -> Asset?
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>path</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>loadFallback</code></td>
      <td><code>boolean</code></td>
      <td>нет</td>
    </tr>
    <tr>
      <td><code>canvasSizeMultiplier</code></td>
      <td><code>vector2</code></td>
      <td>нет</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `Asset` 

### Функция `assetPool.loadGameAssetFromData`

Загружает ассет по правилам загрузки ассетов игры (пробует разные расширения файлов и т.д.) от папки data

#### Сигнатура

```lua
function assetPool.loadGameAssetFromData(path: string, loadFallback?: boolean, canvasSizeMultiplier?: vector2)
  -> Asset?
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>path</code></td>
      <td><code>string</code></td>
      <td>да</td>
    </tr>
    <tr>
      <td><code>loadFallback</code></td>
      <td><code>boolean</code></td>
      <td>нет</td>
    </tr>
    <tr>
      <td><code>canvasSizeMultiplier</code></td>
      <td><code>vector2</code></td>
      <td>нет</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `Asset` 

### Функция `assetPool.removeAsset`

Удаляет ассет из пула и выгружает из памяти

#### Сигнатура

```lua
function assetPool.removeAsset(asset: Asset)
```

#### Аргументы

<table>
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
      <td>да</td>
    </tr>
  </tbody>
</table>

---

## Класс `Asset`

### Поле `Asset.format`

**Тип**: `number`

### Поле `Asset.hasAlpha`

**Тип**: `boolean`

### Поле `Asset.height`

**Тип**: `number`

### Поле `Asset.isPoolDefault`

**Тип**: `boolean`

### Поле `Asset.meta`

**Тип**: `AssetMeta`

### Поле `Asset.name`

**Тип**: `string`

### Поле `Asset.texture`

**Тип**: `userdata`

### Поле `Asset.width`

**Тип**: `number`

---

## Класс `AssetMeta`

### Поле `AssetMeta.canvasSizeMultiplier`

**Тип**: `vector2`

### Поле `AssetMeta.loadedManually`

**Тип**: `boolean`

### Поле `AssetMeta.notFound`

**Тип**: `boolean`

### Поле `AssetMeta.origDir`

**Тип**: `string`

### Поле `AssetMeta.origName`

**Тип**: `string`

