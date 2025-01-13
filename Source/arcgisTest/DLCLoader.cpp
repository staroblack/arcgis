// Fill out your copyright notice in the Description page of Project Settings.


#include "DLCLoader.h"
#include "IPlatformFilePak.h"
#include "Runtime/Core/Public/HAL/PlatformFileManager.h"
#include "MeshDescription.h"
#include <ProceduralMeshConversion.h>
#include "StaticMeshDescription.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "JsonObjectConverter.h"
#include "Engine/EngineTypes.h"
#include "Misc/ScopeLock.h"
#include "HAL/FileManager.h"
#include <Windows.h> // 包含 Windows API 頭文件
#include "Serialization/JsonSerializer.h"

#include <string> 




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

void ADLCLoader::copyOBJ(FString path) {
	std::string instruction = std::string(TCHAR_TO_UTF8(*path));
	// 要執行的命令
	std::wstring widestr = std::wstring(instruction.begin(), instruction.end());
	
	//const WCHAR* c = widestr.c_str();
	//ShellExecute(NULL, _T("helper.exe"), c, NULL, NULL, 0);

	// 使用 ShellExecute 啟動命令
	HINSTANCE result = ShellExecute(
		NULL,             // 父視窗 (設為 NULL)
		_T("runas"),          // 動作：以管理員身份執行
		_T("cmd.exe"),        // 要執行的程序
		widestr.c_str(), // 傳遞給 cmd.exe 的參數
		NULL,             // 默認工作目錄
		SW_SHOW           // 顯示窗口
	);
}

TArray<FString> ADLCLoader::LoadAllPak(FString pakFolder, bool& bOutSuccess, FString& OutInfoMessage)
{
	int count = 0;

	FString cubePath = FPaths::Combine(FPaths::ProjectDir(), "Content/Cube/cube.obj");
	FString pakPath = FPaths::Combine(FPaths::ProjectDir(), "Content/testCase");
	//GEngine->AddOnScreenDebugMessage(-1, 15000.0f, FColor::Green, pakPath);
	UObjectLibrary* tempLibrary = UObjectLibrary::CreateLibrary(nullptr, false, GIsEditor);
	tempLibrary->bRecursivePaths = true;
	loadLibrary = tempLibrary;
	bOutSuccess = true;
	TArray<FString> files;
	IFileManager& fileManager = IFileManager::Get();
	FString absFolderPath = fileManager.ConvertToAbsolutePathForExternalAppForRead(*pakPath);
	FString allFolderPath = absFolderPath;


	FPaths::NormalizeDirectoryName(absFolderPath);
	IFileManager& FileManager = IFileManager::Get();
	FJsonSerializableArray Folders;
	allFolderPath = absFolderPath / "*";
	FileManager.FindFiles(Folders, *allFolderPath, false, true);


	for (int i = 0; i < Folders.Num(); i++)
	{	
		count++;
		//GEngine->AddOnScreenDebugMessage(-1, 15000.0f, FColor::Red, Folders[i]);
		FString file = absFolderPath + "/" + Folders[i];
		FString gamefile = "/Game/testCase/";
		gamefile = gamefile + Folders[i];
		//GEngine->AddOnScreenDebugMessage(-1, 15000.0f, FColor::Blue, gamefile);
		LoadFolder(file, Folders[i], 1, bOutSuccess, OutInfoMessage);
		
	}

	/*for (auto& file : files) {
		count++;
		file = absFolderPath + "/" + file;
		paths.Add(file); 
		GEngine->AddOnScreenDebugMessage(-1, 15000.0f, FColor::Red, file);
		LoadPak(file, 1, bOutSuccess, OutInfoMessage);
	}*/

	if (count == 0) {
		GEngine->AddOnScreenDebugMessage(-1, 15000.0f, FColor::Red, "no file found at : " + pakPath);
	}
	return files;
}

FinputStruct ADLCLoader::LoadPak(FString pakFilePath, bool loading, bool& bOutSuccess, FString& OutInfoMessage)
{
	//UObjectLibrary* tempLibrary = UObjectLibrary::CreateLibrary(nullptr, false, GIsEditor);
	//tempLibrary->bRecursivePaths = true;
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
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, "pak file not find : " + pakFilePath);

		// return to old platform file
		// FPlatformFileManager::Get().SetPlatformFile(*ADLCLoader::oldPlatform);
	}
	UE_LOG(LogTemp, Warning, TEXT("pak file: %s founded"), *pakFilePath);

	// prepare mount point
	FPakFile* pakFile = new FPakFile(pakPlatform, *pakFilePath, false);
	FString oriMountingPoint = pakFile->GetMountPoint();
	FString ProjectPath = FPaths::ProjectDir();
	FString ProjectContentPath = FPaths::ProjectContentDir();
	FString PakFilename = FPaths::GetBaseFilename(pakFilePath);
	FString mountPoint = ProjectContentPath + "DLC/" + PakFilename + "/";
	// mounting point conversion

