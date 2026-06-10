@echo off
REM Wrapper to call the PowerShell build script

set "EXERCISE=%~1"
powershell.exe -NoProfile -ExecutionPolicy Bypass -File "%~dp0build.ps1" "%EXERCISE%"
exit /b %ERRORLEVEL%
