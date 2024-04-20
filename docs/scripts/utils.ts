import * as path from "node:path";

export function isSubpath(parent: string, dir: string) {
    const relative = path.relative(parent, dir);
    return relative && !relative.startsWith('..') && !path.isAbsolute(relative);
}
