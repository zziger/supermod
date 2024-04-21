---@meta filesystem
---@moduleTitle Filesystem
---@moduleDesc Этот модуль позволяет удобно работать с файловой системой.

---@class path
---@operator div(string): path
---@operator div(path): path
local path = {}

---Сбрасывает путь до пустой строки
function path:clear() end

---Удаляет название файла из пути
---@return path
---@example fs.path('/path/to/file.txt'):removeFilename() -- '/path/to/'
function path:removeFilename() end

---Изменяет название файла в пути
---@param filename path | string
---@return path
---@example fs.path('/path/to/file.txt'):replaceFilename('newfile.txt') -- '/path/to/newfile.txt'
function path:replaceFilename(filename) end

---Изменяет расширение файла в пути. Работает и с точкой в начале, и без нее.
---Если в пути расширения нет, добавляет новое. Если в пути несколько расширений (например .tar.gz), заменяет только последнее.
---@param extension path | string
---@return path
---@example fs.path('/path/to/file.txt'):replaceExtension('.png'):genericString() -- '/path/to/file.png'
---@example fs.path('/path/to/file.txt'):replaceExtension('png'):genericString() -- '/path/to/file.png'
---@example fs.path('/path/to/file'):replaceExtension('.png'):genericString() -- '/path/to/file.png'
---@example fs.path('/path/to/file'):replaceExtension('png'):genericString() -- '/path/to/file.png'
---@example fs.path('/path/to/file.tar.gz'):replaceExtension('.zip'):genericString() -- '/path/to/file.tar.zip'
function path:replaceExtension(extension) end

---Возвращает новый путь, полученный добавлением другого пути к текущему
---Также для простоты можно использовать оператор /
---@param other path | string
---@return path
---@example fs.path('/path/to/'):append('file.txt'):genericString() -- '/path/to/file.txt'
---@example (fs.path('/path/to/') / 'file.txt'):genericString() -- '/path/to/file.txt'
function path:append(other) end

---Возвращает родительский путь (например, папку файла)
---@return path
---@example fs.path('/path/to/file.txt'):parentPath():genericString() -- '/path/to'
function path:parentPath() end

---Возвращает название файла
---@return path
---@example fs.path('/path/to/file.txt'):filename():genericString() -- 'file.txt'
function path:filename() end

---Возвращает название файла без расширения. Если расширений несколько (например, .tar.gz), возвращает все до последней точки.
---@return path
---@example fs.path('/path/to/file.txt'):stem():genericString() -- 'file'
---@example fs.path('/path/to/file.tar.gz'):stem():genericString() -- 'file.tar'
function path:stem() end

---Возвращает расширение файла (с точкой в начале). Если расширений несколько (например, .tar.gz), возвращает только последнее.
---@return path
---@example fs.path('/path/to/file.txt'):extension():genericString() -- '.txt'
---@example fs.path('/path/to/file.tar.gz'):extension():genericString() -- '.gz'
function path:extension() end

---Возвращает true, если путь является пустой строкой
---@return boolean
---@example fs.path(''):isEmpty() -- true
---@example fs.path():isEmpty() -- false
---@example fs.path('/path/to/file.txt'):isEmpty() -- false
function path:isEmpty() end

---Возвращает true, если есть родительский путь (например, путь к файлу в папке)
---@return boolean
---@example fs.path('/path/to/file.txt'):hasParentPath() -- true
---@example fs.path('/file.txt'):hasParentPath() -- true
---@example fs.path('file.txt'):hasParentPath() -- false
function path:hasParentPath() end

---Возвращает true, если у пути есть название файла
---@return boolean
---@example fs.path('/path/to/file.txt'):hasFilename() -- true
---@example fs.path('/path/to/'):hasFilename() -- false
function path:hasFilename() end

---Возвращает true, если у пути есть название файла (без учета расширения)
---@return boolean
---@example fs.path('/path/to/file.txt'):hasStem() -- true
---@example fs.path('/path/to/'):hasStem() -- false
function path:hasStem() end

---Возвращает true, если у пути есть расширение файла
---@return boolean
---@example fs.path('/path/to/file.txt'):hasExtension() -- true
---@example fs.path('/path/to/file'):hasExtension() -- false
function path:hasExtension() end

---Возвращает true, если путь является абсолютным (начинается с корня диска)
---@return boolean
---@example fs.path('/path/to/file.txt'):isAbsolute() -- true
---@example fs.path('path/to/file.txt'):isAbsolute() -- false
---@example fs.path('.'):isAbsolute() -- false
function path:isAbsolute() end

