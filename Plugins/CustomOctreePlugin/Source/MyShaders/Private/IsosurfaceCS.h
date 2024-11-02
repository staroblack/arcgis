// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../../CustomOctreePlugin/Public/SceneManagerTest.h"
#include "IsosurfaceCS.generated.h"

UCLASS()
class UIsosurfaceCS : public UObject
{
	GENERATED_BODY()
	
public:	
	static void Dispath(TArray<int> index_tbo_data, TArray<int> status_tbo_data, TArray<FVector3f> vel_tbo_data, TArray<float> temp_tbo_data, ASceneManagerTest::FIsosurfaceParameters& params);
};
