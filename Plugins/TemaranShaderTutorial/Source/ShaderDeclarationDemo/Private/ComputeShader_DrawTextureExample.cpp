// @Author	Fredrik Lindh [Temaran] (temaran@gmail.com) {https://github.com/Temaran}
///////////////////////////////////////////////////////////////////////////////////////

#include "ComputeShader_DrawTextureExample.h"
#include "ShaderParameterUtils.h"
#include "RHIStaticStates.h"
#include "Shader.h"
#include "GlobalShader.h"
#include "RenderGraphBuilder.h"
#include "RenderGraphUtils.h"
#include "ShaderParameterStruct.h"
#include "UniformBuffer.h"
#include "RHICommandList.h"
#include "Rendering/Texture2DResource.h"
#include "RenderGraph.h"

#define NUM_THREADS_PER_GROUP_DIMENSION 32
#define THREADGROUPSIZE_X 16
#define THREADGROUPSIZE_Y 1
#define THREADGROUPSIZE_Z 1

void AssignValuesToBuffer(FRHICommandListImmediate& RHICmdList, FRHIBuffer* RHIBuffer, const std::vector<uint32>& InputData)
{
	// Get the size of the buffer in bytes
	size_t BufferSize = InputData.size() * sizeof(uint32);

	// Lock the buffer for CPU access
	uint32 DestStride = 0;
	void* BufferData = RHILockBuffer(RHIBuffer, 0, BufferSize, RLM_WriteOnly);

	// Copy data from InputData to the locked buffer
	FMemory::Memcpy(BufferData, InputData.data(), BufferSize);

	// Unlock the buffer
	RHIUnlockBuffer(RHIBuffer);
}

/**********************************************************************************************/
/* This class carries our parameter declarations and acts as the bridge between cpp and HLSL. */
/**********************************************************************************************/
class FGalaxySimulatorExampleCS : public FGlobalShader
{
public:
	DECLARE_GLOBAL_SHADER(FGalaxySimulatorExampleCS);
	SHADER_USE_PARAMETER_STRUCT(FGalaxySimulatorExampleCS, FGlobalShader);

	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER_RDG_TEXTURE_UAV(RWTexture2D<uint>, OutputTexture)
		SHADER_PARAMETER(FVector2f, TextureSize) // Metal doesn't support GetDimensions(), so we send in this data via our parameters.
		SHADER_PARAMETER(float, SimulationState)
	END_SHADER_PARAMETER_STRUCT()

public:
	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM5);
	}

	static inline void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
	{
		FGlobalShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);

		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_X"), NUM_THREADS_PER_GROUP_DIMENSION);
		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_Y"), NUM_THREADS_PER_GROUP_DIMENSION);
		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_Z"), 1);
	}
};

//class FGalaxySimulatorExampleCSSteady : public FGlobalShader
//{
//public:
//	DECLARE_GLOBAL_SHADER(FGalaxySimulatorExampleCSSteady);
//	SHADER_USE_PARAMETER_STRUCT(FGalaxySimulatorExampleCSSteady, FGlobalShader);
//
//	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
//
//		SHADER_PARAMETER_RDG_BUFFER_UAV(RWBuffer<float4>, positions)
//		SHADER_PARAMETER_RDG_BUFFER_UAV(RWBuffer<float4>, pathLine)
//
//		SHADER_PARAMETER_RDG_BUFFER_SRV(StructuredBuffer<int>, index_tex)
//		SHADER_PARAMETER_RDG_BUFFER_SRV(StructuredBuffer<int>, status_tex)
//		SHADER_PARAMETER_RDG_BUFFER_SRV(StructuredBuffer<float3>, vel_tex)
//		SHADER_PARAMETER_RDG_BUFFER_SRV(StructuredBuffer<float>, pre_tex)
//
//		SHADER_PARAMETER(int, index_tex_size)
//		SHADER_PARAMETER(int, vel_tex_size)
//
//		SHADER_PARAMETER(float, collideForce)
//		SHADER_PARAMETER(float, dt)
//		SHADER_PARAMETER(int, maxLength)
//		SHADER_PARAMETER(float, stepDivider)
//
//		SHADER_PARAMETER(int, index_length)
//		SHADER_PARAMETER(int, chunklist_length)
//		SHADER_PARAMETER(FVector3f, chunkSize)
//		SHADER_PARAMETER(FVector3f, minPos)
//		SHADER_PARAMETER(FVector3f, maxPos)
//		SHADER_PARAMETER(FVector3f, spacing)
//		SHADER_PARAMETER(int, totalLevel)
//
//		END_SHADER_PARAMETER_STRUCT()
//
//public:
//	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
//	{
//		return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM5);
//	}
//
//	static inline void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
//	{
//		FGlobalShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);
//
//		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_X"), THREADGROUPSIZE_X);
//		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_Y"), THREADGROUPSIZE_Y);
//		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_Z"), THREADGROUPSIZE_Z);
//	}
//};

