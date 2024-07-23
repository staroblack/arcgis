echo "params : UnrealPak.exe folder path, output pak path, source folder path"
echo "example : pak.bat D:\Unreal5\UE_5.0\Engine\Binaries\Win64 D:\output\test.pak D:\test\

cd %1
UnrealPak.exe %2 %3
