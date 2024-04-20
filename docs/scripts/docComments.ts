import { SourceRange, SourceLocation } from "./source";
import * as assert from "assert";

const DOC_COMMENT_PREFIX = '---';
const DOC_COMMENT_ENTITIES = ['class', 'filedoc'];
const LINE_SEP_REGEX = /\r\n|\r|\n/;

export class DocCommentField {
    constructor(public name: string, public value: string) {
    }
}

export class DocCommentEntity {
    public fields: DocCommentField[] = [];

    constructor(public type: string, public range: SourceRange, public content: string) {
        let lastField: DocCommentField | null = null;

        const lines = content.split(LINE_SEP_REGEX);
        for (let i = 0; i < lines.length; i++){
            const line = lines[i];
            assert.ok(line.startsWith(DOC_COMMENT_PREFIX), 'Line is not a doc comment');

            const res = line.match(/---\s*@(\S+)(?:\s+(.*))?$/);
            if (!res) {
                if (lastField) {
                    lastField.value += '\n' + line.replace(/^---\s*/, '')
                }
                continue;
            }

            const [, name, value] = res;
            lastField = new DocCommentField(name, value || '');
            this.fields.push(lastField);
        }
    }

    hasField(name: string) {
        return this.fields.some(f => f.name === name);
    }

    getField(name: string): any {
        return this.fields.find(f => f.name === name)?.value;
    }

    getFields(name: string): any {
        return this.fields.filter(f => f.name === name).map(f => f.value);
    }
}

export class DocComments {
    public entities: DocCommentEntity[] = [];

    findByLoc(loc: SourceLocation) {
        return this.entities.find(entity => entity.range.isInside(loc));
    }

    findField(name: string) {
        return this.entities.find(e => e.fields.some(f => f.name === name))?.fields.find(f => f.name === name);
    }

    constructor(fileContent: string) {
        const lines = fileContent.split(LINE_SEP_REGEX);

        let entityType: string | null = null;
        let entityContent: string = '';
        let entityStart: SourceLocation | null = null;

        for (let i = 0; i < lines.length; i++) {
            const line = lines[i];
            if (!line.startsWith('---')) {
                if (entityType != null) {
                    const entityEnd = new SourceLocation(i - 1, lines[i - 1].length);
                    this.entities.push(new DocCommentEntity(entityType, new SourceRange(entityStart!, entityEnd), entityContent));
                    entityType = null;
                    entityContent = '';
                    entityStart = null;
                }
                continue;
            }

            const tag = line.match(/---\s*@(\S+)/)?.[1] ?? 'unknown';
            if (DOC_COMMENT_ENTITIES.includes(tag) || entityType == null) {
                if (entityType != null) {
                    const entityEnd = new SourceLocation(i - 1, lines[i - 1].length);
                    this.entities.push(new DocCommentEntity(entityType, new SourceRange(entityStart!, entityEnd), entityContent));
                }

                entityType = tag;
                entityContent = line;
                entityStart = new SourceLocation(i, 0);
            } else {
                entityContent += '\n' + line;
            }
        }

        if (entityType != null) {
            const entityEnd = new SourceLocation(lines.length - 1, lines[lines.length - 1].length);
            this.entities.push(new DocCommentEntity(entityType, new SourceRange(entityStart!, entityEnd), entityContent));
        }
    }
}