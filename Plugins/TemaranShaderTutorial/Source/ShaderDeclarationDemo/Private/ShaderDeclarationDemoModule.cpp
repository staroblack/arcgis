// @Author	Fredrik Lindh [Temaran] (temaran@gmail.com) {https://github.com/Temaran}
///////////////////////////////////////////////////////////////////////////////////////

#include "ShaderDeclarationDemoModule.h"

#include "ComputeShader_DataUploadAndReadbackExample.h"
#include "ComputeShader_DrawTextureExample.h"
#include "VertexAndPixelShader_FullscreenTexturedQuadExample.h"

#include "Misc/Paths.h"
#include "Misc/FileHelper.h"
#include "RHI.h"
#include "GlobalShader.h"
#include "RHICommandList.h"
#include "RenderGraphBuilder.h"
#include "RenderTargetPool.h"
#include "Runtime/Core/Public/Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"
#include "Runtime/Engine/Classes/Engine/Texture2D.h"
#include "RenderGraphUtils.h"
#include "Components/LineBatchComponent.h"
#include <fstream>

IMPLEMENT_MODULE(FShaderDeclarationDemoModule, ShaderDeclarationDemo)

// Declare some GPU stats so we can track them later
DECLARE_GPU_STAT_NAMED(ShaderPlugin_Render, TEXT("ShaderPlugin: Root Render"));
DECLARE_GPU_STAT_NAMED(ShaderPlugin_Compute, TEXT("ShaderPlugin: Render Compute Shader"));
DECLARE_GPU_STAT_NAMED(ShaderPlugin_Pixel, TEXT("ShaderPlugin: Render Pixel Shader"));

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

void FShaderDeclarationDemoModule::StartupModule()
{
	// Maps virtual shader source directory to the plugin's actual shaders directory.
	FString PluginShaderDir = FPaths::Combine(IPluginManager::Get().FindPlugin(TEXT("TemaranShaderTutorial"))->GetBaseDir(), TEXT("Shaders"));
	AddShaderSourceDirectoryMapping(TEXT("/TutorialShaders"), PluginShaderDir);
}

void FShaderDeclarationDemoModule::ShutdownModule()
{
	EndRendering();
}

void FShaderDeclarationDemoModule::BeginRendering(std::vector<int>& index_tbo, std::vector<int>& status_tbo, std::vector<float>& vel_tbo, std::vector<float>& pre_tbo, ULineBatchComponent* l)
{
	
	if (!GEngine)
	{
		return;
	}

	{
		FScopeLock EmptyLock(&ReduceSummationWorkSet.WorkSetLock);
		ReduceSummationWorkSet.ReduceSummationWork.Empty();
	}

	bCachedParametersValid = false;
	if (!GEngine->GetPreRenderDelegateEx().IsBoundToObject(this))
	{
		GEngine->GetPreRenderDelegateEx().AddRaw(this, &FShaderDeclarationDemoModule::HandlePreRender_RenderThread);
	}
}

void FShaderDeclarationDemoModule::EndRendering()
{
	if (!GEngine)
	{
		return;
	}

	GEngine->GetPreRenderDelegateEx().RemoveAll(this);
}

void FShaderDeclarationDemoModule::UpdateParameters(FShaderUsageExampleParameters& DrawParameters)
{
	FScopeLock UpdateLock(&InputLock);

	CachedShaderUsageExampleParameters = DrawParameters;
	bCachedParametersValid = true;
}

void FShaderDeclarationDemoModule::GetCompletedSummationRequests(TMap<int32, FIntegerSummationResult>& OutNewCompletedResults)
{
	FScopeLock CompleteRequestsLock(&ReduceSummationWorkSet.WorkSetLock);

	// Copy to the output map.
	for (auto& [RequestId, WorkData] : ReduceSummationWorkSet.ReduceSummationWork)
	{
		if (WorkData.bReadbackComplete)
		{
			OutNewCompletedResults.Add(RequestId, WorkData);
		}
	}

	// Remove acquired jobs from the active work set.
	for (auto& [RequestId, WorkData] : OutNewCompletedResults)
	{
		ReduceSummationWorkSet.ReduceSummationWork.Remove(RequestId);
	}
}

void FShaderDeclarationDemoModule::HandlePreRender_RenderThread(FRDGBuilder& RDGBuilder)
{
	check(IsInRenderingThread());

	/*if (!bCachedParametersValid)
	{
		return;
	}*/

	// Depending on your data, you might not have to lock here, just added this code to show how you can do it if you have to.
	/*InputLock.Lock();
	FShaderUsageExampleParameters InputParameters = CachedShaderUsageExampleParameters;
	InputLock.Unlock();*/
	
	/*if (!InputParameters.RenderTarget)
	{
		return;
	}*/

	QUICK_SCOPE_CYCLE_COUNTER(STAT_ShaderPlugin_Render); // Used to gather CPU profiling data for Unreal Insights! Insights is a really powerful tool for debugging CPU stats, memory and networking.
	SCOPED_DRAW_EVENT(RDGBuilder.RHICmdList, ShaderPlugin_Render); // Used to profile GPU activity and add metadata to be consumed by for example RenderDoc

	// The graph will help us figure out when the GPU memory is needed, and only have it allocated from then, so this makes memory management a lot easier and nicer!
	FRDGTextureDesc ComputeShaderOutputDesc = FRDGTextureDesc::Create2D(FIntPoint(256), EPixelFormat::PF_R32_UINT, FClearValueBinding::None, ETextureCreateFlags::RenderTargetable | ETextureCreateFlags::UAV | ETextureCreateFlags::ShaderResource);
	FRDGTextureRef OutputTexture = RDGBuilder.CreateTexture(ComputeShaderOutputDesc, TEXT("ShaderPlugin_ComputeShaderOutput"), ERDGTextureFlags::None);
	

	//FComputeShader_DrawTextureExample::modified(RDGBuilder, point, pathDesc, index_tbo_data, status_tbo_data, vel_tbo_data, pre_tbo_data);
	//FComputeShader_DrawTextureExample::DispatchGalaxySimulation_RenderThread(RDGBuilder, RDGBuilder.CreateUAV(OutputTexture));

	//FVertexAndPixelShader_FullscreenTexturedQuadExample::DrawToRenderTarget_RenderThread(RDGBuilder, InputParameters, RDGBuilder.CreateSRV(OutputTexture));
}