// Fill out your copyright notice in the Description page of Project Settings.

#include "MyShaders.h"
#include "Logging.h"
#include "Interfaces/IPluginManager.h"
#include "Modules/ModuleManager.h"
#include "SteadyStreamCS.h"
#include "DynamicStreamCS.h"
#include "IsosurfaceCS.h"

#define LOCTEXT_NAMESPACE "FMyShaders"

FRDGBufferSRVRef GenerateBufferSRV(FRDGBuilder& GraphBuilder, TArray<int>& data, const TCHAR* Name) {
	FRDGBufferRef BufferDesc = CreateStructuredBuffer(
		GraphBuilder,
		Name,
		sizeof(int),
		data.Num(),
		data.GetData(),
		sizeof(int) * data.Num(),
		ERDGInitialDataFlags::None);
	return GraphBuilder.CreateSRV(BufferDesc);
}

FRDGBufferSRVRef GenerateBufferSRV(FRDGBuilder& GraphBuilder, TArray<FVector3f>& data, const TCHAR* Name) {
	FRDGBufferRef BufferDesc = CreateStructuredBuffer(
		GraphBuilder,
		Name,
		sizeof(FVector3f),
		data.Num(),
		data.GetData(),
		sizeof(FVector3f) * data.Num(),
		ERDGInitialDataFlags::None);
	return GraphBuilder.CreateSRV(BufferDesc);
}

FRDGBufferSRVRef GenerateBufferSRV(FRDGBuilder& GraphBuilder, TArray<float>& data, const TCHAR* Name) {
	FRDGBufferRef BufferDesc = CreateStructuredBuffer(
		GraphBuilder,
		Name,
		sizeof(float),
		data.Num(),
		data.GetData(),
		sizeof(float) * data.Num(),
		ERDGInitialDataFlags::None);
	return GraphBuilder.CreateSRV(BufferDesc);
}

FRDGBufferUAVRef GenerateBufferUAV(FRDGBuilder& GraphBuilder, TArray<FVector4f>& data, const TCHAR* Name) {
	FRDGBufferRef BufferDesc = CreateStructuredBuffer(
		GraphBuilder,
		Name,
		sizeof(FVector4f),
		data.Num(),
		data.GetData(),
		sizeof(FVector4f) * data.Num(),
		ERDGInitialDataFlags::None);
	return GraphBuilder.CreateUAV(BufferDesc);
}

FRDGBufferUAVRef GenerateBufferUAV(FRDGBuilder& GraphBuilder, TArray<FVector3f>& data, const TCHAR* Name) {
	FRDGBufferRef BufferDesc = CreateStructuredBuffer(
		GraphBuilder,
		Name,
		sizeof(FVector3f),
		data.Num(),
		data.GetData(),
		sizeof(FVector3f) * data.Num(),
		ERDGInitialDataFlags::None);
	return GraphBuilder.CreateUAV(BufferDesc);
}

float colormap_red(float x) {
	if (x < 0.7) {
		return 4.0 * x - 1.5;
	}
	else {
		return -4.0 * x + 4.5;
	}
}

float colormap_green(float x) {
	if (x < 0.5) {
		return 4.0 * x - 0.5;
	}
	else {
		return -4.0 * x + 3.5;
	}
}

float colormap_blue(float x) {
	if (x < 0.3) {
		return 4.0 * x + 0.5;
	}
	else {
		return -4.0 * x + 2.5;
	}
}

FLinearColor colormap(float x) {
	float r = clamp(colormap_red(x), 0.0f, 1.0f);
	float g = clamp(colormap_green(x), 0.0f, 1.0f);
	float b = clamp(colormap_blue(x), 0.0f, 1.0f);
	return FLinearColor(r, g, b, 1);
}

void AssignVectorToTArray(const std::vector<int>& SourceVector, TArray<int>& TargetArray)
{
	// Resize the TArray to match the size of the std::vector
	TargetArray.SetNum(SourceVector.size());
	// Copy the data from std::vector to TArray
	FMemory::Memcpy(TargetArray.GetData(), SourceVector.data(), SourceVector.size() * sizeof(int));
}

