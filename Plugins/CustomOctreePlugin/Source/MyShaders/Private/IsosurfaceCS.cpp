// Fill out your copyright notice in the Description page of Project Settings.


#include "IsosurfaceCS.h"
#include "MyShaders.h"
#include "MC_Edge.h"

#include "Modules/ModuleManager.h"
#include "GlobalShader.h"
#include "RenderGraphUtils.h"
#include "ShaderParameterStruct.h"
#include "RenderGraphBuilder.h"
#include "RHIDefinitions.h"


//#define THREADGROUPSIZE_X 1024
//#define THREADGROUPSIZE_Y 1
//#define THREADGROUPSIZE_Z 1

BEGIN_SHADER_PARAMETER_STRUCT(FExtractBufferParameters, )
	RDG_BUFFER_ACCESS(Source, ERHIAccess::CopySrc)
END_SHADER_PARAMETER_STRUCT()

class FIsosurfaceCS : public FGlobalShader
{
public:
	DECLARE_GLOBAL_SHADER(FIsosurfaceCS);
	SHADER_USE_PARAMETER_STRUCT(FIsosurfaceCS, FGlobalShader);

	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER_RDG_BUFFER_UAV(RWBuffer<float4>, inPos)

		SHADER_PARAMETER_RDG_BUFFER_UAV(RWBuffer<float4>, outPos)
		//SHADER_PARAMETER_RDG_BUFFER_UAV(RWBuffer<float3>, outNormal)
		//SHADER_PARAMETER_RDG_BUFFER_UAV(RWBuffer<int>, outTris)

		SHADER_PARAMETER_RDG_BUFFER_SRV(Buffer<int>, index_tex)
		SHADER_PARAMETER_RDG_BUFFER_SRV(Buffer<int>, status_tex)
		SHADER_PARAMETER_RDG_BUFFER_SRV(Buffer<float3>, vel_tex)
		SHADER_PARAMETER_RDG_BUFFER_SRV(Buffer<float>, temp_tex)
		SHADER_PARAMETER_RDG_BUFFER_SRV(Buffer<int>, MC_Edge_Trigger_tex)
		SHADER_PARAMETER_RDG_BUFFER_SRV(Buffer<int>, MC_Edge_Connect_tex)

		SHADER_PARAMETER(int, index_length)
		SHADER_PARAMETER(int, chunklist_length)

		SHADER_PARAMETER(FMatrix44f, proj)
		SHADER_PARAMETER(FMatrix44f, model)

		SHADER_PARAMETER(FVector3f, chunkSize)
		
		SHADER_PARAMETER(FVector3f, minPos)
		SHADER_PARAMETER(FVector3f, maxPos)
		SHADER_PARAMETER(FVector3f, spacing)
		SHADER_PARAMETER(int, totalLevel)

		SHADER_PARAMETER(int, isQCritirea)

		SHADER_PARAMETER(float, isovalue)

		SHADER_PARAMETER(FVector3f, center)
		SHADER_PARAMETER(float, scale)

