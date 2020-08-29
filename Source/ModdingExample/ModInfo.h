// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StructsAndEnums.h"
#include "GameFramework/GameModeBase.h"
#include "ModInfo.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class MODDINGEXAMPLE_API UModInfo : public UObject
{
	GENERATED_BODY()
public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "ModInfo")
		FModData ModInfo;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "LevelInfo")
		bool CustomLevels;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AssetRegistrySearchable, meta = (EditCondition = CustomLevels, HideEditConditionToggle), Category = "LevelInfo")
		TArray <TSoftObjectPtr<UWorld>> Levels;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GameModeInfo")
		bool CustomGamemodes;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (EditCondition = CustomGamemodes, HideEditConditionToggle), Category = "GameModeInfo")
	TArray<TSubclassOf<AGameModeBase>> GameModes;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WeaponInfo")
		bool CustomWeapons;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (EditCondition = CustomWeapons, HideEditConditionToggle), Category = "WeaponInfo")
		TArray<FWeaponData> Weapons;
};