import fs from "fs";

export class Markdown {
    public content: string = '';

    heading(level: number, text: string) {
        this.content += `${'#'.repeat(level)} ${text}\n\n`;
        return this;
    }

    text(text: string) {
        if (!text) return this;
        this.content += `${Markdown.resolveVariables(text.replace(/\r|\n|\r\n/g, '<br/>\n'))}\n\n`;
        return this;
    }

    quote(text: string) {
        this.content += `> ${text.replace(/\r|\n|\r\n/g, '<br/>\n> ')}\n\n`;
        return this;
    }

    annotation(text: string, type = 'warning') {
        this.content += `{% hint style="warning" %}\n${text.replace(/\r|\n|\r\n/g, '<br/>\n')}\n{% endhint %}\n\n`;
        return this;
    }

    code(text: string, lang = 'lua') {
        this.content += `\`\`\`${lang}\n${text}\n\`\`\`\n\n`;
        return this;
    }

    object(obj: Markdown) {
        this.content += obj.content;
        return this;
    }

    separator() {
        this.content += '---\n\n';
    }

    detailsBegin(summary: string) {
        this.content += `<details>\n<summary>${summary}</summary>\n\n`;
        return this;
    }

    detailsEnd() {
        this.content += '</details>\n\n';
        return this;
    }

    table(headers: string[], rows: string[][], removeEmpty = true) {
        if (removeEmpty) {
            const emptyColumns = new Set<number>();
            for (let i = 0; i < headers.length; i++) {
                if (rows.every(row => !row[i])) {
                    emptyColumns.add(i);
                }
            }
            headers = headers.filter((_, i) => !emptyColumns.has(i));
            rows = rows.map(row => row.filter((_, i) => !emptyColumns.has(i)));
        }

        this.content += '<table>\n  ';
        if (headers.length > 0) {
            this.content += '<thead>\n    <tr>\n';
            for (const header of headers) {
                this.content += `      <th>${header}</th>\n`;
            }
            this.content += '    </tr>\n  </thead>\n';
        }
        this.content += '  <tbody>\n';
        for (const row of rows) {
            this.content += '    <tr>\n';
            for (const cell of row) {
                this.content += `      <td>${cell}</td>\n`;
            }
            this.content += '    </tr>\n';
        }
        this.content += '  </tbody>\n</table>\n\n';
        return this;
    }

    static codeline(text: string, tag = false) {
        if (!text) return '';

        if (tag) return `<code>${text.replace(/</g, '&lt;')}</code>`;
        return `\`${text}\``;
    }

    static strikethrough(text: string, tag = false, value: boolean = true) {
        if (!text) return '';
        if (!value) return text;

        if (tag) return `<del>${text.replace(/</g, '&lt;')}</del>`;
        return `~~${text}~~`;
    }

    static resolveVariables(str: string) {
        return str.replace(/\$snippet:(\w+)/g, (match, name) => {
            return fs.readFileSync(`../snippets/${name}.md`, 'utf8');
        })
    }
}