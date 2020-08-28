// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGameMode.h"
#include "GameFramework/PlayerStart.h"
#include "Containers/Array.h"
#include "UObject/ConstructorHelpers.h"

ABaseGameMode::ABaseGameMode()
	: Super()
{
}

void ABaseGameMode::BeginPlay()
{
}

void ABaseGameMode::PrintFunctionTest()
{
}

void ABaseGameMode::RequestSpawnCharacter_Implementation(AController* Controller, TSubclassOf<AActor> Weapon)
{

}