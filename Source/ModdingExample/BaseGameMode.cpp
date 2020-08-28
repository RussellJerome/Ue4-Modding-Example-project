// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGameMode.h"
#include "GameFramework/PlayerStart.h"
#include "Containers/Array.h"
#include "UObject/ConstructorHelpers.h"

ABaseGameMode::ABaseGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/Base/BP_BaseCharacter"));
	//DefaultPawnClass = PlayerPawnClassFinder.Class;
	PlayerStateClass = ABasePlayerState::StaticClass();
	PlayerControllerClass = ABasePlayerController::StaticClass();
}

void ABaseGameMode::BeginPlay()
{
	Super::BeginPlay();
	UWidgetBlueprintLibrary::SetInputMode_GameOnly(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("NotValidPak"));
}

void ABaseGameMode::PrintFunctionTest()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("FunctionTest"));
}

void ABaseGameMode::RequestSpawnCharacter_Implementation(AController* Controller, TSubclassOf<AActor> Weapon)
{

}