// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include <windows.h>
#include <filesystem>
#include "DLCLoader.h"
#include "packaging.generated.h"

class UAssetImportTask;
class UFactory;
class FJsonObject;
/**
 * 
 */


UCLASS()
class ARCGISTEST_API Upackaging : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "importing")
	static UAssetImportTask* createImportTask(FString sourcePath, FString destinationPath, bool& bOutSuccess, FString& OutInfoMessage);

	UFUNCTION(BlueprintCallable, Category = "importing")
	static UObject* ProcessImportTask(UAssetImportTask* importTask, bool& bOutSuccess, FString& OutInfoMessage);

	UFUNCTION(BlueprintCallable, Category = "importing")
	static UObject* importAsset(FString sourcePath, FString destinationPath, bool& bOutSuccess, FString& OutInfoMessage);

	UFUNCTION(BlueprintCallable, Category = "importing")
	static UObject* getPath(FString sourcePath, FString destinationPath, bool& bOutSuccess, FString& OutInfoMessage);

	UFUNCTION(BlueprintCallable, Category = "packaging")
	static void callPAK();

	UFUNCTION(BlueprintCallable, Category = "packaging")
	static FString getSoftwareRoute();

	static TSharedPtr<FJsonObject> ReadJson(FString JsonFilePath, bool& bOutSuccess, FString& OutInfoMessage);

	static void WriteJson(FString JsonFilePath, TSharedPtr<FJsonObject> JsonObject, bool& bOutSuccess, FString& OutInfoMessage);

	UFUNCTION(BlueprintCallable, Category = "jsonWriting")
	static FinputStruct ReadStructFromJsonFile(FString filepath, bool& bOutSuccess, FString& OutInfoMessage);

	UFUNCTION(BlueprintCallable, Category = "jsonWriting")
	static FString ReadStringFromFile(FString filepath, bool& bOutSuccess, FString& OutInfoMessage);

	UFUNCTION(BlueprintCallable, Category = "jsonWriting")
	static void WriteStringToFile(FString filepath, FString inputString, bool& bOutSuccess, FString& OutInfoMessage);

	UFUNCTION(BlueprintCallable, Category = "jsonWriting")
	static void WriteStructFromJsonFile(FString filepath, FinputStruct inputStruct, bool& bOutSuccess, FString& OutInfoMessage);
};
