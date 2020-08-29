// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Kismet/GameplayStatics.h"
#include "BasePlayerState.h"
#include "BasePlayerController.h"
#include "StructsAndEnums.h"
#include "BaseGameMode.generated.h"

/**
 * 
 */
UCLASS()
class MODDINGEXAMPLE_API ABaseGameMode : public AGameMode
{
	GENERATED_BODY()
public:
    ABaseGameMode();
    virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Match")
        TEnumAsByte <EMatchType> MatchType;

    UFUNCTION(BlueprintCallable, Category = "GM")
        void PrintFunctionTest();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Spawn")
    void RequestSpawnCharacter(AController* Controller, TSubclassOf<AActor> Weapon);
    void RequestSpawnCharacter_Implementation(AController* Controller, TSubclassOf<AActor> Weapon);
};
