@if not "%MINGW_ROOT%" == "" (@set "PATH=%PATH%;%MINGW_ROOT%")

cd .

chcp 1252

if "%1"=="" ("C:\PROGRA~1\MATLAB\R2020A~1\bin\win64\gmake"  -f main.mk all) else ("C:\PROGRA~1\MATLAB\R2020A~1\bin\win64\gmake"  -f main.mk %1)
@if errorlevel 1 goto error_exit

exit 0

:error_exit
echo The make command returned an error of %errorlevel%
exit 1
