// Some copyright should be here...

using System.IO;
using UnrealBuildTool;

public class MapSystem : ModuleRules
{

    public MapSystem(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        string projPath = Path.Combine(Path.GetFullPath(Path.Combine(ModuleDirectory, "../../../../ThirdParty/")), "PROJ");
        PublicIncludePaths.AddRange(
			new string[] {
                
				// ... add public include paths required here ...
			}
            );
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
                "Json",
				"MeshDescription",
				"StaticMeshDescription",
				"MeshConversion"
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"Json",
				"JsonUtilities",
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);

        PublicAdditionalLibraries.Add(Path.Combine(projPath, "lib", "proj.lib"));
        PublicIncludePaths.Add(Path.Combine(projPath, "include"));
    }
}
