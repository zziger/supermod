// This script parses header file for COM interfaces
const fs = require('fs');

const path = "path/to/file.h";
const content = fs.readFileSync(path, 'utf8');

// Find all IIDs
const ids = new Map();
{
    const matches = content.matchAll(/DEFINE_GUID\(IID_(.*?),\s*(.*?)\)/g);

    for (const match of matches) {
        const numbers = match[2].split(/[,\s]+/g).map((e, i) => parseInt(e).toString(16).padStart(i === 0 ? 8 : i < 3 ? 4 : 2, '0'));
        if (numbers.length !== 11) throw new Error("Invalid number count for ID entry " + match[1]);
        const id = `${numbers[0]}-${numbers[1]}-${numbers[2]}-${numbers[3]}${numbers[4]}-${numbers.slice(5).join('')}`;
        if (id.length !== 36) throw new Error("Invalid ID length for entry " + match[1]);
        if (ids.has(match[1])) throw new Error("Duplicate entry " + match[1]);
        ids.set(match[1], id);
    }
}


// Find all interfaces
const interfaceOrder = [];
const interfaces = new Map();

{
    const matches = content.matchAll(/DECLARE_INTERFACE_?\((?<name>.*?)(?:, (?<parent>.*?))?\).*?\{/gs);

    for (const match of matches) {
        let interfaceDef = {
            name: match.groups.name,
            inherits: match.groups.parent ?? null,
            iid: ids.get(match.groups.name)
        };
        if (!interfaceDef.iid) throw new Error(`Interface ${interfaceDef.name} does not have an IID`);

        const startIndex = match.index + match[0].length;
        let endIndex;

        let braces = 0;
        for (endIndex = startIndex; endIndex < content.length; endIndex++) {
            if (content[endIndex] === '{') braces++;
            else if (content[endIndex] === '}') {
                if (braces > 0) braces--;
                else break;
            }
        }
        if (content[endIndex] !== '}') throw new Error('Unexpected EOF while parsing ' + match.groups.name);

        const innerContent = content.slice(startIndex, endIndex);

        // Find all methods
        {
            const innerMatches = innerContent.matchAll(/STDMETHOD(?:_\s*\(\s*(?<ret>.*?),\s*|\s*\(\s*)(?<name>.*?)\s*\)\(\s*THIS_?\s*(?<arg>.*?)\)/gs);
            const methods = [];

            for (const innerMatch of innerMatches) {
                methods.push({
                    name: innerMatch.groups.name,
                    ret: innerMatch.groups.ret ?? null,
                    args: innerMatch.groups.arg.replace(/[\r\n\s]+/g, ' ') || null,
                    inherited: false
                });
            }

            interfaceDef.methods = methods;
        }

        interfaceOrder.push(interfaceDef.name);
        interfaces.set(interfaceDef.name, interfaceDef);
    }
}

const wellKnown = new Map()
wellKnown.set('IUnknown', {
    name: 'IUnknown',
    iid: '00000000-0000-0000-C000000000000046',
    methods: [
        {
            name: 'QueryInterface',
            ret: null,
            args: 'REFIID iid, LPVOID *ppv'
        },
        {
            name: 'AddRef',
            ret: 'ULONG',
            args: null
        },
        {
            name: 'Release',
            ret: 'ULONG',
            args: null
        }
    ]
});

// Mark inherited methods
for (const interfaceDef of interfaces.values()) {
    if (!interfaceDef.inherits) continue;

    const parent = interfaces.get(interfaceDef.inherits) || wellKnown.get(interfaceDef.inherits);
    if (!parent) throw new Error(`Interface ${interfaceDef.name} has unknown parent ${interfaceDef.inherits}`);
    for (let i = 0; i < parent.methods.length; i++) {
        if (parent.methods[i].name !== interfaceDef.methods[i].name) throw new Error(`Interface ${interfaceDef.name} mismatches method ${i} with ${interfaceDef.inherits}`);
        interfaceDef.methods[i].inherited = true;
    }
}

let mainOutput = '';
for (const interfaceName of interfaceOrder) {
    const interfaceDef = interfaces.get(interfaceName);
    let output = `{ '${interfaceDef.name}', `;
    if (interfaceDef.inherits) output += `inherits = '${interfaceDef.inherits}', `;
    output += '\nmethods = {\n'

    for (const method of interfaceDef.methods) {
        if (method.inherited) continue;
        output += `{ '${method.name}'`;
        if (method.args) output += `, '${method.args}'`;
        if (method.ret) output += `, ret = '${method.ret}'`;
        output += ' },\n';
    }
    output += '},\n';
    output += `iid = '${interfaceDef.iid}'\n},`;

    mainOutput += output + '\n';
}

fs.writeFileSync('output.txt', mainOutput);