// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuWidget.h"

void UMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();
	UBaseGameInstance * GameInstance = Cast<UBaseGameInstance >(UGameplayStatics::GetGameInstance(GetWorld()));
	if (GameInstance)
	{
		GameInstance->LoadMods();
	}
}