// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "BasePlayerState.generated.h"

/**
 * 
 */
UCLASS()
class MODDINGEXAMPLE_API ABasePlayerState : public APlayerState
{
	GENERATED_BODY()
public:
	UPROPERTY(replicated, EditDefaultsOnly, BlueprintReadWrite, Category = "Teams")
		int Team;
};
