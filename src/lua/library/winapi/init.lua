
local ffi = require 'ffi'

local GUID = ffi.typeof 'GUID';

local mswindows = setmetatable({
	RECT = ffi.typeof 'RECT';
	GUID = GUID;
	POINT = ffi.typeof 'POINT';
	WNDCLASSEXA = ffi.typeof 'WNDCLASSEXA';
	MSG = ffi.typeof 'MSG';
	user32 = ffi.load 'user32';
	kernel32 = ffi.load 'kernel32';
	comctl32 = ffi.load 'comctl32';
	ole32 = ffi.load 'ole32';
	wstring = function(ptr, len)
		local bufSize = ffi.C.MultiByteToWideChar(65001, 0, ptr, len or -1, nil, 0, nil, nil)
		local buf = ffi.new('char[?]', bufSize)
		ffi.C.MultiByteToWideChar(65001, 0, ptr, len or -1, buf, bufSize, nil, nil)
		return ffi.string(buf, bufSize)
	end;
	guid = function(v)
		local a, b, c, d1, d2, d3, d4, d5, d6, d7, d8 = string.match(v,
			'^{?(%x%x%x%x%x%x%x%x)%-?(%x%x%x%x)%-?(%x%x%x%x)%-?(%x%x)(%x%x)%-?(%x%x)(%x%x)(%x%x)(%x%x)(%x%x)(%x%x)}?$')
		if not a then
			error('invalid guid string')
		end
		return GUID(tonumber(a, 16), tonumber(b, 16), tonumber(c, 16),
			{tonumber(d1, 16), tonumber(d2, 16), tonumber(d3, 16), tonumber(d4, 16),
			tonumber(d5, 16), tonumber(d6, 16), tonumber(d7, 16), tonumber(d8, 16)})
	end;
}, {
	__index = function(self, key)  return ffi.C[key];  end
})

return mswindows