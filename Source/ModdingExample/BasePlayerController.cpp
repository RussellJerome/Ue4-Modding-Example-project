// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayerController.h"
#include "BaseGameInstance.h"
#include "StructsAndEnums.h"
#include "BaseGameMode.h"
void ABasePlayerController::SpawnPlayer_Implementation(TSubclassOf<AActor> Weapon)
{

	ABaseGameMode* GM = (ABaseGameMode*)GetWorld()->GetAuthGameMode();
	if (GM)
	{
		GM->RequestSpawnCharacter(this, Weapon);
	}

}

bool ABasePlayerController::SpawnPlayer_Validate(TSubclassOf<AActor> Weapon) { return true; }