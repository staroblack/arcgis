@echo off
REM Define source and destination directories
SET source_testpak="D:\graphic\arcgisTest\arcgis\testpak"
SET source_grid="D:\graphic\arcgisTest\arcgis\StreamDatas\grid11_collection"
SET destination="C:\Users\User\Desktop\Windows\arcgisTest"
SET source_dll="D:\graphic\arcgisTest\arcgis\Plugins\CustomOctreePlugin\Source\CustomOctreePlugin\thirdparty\dll"
SET destination_dll="C:\Users\User\Desktop\Windows\arcgisTest\Binaries\Win64"

REM Check and copy the 'testpak' folder
IF NOT EXIST %source_testpak% (
    echo Source folder 'testpak' does not exist.
) ELSE (
    xcopy /E /I /Q %source_testpak% %destination%\testpak
    IF %ERRORLEVEL% EQU 0 (
        echo 'testpak' copied successfully.
    ) ELSE (
        echo Failed to copy 'testpak'.
    )
)

REM Create 'StreamDatas' folder in the destination if it doesn't exist
IF NOT EXIST "%destination%\StreamDatas" (
    mkdir "%destination%\StreamDatas"
)

REM Check and copy the 'grid11_collection' folder
IF NOT EXIST %source_grid% (
    echo Source folder 'grid11_collection' does not exist.
) ELSE (
    xcopy /E /I /Q %source_grid% "%destination%\StreamDatas\grid11_collection"
    IF %ERRORLEVEL% EQU 0 (
        echo 'grid11_collection' copied successfully to 'StreamDatas'.
    ) ELSE (
        echo Failed to copy 'grid11_collection'.
    )
)

REM Check and move DLL files to the specified directory
IF NOT EXIST %source_dll% (
    echo Source DLL folder does not exist.
) ELSE (
    move "%source_dll%\*" %destination_dll%
    IF %ERRORLEVEL% EQU 0 (
        echo DLL files moved successfully to '%destination_dll%'.
    ) ELSE (
        echo Failed to move DLL files.
    )
)

pause
