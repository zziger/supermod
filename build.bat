cmake -BBUILD . -A Win32 -DVERSION="%1"
cmake --build BUILD --config RelWithDebInfo