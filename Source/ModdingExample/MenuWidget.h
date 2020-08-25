// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "MenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class MODDINGEXAMPLE_API UMenuWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;
};
