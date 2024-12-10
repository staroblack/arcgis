// Fill out your copyright notice in the Description page of Project Settings.


#include "packaging.h"
#include "Editor\UnrealEd\Public\AssetImportTask.h"
#include "Developer\AssetTools\Public\AssetToolsModule.h"
#include "Serialization/JsonSerializer.h"
#include "JsonObjectConverter.h"
#include <filesystem>
#include <string>


UAssetImportTask* Upackaging::createImportTask(FString sourcePath, FString destinationPath, bool& bOutSuccess, FString& OutInfoMessage) {
	UAssetImportTask* RetTask = NewObject<UAssetImportTask>();

	RetTask->Filename = sourcePath;
	RetTask->DestinationPath = FPaths::GetPath(destinationPath);
	RetTask->DestinationName = FPaths::GetCleanFilename(destinationPath);

	RetTask->bSave = false;
	RetTask->bAutomated = true;
	RetTask->bAsync = false;
	RetTask->bReplaceExisting = true;
	RetTask->bReplaceExistingSettings = false;

	bOutSuccess = true;
	return RetTask;
}

UObject* Upackaging::ProcessImportTask(UAssetImportTask* importTask, bool& bOutSuccess, FString& OutInfoMessage) {
	if (importTask == nullptr)
	{
		bOutSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("process failed"));
		return nullptr;
	}

	FAssetToolsModule* assetTools = FModuleManager::LoadModulePtr<FAssetToolsModule>("AssetTools");

	assetTools->Get().ImportAssetTasks({ importTask });

	if (importTask->GetObjects().Num() == 0) {
		bOutSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("empty"));
		return nullptr;
	}

	UObject* importedAsset = StaticLoadObject(UObject::StaticClass(), nullptr, *FPaths::Combine(importTask->DestinationPath, importTask->DestinationName));

	bOutSuccess = true;
	OutInfoMessage = FString::Printf(TEXT("process success"));
	return importedAsset;
}

UObject* Upackaging::getPath(FString sourcePath, FString destinationPath, bool& bOutSuccess, FString& OutInfoMessage) {

	UObject* result = importAsset(sourcePath, destinationPath, bOutSuccess, OutInfoMessage);

	/*
	for (const auto& entry : std::filesystem::directory_iterator(std::string(TCHAR_TO_UTF8(*sourcePath)))) {
		std::string import_path{ entry.path().string() };
		importAsset(UTF8_TO_TCHAR(import_path.c_str()), destinationPath, bOutSuccess, OutInfoMessage);

	}
	*/
	return result;
}

UObject* Upackaging::importAsset(FString sourcePath, FString destinationPath, bool& bOutSuccess, FString& OutInfoMessage) {
	UAssetImportTask* task = createImportTask(sourcePath, destinationPath, bOutSuccess, OutInfoMessage);
	if (!bOutSuccess) {
		return nullptr;
	}

	UObject* RetAsset = ProcessImportTask(task, bOutSuccess, OutInfoMessage);
	if (!bOutSuccess) {
		return nullptr;
	}
	bOutSuccess = true;
	OutInfoMessage = FString::Printf(TEXT("success"));
	return RetAsset;
}

void Upackaging::callPAK() {

	//system("D:");
	FString pakPath = FPaths::ProjectDir();
	IFileManager& fileManager = IFileManager::Get();
	FString absFolderPath = fileManager.ConvertToAbsolutePathForExternalAppForRead(*pakPath);
	std::string path = std::string(TCHAR_TO_UTF8(*absFolderPath));
	std::string instruction = "cd " + path + "unrealPak";
	//system(instruction.c_str());
	GEngine->AddOnScreenDebugMessage(-1, 15000.0f, FColor::Red, UTF8_TO_TCHAR(instruction.c_str()));
	//system("UnrealPak.exe");
	instruction = "unrealpak " + path + "testpak/test.pak -create=" + path + "Content/Test";
	GEngine->AddOnScreenDebugMessage(-1, 15000.0f, FColor::Red, UTF8_TO_TCHAR(instruction.c_str()));
	//system("unrealpak D:/test/test.pak -create=D:/graphic/cook/Saved/Cooked/Windows/cook/Content/cook");
	//system(instruction.c_str());
	return;
}

