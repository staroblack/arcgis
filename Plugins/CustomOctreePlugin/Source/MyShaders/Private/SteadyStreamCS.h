// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RHICommandList.h"
#include "Engine/TextureRenderTarget2D.h"
#include "../../CustomOctreePlugin/Public/SceneManagerTest.h"
#include "SteadyStreamCS.generated.h"

UCLASS()
class USteadyStreamCS : public UObject
{
	GENERATED_BODY()
	
public:
	static void Dispath(TArray<int> index_tbo_data, TArray<int> status_tbo_data, TArray<FVector3f> vel_tbo_data, TArray<float> pre_tbo_data, FStreamLineParameters& params);
};
