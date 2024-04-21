# Модуль Filesystem

Этот модуль позволяет удобно работать с файловой системой.

## Импорт модуля

Для импорта модуля используйте следующий код:

```lua
local filesystem = require("filesystem")
```

## Элементы модуля

### Функция `filesystem.absolute`

Возвращает абсолютный путь из относительного

#### Сигнатура

```lua
function filesystem.absolute(path: string|path)
  -> path
```

#### Аргументы

<table>
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
      <td><code>string</code> или <code>path</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `path` 

#### Примеры

<details>
<summary>Показать пример #1</summary>

```lua
fs.absolute('path/to/file.txt'):genericString() -- 'C:/path/to/file.txt'
```

</details>

### Функция `filesystem.copy`

Копирует файл или папку

#### Сигнатура

```lua
function filesystem.copy(source: string|path, target: string|path, options?: copyOptions)
```

#### Аргументы

<table>
  <thead>
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
      <td><code>string</code> или <code>path</code></td>
      <td>да</td>
      <td>Исходный путь</td>
    </tr>
    <tr>
      <td><code>target</code></td>
      <td><code>string</code> или <code>path</code></td>
      <td>да</td>
      <td>Целевой путь</td>
    </tr>
    <tr>
      <td><code>options</code></td>
      <td><code>copyOptions</code></td>
      <td>нет</td>
      <td>Параметры копирования</td>
    </tr>
  </tbody>
</table>

#### Примеры

<details>
<summary>Показать пример #1</summary>

```lua
fs.copy('/path/to/file.txt', '/path/to/another/file.txt')
```

</details>

<details>
<summary>Показать пример #2</summary>

```lua
fs.copy('/path/to/dir', '/path/to/another/dir', { recursive = true, existing = 'overwrite' })
```

</details>

### Функция `filesystem.createDirectories`

Создает папку и все родительские папки

#### Сигнатура

```lua
function filesystem.createDirectories(path: string|path)
```

#### Аргументы

<table>
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
      <td><code>string</code> или <code>path</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Примеры

<details>
<summary>Показать пример #1</summary>

```lua
fs.createDirectories('/path/to/dir')
```

</details>

### Функция `filesystem.createDirectory`

Создает папку

#### Сигнатура

```lua
function filesystem.createDirectory(path: string|path)
```

#### Аргументы

<table>
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
      <td><code>string</code> или <code>path</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Примеры

<details>
<summary>Показать пример #1</summary>

```lua
fs.createDirectory('/path/to/dir')
```

</details>

### Функция `filesystem.currentPath`

Возвращает (если вызвать без аргументов) или меняет (если передать путь) текущий рабочий путь файловой системы

#### Сигнатура

```lua
function filesystem.currentPath(path: string|path)
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>path</code></td>
      <td><code>string</code> или <code>path</code></td>
      <td>да</td>
      <td>Путь</td>
    </tr>
  </tbody>
</table>

#### Примеры

<details>
<summary>Показать пример #1</summary>

```lua
fs.currentPath('/path/to/dir')
```

</details>

<details>
<summary>Показать пример #2</summary>

```lua
fs.currentPath():genericString() -- '/path/to/dir'
```

</details>

#### Перегрузки

- `fun(): path` - Возвращает текущий путь файловой системы

### Функция `filesystem.exists`

Возвращает true, если путь существует

#### Сигнатура

```lua
function filesystem.exists(path: string|path)
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
      <td><code>path</code></td>
      <td><code>string</code> или <code>path</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

#### Примеры

<details>
<summary>Показать пример #1</summary>

```lua
fs.exists('/path/to/file.txt') -- true
```

</details>

### Функция `filesystem.isDirectory`

Возвращает true, если путь это папка

#### Сигнатура

```lua
function filesystem.isDirectory(path: string|path)
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
      <td><code>path</code></td>
      <td><code>string</code> или <code>path</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

#### Примеры

<details>
<summary>Показать пример #1</summary>

```lua
fs.isDirectory('/path/to/some/dir') -- true
```

</details>

### Функция `filesystem.isEmpty`

Возвращает true, если путь это пустой файл или папка

#### Сигнатура

```lua
function filesystem.isEmpty(path: string|path)
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
      <td><code>path</code></td>
      <td><code>string</code> или <code>path</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `boolean` 

#### Примеры

<details>
<summary>Показать пример #1</summary>

```lua
fs.isEmpty('/path/to/empty/dir') -- true
```

</details>

### Функция `filesystem.move`

Перемещает (переименовывает) файл или папку

#### Сигнатура

```lua
function filesystem.move(source: string|path, target: string|path)
```

#### Аргументы

