// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "VideoCaptureSubsystem.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FVideoCaptureOptions;
#ifdef CAPTURESUBSYSTEM_VideoCaptureSubsystem_generated_h
#error "VideoCaptureSubsystem.generated.h already included, missing '#pragma once' in VideoCaptureSubsystem.h"
#endif
#define CAPTURESUBSYSTEM_VideoCaptureSubsystem_generated_h

#define FID_arcgis_Plugins_UE_CaptureSubsystem_Source_CaptureSubsystem_Public_VideoCaptureSubsystem_h_8_DELEGATE \
CAPTURESUBSYSTEM_API void FOnError_DelegateWrapper(const FMulticastScriptDelegate& OnError, const FString& ErrorText);


#define FID_arcgis_Plugins_UE_CaptureSubsystem_Source_CaptureSubsystem_Public_VideoCaptureSubsystem_h_36_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FVideoCaptureOptions_Statics; \
	CAPTURESUBSYSTEM_API static class UScriptStruct* StaticStruct();


template<> CAPTURESUBSYSTEM_API UScriptStruct* StaticStruct<struct FVideoCaptureOptions>();

#define FID_arcgis_Plugins_UE_CaptureSubsystem_Source_CaptureSubsystem_Public_VideoCaptureSubsystem_h_42_SPARSE_DATA
#define FID_arcgis_Plugins_UE_CaptureSubsystem_Source_CaptureSubsystem_Public_VideoCaptureSubsystem_h_42_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_arcgis_Plugins_UE_CaptureSubsystem_Source_CaptureSubsystem_Public_VideoCaptureSubsystem_h_42_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_arcgis_Plugins_UE_CaptureSubsystem_Source_CaptureSubsystem_Public_VideoCaptureSubsystem_h_42_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetRecommendedPhotoFileName); \
	DECLARE_FUNCTION(execGetRecommendedVideoFileName); \
	DECLARE_FUNCTION(execIsRecording); \
	DECLARE_FUNCTION(execTakeScreenshot); \
	DECLARE_FUNCTION(execForceEndCapture); \
	DECLARE_FUNCTION(execEndCapture); \
	DECLARE_FUNCTION(execStartCapture);


#define FID_arcgis_Plugins_UE_CaptureSubsystem_Source_CaptureSubsystem_Public_VideoCaptureSubsystem_h_42_ACCESSORS
#define FID_arcgis_Plugins_UE_CaptureSubsystem_Source_CaptureSubsystem_Public_VideoCaptureSubsystem_h_42_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVideoCaptureSubsystem(); \
	friend struct Z_Construct_UClass_UVideoCaptureSubsystem_Statics; \
public: \
	DECLARE_CLASS(UVideoCaptureSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CaptureSubsystem"), NO_API) \
	DECLARE_SERIALIZER(UVideoCaptureSubsystem)


#define FID_arcgis_Plugins_UE_CaptureSubsystem_Source_CaptureSubsystem_Public_VideoCaptureSubsystem_h_42_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVideoCaptureSubsystem(); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVideoCaptureSubsystem(UVideoCaptureSubsystem&&); \
	NO_API UVideoCaptureSubsystem(const UVideoCaptureSubsystem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVideoCaptureSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVideoCaptureSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UVideoCaptureSubsystem) \
	NO_API virtual ~UVideoCaptureSubsystem();


#define FID_arcgis_Plugins_UE_CaptureSubsystem_Source_CaptureSubsystem_Public_VideoCaptureSubsystem_h_39_PROLOG
#define FID_arcgis_Plugins_UE_CaptureSubsystem_Source_CaptureSubsystem_Public_VideoCaptureSubsystem_h_42_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_arcgis_Plugins_UE_CaptureSubsystem_Source_CaptureSubsystem_Public_VideoCaptureSubsystem_h_42_SPARSE_DATA \
	FID_arcgis_Plugins_UE_CaptureSubsystem_Source_CaptureSubsystem_Public_VideoCaptureSubsystem_h_42_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_arcgis_Plugins_UE_CaptureSubsystem_Source_CaptureSubsystem_Public_VideoCaptureSubsystem_h_42_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_arcgis_Plugins_UE_CaptureSubsystem_Source_CaptureSubsystem_Public_VideoCaptureSubsystem_h_42_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_arcgis_Plugins_UE_CaptureSubsystem_Source_CaptureSubsystem_Public_VideoCaptureSubsystem_h_42_ACCESSORS \
	FID_arcgis_Plugins_UE_CaptureSubsystem_Source_CaptureSubsystem_Public_VideoCaptureSubsystem_h_42_INCLASS_NO_PURE_DECLS \
	FID_arcgis_Plugins_UE_CaptureSubsystem_Source_CaptureSubsystem_Public_VideoCaptureSubsystem_h_42_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CAPTURESUBSYSTEM_API UClass* StaticClass<class UVideoCaptureSubsystem>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_arcgis_Plugins_UE_CaptureSubsystem_Source_CaptureSubsystem_Public_VideoCaptureSubsystem_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