void AssignVectorToTArray(const std::vector<float>& SourceVector, TArray<float>& TargetArray)
{
	// Resize the TArray to match the size of the std::vector
	TargetArray.SetNum(SourceVector.size());
	// Copy the data from std::vector to TArray
	FMemory::Memcpy(TargetArray.GetData(), SourceVector.data(), SourceVector.size() * sizeof(float));
}

void FMyShaders::StartupModule()
{
	// Maps virtual shader source directory to the plugin's actual shaders directory.
	FString PluginShaderDir = FPaths::Combine(IPluginManager::Get().FindPlugin(TEXT("CustomOctreePlugin"))->GetBaseDir(), TEXT("Shaders"));
	AddShaderSourceDirectoryMapping(TEXT("/ARShaders"), PluginShaderDir);
}

void FMyShaders::ShutdownModule()
{
}

void FMyShaders::GetSteadyStreamLine(std::vector<int>& index_tbo, std::vector<int>& status_tbo, std::vector<float>& vel_tbo, std::vector<float>& pre_tbo, ASceneManagerTest::FStreamLineParameters& params) {
	TArray<int> index_tbo_data;
	TArray<int> status_tbo_data;
	TArray<FVector3f> vel_tbo_data;
	TArray<float> pre_tbo_data;

	AssignVectorToTArray(index_tbo, index_tbo_data);
	AssignVectorToTArray(status_tbo, status_tbo_data);
	for (int i = 0; i < vel_tbo.size(); i += 3) {
		FVector3f data = FVector3f(vel_tbo[i], vel_tbo[i + 1], vel_tbo[i + 2]);
		vel_tbo_data.Push(data);
	}
	AssignVectorToTArray(pre_tbo, pre_tbo_data);

	USteadyStreamCS::Dispath(index_tbo_data, status_tbo_data, vel_tbo_data, pre_tbo_data, params);
}

void FMyShaders::GetDynamicStreamLine(std::vector<int>& index_tbo, std::vector<int>& status_tbo, std::vector<float>& vel_tbo, std::vector<float>& pre_tbo, ASceneManagerTest::FStreamLineParameters& params) {
	TArray<int> index_tbo_data;
	TArray<int> status_tbo_data;
	TArray<FVector3f> vel_tbo_data;
	TArray<float> pre_tbo_data;

	AssignVectorToTArray(index_tbo, index_tbo_data);
	AssignVectorToTArray(status_tbo, status_tbo_data);
	for (int i = 0; i < vel_tbo.size(); i += 3) {
		FVector3f data = FVector3f(vel_tbo[i], vel_tbo[i + 1], vel_tbo[i + 2]);
		vel_tbo_data.Push(data);
	}
	AssignVectorToTArray(pre_tbo, pre_tbo_data);

	UDynamicStreamCS::Dispath(index_tbo_data, status_tbo_data, vel_tbo_data, pre_tbo_data, params);
}

void FMyShaders::GetIsosufacePos(std::vector<float>& isosurfacePointList, std::vector<int>& index_tbo, std::vector<int>& status_tbo, std::vector<float>& vel_tbo, std::vector<float>& temp_tbo, ASceneManagerTest::FIsosurfaceParameters& params) {
	TArray<int> index_tbo_data;
	TArray<int> status_tbo_data;
	TArray<FVector3f> vel_tbo_data;
	TArray<float> temp_tbo_data;

	AssignVectorToTArray(index_tbo, index_tbo_data);
	AssignVectorToTArray(status_tbo, status_tbo_data);
	AssignVectorToTArray(temp_tbo, temp_tbo_data);
	for (int i = 0; i < vel_tbo.size(); i += 3) {
		FVector3f data = FVector3f(vel_tbo[i], vel_tbo[i + 1], vel_tbo[i + 2]);
		vel_tbo_data.Push(data);
	}
	params.isosurfacePoint.Empty();
	for (int i = 0; i < isosurfacePointList.size(); i += 3) {
		FVector4f data = FVector4f(isosurfacePointList[i], isosurfacePointList[i + 1], isosurfacePointList[i + 2], 0);
		params.isosurfacePoint.Push(data);
	}
	
	UIsosurfaceCS::Dispath(index_tbo_data, status_tbo_data, vel_tbo_data, temp_tbo_data, params);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMyShaders, MyShaders);