<table>
  <thead>
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
      <td><code>string</code> или <code>path</code></td>
      <td>да</td>
      <td>Исходный путь</td>
    </tr>
    <tr>
      <td><code>target</code></td>
      <td><code>string</code> или <code>path</code></td>
      <td>да</td>
      <td>Целевой путь</td>
    </tr>
  </tbody>
</table>

#### Алиасы

- `filesystem.rename`

#### Примеры

<details>
<summary>Показать пример #1</summary>

```lua
fs.move('/path/to/file.txt', '/path/to/another/file.txt')
```

</details>

<details>
<summary>Показать пример #2</summary>

```lua
fs.rename('/path/to/file.txt', '/path/to/another/file.txt')
```

</details>

### Функция `filesystem.path`

Создает новый путь из строки

#### Сигнатура

```lua
function filesystem.path(str?: string)
  -> path
```

#### Аргументы

<table>
  <thead>
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
      <td><code>string</code></td>
      <td>нет</td>
      <td>Путь</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `path` 

#### Примеры

<details>
<summary>Показать пример #1</summary>

```lua
fs.path('/path/to/file.txt'):parentPath():genericString() -- '/path/to'
```

</details>

### Функция `filesystem.relative`

Создает относительный путь из абсолютного<br/>
fs.relative('C:/path/to/file.txt'):genericString() -- 'to/file.txt'

#### Сигнатура

```lua
function filesystem.relative(path: string|path, base?: string|path)
  -> path
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
      <th>Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>path</code></td>
      <td><code>string</code> или <code>path</code></td>
      <td>да</td>
      <td>Абсолютный путь (целевой)</td>
    </tr>
    <tr>
      <td><code>base</code></td>
      <td><code>string</code> или <code>path</code></td>
      <td>нет</td>
      <td>Основной путь (откуда считать относительный). Если не указан, используется текущий рабочий путь</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `path` 

#### Примеры

<details>
<summary>Показать пример #1</summary>

```lua
fs.relative('C:/path/to/file.txt', 'C:/path'):genericString() -- 'to/file.txt'
```

</details>

<details>
<summary>Показать пример #2</summary>

```lua
fs.currentPath('C:/path')
fs.relative('C:/path/to/file.txt'):genericString() -- 'to/file.txt'
```

</details>

### Функция `filesystem.remove`

Удаляет файл или папку (пустую)

#### Сигнатура

```lua
function filesystem.remove(path: string|path)
```

#### Аргументы

<table>
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
      <td><code>string</code> или <code>path</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Примеры

<details>
<summary>Показать пример #1</summary>

```lua
fs.remove('/path/to/file.txt')
```

</details>

### Функция `filesystem.removeAll`

Удаляет файл или папку со всем содержимым

#### Сигнатура

```lua
function filesystem.removeAll(path: string|path)
```

#### Аргументы

<table>
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
      <td><code>string</code> или <code>path</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Примеры

<details>
<summary>Показать пример #1</summary>

```lua
fs.removeAll('/path/to/dir')
```

</details>

### Функция `filesystem.tempDirectoryPath`

Возвращает путь к временной папке (например, для сохранения временных файлов)

#### Сигнатура

```lua
function filesystem.tempDirectoryPath()
  -> path
```

#### Возвращает

- `path` 

#### Примеры

<details>
<summary>Показать пример #1</summary>

```lua
fs.tempDirectoryPath():genericString() -- 'C:/tmp/supercow' (путь будет другим)
```

</details>

---

## Класс `copyOptions`

### Поле `copyOptions.existing`

Что делать, если файл уже существует

**Тип**: `'overwrite'` или `'skip'` или `'update'`

### Поле `copyOptions.recursive`

Копировать папки со всем содержимым

**Тип**: `boolean`

### Поле `copyOptions.symlinks`

Что делать с символическими ссылками

**Тип**: `'copy'` или `'skip'`

---

## Класс `path`

### Метод `path:append`

Возвращает новый путь, полученный добавлением другого пути к текущему<br/>
Также для простоты можно использовать оператор /

#### Сигнатура

```lua
path:append(other: string|path)
  -> path
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>other</code></td>
      <td><code>string</code> или <code>path</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `path` 

#### Примеры

<details>
<summary>Показать пример #1</summary>

```lua
fs.path('/path/to/'):append('file.txt'):genericString() -- '/path/to/file.txt'
```

</details>

<details>
<summary>Показать пример #2</summary>

```lua
(fs.path('/path/to/') / 'file.txt'):genericString() -- '/path/to/file.txt'
```

</details>

### Метод `path:clear`

Сбрасывает путь до пустой строки

#### Сигнатура

```lua
path:clear()
```

