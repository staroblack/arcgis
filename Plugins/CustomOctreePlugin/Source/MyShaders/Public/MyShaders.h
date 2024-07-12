// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "RenderGraphBuilder.h"
#include "RenderGraphUtils.h"
#include "../../CustomOctreePlugin/Public/SceneManagerTest.h"

FRDGBufferSRVRef GenerateBufferSRV(FRDGBuilder& GraphBuilder, TArray<int>& data, const TCHAR* Name);

FRDGBufferSRVRef GenerateBufferSRV(FRDGBuilder& GraphBuilder, TArray<FVector3f>& data, const TCHAR* Name);

FRDGBufferSRVRef GenerateBufferSRV(FRDGBuilder& GraphBuilder, TArray<float>& data, const TCHAR* Name);

FRDGBufferUAVRef GenerateBufferUAV(FRDGBuilder& GraphBuilder, TArray<FVector4f>& data, const TCHAR* Name);

float colormap_red(float x);

float colormap_green(float x);

float colormap_blue(float x);

FLinearColor colormap(float x);

class MYSHADERS_API FMyShaders : public IModuleInterface
{
public:
	static inline FMyShaders& Get()
	{
		return FModuleManager::LoadModuleChecked<FMyShaders>("MyShaders");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("MyShaders");
	}

	static void GetSteadyStreamLine(std::vector<int>& index_tbo, std::vector<int>& status_tbo, std::vector<float>& vel_tbo, std::vector<float>& pre_tbo, FSteadyStreamParameters& params);
	static void GetDynamicStreamLine(std::vector<int>& index_tbo, std::vector<int>& status_tbo, std::vector<float>& vel_tbo, std::vector<float>& pre_tbo, FDynamicStreamParameters& params);

public:

	/** IModuleInterface implementation */
	void StartupModule() override;
	void ShutdownModule() override;
};
