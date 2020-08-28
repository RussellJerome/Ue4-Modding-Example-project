// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BasePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MODDINGEXAMPLE_API ABasePlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "Spawn", Reliable, Server, WithValidation) // Called on the client executed on the server
	void SpawnPlayer(TSubclassOf<AActor> Weapon);
	void SpawnPlayer_Implementation(TSubclassOf<AActor> Weapon);
	bool SpawnPlayer_Validate(TSubclassOf<AActor> Weapon);
	
};