### Метод `path:extension`

Возвращает расширение файла (с точкой в начале). Если расширений несколько (например, .tar.gz), возвращает только последнее.

#### Сигнатура

```lua
path:extension()
  -> path
```

#### Возвращает

- `path` 

#### Примеры

<details>
<summary>Показать пример #1</summary>

```lua
fs.path('/path/to/file.txt'):extension():genericString() -- '.txt'
```

</details>

<details>
<summary>Показать пример #2</summary>

```lua
fs.path('/path/to/file.tar.gz'):extension():genericString() -- '.gz'
```

</details>

### Метод `path:filename`

Возвращает название файла

#### Сигнатура

```lua
path:filename()
  -> path
```

#### Возвращает

- `path` 

#### Примеры

<details>
<summary>Показать пример #1</summary>

```lua
fs.path('/path/to/file.txt'):filename():genericString() -- 'file.txt'
```

</details>

### Метод `path:genericString`

Возвращает путь в виде строки с прямыми слешами (/)

#### Сигнатура

```lua
path:genericString()
  -> string
```

#### Возвращает

- `string` 

#### Примеры

<details>
<summary>Показать пример #1</summary>

```lua
fs.path('/path/to/file.txt'):genericString() -- '/path/to/file.txt'
```

</details>

### Метод `path:hasExtension`

Возвращает true, если у пути есть расширение файла

#### Сигнатура

```lua
path:hasExtension()
  -> boolean
```

#### Возвращает

- `boolean` 

#### Примеры

<details>
<summary>Показать пример #1</summary>

```lua
fs.path('/path/to/file.txt'):hasExtension() -- true
```

</details>

<details>
<summary>Показать пример #2</summary>

```lua
fs.path('/path/to/file'):hasExtension() -- false
```

</details>

### Метод `path:hasFilename`

Возвращает true, если у пути есть название файла

#### Сигнатура

```lua
path:hasFilename()
  -> boolean
```

#### Возвращает

- `boolean` 

#### Примеры

<details>
<summary>Показать пример #1</summary>

```lua
fs.path('/path/to/file.txt'):hasFilename() -- true
```

</details>

<details>
<summary>Показать пример #2</summary>

```lua
fs.path('/path/to/'):hasFilename() -- false
```

</details>

### Метод `path:hasParentPath`

Возвращает true, если есть родительский путь (например, путь к файлу в папке)

#### Сигнатура

```lua
path:hasParentPath()
  -> boolean
```

#### Возвращает

- `boolean` 

#### Примеры

<details>
<summary>Показать пример #1</summary>

```lua
fs.path('/path/to/file.txt'):hasParentPath() -- true
```

</details>

<details>
<summary>Показать пример #2</summary>

```lua
fs.path('/file.txt'):hasParentPath() -- true
```

</details>

<details>
<summary>Показать пример #3</summary>

```lua
fs.path('file.txt'):hasParentPath() -- false
```

</details>

### Метод `path:hasStem`

Возвращает true, если у пути есть название файла (без учета расширения)

#### Сигнатура

```lua
path:hasStem()
  -> boolean
```

#### Возвращает

- `boolean` 

#### Примеры

<details>
<summary>Показать пример #1</summary>

```lua
fs.path('/path/to/file.txt'):hasStem() -- true
```

</details>

<details>
<summary>Показать пример #2</summary>

```lua
fs.path('/path/to/'):hasStem() -- false
```

</details>

### Метод `path:isAbsolute`

Возвращает true, если путь является абсолютным (начинается с корня диска)

#### Сигнатура

```lua
path:isAbsolute()
  -> boolean
```

#### Возвращает

- `boolean` 

#### Примеры

<details>
<summary>Показать пример #1</summary>

```lua
fs.path('/path/to/file.txt'):isAbsolute() -- true
```

</details>

<details>
<summary>Показать пример #2</summary>

```lua
fs.path('path/to/file.txt'):isAbsolute() -- false
```

</details>

<details>
<summary>Показать пример #3</summary>

```lua
fs.path('.'):isAbsolute() -- false
```

</details>

### Метод `path:isEmpty`

Возвращает true, если путь является пустой строкой

#### Сигнатура

```lua
path:isEmpty()
  -> boolean
```

#### Возвращает

- `boolean` 

#### Примеры

<details>
<summary>Показать пример #1</summary>

```lua
fs.path(''):isEmpty() -- true
```

</details>

<details>
<summary>Показать пример #2</summary>

```lua
fs.path():isEmpty() -- false
```

</details>

<details>
<summary>Показать пример #3</summary>

```lua
fs.path('/path/to/file.txt'):isEmpty() -- false
```

</details>

