// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayerController.h"
#include "BaseGameMode.h"
void ABasePlayerController::SpawnPlayer_Implementation(TSubclassOf<AActor> Weapon)
{
}

bool ABasePlayerController::SpawnPlayer_Validate(TSubclassOf<AActor> Weapon) { return true; }