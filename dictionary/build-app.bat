set BAT_BASE_PATH=%~dp0
set PRJ_BASE_PATH=%BAT_BASE_PATH% 
set BIN_PATH=%BAT_BASE_PATH%\bin
set APP_PATH=%BAT_BASE_PATH%\app
set CORE_PATH=%BAT_BASE_PATH%\core

MD %BIN_PATH%
clang -I%APP_PATH%\include -I%CORE_PATH%\include -o %BIN_PATH%\app.exe %APP_PATH%\src\*.c -L%BIN_PATH%  -l dictionary
