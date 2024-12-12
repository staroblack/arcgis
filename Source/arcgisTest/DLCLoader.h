// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Engine/AssetManager.h"
#include "Engine/ObjectLibrary.h"
#include "Engine/StreamableManager.h"
#include "icon.h"
#include "Http.h"

#include "DLCLoader.generated.h"

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


// descriptor class
class ModelInfo {
public:
	enum class E_STATUS {
		NOT_AVALIABLE,
		UNLOAD,
		LOAD_PENDING,
		LOADED
	};

	E_STATUS status = E_STATUS::NOT_AVALIABLE;
	FVector coordinate;
	FAssetData assetData;
	IPlatformFile* pakPlatformFile = nullptr;
	UObject* upper;

	double offset = 0;
	bool boundingBoxCalibrationFlag = false;
	FBox boundingBox;

	TSharedPtr<FStreamableHandle> requestHandle;
	UStaticMeshComponent* comp = nullptr;
	

	FCriticalSection signalLock;
	TArray<ModelInfo*> unloadSignal;
	int referenceCounter = 0;


public:
	ModelInfo() = default;
	~ModelInfo() = default;

	void Init(UObject* upper, FAssetData* assetData, IPlatformFile* pakFile);
	void Load();
	void Load(TArray<ModelInfo*>& unload);
	void Unload(bool forceUnload = true);

	void UnloadAllSignal(bool forceUnload = true);

	static void Complete(ModelInfo* info);

};

UCLASS()
class ARCGISTEST_API ADLCLoader : public AActor
{
	GENERATED_BODY()

private:
	enum class m_E_STATUS {
		NOT_AVALIABLE = 0,
		READY
	};

	m_E_STATUS m_status = m_E_STATUS::NOT_AVALIABLE;
	IPlatformFile* m_pakPlatformFile = nullptr;
	UObjectLibrary* m_objectLibrary;
	//Descriptor descriptor;

	// test
	TArray<ModelInfo*> models;
	int currModel;

	// plan to remove
	UStaticMeshComponent* staticComp;
	FSoftObjectPath softPath;
	TArray<FSoftObjectPath> softPathes;
	TArray<FAssetData> assetDatas;
	TArray<FAssetData> tempDatas;
	TArray<UStaticMeshComponent*> meshComps;

	UObjectLibrary* loadLibrary;
	TArray<Aicon*> icons;
	TArray<Aicon*> filteredIcons;
	int iconsCount = 0;

	FString xmlString;

	ULineBatchComponent* lineComponent = NULL;
	TArray<FString> paths;

public:	
	// Sets default values for this actor's properties
	ADLCLoader();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	TArray<FString> LoadAllPak(FString pakFolder, bool& bOutSuccess, FString& OutInfoMessage);

	UFUNCTION(BlueprintCallable)
	FinputStruct LoadPak(FString pakFilePath, bool loading  ,bool& bOutSuccess, FString& OutInfoMessage);

	UFUNCTION(BlueprintCallable)
	FinputStruct LoadFolder(FString folderFilePath, FString gameFolder, bool loading, bool& bOutSuccess, FString& OutInfoMessage);

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

	UFUNCTION(BlueprintCallable, Category = "pakloading")
	TArray<FString> getPaths();

	UFUNCTION(BlueprintCallable, Category = "pakloading")
	void initIconsHitbox();

	UFUNCTION(BlueprintCallable, Category = "pakloading")
	TArray<Aicon*> getIcons();

	UFUNCTION(BlueprintCallable, Category = "drawing hitbox")
	void drawHitbox(TArray<FVector> points, FLinearColor color, float thickness);

	UFUNCTION(BlueprintCallable, Category = "drawing hitbox")
	TArray<FVector> getCorners(FVector center, FVector Extent);

	UFUNCTION(BlueprintCallable, Category = "drawing hitbox")
	void flushline();

	UFUNCTION(BlueprintCallable, Category = "compare string")
	Aicon* findIcon(FString input);

	UFUNCTION(BlueprintCallable, Category = "compare string")
	bool compareString(TArray<FString> input, FString compare);

	UFUNCTION(BlueprintCallable, Category = "compare string")
	bool compareOneString(FString input, FString compare);

	UFUNCTION(BlueprintCallable, Category = "compare string")
	void printString(FString input);

	UFUNCTION(BlueprintCallable, Category = "getting Http")
	void sendHttpRequest(FString lon, FString lat);

	void OnRespondseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully);

	UFUNCTION(BlueprintCallable, Category = "getting Http")
	FString getXmlString() {
		return xmlString;
	}

	UFUNCTION(BlueprintCallable, Category = "getting Http")
	void setIconsHttp();

	UFUNCTION(BlueprintCallable, Category = "icon filtering")
	void addFilteredIcon(Aicon* icon);

	UFUNCTION(BlueprintCallable, Category = "icon filtering")
	void clearFilteredIcon();

	UFUNCTION(BlueprintCallable, Category = "icon filtering")
	TArray<Aicon*> getFilteredIcon();


public:
	static IPlatformFile* oldPlatform;

};