// This will tell the engine to create the shader and where the shader entry point is.
//                            ShaderType                                   ShaderPath                            Shader function name    Type
IMPLEMENT_GLOBAL_SHADER(FGalaxySimulatorExampleCS, "/TutorialShaders/Private/ComputeShader_DrawTextureExample.usf", "SimulateGalaxy", SF_Compute);

/**********************************************************************************************/
/* These functions schedule our Compute Shader work from the CPU!							  */
/**********************************************************************************************/

/*void FComputeShader_DrawTextureExample::modified(FRDGBuilder& RDGBuilder, FRDGBufferRef point, FRDGBufferRef path, TArray<int>& index_tbo_data, TArray<int>& status_tbo_data, TArray<FVector3f>& vel_tbo_data, TArray<float>& pre_tbo_data)
{
	QUICK_SCOPE_CYCLE_COUNTER(STAT_ShaderPlugin_DispatchGalaxySimulation);
	SCOPED_DRAW_EVENT(RDGBuilder.RHICmdList, ShaderPlugin_Compute); // Used to profile GPU activity and add metadata to be consumed by for example RenderDoc

	// This shader shows how you can use a compute shader to write to a texture.
	// Here we send our inputs using parameters as part of the shader parameter struct. This is an efficient way of sending in simple constants for a shader, but does not work well if you need to send larger amounts of data.
	FGalaxySimulatorExampleCSSteady::FParameters* ShaderParams = RDGBuilder.AllocParameters<FGalaxySimulatorExampleCSSteady::FParameters>();

	FRDGBufferRef IndexDesc = CreateStructuredBuffer(
		RDGBuilder,
		TEXT("ShaderPlugin_IndexBuffer"),
		sizeof(int),
		index_tbo_data.Num(),
		index_tbo_data.GetData(),
		sizeof(int) * index_tbo_data.Num(),
		ERDGInitialDataFlags::None);
	FRDGBufferSRVRef Index = RDGBuilder.CreateSRV(IndexDesc);

	FRDGBufferRef StatusDesc = CreateStructuredBuffer(
		RDGBuilder,
		TEXT("ShaderPlugin_StatusBuffer"),
		sizeof(int),
		status_tbo_data.Num(),
		status_tbo_data.GetData(),
		sizeof(int) * status_tbo_data.Num(),
		ERDGInitialDataFlags::None);
	FRDGBufferSRVRef Status = RDGBuilder.CreateSRV(StatusDesc);

	FRDGBufferRef VelDesc = CreateStructuredBuffer(
		RDGBuilder,
		TEXT("ShaderPlugin_VelBuffer"),
		sizeof(FVector3f),
		vel_tbo_data.Num(),
		vel_tbo_data.GetData(),
		sizeof(FVector3f) * vel_tbo_data.Num(),
		ERDGInitialDataFlags::None);
	FRDGBufferSRVRef Vel = RDGBuilder.CreateSRV(VelDesc);

	FRDGBufferRef PreDesc = CreateStructuredBuffer(
		RDGBuilder,
		TEXT("ShaderPlugin_PreBuffer"),
		sizeof(float),
		pre_tbo_data.Num(),
		pre_tbo_data.GetData(),
		sizeof(float) * pre_tbo_data.Num(),
		ERDGInitialDataFlags::None);
	FRDGBufferSRVRef Pre = RDGBuilder.CreateSRV(PreDesc);

	// create spawn points
	TArray<FVector4f> points;
	for (int i = 0; i < 100; i++) {
		FVector4f position = FVector4f(0.0f, -0.31f + 0.006263f * i, 0.0f, 0.0f);
		points.Push(position);
	}
	FRDGBufferRef pointDesc = CreateStructuredBuffer(
		RDGBuilder,
		TEXT("point"),
		sizeof(FVector4f),
		points.Num(),
		points.GetData(),
		sizeof(FVector4f) * points.Num(),
		ERDGInitialDataFlags::None);
	FRDGBufferUAVRef pointUAV = RDGBuilder.CreateUAV(pointDesc);

	FRDGBufferUAVRef pathUAV = RDGBuilder.CreateUAV(path);

	// fill in the buffer with vector
	//RDGBuilder.AddPass(
	//	RDG_EVENT_NAME("PointBuffer"),
	//	ERDGPassFlags::None,
	//	[&point, points](FRHICommandListImmediate& RHICmdList)
	//	{
	//		// Get a reference to the buffer's underlying resource
	//		FRHIBuffer* BufferResource = point->GetRHI();

	//		// Map the buffer for writing
	//		void* BufferData = RHILockBuffer(BufferResource, 0, BufferResource->GetSize(), RLM_WriteOnly);

	//		// Write values to the buffer
	//		FMemory::Memcpy(BufferData, &points[0], BufferResource->GetSize());

	//		// Unlock the buffer
	//		RHIUnlockBuffer(BufferResource);
	//	}
	//);

	ShaderParams->positions = pointUAV;
	ShaderParams->pathLine = pathUAV;

	ShaderParams->index_tex = RDGBuilder.CreateSRV(Index);
	ShaderParams->status_tex = RDGBuilder.CreateSRV(Status);
	ShaderParams->vel_tex = RDGBuilder.CreateSRV(Vel);
	ShaderParams->pre_tex = RDGBuilder.CreateSRV(Pre);
	ShaderParams->index_tex = Index;
	ShaderParams->status_tex = Status;
	ShaderParams->vel_tex = Vel;
	ShaderParams->pre_tex = Pre;

	//ShaderParams->index_tex_size = indexTex->GetSizeX();
	//ShaderParams->vel_tex_size = velTex->GetSizeX();

	ShaderParams->collideForce = 1;
	ShaderParams->dt = 0.033;
	ShaderParams->maxLength = 1000;
	ShaderParams->stepDivider = 53;
	ShaderParams->index_length = 3849;
	ShaderParams->chunklist_length = 2726;
	ShaderParams->chunkSize = FVector3f(13, 5, 4);
	ShaderParams->minPos = FVector3f(-1.2425, -0.675, 0);
	ShaderParams->maxPos = FVector3f(2.4325, 0.675, 1.19);
	ShaderParams->spacing = FVector3f(0.00883413f, 0.0084375f, 0.00929688f);
	ShaderParams->totalLevel = 5;

	TShaderMapRef<FGalaxySimulatorExampleCSSteady> ComputeShader(GetGlobalShaderMap(GMaxRHIFeatureLevel));
	FIntVector GroupCounts = FIntVector(FMath::DivideAndRoundUp(100.0f, 16.0f), 1, 1);
	FComputeShaderUtils::AddPass(RDGBuilder, RDG_EVENT_NAME("GalaxySimulation"), ERDGPassFlags::Compute | ERDGPassFlags::NeverCull, ComputeShader, ShaderParams, GroupCounts);
	//RDGBuilder.Execute();
}*/

