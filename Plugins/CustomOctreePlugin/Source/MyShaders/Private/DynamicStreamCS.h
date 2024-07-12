// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RHICommandList.h"
#include "../../CustomOctreePlugin/Public/SceneManagerTest.h"
#include "DynamicStreamCS.generated.h"

UCLASS()
class UDynamicStreamCS : public UObject
{
	GENERATED_BODY()
	
public:
	//static void Run();
	static void Dispath(TArray<int> index_tbo_data, TArray<int> status_tbo_data, TArray<FVector3f> vel_tbo_data, TArray<float> pre_tbo_data, FDynamicStreamParameters& params);
};
