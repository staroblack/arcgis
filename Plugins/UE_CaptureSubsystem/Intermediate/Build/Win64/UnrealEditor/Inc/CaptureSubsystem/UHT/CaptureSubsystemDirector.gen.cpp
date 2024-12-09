// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CaptureSubsystem/Public/CaptureSubsystemDirector.h"
#include "CaptureSubsystem/Public/VideoCaptureSubsystem.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCaptureSubsystemDirector() {}
// Cross Module References
	CAPTURESUBSYSTEM_API UClass* Z_Construct_UClass_UCaptureSubsystemDirector();
	CAPTURESUBSYSTEM_API UClass* Z_Construct_UClass_UCaptureSubsystemDirector_NoRegister();
	CAPTURESUBSYSTEM_API UClass* Z_Construct_UClass_UVideoCaptureSubsystem_NoRegister();
	CAPTURESUBSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FVideoCaptureOptions();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	ENGINE_API UClass* Z_Construct_UClass_UWorld_NoRegister();
	UPackage* Z_Construct_UPackage__Script_CaptureSubsystem();
// End Cross Module References
	DEFINE_FUNCTION(UCaptureSubsystemDirector::execInitialize_Director)
	{
		P_GET_OBJECT(UWorld,Z_Param_World);
		P_GET_STRUCT(FVideoCaptureOptions,Z_Param_CaptureOptions);
		P_GET_OBJECT(UVideoCaptureSubsystem,Z_Param_InSubsystem);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Initialize_Director(Z_Param_World,Z_Param_CaptureOptions,Z_Param_InSubsystem);
		P_NATIVE_END;
	}
	void UCaptureSubsystemDirector::StaticRegisterNativesUCaptureSubsystemDirector()
	{
		UClass* Class = UCaptureSubsystemDirector::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Initialize_Director", &UCaptureSubsystemDirector::execInitialize_Director },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UCaptureSubsystemDirector_Initialize_Director_Statics
	{
		struct CaptureSubsystemDirector_eventInitialize_Director_Parms
		{
			UWorld* World;
			FVideoCaptureOptions CaptureOptions;
			UVideoCaptureSubsystem* InSubsystem;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_World;
		static const UECodeGen_Private::FStructPropertyParams NewProp_CaptureOptions;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InSubsystem;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCaptureSubsystemDirector_Initialize_Director_Statics::NewProp_World = { "World", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CaptureSubsystemDirector_eventInitialize_Director_Parms, World), Z_Construct_UClass_UWorld_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCaptureSubsystemDirector_Initialize_Director_Statics::NewProp_CaptureOptions = { "CaptureOptions", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CaptureSubsystemDirector_eventInitialize_Director_Parms, CaptureOptions), Z_Construct_UScriptStruct_FVideoCaptureOptions, METADATA_PARAMS(0, nullptr) }; // 936405184
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCaptureSubsystemDirector_Initialize_Director_Statics::NewProp_InSubsystem = { "InSubsystem", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CaptureSubsystemDirector_eventInitialize_Director_Parms, InSubsystem), Z_Construct_UClass_UVideoCaptureSubsystem_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCaptureSubsystemDirector_Initialize_Director_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCaptureSubsystemDirector_Initialize_Director_Statics::NewProp_World,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCaptureSubsystemDirector_Initialize_Director_Statics::NewProp_CaptureOptions,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCaptureSubsystemDirector_Initialize_Director_Statics::NewProp_InSubsystem,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCaptureSubsystemDirector_Initialize_Director_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/CaptureSubsystemDirector.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCaptureSubsystemDirector_Initialize_Director_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCaptureSubsystemDirector, nullptr, "Initialize_Director", nullptr, nullptr, Z_Construct_UFunction_UCaptureSubsystemDirector_Initialize_Director_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCaptureSubsystemDirector_Initialize_Director_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCaptureSubsystemDirector_Initialize_Director_Statics::CaptureSubsystemDirector_eventInitialize_Director_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCaptureSubsystemDirector_Initialize_Director_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCaptureSubsystemDirector_Initialize_Director_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCaptureSubsystemDirector_Initialize_Director_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UCaptureSubsystemDirector_Initialize_Director_Statics::CaptureSubsystemDirector_eventInitialize_Director_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UCaptureSubsystemDirector_Initialize_Director()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCaptureSubsystemDirector_Initialize_Director_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCaptureSubsystemDirector);
	UClass* Z_Construct_UClass_UCaptureSubsystemDirector_NoRegister()
	{
		return UCaptureSubsystemDirector::StaticClass();
	}
	struct Z_Construct_UClass_UCaptureSubsystemDirector_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCaptureSubsystemDirector_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_CaptureSubsystem,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCaptureSubsystemDirector_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UCaptureSubsystemDirector_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UCaptureSubsystemDirector_Initialize_Director, "Initialize_Director" }, // 3501038488
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCaptureSubsystemDirector_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCaptureSubsystemDirector_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "CaptureSubsystemDirector.h" },
		{ "ModuleRelativePath", "Public/CaptureSubsystemDirector.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCaptureSubsystemDirector_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCaptureSubsystemDirector>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UCaptureSubsystemDirector_Statics::ClassParams = {
		&UCaptureSubsystemDirector::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCaptureSubsystemDirector_Statics::Class_MetaDataParams), Z_Construct_UClass_UCaptureSubsystemDirector_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UCaptureSubsystemDirector()
	{
		if (!Z_Registration_Info_UClass_UCaptureSubsystemDirector.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCaptureSubsystemDirector.OuterSingleton, Z_Construct_UClass_UCaptureSubsystemDirector_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UCaptureSubsystemDirector.OuterSingleton;
	}
	template<> CAPTURESUBSYSTEM_API UClass* StaticClass<UCaptureSubsystemDirector>()
	{
		return UCaptureSubsystemDirector::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCaptureSubsystemDirector);
	struct Z_CompiledInDeferFile_FID_arcgis_Plugins_UE_CaptureSubsystem_Source_CaptureSubsystem_Public_CaptureSubsystemDirector_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_arcgis_Plugins_UE_CaptureSubsystem_Source_CaptureSubsystem_Public_CaptureSubsystemDirector_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UCaptureSubsystemDirector, UCaptureSubsystemDirector::StaticClass, TEXT("UCaptureSubsystemDirector"), &Z_Registration_Info_UClass_UCaptureSubsystemDirector, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCaptureSubsystemDirector), 1801230318U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_arcgis_Plugins_UE_CaptureSubsystem_Source_CaptureSubsystem_Public_CaptureSubsystemDirector_h_1585743279(TEXT("/Script/CaptureSubsystem"),
		Z_CompiledInDeferFile_FID_arcgis_Plugins_UE_CaptureSubsystem_Source_CaptureSubsystem_Public_CaptureSubsystemDirector_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_arcgis_Plugins_UE_CaptureSubsystem_Source_CaptureSubsystem_Public_CaptureSubsystemDirector_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
