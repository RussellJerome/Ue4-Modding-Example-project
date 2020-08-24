// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
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
		FString ModName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "ModInfo")
		FString Author;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "ModInfo")
		FString ModDetails;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "ModInfo")
		FString ModVersion;
};
