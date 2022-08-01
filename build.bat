cmake -BBUILD . -A Win32
cmake --build BUILD --config Release
IF EXIST BUILD\Release\msimg32.dll DEL /f BUILD\Release\msimg32.dll
copy BUILD\Release\supercow-mod.dll BUILD\Release\msimg32.dll