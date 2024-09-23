// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "EasyXMLElement.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UEasyXMLAttribute;
class UEasyXMLElement;
enum class EEasyXMLParserFound : uint8;
#ifdef EASYXMLPARSER_EasyXMLElement_generated_h
#error "EasyXMLElement.generated.h already included, missing '#pragma once' in EasyXMLElement.h"
#endif
#define EASYXMLPARSER_EasyXMLElement_generated_h

#define FID_graphics_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLElement_h_13_SPARSE_DATA
#define FID_graphics_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLElement_h_13_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_graphics_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLElement_h_13_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_graphics_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLElement_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetAttribute); \
	DECLARE_FUNCTION(execReadElements); \
	DECLARE_FUNCTION(execReadElement); \
	DECLARE_FUNCTION(execReadBool); \
	DECLARE_FUNCTION(execReadString); \
	DECLARE_FUNCTION(execReadFloat); \
	DECLARE_FUNCTION(execReadInt);


#define FID_graphics_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLElement_h_13_ACCESSORS
#define FID_graphics_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLElement_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEasyXMLElement(); \
	friend struct Z_Construct_UClass_UEasyXMLElement_Statics; \
public: \
	DECLARE_CLASS(UEasyXMLElement, UEasyXMLObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/EasyXMLParser"), NO_API) \
	DECLARE_SERIALIZER(UEasyXMLElement)


#define FID_graphics_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLElement_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UEasyXMLElement(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UEasyXMLElement(UEasyXMLElement&&); \
	NO_API UEasyXMLElement(const UEasyXMLElement&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEasyXMLElement); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEasyXMLElement); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEasyXMLElement) \
	NO_API virtual ~UEasyXMLElement();


#define FID_graphics_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLElement_h_10_PROLOG
#define FID_graphics_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLElement_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_graphics_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLElement_h_13_SPARSE_DATA \
	FID_graphics_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLElement_h_13_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_graphics_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLElement_h_13_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_graphics_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLElement_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_graphics_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLElement_h_13_ACCESSORS \
	FID_graphics_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLElement_h_13_INCLASS_NO_PURE_DECLS \
	FID_graphics_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLElement_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> EASYXMLPARSER_API UClass* StaticClass<class UEasyXMLElement>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_graphics_arcgis_Plugins_EasyXMLParser_Source_EasyXMLParser_Public_EasyXMLElement_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
