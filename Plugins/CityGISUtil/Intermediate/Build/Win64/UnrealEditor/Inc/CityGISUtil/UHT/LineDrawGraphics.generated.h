// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "LineDrawGraphics.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class ULineBatchComponent;
class UObject;
struct FColor;
struct FLinearColor;
#ifdef CITYGISUTIL_LineDrawGraphics_generated_h
#error "LineDrawGraphics.generated.h already included, missing '#pragma once' in LineDrawGraphics.h"
#endif
#define CITYGISUTIL_LineDrawGraphics_generated_h

#define FID_graphic_arcgisTest_arcgis_Plugins_CityGISUtil_Source_CityGISUtil_Public_LineDrawGraphics_h_37_SPARSE_DATA
#define FID_graphic_arcgisTest_arcgis_Plugins_CityGISUtil_Source_CityGISUtil_Public_LineDrawGraphics_h_37_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_graphic_arcgisTest_arcgis_Plugins_CityGISUtil_Source_CityGISUtil_Public_LineDrawGraphics_h_37_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_graphic_arcgisTest_arcgis_Plugins_CityGISUtil_Source_CityGISUtil_Public_LineDrawGraphics_h_37_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execFlushLineComponent); \
	DECLARE_FUNCTION(execBPDrawSoildBox); \
	DECLARE_FUNCTION(execBPDrawBox); \
	DECLARE_FUNCTION(execBPDrawLine);


#define FID_graphic_arcgisTest_arcgis_Plugins_CityGISUtil_Source_CityGISUtil_Public_LineDrawGraphics_h_37_ACCESSORS
#define FID_graphic_arcgisTest_arcgis_Plugins_CityGISUtil_Source_CityGISUtil_Public_LineDrawGraphics_h_37_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULineDrawGraphics(); \
	friend struct Z_Construct_UClass_ULineDrawGraphics_Statics; \
public: \
	DECLARE_CLASS(ULineDrawGraphics, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CityGISUtil"), NO_API) \
	DECLARE_SERIALIZER(ULineDrawGraphics)


#define FID_graphic_arcgisTest_arcgis_Plugins_CityGISUtil_Source_CityGISUtil_Public_LineDrawGraphics_h_37_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULineDrawGraphics(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULineDrawGraphics(ULineDrawGraphics&&); \
	NO_API ULineDrawGraphics(const ULineDrawGraphics&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULineDrawGraphics); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULineDrawGraphics); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULineDrawGraphics) \
	NO_API virtual ~ULineDrawGraphics();


#define FID_graphic_arcgisTest_arcgis_Plugins_CityGISUtil_Source_CityGISUtil_Public_LineDrawGraphics_h_34_PROLOG
#define FID_graphic_arcgisTest_arcgis_Plugins_CityGISUtil_Source_CityGISUtil_Public_LineDrawGraphics_h_37_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_graphic_arcgisTest_arcgis_Plugins_CityGISUtil_Source_CityGISUtil_Public_LineDrawGraphics_h_37_SPARSE_DATA \
	FID_graphic_arcgisTest_arcgis_Plugins_CityGISUtil_Source_CityGISUtil_Public_LineDrawGraphics_h_37_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_graphic_arcgisTest_arcgis_Plugins_CityGISUtil_Source_CityGISUtil_Public_LineDrawGraphics_h_37_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_graphic_arcgisTest_arcgis_Plugins_CityGISUtil_Source_CityGISUtil_Public_LineDrawGraphics_h_37_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_graphic_arcgisTest_arcgis_Plugins_CityGISUtil_Source_CityGISUtil_Public_LineDrawGraphics_h_37_ACCESSORS \
	FID_graphic_arcgisTest_arcgis_Plugins_CityGISUtil_Source_CityGISUtil_Public_LineDrawGraphics_h_37_INCLASS_NO_PURE_DECLS \
	FID_graphic_arcgisTest_arcgis_Plugins_CityGISUtil_Source_CityGISUtil_Public_LineDrawGraphics_h_37_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CITYGISUTIL_API UClass* StaticClass<class ULineDrawGraphics>();

