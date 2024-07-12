// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class CustomOctreePlugin : ModuleRules
{
	public CustomOctreePlugin(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
				Path.Combine(PluginDirectory, "Source/CustomOctreePlugin/Include/"),
				Path.Combine(PluginDirectory, "Source/CustomOctreePlugin/thirdparty/"),
				Path.Combine(PluginDirectory, "Source/CustomOctreePlugin/thirdparty/glm/"),
				//Path.Combine(PluginDirectory, "Source/CustomOctreePlugin/thirdparty/opencv2"),
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
				Path.Combine(PluginDirectory, "Source/CustomOctreePlugin/Include/"),
				Path.Combine(PluginDirectory, "Source/CustomOctreePlugin/thirdparty/"),
				Path.Combine(PluginDirectory, "Source/CustomOctreePlugin/thirdparty/glm/"),
				//Path.Combine(PluginDirectory, "Source/CustomOctreePlugin/thirdparty/opencv2"),
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
                "Core",
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "Renderer",
                "RenderCore",
                "RHI",
                "Projects",
                "ProceduralMeshComponent",
				"MyShaders"
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
                "Core",
                "CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
                "Renderer",
                "RenderCore",
                "RHI",
                "Projects",
                "ProceduralMeshComponent",
                "MyShaders"
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
