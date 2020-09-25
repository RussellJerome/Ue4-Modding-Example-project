// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "StructsAndEnums.h"
#include "BaseGameState.generated.h"

/**
 * 
 */
UCLASS()
class MODDINGEXAMPLE_API ABaseGameState : public AGameState
{
	GENERATED_BODY()
public:
    UPROPERTY(Transient, Replicated)
        int32 NumTeams;
};
