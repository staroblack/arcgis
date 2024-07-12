// @Author	Fredrik Lindh [Temaran] (temaran@gmail.com) {https://github.com/Temaran}
///////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "CoreMinimal.h"
#include "ShaderDeclarationDemoModule.h"

/**************************************************************************************/
/* This is just an interface we use to keep all the compute shading code in one file. */
/**************************************************************************************/
class FComputeShader_DrawTextureExample
{
public:
	// The Galaxy Simulation demo code shows how to draw to a texture using a Compute Shader.
	//static void modified(FRDGBuilder& RDGBuilder, FRDGBufferRef point, FRDGBufferRef path, TArray<int>& index_tbo_data, TArray<int>& status_tbo_data, TArray<FVector3f>& vel_tbo_data, TArray<float>& pre_tbo_data);
	static void DispatchGalaxySimulation_RenderThread(FRDGBuilder& RDGBuilder, FRDGTextureUAVRef OutputTextureUAV);
};
