// Fill out your copyright notice in the Description page of Project Settings.


#include "MainWeapon.h"

// Sets default values
AMainWeapon::AMainWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMainWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

