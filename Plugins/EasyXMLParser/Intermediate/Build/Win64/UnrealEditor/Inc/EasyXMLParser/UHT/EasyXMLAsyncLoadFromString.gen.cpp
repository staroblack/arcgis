// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EasyXMLParser/Public/EasyXMLAsyncLoadFromString.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEasyXMLAsyncLoadFromString() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	EASYXMLPARSER_API UClass* Z_Construct_UClass_UEasyXMLAsyncLoadFromString();
	EASYXMLPARSER_API UClass* Z_Construct_UClass_UEasyXMLAsyncLoadFromString_NoRegister();
	EASYXMLPARSER_API UClass* Z_Construct_UClass_UEasyXMLElement_NoRegister();
	EASYXMLPARSER_API UFunction* Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromString_Result__DelegateSignature();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintAsyncActionBase();
	UPackage* Z_Construct_UPackage__Script_EasyXMLParser();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromString_Result__DelegateSignature_Statics
	{
		struct _Script_EasyXMLParser_eventEasyXMLAsyncLoadFromString_Result_Parms
		{
			UEasyXMLElement* XMLObject;
			FString ErrorMessage;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_XMLObject;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromString_Result__DelegateSignature_Statics::NewProp_XMLObject = { "XMLObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_EasyXMLParser_eventEasyXMLAsyncLoadFromString_Result_Parms, XMLObject), Z_Construct_UClass_UEasyXMLElement_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromString_Result__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_EasyXMLParser_eventEasyXMLAsyncLoadFromString_Result_Parms, ErrorMessage), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromString_Result__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromString_Result__DelegateSignature_Statics::NewProp_XMLObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromString_Result__DelegateSignature_Statics::NewProp_ErrorMessage,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromString_Result__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/EasyXMLAsyncLoadFromString.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromString_Result__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_EasyXMLParser, nullptr, "EasyXMLAsyncLoadFromString_Result__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromString_Result__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromString_Result__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromString_Result__DelegateSignature_Statics::_Script_EasyXMLParser_eventEasyXMLAsyncLoadFromString_Result_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromString_Result__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromString_Result__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromString_Result__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromString_Result__DelegateSignature_Statics::_Script_EasyXMLParser_eventEasyXMLAsyncLoadFromString_Result_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromString_Result__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromString_Result__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FEasyXMLAsyncLoadFromString_Result_DelegateWrapper(const FMulticastScriptDelegate& EasyXMLAsyncLoadFromString_Result, UEasyXMLElement* XMLObject, const FString& ErrorMessage)
{
	struct _Script_EasyXMLParser_eventEasyXMLAsyncLoadFromString_Result_Parms
	{
		UEasyXMLElement* XMLObject;
		FString ErrorMessage;
	};
	_Script_EasyXMLParser_eventEasyXMLAsyncLoadFromString_Result_Parms Parms;
	Parms.XMLObject=XMLObject;
	Parms.ErrorMessage=ErrorMessage;
	EasyXMLAsyncLoadFromString_Result.ProcessMulticastDelegate<UObject>(&Parms);
}
	DEFINE_FUNCTION(UEasyXMLAsyncLoadFromString::execAsyncLoadFromString)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_XMLString);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UEasyXMLAsyncLoadFromString**)Z_Param__Result=UEasyXMLAsyncLoadFromString::AsyncLoadFromString(Z_Param_WorldContextObject,Z_Param_XMLString);
		P_NATIVE_END;
	}
	void UEasyXMLAsyncLoadFromString::StaticRegisterNativesUEasyXMLAsyncLoadFromString()
	{
		UClass* Class = UEasyXMLAsyncLoadFromString::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AsyncLoadFromString", &UEasyXMLAsyncLoadFromString::execAsyncLoadFromString },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UEasyXMLAsyncLoadFromString_AsyncLoadFromString_Statics
	{
		struct EasyXMLAsyncLoadFromString_eventAsyncLoadFromString_Parms
		{
			UObject* WorldContextObject;
			FString XMLString;
			UEasyXMLAsyncLoadFromString* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_XMLString_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_XMLString;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEasyXMLAsyncLoadFromString_AsyncLoadFromString_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLAsyncLoadFromString_eventAsyncLoadFromString_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEasyXMLAsyncLoadFromString_AsyncLoadFromString_Statics::NewProp_XMLString_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEasyXMLAsyncLoadFromString_AsyncLoadFromString_Statics::NewProp_XMLString = { "XMLString", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLAsyncLoadFromString_eventAsyncLoadFromString_Parms, XMLString), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLAsyncLoadFromString_AsyncLoadFromString_Statics::NewProp_XMLString_MetaData), Z_Construct_UFunction_UEasyXMLAsyncLoadFromString_AsyncLoadFromString_Statics::NewProp_XMLString_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEasyXMLAsyncLoadFromString_AsyncLoadFromString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLAsyncLoadFromString_eventAsyncLoadFromString_Parms, ReturnValue), Z_Construct_UClass_UEasyXMLAsyncLoadFromString_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEasyXMLAsyncLoadFromString_AsyncLoadFromString_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLAsyncLoadFromString_AsyncLoadFromString_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLAsyncLoadFromString_AsyncLoadFromString_Statics::NewProp_XMLString,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLAsyncLoadFromString_AsyncLoadFromString_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEasyXMLAsyncLoadFromString_AsyncLoadFromString_Statics::Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "Category", "EasyXMLParser" },
		{ "ModuleRelativePath", "Public/EasyXMLAsyncLoadFromString.h" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEasyXMLAsyncLoadFromString_AsyncLoadFromString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UEasyXMLAsyncLoadFromString, nullptr, "AsyncLoadFromString", nullptr, nullptr, Z_Construct_UFunction_UEasyXMLAsyncLoadFromString_AsyncLoadFromString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLAsyncLoadFromString_AsyncLoadFromString_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEasyXMLAsyncLoadFromString_AsyncLoadFromString_Statics::EasyXMLAsyncLoadFromString_eventAsyncLoadFromString_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLAsyncLoadFromString_AsyncLoadFromString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEasyXMLAsyncLoadFromString_AsyncLoadFromString_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLAsyncLoadFromString_AsyncLoadFromString_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UEasyXMLAsyncLoadFromString_AsyncLoadFromString_Statics::EasyXMLAsyncLoadFromString_eventAsyncLoadFromString_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UEasyXMLAsyncLoadFromString_AsyncLoadFromString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEasyXMLAsyncLoadFromString_AsyncLoadFromString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UEasyXMLAsyncLoadFromString);
	UClass* Z_Construct_UClass_UEasyXMLAsyncLoadFromString_NoRegister()
	{
		return UEasyXMLAsyncLoadFromString::StaticClass();
	}
	struct Z_Construct_UClass_UEasyXMLAsyncLoadFromString_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Successed_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_Successed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Failed_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_Failed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp__XMLString_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp__XMLString;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UEasyXMLAsyncLoadFromString_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintAsyncActionBase,
		(UObject* (*)())Z_Construct_UPackage__Script_EasyXMLParser,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLAsyncLoadFromString_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UEasyXMLAsyncLoadFromString_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UEasyXMLAsyncLoadFromString_AsyncLoadFromString, "AsyncLoadFromString" }, // 377124245
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLAsyncLoadFromString_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEasyXMLAsyncLoadFromString_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "EasyXMLAsyncLoadFromString.h" },
		{ "ModuleRelativePath", "Public/EasyXMLAsyncLoadFromString.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEasyXMLAsyncLoadFromString_Statics::NewProp_Successed_MetaData[] = {
		{ "ModuleRelativePath", "Public/EasyXMLAsyncLoadFromString.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEasyXMLAsyncLoadFromString_Statics::NewProp_Successed = { "Successed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEasyXMLAsyncLoadFromString, Successed), Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromString_Result__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLAsyncLoadFromString_Statics::NewProp_Successed_MetaData), Z_Construct_UClass_UEasyXMLAsyncLoadFromString_Statics::NewProp_Successed_MetaData) }; // 2581933539
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEasyXMLAsyncLoadFromString_Statics::NewProp_Failed_MetaData[] = {
		{ "ModuleRelativePath", "Public/EasyXMLAsyncLoadFromString.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEasyXMLAsyncLoadFromString_Statics::NewProp_Failed = { "Failed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEasyXMLAsyncLoadFromString, Failed), Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromString_Result__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLAsyncLoadFromString_Statics::NewProp_Failed_MetaData), Z_Construct_UClass_UEasyXMLAsyncLoadFromString_Statics::NewProp_Failed_MetaData) }; // 2581933539
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEasyXMLAsyncLoadFromString_Statics::NewProp__XMLString_MetaData[] = {
		{ "ModuleRelativePath", "Public/EasyXMLAsyncLoadFromString.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UEasyXMLAsyncLoadFromString_Statics::NewProp__XMLString = { "_XMLString", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEasyXMLAsyncLoadFromString, _XMLString), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLAsyncLoadFromString_Statics::NewProp__XMLString_MetaData), Z_Construct_UClass_UEasyXMLAsyncLoadFromString_Statics::NewProp__XMLString_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEasyXMLAsyncLoadFromString_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEasyXMLAsyncLoadFromString_Statics::NewProp_Successed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEasyXMLAsyncLoadFromString_Statics::NewProp_Failed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEasyXMLAsyncLoadFromString_Statics::NewProp__XMLString,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UEasyXMLAsyncLoadFromString_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEasyXMLAsyncLoadFromString>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UEasyXMLAsyncLoadFromString_Statics::ClassParams = {
		&UEasyXMLAsyncLoadFromString::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UEasyXMLAsyncLoadFromString_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLAsyncLoadFromString_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLAsyncLoadFromString_Statics::Class_MetaDataParams), Z_Construct_UClass_UEasyXMLAsyncLoadFromString_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLAsyncLoadFromString_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UEasyXMLAsyncLoadFromString()
	{
		if (!Z_Registration_Info_UClass_UEasyXMLAsyncLoadFromString.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEasyXMLAsyncLoadFromString.OuterSingleton, Z_Construct_UClass_UEasyXMLAsyncLoadFromString_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UEasyXMLAsyncLoadFromString.OuterSingleton;
	}
	template<> EASYXMLPARSER_API UClass* StaticClass<UEasyXMLAsyncLoadFromString>()
	{
		return UEasyXMLAsyncLoadFromString::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UEasyXMLAsyncLoadFromString);
	UEasyXMLAsyncLoadFromString::~UEasyXMLAsyncLoadFromString() {}
	struct Z_CompiledInDeferFile_FID_graphic_arcgisTest_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLAsyncLoadFromString_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_graphic_arcgisTest_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLAsyncLoadFromString_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UEasyXMLAsyncLoadFromString, UEasyXMLAsyncLoadFromString::StaticClass, TEXT("UEasyXMLAsyncLoadFromString"), &Z_Registration_Info_UClass_UEasyXMLAsyncLoadFromString, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEasyXMLAsyncLoadFromString), 84834431U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_graphic_arcgisTest_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLAsyncLoadFromString_h_686555104(TEXT("/Script/EasyXMLParser"),
		Z_CompiledInDeferFile_FID_graphic_arcgisTest_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLAsyncLoadFromString_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_graphic_arcgisTest_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLAsyncLoadFromString_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
