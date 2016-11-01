@xcopy "../../../Sources/EntityDef" "../../ServerData/EntityDef" /S /E /I /C /Y

@path %FV_PATH%/Externals/Redist/Win32;%FV_PATH%/SDK/Win32/Dll/DebugDll;%FV_PATH%/Externals/Redist/Win32/DebugDll;%GX_PATH%/SDK/Win32/Dll/DebugDll;%path%

@start "%~dp0FvMachined" "FvMachined.exe"
@ping localhost -n 5 > nul

@start "%~dp0FvDBManager" "FvDBManager.exe"
@ping localhost -n 10 > nul

@start "%~dp0FvCellAppManager" "FvCellAppManager.exe"
@ping localhost -n 10 > nul

@start "%~dp0FvBaseAppManager" "FvBaseAppManager.exe"
@ping localhost -n 10 > nul

@start "%~dp0FvBaseApp" "FvBaseApp.exe"
@ping localhost -n 10 > nul

@start "%~dp0FvCellApp" "FvCellApp.exe"
@ping localhost -n 10 > nul

@start "%~dp0FvLoginApp" "FvLoginApp.exe"