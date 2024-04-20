export class SourceLocation {
    constructor(public line: number, public column: number) {
    }

    static fromInt(int: number) {
        return new SourceLocation(Math.floor(int / 10000), int % 10000);
    }
}

export class SourceRange {
    constructor(public start: SourceLocation, public end: SourceLocation) {
    }

    // inclusive
    public isInside(loc: SourceLocation) {
        return this.start.line <= loc.line && loc.line <= this.end.line &&
            (this.start.line !== loc.line || this.start.column <= loc.column) &&
            (this.end.line !== loc.line || this.end.column >= loc.column);
    }
}