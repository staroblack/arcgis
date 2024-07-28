// Fill out your copyright notice in the Description page of Project Settings.


#include "DLCLoader.h"
#include "IPlatformFilePak.h"
#include "Runtime/Core/Public/HAL/PlatformFileManager.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "JsonObjectConverter.h"
#include "Engine/EngineTypes.h"
#include "Misc/ScopeLock.h"
#include "HAL/FileManager.h"
#include "Serialization/JsonSerializer.h"





IPlatformFile* ADLCLoader::oldPlatform = nullptr;

// Sets default values
ADLCLoader::ADLCLoader()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADLCLoader::BeginPlay()
{
	Super::BeginPlay();

	ADLCLoader::oldPlatform = &FPlatformFileManager::Get().GetPlatformFile();

	// create object library
	this->m_objectLibrary = UObjectLibrary::CreateLibrary(nullptr, false, GIsEditor);
	this->m_objectLibrary->bRecursivePaths = true;

}

// Called every frame
void ADLCLoader::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

TArray<FString> ADLCLoader::LoadAllPak(FString pakFolder, bool& bOutSuccess, FString& OutInfoMessage)
{
	bOutSuccess = true;
	TArray<FString> files;
	IFileManager& fileManager = IFileManager::Get();
	FString absFolderPath = fileManager.ConvertToAbsolutePathForExternalAppForRead(*pakFolder);
	fileManager.FindFiles(files, *pakFolder, TEXT("pak"));

	for (auto& file : files) {
		file = absFolderPath + "/" + file;
		//LoadPak(file, 0, bOutSuccess, OutInfoMessage);
	}
	return files;
}

FinputStruct ADLCLoader::LoadPak(FString pakFilePath, bool loading, bool& bOutSuccess, FString& OutInfoMessage)
{
	
	FPakPlatformFile* pakPlatform = new FPakPlatformFile();

	// initialize pak platform file
	pakPlatform->Initialize(ADLCLoader::oldPlatform, TEXT(""));

	// switch to pak platform file
	FPlatformFileManager::Get().SetPlatformFile(*pakPlatform);
	this->m_pakPlatformFile = pakPlatform;
	FinputStruct output;
	// load pak file
		// check file exist
		if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*pakFilePath)) {
			UE_LOG(LogTemp, Warning, TEXT("pak file: %s not found"), *pakFilePath);
			GEngine->AddOnScreenDebugMessage(-1, 15000.0f, FColor::Green, "pak file not find : " + pakFilePath);

			// return to old platform file
			// FPlatformFileManager::Get().SetPlatformFile(*ADLCLoader::oldPlatform);
		}
		UE_LOG(LogTemp, Warning, TEXT("pak file: %s founded"), *pakFilePath);
		GEngine->AddOnScreenDebugMessage(-1, 15000.0f, FColor::Green, "pak file find : " + pakFilePath);

		// prepare mount point
		FPakFile* pakFile = new FPakFile(pakPlatform, *pakFilePath, false);
		FString oriMountingPoint = pakFile->GetMountPoint();
		FString ProjectPath = FPaths::ProjectDir();
		FString ProjectContentPath = FPaths::ProjectContentDir();
		FString PakFilename = FPaths::GetBaseFilename(pakFilePath);
		FString mountPoint = ProjectContentPath + "DLC/" + PakFilename + "/";
		// mounting point conversion
#if WITH_EDITOR
		pakFile->SetMountPoint(*FPaths::ConvertRelativePathToFull(mountPoint));
		mountPoint = FPaths::ConvertRelativePathToFull(mountPoint);
		ProjectContentPath = FPaths::ConvertRelativePathToFull(ProjectContentPath);
#else
		pakFile->SetMountPoint(*mountPoint);
