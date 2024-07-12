// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "readJson.generated.h"

class FJsonObject;

USTRUCT(BlueprintType, Category = "readJson")
struct FinputStruct
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "readJson")
		FString caseName = "case_name";
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "readJson")
		FString madeUnit = "made_Unit";
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "readJson")
		FString madePerson = "made_person";
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "readJson")
		FString uploadDate = "upload_date";
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "readJson")
		FString modelCity = "model_city";
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "readJson")
		float lat = 123.0f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "readJson")
		float lon = 456.0f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "readJson")
		FString quote = "quote";
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "readJson")
		FString simArea = "sim_area";
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "readJson")
		FString loadInData = "load_in_data";
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "readJson")
		FString simTime = "simulation_time";
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "readJson")
		FString loadModelPath = "city_model_path";
};

/**
 * 
 */
UCLASS()
class ARCGISTEST_API UreadJson : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
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