		END_SHADER_PARAMETER_STRUCT()

public:
	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM5);
	}

	static inline void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
	{
		FGlobalShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);

		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_X"), 1024);
		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_Y"), 1);
		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_Z"), 1);
	}

	static void Execute(FRHICommandListImmediate& RHICmdList, TArray<int> index_tbo_data, TArray<int> status_tbo_data, TArray<FVector3f> vel_tbo_data, TArray<float> temp_tbo_data, ASceneManagerTest::FIsosurfaceParameters& params)
	{
		if (vel_tbo_data.Num() == 0) return;

		FRDGBuilder GraphBuilder(RHICmdList);
		const TShaderMapRef<FIsosurfaceCS> ComputeShader(GetGlobalShaderMap(GMaxRHIFeatureLevel));

		// SRV
		FRDGBufferSRVRef Index = GenerateBufferSRV(GraphBuilder, index_tbo_data, TEXT("IndexBuffer"));
		FRDGBufferSRVRef Status = GenerateBufferSRV(GraphBuilder, status_tbo_data, TEXT("StatusBuffer"));
		FRDGBufferSRVRef Vel = GenerateBufferSRV(GraphBuilder, vel_tbo_data, TEXT("VelBuffer"));
		FRDGBufferSRVRef Temp = GenerateBufferSRV(GraphBuilder, temp_tbo_data, TEXT("TempBuffer"));

		TArray<int> MC_Edge_Trigger_tbo;
		for (int i = 0; i < 256; i++)
			MC_Edge_Trigger_tbo.Add(MC_Edge_Trigger[i]);

		TArray<int> MC_Edge_Connect_tbo;
		for (int i = 0; i < 4096; i++)
			MC_Edge_Connect_tbo.Add(MC_Edge_Connect[i]);

		FRDGBufferSRVRef MCEdgeTrigger = GenerateBufferSRV(GraphBuilder, MC_Edge_Trigger_tbo, TEXT("MCEdgeTriggerBuffer"));
		FRDGBufferSRVRef MCEdgeConnect = GenerateBufferSRV(GraphBuilder, MC_Edge_Connect_tbo, TEXT("MCEdgeConnectBuffer"));

		// UAV
		FRDGBufferUAVRef inPos = GenerateBufferUAV(GraphBuilder, params.isosurfacePoint, TEXT("IsosurfacePoints"));

		const FIntVector MeshExtent = FIntVector(params.chunkSize.X, params.chunkSize.Y, params.chunkSize.Z) * cbrt(params.chunkListLength) + FIntVector(1);
		const int NumPos = (MeshExtent.X - 1) * MeshExtent.Y * MeshExtent.Z +
			MeshExtent.X * (MeshExtent.Y - 1) * MeshExtent.Z +
			MeshExtent.X * MeshExtent.Y * (MeshExtent.Z - 1);
		const int NumCells = params.chunkSize.X * params.chunkSize.Y * params.chunkSize.Z * params.chunkListLength;
		const int NumTris = NumCells * 3 * 5;

		TArray<FVector4f> OutPos;
		OutPos.Init(FVector4f(-1, -1, -1, -1), NumTris);
		FRDGBufferRef outPosDesc = CreateStructuredBuffer(
			GraphBuilder,
			TEXT("OutputPoints"),
			sizeof(FVector4f),
			OutPos.Num(),
			OutPos.GetData(),
			sizeof(FVector4f) * OutPos.Num(),
			ERDGInitialDataFlags::None);
		FRDGBufferUAVRef outPos = GraphBuilder.CreateUAV(outPosDesc);

		// set params
		FParameters* PassParameters = GraphBuilder.AllocParameters<FParameters>();
		PassParameters->inPos = inPos;

		PassParameters->outPos = outPos;

		PassParameters->index_tex = Index;
		PassParameters->status_tex = Status;
		PassParameters->vel_tex = Vel;
		PassParameters->temp_tex = Temp;
		PassParameters->MC_Edge_Trigger_tex = MCEdgeTrigger;
		PassParameters->MC_Edge_Connect_tex = MCEdgeConnect;

		PassParameters->index_length = params.indexLength;
		PassParameters->chunklist_length = params.chunkListLength;

		PassParameters->proj = params.viewProj;
		PassParameters->model = params.model;

		PassParameters->chunkSize = params.chunkSize;
		PassParameters->minPos = params.minPos;
		PassParameters->maxPos = params.maxPos;
		PassParameters->spacing = params.spacing;
		PassParameters->totalLevel = params.totalLevel;

		PassParameters->isQCritirea = params.isQCritirea;
		PassParameters->isovalue = params.isovalue;
		
		PassParameters->center = FVector3f(params.center);
		PassParameters->scale = params.myScale;


		FVector3f threadCount = cbrt(params.chunkListLength) * params.chunkSize;
		FIntVector GroupCounts = FComputeShaderUtils::GetGroupCount(FIntVector(threadCount.X * threadCount.Y * threadCount.Z, 1, 1), FIntVector(1024, 1, 1));

		FComputeShaderUtils::AddPass(GraphBuilder, RDG_EVENT_NAME("IsosurfaceCS"), ERDGPassFlags::Compute, ComputeShader, PassParameters, GroupCounts);

		FExtractBufferParameters* Parameters = GraphBuilder.AllocParameters<FExtractBufferParameters>();
		Parameters->Source = outPosDesc;
		
		OutPos.Empty();
		OutPos.SetNumZeroed(NumTris);

		GraphBuilder.AddPass(
			RDG_EVENT_NAME("PooledBufferDownload(%s)", outPosDesc->Name),
			Parameters,
			ERDGPassFlags::Copy | ERDGPassFlags::NeverCull,
			[Parameters, &OutPos, NumTris](FRHICommandListImmediate& RHICmdList)
			{
				void* PSource = RHICmdList.LockBuffer(Parameters->Source->GetRHI(), 0, NumTris * sizeof(FVector4f), RLM_ReadOnly);
				FMemory::Memcpy(OutPos.GetData(), PSource, NumTris * sizeof(FVector4f));
				RHICmdList.UnlockBuffer(Parameters->Source->GetRHI());
			}
		);
		
		GraphBuilder.Execute();

		TArray<int> reverseTris;
		params.outputPos.Empty();
		params.OutTris.Empty();

		int count = 0;
		int offset[3] = { 0, 1, -1 };
		for (int i = 0; i < OutPos.Num(); i++) {
			if (OutPos[i] == FVector4f(-1, -1, -1, -1))
				continue;

			params.OutTris.Add(count);
			params.outputPos.Add(FVector(OutPos[i]));
			count++;
		}
	}
};

IMPLEMENT_GLOBAL_SHADER(FIsosurfaceCS, "/ARShaders/Private/IsosurfaceCS.usf", "MainCS", SF_Compute);

void UIsosurfaceCS::Dispath(TArray<int> index_tbo_data, TArray<int> status_tbo_data, TArray<FVector3f> vel_tbo_data, TArray<float> temp_tbo_data, ASceneManagerTest::FIsosurfaceParameters& params)
{
	ENQUEUE_RENDER_COMMAND(CommandList)(
		[index_tbo_data, status_tbo_data, vel_tbo_data, temp_tbo_data, &params](FRHICommandListImmediate& RHICmdList)
		{
			FIsosurfaceCS::Execute(RHICmdList, index_tbo_data, status_tbo_data, vel_tbo_data, temp_tbo_data, params);
		}
	);
}