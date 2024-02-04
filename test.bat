xmake f -y -m release -a x86
xmake build -y test || exit /b 1
xmake run -y test