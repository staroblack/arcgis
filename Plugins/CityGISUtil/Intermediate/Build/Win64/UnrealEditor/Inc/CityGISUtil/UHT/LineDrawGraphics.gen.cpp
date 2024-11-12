// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../../Plugins/CityGISUtil/Source/CityGISUtil/Public/LineDrawGraphics.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLineDrawGraphics() {}
// Cross Module References
	CITYGISUTIL_API UClass* Z_Construct_UClass_ALineDrawManager();
	CITYGISUTIL_API UClass* Z_Construct_UClass_ALineDrawManager_NoRegister();
	CITYGISUTIL_API UClass* Z_Construct_UClass_ULineDrawGraphics();
	CITYGISUTIL_API UClass* Z_Construct_UClass_ULineDrawGraphics_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FColor();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	ENGINE_API UClass* Z_Construct_UClass_ULineBatchComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_CityGISUtil();
// End Cross Module References
	DEFINE_FUNCTION(ULineDrawGraphics::execFlushLineComponent)
	{
		P_GET_SOFTOBJECT(TSoftObjectPtr<ULineBatchComponent>,Z_Param_lines);
		P_FINISH;
		P_NATIVE_BEGIN;
		ULineDrawGraphics::FlushLineComponent(Z_Param_lines);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ULineDrawGraphics::execBPDrawSoildBox)
	{
		P_GET_OBJECT(UObject,Z_Param_context);
		P_GET_STRUCT(FVector,Z_Param_Center);
		P_GET_STRUCT(FVector,Z_Param_Extent);
		P_GET_STRUCT(FLinearColor,Z_Param_Color);
		P_GET_PROPERTY(FByteProperty,Z_Param_DepthPriority);
		P_GET_PROPERTY(FFloatProperty,Z_Param_Duration);
		P_GET_UBOOL(Z_Param_bPersistent);
		P_FINISH;
		P_NATIVE_BEGIN;
		ULineDrawGraphics::BPDrawSoildBox(Z_Param_context,Z_Param_Center,Z_Param_Extent,Z_Param_Color,Z_Param_DepthPriority,Z_Param_Duration,Z_Param_bPersistent);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ULineDrawGraphics::execBPDrawBox)
	{
		P_GET_OBJECT(UObject,Z_Param_context);
		P_GET_STRUCT(FVector,Z_Param_Center);
		P_GET_STRUCT(FVector,Z_Param_Box);
		P_GET_STRUCT(FLinearColor,Z_Param_Color);
		P_GET_PROPERTY(FByteProperty,Z_Param_DepthPriority);
		P_GET_PROPERTY(FFloatProperty,Z_Param_Thickness);
		P_GET_PROPERTY(FFloatProperty,Z_Param_Duration);
		P_GET_UBOOL(Z_Param_bPersistent);
		P_FINISH;
		P_NATIVE_BEGIN;
		ULineDrawGraphics::BPDrawBox(Z_Param_context,Z_Param_Center,Z_Param_Box,Z_Param_Color,Z_Param_DepthPriority,Z_Param_Thickness,Z_Param_Duration,Z_Param_bPersistent);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ULineDrawGraphics::execBPDrawLine)
	{
		P_GET_OBJECT(UObject,Z_Param_context);
		P_GET_STRUCT(FVector,Z_Param_Start);
		P_GET_STRUCT(FVector,Z_Param_End);
		P_GET_STRUCT(FLinearColor,Z_Param_Color);
		P_GET_PROPERTY(FByteProperty,Z_Param_DepthPriority);
		P_GET_PROPERTY(FFloatProperty,Z_Param_Thickness);
		P_GET_PROPERTY(FFloatProperty,Z_Param_Duration);
		P_GET_UBOOL(Z_Param_bPersistent);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TSoftObjectPtr<ULineBatchComponent>*)Z_Param__Result=ULineDrawGraphics::BPDrawLine(Z_Param_context,Z_Param_Start,Z_Param_End,Z_Param_Color,Z_Param_DepthPriority,Z_Param_Thickness,Z_Param_Duration,Z_Param_bPersistent);
		P_NATIVE_END;
	}
	void ULineDrawGraphics::StaticRegisterNativesULineDrawGraphics()
	{
		UClass* Class = ULineDrawGraphics::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BPDrawBox", &ULineDrawGraphics::execBPDrawBox },
			{ "BPDrawLine", &ULineDrawGraphics::execBPDrawLine },
			{ "BPDrawSoildBox", &ULineDrawGraphics::execBPDrawSoildBox },
			{ "FlushLineComponent", &ULineDrawGraphics::execFlushLineComponent },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ULineDrawGraphics_BPDrawBox_Statics
	{
		struct LineDrawGraphics_eventBPDrawBox_Parms
		{
			UObject* context;
			FVector Center;
			FVector Box;
			FLinearColor Color;
			uint8 DepthPriority;
			float Thickness;
			float Duration;
			bool bPersistent;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_context;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Center;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Box;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Color;
		static const UECodeGen_Private::FBytePropertyParams NewProp_DepthPriority;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Thickness;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Duration;
		static void NewProp_bPersistent_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bPersistent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULineDrawGraphics_BPDrawBox_Statics::NewProp_context = { "context", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawGraphics_eventBPDrawBox_Parms, context), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULineDrawGraphics_BPDrawBox_Statics::NewProp_Center = { "Center", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawGraphics_eventBPDrawBox_Parms, Center), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULineDrawGraphics_BPDrawBox_Statics::NewProp_Box = { "Box", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawGraphics_eventBPDrawBox_Parms, Box), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULineDrawGraphics_BPDrawBox_Statics::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawGraphics_eventBPDrawBox_Parms, Color), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ULineDrawGraphics_BPDrawBox_Statics::NewProp_DepthPriority = { "DepthPriority", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawGraphics_eventBPDrawBox_Parms, DepthPriority), nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULineDrawGraphics_BPDrawBox_Statics::NewProp_Thickness = { "Thickness", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawGraphics_eventBPDrawBox_Parms, Thickness), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULineDrawGraphics_BPDrawBox_Statics::NewProp_Duration = { "Duration", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawGraphics_eventBPDrawBox_Parms, Duration), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_ULineDrawGraphics_BPDrawBox_Statics::NewProp_bPersistent_SetBit(void* Obj)
	{
		((LineDrawGraphics_eventBPDrawBox_Parms*)Obj)->bPersistent = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULineDrawGraphics_BPDrawBox_Statics::NewProp_bPersistent = { "bPersistent", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(LineDrawGraphics_eventBPDrawBox_Parms), &Z_Construct_UFunction_ULineDrawGraphics_BPDrawBox_Statics::NewProp_bPersistent_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULineDrawGraphics_BPDrawBox_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULineDrawGraphics_BPDrawBox_Statics::NewProp_context,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULineDrawGraphics_BPDrawBox_Statics::NewProp_Center,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULineDrawGraphics_BPDrawBox_Statics::NewProp_Box,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULineDrawGraphics_BPDrawBox_Statics::NewProp_Color,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULineDrawGraphics_BPDrawBox_Statics::NewProp_DepthPriority,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULineDrawGraphics_BPDrawBox_Statics::NewProp_Thickness,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULineDrawGraphics_BPDrawBox_Statics::NewProp_Duration,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULineDrawGraphics_BPDrawBox_Statics::NewProp_bPersistent,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULineDrawGraphics_BPDrawBox_Statics::Function_MetaDataParams[] = {
		{ "CPP_Default_bPersistent", "false" },
		{ "ModuleRelativePath", "Public/LineDrawGraphics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULineDrawGraphics_BPDrawBox_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULineDrawGraphics, nullptr, "BPDrawBox", nullptr, nullptr, Z_Construct_UFunction_ULineDrawGraphics_BPDrawBox_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULineDrawGraphics_BPDrawBox_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULineDrawGraphics_BPDrawBox_Statics::LineDrawGraphics_eventBPDrawBox_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULineDrawGraphics_BPDrawBox_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULineDrawGraphics_BPDrawBox_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULineDrawGraphics_BPDrawBox_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ULineDrawGraphics_BPDrawBox_Statics::LineDrawGraphics_eventBPDrawBox_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ULineDrawGraphics_BPDrawBox()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULineDrawGraphics_BPDrawBox_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULineDrawGraphics_BPDrawLine_Statics
	{
		struct LineDrawGraphics_eventBPDrawLine_Parms
		{
			UObject* context;
			FVector Start;
			FVector End;
			FLinearColor Color;
			uint8 DepthPriority;
			float Thickness;
			float Duration;
			bool bPersistent;
			TSoftObjectPtr<ULineBatchComponent> ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_context;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Start;
		static const UECodeGen_Private::FStructPropertyParams NewProp_End;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Color;
		static const UECodeGen_Private::FBytePropertyParams NewProp_DepthPriority;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Thickness;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Duration;
		static void NewProp_bPersistent_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bPersistent;
		static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULineDrawGraphics_BPDrawLine_Statics::NewProp_context = { "context", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawGraphics_eventBPDrawLine_Parms, context), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULineDrawGraphics_BPDrawLine_Statics::NewProp_Start = { "Start", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawGraphics_eventBPDrawLine_Parms, Start), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULineDrawGraphics_BPDrawLine_Statics::NewProp_End = { "End", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawGraphics_eventBPDrawLine_Parms, End), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULineDrawGraphics_BPDrawLine_Statics::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawGraphics_eventBPDrawLine_Parms, Color), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ULineDrawGraphics_BPDrawLine_Statics::NewProp_DepthPriority = { "DepthPriority", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawGraphics_eventBPDrawLine_Parms, DepthPriority), nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULineDrawGraphics_BPDrawLine_Statics::NewProp_Thickness = { "Thickness", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawGraphics_eventBPDrawLine_Parms, Thickness), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULineDrawGraphics_BPDrawLine_Statics::NewProp_Duration = { "Duration", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawGraphics_eventBPDrawLine_Parms, Duration), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_ULineDrawGraphics_BPDrawLine_Statics::NewProp_bPersistent_SetBit(void* Obj)
	{
		((LineDrawGraphics_eventBPDrawLine_Parms*)Obj)->bPersistent = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULineDrawGraphics_BPDrawLine_Statics::NewProp_bPersistent = { "bPersistent", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(LineDrawGraphics_eventBPDrawLine_Parms), &Z_Construct_UFunction_ULineDrawGraphics_BPDrawLine_Statics::NewProp_bPersistent_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UFunction_ULineDrawGraphics_BPDrawLine_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0014000000080588, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawGraphics_eventBPDrawLine_Parms, ReturnValue), Z_Construct_UClass_ULineBatchComponent_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULineDrawGraphics_BPDrawLine_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULineDrawGraphics_BPDrawLine_Statics::NewProp_context,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULineDrawGraphics_BPDrawLine_Statics::NewProp_Start,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULineDrawGraphics_BPDrawLine_Statics::NewProp_End,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULineDrawGraphics_BPDrawLine_Statics::NewProp_Color,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULineDrawGraphics_BPDrawLine_Statics::NewProp_DepthPriority,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULineDrawGraphics_BPDrawLine_Statics::NewProp_Thickness,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULineDrawGraphics_BPDrawLine_Statics::NewProp_Duration,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULineDrawGraphics_BPDrawLine_Statics::NewProp_bPersistent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULineDrawGraphics_BPDrawLine_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULineDrawGraphics_BPDrawLine_Statics::Function_MetaDataParams[] = {
		{ "CPP_Default_bPersistent", "false" },
		{ "ModuleRelativePath", "Public/LineDrawGraphics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULineDrawGraphics_BPDrawLine_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULineDrawGraphics, nullptr, "BPDrawLine", nullptr, nullptr, Z_Construct_UFunction_ULineDrawGraphics_BPDrawLine_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULineDrawGraphics_BPDrawLine_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULineDrawGraphics_BPDrawLine_Statics::LineDrawGraphics_eventBPDrawLine_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULineDrawGraphics_BPDrawLine_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULineDrawGraphics_BPDrawLine_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULineDrawGraphics_BPDrawLine_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ULineDrawGraphics_BPDrawLine_Statics::LineDrawGraphics_eventBPDrawLine_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ULineDrawGraphics_BPDrawLine()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULineDrawGraphics_BPDrawLine_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULineDrawGraphics_BPDrawSoildBox_Statics
	{
		struct LineDrawGraphics_eventBPDrawSoildBox_Parms
		{
			UObject* context;
			FVector Center;
			FVector Extent;
			FLinearColor Color;
			uint8 DepthPriority;
			float Duration;
			bool bPersistent;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_context;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Center;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Extent;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Color;
		static const UECodeGen_Private::FBytePropertyParams NewProp_DepthPriority;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Duration;
		static void NewProp_bPersistent_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bPersistent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULineDrawGraphics_BPDrawSoildBox_Statics::NewProp_context = { "context", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawGraphics_eventBPDrawSoildBox_Parms, context), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULineDrawGraphics_BPDrawSoildBox_Statics::NewProp_Center = { "Center", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawGraphics_eventBPDrawSoildBox_Parms, Center), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULineDrawGraphics_BPDrawSoildBox_Statics::NewProp_Extent = { "Extent", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawGraphics_eventBPDrawSoildBox_Parms, Extent), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULineDrawGraphics_BPDrawSoildBox_Statics::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawGraphics_eventBPDrawSoildBox_Parms, Color), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ULineDrawGraphics_BPDrawSoildBox_Statics::NewProp_DepthPriority = { "DepthPriority", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawGraphics_eventBPDrawSoildBox_Parms, DepthPriority), nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULineDrawGraphics_BPDrawSoildBox_Statics::NewProp_Duration = { "Duration", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawGraphics_eventBPDrawSoildBox_Parms, Duration), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_ULineDrawGraphics_BPDrawSoildBox_Statics::NewProp_bPersistent_SetBit(void* Obj)
	{
		((LineDrawGraphics_eventBPDrawSoildBox_Parms*)Obj)->bPersistent = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULineDrawGraphics_BPDrawSoildBox_Statics::NewProp_bPersistent = { "bPersistent", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(LineDrawGraphics_eventBPDrawSoildBox_Parms), &Z_Construct_UFunction_ULineDrawGraphics_BPDrawSoildBox_Statics::NewProp_bPersistent_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULineDrawGraphics_BPDrawSoildBox_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULineDrawGraphics_BPDrawSoildBox_Statics::NewProp_context,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULineDrawGraphics_BPDrawSoildBox_Statics::NewProp_Center,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULineDrawGraphics_BPDrawSoildBox_Statics::NewProp_Extent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULineDrawGraphics_BPDrawSoildBox_Statics::NewProp_Color,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULineDrawGraphics_BPDrawSoildBox_Statics::NewProp_DepthPriority,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULineDrawGraphics_BPDrawSoildBox_Statics::NewProp_Duration,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULineDrawGraphics_BPDrawSoildBox_Statics::NewProp_bPersistent,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULineDrawGraphics_BPDrawSoildBox_Statics::Function_MetaDataParams[] = {
		{ "context", "WorldContextObject" },
		{ "CPP_Default_bPersistent", "false" },
		{ "ModuleRelativePath", "Public/LineDrawGraphics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULineDrawGraphics_BPDrawSoildBox_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULineDrawGraphics, nullptr, "BPDrawSoildBox", nullptr, nullptr, Z_Construct_UFunction_ULineDrawGraphics_BPDrawSoildBox_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULineDrawGraphics_BPDrawSoildBox_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULineDrawGraphics_BPDrawSoildBox_Statics::LineDrawGraphics_eventBPDrawSoildBox_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULineDrawGraphics_BPDrawSoildBox_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULineDrawGraphics_BPDrawSoildBox_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULineDrawGraphics_BPDrawSoildBox_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ULineDrawGraphics_BPDrawSoildBox_Statics::LineDrawGraphics_eventBPDrawSoildBox_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ULineDrawGraphics_BPDrawSoildBox()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULineDrawGraphics_BPDrawSoildBox_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULineDrawGraphics_FlushLineComponent_Statics
	{
		struct LineDrawGraphics_eventFlushLineComponent_Parms
		{
			TSoftObjectPtr<ULineBatchComponent> lines;
		};
		static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_lines;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UFunction_ULineDrawGraphics_FlushLineComponent_Statics::NewProp_lines = { "lines", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawGraphics_eventFlushLineComponent_Parms, lines), Z_Construct_UClass_ULineBatchComponent_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULineDrawGraphics_FlushLineComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULineDrawGraphics_FlushLineComponent_Statics::NewProp_lines,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULineDrawGraphics_FlushLineComponent_Statics::Function_MetaDataParams[] = {
		{ "context", "WorldContextObject" },
		{ "ModuleRelativePath", "Public/LineDrawGraphics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULineDrawGraphics_FlushLineComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULineDrawGraphics, nullptr, "FlushLineComponent", nullptr, nullptr, Z_Construct_UFunction_ULineDrawGraphics_FlushLineComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULineDrawGraphics_FlushLineComponent_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULineDrawGraphics_FlushLineComponent_Statics::LineDrawGraphics_eventFlushLineComponent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULineDrawGraphics_FlushLineComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULineDrawGraphics_FlushLineComponent_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULineDrawGraphics_FlushLineComponent_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ULineDrawGraphics_FlushLineComponent_Statics::LineDrawGraphics_eventFlushLineComponent_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ULineDrawGraphics_FlushLineComponent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULineDrawGraphics_FlushLineComponent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ULineDrawGraphics);
	UClass* Z_Construct_UClass_ULineDrawGraphics_NoRegister()
	{
		return ULineDrawGraphics::StaticClass();
	}
	struct Z_Construct_UClass_ULineDrawGraphics_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ULineDrawGraphics_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_CityGISUtil,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULineDrawGraphics_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_ULineDrawGraphics_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ULineDrawGraphics_BPDrawBox, "BPDrawBox" }, // 3846302349
		{ &Z_Construct_UFunction_ULineDrawGraphics_BPDrawLine, "BPDrawLine" }, // 3679356724
		{ &Z_Construct_UFunction_ULineDrawGraphics_BPDrawSoildBox, "BPDrawSoildBox" }, // 984149877
		{ &Z_Construct_UFunction_ULineDrawGraphics_FlushLineComponent, "FlushLineComponent" }, // 3141680937
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULineDrawGraphics_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULineDrawGraphics_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "LineDrawGraphics.h" },
		{ "ModuleRelativePath", "Public/LineDrawGraphics.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ULineDrawGraphics_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULineDrawGraphics>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ULineDrawGraphics_Statics::ClassParams = {
		&ULineDrawGraphics::StaticClass,
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
		0x000000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULineDrawGraphics_Statics::Class_MetaDataParams), Z_Construct_UClass_ULineDrawGraphics_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_ULineDrawGraphics()
	{
		if (!Z_Registration_Info_UClass_ULineDrawGraphics.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULineDrawGraphics.OuterSingleton, Z_Construct_UClass_ULineDrawGraphics_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ULineDrawGraphics.OuterSingleton;
	}
	template<> CITYGISUTIL_API UClass* StaticClass<ULineDrawGraphics>()
	{
		return ULineDrawGraphics::StaticClass();
	}
	ULineDrawGraphics::ULineDrawGraphics(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ULineDrawGraphics);
	ULineDrawGraphics::~ULineDrawGraphics() {}
	DEFINE_FUNCTION(ALineDrawManager::execPopDrawArea)
	{
		P_GET_OBJECT(UObject,Z_Param_context);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->PopDrawArea(Z_Param_context);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ALineDrawManager::execRemoveDrawArea)
	{
		P_GET_OBJECT(UObject,Z_Param_context);
		P_GET_PROPERTY(FIntProperty,Z_Param_index);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->RemoveDrawArea(Z_Param_context,Z_Param_index);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ALineDrawManager::execGenerateArea)
	{
		P_GET_OBJECT(UObject,Z_Param_context);
		P_GET_STRUCT(FColor,Z_Param_color);
		P_GET_PROPERTY(FByteProperty,Z_Param_DepthPriority);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GenerateArea(Z_Param_context,Z_Param_color,Z_Param_DepthPriority);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ALineDrawManager::execStartMeasureArea)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StartMeasureArea();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ALineDrawManager::execPopDrawLine)
	{
		P_GET_OBJECT(UObject,Z_Param_context);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->PopDrawLine(Z_Param_context);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ALineDrawManager::execRemoveDrawLine)
	{
		P_GET_OBJECT(UObject,Z_Param_context);
		P_GET_PROPERTY(FIntProperty,Z_Param_index);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->RemoveDrawLine(Z_Param_context,Z_Param_index);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ALineDrawManager::execAddDrawLine)
	{
		P_GET_OBJECT(UObject,Z_Param_context);
		P_GET_STRUCT(FVector,Z_Param_Start);
		P_GET_STRUCT(FVector,Z_Param_End);
		P_GET_STRUCT(FLinearColor,Z_Param_Color);
		P_GET_PROPERTY(FByteProperty,Z_Param_DepthPriority);
		P_GET_PROPERTY(FFloatProperty,Z_Param_Thickness);
		P_GET_PROPERTY(FFloatProperty,Z_Param_Duration);
		P_GET_UBOOL(Z_Param_bPersistent);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TSoftObjectPtr<ULineBatchComponent>*)Z_Param__Result=P_THIS->AddDrawLine(Z_Param_context,Z_Param_Start,Z_Param_End,Z_Param_Color,Z_Param_DepthPriority,Z_Param_Thickness,Z_Param_Duration,Z_Param_bPersistent);
		P_NATIVE_END;
	}
	void ALineDrawManager::StaticRegisterNativesALineDrawManager()
	{
		UClass* Class = ALineDrawManager::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddDrawLine", &ALineDrawManager::execAddDrawLine },
			{ "GenerateArea", &ALineDrawManager::execGenerateArea },
			{ "PopDrawArea", &ALineDrawManager::execPopDrawArea },
			{ "PopDrawLine", &ALineDrawManager::execPopDrawLine },
			{ "RemoveDrawArea", &ALineDrawManager::execRemoveDrawArea },
			{ "RemoveDrawLine", &ALineDrawManager::execRemoveDrawLine },
			{ "StartMeasureArea", &ALineDrawManager::execStartMeasureArea },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ALineDrawManager_AddDrawLine_Statics
	{
		struct LineDrawManager_eventAddDrawLine_Parms
		{
			UObject* context;
			FVector Start;
			FVector End;
			FLinearColor Color;
			uint8 DepthPriority;
			float Thickness;
			float Duration;
			bool bPersistent;
			TSoftObjectPtr<ULineBatchComponent> ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_context;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Start;
		static const UECodeGen_Private::FStructPropertyParams NewProp_End;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Color;
		static const UECodeGen_Private::FBytePropertyParams NewProp_DepthPriority;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Thickness;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Duration;
		static void NewProp_bPersistent_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bPersistent;
		static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ALineDrawManager_AddDrawLine_Statics::NewProp_context = { "context", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawManager_eventAddDrawLine_Parms, context), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ALineDrawManager_AddDrawLine_Statics::NewProp_Start = { "Start", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawManager_eventAddDrawLine_Parms, Start), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ALineDrawManager_AddDrawLine_Statics::NewProp_End = { "End", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawManager_eventAddDrawLine_Parms, End), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ALineDrawManager_AddDrawLine_Statics::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawManager_eventAddDrawLine_Parms, Color), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ALineDrawManager_AddDrawLine_Statics::NewProp_DepthPriority = { "DepthPriority", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawManager_eventAddDrawLine_Parms, DepthPriority), nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ALineDrawManager_AddDrawLine_Statics::NewProp_Thickness = { "Thickness", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawManager_eventAddDrawLine_Parms, Thickness), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ALineDrawManager_AddDrawLine_Statics::NewProp_Duration = { "Duration", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawManager_eventAddDrawLine_Parms, Duration), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_ALineDrawManager_AddDrawLine_Statics::NewProp_bPersistent_SetBit(void* Obj)
	{
		((LineDrawManager_eventAddDrawLine_Parms*)Obj)->bPersistent = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ALineDrawManager_AddDrawLine_Statics::NewProp_bPersistent = { "bPersistent", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(LineDrawManager_eventAddDrawLine_Parms), &Z_Construct_UFunction_ALineDrawManager_AddDrawLine_Statics::NewProp_bPersistent_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UFunction_ALineDrawManager_AddDrawLine_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0014000000080588, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawManager_eventAddDrawLine_Parms, ReturnValue), Z_Construct_UClass_ULineBatchComponent_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ALineDrawManager_AddDrawLine_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALineDrawManager_AddDrawLine_Statics::NewProp_context,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALineDrawManager_AddDrawLine_Statics::NewProp_Start,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALineDrawManager_AddDrawLine_Statics::NewProp_End,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALineDrawManager_AddDrawLine_Statics::NewProp_Color,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALineDrawManager_AddDrawLine_Statics::NewProp_DepthPriority,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALineDrawManager_AddDrawLine_Statics::NewProp_Thickness,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALineDrawManager_AddDrawLine_Statics::NewProp_Duration,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALineDrawManager_AddDrawLine_Statics::NewProp_bPersistent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALineDrawManager_AddDrawLine_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ALineDrawManager_AddDrawLine_Statics::Function_MetaDataParams[] = {
		{ "Category", "LineManager" },
		{ "CPP_Default_bPersistent", "true" },
		{ "ModuleRelativePath", "Public/LineDrawGraphics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ALineDrawManager_AddDrawLine_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ALineDrawManager, nullptr, "AddDrawLine", nullptr, nullptr, Z_Construct_UFunction_ALineDrawManager_AddDrawLine_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ALineDrawManager_AddDrawLine_Statics::PropPointers), sizeof(Z_Construct_UFunction_ALineDrawManager_AddDrawLine_Statics::LineDrawManager_eventAddDrawLine_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ALineDrawManager_AddDrawLine_Statics::Function_MetaDataParams), Z_Construct_UFunction_ALineDrawManager_AddDrawLine_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ALineDrawManager_AddDrawLine_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ALineDrawManager_AddDrawLine_Statics::LineDrawManager_eventAddDrawLine_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ALineDrawManager_AddDrawLine()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ALineDrawManager_AddDrawLine_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ALineDrawManager_GenerateArea_Statics
	{
		struct LineDrawManager_eventGenerateArea_Parms
		{
			UObject* context;
			FColor color;
			uint8 DepthPriority;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_context;
		static const UECodeGen_Private::FStructPropertyParams NewProp_color;
		static const UECodeGen_Private::FBytePropertyParams NewProp_DepthPriority;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ALineDrawManager_GenerateArea_Statics::NewProp_context = { "context", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawManager_eventGenerateArea_Parms, context), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ALineDrawManager_GenerateArea_Statics::NewProp_color = { "color", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawManager_eventGenerateArea_Parms, color), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ALineDrawManager_GenerateArea_Statics::NewProp_DepthPriority = { "DepthPriority", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawManager_eventGenerateArea_Parms, DepthPriority), nullptr, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_ALineDrawManager_GenerateArea_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((LineDrawManager_eventGenerateArea_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ALineDrawManager_GenerateArea_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(LineDrawManager_eventGenerateArea_Parms), &Z_Construct_UFunction_ALineDrawManager_GenerateArea_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ALineDrawManager_GenerateArea_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALineDrawManager_GenerateArea_Statics::NewProp_context,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALineDrawManager_GenerateArea_Statics::NewProp_color,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALineDrawManager_GenerateArea_Statics::NewProp_DepthPriority,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALineDrawManager_GenerateArea_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ALineDrawManager_GenerateArea_Statics::Function_MetaDataParams[] = {
		{ "Category", "LineManager" },
		{ "ModuleRelativePath", "Public/LineDrawGraphics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ALineDrawManager_GenerateArea_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ALineDrawManager, nullptr, "GenerateArea", nullptr, nullptr, Z_Construct_UFunction_ALineDrawManager_GenerateArea_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ALineDrawManager_GenerateArea_Statics::PropPointers), sizeof(Z_Construct_UFunction_ALineDrawManager_GenerateArea_Statics::LineDrawManager_eventGenerateArea_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ALineDrawManager_GenerateArea_Statics::Function_MetaDataParams), Z_Construct_UFunction_ALineDrawManager_GenerateArea_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ALineDrawManager_GenerateArea_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ALineDrawManager_GenerateArea_Statics::LineDrawManager_eventGenerateArea_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ALineDrawManager_GenerateArea()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ALineDrawManager_GenerateArea_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ALineDrawManager_PopDrawArea_Statics
	{
		struct LineDrawManager_eventPopDrawArea_Parms
		{
			UObject* context;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_context;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ALineDrawManager_PopDrawArea_Statics::NewProp_context = { "context", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawManager_eventPopDrawArea_Parms, context), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_ALineDrawManager_PopDrawArea_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((LineDrawManager_eventPopDrawArea_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ALineDrawManager_PopDrawArea_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(LineDrawManager_eventPopDrawArea_Parms), &Z_Construct_UFunction_ALineDrawManager_PopDrawArea_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ALineDrawManager_PopDrawArea_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALineDrawManager_PopDrawArea_Statics::NewProp_context,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALineDrawManager_PopDrawArea_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ALineDrawManager_PopDrawArea_Statics::Function_MetaDataParams[] = {
		{ "Category", "LineManager" },
		{ "ModuleRelativePath", "Public/LineDrawGraphics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ALineDrawManager_PopDrawArea_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ALineDrawManager, nullptr, "PopDrawArea", nullptr, nullptr, Z_Construct_UFunction_ALineDrawManager_PopDrawArea_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ALineDrawManager_PopDrawArea_Statics::PropPointers), sizeof(Z_Construct_UFunction_ALineDrawManager_PopDrawArea_Statics::LineDrawManager_eventPopDrawArea_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ALineDrawManager_PopDrawArea_Statics::Function_MetaDataParams), Z_Construct_UFunction_ALineDrawManager_PopDrawArea_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ALineDrawManager_PopDrawArea_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ALineDrawManager_PopDrawArea_Statics::LineDrawManager_eventPopDrawArea_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ALineDrawManager_PopDrawArea()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ALineDrawManager_PopDrawArea_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ALineDrawManager_PopDrawLine_Statics
	{
		struct LineDrawManager_eventPopDrawLine_Parms
		{
			UObject* context;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_context;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ALineDrawManager_PopDrawLine_Statics::NewProp_context = { "context", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawManager_eventPopDrawLine_Parms, context), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_ALineDrawManager_PopDrawLine_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((LineDrawManager_eventPopDrawLine_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ALineDrawManager_PopDrawLine_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(LineDrawManager_eventPopDrawLine_Parms), &Z_Construct_UFunction_ALineDrawManager_PopDrawLine_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ALineDrawManager_PopDrawLine_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALineDrawManager_PopDrawLine_Statics::NewProp_context,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALineDrawManager_PopDrawLine_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ALineDrawManager_PopDrawLine_Statics::Function_MetaDataParams[] = {
		{ "Category", "LineManager" },
		{ "ModuleRelativePath", "Public/LineDrawGraphics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ALineDrawManager_PopDrawLine_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ALineDrawManager, nullptr, "PopDrawLine", nullptr, nullptr, Z_Construct_UFunction_ALineDrawManager_PopDrawLine_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ALineDrawManager_PopDrawLine_Statics::PropPointers), sizeof(Z_Construct_UFunction_ALineDrawManager_PopDrawLine_Statics::LineDrawManager_eventPopDrawLine_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ALineDrawManager_PopDrawLine_Statics::Function_MetaDataParams), Z_Construct_UFunction_ALineDrawManager_PopDrawLine_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ALineDrawManager_PopDrawLine_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ALineDrawManager_PopDrawLine_Statics::LineDrawManager_eventPopDrawLine_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ALineDrawManager_PopDrawLine()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ALineDrawManager_PopDrawLine_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ALineDrawManager_RemoveDrawArea_Statics
	{
		struct LineDrawManager_eventRemoveDrawArea_Parms
		{
			UObject* context;
			int32 index;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_context;
		static const UECodeGen_Private::FIntPropertyParams NewProp_index;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ALineDrawManager_RemoveDrawArea_Statics::NewProp_context = { "context", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawManager_eventRemoveDrawArea_Parms, context), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ALineDrawManager_RemoveDrawArea_Statics::NewProp_index = { "index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawManager_eventRemoveDrawArea_Parms, index), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_ALineDrawManager_RemoveDrawArea_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((LineDrawManager_eventRemoveDrawArea_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ALineDrawManager_RemoveDrawArea_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(LineDrawManager_eventRemoveDrawArea_Parms), &Z_Construct_UFunction_ALineDrawManager_RemoveDrawArea_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ALineDrawManager_RemoveDrawArea_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALineDrawManager_RemoveDrawArea_Statics::NewProp_context,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALineDrawManager_RemoveDrawArea_Statics::NewProp_index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALineDrawManager_RemoveDrawArea_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ALineDrawManager_RemoveDrawArea_Statics::Function_MetaDataParams[] = {
		{ "Category", "LineManager" },
		{ "ModuleRelativePath", "Public/LineDrawGraphics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ALineDrawManager_RemoveDrawArea_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ALineDrawManager, nullptr, "RemoveDrawArea", nullptr, nullptr, Z_Construct_UFunction_ALineDrawManager_RemoveDrawArea_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ALineDrawManager_RemoveDrawArea_Statics::PropPointers), sizeof(Z_Construct_UFunction_ALineDrawManager_RemoveDrawArea_Statics::LineDrawManager_eventRemoveDrawArea_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ALineDrawManager_RemoveDrawArea_Statics::Function_MetaDataParams), Z_Construct_UFunction_ALineDrawManager_RemoveDrawArea_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ALineDrawManager_RemoveDrawArea_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ALineDrawManager_RemoveDrawArea_Statics::LineDrawManager_eventRemoveDrawArea_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ALineDrawManager_RemoveDrawArea()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ALineDrawManager_RemoveDrawArea_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ALineDrawManager_RemoveDrawLine_Statics
	{
		struct LineDrawManager_eventRemoveDrawLine_Parms
		{
			UObject* context;
			int32 index;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_context;
		static const UECodeGen_Private::FIntPropertyParams NewProp_index;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ALineDrawManager_RemoveDrawLine_Statics::NewProp_context = { "context", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawManager_eventRemoveDrawLine_Parms, context), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ALineDrawManager_RemoveDrawLine_Statics::NewProp_index = { "index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LineDrawManager_eventRemoveDrawLine_Parms, index), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_ALineDrawManager_RemoveDrawLine_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((LineDrawManager_eventRemoveDrawLine_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ALineDrawManager_RemoveDrawLine_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(LineDrawManager_eventRemoveDrawLine_Parms), &Z_Construct_UFunction_ALineDrawManager_RemoveDrawLine_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ALineDrawManager_RemoveDrawLine_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALineDrawManager_RemoveDrawLine_Statics::NewProp_context,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALineDrawManager_RemoveDrawLine_Statics::NewProp_index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALineDrawManager_RemoveDrawLine_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ALineDrawManager_RemoveDrawLine_Statics::Function_MetaDataParams[] = {
		{ "Category", "LineManager" },
		{ "ModuleRelativePath", "Public/LineDrawGraphics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ALineDrawManager_RemoveDrawLine_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ALineDrawManager, nullptr, "RemoveDrawLine", nullptr, nullptr, Z_Construct_UFunction_ALineDrawManager_RemoveDrawLine_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ALineDrawManager_RemoveDrawLine_Statics::PropPointers), sizeof(Z_Construct_UFunction_ALineDrawManager_RemoveDrawLine_Statics::LineDrawManager_eventRemoveDrawLine_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ALineDrawManager_RemoveDrawLine_Statics::Function_MetaDataParams), Z_Construct_UFunction_ALineDrawManager_RemoveDrawLine_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ALineDrawManager_RemoveDrawLine_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ALineDrawManager_RemoveDrawLine_Statics::LineDrawManager_eventRemoveDrawLine_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ALineDrawManager_RemoveDrawLine()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ALineDrawManager_RemoveDrawLine_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ALineDrawManager_StartMeasureArea_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ALineDrawManager_StartMeasureArea_Statics::Function_MetaDataParams[] = {
		{ "Category", "LineManager" },
		{ "ModuleRelativePath", "Public/LineDrawGraphics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ALineDrawManager_StartMeasureArea_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ALineDrawManager, nullptr, "StartMeasureArea", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ALineDrawManager_StartMeasureArea_Statics::Function_MetaDataParams), Z_Construct_UFunction_ALineDrawManager_StartMeasureArea_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ALineDrawManager_StartMeasureArea()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ALineDrawManager_StartMeasureArea_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ALineDrawManager);
	UClass* Z_Construct_UClass_ALineDrawManager_NoRegister()
	{
		return ALineDrawManager::StaticClass();
	}
	struct Z_Construct_UClass_ALineDrawManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ALineDrawManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_CityGISUtil,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ALineDrawManager_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_ALineDrawManager_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ALineDrawManager_AddDrawLine, "AddDrawLine" }, // 1392542024
		{ &Z_Construct_UFunction_ALineDrawManager_GenerateArea, "GenerateArea" }, // 4235067837
		{ &Z_Construct_UFunction_ALineDrawManager_PopDrawArea, "PopDrawArea" }, // 2850318351
		{ &Z_Construct_UFunction_ALineDrawManager_PopDrawLine, "PopDrawLine" }, // 184001579
		{ &Z_Construct_UFunction_ALineDrawManager_RemoveDrawArea, "RemoveDrawArea" }, // 4219380659
		{ &Z_Construct_UFunction_ALineDrawManager_RemoveDrawLine, "RemoveDrawLine" }, // 2996838989
		{ &Z_Construct_UFunction_ALineDrawManager_StartMeasureArea, "StartMeasureArea" }, // 2688720485
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ALineDrawManager_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALineDrawManager_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "LineDrawGraphics.h" },
		{ "ModuleRelativePath", "Public/LineDrawGraphics.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ALineDrawManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALineDrawManager>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ALineDrawManager_Statics::ClassParams = {
		&ALineDrawManager::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x008000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ALineDrawManager_Statics::Class_MetaDataParams), Z_Construct_UClass_ALineDrawManager_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_ALineDrawManager()
	{
		if (!Z_Registration_Info_UClass_ALineDrawManager.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ALineDrawManager.OuterSingleton, Z_Construct_UClass_ALineDrawManager_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ALineDrawManager.OuterSingleton;
	}
	template<> CITYGISUTIL_API UClass* StaticClass<ALineDrawManager>()
	{
		return ALineDrawManager::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ALineDrawManager);
	ALineDrawManager::~ALineDrawManager() {}
	struct Z_CompiledInDeferFile_FID_arcgis_Plugins_CityGISUtil_Source_CityGISUtil_Public_LineDrawGraphics_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_arcgis_Plugins_CityGISUtil_Source_CityGISUtil_Public_LineDrawGraphics_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ULineDrawGraphics, ULineDrawGraphics::StaticClass, TEXT("ULineDrawGraphics"), &Z_Registration_Info_UClass_ULineDrawGraphics, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULineDrawGraphics), 1602531571U) },
		{ Z_Construct_UClass_ALineDrawManager, ALineDrawManager::StaticClass, TEXT("ALineDrawManager"), &Z_Registration_Info_UClass_ALineDrawManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ALineDrawManager), 4116944727U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_arcgis_Plugins_CityGISUtil_Source_CityGISUtil_Public_LineDrawGraphics_h_3757112596(TEXT("/Script/CityGISUtil"),
		Z_CompiledInDeferFile_FID_arcgis_Plugins_CityGISUtil_Source_CityGISUtil_Public_LineDrawGraphics_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_arcgis_Plugins_CityGISUtil_Source_CityGISUtil_Public_LineDrawGraphics_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
