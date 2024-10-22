// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../../Plugins/CityGISUtil/Source/MapSystem/Public/MapSystemBFL.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMapSystemBFL() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	MAPSYSTEM_API UClass* Z_Construct_UClass_AMapSystemBFL();
	MAPSYSTEM_API UClass* Z_Construct_UClass_AMapSystemBFL_NoRegister();
	UPackage* Z_Construct_UPackage__Script_MapSystem();
// End Cross Module References
	DEFINE_FUNCTION(AMapSystemBFL::execTWD97toWGS84)
	{
		P_GET_PROPERTY(FDoubleProperty,Z_Param_x);
		P_GET_PROPERTY(FDoubleProperty,Z_Param_y);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=AMapSystemBFL::TWD97toWGS84(Z_Param_x,Z_Param_y);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMapSystemBFL::execWGS84toTWD97)
	{
		P_GET_PROPERTY(FDoubleProperty,Z_Param_wgs84x);
		P_GET_PROPERTY(FDoubleProperty,Z_Param_wgs84y);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=AMapSystemBFL::WGS84toTWD97(Z_Param_wgs84x,Z_Param_wgs84y);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMapSystemBFL::execTileNumberNumtoLatlon)
	{
		P_GET_PROPERTY(FDoubleProperty,Z_Param_x);
		P_GET_PROPERTY(FDoubleProperty,Z_Param_y);
		P_GET_PROPERTY(FIntProperty,Z_Param_level);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=AMapSystemBFL::TileNumberNumtoLatlon(Z_Param_x,Z_Param_y,Z_Param_level);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMapSystemBFL::execTileNumberLatlontoNum)
	{
		P_GET_PROPERTY(FDoubleProperty,Z_Param_lat);
		P_GET_PROPERTY(FDoubleProperty,Z_Param_lon);
		P_GET_PROPERTY(FIntProperty,Z_Param_level);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=AMapSystemBFL::TileNumberLatlontoNum(Z_Param_lat,Z_Param_lon,Z_Param_level);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMapSystemBFL::execTileNumberSize)
	{
		P_GET_PROPERTY(FDoubleProperty,Z_Param_lat);
		P_GET_PROPERTY(FIntProperty,Z_Param_level);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=AMapSystemBFL::TileNumberSize(Z_Param_lat,Z_Param_level);
		P_NATIVE_END;
	}
	void AMapSystemBFL::StaticRegisterNativesAMapSystemBFL()
	{
		UClass* Class = AMapSystemBFL::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "TileNumberLatlontoNum", &AMapSystemBFL::execTileNumberLatlontoNum },
			{ "TileNumberNumtoLatlon", &AMapSystemBFL::execTileNumberNumtoLatlon },
			{ "TileNumberSize", &AMapSystemBFL::execTileNumberSize },
			{ "TWD97toWGS84", &AMapSystemBFL::execTWD97toWGS84 },
			{ "WGS84toTWD97", &AMapSystemBFL::execWGS84toTWD97 },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMapSystemBFL_TileNumberLatlontoNum_Statics
	{
		struct MapSystemBFL_eventTileNumberLatlontoNum_Parms
		{
			double lat;
			double lon;
			int32 level;
			FVector ReturnValue;
		};
		static const UECodeGen_Private::FDoublePropertyParams NewProp_lat;
		static const UECodeGen_Private::FDoublePropertyParams NewProp_lon;
		static const UECodeGen_Private::FIntPropertyParams NewProp_level;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_AMapSystemBFL_TileNumberLatlontoNum_Statics::NewProp_lat = { "lat", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MapSystemBFL_eventTileNumberLatlontoNum_Parms, lat), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_AMapSystemBFL_TileNumberLatlontoNum_Statics::NewProp_lon = { "lon", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MapSystemBFL_eventTileNumberLatlontoNum_Parms, lon), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AMapSystemBFL_TileNumberLatlontoNum_Statics::NewProp_level = { "level", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MapSystemBFL_eventTileNumberLatlontoNum_Parms, level), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMapSystemBFL_TileNumberLatlontoNum_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MapSystemBFL_eventTileNumberLatlontoNum_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMapSystemBFL_TileNumberLatlontoNum_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMapSystemBFL_TileNumberLatlontoNum_Statics::NewProp_lat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMapSystemBFL_TileNumberLatlontoNum_Statics::NewProp_lon,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMapSystemBFL_TileNumberLatlontoNum_Statics::NewProp_level,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMapSystemBFL_TileNumberLatlontoNum_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMapSystemBFL_TileNumberLatlontoNum_Statics::Function_MetaDataParams[] = {
		{ "Category", "MapSystem" },
		{ "ModuleRelativePath", "Public/MapSystemBFL.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMapSystemBFL_TileNumberLatlontoNum_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMapSystemBFL, nullptr, "TileNumberLatlontoNum", nullptr, nullptr, Z_Construct_UFunction_AMapSystemBFL_TileNumberLatlontoNum_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMapSystemBFL_TileNumberLatlontoNum_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMapSystemBFL_TileNumberLatlontoNum_Statics::MapSystemBFL_eventTileNumberLatlontoNum_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMapSystemBFL_TileNumberLatlontoNum_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMapSystemBFL_TileNumberLatlontoNum_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMapSystemBFL_TileNumberLatlontoNum_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AMapSystemBFL_TileNumberLatlontoNum_Statics::MapSystemBFL_eventTileNumberLatlontoNum_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AMapSystemBFL_TileNumberLatlontoNum()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMapSystemBFL_TileNumberLatlontoNum_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMapSystemBFL_TileNumberNumtoLatlon_Statics
	{
		struct MapSystemBFL_eventTileNumberNumtoLatlon_Parms
		{
			double x;
			double y;
			int32 level;
			FVector ReturnValue;
		};
		static const UECodeGen_Private::FDoublePropertyParams NewProp_x;
		static const UECodeGen_Private::FDoublePropertyParams NewProp_y;
		static const UECodeGen_Private::FIntPropertyParams NewProp_level;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_AMapSystemBFL_TileNumberNumtoLatlon_Statics::NewProp_x = { "x", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MapSystemBFL_eventTileNumberNumtoLatlon_Parms, x), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_AMapSystemBFL_TileNumberNumtoLatlon_Statics::NewProp_y = { "y", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MapSystemBFL_eventTileNumberNumtoLatlon_Parms, y), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AMapSystemBFL_TileNumberNumtoLatlon_Statics::NewProp_level = { "level", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MapSystemBFL_eventTileNumberNumtoLatlon_Parms, level), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMapSystemBFL_TileNumberNumtoLatlon_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MapSystemBFL_eventTileNumberNumtoLatlon_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMapSystemBFL_TileNumberNumtoLatlon_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMapSystemBFL_TileNumberNumtoLatlon_Statics::NewProp_x,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMapSystemBFL_TileNumberNumtoLatlon_Statics::NewProp_y,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMapSystemBFL_TileNumberNumtoLatlon_Statics::NewProp_level,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMapSystemBFL_TileNumberNumtoLatlon_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMapSystemBFL_TileNumberNumtoLatlon_Statics::Function_MetaDataParams[] = {
		{ "Category", "MapSystem" },
		{ "ModuleRelativePath", "Public/MapSystemBFL.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMapSystemBFL_TileNumberNumtoLatlon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMapSystemBFL, nullptr, "TileNumberNumtoLatlon", nullptr, nullptr, Z_Construct_UFunction_AMapSystemBFL_TileNumberNumtoLatlon_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMapSystemBFL_TileNumberNumtoLatlon_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMapSystemBFL_TileNumberNumtoLatlon_Statics::MapSystemBFL_eventTileNumberNumtoLatlon_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMapSystemBFL_TileNumberNumtoLatlon_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMapSystemBFL_TileNumberNumtoLatlon_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMapSystemBFL_TileNumberNumtoLatlon_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AMapSystemBFL_TileNumberNumtoLatlon_Statics::MapSystemBFL_eventTileNumberNumtoLatlon_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AMapSystemBFL_TileNumberNumtoLatlon()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMapSystemBFL_TileNumberNumtoLatlon_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMapSystemBFL_TileNumberSize_Statics
	{
		struct MapSystemBFL_eventTileNumberSize_Parms
		{
			double lat;
			int32 level;
			FVector ReturnValue;
		};
		static const UECodeGen_Private::FDoublePropertyParams NewProp_lat;
		static const UECodeGen_Private::FIntPropertyParams NewProp_level;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_AMapSystemBFL_TileNumberSize_Statics::NewProp_lat = { "lat", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MapSystemBFL_eventTileNumberSize_Parms, lat), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AMapSystemBFL_TileNumberSize_Statics::NewProp_level = { "level", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MapSystemBFL_eventTileNumberSize_Parms, level), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMapSystemBFL_TileNumberSize_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MapSystemBFL_eventTileNumberSize_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMapSystemBFL_TileNumberSize_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMapSystemBFL_TileNumberSize_Statics::NewProp_lat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMapSystemBFL_TileNumberSize_Statics::NewProp_level,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMapSystemBFL_TileNumberSize_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMapSystemBFL_TileNumberSize_Statics::Function_MetaDataParams[] = {
		{ "Category", "MapSystem" },
		{ "ModuleRelativePath", "Public/MapSystemBFL.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMapSystemBFL_TileNumberSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMapSystemBFL, nullptr, "TileNumberSize", nullptr, nullptr, Z_Construct_UFunction_AMapSystemBFL_TileNumberSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMapSystemBFL_TileNumberSize_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMapSystemBFL_TileNumberSize_Statics::MapSystemBFL_eventTileNumberSize_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMapSystemBFL_TileNumberSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMapSystemBFL_TileNumberSize_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMapSystemBFL_TileNumberSize_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AMapSystemBFL_TileNumberSize_Statics::MapSystemBFL_eventTileNumberSize_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AMapSystemBFL_TileNumberSize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMapSystemBFL_TileNumberSize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMapSystemBFL_TWD97toWGS84_Statics
	{
		struct MapSystemBFL_eventTWD97toWGS84_Parms
		{
			double x;
			double y;
			FVector ReturnValue;
		};
		static const UECodeGen_Private::FDoublePropertyParams NewProp_x;
		static const UECodeGen_Private::FDoublePropertyParams NewProp_y;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_AMapSystemBFL_TWD97toWGS84_Statics::NewProp_x = { "x", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MapSystemBFL_eventTWD97toWGS84_Parms, x), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_AMapSystemBFL_TWD97toWGS84_Statics::NewProp_y = { "y", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MapSystemBFL_eventTWD97toWGS84_Parms, y), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMapSystemBFL_TWD97toWGS84_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MapSystemBFL_eventTWD97toWGS84_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMapSystemBFL_TWD97toWGS84_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMapSystemBFL_TWD97toWGS84_Statics::NewProp_x,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMapSystemBFL_TWD97toWGS84_Statics::NewProp_y,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMapSystemBFL_TWD97toWGS84_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMapSystemBFL_TWD97toWGS84_Statics::Function_MetaDataParams[] = {
		{ "Category", "MapSystem" },
		{ "ModuleRelativePath", "Public/MapSystemBFL.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMapSystemBFL_TWD97toWGS84_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMapSystemBFL, nullptr, "TWD97toWGS84", nullptr, nullptr, Z_Construct_UFunction_AMapSystemBFL_TWD97toWGS84_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMapSystemBFL_TWD97toWGS84_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMapSystemBFL_TWD97toWGS84_Statics::MapSystemBFL_eventTWD97toWGS84_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMapSystemBFL_TWD97toWGS84_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMapSystemBFL_TWD97toWGS84_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMapSystemBFL_TWD97toWGS84_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AMapSystemBFL_TWD97toWGS84_Statics::MapSystemBFL_eventTWD97toWGS84_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AMapSystemBFL_TWD97toWGS84()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMapSystemBFL_TWD97toWGS84_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMapSystemBFL_WGS84toTWD97_Statics
	{
		struct MapSystemBFL_eventWGS84toTWD97_Parms
		{
			double wgs84x;
			double wgs84y;
			FVector ReturnValue;
		};
		static const UECodeGen_Private::FDoublePropertyParams NewProp_wgs84x;
		static const UECodeGen_Private::FDoublePropertyParams NewProp_wgs84y;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_AMapSystemBFL_WGS84toTWD97_Statics::NewProp_wgs84x = { "wgs84x", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MapSystemBFL_eventWGS84toTWD97_Parms, wgs84x), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_AMapSystemBFL_WGS84toTWD97_Statics::NewProp_wgs84y = { "wgs84y", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MapSystemBFL_eventWGS84toTWD97_Parms, wgs84y), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMapSystemBFL_WGS84toTWD97_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MapSystemBFL_eventWGS84toTWD97_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMapSystemBFL_WGS84toTWD97_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMapSystemBFL_WGS84toTWD97_Statics::NewProp_wgs84x,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMapSystemBFL_WGS84toTWD97_Statics::NewProp_wgs84y,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMapSystemBFL_WGS84toTWD97_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMapSystemBFL_WGS84toTWD97_Statics::Function_MetaDataParams[] = {
		{ "Category", "MapSystem" },
		{ "ModuleRelativePath", "Public/MapSystemBFL.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMapSystemBFL_WGS84toTWD97_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMapSystemBFL, nullptr, "WGS84toTWD97", nullptr, nullptr, Z_Construct_UFunction_AMapSystemBFL_WGS84toTWD97_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMapSystemBFL_WGS84toTWD97_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMapSystemBFL_WGS84toTWD97_Statics::MapSystemBFL_eventWGS84toTWD97_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMapSystemBFL_WGS84toTWD97_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMapSystemBFL_WGS84toTWD97_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMapSystemBFL_WGS84toTWD97_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AMapSystemBFL_WGS84toTWD97_Statics::MapSystemBFL_eventWGS84toTWD97_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AMapSystemBFL_WGS84toTWD97()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMapSystemBFL_WGS84toTWD97_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMapSystemBFL);
	UClass* Z_Construct_UClass_AMapSystemBFL_NoRegister()
	{
		return AMapSystemBFL::StaticClass();
	}
	struct Z_Construct_UClass_AMapSystemBFL_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMapSystemBFL_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_MapSystem,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMapSystemBFL_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_AMapSystemBFL_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMapSystemBFL_TileNumberLatlontoNum, "TileNumberLatlontoNum" }, // 1063573711
		{ &Z_Construct_UFunction_AMapSystemBFL_TileNumberNumtoLatlon, "TileNumberNumtoLatlon" }, // 1381466933
		{ &Z_Construct_UFunction_AMapSystemBFL_TileNumberSize, "TileNumberSize" }, // 938061027
		{ &Z_Construct_UFunction_AMapSystemBFL_TWD97toWGS84, "TWD97toWGS84" }, // 2107502093
		{ &Z_Construct_UFunction_AMapSystemBFL_WGS84toTWD97, "WGS84toTWD97" }, // 1265216236
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMapSystemBFL_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMapSystemBFL_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "MapSystemBFL.h" },
		{ "ModuleRelativePath", "Public/MapSystemBFL.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMapSystemBFL_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMapSystemBFL>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AMapSystemBFL_Statics::ClassParams = {
		&AMapSystemBFL::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMapSystemBFL_Statics::Class_MetaDataParams), Z_Construct_UClass_AMapSystemBFL_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AMapSystemBFL()
	{
		if (!Z_Registration_Info_UClass_AMapSystemBFL.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMapSystemBFL.OuterSingleton, Z_Construct_UClass_AMapSystemBFL_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AMapSystemBFL.OuterSingleton;
	}
	template<> MAPSYSTEM_API UClass* StaticClass<AMapSystemBFL>()
	{
		return AMapSystemBFL::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMapSystemBFL);
	AMapSystemBFL::~AMapSystemBFL() {}
	struct Z_CompiledInDeferFile_FID_graphic_arcgisTest_arcgis_Plugins_CityGISUtil_Source_MapSystem_Public_MapSystemBFL_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_graphic_arcgisTest_arcgis_Plugins_CityGISUtil_Source_MapSystem_Public_MapSystemBFL_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AMapSystemBFL, AMapSystemBFL::StaticClass, TEXT("AMapSystemBFL"), &Z_Registration_Info_UClass_AMapSystemBFL, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMapSystemBFL), 3896577001U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_graphic_arcgisTest_arcgis_Plugins_CityGISUtil_Source_MapSystem_Public_MapSystemBFL_h_2979039448(TEXT("/Script/MapSystem"),
		Z_CompiledInDeferFile_FID_graphic_arcgisTest_arcgis_Plugins_CityGISUtil_Source_MapSystem_Public_MapSystemBFL_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_graphic_arcgisTest_arcgis_Plugins_CityGISUtil_Source_MapSystem_Public_MapSystemBFL_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
