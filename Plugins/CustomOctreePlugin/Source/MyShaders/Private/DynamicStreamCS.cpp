// Fill out your copyright notice in the Description page of Project Settings.


#include "DynamicStreamCS.h"
#include "MyShaders.h"

#include "Modules/ModuleManager.h"
#include "GlobalShader.h"
#include "RenderGraphUtils.h"
#include "ShaderParameterStruct.h"
#include "RenderGraphBuilder.h"
#include "RHIDefinitions.h"

#define THREADGROUPSIZE_X 16
#define THREADGROUPSIZE_Y 1
#define THREADGROUPSIZE_Z 1

class FDynamicStreamCS : public FGlobalShader
{
public:
	DECLARE_GLOBAL_SHADER(FDynamicStreamCS);
	SHADER_USE_PARAMETER_STRUCT(FDynamicStreamCS, FGlobalShader);

	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )

		SHADER_PARAMETER_RDG_BUFFER_UAV(RWBuffer<float4>, positions)
		SHADER_PARAMETER_RDG_BUFFER_UAV(RWBuffer<float4>, pathLine)

		SHADER_PARAMETER_RDG_BUFFER_SRV(Buffer<int>, index_tex)
		SHADER_PARAMETER_RDG_BUFFER_SRV(Buffer<int>, status_tex)
		SHADER_PARAMETER_RDG_BUFFER_SRV(Buffer<float3>, vel_tex)
		SHADER_PARAMETER_RDG_BUFFER_SRV(Buffer<float>, pre_tex)

		SHADER_PARAMETER(int, index_tex_size)
		SHADER_PARAMETER(int, vel_tex_size)

		SHADER_PARAMETER(float, collideForce)
		SHADER_PARAMETER(float, dt)
		SHADER_PARAMETER(int, maxLength)
		SHADER_PARAMETER(float, stepDivider)

		SHADER_PARAMETER(int, index_length)
		SHADER_PARAMETER(int, chunklist_length)

		SHADER_PARAMETER(FVector3f, chunkSize)

		SHADER_PARAMETER(FVector3f, minPos)
		SHADER_PARAMETER(FVector3f, maxPos)
		SHADER_PARAMETER(FVector3f, spacing)
		SHADER_PARAMETER(int, totalLevel)

		SHADER_PARAMETER(int, animateTime)
		SHADER_PARAMETER(int, visibleLength)
		SHADER_PARAMETER(int, invisibleLength)

		SHADER_PARAMETER(int, hack)
		SHADER_PARAMETER(FVector3f, hackPos)
		SHADER_PARAMETER(float, radius)

		END_SHADER_PARAMETER_STRUCT()

