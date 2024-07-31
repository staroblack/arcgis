// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../Include/CustomOctree.h"
#include "CustomOctreePlugin.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"
#include "DrawDebugHelpers.h"
#include "ProceduralMeshComponent.h"
#include "Components/LineBatchComponent.h"
#include "Runtime/Engine/Classes/Engine/TextureRenderTarget2D.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SceneManagerTest.generated.h"

#define ENABLE_CACHE 1

enum SpawnType { SPHERE, SQUARE, LINE };
struct LineGenerator {
	float stepDivider;
	SpawnType spawnType;
	glm::vec3 transform;
	glm::vec3 rotation;
	float scale;
	int spawnCount;
	float collideForce;

	vector<glm::vec3> randomValue;

	LineGenerator();
};

struct FStreamLineParameters {
	TArray<FVector4f> points;
	TArray<FVector4f> pathLine;
	TArray<FBatchedLine> lines;

	float collideForce;
	float dt;
	int maxLength;
	float stepDivider;
	int indexLength;
	int chunkListLength;
	FVector3f chunkSize;
	FVector3f minPos;
	FVector3f maxPos;
	FVector3f spacing;
	int totalLevel;
	float animateTime;
	float visibleLength;
	float invisibleLength;
	float maxMag;

	bool hack;

	FVector center;
	float myScale;

	FStreamLineParameters();
	FStreamLineParameters(std::vector<glm::vec4>& point, int index_length, int chunklist_length, CustomOctree& octree);
};

struct FIsosurfaceParameters {
	TArray<FVector4f> isosurfacePoint;
	TArray<FVector> outputPos;
	TArray<int> OutTris;

	int indexLength;
	int chunkListLength;

	FMatrix44f viewProj;
	FMatrix44f model;

	FVector3f chunkSize;

	FVector3f minPos;
	FVector3f maxPos;
	FVector3f spacing;
	int totalLevel;

	int isQCritirea;
	float isovalue;
	float minIsovalue;
	float maxIsovalue;

	FVector center;
	float myScale;

	FIsosurfaceParameters();
	FIsosurfaceParameters(int index_length, int chunklist_length, float threshold, FMatrix camViewProj, CustomOctree& octree);
};

UCLASS()
class CUSTOMOCTREEPLUGIN_API ASceneManagerTest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASceneManagerTest();
	//Testing
	CustomOctree _octree;
	vector<float> octreeLODList;
	vector<CustomChunk*> chunkList;
	int timeBase = 5;
	int nowFrame = 1;
	wstring dataFolder;
	int actuallyReadChunkCount = 0;
	vector<ifstream*> fileValueList;
	vector<ifstream*> fileIndexList;
	vector<ifstream*> baseFileValueList;
	vector<ifstream*> baseFileIndexList;
	float baseViewDistance = 50.0f;

	int loadChunkCount = 0;

	std::vector<int> index_tbo_data;
	std::vector<int> status_tbo_data;
	std::vector<float> vel_tbo_data;
	std::vector<float> pre_tbo_data;
	
	FStreamLineParameters streamLineParams;
	FIsosurfaceParameters isosurfaceParams;
	LineGenerator lineGenerator;

	UTexture2D* IndexTex = NULL;
	UTexture2D* StatusTex = NULL;
	UTexture2D* VelTex = NULL;
	UTexture2D* PreTex = NULL;

	ULineBatchComponent* lineComponent = NULL;
	UProceduralMeshComponent* planePMC = NULL;
	UProceduralMeshComponent* isosurfacePMC = NULL;
	UProceduralMeshComponent* isosurfacePMC2 = NULL;

	vector<float> isosurfacePointList; //GLfloat
	vector<uint32> isosurfaceIndexList; //GLuint

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;

public:	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	USceneComponent* randomComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterialInterface* MaterialToApplyToClickedObject;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool DrawRedDot;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	FVector Center;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	float MyScale;

	float QCritireaThreshold1 = 100;

	float QCritireaThreshold2 = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float vorticityThreshold = 30;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void LoadChunkDataFromFile(CustomChunk* Chunk, int chunkListIndex);
	bool ClipFrustum(CustomChunk* _Chunk, float frustumEquation[24]);
	void GetChunkInFrustum(CustomChunk*, vector<CustomChunk*>&, float[24]);
	double dot(const glm::dvec4& vec1, const glm::dvec4& vec2);
	void extract_planes_from_projmat(glm::mat4& mat, float frustumEquation[24]);

	void DrawCube(FVector min, FVector max);

	void UpdateTexBuffer();
	void FillIndexTex_Recursive(CustomChunk* _Chunk, Frame& fc, int tbo_index);
	void CreateTextures();

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	FMatrix GetCameraViewProj();

	void UpdateSpawnPointPositions(std::vector<glm::vec4>& points);

	void UpdateIsosurface();

	void UpdatePlane();
	void DrawPlane();
	void UpdateStreamLine(bool isDynamic);
	void DrawStreamLines();

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void UpdateCenter(FVector InCenter);

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void UpdateScale(float scale);

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void DrawVorticity();

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void DrawQCritirea();

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void SetDrawType(int DrawType);

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void SetStepDivider(int stepDivider);

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void SetSpawnCount(int spawnCount);

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void SetSpawnRange(float spawnRange);

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void SetXPos(float xPos);

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void SetYPos(float yPos);

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void SetZPos(float zPos);

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void SetXRot(float xRot);

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void SetYRot(float yRot);

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void SetZRot(float zRot);

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void SetSpawnType(int spawnType);

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void SetVisibleLength(float VisibleLength);

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void SetInvisibleLength(float InvisibleLength);

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void SetAnimateSpeed(float AnimateSpeed);

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void SetSelectedAxis(int SelectedAxis);

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void SetPlaneOffset(float PlaneOffset);

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void SetPlaneDrawType(int PlaneDrawType);

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void SetVoricityValue(float voricityValue);

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void SetQCritirea1Value(float QCritirea1Value);

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void SetQCritirea2Value(float QCritirea2Value);

	int drawType = 0;

	bool once = false;

	// plane params
	int selectedAxis = 2;
	float planeOffset = 0.05;
	int planeDrawType = 4;

	unsigned long lastAnimate = 0;
	int first = 1;
	float animateSpeed = 1.0f;
	float visibleLength = 20.0f;
	float invisibleLength = 20.0f;
	float animateTime = 10;
	bool hack = false;
};