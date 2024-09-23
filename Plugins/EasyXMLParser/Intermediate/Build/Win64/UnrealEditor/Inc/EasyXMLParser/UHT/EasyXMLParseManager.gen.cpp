// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EasyXMLParser/Public/EasyXMLParseManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEasyXMLParseManager() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	EASYXMLPARSER_API UClass* Z_Construct_UClass_UEasyXMLElement_NoRegister();
	EASYXMLPARSER_API UClass* Z_Construct_UClass_UEasyXMLParseManager();
	EASYXMLPARSER_API UClass* Z_Construct_UClass_UEasyXMLParseManager_NoRegister();
	EASYXMLPARSER_API UEnum* Z_Construct_UEnum_EasyXMLParser_EEasyXMLParserErrorCode();
	UPackage* Z_Construct_UPackage__Script_EasyXMLParser();
// End Cross Module References
	DEFINE_FUNCTION(UEasyXMLParseManager::execLoadFromString)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_XMLString);
		P_GET_ENUM_REF(EEasyXMLParserErrorCode,Z_Param_Out_Result);
		P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_ErrorMessage);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UEasyXMLElement**)Z_Param__Result=UEasyXMLParseManager::LoadFromString(Z_Param_XMLString,(EEasyXMLParserErrorCode&)(Z_Param_Out_Result),Z_Param_Out_ErrorMessage);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UEasyXMLParseManager::execLoadFromFile)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_FilePath);
		P_GET_UBOOL(Z_Param_IsAblolute);
		P_GET_ENUM_REF(EEasyXMLParserErrorCode,Z_Param_Out_Result);
		P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_ErrorMessage);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UEasyXMLElement**)Z_Param__Result=UEasyXMLParseManager::LoadFromFile(Z_Param_FilePath,Z_Param_IsAblolute,(EEasyXMLParserErrorCode&)(Z_Param_Out_Result),Z_Param_Out_ErrorMessage);
		P_NATIVE_END;
	}
	void UEasyXMLParseManager::StaticRegisterNativesUEasyXMLParseManager()
	{
		UClass* Class = UEasyXMLParseManager::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "LoadFromFile", &UEasyXMLParseManager::execLoadFromFile },
			{ "LoadFromString", &UEasyXMLParseManager::execLoadFromString },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UEasyXMLParseManager_LoadFromFile_Statics
	{
		struct EasyXMLParseManager_eventLoadFromFile_Parms
		{
			FString FilePath;
			bool IsAblolute;
			EEasyXMLParserErrorCode Result;
			FString ErrorMessage;
			UEasyXMLElement* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FilePath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_FilePath;
		static void NewProp_IsAblolute_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsAblolute;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Result_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Result;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEasyXMLParseManager_LoadFromFile_Statics::NewProp_FilePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEasyXMLParseManager_LoadFromFile_Statics::NewProp_FilePath = { "FilePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLParseManager_eventLoadFromFile_Parms, FilePath), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLParseManager_LoadFromFile_Statics::NewProp_FilePath_MetaData), Z_Construct_UFunction_UEasyXMLParseManager_LoadFromFile_Statics::NewProp_FilePath_MetaData) };
	void Z_Construct_UFunction_UEasyXMLParseManager_LoadFromFile_Statics::NewProp_IsAblolute_SetBit(void* Obj)
	{
		((EasyXMLParseManager_eventLoadFromFile_Parms*)Obj)->IsAblolute = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEasyXMLParseManager_LoadFromFile_Statics::NewProp_IsAblolute = { "IsAblolute", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EasyXMLParseManager_eventLoadFromFile_Parms), &Z_Construct_UFunction_UEasyXMLParseManager_LoadFromFile_Statics::NewProp_IsAblolute_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UEasyXMLParseManager_LoadFromFile_Statics::NewProp_Result_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UEasyXMLParseManager_LoadFromFile_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLParseManager_eventLoadFromFile_Parms, Result), Z_Construct_UEnum_EasyXMLParser_EEasyXMLParserErrorCode, METADATA_PARAMS(0, nullptr) }; // 2087042666
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEasyXMLParseManager_LoadFromFile_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLParseManager_eventLoadFromFile_Parms, ErrorMessage), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEasyXMLParseManager_LoadFromFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLParseManager_eventLoadFromFile_Parms, ReturnValue), Z_Construct_UClass_UEasyXMLElement_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEasyXMLParseManager_LoadFromFile_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLParseManager_LoadFromFile_Statics::NewProp_FilePath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLParseManager_LoadFromFile_Statics::NewProp_IsAblolute,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLParseManager_LoadFromFile_Statics::NewProp_Result_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLParseManager_LoadFromFile_Statics::NewProp_Result,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLParseManager_LoadFromFile_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLParseManager_LoadFromFile_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEasyXMLParseManager_LoadFromFile_Statics::Function_MetaDataParams[] = {
		{ "Category", "EasyXMLParser" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * load xml file\n\x09 * @param FilePath - xml file path\n\x09 * @param IsAblolute - true:FilePath is absolute path, false:Relative path from \"Content\"\n\x09 * @return xml object\n\x09 */" },
#endif
		{ "ExpandEnumAsExecs", "Result" },
		{ "ModuleRelativePath", "Public/EasyXMLParseManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "load xml file\n@param FilePath - xml file path\n@param IsAblolute - true:FilePath is absolute path, false:Relative path from \"Content\"\n@return xml object" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEasyXMLParseManager_LoadFromFile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UEasyXMLParseManager, nullptr, "LoadFromFile", nullptr, nullptr, Z_Construct_UFunction_UEasyXMLParseManager_LoadFromFile_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLParseManager_LoadFromFile_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEasyXMLParseManager_LoadFromFile_Statics::EasyXMLParseManager_eventLoadFromFile_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLParseManager_LoadFromFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEasyXMLParseManager_LoadFromFile_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLParseManager_LoadFromFile_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UEasyXMLParseManager_LoadFromFile_Statics::EasyXMLParseManager_eventLoadFromFile_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UEasyXMLParseManager_LoadFromFile()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEasyXMLParseManager_LoadFromFile_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UEasyXMLParseManager_LoadFromString_Statics
	{
		struct EasyXMLParseManager_eventLoadFromString_Parms
		{
			FString XMLString;
			EEasyXMLParserErrorCode Result;
			FString ErrorMessage;
			UEasyXMLElement* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_XMLString_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_XMLString;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Result_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Result;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEasyXMLParseManager_LoadFromString_Statics::NewProp_XMLString_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEasyXMLParseManager_LoadFromString_Statics::NewProp_XMLString = { "XMLString", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLParseManager_eventLoadFromString_Parms, XMLString), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLParseManager_LoadFromString_Statics::NewProp_XMLString_MetaData), Z_Construct_UFunction_UEasyXMLParseManager_LoadFromString_Statics::NewProp_XMLString_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UEasyXMLParseManager_LoadFromString_Statics::NewProp_Result_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UEasyXMLParseManager_LoadFromString_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLParseManager_eventLoadFromString_Parms, Result), Z_Construct_UEnum_EasyXMLParser_EEasyXMLParserErrorCode, METADATA_PARAMS(0, nullptr) }; // 2087042666
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEasyXMLParseManager_LoadFromString_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLParseManager_eventLoadFromString_Parms, ErrorMessage), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEasyXMLParseManager_LoadFromString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLParseManager_eventLoadFromString_Parms, ReturnValue), Z_Construct_UClass_UEasyXMLElement_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEasyXMLParseManager_LoadFromString_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLParseManager_LoadFromString_Statics::NewProp_XMLString,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLParseManager_LoadFromString_Statics::NewProp_Result_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLParseManager_LoadFromString_Statics::NewProp_Result,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLParseManager_LoadFromString_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLParseManager_LoadFromString_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEasyXMLParseManager_LoadFromString_Statics::Function_MetaDataParams[] = {
		{ "Category", "EasyXMLParser" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * load xml string\n\x09 * @param XMLString - xml file path\n\x09 * @return xml object\n\x09 */" },
#endif
		{ "ExpandEnumAsExecs", "Result" },
		{ "ModuleRelativePath", "Public/EasyXMLParseManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "load xml string\n@param XMLString - xml file path\n@return xml object" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEasyXMLParseManager_LoadFromString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UEasyXMLParseManager, nullptr, "LoadFromString", nullptr, nullptr, Z_Construct_UFunction_UEasyXMLParseManager_LoadFromString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLParseManager_LoadFromString_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEasyXMLParseManager_LoadFromString_Statics::EasyXMLParseManager_eventLoadFromString_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLParseManager_LoadFromString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEasyXMLParseManager_LoadFromString_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLParseManager_LoadFromString_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UEasyXMLParseManager_LoadFromString_Statics::EasyXMLParseManager_eventLoadFromString_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UEasyXMLParseManager_LoadFromString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEasyXMLParseManager_LoadFromString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UEasyXMLParseManager);
	UClass* Z_Construct_UClass_UEasyXMLParseManager_NoRegister()
	{
		return UEasyXMLParseManager::StaticClass();
	}
	struct Z_Construct_UClass_UEasyXMLParseManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UEasyXMLParseManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_EasyXMLParser,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLParseManager_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UEasyXMLParseManager_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UEasyXMLParseManager_LoadFromFile, "LoadFromFile" }, // 2452959666
		{ &Z_Construct_UFunction_UEasyXMLParseManager_LoadFromString, "LoadFromString" }, // 4251683691
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLParseManager_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEasyXMLParseManager_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "EasyXMLParseManager.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/EasyXMLParseManager.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UEasyXMLParseManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEasyXMLParseManager>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UEasyXMLParseManager_Statics::ClassParams = {
		&UEasyXMLParseManager::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLParseManager_Statics::Class_MetaDataParams), Z_Construct_UClass_UEasyXMLParseManager_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UEasyXMLParseManager()
	{
		if (!Z_Registration_Info_UClass_UEasyXMLParseManager.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEasyXMLParseManager.OuterSingleton, Z_Construct_UClass_UEasyXMLParseManager_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UEasyXMLParseManager.OuterSingleton;
	}
	template<> EASYXMLPARSER_API UClass* StaticClass<UEasyXMLParseManager>()
	{
		return UEasyXMLParseManager::StaticClass();
	}
	UEasyXMLParseManager::UEasyXMLParseManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UEasyXMLParseManager);
	UEasyXMLParseManager::~UEasyXMLParseManager() {}
	struct Z_CompiledInDeferFile_FID_graphics_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLParseManager_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_graphics_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLParseManager_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UEasyXMLParseManager, UEasyXMLParseManager::StaticClass, TEXT("UEasyXMLParseManager"), &Z_Registration_Info_UClass_UEasyXMLParseManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEasyXMLParseManager), 2817724305U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_graphics_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLParseManager_h_960440594(TEXT("/Script/EasyXMLParser"),
		Z_CompiledInDeferFile_FID_graphics_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLParseManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_graphics_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLParseManager_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
