// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayerController.h"
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

void ABasePlayerController::SetTeamServer_Implementation(int32 STeam)
{
	SetTeam(STeam);
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("RunningOnServer"));

}


bool ABasePlayerController::SetTeamServer_Validate(int32 STeam) { return true; }

void ABasePlayerController::SetTeam(int32 Team)
{
	ABasePlayerState* BPS = Cast<ABasePlayerState>(PlayerState);
	if (HasAuthority())

		if (BPS)
		{
			BPS->Team = Team;
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("WeHaveAuthority!"));
		}


		else
			SetTeamServer(Team);
}