#define FID_graphic_arcgisTest_arcgis_Plugins_CityGISUtil_Source_CityGISUtil_Public_LineDrawGraphics_h_78_SPARSE_DATA
#define FID_graphic_arcgisTest_arcgis_Plugins_CityGISUtil_Source_CityGISUtil_Public_LineDrawGraphics_h_78_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_graphic_arcgisTest_arcgis_Plugins_CityGISUtil_Source_CityGISUtil_Public_LineDrawGraphics_h_78_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_graphic_arcgisTest_arcgis_Plugins_CityGISUtil_Source_CityGISUtil_Public_LineDrawGraphics_h_78_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execPopDrawArea); \
	DECLARE_FUNCTION(execRemoveDrawArea); \
	DECLARE_FUNCTION(execGenerateArea); \
	DECLARE_FUNCTION(execStartMeasureArea); \
	DECLARE_FUNCTION(execPopDrawLine); \
	DECLARE_FUNCTION(execRemoveDrawLine); \
	DECLARE_FUNCTION(execAddDrawLine);


#define FID_graphic_arcgisTest_arcgis_Plugins_CityGISUtil_Source_CityGISUtil_Public_LineDrawGraphics_h_78_ACCESSORS
#define FID_graphic_arcgisTest_arcgis_Plugins_CityGISUtil_Source_CityGISUtil_Public_LineDrawGraphics_h_78_INCLASS \
private: \
	static void StaticRegisterNativesALineDrawManager(); \
	friend struct Z_Construct_UClass_ALineDrawManager_Statics; \
public: \
	DECLARE_CLASS(ALineDrawManager, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CityGISUtil"), NO_API) \
	DECLARE_SERIALIZER(ALineDrawManager)


#define FID_graphic_arcgisTest_arcgis_Plugins_CityGISUtil_Source_CityGISUtil_Public_LineDrawGraphics_h_78_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ALineDrawManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ALineDrawManager) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALineDrawManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALineDrawManager); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALineDrawManager(ALineDrawManager&&); \
	NO_API ALineDrawManager(const ALineDrawManager&); \
public: \
	NO_API virtual ~ALineDrawManager();


#define FID_graphic_arcgisTest_arcgis_Plugins_CityGISUtil_Source_CityGISUtil_Public_LineDrawGraphics_h_75_PROLOG
#define FID_graphic_arcgisTest_arcgis_Plugins_CityGISUtil_Source_CityGISUtil_Public_LineDrawGraphics_h_78_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_graphic_arcgisTest_arcgis_Plugins_CityGISUtil_Source_CityGISUtil_Public_LineDrawGraphics_h_78_SPARSE_DATA \
	FID_graphic_arcgisTest_arcgis_Plugins_CityGISUtil_Source_CityGISUtil_Public_LineDrawGraphics_h_78_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_graphic_arcgisTest_arcgis_Plugins_CityGISUtil_Source_CityGISUtil_Public_LineDrawGraphics_h_78_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_graphic_arcgisTest_arcgis_Plugins_CityGISUtil_Source_CityGISUtil_Public_LineDrawGraphics_h_78_RPC_WRAPPERS \
	FID_graphic_arcgisTest_arcgis_Plugins_CityGISUtil_Source_CityGISUtil_Public_LineDrawGraphics_h_78_ACCESSORS \
	FID_graphic_arcgisTest_arcgis_Plugins_CityGISUtil_Source_CityGISUtil_Public_LineDrawGraphics_h_78_INCLASS \
	FID_graphic_arcgisTest_arcgis_Plugins_CityGISUtil_Source_CityGISUtil_Public_LineDrawGraphics_h_78_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CITYGISUTIL_API UClass* StaticClass<class ALineDrawManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_graphic_arcgisTest_arcgis_Plugins_CityGISUtil_Source_CityGISUtil_Public_LineDrawGraphics_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
