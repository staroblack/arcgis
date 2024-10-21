// Some copyright should be here...

using System.IO;
using UnrealBuildTool;

public class CityGISUtil : ModuleRules
{
    private string ThirdPartyPath
    {
        get { return Path.GetFullPath(Path.Combine(ModuleDirectory, "../../../../ThirdParty/")); }
    }

    public CityGISUtil(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        // disable C4668 Warning
        bEnableUndefinedIdentifierWarnings = false;

        // C4541 dynamic cast error
        bUseRTTI = true;

        // Start OpenCV linking here!
        bool isLibrarySupported = false;

        // Create LDLib Path 
        string LDLibPath = Path.Combine(ThirdPartyPath, "LDLib");
        string OpenCLPath = Path.Combine(ThirdPartyPath, "OpenCL");
        string libPath = Path.Combine(ThirdPartyPath, "lib");
        string dllPath = Path.Combine(ThirdPartyPath, "dll");
        string cdtPath = Path.Combine(ThirdPartyPath, "CDT");
        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            isLibrarySupported = true;
        }

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
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);

        if (isLibrarySupported)
        {
            //Add Static Libraries
            //PublicAdditionalLibraries.Add(Path.Combine(LDLibPath, "build", "bin", "Release", "LandscapeDesigner.lib"));
            //PublicAdditionalLibraries.Add(Path.Combine(LDLibPath, "build", "bin", "Release", "eTenderXml.lib"));
            //PublicAdditionalLibraries.Add(Path.Combine(LDLibPath, "3rdparty", "gmp", "lib", "libgmp-10.lib"));
            //PublicAdditionalLibraries.Add(Path.Combine(LDLibPath, "3rdparty", "opencv", "x64", "vc14", "lib", "opencv_world460.lib"));
            //PublicAdditionalLibraries.Add(Path.Combine(LDLibPath, "3rdparty", "GLEW", "lib", "glew32.lib"));
            //PublicAdditionalLibraries.Add(Path.Combine(LDLibPath, "3rdparty", "GLFW", "lib", "glfw3.lib"));
            //PublicAdditionalLibraries.Add(Path.Combine(LDLibPath, "3rdparty", "glog", "buildvc", "Release", "glog.lib"));
            //PublicAdditionalLibraries.Add(Path.Combine(LDLibPath, "3rdparty", "Embree", "lib", "embree3.lib"));
            //PublicAdditionalLibraries.Add(Path.Combine(LDLibPath, "3rdparty", "libdxfrw", "vs2015", "x64", "Release", "libdxfrw.lib"));
            //PublicAdditionalLibraries.Add(Path.Combine(LDLibPath, "3rdparty", "boost-1_70_0", "lib", "Win64", "boost_system-vc142-mt-x64-1_70.lib"));
            //PublicAdditionalLibraries.Add(Path.Combine(LDLibPath, "3rdparty", "xz-5.2.5", "windows", "vs2015", "Release", "x64", "liblzma_dll", "liblzma.lib"));
            //PublicAdditionalLibraries.Add(Path.Combine(LDLibPath, "3rdparty", "libiconv-for-Windows", "lib64", "libiconvStatic.lib"));
            //PublicAdditionalLibraries.Add(Path.Combine(LDLibPath, "3rdparty", "SketchUpSDK", "binaries", "sketchup", "x64", "SketchUpAPI.lib"));
            //PublicAdditionalLibraries.Add(Path.Combine(LDLibPath, "3rdparty", "armadillo-10.7.1", "lib", "armadillo.lib"));
            //PublicAdditionalLibraries.Add(Path.Combine(LDLibPath, "3rdparty", "blas", "lib", "libblas.lib"));
            //PublicAdditionalLibraries.Add(Path.Combine(LDLibPath, "3rdparty", "lapack", "lib", "liblapack.lib"));
            //PublicAdditionalLibraries.Add(Path.Combine(LDLibPath, "3rdparty", "superlu-5.3.0", "lib", "superlu.lib"));
            //PublicAdditionalLibraries.Add(Path.Combine(LDLibPath, "3rdparty", "CURL", "lib", "libcurl_imp.lib"));
            //PublicAdditionalLibraries.Add(Path.Combine(OpenCLPath, "lib", "x64", "OpenCL.lib"));
            //PublicAdditionalLibraries.Add(Path.Combine(libPath, "OpenGL32.lib"));
            //PublicAdditionalLibraries.Add(Path.Combine(libPath, "GLU32.lib"));
            //PublicAdditionalLibraries.Add(Path.Combine(libPath, "psapi.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(cdtPath, "lib", "x64", "Release", "CDT.lib"));

            //PublicIncludePaths.Add(Path.Combine(LDLibPath));
            //PublicIncludePaths.Add(Path.Combine(LDLibPath, "3rdparty"));
            //PublicIncludePaths.Add(Path.Combine(LDLibPath, "3rdparty", "gmp", "include"));
            //PublicIncludePaths.Add(Path.Combine(LDLibPath, "3rdparty", "CGAL-5.5", "include"));
            //PublicIncludePaths.Add(Path.Combine(LDLibPath, "3rdparty", "blender", "blenlib"));
            //PublicIncludePaths.Add(Path.Combine(LDLibPath, "3rdparty", "blender", "blenkernel"));
            //PublicIncludePaths.Add(Path.Combine(LDLibPath, "3rdparty", "blender", "makesdna"));
            //PublicIncludePaths.Add(Path.Combine(LDLibPath, "3rdparty", "blender", "bmesh"));
            //PublicIncludePaths.Add(Path.Combine(LDLibPath, "3rdparty", "CURL", "include"));
            //PublicIncludePaths.Add(Path.Combine(LDLibPath, "3rdparty", "vcglib-1.0.1"));
            //PublicIncludePaths.Add(Path.Combine(LDLibPath, "3rdparty", "json-develop", "include"));
            //PublicIncludePaths.Add(Path.Combine(LDLibPath, "3rdparty", "opencv", "include"));
            //PublicIncludePaths.Add(Path.Combine(LDLibPath, "3rdparty", "Eigen"));
            //PublicIncludePaths.Add(Path.Combine(LDLibPath, "3rdparty", "GLEW", "include"));
            //PublicIncludePaths.Add(Path.Combine(LDLibPath, "3rdparty", "GLFW", "include"));
            //PublicIncludePaths.Add(Path.Combine(LDLibPath, "3rdparty", "glog", "src", "windows"));
            //PublicIncludePaths.Add(Path.Combine(LDLibPath, "3rdparty", "Embree", "include"));
            //PublicIncludePaths.Add(Path.Combine(LDLibPath, "3rdparty", "libdxfrw", "src"));
            //PublicIncludePaths.Add(Path.Combine(LDLibPath, "3rdparty", "boost-1_70_0", "include"));
            //PublicIncludePaths.Add(Path.Combine(LDLibPath, "3rdparty", "xz-5.2.5", "src", "liblzma", "api"));
            //PublicIncludePaths.Add(Path.Combine(LDLibPath, "3rdparty", "libiconv-for-Windows", "include"));
            //PublicIncludePaths.Add(Path.Combine(LDLibPath, "3rdparty", "SketchUpSDK", "headers"));
            //PublicIncludePaths.Add(Path.Combine(LDLibPath, "3rdparty", "armadillo-10.7.1", "include"));
            //PublicIncludePaths.Add(Path.Combine(LDLibPath, "spline", "include"));
            //PublicIncludePaths.Add(Path.Combine(LDLibPath, "commonWrapper", "headerOnly"));
            //PublicIncludePaths.Add(Path.Combine(LDLibPath, "commonWrapper", "src"));
            //PublicIncludePaths.Add(Path.Combine(OpenCLPath, "include"));
            PublicIncludePaths.Add(Path.Combine(cdtPath, "include"));


            //if (Target.Platform == UnrealTargetPlatform.Win64)
            //{
            //    PublicDefinitions.Add("CURL_STATICLIB");
            //    PublicDefinitions.Add("GLOG_NO_ABBREVIATED_SEVERITIES");
            //    PublicDefinitions.Add("CGAL_HEADER_ONLY");
            //    PublicDefinitions.Add("USING_OPENCL");
            //    PublicDefinitions.Add("SPLINELIB_STATIC");
            //    PublicDefinitions.Add("NOMINMAX");
            //}

        }
    }
}
