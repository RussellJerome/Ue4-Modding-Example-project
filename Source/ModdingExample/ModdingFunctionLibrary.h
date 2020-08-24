// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Runtime/PakFile/Public/IPlatformFilePak.h"
#include "HAL/PlatformFilemanager.h"
#include "Misc/PackageName.h"
#include "Math/Rotator.h"
#include "PakLoader.h"
#include "GameFramework/GameSession.h"
#include "ModdingFunctionLibrary.generated.h"


UCLASS()
class MODDINGEXAMPLE_API UModdingFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintPure, Category = "PakLoader")
		static UClass* GetPakFileClass(const FString& Filename);

	UFUNCTION(BlueprintCallable, Category = "PakLoader")
		static void RegisterMountPoint(const FString& RootPath, const FString& ContentPath);

	UFUNCTION(BlueprintCallable, Category = "PakLoader")
		static void UnRegisterMountPoint(const FString& RootPath, const FString& ContentPath);

	UFUNCTION(BlueprintCallable, Category = "PakLoader")
		static bool GetFilesInRootAndAllSubFolders(TArray<FString>& Files, FString RootFolderFullPath, FString Ext);
};