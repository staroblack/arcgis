// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EasyXMLParser/Public/EasyXMLAttribute.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEasyXMLAttribute() {}
// Cross Module References
	EASYXMLPARSER_API UClass* Z_Construct_UClass_UEasyXMLAttribute();
	EASYXMLPARSER_API UClass* Z_Construct_UClass_UEasyXMLAttribute_NoRegister();
	EASYXMLPARSER_API UClass* Z_Construct_UClass_UEasyXMLObject();
	UPackage* Z_Construct_UPackage__Script_EasyXMLParser();
// End Cross Module References
	void UEasyXMLAttribute::StaticRegisterNativesUEasyXMLAttribute()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UEasyXMLAttribute);
	UClass* Z_Construct_UClass_UEasyXMLAttribute_NoRegister()
	{
		return UEasyXMLAttribute::StaticClass();
	}
	struct Z_Construct_UClass_UEasyXMLAttribute_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UEasyXMLAttribute_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UEasyXMLObject,
		(UObject* (*)())Z_Construct_UPackage__Script_EasyXMLParser,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLAttribute_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEasyXMLAttribute_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "EasyXMLAttribute.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/EasyXMLAttribute.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UEasyXMLAttribute_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEasyXMLAttribute>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UEasyXMLAttribute_Statics::ClassParams = {
		&UEasyXMLAttribute::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLAttribute_Statics::Class_MetaDataParams), Z_Construct_UClass_UEasyXMLAttribute_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UEasyXMLAttribute()
	{
		if (!Z_Registration_Info_UClass_UEasyXMLAttribute.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEasyXMLAttribute.OuterSingleton, Z_Construct_UClass_UEasyXMLAttribute_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UEasyXMLAttribute.OuterSingleton;
	}
	template<> EASYXMLPARSER_API UClass* StaticClass<UEasyXMLAttribute>()
	{
		return UEasyXMLAttribute::StaticClass();
	}
	UEasyXMLAttribute::UEasyXMLAttribute(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UEasyXMLAttribute);
	UEasyXMLAttribute::~UEasyXMLAttribute() {}
	struct Z_CompiledInDeferFile_FID_graphics_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLAttribute_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_graphics_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLAttribute_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UEasyXMLAttribute, UEasyXMLAttribute::StaticClass, TEXT("UEasyXMLAttribute"), &Z_Registration_Info_UClass_UEasyXMLAttribute, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEasyXMLAttribute), 3533025651U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_graphics_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLAttribute_h_3318413034(TEXT("/Script/EasyXMLParser"),
		Z_CompiledInDeferFile_FID_graphics_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLAttribute_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_graphics_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLAttribute_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
