param (
    [Parameter(Position=0, Mandatory=$false)]
    [string]$ExerciseName
)

$OriginalDir = Get-Location

# If an exercise name is provided, look for it in the same directory as this script.
# Otherwise, assume we are currently inside the exercise directory.
if ([string]::IsNullOrWhiteSpace($ExerciseName)) {
    $ExerciseDir = $OriginalDir.Path
    $ExerciseName = Split-Path $ExerciseDir -Leaf
} else {
    $ExerciseDir = Join-Path $PSScriptRoot $ExerciseName
}

if (-Not (Test-Path "$ExerciseDir\CMakeLists.txt")) {
    Write-Host "Error: Could not find CMakeLists.txt in $ExerciseDir.`nMake sure you are inside an exercise directory or provide a valid exercise name." -ForegroundColor Red
    exit 1
}

Write-Host "=============================================" -ForegroundColor Cyan
Write-Host " Building and Testing: $ExerciseName" -ForegroundColor Cyan
Write-Host "=============================================" -ForegroundColor Cyan

Set-Location $ExerciseDir

try {
    # 1. Configure
    Write-Host "`n[1/2] Configuring CMake..." -ForegroundColor Yellow
    cmake -DEXERCISM_RUN_ALL_TESTS=1 -S . -B build
    if ($LASTEXITCODE -ne 0) {
        Write-Host "CMake configuration failed." -ForegroundColor Red
        exit $LASTEXITCODE
    }

    # 2. Build and Test
    Write-Host "`n[2/2] Building project and running tests..." -ForegroundColor Yellow
    cmake --build build
    if ($LASTEXITCODE -ne 0) {
        Write-Host "Build or tests failed." -ForegroundColor Red
        exit $LASTEXITCODE
    }

    Write-Host "`nSuccessfully built and all tests passed!" -ForegroundColor Green
} finally {
    Set-Location $OriginalDir
}
