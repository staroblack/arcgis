// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EasyXMLParser/Public/EasyXMLAsyncLoadFromFile.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEasyXMLAsyncLoadFromFile() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	EASYXMLPARSER_API UClass* Z_Construct_UClass_UEasyXMLAsyncLoadFromFile();
	EASYXMLPARSER_API UClass* Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_NoRegister();
	EASYXMLPARSER_API UClass* Z_Construct_UClass_UEasyXMLElement_NoRegister();
	EASYXMLPARSER_API UFunction* Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromFile_Result__DelegateSignature();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintAsyncActionBase();
	UPackage* Z_Construct_UPackage__Script_EasyXMLParser();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromFile_Result__DelegateSignature_Statics
	{
		struct _Script_EasyXMLParser_eventEasyXMLAsyncLoadFromFile_Result_Parms
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
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromFile_Result__DelegateSignature_Statics::NewProp_XMLObject = { "XMLObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_EasyXMLParser_eventEasyXMLAsyncLoadFromFile_Result_Parms, XMLObject), Z_Construct_UClass_UEasyXMLElement_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromFile_Result__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_EasyXMLParser_eventEasyXMLAsyncLoadFromFile_Result_Parms, ErrorMessage), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromFile_Result__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromFile_Result__DelegateSignature_Statics::NewProp_XMLObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromFile_Result__DelegateSignature_Statics::NewProp_ErrorMessage,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromFile_Result__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/EasyXMLAsyncLoadFromFile.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromFile_Result__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_EasyXMLParser, nullptr, "EasyXMLAsyncLoadFromFile_Result__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromFile_Result__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromFile_Result__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromFile_Result__DelegateSignature_Statics::_Script_EasyXMLParser_eventEasyXMLAsyncLoadFromFile_Result_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromFile_Result__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromFile_Result__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromFile_Result__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromFile_Result__DelegateSignature_Statics::_Script_EasyXMLParser_eventEasyXMLAsyncLoadFromFile_Result_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromFile_Result__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromFile_Result__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FEasyXMLAsyncLoadFromFile_Result_DelegateWrapper(const FMulticastScriptDelegate& EasyXMLAsyncLoadFromFile_Result, UEasyXMLElement* XMLObject, const FString& ErrorMessage)
{
	struct _Script_EasyXMLParser_eventEasyXMLAsyncLoadFromFile_Result_Parms
	{
		UEasyXMLElement* XMLObject;
		FString ErrorMessage;
	};
	_Script_EasyXMLParser_eventEasyXMLAsyncLoadFromFile_Result_Parms Parms;
	Parms.XMLObject=XMLObject;
	Parms.ErrorMessage=ErrorMessage;
	EasyXMLAsyncLoadFromFile_Result.ProcessMulticastDelegate<UObject>(&Parms);
}
	DEFINE_FUNCTION(UEasyXMLAsyncLoadFromFile::execAsyncLoadFromFile)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_FilePath);
		P_GET_UBOOL(Z_Param_IsAblolute);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UEasyXMLAsyncLoadFromFile**)Z_Param__Result=UEasyXMLAsyncLoadFromFile::AsyncLoadFromFile(Z_Param_WorldContextObject,Z_Param_FilePath,Z_Param_IsAblolute);
		P_NATIVE_END;
	}
	void UEasyXMLAsyncLoadFromFile::StaticRegisterNativesUEasyXMLAsyncLoadFromFile()
	{
		UClass* Class = UEasyXMLAsyncLoadFromFile::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AsyncLoadFromFile", &UEasyXMLAsyncLoadFromFile::execAsyncLoadFromFile },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UEasyXMLAsyncLoadFromFile_AsyncLoadFromFile_Statics
	{
		struct EasyXMLAsyncLoadFromFile_eventAsyncLoadFromFile_Parms
		{
			UObject* WorldContextObject;
			FString FilePath;
			bool IsAblolute;
			UEasyXMLAsyncLoadFromFile* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FilePath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_FilePath;
		static void NewProp_IsAblolute_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsAblolute;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEasyXMLAsyncLoadFromFile_AsyncLoadFromFile_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLAsyncLoadFromFile_eventAsyncLoadFromFile_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEasyXMLAsyncLoadFromFile_AsyncLoadFromFile_Statics::NewProp_FilePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEasyXMLAsyncLoadFromFile_AsyncLoadFromFile_Statics::NewProp_FilePath = { "FilePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLAsyncLoadFromFile_eventAsyncLoadFromFile_Parms, FilePath), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLAsyncLoadFromFile_AsyncLoadFromFile_Statics::NewProp_FilePath_MetaData), Z_Construct_UFunction_UEasyXMLAsyncLoadFromFile_AsyncLoadFromFile_Statics::NewProp_FilePath_MetaData) };
	void Z_Construct_UFunction_UEasyXMLAsyncLoadFromFile_AsyncLoadFromFile_Statics::NewProp_IsAblolute_SetBit(void* Obj)
	{
		((EasyXMLAsyncLoadFromFile_eventAsyncLoadFromFile_Parms*)Obj)->IsAblolute = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEasyXMLAsyncLoadFromFile_AsyncLoadFromFile_Statics::NewProp_IsAblolute = { "IsAblolute", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EasyXMLAsyncLoadFromFile_eventAsyncLoadFromFile_Parms), &Z_Construct_UFunction_UEasyXMLAsyncLoadFromFile_AsyncLoadFromFile_Statics::NewProp_IsAblolute_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEasyXMLAsyncLoadFromFile_AsyncLoadFromFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLAsyncLoadFromFile_eventAsyncLoadFromFile_Parms, ReturnValue), Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEasyXMLAsyncLoadFromFile_AsyncLoadFromFile_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLAsyncLoadFromFile_AsyncLoadFromFile_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLAsyncLoadFromFile_AsyncLoadFromFile_Statics::NewProp_FilePath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLAsyncLoadFromFile_AsyncLoadFromFile_Statics::NewProp_IsAblolute,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLAsyncLoadFromFile_AsyncLoadFromFile_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEasyXMLAsyncLoadFromFile_AsyncLoadFromFile_Statics::Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "Category", "EasyXMLParser" },
		{ "ModuleRelativePath", "Public/EasyXMLAsyncLoadFromFile.h" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEasyXMLAsyncLoadFromFile_AsyncLoadFromFile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UEasyXMLAsyncLoadFromFile, nullptr, "AsyncLoadFromFile", nullptr, nullptr, Z_Construct_UFunction_UEasyXMLAsyncLoadFromFile_AsyncLoadFromFile_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLAsyncLoadFromFile_AsyncLoadFromFile_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEasyXMLAsyncLoadFromFile_AsyncLoadFromFile_Statics::EasyXMLAsyncLoadFromFile_eventAsyncLoadFromFile_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLAsyncLoadFromFile_AsyncLoadFromFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEasyXMLAsyncLoadFromFile_AsyncLoadFromFile_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLAsyncLoadFromFile_AsyncLoadFromFile_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UEasyXMLAsyncLoadFromFile_AsyncLoadFromFile_Statics::EasyXMLAsyncLoadFromFile_eventAsyncLoadFromFile_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UEasyXMLAsyncLoadFromFile_AsyncLoadFromFile()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEasyXMLAsyncLoadFromFile_AsyncLoadFromFile_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UEasyXMLAsyncLoadFromFile);
	UClass* Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_NoRegister()
	{
		return UEasyXMLAsyncLoadFromFile::StaticClass();
	}
	struct Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_Statics
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
		static const UECodeGen_Private::FMetaDataPairParam NewProp__XMLFile_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp__XMLFile;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp__IsAblolute_MetaData[];
#endif
		static void NewProp__IsAblolute_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp__IsAblolute;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintAsyncActionBase,
		(UObject* (*)())Z_Construct_UPackage__Script_EasyXMLParser,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UEasyXMLAsyncLoadFromFile_AsyncLoadFromFile, "AsyncLoadFromFile" }, // 3624552300
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "EasyXMLAsyncLoadFromFile.h" },
		{ "ModuleRelativePath", "Public/EasyXMLAsyncLoadFromFile.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_Statics::NewProp_Successed_MetaData[] = {
		{ "ModuleRelativePath", "Public/EasyXMLAsyncLoadFromFile.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_Statics::NewProp_Successed = { "Successed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEasyXMLAsyncLoadFromFile, Successed), Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromFile_Result__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_Statics::NewProp_Successed_MetaData), Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_Statics::NewProp_Successed_MetaData) }; // 4031217982
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_Statics::NewProp_Failed_MetaData[] = {
		{ "ModuleRelativePath", "Public/EasyXMLAsyncLoadFromFile.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_Statics::NewProp_Failed = { "Failed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEasyXMLAsyncLoadFromFile, Failed), Z_Construct_UDelegateFunction_EasyXMLParser_EasyXMLAsyncLoadFromFile_Result__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_Statics::NewProp_Failed_MetaData), Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_Statics::NewProp_Failed_MetaData) }; // 4031217982
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_Statics::NewProp__XMLFile_MetaData[] = {
		{ "ModuleRelativePath", "Public/EasyXMLAsyncLoadFromFile.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_Statics::NewProp__XMLFile = { "_XMLFile", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEasyXMLAsyncLoadFromFile, _XMLFile), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_Statics::NewProp__XMLFile_MetaData), Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_Statics::NewProp__XMLFile_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_Statics::NewProp__IsAblolute_MetaData[] = {
		{ "ModuleRelativePath", "Public/EasyXMLAsyncLoadFromFile.h" },
	};
#endif
	void Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_Statics::NewProp__IsAblolute_SetBit(void* Obj)
	{
		((UEasyXMLAsyncLoadFromFile*)Obj)->_IsAblolute = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_Statics::NewProp__IsAblolute = { "_IsAblolute", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UEasyXMLAsyncLoadFromFile), &Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_Statics::NewProp__IsAblolute_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_Statics::NewProp__IsAblolute_MetaData), Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_Statics::NewProp__IsAblolute_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_Statics::NewProp_Successed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_Statics::NewProp_Failed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_Statics::NewProp__XMLFile,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_Statics::NewProp__IsAblolute,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEasyXMLAsyncLoadFromFile>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_Statics::ClassParams = {
		&UEasyXMLAsyncLoadFromFile::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_Statics::Class_MetaDataParams), Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UEasyXMLAsyncLoadFromFile()
	{
		if (!Z_Registration_Info_UClass_UEasyXMLAsyncLoadFromFile.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEasyXMLAsyncLoadFromFile.OuterSingleton, Z_Construct_UClass_UEasyXMLAsyncLoadFromFile_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UEasyXMLAsyncLoadFromFile.OuterSingleton;
	}
	template<> EASYXMLPARSER_API UClass* StaticClass<UEasyXMLAsyncLoadFromFile>()
	{
		return UEasyXMLAsyncLoadFromFile::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UEasyXMLAsyncLoadFromFile);
	UEasyXMLAsyncLoadFromFile::~UEasyXMLAsyncLoadFromFile() {}
	struct Z_CompiledInDeferFile_FID_graphics_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLAsyncLoadFromFile_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_graphics_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLAsyncLoadFromFile_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UEasyXMLAsyncLoadFromFile, UEasyXMLAsyncLoadFromFile::StaticClass, TEXT("UEasyXMLAsyncLoadFromFile"), &Z_Registration_Info_UClass_UEasyXMLAsyncLoadFromFile, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEasyXMLAsyncLoadFromFile), 3622247318U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_graphics_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLAsyncLoadFromFile_h_1166116263(TEXT("/Script/EasyXMLParser"),
		Z_CompiledInDeferFile_FID_graphics_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLAsyncLoadFromFile_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_graphics_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLAsyncLoadFromFile_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
