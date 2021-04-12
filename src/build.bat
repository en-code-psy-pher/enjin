@echo off

mkdir ..\build
pushd ..\build

set CommonCompilerFlags=/EHsc -FC -Zi /MD
set CommonLinkerFlags= /NODEFAULTLIB:MSVCRTD -incremental:no -opt:ref user32.lib kernel32.lib advapi32.lib gdi32.lib winmm.lib shell32.lib opengl32.lib glew32.lib glfw3.lib SOIL.lib assimp.lib 

cl -I..\src\includes %CommonCompilerFlags% -D_CRT_SECURE_NO_WARNINGS ..\src\core\*.cpp ..\src\renderer\*.cpp ..\src\main.cpp %CommonDependencies% /link /LIBPATH:"..\\src\\libs" %CommonLinkerFlags%

rem cl -I..\src\includes %CommonCompilerFlags% -D_CRT_SECURE_NO_WARNINGS ..\src\core\*.cpp ..\src\renderer\*.cpp ..\src\main.cpp /link %CommonLinkerFlags%

popd

