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
	
	UFUNCTION(BlueprintCallable, Category = "Teams", Reliable, Server, WithValidation) // Called on the client executed on the server
	void SetTeamServer(int32 STeam);
	void SetTeamServer_Implementation(int32 STeam);
	bool SetTeamServer_Validate(int32 STeam);

	UFUNCTION(BlueprintCallable, Category = "Teams")
		void SetTeam(int32 Team);
};