void FComputeShader_DrawTextureExample::DispatchGalaxySimulation_RenderThread(FRDGBuilder& RDGBuilder, FRDGTextureUAVRef OutputTextureUAV)
{
	QUICK_SCOPE_CYCLE_COUNTER(STAT_ShaderPlugin_DispatchGalaxySimulation);
	SCOPED_DRAW_EVENT(RDGBuilder.RHICmdList, ShaderPlugin_Compute); // Used to profile GPU activity and add metadata to be consumed by for example RenderDoc

	// This shader shows how you can use a compute shader to write to a texture.
	// Here we send our inputs using parameters as part of the shader parameter struct. This is an efficient way of sending in simple constants for a shader, but does not work well if you need to send larger amounts of data.
	FGalaxySimulatorExampleCS::FParameters* ShaderParams = RDGBuilder.AllocParameters<FGalaxySimulatorExampleCS::FParameters>();
	ShaderParams->OutputTexture = OutputTextureUAV;
	ShaderParams->TextureSize = FVector2f(128, 128);
	ShaderParams->SimulationState = 1;

	TShaderMapRef<FGalaxySimulatorExampleCS> ComputeShader(GetGlobalShaderMap(GMaxRHIFeatureLevel));
	FIntVector GroupCounts = FIntVector(FMath::DivideAndRoundUp(128, NUM_THREADS_PER_GROUP_DIMENSION), FMath::DivideAndRoundUp(128, NUM_THREADS_PER_GROUP_DIMENSION), 1);
	FComputeShaderUtils::AddPass(RDGBuilder, RDG_EVENT_NAME("GalaxySimulation"), ERDGPassFlags::Compute | ERDGPassFlags::NeverCull, ComputeShader, ShaderParams, GroupCounts);
}