#endif
		
		UE_LOG(LogTemp, Warning, TEXT("project dir: %s"), *ProjectPath);
		UE_LOG(LogTemp, Warning, TEXT("ori mount point: %s"), *oriMountingPoint);
		UE_LOG(LogTemp, Warning, TEXT("new mount point: %s"), *mountPoint);
		GEngine->AddOnScreenDebugMessage(-1, 150.0f, FColor::Green, "Mount point : " + mountPoint);

		//test spawninfo
		FActorSpawnParameters spawnInfo;
		spawnInfo.Name = "testing";
		Aicon* tempActor = (Aicon*)GetWorld()->SpawnActor<Aicon>(FVector(0, 0, 0), FRotator(0, 0, 0), spawnInfo);
		tempActor->index = iconsCount;
		icons.Add(tempActor);

		// mount pak
		if (pakPlatform->Mount(*pakFilePath, 1, *pakFile->GetMountPoint())) {
			GEngine->AddOnScreenDebugMessage(-1, 150.0f, FColor::Green, "Mount Pak Success : " + pakFilePath);

			FAssetRegistryModule& assetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry"));
			IAssetRegistry& assetRegistry = assetRegistryModule.Get();

			// rescan registry
			assetRegistry.ScanPathsSynchronous({ pakFile->GetMountPoint() }, true);
			assetRegistry.ScanPathsSynchronous({ "/Game/" }, true);

			// get all file names in the pak
			TArray<FString> filenames;
			pakFile->FindPrunedFilesAtPath(filenames, *mountPoint, true, false, true);

			// load asset datas
			TMap<FString, FAssetData*> assetDataMap;
			FString path = mountPoint.Replace(*ProjectContentPath, TEXT("/Game/"));
			this->m_objectLibrary->LoadAssetDataFromPath(path);
			this->m_objectLibrary->GetAssetDataList(this->assetDatas);
			this->m_objectLibrary->ClearLoaded();

			// scan filenames for descriptor
			for (FString& filename : filenames) {

				// load descriptor from json
				if (filename.Contains("GridDescriptor.json")) {
					bOutSuccess = true;
					output = ReadStructFromJsonFile(filename, bOutSuccess, OutInfoMessage);


					tempActor->output.caseName = output.caseName;
					tempActor->output.madeUnit = output.madeUnit;
					tempActor->output.madePerson = output.madePerson;
					tempActor->output.uploadDate = output.uploadDate;
					tempActor->output.modelCity = output.modelCity;
					tempActor->output.quote = output.quote;
					tempActor->output.simArea = output.simArea;
					tempActor->output.simTime = output.simTime;
					tempActor->output.lat = output.lat;
					tempActor->output.lon = output.lon;
					
					//FString fileDir = filename;
					//FString json;
					//FFileHelper::LoadFileToString(json, *fileDir);
					//FJsonDescriptor desc;
					//FJsonObjectConverter::JsonObjectStringToUStruct<FJsonDescriptor>(json, &desc);


					//this->descriptor.Append(this, &desc, &assetDataMap, pakPlatform);

					//this->m_status = m_E_STATUS::READY;
					break;
				}
				else {
					UE_LOG(LogTemp, Warning, TEXT("no json"));
					bOutSuccess = false;
				}
			}

			// build assetDataMap
			for (auto& assetData : assetDatas) {
				assetDataMap.Add(assetData.AssetName.ToString(), &assetData);
				GEngine->AddOnScreenDebugMessage(-1, 15000.0f, FColor::Green, "assetData.AssetName : " + assetData.AssetName.ToString());
				tempActor->assets.Add(&assetData);
				if (loading == 1) {
					/*ModelInfo* model = new ModelInfo();
					model->Init(this, &assetData, pakPlatform);
					model->Load();
					this->models.Add(model);*/
				}
			}
			
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("failed to mount pak file"));
		}
		iconsCount++;
	return output;
}


/*

*/


// helper class methods
// model info
void ModelInfo::Init(UObject* outer, FAssetData* assetdata, IPlatformFile* pakFile)
{
	this->status = E_STATUS::NOT_AVALIABLE;
	this->upper = outer;
	this->pakPlatformFile = pakFile;
	this->boundingBoxCalibrationFlag = false;

	if (assetdata) {
		this->assetData = *assetdata;
		this->status = E_STATUS::UNLOAD;
	}
	else {
		return;
	}

	// create component
	AActor* actor = Cast<AActor>(this->upper);
	this->comp = NewObject<UStaticMeshComponent>(this->upper);
	actor->AddInstanceComponent(this->comp);
	this->comp->OnComponentCreated();
	this->comp->RegisterComponent();
	this->comp->SetWorldLocation(this->coordinate);
	this->comp->SetWorldScale3D(FVector(100, 100, 100));
	this->comp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

void ModelInfo::Load()
{
	if (this->status != E_STATUS::UNLOAD) return;

	this->status = E_STATUS::LOAD_PENDING;

	GEngine->AddOnScreenDebugMessage(-1, 150.0f, FColor::Red, "[ModelInfo::Load]!");
#if WITH_EDITOR
	this->requestHandle = UAssetManager::GetStreamableManager().RequestAsyncLoad(FSoftObjectPath(TEXT("StaticMesh\'/Engine/BasicShapes/Sphere.Sphere\'")), FStreamableDelegate::CreateLambda(&ModelInfo::Complete, this), 0, true);
#else
	this->requestHandle = UAssetManager::GetStreamableManager().RequestAsyncLoad(this->assetData.ToSoftObjectPath(), FStreamableDelegate::CreateLambda(&ModelInfo::Complete, this), 0, true);
#endif
}

void ModelInfo::Load(TArray<ModelInfo*>& unload)
{
	if (this->status != E_STATUS::UNLOAD) return;

	this->status = E_STATUS::LOAD_PENDING;

	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "call load");
	{
		FScopeLock lock(&this->signalLock);
		this->unloadSignal += unload;
	}

#if WITH_EDITOR
	this->requestHandle = UAssetManager::GetStreamableManager().RequestAsyncLoad(FSoftObjectPath(TEXT("StaticMesh\'/Engine/BasicShapes/Sphere.Sphere\'")), FStreamableDelegate::CreateLambda(&ModelInfo::Complete, this), 0, true);
#else
	this->requestHandle = UAssetManager::GetStreamableManager().RequestAsyncLoad(this->assetData.ToSoftObjectPath(), FStreamableDelegate::CreateLambda(&ModelInfo::Complete, this), 0, true);
#endif
}

