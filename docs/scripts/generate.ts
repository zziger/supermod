import * as fs from 'fs';
import * as path from 'path';
import * as url from 'url';
import {SourceFile} from "./sourceFile";
import {SourceLocation, SourceRange} from "./source";
import {Markdown} from "./markdown";
import {isSubpath} from "./utils";
import * as child_process from "node:child_process";


interface IExtendsBase {
    type: string;
    start: number;
    finish: number;
}

interface IExtendsFunction extends IExtendsBase {
    type: 'function';
    name: string;
    desc: string;
    rawdesc: string;
    view: string;
    args: {
        start: number;
        finish: number;
        name: string;
        type: string;
        view: string;
        rawdesc?: string;
    }[];
    returns: {
        type: string;
        view: string;
    }[];
}

interface IExtendsType extends IExtendsBase {
    type: 'doc.type';
    view: string;
}

interface IExtendsGetLocal extends IExtendsBase {
    type: 'getlocal';
}

interface IExtendsGetField extends IExtendsBase {
    type: 'getfield';
}

interface IExtendsName extends IExtendsBase {
    type: 'doc.extends.name';
    view: string;
}

interface IExtendsSelect extends IExtendsBase {
    type: 'select';
    view: string;
}

interface IExtendsTable extends IExtendsBase {
    type: 'table';
    view: string;
}

type IExtends = IExtendsFunction | IExtendsType | IExtendsGetLocal | IExtendsGetField | IExtendsName | IExtendsSelect | IExtendsTable;

interface IDefine {
    file: string;
    finish: number;
    start: number;
    type: string;
    extends?: IExtends[] | IExtends;
}

interface IField extends IDefine {
    desc: string;
    rawdesc: string;
    name: string;
    extends: IExtends;
    hidden?: boolean;
}

interface IObject {
    defines: IDefine[];
    name: string;
    type: string;
    desc?: string;
    rawdesc?: string;
    fields?: IField[];
    global?: boolean;
}

const tempPath = "./temp";
if (!fs.existsSync(tempPath)) {
    fs.mkdirSync(tempPath);
}

const luaLsPath = process.argv[2];
if (!luaLsPath || !fs.existsSync(luaLsPath)) {
    console.error("Usage: tsx generate.ts <path to luaLs>");
    process.exit(1);
}

child_process.execSync(`"${luaLsPath}" --doc "${path.resolve("../../src/lua")}"`, {stdio: 'inherit'});
fs.copyFileSync(path.join(luaLsPath, "../../log/doc.json"), path.join(tempPath, 'doc.json'));

const json = JSON.parse(fs.readFileSync(path.join(tempPath, 'doc.json'), 'utf8')) as IObject[];
const skippedFields = new Set<string>(["__index"]);
const globalModules = new Set<string>(["init", "base"]);

class Entity {
    constructor(public name: string) {}
    content: Markdown = new Markdown();
    priority: number = 0;
}

class Module {
    md: Markdown;
    file?: SourceFile;
    classes: Entity[] = [];
    enums: Entity[] = [];
    title: string = "";
    hideMembers: boolean = false;

    constructor(public name: string, public isGlobal = false) {
        this.md = new Markdown();
    }

    static globalModule = new Module("index", true);
    static nameCache = new Map<string, Module>();

    static getByName(name: string) {
        if (globalModules.has(name)) return this.globalModule;

        if (!this.nameCache.has(name)) {
            const module = new Module(name);
            this.nameCache.set(name, module);
        }
        return this.nameCache.get(name)!;
    }

    static getModules() {
        return this.nameCache;
    }
}

const rootDir = path.resolve('../../src/lua/library');

const globalClassObj = {
    type: "type",
    defines: [
        {
            type: "doc.class",
            start: 0,
            finish: 0,
            file: url.pathToFileURL(path.resolve('../../src/lua/library/init.lua')).toString(),
        }
    ],
    name: "global",
    fields: [] as IField[],
    global: true,
} as IObject;

// Gather all global functions/variables
for (const obj of json) {
    const define = obj.defines[0];
    const isLibrary = isSubpath(rootDir, url.fileURLToPath(define.file));
    if (!isLibrary) continue;
    if (obj.type === "variable") {
        (obj.defines[0] as unknown as IField).name = obj.name;
        globalClassObj.fields!.push(obj.defines[0] as unknown as IField);
    }
}

