// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "TextAdventureGameGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTextAdventureGameGameModeBase() {}
// Cross Module References
	TEXTADVENTUREGAME_API UClass* Z_Construct_UClass_ATextAdventureGameGameModeBase_NoRegister();
	TEXTADVENTUREGAME_API UClass* Z_Construct_UClass_ATextAdventureGameGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_TextAdventureGame();
// End Cross Module References
	void ATextAdventureGameGameModeBase::StaticRegisterNativesATextAdventureGameGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_ATextAdventureGameGameModeBase_NoRegister()
	{
		return ATextAdventureGameGameModeBase::StaticClass();
	}
	UClass* Z_Construct_UClass_ATextAdventureGameGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AGameModeBase,
				(UObject* (*)())Z_Construct_UPackage__Script_TextAdventureGame,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
				{ "IncludePath", "TextAdventureGameGameModeBase.h" },
				{ "ModuleRelativePath", "TextAdventureGameGameModeBase.h" },
				{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ATextAdventureGameGameModeBase>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ATextAdventureGameGameModeBase::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900288u,
				nullptr, 0,
				nullptr, 0,
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATextAdventureGameGameModeBase, 301602122);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATextAdventureGameGameModeBase(Z_Construct_UClass_ATextAdventureGameGameModeBase, &ATextAdventureGameGameModeBase::StaticClass, TEXT("/Script/TextAdventureGame"), TEXT("ATextAdventureGameGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATextAdventureGameGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
