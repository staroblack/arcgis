// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../../Engine/Source/Runtime/Engine/Classes/Engine/ObjectLibrary.h"
#include "../../Engine/Source/Runtime/Engine/Classes/Engine/StreamableManager.h"
#include "../../Engine/Source/Runtime/Engine/Classes/Engine/AssetManager.h"

#include "icon.generated.h"

UCLASS()
class ARCGISTEST_API Aicon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Aicon();

	//the data
	int index;
	FString caseName;
	FString madeUnit;
	FString madePerson;
	FString uploadDate;
	FString modelCity;
	FString quote;
	FString simArea;
	FString simTime;
	float lat;
	float lon;


	//modelinfo
	TArray<FAssetData*> assets;
	UStaticMeshComponent* meshComponent;
	TSharedPtr<FStreamableHandle> requestHandle;

protected:

public:	
	UFUNCTION(BlueprintCallable, Category = "pakloading")
	void load();

	void complete();

	UFUNCTION(BlueprintCallable, Category = "pakloading")
	int getIconIndex();
};
