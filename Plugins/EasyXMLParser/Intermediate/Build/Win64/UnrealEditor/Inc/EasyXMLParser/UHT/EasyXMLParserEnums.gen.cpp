// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EasyXMLParser/Public/EasyXMLParserEnums.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEasyXMLParserEnums() {}
// Cross Module References
	EASYXMLPARSER_API UEnum* Z_Construct_UEnum_EasyXMLParser_EEasyXMLParserErrorCode();
	EASYXMLPARSER_API UEnum* Z_Construct_UEnum_EasyXMLParser_EEasyXMLParserFound();
	UPackage* Z_Construct_UPackage__Script_EasyXMLParser();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EEasyXMLParserErrorCode;
	static UEnum* EEasyXMLParserErrorCode_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EEasyXMLParserErrorCode.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EEasyXMLParserErrorCode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_EasyXMLParser_EEasyXMLParserErrorCode, (UObject*)Z_Construct_UPackage__Script_EasyXMLParser(), TEXT("EEasyXMLParserErrorCode"));
		}
		return Z_Registration_Info_UEnum_EEasyXMLParserErrorCode.OuterSingleton;
	}
	template<> EASYXMLPARSER_API UEnum* StaticEnum<EEasyXMLParserErrorCode>()
	{
		return EEasyXMLParserErrorCode_StaticEnum();
	}
	struct Z_Construct_UEnum_EasyXMLParser_EEasyXMLParserErrorCode_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_EasyXMLParser_EEasyXMLParserErrorCode_Statics::Enumerators[] = {
		{ "EEasyXMLParserErrorCode::Successed", (int64)EEasyXMLParserErrorCode::Successed },
		{ "EEasyXMLParserErrorCode::Failed", (int64)EEasyXMLParserErrorCode::Failed },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_EasyXMLParser_EEasyXMLParserErrorCode_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Failed.Name", "EEasyXMLParserErrorCode::Failed" },
		{ "ModuleRelativePath", "Public/EasyXMLParserEnums.h" },
		{ "Successed.Name", "EEasyXMLParserErrorCode::Successed" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_EasyXMLParser_EEasyXMLParserErrorCode_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_EasyXMLParser,
		nullptr,
		"EEasyXMLParserErrorCode",
		"EEasyXMLParserErrorCode",
		Z_Construct_UEnum_EasyXMLParser_EEasyXMLParserErrorCode_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_EasyXMLParser_EEasyXMLParserErrorCode_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_EasyXMLParser_EEasyXMLParserErrorCode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_EasyXMLParser_EEasyXMLParserErrorCode_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_EasyXMLParser_EEasyXMLParserErrorCode()
	{
		if (!Z_Registration_Info_UEnum_EEasyXMLParserErrorCode.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EEasyXMLParserErrorCode.InnerSingleton, Z_Construct_UEnum_EasyXMLParser_EEasyXMLParserErrorCode_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EEasyXMLParserErrorCode.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EEasyXMLParserFound;
	static UEnum* EEasyXMLParserFound_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EEasyXMLParserFound.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EEasyXMLParserFound.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_EasyXMLParser_EEasyXMLParserFound, (UObject*)Z_Construct_UPackage__Script_EasyXMLParser(), TEXT("EEasyXMLParserFound"));
		}
		return Z_Registration_Info_UEnum_EEasyXMLParserFound.OuterSingleton;
	}
	template<> EASYXMLPARSER_API UEnum* StaticEnum<EEasyXMLParserFound>()
	{
		return EEasyXMLParserFound_StaticEnum();
	}
	struct Z_Construct_UEnum_EasyXMLParser_EEasyXMLParserFound_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_EasyXMLParser_EEasyXMLParserFound_Statics::Enumerators[] = {
		{ "EEasyXMLParserFound::Found", (int64)EEasyXMLParserFound::Found },
		{ "EEasyXMLParserFound::NotFound", (int64)EEasyXMLParserFound::NotFound },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_EasyXMLParser_EEasyXMLParserFound_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Found.Name", "EEasyXMLParserFound::Found" },
		{ "ModuleRelativePath", "Public/EasyXMLParserEnums.h" },
		{ "NotFound.Name", "EEasyXMLParserFound::NotFound" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_EasyXMLParser_EEasyXMLParserFound_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_EasyXMLParser,
		nullptr,
		"EEasyXMLParserFound",
		"EEasyXMLParserFound",
		Z_Construct_UEnum_EasyXMLParser_EEasyXMLParserFound_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_EasyXMLParser_EEasyXMLParserFound_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_EasyXMLParser_EEasyXMLParserFound_Statics::Enum_MetaDataParams), Z_Construct_UEnum_EasyXMLParser_EEasyXMLParserFound_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_EasyXMLParser_EEasyXMLParserFound()
	{
		if (!Z_Registration_Info_UEnum_EEasyXMLParserFound.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EEasyXMLParserFound.InnerSingleton, Z_Construct_UEnum_EasyXMLParser_EEasyXMLParserFound_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EEasyXMLParserFound.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_graphic_arcgisTest_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLParserEnums_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_graphic_arcgisTest_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLParserEnums_h_Statics::EnumInfo[] = {
		{ EEasyXMLParserErrorCode_StaticEnum, TEXT("EEasyXMLParserErrorCode"), &Z_Registration_Info_UEnum_EEasyXMLParserErrorCode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2087042666U) },
		{ EEasyXMLParserFound_StaticEnum, TEXT("EEasyXMLParserFound"), &Z_Registration_Info_UEnum_EEasyXMLParserFound, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2185933784U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_graphic_arcgisTest_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLParserEnums_h_465836107(TEXT("/Script/EasyXMLParser"),
		nullptr, 0,
		nullptr, 0,
		Z_CompiledInDeferFile_FID_graphic_arcgisTest_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLParserEnums_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_graphic_arcgisTest_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLParserEnums_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