public:
	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM5);
	}

	static inline void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
	{
		FGlobalShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);

		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_X"), THREADGROUPSIZE_X);
		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_Y"), THREADGROUPSIZE_Y);
		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_Z"), THREADGROUPSIZE_Z);
	}

	static void Execute(FRHICommandListImmediate& RHICmdList, TArray<int> index_tbo_data, TArray<int> status_tbo_data, TArray<FVector3f> vel_tbo_data, TArray<float> pre_tbo_data, FStreamLineParameters& params)
	{
		if (vel_tbo_data.Num() == 0) return;

		FRDGBuilder GraphBuilder(RHICmdList);
		const TShaderMapRef<FDynamicStreamCS> ComputeShader(GetGlobalShaderMap(GMaxRHIFeatureLevel));
		FRDGBufferSRVRef Index = GenerateBufferSRV(GraphBuilder, index_tbo_data, TEXT("IndexBuffer"));
		FRDGBufferSRVRef Status = GenerateBufferSRV(GraphBuilder, status_tbo_data, TEXT("StatusBuffer"));
		FRDGBufferSRVRef Vel = GenerateBufferSRV(GraphBuilder, vel_tbo_data, TEXT("VelBuffer"));
		FRDGBufferSRVRef Pre = GenerateBufferSRV(GraphBuilder, pre_tbo_data, TEXT("PreBuffer"));

		FRDGBufferUAVRef pointUAV = GenerateBufferUAV(GraphBuilder, params.points, TEXT("point"));
		
		TArray<FVector4f> paths;
		paths.SetNumZeroed(params.points.Num() * params.maxLength);
		FRDGBufferRef pathDesc = CreateStructuredBuffer(
			GraphBuilder,
			TEXT("path"),
			sizeof(FVector4f),
			paths.Num(),
			paths.GetData(),
			sizeof(FVector4f) * paths.Num(),
			ERDGInitialDataFlags::None);

		FRDGBufferUAVRef pathsUAV = GraphBuilder.CreateUAV(pathDesc);

		// set params
		FParameters* PassParameters = GraphBuilder.AllocParameters<FParameters>();
		PassParameters->positions = pointUAV;
		PassParameters->pathLine = pathsUAV;

		PassParameters->index_tex = Index;
		PassParameters->status_tex = Status;
		PassParameters->vel_tex = Vel;
		PassParameters->pre_tex = Pre;

		PassParameters->collideForce = params.collideForce;
		PassParameters->dt = params.dt;
		PassParameters->maxLength = params.maxLength;
		PassParameters->stepDivider = params.stepDivider;
		PassParameters->index_length = params.indexLength;
		PassParameters->chunklist_length = params.chunkListLength;
		PassParameters->chunkSize = params.chunkSize;
		PassParameters->minPos = params.minPos;
		PassParameters->maxPos = params.maxPos;
		PassParameters->spacing = params.spacing;
		PassParameters->totalLevel = params.totalLevel;
		PassParameters->animateTime = params.animateTime;
		PassParameters->visibleLength = params.visibleLength;
		PassParameters->invisibleLength = params.invisibleLength;

		FVector3f hackPos(0.555f, 0.925f, 0.29f);
		PassParameters->hack = params.hack;
		PassParameters->hackPos = hackPos;
		PassParameters->radius = 0.3f;

		//FIntVector GroupCounts = FIntVector(FMath::DivideAndRoundUp((float)params.points.Num(), 16.0f), 1, 1);
		FIntVector GroupCounts = FIntVector(params.points.Num(), 1, 1);
		FComputeShaderUtils::AddPass(GraphBuilder, RDG_EVENT_NAME("DynamicStreamCS"), ERDGPassFlags::Compute, ComputeShader, PassParameters, GroupCounts);
		//UE_LOG(LogTemp, Log, TEXT("threadCount is %f, %f, %f"), threadCount.X, threadCount.Y, threadCount.Z);
		UE_LOG(LogTemp, Log, TEXT("GroupCounts is %i, %i, %i"), GroupCounts.X, GroupCounts.Y, GroupCounts.Z);

		TArray<FVector4f> pathLine;
		pathLine.SetNumZeroed(params.points.Num() * params.maxLength);
		FRHIGPUBufferReadback* GPUBufferReadback = new FRHIGPUBufferReadback(TEXT("MyReadbackBuffer"));
		AddEnqueueCopyPass(GraphBuilder, GPUBufferReadback, pathDesc, sizeof(FVector4f) * pathLine.Num());

		GraphBuilder.Execute();

		ENQUEUE_RENDER_COMMAND(ReadbackSync)(
			[GPUBufferReadback, &pathLine, &params](FRHICommandListImmediate& RHICmdList)
			{
				// Wait until the GPU buffer is ready
				RHICmdList.BlockUntilGPUIdle();

				// Check if the buffer is ready and read the data
				if (GPUBufferReadback->IsReady())
				{
					const void* BufferPtr = GPUBufferReadback->Lock(sizeof(FVector4f) * pathLine.Num());
					FMemory::Memcpy(pathLine.GetData(), BufferPtr, sizeof(FVector4f) * pathLine.Num());
					GPUBufferReadback->Unlock();
				}

				params.pathLine = pathLine;

				float scaleSize = 100.0;
				TArray<FBatchedLine> lines;
				for (int i = 0; i < params.points.Num(); i++)
				{
					for (int j = 0; j < params.maxLength - 1; j++) {
						int offset = i * params.maxLength + j;
						if (offset >= pathLine.Num())
							continue;

						// if not valid dont draw
						if (pathLine[offset].W <= 0 || pathLine[offset + 1].W <= 0)
							continue;

						FVector start = FVector(pathLine[offset].X, pathLine[offset].Y, pathLine[offset].Z);
						FVector end = FVector(pathLine[offset + 1].X, pathLine[offset + 1].Y, pathLine[offset + 1].Z);

						FBatchedLine line = FBatchedLine(start * scaleSize,
							end * scaleSize,
							colormap(pathLine[offset].W / params.maxMag), //pathLine[offset].W = 0.0035 -> red
							0.1, // for long period draw
							0.5,
							0
						);
						lines.Add(line);
					}
				}
				params.lines = lines;
			}
		);
	}
};

IMPLEMENT_GLOBAL_SHADER(FDynamicStreamCS, "/ARShaders/Private/DynamicStreamCS.usf", "MainCS", SF_Compute);

void UDynamicStreamCS::Dispath(TArray<int> index_tbo_data, TArray<int> status_tbo_data, TArray<FVector3f> vel_tbo_data, TArray<float> pre_tbo_data, FStreamLineParameters& params)
{
	ENQUEUE_RENDER_COMMAND(CommandList)(
		[index_tbo_data, status_tbo_data, vel_tbo_data, pre_tbo_data, &params](FRHICommandListImmediate& RHICmdList)
		{
			FDynamicStreamCS::Execute(RHICmdList, index_tbo_data, status_tbo_data, vel_tbo_data, pre_tbo_data, params);
		}
	);
}
