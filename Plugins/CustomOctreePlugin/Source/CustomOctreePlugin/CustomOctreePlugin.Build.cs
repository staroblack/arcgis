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
				Path.Combine(ModuleDirectory, "Include/"),
				Path.Combine(ModuleDirectory, "thirdparty/"),
				Path.Combine(ModuleDirectory, "thirdparty/glm/"),
				//Path.Combine(PluginDirectory, "Source/CustomOctreePlugin/thirdparty/opencv2"),
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
				Path.Combine(ModuleDirectory, "Include/"),
                Path.Combine(ModuleDirectory, "thirdparty/"),
                Path.Combine(ModuleDirectory, "thirdparty/glm/"),
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
				"MyShaders",
				"UMG"
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

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "thirdparty", "lib", "zfp.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "thirdparty", "lib", "assimp-vc141-mt.lib"));
			RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "thirdparty", "dll", "assimp-vc141-mt.dll"));
			RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "thirdparty", "dll", "zfp.dll"));
		}
	}
}
