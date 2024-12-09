// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CaptureSubsystem/Public/VideoCaptureSubsystem.h"
#include "../../Source/Runtime/Engine/Classes/Engine/GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVideoCaptureSubsystem() {}
// Cross Module References
	CAPTURESUBSYSTEM_API UClass* Z_Construct_UClass_UCaptureSubsystemDirector_NoRegister();
	CAPTURESUBSYSTEM_API UClass* Z_Construct_UClass_UVideoCaptureSubsystem();
	CAPTURESUBSYSTEM_API UClass* Z_Construct_UClass_UVideoCaptureSubsystem_NoRegister();
	CAPTURESUBSYSTEM_API UFunction* Z_Construct_UDelegateFunction_CaptureSubsystem_OnError__DelegateSignature();
	CAPTURESUBSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FVideoCaptureOptions();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
	UPackage* Z_Construct_UPackage__Script_CaptureSubsystem();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_CaptureSubsystem_OnError__DelegateSignature_Statics
	{
		struct _Script_CaptureSubsystem_eventOnError_Parms
		{
			FString ErrorText;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorText;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_CaptureSubsystem_OnError__DelegateSignature_Statics::NewProp_ErrorText = { "ErrorText", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_CaptureSubsystem_eventOnError_Parms, ErrorText), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_CaptureSubsystem_OnError__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_CaptureSubsystem_OnError__DelegateSignature_Statics::NewProp_ErrorText,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_CaptureSubsystem_OnError__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VideoCaptureSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_CaptureSubsystem_OnError__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_CaptureSubsystem, nullptr, "OnError__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_CaptureSubsystem_OnError__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CaptureSubsystem_OnError__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_CaptureSubsystem_OnError__DelegateSignature_Statics::_Script_CaptureSubsystem_eventOnError_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CaptureSubsystem_OnError__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_CaptureSubsystem_OnError__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CaptureSubsystem_OnError__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_CaptureSubsystem_OnError__DelegateSignature_Statics::_Script_CaptureSubsystem_eventOnError_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_CaptureSubsystem_OnError__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_CaptureSubsystem_OnError__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FOnError_DelegateWrapper(const FMulticastScriptDelegate& OnError, const FString& ErrorText)
{
	struct _Script_CaptureSubsystem_eventOnError_Parms
	{
		FString ErrorText;
	};
	_Script_CaptureSubsystem_eventOnError_Parms Parms;
	Parms.ErrorText=ErrorText;
	OnError.ProcessMulticastDelegate<UObject>(&Parms);
}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_VideoCaptureOptions;
class UScriptStruct* FVideoCaptureOptions::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_VideoCaptureOptions.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_VideoCaptureOptions.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FVideoCaptureOptions, (UObject*)Z_Construct_UPackage__Script_CaptureSubsystem(), TEXT("VideoCaptureOptions"));
	}
	return Z_Registration_Info_UScriptStruct_VideoCaptureOptions.OuterSingleton;
}
template<> CAPTURESUBSYSTEM_API UScriptStruct* StaticStruct<FVideoCaptureOptions>()
{
	return FVideoCaptureOptions::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OutFileName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_OutFileName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VideoFilter_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_VideoFilter;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UseGPU_MetaData[];
#endif
		static void NewProp_UseGPU_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_UseGPU;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FPS_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_FPS;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VideoBitRate_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_VideoBitRate;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AudioDelay_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_AudioDelay;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SoundVolume_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_SoundVolume;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ShowUI_MetaData[];
#endif
		static void NewProp_ShowUI_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ShowUI;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OptionalCaptureAspectRatio_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_OptionalCaptureAspectRatio;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "ModuleRelativePath", "Public/VideoCaptureSubsystem.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVideoCaptureOptions>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_OutFileName_MetaData[] = {
		{ "Category", "VideoCaptureOptions" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */// Out file name will be auto generated if empty\n" },
#endif
		{ "ModuleRelativePath", "Public/VideoCaptureSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "// Out file name will be auto generated if empty" },
#endif
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_OutFileName = { "OutFileName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FVideoCaptureOptions, OutFileName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_OutFileName_MetaData), Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_OutFileName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_VideoFilter_MetaData[] = {
		{ "Category", "VideoCaptureOptions" },
		{ "ModuleRelativePath", "Public/VideoCaptureSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_VideoFilter = { "VideoFilter", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FVideoCaptureOptions, VideoFilter), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_VideoFilter_MetaData), Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_VideoFilter_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_UseGPU_MetaData[] = {
		{ "Category", "VideoCaptureOptions" },
		{ "ModuleRelativePath", "Public/VideoCaptureSubsystem.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_UseGPU_SetBit(void* Obj)
	{
		((FVideoCaptureOptions*)Obj)->UseGPU = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_UseGPU = { "UseGPU", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FVideoCaptureOptions), &Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_UseGPU_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_UseGPU_MetaData), Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_UseGPU_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_FPS_MetaData[] = {
		{ "Category", "VideoCaptureOptions" },
		{ "ModuleRelativePath", "Public/VideoCaptureSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_FPS = { "FPS", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FVideoCaptureOptions, FPS), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_FPS_MetaData), Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_FPS_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_VideoBitRate_MetaData[] = {
		{ "Category", "VideoCaptureOptions" },
		{ "ModuleRelativePath", "Public/VideoCaptureSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_VideoBitRate = { "VideoBitRate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FVideoCaptureOptions, VideoBitRate), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_VideoBitRate_MetaData), Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_VideoBitRate_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_AudioDelay_MetaData[] = {
		{ "Category", "VideoCaptureOptions" },
		{ "ModuleRelativePath", "Public/VideoCaptureSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_AudioDelay = { "AudioDelay", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FVideoCaptureOptions, AudioDelay), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_AudioDelay_MetaData), Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_AudioDelay_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_SoundVolume_MetaData[] = {
		{ "Category", "VideoCaptureOptions" },
		{ "ModuleRelativePath", "Public/VideoCaptureSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_SoundVolume = { "SoundVolume", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FVideoCaptureOptions, SoundVolume), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_SoundVolume_MetaData), Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_SoundVolume_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_ShowUI_MetaData[] = {
		{ "Category", "VideoCaptureOptions" },
		{ "ModuleRelativePath", "Public/VideoCaptureSubsystem.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_ShowUI_SetBit(void* Obj)
	{
		((FVideoCaptureOptions*)Obj)->ShowUI = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_ShowUI = { "ShowUI", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FVideoCaptureOptions), &Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_ShowUI_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_ShowUI_MetaData), Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_ShowUI_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_OptionalCaptureAspectRatio_MetaData[] = {
		{ "Category", "VideoCaptureOptions" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Will do (height*x)/y to get aspect ratio (useful horizontal Cropping like instagram square shaped videos). set zero to use default aspect ratio \n" },
#endif
		{ "ModuleRelativePath", "Public/VideoCaptureSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Will do (height*x)/y to get aspect ratio (useful horizontal Cropping like instagram square shaped videos). set zero to use default aspect ratio" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_OptionalCaptureAspectRatio = { "OptionalCaptureAspectRatio", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FVideoCaptureOptions, OptionalCaptureAspectRatio), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_OptionalCaptureAspectRatio_MetaData), Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_OptionalCaptureAspectRatio_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_OutFileName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_VideoFilter,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_UseGPU,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_FPS,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_VideoBitRate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_AudioDelay,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_SoundVolume,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_ShowUI,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewProp_OptionalCaptureAspectRatio,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_CaptureSubsystem,
		nullptr,
		&NewStructOps,
		"VideoCaptureOptions",
		Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::PropPointers),
		sizeof(FVideoCaptureOptions),
		alignof(FVideoCaptureOptions),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FVideoCaptureOptions()
	{
		if (!Z_Registration_Info_UScriptStruct_VideoCaptureOptions.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_VideoCaptureOptions.InnerSingleton, Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_VideoCaptureOptions.InnerSingleton;
	}
	DEFINE_FUNCTION(UVideoCaptureSubsystem::execGetRecommendedPhotoFileName)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=UVideoCaptureSubsystem::GetRecommendedPhotoFileName();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVideoCaptureSubsystem::execGetRecommendedVideoFileName)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=UVideoCaptureSubsystem::GetRecommendedVideoFileName();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVideoCaptureSubsystem::execIsRecording)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsRecording();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVideoCaptureSubsystem::execTakeScreenshot)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_InScreenShotPath);
		P_GET_STRUCT(FVector2D,Z_Param_OptionalAspectRatio);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->TakeScreenshot(Z_Param_InScreenShotPath,Z_Param_OptionalAspectRatio);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVideoCaptureSubsystem::execForceEndCapture)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ForceEndCapture();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVideoCaptureSubsystem::execEndCapture)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->EndCapture();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVideoCaptureSubsystem::execStartCapture)
	{
		P_GET_STRUCT(FVideoCaptureOptions,Z_Param_Options);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StartCapture(Z_Param_Options);
		P_NATIVE_END;
	}
	void UVideoCaptureSubsystem::StaticRegisterNativesUVideoCaptureSubsystem()
	{
		UClass* Class = UVideoCaptureSubsystem::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "EndCapture", &UVideoCaptureSubsystem::execEndCapture },
			{ "ForceEndCapture", &UVideoCaptureSubsystem::execForceEndCapture },
			{ "GetRecommendedPhotoFileName", &UVideoCaptureSubsystem::execGetRecommendedPhotoFileName },
			{ "GetRecommendedVideoFileName", &UVideoCaptureSubsystem::execGetRecommendedVideoFileName },
			{ "IsRecording", &UVideoCaptureSubsystem::execIsRecording },
			{ "StartCapture", &UVideoCaptureSubsystem::execStartCapture },
			{ "TakeScreenshot", &UVideoCaptureSubsystem::execTakeScreenshot },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVideoCaptureSubsystem_EndCapture_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVideoCaptureSubsystem_EndCapture_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VideoCaptureSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVideoCaptureSubsystem_EndCapture_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVideoCaptureSubsystem, nullptr, "EndCapture", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVideoCaptureSubsystem_EndCapture_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVideoCaptureSubsystem_EndCapture_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UVideoCaptureSubsystem_EndCapture()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVideoCaptureSubsystem_EndCapture_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVideoCaptureSubsystem_ForceEndCapture_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVideoCaptureSubsystem_ForceEndCapture_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Force End Capture without waiting for the rest of the frames in threads\n" },
#endif
		{ "ModuleRelativePath", "Public/VideoCaptureSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Force End Capture without waiting for the rest of the frames in threads" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVideoCaptureSubsystem_ForceEndCapture_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVideoCaptureSubsystem, nullptr, "ForceEndCapture", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVideoCaptureSubsystem_ForceEndCapture_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVideoCaptureSubsystem_ForceEndCapture_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UVideoCaptureSubsystem_ForceEndCapture()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVideoCaptureSubsystem_ForceEndCapture_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVideoCaptureSubsystem_GetRecommendedPhotoFileName_Statics
	{
		struct VideoCaptureSubsystem_eventGetRecommendedPhotoFileName_Parms
		{
			FString ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVideoCaptureSubsystem_GetRecommendedPhotoFileName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VideoCaptureSubsystem_eventGetRecommendedPhotoFileName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVideoCaptureSubsystem_GetRecommendedPhotoFileName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVideoCaptureSubsystem_GetRecommendedPhotoFileName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVideoCaptureSubsystem_GetRecommendedPhotoFileName_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VideoCaptureSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVideoCaptureSubsystem_GetRecommendedPhotoFileName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVideoCaptureSubsystem, nullptr, "GetRecommendedPhotoFileName", nullptr, nullptr, Z_Construct_UFunction_UVideoCaptureSubsystem_GetRecommendedPhotoFileName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVideoCaptureSubsystem_GetRecommendedPhotoFileName_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVideoCaptureSubsystem_GetRecommendedPhotoFileName_Statics::VideoCaptureSubsystem_eventGetRecommendedPhotoFileName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVideoCaptureSubsystem_GetRecommendedPhotoFileName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVideoCaptureSubsystem_GetRecommendedPhotoFileName_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVideoCaptureSubsystem_GetRecommendedPhotoFileName_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVideoCaptureSubsystem_GetRecommendedPhotoFileName_Statics::VideoCaptureSubsystem_eventGetRecommendedPhotoFileName_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVideoCaptureSubsystem_GetRecommendedPhotoFileName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVideoCaptureSubsystem_GetRecommendedPhotoFileName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVideoCaptureSubsystem_GetRecommendedVideoFileName_Statics
	{
		struct VideoCaptureSubsystem_eventGetRecommendedVideoFileName_Parms
		{
			FString ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVideoCaptureSubsystem_GetRecommendedVideoFileName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VideoCaptureSubsystem_eventGetRecommendedVideoFileName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVideoCaptureSubsystem_GetRecommendedVideoFileName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVideoCaptureSubsystem_GetRecommendedVideoFileName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVideoCaptureSubsystem_GetRecommendedVideoFileName_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VideoCaptureSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVideoCaptureSubsystem_GetRecommendedVideoFileName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVideoCaptureSubsystem, nullptr, "GetRecommendedVideoFileName", nullptr, nullptr, Z_Construct_UFunction_UVideoCaptureSubsystem_GetRecommendedVideoFileName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVideoCaptureSubsystem_GetRecommendedVideoFileName_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVideoCaptureSubsystem_GetRecommendedVideoFileName_Statics::VideoCaptureSubsystem_eventGetRecommendedVideoFileName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVideoCaptureSubsystem_GetRecommendedVideoFileName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVideoCaptureSubsystem_GetRecommendedVideoFileName_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVideoCaptureSubsystem_GetRecommendedVideoFileName_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVideoCaptureSubsystem_GetRecommendedVideoFileName_Statics::VideoCaptureSubsystem_eventGetRecommendedVideoFileName_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVideoCaptureSubsystem_GetRecommendedVideoFileName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVideoCaptureSubsystem_GetRecommendedVideoFileName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVideoCaptureSubsystem_IsRecording_Statics
	{
		struct VideoCaptureSubsystem_eventIsRecording_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UVideoCaptureSubsystem_IsRecording_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VideoCaptureSubsystem_eventIsRecording_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVideoCaptureSubsystem_IsRecording_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VideoCaptureSubsystem_eventIsRecording_Parms), &Z_Construct_UFunction_UVideoCaptureSubsystem_IsRecording_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVideoCaptureSubsystem_IsRecording_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVideoCaptureSubsystem_IsRecording_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVideoCaptureSubsystem_IsRecording_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VideoCaptureSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVideoCaptureSubsystem_IsRecording_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVideoCaptureSubsystem, nullptr, "IsRecording", nullptr, nullptr, Z_Construct_UFunction_UVideoCaptureSubsystem_IsRecording_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVideoCaptureSubsystem_IsRecording_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVideoCaptureSubsystem_IsRecording_Statics::VideoCaptureSubsystem_eventIsRecording_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVideoCaptureSubsystem_IsRecording_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVideoCaptureSubsystem_IsRecording_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVideoCaptureSubsystem_IsRecording_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVideoCaptureSubsystem_IsRecording_Statics::VideoCaptureSubsystem_eventIsRecording_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVideoCaptureSubsystem_IsRecording()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVideoCaptureSubsystem_IsRecording_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVideoCaptureSubsystem_StartCapture_Statics
	{
		struct VideoCaptureSubsystem_eventStartCapture_Parms
		{
			FVideoCaptureOptions Options;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Options;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVideoCaptureSubsystem_StartCapture_Statics::NewProp_Options = { "Options", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VideoCaptureSubsystem_eventStartCapture_Parms, Options), Z_Construct_UScriptStruct_FVideoCaptureOptions, METADATA_PARAMS(0, nullptr) }; // 936405184
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVideoCaptureSubsystem_StartCapture_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVideoCaptureSubsystem_StartCapture_Statics::NewProp_Options,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVideoCaptureSubsystem_StartCapture_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VideoCaptureSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVideoCaptureSubsystem_StartCapture_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVideoCaptureSubsystem, nullptr, "StartCapture", nullptr, nullptr, Z_Construct_UFunction_UVideoCaptureSubsystem_StartCapture_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVideoCaptureSubsystem_StartCapture_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVideoCaptureSubsystem_StartCapture_Statics::VideoCaptureSubsystem_eventStartCapture_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVideoCaptureSubsystem_StartCapture_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVideoCaptureSubsystem_StartCapture_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVideoCaptureSubsystem_StartCapture_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVideoCaptureSubsystem_StartCapture_Statics::VideoCaptureSubsystem_eventStartCapture_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVideoCaptureSubsystem_StartCapture()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVideoCaptureSubsystem_StartCapture_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVideoCaptureSubsystem_TakeScreenshot_Statics
	{
		struct VideoCaptureSubsystem_eventTakeScreenshot_Parms
		{
			FString InScreenShotPath;
			FVector2D OptionalAspectRatio;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_InScreenShotPath;
		static const UECodeGen_Private::FStructPropertyParams NewProp_OptionalAspectRatio;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVideoCaptureSubsystem_TakeScreenshot_Statics::NewProp_InScreenShotPath = { "InScreenShotPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VideoCaptureSubsystem_eventTakeScreenshot_Parms, InScreenShotPath), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVideoCaptureSubsystem_TakeScreenshot_Statics::NewProp_OptionalAspectRatio = { "OptionalAspectRatio", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VideoCaptureSubsystem_eventTakeScreenshot_Parms, OptionalAspectRatio), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVideoCaptureSubsystem_TakeScreenshot_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVideoCaptureSubsystem_TakeScreenshot_Statics::NewProp_InScreenShotPath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVideoCaptureSubsystem_TakeScreenshot_Statics::NewProp_OptionalAspectRatio,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVideoCaptureSubsystem_TakeScreenshot_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// if path is empty it will be auto generated\n" },
#endif
		{ "ModuleRelativePath", "Public/VideoCaptureSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "if path is empty it will be auto generated" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVideoCaptureSubsystem_TakeScreenshot_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVideoCaptureSubsystem, nullptr, "TakeScreenshot", nullptr, nullptr, Z_Construct_UFunction_UVideoCaptureSubsystem_TakeScreenshot_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVideoCaptureSubsystem_TakeScreenshot_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVideoCaptureSubsystem_TakeScreenshot_Statics::VideoCaptureSubsystem_eventTakeScreenshot_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVideoCaptureSubsystem_TakeScreenshot_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVideoCaptureSubsystem_TakeScreenshot_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVideoCaptureSubsystem_TakeScreenshot_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVideoCaptureSubsystem_TakeScreenshot_Statics::VideoCaptureSubsystem_eventTakeScreenshot_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVideoCaptureSubsystem_TakeScreenshot()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVideoCaptureSubsystem_TakeScreenshot_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVideoCaptureSubsystem);
	UClass* Z_Construct_UClass_UVideoCaptureSubsystem_NoRegister()
	{
		return UVideoCaptureSubsystem::StaticClass();
	}
	struct Z_Construct_UClass_UVideoCaptureSubsystem_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Director_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Director;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnError_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnError;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVideoCaptureSubsystem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_CaptureSubsystem,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVideoCaptureSubsystem_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UVideoCaptureSubsystem_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVideoCaptureSubsystem_EndCapture, "EndCapture" }, // 2634910339
		{ &Z_Construct_UFunction_UVideoCaptureSubsystem_ForceEndCapture, "ForceEndCapture" }, // 2927939204
		{ &Z_Construct_UFunction_UVideoCaptureSubsystem_GetRecommendedPhotoFileName, "GetRecommendedPhotoFileName" }, // 4000484336
		{ &Z_Construct_UFunction_UVideoCaptureSubsystem_GetRecommendedVideoFileName, "GetRecommendedVideoFileName" }, // 1728479679
		{ &Z_Construct_UFunction_UVideoCaptureSubsystem_IsRecording, "IsRecording" }, // 921685369
		{ &Z_Construct_UFunction_UVideoCaptureSubsystem_StartCapture, "StartCapture" }, // 3493025199
		{ &Z_Construct_UFunction_UVideoCaptureSubsystem_TakeScreenshot, "TakeScreenshot" }, // 3062062177
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVideoCaptureSubsystem_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVideoCaptureSubsystem_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "VideoCaptureSubsystem.h" },
		{ "ModuleRelativePath", "Public/VideoCaptureSubsystem.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVideoCaptureSubsystem_Statics::NewProp_Director_MetaData[] = {
		{ "ModuleRelativePath", "Public/VideoCaptureSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVideoCaptureSubsystem_Statics::NewProp_Director = { "Director", nullptr, (EPropertyFlags)0x0010000000002000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVideoCaptureSubsystem, Director), Z_Construct_UClass_UCaptureSubsystemDirector_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVideoCaptureSubsystem_Statics::NewProp_Director_MetaData), Z_Construct_UClass_UVideoCaptureSubsystem_Statics::NewProp_Director_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVideoCaptureSubsystem_Statics::NewProp_OnError_MetaData[] = {
		{ "ModuleRelativePath", "Public/VideoCaptureSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UVideoCaptureSubsystem_Statics::NewProp_OnError = { "OnError", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVideoCaptureSubsystem, OnError), Z_Construct_UDelegateFunction_CaptureSubsystem_OnError__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVideoCaptureSubsystem_Statics::NewProp_OnError_MetaData), Z_Construct_UClass_UVideoCaptureSubsystem_Statics::NewProp_OnError_MetaData) }; // 582685534
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVideoCaptureSubsystem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVideoCaptureSubsystem_Statics::NewProp_Director,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVideoCaptureSubsystem_Statics::NewProp_OnError,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVideoCaptureSubsystem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVideoCaptureSubsystem>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UVideoCaptureSubsystem_Statics::ClassParams = {
		&UVideoCaptureSubsystem::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UVideoCaptureSubsystem_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UVideoCaptureSubsystem_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVideoCaptureSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UVideoCaptureSubsystem_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVideoCaptureSubsystem_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UVideoCaptureSubsystem()
	{
		if (!Z_Registration_Info_UClass_UVideoCaptureSubsystem.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVideoCaptureSubsystem.OuterSingleton, Z_Construct_UClass_UVideoCaptureSubsystem_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UVideoCaptureSubsystem.OuterSingleton;
	}
	template<> CAPTURESUBSYSTEM_API UClass* StaticClass<UVideoCaptureSubsystem>()
	{
		return UVideoCaptureSubsystem::StaticClass();
	}
	UVideoCaptureSubsystem::UVideoCaptureSubsystem() {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVideoCaptureSubsystem);
	UVideoCaptureSubsystem::~UVideoCaptureSubsystem() {}
	struct Z_CompiledInDeferFile_FID_arcgis_Plugins_UE_CaptureSubsystem_Source_CaptureSubsystem_Public_VideoCaptureSubsystem_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_arcgis_Plugins_UE_CaptureSubsystem_Source_CaptureSubsystem_Public_VideoCaptureSubsystem_h_Statics::ScriptStructInfo[] = {
		{ FVideoCaptureOptions::StaticStruct, Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics::NewStructOps, TEXT("VideoCaptureOptions"), &Z_Registration_Info_UScriptStruct_VideoCaptureOptions, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FVideoCaptureOptions), 936405184U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_arcgis_Plugins_UE_CaptureSubsystem_Source_CaptureSubsystem_Public_VideoCaptureSubsystem_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UVideoCaptureSubsystem, UVideoCaptureSubsystem::StaticClass, TEXT("UVideoCaptureSubsystem"), &Z_Registration_Info_UClass_UVideoCaptureSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVideoCaptureSubsystem), 199551530U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_arcgis_Plugins_UE_CaptureSubsystem_Source_CaptureSubsystem_Public_VideoCaptureSubsystem_h_604059437(TEXT("/Script/CaptureSubsystem"),
		Z_CompiledInDeferFile_FID_arcgis_Plugins_UE_CaptureSubsystem_Source_CaptureSubsystem_Public_VideoCaptureSubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_arcgis_Plugins_UE_CaptureSubsystem_Source_CaptureSubsystem_Public_VideoCaptureSubsystem_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_arcgis_Plugins_UE_CaptureSubsystem_Source_CaptureSubsystem_Public_VideoCaptureSubsystem_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_arcgis_Plugins_UE_CaptureSubsystem_Source_CaptureSubsystem_Public_VideoCaptureSubsystem_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
