// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../../Engine/Source/Runtime/Engine/Classes/Engine/ObjectLibrary.h"
#include "../../Engine/Source/Runtime/Engine/Classes/Engine/StreamableManager.h"
#include "../../Engine/Source/Runtime/Engine/Classes/Engine/AssetManager.h"
#include "Components/LineBatchComponent.h"

#include "icon.generated.h"

USTRUCT(BlueprintType, Category = "readJson")
struct FOutputStruct
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
	FString simTime = "simulation_time";
};

UCLASS()
class ARCGISTEST_API Aicon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Aicon();

	//the data
	FOutputStruct output;
	int index;


	//modelinfo
	TArray<FAssetData*> assets;
	UStaticMeshComponent* meshComponent;
	UStaticMeshComponent* hitboxCube;
	TSharedPtr<FStreamableHandle> requestHandle;

	bool firstLoad = true;
	ULineBatchComponent* lineComponent = NULL;


protected:

public:	
	UFUNCTION(BlueprintCallable, Category = "pakloading")
	void hitboxInit();

	void hitboxComplete();
	
	UFUNCTION(BlueprintCallable, Category = "pakloading")
	void load();

	void complete();

	UFUNCTION(BlueprintCallable, Category = "pakloading")
	int getIconIndex();

	UFUNCTION(BlueprintCallable, Category = "pakloading")
	FOutputStruct getOutputStruct();

	UFUNCTION(BlueprintCallable, Category = "pakloading")
	UStaticMeshComponent* getMeshComponent();

	UFUNCTION(BlueprintCallable, Category = "pakloading")
	UStaticMeshComponent* getHitbox();

	UFUNCTION(BlueprintCallable, Category = "pakloading")
	void unloadModel();

	UFUNCTION(BlueprintCallable, Category = "pakloading")
	bool getFirstLoad();

	UFUNCTION(BlueprintCallable, Category = "pakloading")
	void setFirstLoad(bool loaded);
	
	UFUNCTION(BlueprintCallable, Category = "pakloading")
	TArray<float> getSimArea(FString line);
};
