// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EasyXMLParser/Public/EasyXMLObject.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEasyXMLObject() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	EASYXMLPARSER_API UClass* Z_Construct_UClass_UEasyXMLObject();
	EASYXMLPARSER_API UClass* Z_Construct_UClass_UEasyXMLObject_NoRegister();
	UPackage* Z_Construct_UPackage__Script_EasyXMLParser();
// End Cross Module References
	DEFINE_FUNCTION(UEasyXMLObject::execGetBoolValue)
	{
		P_GET_UBOOL(Z_Param_DefaultValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetBoolValue(Z_Param_DefaultValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UEasyXMLObject::execGetStringValue)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_DefaultValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetStringValue(Z_Param_DefaultValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UEasyXMLObject::execGetFloatValue)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_DefaultValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetFloatValue(Z_Param_DefaultValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UEasyXMLObject::execGetIntValue)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_DefaultValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetIntValue(Z_Param_DefaultValue);
		P_NATIVE_END;
	}
	void UEasyXMLObject::StaticRegisterNativesUEasyXMLObject()
	{
		UClass* Class = UEasyXMLObject::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetBoolValue", &UEasyXMLObject::execGetBoolValue },
			{ "GetFloatValue", &UEasyXMLObject::execGetFloatValue },
			{ "GetIntValue", &UEasyXMLObject::execGetIntValue },
			{ "GetStringValue", &UEasyXMLObject::execGetStringValue },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UEasyXMLObject_GetBoolValue_Statics
	{
		struct EasyXMLObject_eventGetBoolValue_Parms
		{
			bool DefaultValue;
			bool ReturnValue;
		};
		static void NewProp_DefaultValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_DefaultValue;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UEasyXMLObject_GetBoolValue_Statics::NewProp_DefaultValue_SetBit(void* Obj)
	{
		((EasyXMLObject_eventGetBoolValue_Parms*)Obj)->DefaultValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEasyXMLObject_GetBoolValue_Statics::NewProp_DefaultValue = { "DefaultValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EasyXMLObject_eventGetBoolValue_Parms), &Z_Construct_UFunction_UEasyXMLObject_GetBoolValue_Statics::NewProp_DefaultValue_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UEasyXMLObject_GetBoolValue_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((EasyXMLObject_eventGetBoolValue_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEasyXMLObject_GetBoolValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EasyXMLObject_eventGetBoolValue_Parms), &Z_Construct_UFunction_UEasyXMLObject_GetBoolValue_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEasyXMLObject_GetBoolValue_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLObject_GetBoolValue_Statics::NewProp_DefaultValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLObject_GetBoolValue_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEasyXMLObject_GetBoolValue_Statics::Function_MetaDataParams[] = {
		{ "Category", "EasyXMLParser|GetValue" },
		{ "CPP_Default_DefaultValue", "false" },
		{ "ModuleRelativePath", "Public/EasyXMLObject.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEasyXMLObject_GetBoolValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UEasyXMLObject, nullptr, "GetBoolValue", nullptr, nullptr, Z_Construct_UFunction_UEasyXMLObject_GetBoolValue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLObject_GetBoolValue_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEasyXMLObject_GetBoolValue_Statics::EasyXMLObject_eventGetBoolValue_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLObject_GetBoolValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEasyXMLObject_GetBoolValue_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLObject_GetBoolValue_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UEasyXMLObject_GetBoolValue_Statics::EasyXMLObject_eventGetBoolValue_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UEasyXMLObject_GetBoolValue()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEasyXMLObject_GetBoolValue_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UEasyXMLObject_GetFloatValue_Statics
	{
		struct EasyXMLObject_eventGetFloatValue_Parms
		{
			float DefaultValue;
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DefaultValue;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UEasyXMLObject_GetFloatValue_Statics::NewProp_DefaultValue = { "DefaultValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLObject_eventGetFloatValue_Parms, DefaultValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UEasyXMLObject_GetFloatValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLObject_eventGetFloatValue_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEasyXMLObject_GetFloatValue_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLObject_GetFloatValue_Statics::NewProp_DefaultValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLObject_GetFloatValue_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEasyXMLObject_GetFloatValue_Statics::Function_MetaDataParams[] = {
		{ "Category", "EasyXMLParser|GetValue" },
		{ "CPP_Default_DefaultValue", "0.000000" },
		{ "ModuleRelativePath", "Public/EasyXMLObject.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEasyXMLObject_GetFloatValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UEasyXMLObject, nullptr, "GetFloatValue", nullptr, nullptr, Z_Construct_UFunction_UEasyXMLObject_GetFloatValue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLObject_GetFloatValue_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEasyXMLObject_GetFloatValue_Statics::EasyXMLObject_eventGetFloatValue_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLObject_GetFloatValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEasyXMLObject_GetFloatValue_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLObject_GetFloatValue_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UEasyXMLObject_GetFloatValue_Statics::EasyXMLObject_eventGetFloatValue_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UEasyXMLObject_GetFloatValue()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEasyXMLObject_GetFloatValue_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UEasyXMLObject_GetIntValue_Statics
	{
		struct EasyXMLObject_eventGetIntValue_Parms
		{
			int32 DefaultValue;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_DefaultValue;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UEasyXMLObject_GetIntValue_Statics::NewProp_DefaultValue = { "DefaultValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLObject_eventGetIntValue_Parms, DefaultValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UEasyXMLObject_GetIntValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLObject_eventGetIntValue_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEasyXMLObject_GetIntValue_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLObject_GetIntValue_Statics::NewProp_DefaultValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLObject_GetIntValue_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEasyXMLObject_GetIntValue_Statics::Function_MetaDataParams[] = {
		{ "Category", "EasyXMLParser|GetValue" },
		{ "CPP_Default_DefaultValue", "0" },
		{ "ModuleRelativePath", "Public/EasyXMLObject.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEasyXMLObject_GetIntValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UEasyXMLObject, nullptr, "GetIntValue", nullptr, nullptr, Z_Construct_UFunction_UEasyXMLObject_GetIntValue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLObject_GetIntValue_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEasyXMLObject_GetIntValue_Statics::EasyXMLObject_eventGetIntValue_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLObject_GetIntValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEasyXMLObject_GetIntValue_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLObject_GetIntValue_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UEasyXMLObject_GetIntValue_Statics::EasyXMLObject_eventGetIntValue_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UEasyXMLObject_GetIntValue()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEasyXMLObject_GetIntValue_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UEasyXMLObject_GetStringValue_Statics
	{
		struct EasyXMLObject_eventGetStringValue_Parms
		{
			FString DefaultValue;
			FString ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_DefaultValue;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEasyXMLObject_GetStringValue_Statics::NewProp_DefaultValue = { "DefaultValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLObject_eventGetStringValue_Parms, DefaultValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEasyXMLObject_GetStringValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLObject_eventGetStringValue_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEasyXMLObject_GetStringValue_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLObject_GetStringValue_Statics::NewProp_DefaultValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLObject_GetStringValue_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEasyXMLObject_GetStringValue_Statics::Function_MetaDataParams[] = {
		{ "Category", "EasyXMLParser|GetValue" },
		{ "CPP_Default_DefaultValue", "" },
		{ "ModuleRelativePath", "Public/EasyXMLObject.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEasyXMLObject_GetStringValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UEasyXMLObject, nullptr, "GetStringValue", nullptr, nullptr, Z_Construct_UFunction_UEasyXMLObject_GetStringValue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLObject_GetStringValue_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEasyXMLObject_GetStringValue_Statics::EasyXMLObject_eventGetStringValue_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLObject_GetStringValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEasyXMLObject_GetStringValue_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLObject_GetStringValue_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UEasyXMLObject_GetStringValue_Statics::EasyXMLObject_eventGetStringValue_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UEasyXMLObject_GetStringValue()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEasyXMLObject_GetStringValue_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UEasyXMLObject);
	UClass* Z_Construct_UClass_UEasyXMLObject_NoRegister()
	{
		return UEasyXMLObject::StaticClass();
	}
	struct Z_Construct_UClass_UEasyXMLObject_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Value;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Parent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Parent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UEasyXMLObject_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_EasyXMLParser,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLObject_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UEasyXMLObject_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UEasyXMLObject_GetBoolValue, "GetBoolValue" }, // 166907217
		{ &Z_Construct_UFunction_UEasyXMLObject_GetFloatValue, "GetFloatValue" }, // 2360412551
		{ &Z_Construct_UFunction_UEasyXMLObject_GetIntValue, "GetIntValue" }, // 306641911
		{ &Z_Construct_UFunction_UEasyXMLObject_GetStringValue, "GetStringValue" }, // 116593554
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLObject_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEasyXMLObject_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "EasyXMLObject.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/EasyXMLObject.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEasyXMLObject_Statics::NewProp_Name_MetaData[] = {
		{ "Category", "EasyXMLParser|Object" },
		{ "ModuleRelativePath", "Public/EasyXMLObject.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UEasyXMLObject_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEasyXMLObject, Name), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLObject_Statics::NewProp_Name_MetaData), Z_Construct_UClass_UEasyXMLObject_Statics::NewProp_Name_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEasyXMLObject_Statics::NewProp_Value_MetaData[] = {
		{ "Category", "EasyXMLParser|Object" },
		{ "ModuleRelativePath", "Public/EasyXMLObject.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UEasyXMLObject_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEasyXMLObject, Value), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLObject_Statics::NewProp_Value_MetaData), Z_Construct_UClass_UEasyXMLObject_Statics::NewProp_Value_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEasyXMLObject_Statics::NewProp_Parent_MetaData[] = {
		{ "Category", "EasyXMLParser|Object" },
		{ "ModuleRelativePath", "Public/EasyXMLObject.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEasyXMLObject_Statics::NewProp_Parent = { "Parent", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEasyXMLObject, Parent), Z_Construct_UClass_UEasyXMLObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLObject_Statics::NewProp_Parent_MetaData), Z_Construct_UClass_UEasyXMLObject_Statics::NewProp_Parent_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEasyXMLObject_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEasyXMLObject_Statics::NewProp_Name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEasyXMLObject_Statics::NewProp_Value,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEasyXMLObject_Statics::NewProp_Parent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UEasyXMLObject_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEasyXMLObject>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UEasyXMLObject_Statics::ClassParams = {
		&UEasyXMLObject::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UEasyXMLObject_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLObject_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLObject_Statics::Class_MetaDataParams), Z_Construct_UClass_UEasyXMLObject_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLObject_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UEasyXMLObject()
	{
		if (!Z_Registration_Info_UClass_UEasyXMLObject.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEasyXMLObject.OuterSingleton, Z_Construct_UClass_UEasyXMLObject_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UEasyXMLObject.OuterSingleton;
	}
	template<> EASYXMLPARSER_API UClass* StaticClass<UEasyXMLObject>()
	{
		return UEasyXMLObject::StaticClass();
	}
	UEasyXMLObject::UEasyXMLObject(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UEasyXMLObject);
	UEasyXMLObject::~UEasyXMLObject() {}
	struct Z_CompiledInDeferFile_FID_graphic_arcgisTest_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLObject_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_graphic_arcgisTest_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLObject_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UEasyXMLObject, UEasyXMLObject::StaticClass, TEXT("UEasyXMLObject"), &Z_Registration_Info_UClass_UEasyXMLObject, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEasyXMLObject), 2724430693U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_graphic_arcgisTest_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLObject_h_2720764304(TEXT("/Script/EasyXMLParser"),
		Z_CompiledInDeferFile_FID_graphic_arcgisTest_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLObject_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_graphic_arcgisTest_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLObject_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
