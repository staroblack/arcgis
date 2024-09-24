// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "EasyXMLParserEnums.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef EASYXMLPARSER_EasyXMLParserEnums_generated_h
#error "EasyXMLParserEnums.generated.h already included, missing '#pragma once' in EasyXMLParserEnums.h"
#endif
#define EASYXMLPARSER_EasyXMLParserEnums_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_graphic_arcgisTest_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLParserEnums_h


#define FOREACH_ENUM_EEASYXMLPARSERERRORCODE(op) \
	op(EEasyXMLParserErrorCode::Successed) \
	op(EEasyXMLParserErrorCode::Failed) 

enum class EEasyXMLParserErrorCode : uint8;
template<> struct TIsUEnumClass<EEasyXMLParserErrorCode> { enum { Value = true }; };
template<> EASYXMLPARSER_API UEnum* StaticEnum<EEasyXMLParserErrorCode>();

#define FOREACH_ENUM_EEASYXMLPARSERFOUND(op) \
	op(EEasyXMLParserFound::Found) \
	op(EEasyXMLParserFound::NotFound) 

enum class EEasyXMLParserFound : uint8;
template<> struct TIsUEnumClass<EEasyXMLParserFound> { enum { Value = true }; };
template<> EASYXMLPARSER_API UEnum* StaticEnum<EEasyXMLParserFound>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
