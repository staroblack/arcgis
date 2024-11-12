// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MapSystemBFL.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MAPSYSTEM_MapSystemBFL_generated_h
#error "MapSystemBFL.generated.h already included, missing '#pragma once' in MapSystemBFL.h"
#endif
#define MAPSYSTEM_MapSystemBFL_generated_h

#define FID_arcgis_Plugins_CityGISUtil_Source_MapSystem_Public_MapSystemBFL_h_15_SPARSE_DATA
#define FID_arcgis_Plugins_CityGISUtil_Source_MapSystem_Public_MapSystemBFL_h_15_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_arcgis_Plugins_CityGISUtil_Source_MapSystem_Public_MapSystemBFL_h_15_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_arcgis_Plugins_CityGISUtil_Source_MapSystem_Public_MapSystemBFL_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execTWD97toWGS84); \
	DECLARE_FUNCTION(execWGS84toTWD97); \
	DECLARE_FUNCTION(execTileNumberNumtoLatlon); \
	DECLARE_FUNCTION(execTileNumberLatlontoNum); \
	DECLARE_FUNCTION(execTileNumberSize);


#define FID_arcgis_Plugins_CityGISUtil_Source_MapSystem_Public_MapSystemBFL_h_15_ACCESSORS
#define FID_arcgis_Plugins_CityGISUtil_Source_MapSystem_Public_MapSystemBFL_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAMapSystemBFL(); \
	friend struct Z_Construct_UClass_AMapSystemBFL_Statics; \
public: \
	DECLARE_CLASS(AMapSystemBFL, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MapSystem"), NO_API) \
	DECLARE_SERIALIZER(AMapSystemBFL)


#define FID_arcgis_Plugins_CityGISUtil_Source_MapSystem_Public_MapSystemBFL_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMapSystemBFL(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMapSystemBFL) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMapSystemBFL); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMapSystemBFL); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMapSystemBFL(AMapSystemBFL&&); \
	NO_API AMapSystemBFL(const AMapSystemBFL&); \
public: \
	NO_API virtual ~AMapSystemBFL();


#define FID_arcgis_Plugins_CityGISUtil_Source_MapSystem_Public_MapSystemBFL_h_12_PROLOG
#define FID_arcgis_Plugins_CityGISUtil_Source_MapSystem_Public_MapSystemBFL_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_arcgis_Plugins_CityGISUtil_Source_MapSystem_Public_MapSystemBFL_h_15_SPARSE_DATA \
	FID_arcgis_Plugins_CityGISUtil_Source_MapSystem_Public_MapSystemBFL_h_15_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_arcgis_Plugins_CityGISUtil_Source_MapSystem_Public_MapSystemBFL_h_15_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_arcgis_Plugins_CityGISUtil_Source_MapSystem_Public_MapSystemBFL_h_15_RPC_WRAPPERS \
	FID_arcgis_Plugins_CityGISUtil_Source_MapSystem_Public_MapSystemBFL_h_15_ACCESSORS \
	FID_arcgis_Plugins_CityGISUtil_Source_MapSystem_Public_MapSystemBFL_h_15_INCLASS \
	FID_arcgis_Plugins_CityGISUtil_Source_MapSystem_Public_MapSystemBFL_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MAPSYSTEM_API UClass* StaticClass<class AMapSystemBFL>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_arcgis_Plugins_CityGISUtil_Source_MapSystem_Public_MapSystemBFL_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
