param (
    [string]$Exercise = "."
)

Push-Location $Exercise
try {
    mingw32-make SHELL=cmd.exe test
} finally {
    Remove-Item -Path tests.out -ErrorAction SilentlyContinue
    Pop-Location
}
