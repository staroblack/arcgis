// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEasyXMLParser_init() {}
	EASYXMLPARSER_API UFunction* Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromFile_Result__DelegateSignature();
	EASYXMLPARSER_API UFunction* Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromString_Result__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_EasyXMLParser;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_EasyXMLParser()
	{
		if (!Z_Registration_Info_UPackage__Script_EasyXMLParser.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromFile_Result__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromString_Result__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/EasyXMLParser",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x3352B34D,
				0x5229CB6F,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_EasyXMLParser.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_EasyXMLParser.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_EasyXMLParser(Z_Construct_UPackage__Script_EasyXMLParser, TEXT("/Script/EasyXMLParser"), Z_Registration_Info_UPackage__Script_EasyXMLParser, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x3352B34D, 0x5229CB6F));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
