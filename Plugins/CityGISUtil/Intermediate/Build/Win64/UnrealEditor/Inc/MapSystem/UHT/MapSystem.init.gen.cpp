// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMapSystem_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_MapSystem;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_MapSystem()
	{
		if (!Z_Registration_Info_UPackage__Script_MapSystem.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/MapSystem",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0xFFED004F,
				0x77762BDB,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_MapSystem.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_MapSystem.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_MapSystem(Z_Construct_UPackage__Script_MapSystem, TEXT("/Script/MapSystem"), Z_Registration_Info_UPackage__Script_MapSystem, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xFFED004F, 0x77762BDB));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
