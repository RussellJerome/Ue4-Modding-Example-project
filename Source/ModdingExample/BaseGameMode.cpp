// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGameMode.h"
#include "UObject/ConstructorHelpers.h"

ABaseGameMode::ABaseGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/ThirdPersonBP/Blueprints/ThirdPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
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