//#if WITH_EDITOR
//		pakFile->SetMountPoint(*FPaths::ConvertRelativePathToFull(mountPoint));
//		mountPoint = FPaths::ConvertRelativePathToFull(mountPoint);
//		ProjectContentPath = FPaths::ConvertRelativePathToFull(ProjectContentPath);
//#else
//		pakFile->SetMountPoint(*mountPoint);
//		pakFile->SetMountPoint(*FPaths::ConvertRelativePathToFull(mountPoint));
//		mountPoint = FPaths::ConvertRelativePathToFull(mountPoint);
//		ProjectContentPath = FPaths::ConvertRelativePathToFull(ProjectContentPath);
//#endif
		
	pakFile->SetMountPoint(*FPaths::ConvertRelativePathToFull(mountPoint));
	mountPoint = FPaths::ConvertRelativePathToFull(mountPoint);
	ProjectContentPath = FPaths::ConvertRelativePathToFull(ProjectContentPath);

	UE_LOG(LogTemp, Warning, TEXT("project dir: %s"), *ProjectPath);
	UE_LOG(LogTemp, Warning, TEXT("ori mount point: %s"), *oriMountingPoint);
	UE_LOG(LogTemp, Warning, TEXT("new mount point: %s"), *mountPoint);
	
	// mount pak
	if (pakPlatform->Mount(*pakFilePath, 1, *pakFile->GetMountPoint())) {
		//GEngine->AddOnScreenDebugMessage(-1, 150.0f, FColor::Green, "Mount Pak Success : " + pakFilePath);

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
			
			
		//this->m_objectLibrary->LoadAssetsFromAssetData();
		//loadLibrary->ClearLoaded();

		if (loading == 1) {
			loadLibrary->LoadAssetDataFromPath(path);
			loadLibrary->GetAssetDataList(this->assetDatas);

			//test spawninfo
			FActorSpawnParameters spawnInfo;
			Aicon* tempActor = GetWorld()->SpawnActor<Aicon>(FVector(0, 0, 0), FRotator(0, 0, 0), spawnInfo);
			tempActor->index = iconsCount;
			icons.Add(tempActor);
			//GEngine->AddOnScreenDebugMessage(-1, 15000.0f, FColor::Red, "spawn");

			for (auto& assetData : assetDatas) {

				assetDataMap.Add(assetData.AssetName.ToString(), &assetData);
				//GEngine->AddOnScreenDebugMessage(-1, 15000.0f, FColor::Green, "assetData.AssetName : " + assetData.AssetName.ToString());
				FAssetData* tempAsset = new(FAssetData);
				*tempAsset = assetData;
				tempActor->assets.Add(tempAsset);
				// GEngine->AddOnScreenDebugMessage(-1, 15000.0f, FColor::Red, "load in  : " + tempActor->assets[0]->AssetName.ToString());
				if (loading == 1) {
					/*ModelInfo* model = new ModelInfo();
					model->Init(this, &assetData, pakPlatform);
					model->Load();
					this->models.Add(model);*/
				}
			}

			bool check_json = false;
			// scan filenames for descriptor
			for (FString& filename : filenames) {
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, filename);
				// load descriptor from json
				if (filename.Contains(".json")) {
					check_json = true;
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
			}
			if (!check_json) {
				UE_LOG(LogTemp, Warning, TEXT("no json"));
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "no json");

				bOutSuccess = false;
			}
		}
			

		for (int i = 0; i < icons.Num(); i++) {
			for (int k = 0; k < icons[i]->assets.Num(); k++) {
				//GEngine->AddOnScreenDebugMessage(-1, 15000.0f, FColor::Blue, "all  : "+ icons[i]->assets[k]->AssetName.ToString());
			}
		}
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("failed to mount pak file"));
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "failed to mount pak file");
	}
	iconsCount++;
	return output;
}