### Метод `path:isRelative`

Возвращает true, если путь является относительным (начинается с папки, .. или .)

#### Сигнатура

```lua
path:isRelative()
  -> boolean
```

#### Возвращает

- `boolean` 

#### Примеры

<details>
<summary>Показать пример #1</summary>

```lua
fs.path('/path/to/file.txt'):isRelative() -- false
```

</details>

<details>
<summary>Показать пример #2</summary>

```lua
fs.path('path/to/file.txt'):isRelative() -- true
```

</details>

<details>
<summary>Показать пример #3</summary>

```lua
fs.path('./path/to/file.txt'):isRelative() -- true
```

</details>

<details>
<summary>Показать пример #4</summary>

```lua
fs.path('../path'):isRelative() -- true
```

</details>

### Метод `path:makePreferred`

Меняет слеши в пути на обратные (\)

#### Сигнатура

```lua
path:makePreferred()
  -> path
```

#### Возвращает

- `path` 

### Метод `path:parentPath`

Возвращает родительский путь (например, папку файла)

#### Сигнатура

```lua
path:parentPath()
  -> path
```

#### Возвращает

- `path` 

#### Примеры

<details>
<summary>Показать пример #1</summary>

```lua
fs.path('/path/to/file.txt'):parentPath():genericString() -- '/path/to'
```

</details>

### Метод `path:removeFilename`

Удаляет название файла из пути

#### Сигнатура

```lua
path:removeFilename()
  -> path
```

#### Возвращает

- `path` 

#### Примеры

<details>
<summary>Показать пример #1</summary>

```lua
fs.path('/path/to/file.txt'):removeFilename() -- '/path/to/'
```

</details>

### Метод `path:replaceExtension`

Изменяет расширение файла в пути. Работает и с точкой в начале, и без нее.<br/>
Если в пути расширения нет, добавляет новое. Если в пути несколько расширений (например .tar.gz), заменяет только последнее.

#### Сигнатура

```lua
path:replaceExtension(extension: string|path)
  -> path
```

#### Аргументы

<table>
  <thead>
    <tr>
      <th>Имя</th>
      <th>Тип</th>
      <th>Обязателен?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>extension</code></td>
      <td><code>string</code> или <code>path</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `path` 

#### Примеры

<details>
<summary>Показать пример #1</summary>

```lua
fs.path('/path/to/file.txt'):replaceExtension('.png'):genericString() -- '/path/to/file.png'
```

</details>

<details>
<summary>Показать пример #2</summary>

```lua
fs.path('/path/to/file.txt'):replaceExtension('png'):genericString() -- '/path/to/file.png'
```

</details>

<details>
<summary>Показать пример #3</summary>

```lua
fs.path('/path/to/file'):replaceExtension('.png'):genericString() -- '/path/to/file.png'
```

</details>

<details>
<summary>Показать пример #4</summary>

```lua
fs.path('/path/to/file'):replaceExtension('png'):genericString() -- '/path/to/file.png'
```

</details>

<details>
<summary>Показать пример #5</summary>

```lua
fs.path('/path/to/file.tar.gz'):replaceExtension('.zip'):genericString() -- '/path/to/file.tar.zip'
```

</details>

### Метод `path:replaceFilename`

Изменяет название файла в пути

#### Сигнатура

```lua
path:replaceFilename(filename: string|path)
  -> path
```

#### Аргументы

<table>
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
      <td><code>string</code> или <code>path</code></td>
      <td>да</td>
    </tr>
  </tbody>
</table>

#### Возвращает

- `path` 

#### Примеры

<details>
<summary>Показать пример #1</summary>

```lua
fs.path('/path/to/file.txt'):replaceFilename('newfile.txt') -- '/path/to/newfile.txt'
```

</details>

### Метод `path:stem`

Возвращает название файла без расширения. Если расширений несколько (например, .tar.gz), возвращает все до последней точки.

#### Сигнатура

```lua
path:stem()
  -> path
```

#### Возвращает

- `path` 

#### Примеры

<details>
<summary>Показать пример #1</summary>

```lua
fs.path('/path/to/file.txt'):stem():genericString() -- 'file'
```

</details>

<details>
<summary>Показать пример #2</summary>

```lua
fs.path('/path/to/file.tar.gz'):stem():genericString() -- 'file.tar'
```

</details>

### Метод `path:string`

Возвращает путь в виде строки с оригинальными слешами

#### Сигнатура

```lua
path:string()
  -> string
```

#### Возвращает

- `string` 

#### Примеры

<details>
<summary>Показать пример #1</summary>

```lua
fs.path('/path/to/file.txt'):string() -- '\\path\\to\\file.txt'
```

</details>

