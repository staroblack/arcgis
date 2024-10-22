#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CDT.h"

THIRD_PARTY_INCLUDES_START
#pragma push_macro("check")
#pragma push_macro("PI")
#undef PI
#undef check
#pragma warning (push)
#pragma warning (disable: 4250)
#pragma warning (disable : 4191)
#pragma warning (disable : 4686)
#pragma warning (disable : 4018)
#pragma warning (disable : 4211)
#pragma warning (disable : 4589)
//#include "SystemUtility/ProjectManager.h"
//#include "SystemUtility/bFile/bFileIO.h"
// C:\CityGIS_UE5\ThirdParty\ldlib\3rdparty\armadillo-10.7.1\include\armadillo
#pragma warning (pop)
#pragma pop_macro("check")
#pragma pop_macro("PI")
THIRD_PARTY_INCLUDES_END

#include "LineDrawGraphics.generated.h"

/**
 * 
 */
class ULineBatchComponent;

UCLASS()
class ULineDrawGraphics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
private:
	static TSoftObjectPtr<ULineBatchComponent> GetDebugLineBatcher(const UWorld* InWorld, bool bPersistentLines, float LifeTime, bool bDepthIsForeground);

public:
	UFUNCTION(BlueprintCallable)
		static TSoftObjectPtr<ULineBatchComponent> BPDrawLine(UObject* context, FVector Start, FVector End, FLinearColor Color, uint8 DepthPriority, float Thickness, float Duration, bool bPersistent = false);
	UFUNCTION(BlueprintCallable)
		static void BPDrawBox(UObject* context, FVector  Center, FVector  Box, FLinearColor Color, uint8 DepthPriority, float Thickness, float Duration, bool bPersistent = false);
	UFUNCTION(BlueprintCallable, meta = (context = "WorldContextObject"))
		static void BPDrawSoildBox(UObject* context, FVector  Center, FVector  Extent, FLinearColor  Color, uint8 DepthPriority, float Duration, bool bPersistent = false);
	UFUNCTION(BlueprintCallable, meta = (context = "WorldContextObject"))
		static void FlushLineComponent(TSoftObjectPtr<ULineBatchComponent> lines);


};

struct LineBatchInfo {
	LineBatchInfo(FVector start, FVector end, FLinearColor color, uint8 depthPriority, float thickness, float lifeTime) :
		start(start), end(end), color(color), depthPriority(depthPriority), thickness(thickness), lifeTime(lifeTime) {}
	FVector start;
	FVector end;
	FLinearColor color;
	uint8 depthPriority;
	float thickness;
	float lifeTime;
};

struct MeshLineBatchInfo {
	MeshLineBatchInfo(TArray<FVector> Verts, TArray<int32> Indices, FColor color, uint8 depthPriority, float lifeTime = -1) :
		Verts(Verts), Indices(Indices), color(color), depthPriority(depthPriority), lifeTime(lifeTime) {}
	TArray<FVector> Verts;
	TArray<int32> Indices;
	FColor color;
	uint8 depthPriority;
	float lifeTime;
};

UCLASS()
class ALineDrawManager : public AActor
{
	GENERATED_UCLASS_BODY()
private:
	TSoftObjectPtr<ULineBatchComponent> GetDebugLineBatcher(const UWorld* InWorld, bool bPersistentLines, float LifeTime, bool bDepthIsForeground);

	void UpdateLineBatcher(UObject* context);

public:
	UFUNCTION(BlueprintCallable, Category = "LineManager")
		TSoftObjectPtr<ULineBatchComponent> AddDrawLine(UObject* context, FVector Start, FVector End, FLinearColor Color, uint8 DepthPriority, float Thickness, float Duration, bool bPersistent = true);
	
	UFUNCTION(BlueprintCallable, Category = "LineManager")
		bool RemoveDrawLine(UObject* context, int index);

	UFUNCTION(BlueprintCallable, Category = "LineManager")
		bool PopDrawLine(UObject* context);

	UFUNCTION(BlueprintCallable, Category = "LineManager")
		void StartMeasureArea();

	UFUNCTION(BlueprintCallable, Category = "LineManager")
		bool GenerateArea(UObject* context, FColor color, uint8 DepthPriority);

	UFUNCTION(BlueprintCallable, Category = "LineManager")
		bool RemoveDrawArea(UObject* context, int index);

	UFUNCTION(BlueprintCallable, Category = "LineManager")
		bool PopDrawArea(UObject* context);

private:
	TArray<LineBatchInfo> lineArray;
	TArray<MeshLineBatchInfo> meshArray;
	int areaStartIndex = -1;
};