FinputStruct ADLCLoader::LoadFolder(FString folderFilePath, FString folderName, bool loading, bool& bOutSuccess, FString& OutInfoMessage) {
	FinputStruct output;
	TMap<FString, FAssetData*> assetDataMap;
	TArray<FString> files, jsonfiles, objfiles;
	IFileManager& fileManager = IFileManager::Get();
	FString absFolderPath = fileManager.ConvertToAbsolutePathForExternalAppForRead(*folderFilePath);
	//GEngine->AddOnScreenDebugMessage(-1, 15000.0f, FColor::Blue, files[0]);


	FString name = FPaths::ProjectContentDir();
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, name);

	if (loading == 1) {
		FActorSpawnParameters spawnInfo;
		Aicon* tempActor = GetWorld()->SpawnActor<Aicon>(FVector(0, 0, 0), FRotator(0, 0, 0), spawnInfo);
		tempActor->index = iconsCount;
		icons.Add(tempActor);
		tempActor->folderName = folderName;

		//�M��json�ɨ�Ū���ɮ�
		bool check_json = false;
		// scan filenames for descriptor
		fileManager.FindFiles(jsonfiles, *folderFilePath, TEXT("json"));
		//GEngine->AddOnScreenDebugMessage(-1, 15000.0f, FColor::Blue, jsonfiles[0]);
		for (auto filename : jsonfiles) {
			check_json = true;
			bOutSuccess = true;
			output = ReadStructFromJsonFile(folderFilePath + "/" + filename, bOutSuccess, OutInfoMessage);


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
		}

		//�M��obj�ɨðO���ɦW
		bool check_obj = false;
		fileManager.FindFiles(objfiles, *folderFilePath, TEXT("obj"));
		for (auto filename : objfiles) {
			check_obj = true;
			bOutSuccess = true;
			output = ReadStructFromJsonFile(folderFilePath + "/" + filename, bOutSuccess, OutInfoMessage);

			tempActor->modelPath = folderFilePath + "/" + filename;
		}

		//�Y�䤤�@���S���N����
		if (!check_obj || !check_json) {
			if (!check_obj) {
				UE_LOG(LogTemp, Warning, TEXT("no obj"));
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "no obj");
				bOutSuccess = false;
			}
			if(!check_json) {
				UE_LOG(LogTemp, Warning, TEXT("no json"));
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "no json");
				bOutSuccess = false;
			}
			
		}
	}
	for (int i = 0; i < icons.Num(); i++) {
		for (int k = 0; k < icons[i]->assets.Num(); k++) {
			//GEngine->AddOnScreenDebugMessage(-1, 15000.0f, FColor::Blue, "all  : "+ icons[i]->assets[k]->AssetName.ToString());
		}
	}
	
	iconsCount++;
	return output;
}

TArray<FString> ADLCLoader::getPaths() {
	return paths;
}

FString ADLCLoader::getCubePath() {
	FString cubePath = FPaths::Combine(FPaths::ProjectDir(), "Content/Cube/cube.obj");
	return cubePath;
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
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "write failed");
		OutInfoMessage = FString::Printf(TEXT("write failed"));
		return;
	}

	ADLCLoader::WriteJson(filepath, JsonObject, bOutSuccess, OutInfoMessage);
}

void ADLCLoader::WriteJson(FString JsonFilePath, TSharedPtr<FJsonObject> JsonObject, bool& bOutSuccess, FString& OutInfoMessage) {
	FString JsonString;

	if (!FJsonSerializer::Serialize(JsonObject.ToSharedRef(), TJsonWriterFactory<>::Create(&JsonString, 0))) {
		bOutSuccess = false;
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "write failed1");
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
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "write failed2");
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, filepath);
		bOutSuccess = false;
		return;
	}

	bOutSuccess = true;
	OutInfoMessage = FString::Printf(TEXT("write string to file Succeeded - '%s'"), *filepath);
	return;
}

void ADLCLoader::initIconsHitbox() {
	//printString("initIconsHitbox");
	for (int i = 0; i < icons.Num(); i++) {
		icons[i]->hitboxInit();
	}
	//printString("OverIconsHitbox");
}

void ADLCLoader::drawHitbox(TArray<FVector> points, FLinearColor color, float thickness) {
	lineComponent = this->GetWorld()->PersistentLineBatcher;
	float lifetime = 10000000;
	//printString("drawing");
	TArray<FBatchedLine> lines;
	for (int i = 0; i < 4; i++) {
		FBatchedLine line;
		if (i == 3) {
			line = FBatchedLine(points[3], points[0], color, lifetime, thickness, 0);
		}
		else {
			line = FBatchedLine(points[i], points[i + 1], color, lifetime, thickness, 0);
		}
		lines.Add(line);
	}
	lineComponent->DrawLines(lines);
}

TArray<FVector> ADLCLoader::getCorners(FVector center, FVector Extent) {
	//printString("getCorners");
	TArray<FVector> corners;

	corners.Add(center + FVector(Extent.X, Extent.Y, Extent.Z));
	corners.Add(center + FVector(-Extent.X, Extent.Y, Extent.Z));
	corners.Add(center + FVector(-Extent.X, -Extent.Y, Extent.Z));
	corners.Add(center + FVector(Extent.X, -Extent.Y, Extent.Z));

	return corners;
}

Aicon* ADLCLoader::findIcon(FString input) {
	for (int i = 0; i < icons.Num(); i++) {
		if (input == icons[i]->output.caseName) {
			return icons[i];
		}
	}
	return nullptr;
}

