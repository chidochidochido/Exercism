@echo off
mingw32-make SHELL=cmd.exe test
if exist tests.out del /q tests.out
