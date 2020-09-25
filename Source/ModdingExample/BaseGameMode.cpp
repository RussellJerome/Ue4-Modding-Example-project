// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGameMode.h"
#include "GameFramework/PlayerStart.h"
#include "Containers/Array.h"
#include "BaseGameInstance.h"
#include "UObject/ConstructorHelpers.h"

ABaseGameMode::ABaseGameMode()
	: Super()
{
	PlayerStateClass = ABasePlayerState::StaticClass();
	PlayerControllerClass = ABasePlayerController::StaticClass();
}

void ABaseGameMode::BeginPlay()
{
	Super::BeginPlay();
	UWidgetBlueprintLibrary::SetInputMode_GameOnly(UGameplayStatics::GetPlayerController(GetWorld(), 0));
}

void ABaseGameMode::PrintFunctionTest()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("FunctionTest"));
}

void ABaseGameMode::RequestSpawnCharacter_Implementation(AController* Controller, TSubclassOf<AActor> Weapon)
{
}

void ABaseGameMode::InitGameState()
{
	Super::InitGameState();
	//ABaseGameState* const MyGameState = Cast<ABaseGameState>(GameState);
//	MyGameState->NumTeams = NumTeams;
}

void ABaseGameMode::PostLogin(APlayerController* NewPlayer)
{
	ABasePlayerState* NewPlayerState = CastChecked<ABasePlayerState>(NewPlayer->PlayerState);
	const int32 TeamNum = FMath::RandRange(1, NumTeams);
	NewPlayerState->SetTeamNum(TeamNum);
	Super::PostLogin(NewPlayer);
}