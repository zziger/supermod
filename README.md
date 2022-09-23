# Мод на игру "Супер Корова" (Nevosoft)

## Сборка

Требования для сборки:
- Visual Studio Build Tools, рекомендуемо v143
- Windows SDK
- CMake 3.8 или новее

Для сборки нужно выполнить `build.bat` в корне проекта.<br>
Итоговая DLL будет находиться по пути `BUILD\Release\dinput8.dll`

## Установка

- Скачать последнюю версию мода [тут](https://github.com/zziger/supercow-mod/releases/latest/download/dinput8.dll).
- Поместить скачанный файл `dinput8.dll` в папку с игрой. Название файла менять нельзя.

## Функции

### Команды в консоли

- `load НАЗВАНИЕ_МОДУЛЯ` - загружает выбранный модуль.
- `unload НАЗВАНИЕ_МОДУЛЯ` - выгружает выбранный модуль.
- `editor` - Открывает редактор уровней, команду нужно выполнить до полной загрузки игры.

Для выполнения команд конкретного модуля нужно его загрузить командой `load`.

### Доступные модули

#### ALLOW_MULTIPLE_INSTANCES
Разрешает запуск нескольких копий игры одновременно.

#### RENDER_UNFOCUSED
Отключает установку игры на паузу, пока окно не активно.

#### WIDESCREEN_FIX
Заставляет игру производить рендер в разрешении экрана.<br>
Можно установить кастомное разрешение командой `overrideRes 1920 1080`, где 1920 это - ширина а 1080 - высота.<br>
Чтобы сбросить перезапись - `resetResOverride`.<br>
Есть возможность перезаписать разрешение загрузки конкретной текстуры командой `addTextureOverride texturename.jpg 1366 768`.<br>
Чтобы сбросить перезапись - `removeTextureOverride texturename.jpg`

[//]: # (#### EDITOR)
[//]: # (Включает редактор уровней при запуске игры.)

#### ADD_MUSIC
Позволяет загружать дополнительную музыку для уровней.<br>
Добавление - `addMusic path/to/file.ogg` (путь относительно папки `data` игры);<br>
Удаление - `removeMusic path/to/file.ogg`;<br>
Просмотр списка - `additionalMusic`.<br>
После добавления/удаления нужно перезапустить игру!

#### STARTUP_SPLASH
Позволяет показывать сплеш с любым текстом сразу после загрузки модуля (игры).<br>
Установить текст - `setStartupSplash тут ваш текст`.

#### EARLY_STATS
Показывает краткую статистику текстом сразу после прохождения уровня.<br>
Полезно для спидранов, в которых окно статистики пропускается для скорости

#### FPS_LIMIT
Мягко ограничивает количество FPS игры.<br>
Изменить лимит - `setFps 120`.

#### EXTEND_GROUNDS_LIMIT
Изменяет встроенный лимит обьектов типа ground.<br>
Изменить лимит - `setGrounds 10`.

### Консоль
Для отключения консоли (например, в целях добавления мода в свой мод/репак) достаточно добавить `"console":false` в `modcfg.json`

## Лицензия

[MIT](LICENSE)

## Contributions

Если нужен какой-то новый функционал - PR приветствуются.<br>
Для вопросов - Discord `zziger#8040`