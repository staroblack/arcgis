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

struct LineGenerator {
	glm::vec3 transform;
	glm::vec3 rotation;
	float scale;
	int spawnCount;

	LineGenerator();
};

struct FSteadyStreamParameters {
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
	float maxMag;

	FSteadyStreamParameters();
	FSteadyStreamParameters(std::vector<glm::vec4>& point, int index_length, int chunklist_length, CustomOctree& octree);
};

struct FDynamicStreamParameters {
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
	FVector transform;
	float myScale;


	FDynamicStreamParameters();
	FDynamicStreamParameters(std::vector<glm::vec4>& point, int index_length, int chunklist_length, CustomOctree& octree);
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
	float baseViewDistance = 50.f;

	int loadChunkCount = 0;

	std::vector<int> index_tbo_data;
	std::vector<int> status_tbo_data;
	std::vector<float> vel_tbo_data;
	std::vector<float> pre_tbo_data;
	
	FSteadyStreamParameters steadyStreamParams;
	FDynamicStreamParameters dynamicStreamParams;
	LineGenerator lineGenerator;

	UTexture2D* IndexTex = NULL;
	UTexture2D* StatusTex = NULL;
	UTexture2D* VelTex = NULL;
	UTexture2D* PreTex = NULL;

	ULineBatchComponent* lineComponent = NULL;

	vector<float> isosurfacePointList; //GLfloat
	vector<uint32> isosurfaceIndexList; //GLuint

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;

public:	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	USceneComponent* randomComponent;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UProceduralMeshComponent* ProceduralMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterialInterface* MaterialToApplyToClickedObject;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool DrawRedDot;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	FVector Center;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	float MyScale;


	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void LoadChunkDataFromFile(CustomChunk* Chunk, int chunkListIndex);
	bool ClipFrustum(CustomChunk* _Chunk, float frustumEquation[24]);
	void GetChunkInFrustum(CustomChunk*, vector<CustomChunk*>&, float[24]);
	double dot(const glm::dvec4& vec1, const glm::dvec4& vec2);
	void extract_planes_from_projmat(glm::mat4& mat, float frustumEquation[24]);

	void DrawCube(FVector min, FVector max);

	// shader part
	void UpdateTexBuffer();
	void FillIndexTex_Recursive(CustomChunk* _Chunk, Frame& fc, int tbo_index);
	void CreateTextures();

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	FMatrix GetCameraViewProj();

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void UpdateProceduralMesh();

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void UpdateSteadyStreamLine();

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void UpdateDynamicStreamLine();

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void IncreaseSpawnCount();

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void DecreaseSpawnCount();

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void ShiftXPos();

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void ShiftXNeg();

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void ShiftYPos();

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void ShiftYNeg();

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void ShiftZPos();

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void ShiftZNeg();

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void SwitchHack();

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void IncreaseScale();

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void DecreaseScale();


	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void UpdateCenter(FVector InCenter);

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void UpdateScale(float scale);


	void UpdateSpawnPointPositions(std::vector<glm::vec4>& points);

	void UpdateIsosurface();

	bool once = false;
	unsigned long lastAnimate = 0;
	int first = 1;
	float animateSpeed = 1.0f;
	float visibleLength = 20.0f;
	float invisibleLength = 20.0f;
	float animateTime = 10;
	bool hack = false;
};