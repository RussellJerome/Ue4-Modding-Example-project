// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "BaseGameMode.generated.h"

/**
 * 
 */
UCLASS()
class MODDINGEXAMPLE_API ABaseGameMode : public AGameMode
{
	GENERATED_BODY()
public:
    ABaseGameMode();
    virtual void BeginPlay() override;

    UFUNCTION(BlueprintCallable, Category = "GM")
        void PrintFunctionTest();
};
