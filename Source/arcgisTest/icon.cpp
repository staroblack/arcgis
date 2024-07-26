// Fill out your copyright notice in the Description page of Project Settings.


#include "icon.h"
#include "IPlatformFilePak.h"
#include "Runtime/Core/Public/HAL/PlatformFileManager.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "JsonObjectConverter.h"
#include "Engine/EngineTypes.h"
#include "Misc/ScopeLock.h"
#include "HAL/FileManager.h"

// Sets default values
Aicon::Aicon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


void Aicon::load()
{
	//FSoftObjectPath(TEXT("StaticMesh\'/Engine/BasicShapes/Sphere.Sphere\'"))
#if WITH_EDITOR
	for (int i = 0; i < assets.Num(); i++) {
		this->requestHandle = UAssetManager::GetStreamableManager().RequestAsyncLoad(assets[i]->ToSoftObjectPath(), FStreamableDelegate::CreateLambda(&Aicon::complete, this), 0, true);
	}
	//this->requestHandle = UAssetManager::GetStreamableManager().RequestAsyncLoad(assetData.ToSoftObjectPath(), FStreamableDelegate::CreateLambda(&Aicon::complete, this), 0, true);
#else
	this->requestHandle = UAssetManager::GetStreamableManager().RequestAsyncLoad(assets[i]->ToSoftObjectPath(), FStreamableDelegate::CreateLambda(&Aicon::complete, this), 0, true);
#endif
}

void Aicon::complete()
{
	AActor* actor = Cast<AActor>(this);
	meshComponent = NewObject<UStaticMeshComponent>(this);
	actor->AddInstanceComponent(meshComponent);
	meshComponent->OnComponentCreated();
	meshComponent->RegisterComponent();
	meshComponent->SetWorldLocation(FVector(0, 0, 0));
	meshComponent->SetWorldScale3D(FVector(10000, 10000, 10000));
	meshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	UStaticMesh* obj = Cast<UStaticMesh>(this->requestHandle->GetLoadedAsset());
	if (obj) {
		meshComponent->SetStaticMesh(obj);
		meshComponent->SetWorldScale3D(FVector(10000, 10000, 10000));
		meshComponent->SetVisibility(true, true);

		GEngine->AddOnScreenDebugMessage(-1, 150.0f, FColor::Green, "[ModelInfo::Complete] Success!");
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 150.0f, FColor::Green, "[ModelInfo::Complete] Failed!");
	}
}

int Aicon::getIconIndex() {
	return index;
}