void ModelInfo::Unload(bool forceUnload)
{
	if (!forceUnload) {
		--this->referenceCounter;
		if (this->referenceCounter > 0) {
			return;
		}
	}
	this->referenceCounter = 0;

	//update component
	if (this->comp) {
		this->comp->SetVisibility(false, true);
		this->comp->SetStaticMesh(NULL);
	}



	// exception
	switch (this->status)
	{
	case E_STATUS::LOAD_PENDING:
		this->requestHandle->CancelHandle();
		this->status = E_STATUS::UNLOAD;
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, "canceled");

		// unload all model info in the signal list
		this->UnloadAllSignal();

	case E_STATUS::UNLOAD:
	case E_STATUS::NOT_AVALIABLE:
		return;
	}

	// unload
#if !WITH_EDITOR
	UAssetManager::GetStreamableManager().Unload(this->assetData.ToSoftObjectPath());
#endif

	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, "unload");

	// switch status
	this->status = E_STATUS::UNLOAD;

	// unload all model info in the signal list
	this->UnloadAllSignal();

	// force gc
	//GEngine->ForceGarbageCollection(true);
}

void ModelInfo::UnloadAllSignal(bool forceUnload)
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("aaaa%s"), *this->assetData.AssetName.ToString()));
	FScopeLock lock(&this->signalLock);
	TArray<ModelInfo*> temp = this->unloadSignal;
	this->unloadSignal.Empty();

	for (auto& model : temp) {
		model->Unload(forceUnload);
	}
}

void ModelInfo::Complete(ModelInfo* info)
{
	// set status
	info->status = E_STATUS::LOADED;

	GEngine->AddOnScreenDebugMessage(-1, 150.0f, FColor::Green, "[ModelInfo::Complete] Start!");

	// retrive static mesh and assign it to component
	UStaticMesh* obj = Cast<UStaticMesh>(info->requestHandle->GetLoadedAsset());
	if (obj) {
		info->comp->SetStaticMesh(obj);
		info->comp->SetWorldScale3D(FVector(100, 100, 100));
		info->comp->SetVisibility(true, true);
		

		// using static mesh calibrate bounding box 
		if (!info->boundingBoxCalibrationFlag) {
			info->boundingBox = obj->GetBoundingBox().MoveTo(info->coordinate);
			info->boundingBoxCalibrationFlag = true;
		}
		// unload binded model
		info->UnloadAllSignal(false);
		GEngine->AddOnScreenDebugMessage(-1, 150.0f, FColor::Green, "[ModelInfo::Complete] Success!");
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 150.0f, FColor::Green, "[ModelInfo::Complete] Failed!");
	}
}

FString ADLCLoader::ReadStringFromFile(FString filepath, bool& bOutSuccess, FString& OutInfoMessage) {
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

TSharedPtr<FJsonObject> ADLCLoader::ReadJson(FString JsonFilePath, bool& bOutSuccess, FString& OutInfoMessage) {
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

FinputStruct ADLCLoader::ReadStructFromJsonFile(FString filepath, bool& bOutSuccess, FString& OutInfoMessage) {
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

void ADLCLoader::WriteStructFromJsonFile(FString filepath, FinputStruct inputStruct, bool& bOutSuccess, FString& OutInfoMessage) {
	TSharedPtr<FJsonObject> JsonObject = FJsonObjectConverter::UStructToJsonObject(inputStruct);
	if (JsonObject == nullptr)
	{
		bOutSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("write failed"));
		return;
	}

	ADLCLoader::WriteJson(filepath, JsonObject, bOutSuccess, OutInfoMessage);
}

void ADLCLoader::WriteJson(FString JsonFilePath, TSharedPtr<FJsonObject> JsonObject, bool& bOutSuccess, FString& OutInfoMessage) {
	FString JsonString;

	if (!FJsonSerializer::Serialize(JsonObject.ToSharedRef(), TJsonWriterFactory<>::Create(&JsonString, 0))) {
		bOutSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("write failed"));
		return;
	}

	ADLCLoader::WriteStringToFile(JsonFilePath, JsonString, bOutSuccess, OutInfoMessage);

	if (!bOutSuccess) {
		return;
	}

	bOutSuccess = true;
	OutInfoMessage = FString::Printf(TEXT("Write Struct Json Succeeded"));
	return;
}

void ADLCLoader::WriteStringToFile(FString filepath, FString inputString, bool& bOutSuccess, FString& OutInfoMessage) {
	if (!FFileHelper::SaveStringToFile(inputString, *filepath))
	{
		bOutSuccess = false;
		return;
	}

	bOutSuccess = true;
	OutInfoMessage = FString::Printf(TEXT("write string to file Succeeded - '%s'"), *filepath);
	return;
}

TArray<Aicon*> ADLCLoader::getIcons() {
	return icons;
}

