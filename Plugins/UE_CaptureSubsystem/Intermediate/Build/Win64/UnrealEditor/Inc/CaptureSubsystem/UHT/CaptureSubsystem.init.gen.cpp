// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCaptureSubsystem_init() {}
	CAPTURESUBSYSTEM_API UFunction* Z_Construct_UDelegateFunction_CaptureSubsystem_OnError__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_CaptureSubsystem;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_CaptureSubsystem()
	{
		if (!Z_Registration_Info_UPackage__Script_CaptureSubsystem.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_CaptureSubsystem_OnError__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/CaptureSubsystem",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x5247286F,
				0x27731878,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_CaptureSubsystem.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_CaptureSubsystem.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_CaptureSubsystem(Z_Construct_UPackage__Script_CaptureSubsystem, TEXT("/Script/CaptureSubsystem"), Z_Registration_Info_UPackage__Script_CaptureSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x5247286F, 0x27731878));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
