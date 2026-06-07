@echo off
setlocal
if not "%~1"=="" pushd "%~1"
mingw32-make SHELL=cmd.exe test
if exist tests.out del /q tests.out
if not "%~1"=="" popd
endlocal