FString Upackaging::ReadStringFromFile(FString filepath, bool& bOutSuccess, FString& OutInfoMessage) {
	// Check if the file exists
	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*filepath))
	{
		bOutSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("Read String From File Failed - File doesn't exist - '%s'"), *filepath);
		return "";
	}

	FString RetString = "";

	// Try to read the file. Output goes in RetString
	if (!FFileHelper::LoadFileToString(RetString, *filepath))
	{
		bOutSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("Read String From File Failed - Was not able to read file. Is this a text file? - '%s'"), *filepath);
		return "";
	}

	bOutSuccess = true;
	OutInfoMessage = FString::Printf(TEXT("Read String From File Succeeded - '%s'"), *filepath);
	return RetString;
}

TSharedPtr<FJsonObject> Upackaging::ReadJson(FString JsonFilePath, bool& bOutSuccess, FString& OutInfoMessage) {
	FString JsonString = ReadStringFromFile(JsonFilePath, bOutSuccess, OutInfoMessage);
	if (!bOutSuccess) {
		return nullptr;
	}

	TSharedPtr<FJsonObject> RetJsonObject;

	if (!FJsonSerializer::Deserialize(TJsonReaderFactory<>::Create(JsonString), RetJsonObject)) {
		bOutSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("Read Json failed - Was not able to deserialize the json string. Is it the right format? - '%s'"), *JsonString);
		return nullptr;
	}

	bOutSuccess = true;
	OutInfoMessage = FString::Printf(TEXT("Read Json Succeeded - '%s'"), *JsonFilePath);
	return RetJsonObject;
}

FinputStruct Upackaging::ReadStructFromJsonFile(FString filepath, bool& bOutSuccess, FString& OutInfoMessage) {
	// Check if the file exists
	TSharedPtr<FJsonObject> JsonObject = ReadJson(filepath, bOutSuccess, OutInfoMessage);
	if (!bOutSuccess)
	{
		return FinputStruct();
	}

	FinputStruct RetStruct;

	// Try to read the file. Output goes in RetString
	if (!FJsonObjectConverter::JsonObjectToUStruct<FinputStruct>(JsonObject.ToSharedRef(), &RetStruct))
	{
		bOutSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("Read String From File Failed - Was not able to read file. Is this a text file? - '%s'"), *filepath);
		return FinputStruct();
	}

	bOutSuccess = true;
	OutInfoMessage = FString::Printf(TEXT("Read Struct Json Succeeded - '%s'"), *filepath);
	return RetStruct;
}

void Upackaging::WriteStructFromJsonFile(FString filepath, FinputStruct inputStruct, bool& bOutSuccess, FString& OutInfoMessage) {
	GEngine->AddOnScreenDebugMessage(-1, 150.0f, FColor::Green, "in");
	TSharedPtr<FJsonObject> JsonObject = FJsonObjectConverter::UStructToJsonObject(inputStruct);
	if (JsonObject == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 150.0f, FColor::Green, "in2");
		bOutSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("write failed"));
		return;
	}

	Upackaging::WriteJson(filepath, JsonObject, bOutSuccess, OutInfoMessage);
}

void Upackaging::WriteJson(FString JsonFilePath, TSharedPtr<FJsonObject> JsonObject, bool& bOutSuccess, FString& OutInfoMessage) {
	FString JsonString;
	GEngine->AddOnScreenDebugMessage(-1, 150.0f, FColor::Green, "in3");
	if (!FJsonSerializer::Serialize(JsonObject.ToSharedRef(), TJsonWriterFactory<>::Create(&JsonString, 0))) {
		GEngine->AddOnScreenDebugMessage(-1, 150.0f, FColor::Green, "in4");
		bOutSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("write failed"));
		return;
	}

	Upackaging::WriteStringToFile(JsonFilePath, JsonString, bOutSuccess, OutInfoMessage);

	if (!bOutSuccess) {
		return;
	}

	bOutSuccess = true;
	OutInfoMessage = FString::Printf(TEXT("Write Struct Json Succeeded"));
	return;
}

void Upackaging::WriteStringToFile(FString filepath, FString inputString, bool& bOutSuccess, FString& OutInfoMessage) {
	GEngine->AddOnScreenDebugMessage(-1, 150.0f, FColor::Green, "in5");
	if (!FFileHelper::SaveStringToFile(inputString, *filepath))
	{
		GEngine->AddOnScreenDebugMessage(-1, 150.0f, FColor::Green, "in6");
		bOutSuccess = false;
		return;
	}

	bOutSuccess = true;
	OutInfoMessage = FString::Printf(TEXT("write string to file Succeeded - '%s'"), *filepath);
	return;
}


FString Upackaging::getSoftwareRoute() {
	FString pakPath = FPaths::ProjectDir();
	IFileManager& fileManager = IFileManager::Get();
	FString absFolderPath = fileManager.ConvertToAbsolutePathForExternalAppForRead(*pakPath);
	return absFolderPath;
}
