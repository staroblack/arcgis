// Fill out your copyright notice in the Description page of Project Settings.


#include "readJson.h"
#include "Serialization/JsonSerializer.h"
#include "JsonObjectConverter.h"

FString UreadJson::ReadStringFromFile(FString filepath, bool& bOutSuccess, FString& OutInfoMessage) {
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

TSharedPtr<FJsonObject> UreadJson::ReadJson(FString JsonFilePath, bool& bOutSuccess, FString& OutInfoMessage) {
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

FinputStruct UreadJson::ReadStructFromJsonFile(FString filepath, bool& bOutSuccess, FString& OutInfoMessage) {
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

void UreadJson::WriteStructFromJsonFile(FString filepath, FinputStruct inputStruct, bool& bOutSuccess, FString& OutInfoMessage) {
	TSharedPtr<FJsonObject> JsonObject = FJsonObjectConverter::UStructToJsonObject(inputStruct);
	if (JsonObject == nullptr)
	{
		bOutSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("write failed"));
		return;
	}

	UreadJson::WriteJson(filepath, JsonObject, bOutSuccess, OutInfoMessage);
}

void UreadJson::WriteJson(FString JsonFilePath, TSharedPtr<FJsonObject> JsonObject, bool& bOutSuccess, FString& OutInfoMessage) {
	FString JsonString;

	if (!FJsonSerializer::Serialize(JsonObject.ToSharedRef(), TJsonWriterFactory<>::Create(&JsonString, 0))) {
		bOutSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("write failed"));
		return;
	}

	UreadJson::WriteStringToFile(JsonFilePath, JsonString, bOutSuccess, OutInfoMessage);

	if (!bOutSuccess) {
		return;
	}

	bOutSuccess = true;
	OutInfoMessage = FString::Printf(TEXT("Write Struct Json Succeeded"));
	return;
}

void UreadJson::WriteStringToFile(FString filepath, FString inputString, bool& bOutSuccess, FString& OutInfoMessage) {
	if (!FFileHelper::SaveStringToFile(inputString, *filepath))
	{
		bOutSuccess = false;
		return;
	}

	bOutSuccess = true;
	OutInfoMessage = FString::Printf(TEXT("write string to file Succeeded - '%s'"), *filepath);
	return;
}