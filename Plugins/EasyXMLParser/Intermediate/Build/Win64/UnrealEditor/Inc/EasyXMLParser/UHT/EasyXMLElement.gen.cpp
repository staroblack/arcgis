// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EasyXMLParser/Public/EasyXMLElement.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEasyXMLElement() {}
// Cross Module References
	EASYXMLPARSER_API UClass* Z_Construct_UClass_UEasyXMLAttribute_NoRegister();
	EASYXMLPARSER_API UClass* Z_Construct_UClass_UEasyXMLElement();
	EASYXMLPARSER_API UClass* Z_Construct_UClass_UEasyXMLElement_NoRegister();
	EASYXMLPARSER_API UClass* Z_Construct_UClass_UEasyXMLObject();
	EASYXMLPARSER_API UEnum* Z_Construct_UEnum_EasyXMLParser_EEasyXMLParserFound();
	UPackage* Z_Construct_UPackage__Script_EasyXMLParser();
// End Cross Module References
	DEFINE_FUNCTION(UEasyXMLElement::execGetAttribute)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_AtrributeName);
		P_GET_ENUM_REF(EEasyXMLParserFound,Z_Param_Out_Result);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UEasyXMLAttribute**)Z_Param__Result=P_THIS->GetAttribute(Z_Param_AtrributeName,(EEasyXMLParserFound&)(Z_Param_Out_Result));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UEasyXMLElement::execReadElements)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_AccessString);
		P_GET_ENUM_REF(EEasyXMLParserFound,Z_Param_Out_Result);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<UEasyXMLElement*>*)Z_Param__Result=P_THIS->ReadElements(Z_Param_AccessString,(EEasyXMLParserFound&)(Z_Param_Out_Result));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UEasyXMLElement::execReadElement)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_AccessString);
		P_GET_ENUM_REF(EEasyXMLParserFound,Z_Param_Out_Result);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UEasyXMLElement**)Z_Param__Result=P_THIS->ReadElement(Z_Param_AccessString,(EEasyXMLParserFound&)(Z_Param_Out_Result));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UEasyXMLElement::execReadBool)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_AccessString);
		P_GET_UBOOL(Z_Param_DefaultValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->ReadBool(Z_Param_AccessString,Z_Param_DefaultValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UEasyXMLElement::execReadString)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_AccessString);
		P_GET_PROPERTY(FStrProperty,Z_Param_DefaultValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->ReadString(Z_Param_AccessString,Z_Param_DefaultValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UEasyXMLElement::execReadFloat)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_AccessString);
		P_GET_PROPERTY(FFloatProperty,Z_Param_DefaultValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->ReadFloat(Z_Param_AccessString,Z_Param_DefaultValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UEasyXMLElement::execReadInt)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_AccessString);
		P_GET_PROPERTY(FIntProperty,Z_Param_DefaultValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->ReadInt(Z_Param_AccessString,Z_Param_DefaultValue);
		P_NATIVE_END;
	}
	void UEasyXMLElement::StaticRegisterNativesUEasyXMLElement()
	{
		UClass* Class = UEasyXMLElement::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetAttribute", &UEasyXMLElement::execGetAttribute },
			{ "ReadBool", &UEasyXMLElement::execReadBool },
			{ "ReadElement", &UEasyXMLElement::execReadElement },
			{ "ReadElements", &UEasyXMLElement::execReadElements },
			{ "ReadFloat", &UEasyXMLElement::execReadFloat },
			{ "ReadInt", &UEasyXMLElement::execReadInt },
			{ "ReadString", &UEasyXMLElement::execReadString },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UEasyXMLElement_GetAttribute_Statics
	{
		struct EasyXMLElement_eventGetAttribute_Parms
		{
			FString AtrributeName;
			EEasyXMLParserFound Result;
			UEasyXMLAttribute* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AtrributeName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_AtrributeName;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Result_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Result;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEasyXMLElement_GetAttribute_Statics::NewProp_AtrributeName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEasyXMLElement_GetAttribute_Statics::NewProp_AtrributeName = { "AtrributeName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLElement_eventGetAttribute_Parms, AtrributeName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLElement_GetAttribute_Statics::NewProp_AtrributeName_MetaData), Z_Construct_UFunction_UEasyXMLElement_GetAttribute_Statics::NewProp_AtrributeName_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UEasyXMLElement_GetAttribute_Statics::NewProp_Result_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UEasyXMLElement_GetAttribute_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLElement_eventGetAttribute_Parms, Result), Z_Construct_UEnum_EasyXMLParser_EEasyXMLParserFound, METADATA_PARAMS(0, nullptr) }; // 2185933784
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEasyXMLElement_GetAttribute_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLElement_eventGetAttribute_Parms, ReturnValue), Z_Construct_UClass_UEasyXMLAttribute_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEasyXMLElement_GetAttribute_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLElement_GetAttribute_Statics::NewProp_AtrributeName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLElement_GetAttribute_Statics::NewProp_Result_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLElement_GetAttribute_Statics::NewProp_Result,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLElement_GetAttribute_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEasyXMLElement_GetAttribute_Statics::Function_MetaDataParams[] = {
		{ "Category", "EasyXMLParser|Object" },
		{ "ExpandEnumAsExecs", "Result" },
		{ "ModuleRelativePath", "Public/EasyXMLElement.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEasyXMLElement_GetAttribute_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UEasyXMLElement, nullptr, "GetAttribute", nullptr, nullptr, Z_Construct_UFunction_UEasyXMLElement_GetAttribute_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLElement_GetAttribute_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEasyXMLElement_GetAttribute_Statics::EasyXMLElement_eventGetAttribute_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLElement_GetAttribute_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEasyXMLElement_GetAttribute_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLElement_GetAttribute_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UEasyXMLElement_GetAttribute_Statics::EasyXMLElement_eventGetAttribute_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UEasyXMLElement_GetAttribute()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEasyXMLElement_GetAttribute_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UEasyXMLElement_ReadBool_Statics
	{
		struct EasyXMLElement_eventReadBool_Parms
		{
			FString AccessString;
			bool DefaultValue;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AccessString_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_AccessString;
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
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEasyXMLElement_ReadBool_Statics::NewProp_AccessString_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEasyXMLElement_ReadBool_Statics::NewProp_AccessString = { "AccessString", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLElement_eventReadBool_Parms, AccessString), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLElement_ReadBool_Statics::NewProp_AccessString_MetaData), Z_Construct_UFunction_UEasyXMLElement_ReadBool_Statics::NewProp_AccessString_MetaData) };
	void Z_Construct_UFunction_UEasyXMLElement_ReadBool_Statics::NewProp_DefaultValue_SetBit(void* Obj)
	{
		((EasyXMLElement_eventReadBool_Parms*)Obj)->DefaultValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEasyXMLElement_ReadBool_Statics::NewProp_DefaultValue = { "DefaultValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EasyXMLElement_eventReadBool_Parms), &Z_Construct_UFunction_UEasyXMLElement_ReadBool_Statics::NewProp_DefaultValue_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UEasyXMLElement_ReadBool_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((EasyXMLElement_eventReadBool_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEasyXMLElement_ReadBool_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EasyXMLElement_eventReadBool_Parms), &Z_Construct_UFunction_UEasyXMLElement_ReadBool_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEasyXMLElement_ReadBool_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLElement_ReadBool_Statics::NewProp_AccessString,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLElement_ReadBool_Statics::NewProp_DefaultValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLElement_ReadBool_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEasyXMLElement_ReadBool_Statics::Function_MetaDataParams[] = {
		{ "Category", "EasyXMLParser|ReadValue" },
		{ "CPP_Default_DefaultValue", "false" },
		{ "ModuleRelativePath", "Public/EasyXMLElement.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEasyXMLElement_ReadBool_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UEasyXMLElement, nullptr, "ReadBool", nullptr, nullptr, Z_Construct_UFunction_UEasyXMLElement_ReadBool_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLElement_ReadBool_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEasyXMLElement_ReadBool_Statics::EasyXMLElement_eventReadBool_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLElement_ReadBool_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEasyXMLElement_ReadBool_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLElement_ReadBool_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UEasyXMLElement_ReadBool_Statics::EasyXMLElement_eventReadBool_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UEasyXMLElement_ReadBool()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEasyXMLElement_ReadBool_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UEasyXMLElement_ReadElement_Statics
	{
		struct EasyXMLElement_eventReadElement_Parms
		{
			FString AccessString;
			EEasyXMLParserFound Result;
			UEasyXMLElement* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AccessString_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_AccessString;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Result_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Result;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEasyXMLElement_ReadElement_Statics::NewProp_AccessString_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEasyXMLElement_ReadElement_Statics::NewProp_AccessString = { "AccessString", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLElement_eventReadElement_Parms, AccessString), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLElement_ReadElement_Statics::NewProp_AccessString_MetaData), Z_Construct_UFunction_UEasyXMLElement_ReadElement_Statics::NewProp_AccessString_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UEasyXMLElement_ReadElement_Statics::NewProp_Result_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UEasyXMLElement_ReadElement_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLElement_eventReadElement_Parms, Result), Z_Construct_UEnum_EasyXMLParser_EEasyXMLParserFound, METADATA_PARAMS(0, nullptr) }; // 2185933784
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEasyXMLElement_ReadElement_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLElement_eventReadElement_Parms, ReturnValue), Z_Construct_UClass_UEasyXMLElement_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEasyXMLElement_ReadElement_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLElement_ReadElement_Statics::NewProp_AccessString,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLElement_ReadElement_Statics::NewProp_Result_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLElement_ReadElement_Statics::NewProp_Result,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLElement_ReadElement_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEasyXMLElement_ReadElement_Statics::Function_MetaDataParams[] = {
		{ "Category", "EasyXMLParser|ReadValue" },
		{ "ExpandEnumAsExecs", "Result" },
		{ "ModuleRelativePath", "Public/EasyXMLElement.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEasyXMLElement_ReadElement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UEasyXMLElement, nullptr, "ReadElement", nullptr, nullptr, Z_Construct_UFunction_UEasyXMLElement_ReadElement_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLElement_ReadElement_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEasyXMLElement_ReadElement_Statics::EasyXMLElement_eventReadElement_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLElement_ReadElement_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEasyXMLElement_ReadElement_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLElement_ReadElement_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UEasyXMLElement_ReadElement_Statics::EasyXMLElement_eventReadElement_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UEasyXMLElement_ReadElement()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEasyXMLElement_ReadElement_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UEasyXMLElement_ReadElements_Statics
	{
		struct EasyXMLElement_eventReadElements_Parms
		{
			FString AccessString;
			EEasyXMLParserFound Result;
			TArray<UEasyXMLElement*> ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AccessString_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_AccessString;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Result_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Result;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEasyXMLElement_ReadElements_Statics::NewProp_AccessString_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEasyXMLElement_ReadElements_Statics::NewProp_AccessString = { "AccessString", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLElement_eventReadElements_Parms, AccessString), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLElement_ReadElements_Statics::NewProp_AccessString_MetaData), Z_Construct_UFunction_UEasyXMLElement_ReadElements_Statics::NewProp_AccessString_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UEasyXMLElement_ReadElements_Statics::NewProp_Result_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UEasyXMLElement_ReadElements_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLElement_eventReadElements_Parms, Result), Z_Construct_UEnum_EasyXMLParser_EEasyXMLParserFound, METADATA_PARAMS(0, nullptr) }; // 2185933784
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEasyXMLElement_ReadElements_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UEasyXMLElement_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UEasyXMLElement_ReadElements_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLElement_eventReadElements_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEasyXMLElement_ReadElements_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLElement_ReadElements_Statics::NewProp_AccessString,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLElement_ReadElements_Statics::NewProp_Result_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLElement_ReadElements_Statics::NewProp_Result,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLElement_ReadElements_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLElement_ReadElements_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEasyXMLElement_ReadElements_Statics::Function_MetaDataParams[] = {
		{ "Category", "EasyXMLParser|ReadValue" },
		{ "ExpandEnumAsExecs", "Result" },
		{ "ModuleRelativePath", "Public/EasyXMLElement.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEasyXMLElement_ReadElements_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UEasyXMLElement, nullptr, "ReadElements", nullptr, nullptr, Z_Construct_UFunction_UEasyXMLElement_ReadElements_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLElement_ReadElements_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEasyXMLElement_ReadElements_Statics::EasyXMLElement_eventReadElements_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLElement_ReadElements_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEasyXMLElement_ReadElements_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLElement_ReadElements_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UEasyXMLElement_ReadElements_Statics::EasyXMLElement_eventReadElements_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UEasyXMLElement_ReadElements()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEasyXMLElement_ReadElements_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UEasyXMLElement_ReadFloat_Statics
	{
		struct EasyXMLElement_eventReadFloat_Parms
		{
			FString AccessString;
			float DefaultValue;
			float ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AccessString_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_AccessString;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DefaultValue;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEasyXMLElement_ReadFloat_Statics::NewProp_AccessString_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEasyXMLElement_ReadFloat_Statics::NewProp_AccessString = { "AccessString", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLElement_eventReadFloat_Parms, AccessString), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLElement_ReadFloat_Statics::NewProp_AccessString_MetaData), Z_Construct_UFunction_UEasyXMLElement_ReadFloat_Statics::NewProp_AccessString_MetaData) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UEasyXMLElement_ReadFloat_Statics::NewProp_DefaultValue = { "DefaultValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLElement_eventReadFloat_Parms, DefaultValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UEasyXMLElement_ReadFloat_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLElement_eventReadFloat_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEasyXMLElement_ReadFloat_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLElement_ReadFloat_Statics::NewProp_AccessString,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLElement_ReadFloat_Statics::NewProp_DefaultValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLElement_ReadFloat_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEasyXMLElement_ReadFloat_Statics::Function_MetaDataParams[] = {
		{ "Category", "EasyXMLParser|ReadValue" },
		{ "CPP_Default_DefaultValue", "0.000000" },
		{ "ModuleRelativePath", "Public/EasyXMLElement.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEasyXMLElement_ReadFloat_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UEasyXMLElement, nullptr, "ReadFloat", nullptr, nullptr, Z_Construct_UFunction_UEasyXMLElement_ReadFloat_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLElement_ReadFloat_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEasyXMLElement_ReadFloat_Statics::EasyXMLElement_eventReadFloat_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLElement_ReadFloat_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEasyXMLElement_ReadFloat_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLElement_ReadFloat_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UEasyXMLElement_ReadFloat_Statics::EasyXMLElement_eventReadFloat_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UEasyXMLElement_ReadFloat()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEasyXMLElement_ReadFloat_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UEasyXMLElement_ReadInt_Statics
	{
		struct EasyXMLElement_eventReadInt_Parms
		{
			FString AccessString;
			int32 DefaultValue;
			int32 ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AccessString_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_AccessString;
		static const UECodeGen_Private::FIntPropertyParams NewProp_DefaultValue;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEasyXMLElement_ReadInt_Statics::NewProp_AccessString_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEasyXMLElement_ReadInt_Statics::NewProp_AccessString = { "AccessString", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLElement_eventReadInt_Parms, AccessString), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLElement_ReadInt_Statics::NewProp_AccessString_MetaData), Z_Construct_UFunction_UEasyXMLElement_ReadInt_Statics::NewProp_AccessString_MetaData) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UEasyXMLElement_ReadInt_Statics::NewProp_DefaultValue = { "DefaultValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLElement_eventReadInt_Parms, DefaultValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UEasyXMLElement_ReadInt_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLElement_eventReadInt_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEasyXMLElement_ReadInt_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLElement_ReadInt_Statics::NewProp_AccessString,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLElement_ReadInt_Statics::NewProp_DefaultValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLElement_ReadInt_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEasyXMLElement_ReadInt_Statics::Function_MetaDataParams[] = {
		{ "Category", "EasyXMLParser|ReadValue" },
		{ "CPP_Default_DefaultValue", "0" },
		{ "ModuleRelativePath", "Public/EasyXMLElement.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEasyXMLElement_ReadInt_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UEasyXMLElement, nullptr, "ReadInt", nullptr, nullptr, Z_Construct_UFunction_UEasyXMLElement_ReadInt_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLElement_ReadInt_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEasyXMLElement_ReadInt_Statics::EasyXMLElement_eventReadInt_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLElement_ReadInt_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEasyXMLElement_ReadInt_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLElement_ReadInt_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UEasyXMLElement_ReadInt_Statics::EasyXMLElement_eventReadInt_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UEasyXMLElement_ReadInt()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEasyXMLElement_ReadInt_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UEasyXMLElement_ReadString_Statics
	{
		struct EasyXMLElement_eventReadString_Parms
		{
			FString AccessString;
			FString DefaultValue;
			FString ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AccessString_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_AccessString;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultValue_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_DefaultValue;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEasyXMLElement_ReadString_Statics::NewProp_AccessString_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEasyXMLElement_ReadString_Statics::NewProp_AccessString = { "AccessString", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLElement_eventReadString_Parms, AccessString), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLElement_ReadString_Statics::NewProp_AccessString_MetaData), Z_Construct_UFunction_UEasyXMLElement_ReadString_Statics::NewProp_AccessString_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEasyXMLElement_ReadString_Statics::NewProp_DefaultValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEasyXMLElement_ReadString_Statics::NewProp_DefaultValue = { "DefaultValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLElement_eventReadString_Parms, DefaultValue), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLElement_ReadString_Statics::NewProp_DefaultValue_MetaData), Z_Construct_UFunction_UEasyXMLElement_ReadString_Statics::NewProp_DefaultValue_MetaData) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEasyXMLElement_ReadString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EasyXMLElement_eventReadString_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEasyXMLElement_ReadString_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLElement_ReadString_Statics::NewProp_AccessString,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLElement_ReadString_Statics::NewProp_DefaultValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEasyXMLElement_ReadString_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEasyXMLElement_ReadString_Statics::Function_MetaDataParams[] = {
		{ "Category", "EasyXMLParser|ReadValue" },
		{ "CPP_Default_DefaultValue", "" },
		{ "ModuleRelativePath", "Public/EasyXMLElement.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEasyXMLElement_ReadString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UEasyXMLElement, nullptr, "ReadString", nullptr, nullptr, Z_Construct_UFunction_UEasyXMLElement_ReadString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLElement_ReadString_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEasyXMLElement_ReadString_Statics::EasyXMLElement_eventReadString_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLElement_ReadString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEasyXMLElement_ReadString_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEasyXMLElement_ReadString_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UEasyXMLElement_ReadString_Statics::EasyXMLElement_eventReadString_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UEasyXMLElement_ReadString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEasyXMLElement_ReadString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UEasyXMLElement);
	UClass* Z_Construct_UClass_UEasyXMLElement_NoRegister()
	{
		return UEasyXMLElement::StaticClass();
	}
	struct Z_Construct_UClass_UEasyXMLElement_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LineNumber_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_LineNumber;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Children_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Children_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Children;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Attributes_ValueProp;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Attributes_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Attributes_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_Attributes;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Comments_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Comments_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Comments;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UEasyXMLElement_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UEasyXMLObject,
		(UObject* (*)())Z_Construct_UPackage__Script_EasyXMLParser,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLElement_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UEasyXMLElement_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UEasyXMLElement_GetAttribute, "GetAttribute" }, // 484434310
		{ &Z_Construct_UFunction_UEasyXMLElement_ReadBool, "ReadBool" }, // 227506533
		{ &Z_Construct_UFunction_UEasyXMLElement_ReadElement, "ReadElement" }, // 4183157341
		{ &Z_Construct_UFunction_UEasyXMLElement_ReadElements, "ReadElements" }, // 2440327088
		{ &Z_Construct_UFunction_UEasyXMLElement_ReadFloat, "ReadFloat" }, // 2450807716
		{ &Z_Construct_UFunction_UEasyXMLElement_ReadInt, "ReadInt" }, // 3684101586
		{ &Z_Construct_UFunction_UEasyXMLElement_ReadString, "ReadString" }, // 3444208831
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLElement_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEasyXMLElement_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "EasyXMLElement.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/EasyXMLElement.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEasyXMLElement_Statics::NewProp_LineNumber_MetaData[] = {
		{ "Category", "EasyXMLParser|Object" },
		{ "ModuleRelativePath", "Public/EasyXMLElement.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UEasyXMLElement_Statics::NewProp_LineNumber = { "LineNumber", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEasyXMLElement, LineNumber), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLElement_Statics::NewProp_LineNumber_MetaData), Z_Construct_UClass_UEasyXMLElement_Statics::NewProp_LineNumber_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEasyXMLElement_Statics::NewProp_Children_Inner = { "Children", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UEasyXMLElement_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEasyXMLElement_Statics::NewProp_Children_MetaData[] = {
		{ "Category", "EasyXMLParser|Object" },
		{ "ModuleRelativePath", "Public/EasyXMLElement.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UEasyXMLElement_Statics::NewProp_Children = { "Children", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEasyXMLElement, Children), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLElement_Statics::NewProp_Children_MetaData), Z_Construct_UClass_UEasyXMLElement_Statics::NewProp_Children_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEasyXMLElement_Statics::NewProp_Attributes_ValueProp = { "Attributes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UEasyXMLAttribute_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UEasyXMLElement_Statics::NewProp_Attributes_Key_KeyProp = { "Attributes_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEasyXMLElement_Statics::NewProp_Attributes_MetaData[] = {
		{ "Category", "EasyXMLParser|Object" },
		{ "ModuleRelativePath", "Public/EasyXMLElement.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UEasyXMLElement_Statics::NewProp_Attributes = { "Attributes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEasyXMLElement, Attributes), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLElement_Statics::NewProp_Attributes_MetaData), Z_Construct_UClass_UEasyXMLElement_Statics::NewProp_Attributes_MetaData) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UEasyXMLElement_Statics::NewProp_Comments_Inner = { "Comments", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEasyXMLElement_Statics::NewProp_Comments_MetaData[] = {
		{ "Category", "EasyXMLParser|Object" },
		{ "ModuleRelativePath", "Public/EasyXMLElement.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UEasyXMLElement_Statics::NewProp_Comments = { "Comments", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEasyXMLElement, Comments), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLElement_Statics::NewProp_Comments_MetaData), Z_Construct_UClass_UEasyXMLElement_Statics::NewProp_Comments_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEasyXMLElement_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEasyXMLElement_Statics::NewProp_LineNumber,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEasyXMLElement_Statics::NewProp_Children_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEasyXMLElement_Statics::NewProp_Children,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEasyXMLElement_Statics::NewProp_Attributes_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEasyXMLElement_Statics::NewProp_Attributes_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEasyXMLElement_Statics::NewProp_Attributes,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEasyXMLElement_Statics::NewProp_Comments_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEasyXMLElement_Statics::NewProp_Comments,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UEasyXMLElement_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEasyXMLElement>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UEasyXMLElement_Statics::ClassParams = {
		&UEasyXMLElement::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UEasyXMLElement_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLElement_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLElement_Statics::Class_MetaDataParams), Z_Construct_UClass_UEasyXMLElement_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEasyXMLElement_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UEasyXMLElement()
	{
		if (!Z_Registration_Info_UClass_UEasyXMLElement.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEasyXMLElement.OuterSingleton, Z_Construct_UClass_UEasyXMLElement_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UEasyXMLElement.OuterSingleton;
	}
	template<> EASYXMLPARSER_API UClass* StaticClass<UEasyXMLElement>()
	{
		return UEasyXMLElement::StaticClass();
	}
	UEasyXMLElement::UEasyXMLElement(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UEasyXMLElement);
	UEasyXMLElement::~UEasyXMLElement() {}
	struct Z_CompiledInDeferFile_FID_graphics_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLElement_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_graphics_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLElement_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UEasyXMLElement, UEasyXMLElement::StaticClass, TEXT("UEasyXMLElement"), &Z_Registration_Info_UClass_UEasyXMLElement, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEasyXMLElement), 3677970448U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_graphics_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLElement_h_1187375249(TEXT("/Script/EasyXMLParser"),
		Z_CompiledInDeferFile_FID_graphics_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLElement_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_graphics_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLElement_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
