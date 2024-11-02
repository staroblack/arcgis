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

void Aicon::hitboxInit()
{
	//FSoftObjectPath(TEXT("StaticMesh\'/Engine/BasicShapes/Cube.Cube\'"))
#if WITH_EDITOR
	this->requestHandle = UAssetManager::GetStreamableManager().RequestAsyncLoad(FSoftObjectPath(TEXT("StaticMesh\'/Engine/BasicShapes/Cube.Cube\'")), FStreamableDelegate::CreateLambda(&Aicon::hitboxComplete, this), 0, true);
	//this->requestHandle = UAssetManager::GetStreamableManager().RequestAsyncLoad(assetData.ToSoftObjectPath(), FStreamableDelegate::CreateLambda(&Aicon::complete, this), 0, true);
#else
	this->requestHandle = UAssetManager::GetStreamableManager().RequestAsyncLoad(FSoftObjectPath(TEXT("StaticMesh\'/Engine/BasicShapes/Cube.Cube\'")), FStreamableDelegate::CreateLambda(&Aicon::hitboxComplete, this), 0, true);
#endif
}

void Aicon::hitboxComplete()
{
	AActor* actor = Cast<AActor>(this);
	hitboxCube = NewObject<UStaticMeshComponent>(this);
	actor->AddInstanceComponent(hitboxCube);
	hitboxCube->OnComponentCreated();
	hitboxCube->RegisterComponent();
	hitboxCube->SetWorldLocation(FVector(0, 0, 0));
	hitboxCube->SetWorldScale3D(FVector(1, 1, 1));
	hitboxCube->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

	UStaticMesh* obj = Cast<UStaticMesh>(this->requestHandle->GetLoadedAsset());
	if (obj) {
		hitboxCube->SetStaticMesh(obj);
		hitboxCube->SetWorldScale3D(FVector(1, 1, 1));
		hitboxCube->SetVisibility(true, true);
		hitboxCube->SetCollisionObjectType(ECC_GameTraceChannel12);

		//GEngine->AddOnScreenDebugMessage(-1, 150.0f, FColor::Green, "[ModelInfo::Complete] Success!");
	}
	else {
		//GEngine->AddOnScreenDebugMessage(-1, 150.0f, FColor::Green, "[ModelInfo::Complete] Failed!");
	}
}

void Aicon::load()
{
	//FSoftObjectPath(TEXT("StaticMesh\'/Engine/BasicShapes/Cube.Cube\'"))
#if WITH_EDITOR
	for (int i = 0; i < assets.Num(); i++) {
		//GEngine->AddOnScreenDebugMessage(-1, 15000.0f, FColor::Green, "assetData.AssetName : " + assets[i]->AssetName.ToString());
		this->requestHandle = UAssetManager::GetStreamableManager().RequestAsyncLoad(assets[i]->ToSoftObjectPath(), FStreamableDelegate::CreateLambda(&Aicon::complete, this), 0, true);
	}
	//this->requestHandle = UAssetManager::GetStreamableManager().RequestAsyncLoad(assetData.ToSoftObjectPath(), FStreamableDelegate::CreateLambda(&Aicon::complete, this), 0, true);
#else
	for (int i = 0; i < assets.Num(); i++) {
		this->requestHandle = UAssetManager::GetStreamableManager().RequestAsyncLoad(assets[i]->ToSoftObjectPath(), FStreamableDelegate::CreateLambda(&Aicon::complete, this), 0, true);
	}
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
	meshComponent->SetWorldScale3D(FVector(1, 1, 1));
	meshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	UStaticMesh* obj = Cast<UStaticMesh>(this->requestHandle->GetLoadedAsset());
	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, "debug");
	if (obj) {
		meshComponent->SetStaticMesh(obj);
		meshComponent->SetWorldScale3D(FVector(1, 1, 1));
		meshComponent->SetVisibility(true, true);
	}
	else {
		//GEngine->AddOnScreenDebugMessage(-1, 150.0f, FColor::Green, "[ModelInfo::Complete] Failed!");
	}


}

void Aicon::unloadModel() {
	 meshComponent = NewObject<UStaticMeshComponent>(this);
}

int Aicon::getIconIndex() {
	return index;
}

FOutputStruct Aicon::getOutputStruct() {
	return output;
}

UStaticMeshComponent* Aicon::getHitbox() {
	return hitboxCube;
}

UStaticMeshComponent* Aicon::getMeshComponent() {
	return meshComponent;
}

bool Aicon::getFirstLoad() {
	return firstLoad;
}

void Aicon::setFirstLoad(bool loaded) {
	firstLoad = loaded;
}

TArray<float> Aicon::getSimArea(FString line) {
	std::string stringLine = std::string(TCHAR_TO_UTF8(*line));
	std::string delimiter = "x";
	TArray<float> result;
	size_t pos = 0;
	std::string token;
	while ((pos = stringLine.find(delimiter)) != std::string::npos) {
		token = stringLine.substr(0, pos);
		result.Add(std::stof(token));
		stringLine.erase(0, pos + delimiter.length());
	}
	result.Add(std::stof(stringLine));
	return result;
}


void Aicon::sendHttpRequest() {
	FHttpRequestRef Request = FHttpModule::Get().CreateRequest();
	FString lon, lat;
	lon = FString::SanitizeFloat(output.lon);
	lat = FString::SanitizeFloat(output.lat);
	FString url = "https://api.nlsc.gov.tw/other/TownVillagePointQuery/" + lon + "/" + lat + "/" + "4326";

	//example
	//"https://api.nlsc.gov.tw/other/TownVillagePointQuery/120.634413/24.153282/4326"
	//"https://api.nlsc.gov.tw/other/TownVillagePointQuery/" + lon + "/" + lat + "/" + "4326";

	Request->OnProcessRequestComplete().BindUObject(this, &Aicon::OnRespondseReceived);
	Request->SetURL(url);
	Request->SetVerb("GET");
	Request->ProcessRequest();
}

void Aicon::OnRespondseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully) {
	//UE_LOG(LogTemp, Display, TEXT("Response %s"), *Response->GetContentAsString());
	xmlString = *Response->GetContentAsString();
}


FString Aicon::getXmlString() {
	return xmlString;
}

void Aicon::setTown(FString line) {
	overlappedTown.Add(line);
}

TArray<FString> Aicon::getTown() {
	return overlappedTown;
}