json.push(globalClassObj);

for (const obj of json) {
    const define = obj.defines[0];
    const isLibrary = isSubpath(rootDir, url.fileURLToPath(define.file));
    if (!isLibrary) continue;

    const file = SourceFile.fromUrl(define.file);
    const module = Module.getByName(path.parse(file.path).name);
    if (!module.file) {
        if (module.name == "index") {
            module.title = "SuperMod Lua API";
            module.md.heading(1, module.title);
        } else {
            const displayTitle = file.docComments.findField('moduleTitle')?.value ?? module.name;
            module.title = `Модуль ${displayTitle}`;
            module.md.heading(1, module.title);

            const doc = file.docComments.findField('moduleDesc');
            if (doc) module.md.text(doc.value.trim());

            if (!file.docComments.findField('moduleNoImport')) {
                module.md.heading(2, `Импорт модуля`);
                module.md.text('Для импорта модуля используйте следующий код:');
                module.md.code(`local ${module.name} = require("${module.name}")`);
            }
        }

        module.file = file;
        module.hideMembers = !!file.docComments.findField('hideMembers');
    }

    if (module.hideMembers) continue;

    if (obj.type === "type" && obj.defines[0].type === "doc.class") {
        const entity = new Entity(obj.name);
        const docEntity = file.docComments.findByLoc(SourceLocation.fromInt(define.start));
        if (docEntity?.hasField("desc")) entity.content.text(docEntity.getField("desc"));
        if (docEntity?.hasField("priority")) entity.priority = parseInt(docEntity.getField("priority") ?? '0');
        const isMainClass = docEntity?.hasField("mainClass") || obj?.name === module.name;
        if (isMainClass) {
            entity.priority = Number.MAX_SAFE_INTEGER;
            obj.name = module.name;
            entity.content.heading(2, `Элементы модуля`);
        }
        else if (obj.global) {
            entity.priority = Number.MAX_SAFE_INTEGER;
            entity.content.heading(2, `Глобальные элементы`);
        } else {
            // Set class header only if it isn't main class
            entity.content.heading(2, `Класс \`${obj.name}\``);
        }

        const extendsObj = obj.defines[0].extends && Array.isArray(obj.defines[0].extends) && obj.defines[0].extends[0];
        if (extendsObj && extendsObj.type === 'doc.extends.name') {
            entity.content.text(`*Наследуется от \`${extendsObj.view}\`*`);
        }

        if (obj.fields) {
            const fields = obj.fields.sort((a, b) => {
                function getFieldOrder(field: IField) {
                    if (field.type === 'setfield' && field.extends.type === 'function') return 0;
                    if (field.type === 'setmethod' && field.extends.type === 'function') return 1;
                    if (field.type === 'doc.field' || field.type === 'setfield') return 2;
                    return 3;
                }

                return getFieldOrder(a) - getFieldOrder(b);
            });

            const fieldNameMap = Object.fromEntries(fields.map(field => [obj.name + '.' + field.name, field]));
            const aliasMap = new Map<string, string[]>();

            // Resolve aliases
            for (const field of fields) {
                if (field.type === 'setfield' && field.extends && field.extends.type == 'getfield') {
                    const start = SourceLocation.fromInt(field.extends.start);
                    const end = SourceLocation.fromInt(field.extends.finish);
                    const aliasToName = file.getRange(new SourceRange(start, end));
                    const aliasToObj = fieldNameMap[aliasToName];
                    if (!aliasToObj) continue;
                    const arr = aliasMap.get(aliasToObj.name) ?? [];
                    arr.push(obj.name + ':' + field.name);
                    aliasMap.set(aliasToObj.name, arr);
                    field.hidden = true;
                }
            }

            const enumMap = new Map<string, Entity>();

            // Resolve enums
            for (const obj of json) {
                if (obj.type === "type" && obj.defines[0].type === "doc.enum") {
                    const nestedFile = SourceFile.fromUrl(obj.defines[0].file);
                    if (file !== nestedFile) continue;

                    const entity = new Entity(obj.name);
                    entity.content.heading(3, `Энумерация \`${obj.name}\``);

                    const rows = [];
                    for (const obj of json) {
                        if (obj.type === "type" && obj.defines[0].type === "tablefield" && obj.name.startsWith(entity.name + '.')) {
                            const source = SourceLocation.fromInt(obj.defines[0].finish);
                            const range = new SourceRange(new SourceLocation(source.line, source.column), new SourceLocation(source.line + 1, 0));
                            const value = file.getRange(range).replace(/^\s*=\s*/, '').replace(/--.*$/, '').trim().replace(/,$/, '').trim();
                            rows.push([Markdown.codeline(obj.name, true), value, obj.rawdesc ?? '']);
                        }
                    }

                    const allNumbers = rows.every(row => !isNaN(row[1] as any));
                    if (allNumbers) rows.sort((a, b) => parseInt(a[1]) - parseInt(b[1]));

                    entity.content.table(['Имя', 'Значение', 'Описание'], rows.map(e => [e[0], Markdown.codeline(e[1], true), e[2]]));

                    enumMap.set(obj.name, entity);
                }
            }

            let allFields = fields;

            if (isMainClass && module.isGlobal) {
                allFields = [...fields];

                for (const obj of json) {
                    if (obj.type === "variable") {
                        allFields.push(obj as unknown as IField);
                    }
                }
            }

            for (const field of allFields) {
                if (field.hidden) continue;
                if (skippedFields.has(field.name)) continue;

                const fieldFile = field.file ? SourceFile.fromUrl(field.file) : file;

                const formatType = (type: string, tag: boolean = false) => {
                    return type
                        .replace(/\?$/, '')
                        .replace(/^\((.*?)\)$/g, '$1')
                        .replace(/\):(\w)/g, '): $1')
                        .split('|')
                        .map(t => Markdown.codeline(t, tag))
                        .join(' или ');
                }

                const serializeFunction = (entity: Entity, field: IField, method: boolean) => {
                    const extendsObj = field.extends;
                    if (extendsObj.type !== 'function') return;

                    const startLocation = SourceLocation.fromInt(field.start);
                    const functionDocEntity = fieldFile.docComments.findByLoc(new SourceLocation(startLocation.line - 1, 0));
                    if (functionDocEntity?.hasField('hidden')) return;
                    if (functionDocEntity?.hasField('private')) return;
                    if (functionDocEntity?.hasField('package')) return;
                    const isDeprecated = functionDocEntity?.hasField('deprecated') ?? false;
                    const isCtor = functionDocEntity?.hasField('constructor');

                    let name = field.name;
                    if (!obj.global) name  = obj.name + (method ? ":" : ".") + name;
                    entity.content.heading(3, Markdown.strikethrough(`${isCtor ? "Конструктор" : method ? "Метод" : "Функция"} \`${name}\``, false, isDeprecated) + (isDeprecated ? ' (устарела)' : ''));

                    if (isDeprecated) {
                        const message = functionDocEntity!.getField('deprecated');
                        entity.content.annotation(`Эта функция устарела и будет удалена в будущих версиях SuperMod.${message ? `\n${message}` : ''}`);
                    }

                    const args = extendsObj.args ? [...extendsObj.args] : [];
                    if (method) args.shift();

                    entity.content.text(field.rawdesc);

                    if (extendsObj.view) {
                        entity.content.heading(4, `Сигнатура`);
                        let signature = extendsObj.view.replace(/^\(method\) /, '');
                        if (isMainClass) {
                            signature = signature.replace(/^function (\w+)/, "function " + module.name);
                        }
                        entity.content.code(signature, 'lua');
                    }

                    if (args.length > 0) {
                        entity.content.heading(4, `Аргументы`);
                        entity.content.table(
                            ['Имя', 'Тип', 'Обязателен?', 'Описание'],
                            args.map(arg =>
                                [Markdown.codeline(arg.name ?? '...', true), formatType(arg.view, true), arg.view.endsWith('?') ? 'нет' : 'да', arg.rawdesc ?? ''])
                        );
                    }
                    if (extendsObj.returns && extendsObj.returns.length > 0) {
                        entity.content.heading(4, `Возвращает`);
                        const docFields = functionDocEntity?.getFields('return');
                        for (let i = 0; i < extendsObj.returns.length; i++){
                            const returnObj = extendsObj.returns[i];
                            const desc = (docFields?.[i] ?? '').match(/--\s*(.*?)$/)?.[1] ?? '';
                            const descText = desc ? ` - ${desc}` : '';
                            entity.content.text(`- ${formatType(returnObj.view)} ${descText}`);
                        }
                    }

                    const aliases = aliasMap.get(field.name);
                    if (aliases) {
                        entity.content.heading(4, `Алиасы`);
                        for (const alias of aliases) {
                            entity.content.text(`- \`${alias}\``);
                        }
                    }

                    const examples = functionDocEntity?.getFields('example');
                    if (examples && examples.length > 0) {
                        entity.content.heading(4, `Примеры`);
                        for (let j = 0; j < examples.length; j++) {
                            const example = examples[j];
                            entity.content.detailsBegin('Показать пример #' + (j + 1));
                            entity.content.code(example, 'lua');
                            entity.content.detailsEnd();
                        }
                    }

                }

                const name = obj.global ? field.name : obj.name + "." + field.name;
                if (field.type === "setmethod") {
                    serializeFunction(entity, field, true);
                } else if (field.type === "setfield" || field.type === "setglobal") {
                    if (field.extends?.type === 'function') {
                        serializeFunction(entity, field, false);
                    } else if (field.extends?.type === "doc.type") {

                        entity.content.heading(3, `Константа \`${name}\``);
                        entity.content.text(field.rawdesc);
                        entity.content.text('**Тип**: ' + formatType(field.extends.view));
                    } else if (field.extends?.type === "select" || field.extends?.type === 'table') {
                        const startLocation = SourceLocation.fromInt(field.start);
                        const fieldDocEntity = fieldFile.docComments.findByLoc(new SourceLocation(startLocation.line - 1, 0));
                        if (fieldDocEntity?.hasField('hidden')) continue;
                        if (fieldDocEntity?.hasField('private')) continue;
                        if (fieldDocEntity?.hasField('package')) continue;

                        if (enumMap.has(field.name)) {
                            entity.content.object(enumMap.get(field.name)!.content);
                        } else {
                            entity.content.heading(3, `Поле \`${name}\``);
                            entity.content.text(field.rawdesc);
                            entity.content.text('**Тип**: ' + formatType(fieldDocEntity?.getField('type') ?? field.extends.view));
                        }
                    }
                } else if (field.type === "doc.field") {
                    if (field.extends?.type === "doc.type") {
                        const startLocation = SourceLocation.fromInt(field.start);
                        const line = fieldFile.getLine(startLocation);
                        const isPrivate = line.includes('@field private');
                        if (isPrivate) continue;

                        entity.content.heading(3, `Поле \`${name}\``);
                        entity.content.text(field.rawdesc);
                        entity.content.text('**Тип**: ' + formatType(field.extends.view));
                    }
                }
            }
        }
        module.classes.push(entity);
    }
}

let toc = '## Lua\n\n';

const modules = [
    Module.globalModule,
    ...Array.from(Module.getModules().values())
];

for (const module of modules) {
    if (!module.title) continue;

    module.classes.sort((a, b) => b.priority - a.priority);

    const entities = [
        ...module.classes,
        ...module.enums
    ]

    for (let i = 0; i < entities.length; i++){
        const entity = entities[i];
        if (i > 0) module.md.separator();
        module.md.object(entity.content);
    }


    toc += `* [${module.title}](lua/${module.name}.md)\n`;
    fs.writeFileSync('../articles/lua/' + module.name + '.md', module.md.content);
}

const regex = /## Lua\s+.*?(\n##|$)/s;
let summaryFile = fs.readFileSync('../articles/SUMMARY.md', 'utf8');
if (!regex.test(summaryFile)) {
    summaryFile += '\n\n' + toc;
} else {
    summaryFile = summaryFile.replace(regex, toc + '$1');
}
fs.writeFileSync('../articles/SUMMARY.md', summaryFile);
