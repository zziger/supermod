import * as url from 'url';
import * as fs from 'fs';
import {DocComments} from "./docComments";
import {SourceLocation, SourceRange} from "./source";

export class SourceFile {
    public path: string;
    public content: string = '';
    public lines: string[] = [];
    public docComments: DocComments;

    constructor(public fileUrl: string) {
        this.path = url.fileURLToPath(fileUrl);
        this.content = fs.readFileSync(this.path, 'utf8');
        this.lines = this.content.split(/\r\n|\r|\n/);
        this.docComments = new DocComments(this.content);
    }

    getRange(range: SourceRange) {
        const start = range.start;
        const end = range.end;
        const startLine = this.lines[start.line];
        const endLine = this.lines[end.line];
        if (!startLine || !endLine) throw new Error('Can\'t read range ' + JSON.stringify(range) + ' from file ' + this.path);
        if (start.line === end.line)
            return startLine.substring(start.column, end.column);
        return startLine.substring(start.column) + this.lines.slice(start.line + 1, end.line).join('\n') + endLine.substring(0, end.column);
    }

    getLine(loc: SourceLocation) {
        return this.lines[loc.line];
    }

    static urlCache = new Map<string, SourceFile>();
    static fromUrl(fileUrl: string): SourceFile {
        if (!this.urlCache.has(fileUrl)) {
            this.urlCache.set(fileUrl, new SourceFile(fileUrl));
        }
        return this.urlCache.get(fileUrl)!;
    }
}