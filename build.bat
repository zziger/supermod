cmake -BBUILD . -A Win32 -DVERSION="%1"
cmake --build BUILD --config Release
IF EXIST BUILD\Release\dinput8.dll DEL /f BUILD\Release\dinput8.dll
copy BUILD\Release\supercow-mod.dll BUILD\Release\dinput8.dll