---Возвращает true, если путь является относительным (начинается с папки, .. или .)
---@return boolean
---@example fs.path('/path/to/file.txt'):isRelative() -- false
---@example fs.path('path/to/file.txt'):isRelative() -- true
---@example fs.path('./path/to/file.txt'):isRelative() -- true
---@example fs.path('../path'):isRelative() -- true
function path:isRelative() end

---Возвращает путь в виде строки с обратными слешами (\)
---@return string
---@example fs.path('/path/to/file.txt'):string() -- '\\path\\to\\file.txt'
function path:string() end

---Возвращает путь в виде строки с прямыми слешами (/)
---@return string
---@example fs.path('/path/to/file.txt'):genericString() -- '/path/to/file.txt'
function path:genericString() end

---@class copyOptions
---@field recursive? boolean Копировать папки со всем содержимым
---@field existing? 'skip' | 'overwrite' | 'update' Что делать, если файл уже существует
---@field symlinks? 'copy' | 'skip' Что делать с символическими ссылками

---@class filesystem
local filesystem = {}

---Создает новый путь из строки
---@param str? string Путь
---@return path
---@example fs.path('/path/to/file.txt'):parentPath():genericString() -- '/path/to'
function filesystem.path(str) end

---Возвращает (если вызвать без аргументов) или меняет (если передать путь) текущий рабочий путь файловой системы
---@param path path | string Путь
---@overload fun(): path -- Возвращает текущий путь файловой системы
---@example fs.currentPath('/path/to/dir')
---@example fs.currentPath():genericString() -- '/path/to/dir'
function filesystem.currentPath(path) end

---Возвращает путь к временной папке (например, для сохранения временных файлов)
---@return path
---@example fs.tempDirectoryPath():genericString() -- 'C:/tmp/supercow' (путь будет другим)
function filesystem.tempDirectoryPath() end

---Возвращает абсолютный путь из относительного
---@param path path | string
---@return path
---@example fs.absolute('path/to/file.txt'):genericString() -- 'C:/path/to/file.txt'
function filesystem.absolute(path) end

---Создает относительный путь из абсолютного
---@param path path | string Абсолютный путь (целевой)
---@param base? path | string Основной путь (откуда считать относительный). Если не указан, используется текущий рабочий путь
---@return path
---@example fs.relative('C:/path/to/file.txt', 'C:/path'):genericString() -- 'to/file.txt'
---@example fs.currentPath('C:/path')
---fs.relative('C:/path/to/file.txt'):genericString() -- 'to/file.txt'
function filesystem.relative(path, base) end

---Возвращает true, если путь это папка
---@param path path | string
---@return boolean
---@example fs.isDirectory('/path/to/some/dir') -- true
function filesystem.isDirectory(path) end

---Возвращает true, если путь это пустой файл или папка
---@param path path | string
---@return boolean
---@example fs.isEmpty('/path/to/empty/dir') -- true
function filesystem.isEmpty(path) end

---Возвращает true, если путь существует
---@param path path | string
---@return boolean
---@example fs.exists('/path/to/file.txt') -- true
function filesystem.exists(path) end

---Удаляет файл или папку (пустую)
---@param path path | string
---@example fs.remove('/path/to/file.txt')
function filesystem.remove(path) end

---Удаляет файл или папку со всем содержимым
---@param path path | string
---@example fs.removeAll('/path/to/dir')
function filesystem.removeAll(path) end

---Создает папку
---@param path path | string
---@example fs.createDirectory('/path/to/dir')
function filesystem.createDirectory(path) end

---Создает папку и все родительские папки
---@param path path | string
---@example fs.createDirectories('/path/to/dir')
function filesystem.createDirectories(path) end

---Копирует файл или папку
---@param source path | string Исходный путь
---@param target path | string Целевой путь
---@param options? copyOptions Параметры копирования
---@example fs.copy('/path/to/file.txt', '/path/to/another/file.txt')
---@example fs.copy('/path/to/dir', '/path/to/another/dir', { recursive = true, existing = 'overwrite' })
function filesystem.copy(source, target, options) end

---Перемещает (переименовывает) файл или папку
---@param source path | string Исходный путь
---@param target path | string Целевой путь
---@example fs.move('/path/to/file.txt', '/path/to/another/file.txt')
---@example fs.rename('/path/to/file.txt', '/path/to/another/file.txt')
function filesystem.move(source, target) end
filesystem.rename = filesystem.move

return filesystem