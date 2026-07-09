cd C:\emsdk
call emsdk_env.bat

cd C:\Users\naqee\Desktop\C++\raylib\gamejam

emcc -o index.html main.cpp -Os -Wall -I. -I "C:\raylib\raylib\src" "C:\raylib\raylib\src\libraylib.web.a"  -s USE_GLFW=3 -s ASYNCIFY  --shell-file "C:\raylib\raylib\src\minshell.html" -DPLATFORM_WEB

python -m http.server 6767