bool ADLCLoader::compareString(TArray<FString> input, FString compare) {
	for (int i = 0; i < input.Num(); i++) {
		if (input[i].Contains(compare)) {
			return true;
		}
	}
	return false;
}

bool ADLCLoader::compareOneString(FString input, FString compare) {

	if (input == compare) {
		return true;
	}

	return false;
}

void ADLCLoader::flushline() {
	lineComponent = this->GetWorld()->PersistentLineBatcher;
	lineComponent->Flush();
	return;
}

void  ADLCLoader::printString(FString input) {
	GEngine->AddOnScreenDebugMessage(-1, 15000.0f, FColor::Blue, input);
	return;
}

TArray<Aicon*> ADLCLoader::getIcons() {
	return icons;
}

void ADLCLoader::sendHttpRequest(FString lon, FString lat) {
	FHttpRequestRef Request = FHttpModule::Get().CreateRequest();
	FString url = "https://api.nlsc.gov.tw/other/TownVillagePointQuery/" + lon + "/" + lat + "/" + "4326";

	//example
	//"https://api.nlsc.gov.tw/other/TownVillagePointQuery/120.634413/24.153282/4326"

	Request->OnProcessRequestComplete().BindUObject(this, &ADLCLoader::OnRespondseReceived);
	Request->SetURL(url);
	Request->SetVerb("GET");
	Request->ProcessRequest();
}

void ADLCLoader::OnRespondseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully){
	UE_LOG(LogTemp, Display, TEXT("Response %s"), *Response->GetContentAsString());
	xmlString = *Response->GetContentAsString();
}

void ADLCLoader::setIconsHttp() {
	for (int i = 0; i < icons.Num(); i++) {
		icons[i]->sendHttpRequest();
	}
}

void ADLCLoader::addFilteredIcon(Aicon* icon) {
	filteredIcons.Add(icon);
}

void ADLCLoader::clearFilteredIcon() {
	filteredIcons.Empty();
}

TArray<Aicon*> ADLCLoader::getFilteredIcon() {
	return filteredIcons;
}

void ADLCLoader::PopulateStaticMeshFromPMC(UProceduralMeshComponent* ProceduralMesh, UStaticMeshComponent* StaticMeshComponentToPopulate)
{
	if (IsValid(ProceduralMesh) && IsValid(StaticMeshComponentToPopulate))
	{
		UProceduralMeshComponent* procmesh = ProceduralMesh;

		FName procmeshname = FName(procmesh->GetName() + "_Static");

		UStaticMesh* NewStaticMesh = NewObject<UStaticMesh>(GetTransientPackage(), procmeshname, EObjectFlags::RF_Transient);
		NewStaticMesh->bAllowCPUAccess = true;
		NewStaticMesh->NeverStream = true;
		NewStaticMesh->InitResources();
		NewStaticMesh->SetLightingGuid();

		FMeshDescription PMC_Description = BuildMeshDescription(procmesh);
		UStaticMeshDescription* SM_Description = NewStaticMesh->CreateStaticMeshDescription();
		SM_Description->SetMeshDescription(PMC_Description);
		NewStaticMesh->BuildFromStaticMeshDescriptions({ SM_Description }, false);

		// Collision
		NewStaticMesh->CalculateExtendedBounds();
		NewStaticMesh->SetBodySetup(procmesh->ProcMeshBodySetup);


#if WITH_EDITOR

		NewStaticMesh->PostEditChange();

#endif
		NewStaticMesh->MarkPackageDirty();

		if (IsValid(NewStaticMesh))
		{
			StaticMeshComponentToPopulate->SetStaticMesh(NewStaticMesh);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("RuntimeStaticMeshImporter -> CreateStaticMeshFromData -> New static mesh invalid!"));
		}
	}
	else if (!IsValid(ProceduralMesh))
	{
		UE_LOG(LogTemp, Warning, TEXT("RuntimeStaticMeshImporter -> CreateStaticMeshFromData -> Need valid PMC reference!"));
	}
	else if (!IsValid(StaticMeshComponentToPopulate))
	{
		UE_LOG(LogTemp, Warning, TEXT("RuntimeStaticMeshImporter -> CreateStaticMeshFromData -> Need valid static mesh reference!"));
	}
	return;
}

UStaticMeshComponent* ADLCLoader::getCube() {
	return cube;
}

bool ADLCLoader::checkJsonFormat(FinputStruct inputStruct, FString& info) {
	info = "";
	// Define the regex pattern for "numberxnumber"
	const FRegexPattern Pattern(TEXT("^\\d+x\\d+$"));
	FRegexMatcher Matcher(Pattern, inputStruct.simArea);

	// Check if the pattern matches the FString
	if (!Matcher.FindNext()) {
		info = "simAreaFormatWrong";
		return false;
	}

	return true;
}