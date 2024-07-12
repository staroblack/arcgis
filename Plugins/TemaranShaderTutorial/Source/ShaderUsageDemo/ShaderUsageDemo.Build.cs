// @Author	Fredrik Lindh [Temaran] (temaran@gmail.com) {https://github.com/Temaran}
///////////////////////////////////////////////////////////////////////////////////////

using System.IO;
using UnrealBuildTool;

public class ShaderUsageDemo: ModuleRules
{
	public ShaderUsageDemo(ReadOnlyTargetRules Target) 
		: base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange( new string[] {
				// ... add public include paths required here ...
				Path.Combine(PluginDirectory, "../CustomOctreePlugin/Source/CustomOctreePlugin/Include/"),
                Path.Combine(PluginDirectory, "../CustomOctreePlugin/Source/CustomOctreePlugin/thirdparty/"),
                Path.Combine(PluginDirectory, "../CustomOctreePlugin/Source/CustomOctreePlugin/thirdparty/glm/"),
        //Path.Combine(PluginDirectory, "Source/CustomOctreePlugin/thirdparty/opencv2"),
    }
    );


        PrivateIncludePaths.AddRange(
            new string[] {
				// ... add other private include paths required here ...
				Path.Combine(PluginDirectory, "../CustomOctreePlugin/Source/CustomOctreePlugin/Include/"),
                Path.Combine(PluginDirectory, "../CustomOctreePlugin/Source/CustomOctreePlugin/thirdparty/"),
                Path.Combine(PluginDirectory, "../CustomOctreePlugin/Source/CustomOctreePlugin/thirdparty/glm/"),
				//Path.Combine(PluginDirectory, "Source/CustomOctreePlugin/thirdparty/opencv2"),
			}
            );


        PublicDependencyModuleNames.AddRange(new string[] 
		{ 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"RHI",
            "Slate",
            "SlateCore",
            "ShaderDeclarationDemo",
            "ProceduralMeshComponent",
            "Renderer",
            "RenderCore",
            "Projects"
        });

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "RHI",
            "Slate",
            "SlateCore",
            "ShaderDeclarationDemo",
            "ProceduralMeshComponent",
            "Renderer",
            "RenderCore",
            "Projects"
        });
    }
}
