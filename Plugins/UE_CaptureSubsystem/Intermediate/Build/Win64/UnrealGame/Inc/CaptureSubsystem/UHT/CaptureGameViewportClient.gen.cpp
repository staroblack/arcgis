// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CaptureSubsystem/Public/CaptureGameViewportClient.h"
#include "../../Source/Runtime/Engine/Classes/Engine/Engine.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCaptureGameViewportClient() {}
// Cross Module References
	CAPTURESUBSYSTEM_API UClass* Z_Construct_UClass_UCaptureGameViewportClient();
	CAPTURESUBSYSTEM_API UClass* Z_Construct_UClass_UCaptureGameViewportClient_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UGameViewportClient();
	ENGINE_API UClass* Z_Construct_UClass_UTextureRenderTarget2D_NoRegister();
	UPackage* Z_Construct_UPackage__Script_CaptureSubsystem();
// End Cross Module References
	void UCaptureGameViewportClient::StaticRegisterNativesUCaptureGameViewportClient()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCaptureGameViewportClient);
	UClass* Z_Construct_UClass_UCaptureGameViewportClient_NoRegister()
	{
		return UCaptureGameViewportClient::StaticClass();
	}
	struct Z_Construct_UClass_UCaptureGameViewportClient_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MyRenderTarget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MyRenderTarget;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCaptureGameViewportClient_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameViewportClient,
		(UObject* (*)())Z_Construct_UPackage__Script_CaptureSubsystem,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCaptureGameViewportClient_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCaptureGameViewportClient_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "CaptureGameViewportClient.h" },
		{ "ModuleRelativePath", "Public/CaptureGameViewportClient.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCaptureGameViewportClient_Statics::NewProp_MyRenderTarget_MetaData[] = {
		{ "ModuleRelativePath", "Public/CaptureGameViewportClient.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCaptureGameViewportClient_Statics::NewProp_MyRenderTarget = { "MyRenderTarget", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCaptureGameViewportClient, MyRenderTarget), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCaptureGameViewportClient_Statics::NewProp_MyRenderTarget_MetaData), Z_Construct_UClass_UCaptureGameViewportClient_Statics::NewProp_MyRenderTarget_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCaptureGameViewportClient_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCaptureGameViewportClient_Statics::NewProp_MyRenderTarget,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCaptureGameViewportClient_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCaptureGameViewportClient>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UCaptureGameViewportClient_Statics::ClassParams = {
		&UCaptureGameViewportClient::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UCaptureGameViewportClient_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UCaptureGameViewportClient_Statics::PropPointers),
		0,
		0x001000ACu,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCaptureGameViewportClient_Statics::Class_MetaDataParams), Z_Construct_UClass_UCaptureGameViewportClient_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCaptureGameViewportClient_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UCaptureGameViewportClient()
	{
		if (!Z_Registration_Info_UClass_UCaptureGameViewportClient.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCaptureGameViewportClient.OuterSingleton, Z_Construct_UClass_UCaptureGameViewportClient_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UCaptureGameViewportClient.OuterSingleton;
	}
	template<> CAPTURESUBSYSTEM_API UClass* StaticClass<UCaptureGameViewportClient>()
	{
		return UCaptureGameViewportClient::StaticClass();
	}
	UCaptureGameViewportClient::UCaptureGameViewportClient(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCaptureGameViewportClient);
	UCaptureGameViewportClient::~UCaptureGameViewportClient() {}
	struct Z_CompiledInDeferFile_FID_arcgis_Plugins_UE_CaptureSubsystem_Source_CaptureSubsystem_Public_CaptureGameViewportClient_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_arcgis_Plugins_UE_CaptureSubsystem_Source_CaptureSubsystem_Public_CaptureGameViewportClient_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UCaptureGameViewportClient, UCaptureGameViewportClient::StaticClass, TEXT("UCaptureGameViewportClient"), &Z_Registration_Info_UClass_UCaptureGameViewportClient, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCaptureGameViewportClient), 2641608326U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_arcgis_Plugins_UE_CaptureSubsystem_Source_CaptureSubsystem_Public_CaptureGameViewportClient_h_2874516391(TEXT("/Script/CaptureSubsystem"),
		Z_CompiledInDeferFile_FID_arcgis_Plugins_UE_CaptureSubsystem_Source_CaptureSubsystem_Public_CaptureGameViewportClient_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_arcgis_Plugins_UE_CaptureSubsystem_Source_CaptureSubsystem_Public_CaptureGameViewportClient_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
