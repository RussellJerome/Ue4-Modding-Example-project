// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGameInstance.h"
#include "Misc/App.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Containers/UnrealString.h"
#include "HAL/FileManager.h"
#include "HAL/PlatformFilemanager.h"
#include "UObject/UObjectGlobals.h"

bool UBaseGameInstance::GetFilesInRootAndAllSubFolders(TArray<FString>& Files, FString RootFolderFullPath, FString Ext)
{
	if (RootFolderFullPath.Len() < 1) return false;
	FPaths::NormalizeDirectoryName(RootFolderFullPath);
	IFileManager& FileManager = IFileManager::Get();
	if (!Ext.Contains(TEXT("*")))
	{
		if (Ext == "")
		{
			Ext = "*.*";
		}
		else
		{
			Ext = (Ext.Left(1) == ".") ? "*" + Ext : "*." + Ext;
		}
	}
	FileManager.FindFilesRecursive(Files, *RootFolderFullPath, *Ext, true, false);
	return true;
}

void UBaseGameInstance::LoadMods()
{
	ModInfoList.Empty();
	for (int i = 0; i < ModListPak.Num(); i++)
	{
		FString SelectedString = ModListPak[i];
		FString ClassInfo;
		ClassInfo = TEXT("/BaseGame/") + SelectedString + TEXT("/ModInfo");
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, ClassInfo);
		UClass* CalledClass = LoadClassFromPak(ClassInfo);
		if (IsValid(CalledClass))
		{
			if (CalledClass->IsChildOf(UModInfo::StaticClass()))
			{
				UModInfo* NewModInfo = NewObject<UModInfo>(this, CalledClass);
				ModInfoList.AddUnique(NewModInfo);
			}
		}
	}
}

void UBaseGameInstance::Init()
{
	Super::Init();
	RegisterMountPoint("/BaseGame/","../../../ModdingExample/Content/");
	TArray<FString> ModFilesArray;
	FString Path = FPaths::ConvertRelativePathToFull(FPaths::ProjectModsDir());
	GetFilesInRootAndAllSubFolders(ModFilesArray, Path, "");
	for (int i = 0; i < ModFilesArray.Num(); i++)
	{
		FString SelectedString = ModFilesArray[i];
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, SelectedString);
		int64 OutSize;
		if (IsValidPakFile(SelectedString, OutSize, false))
		{
			MountPakFile(SelectedString, i, "");
			FString LeftS;
			FString RightS;
			SelectedString.Split("/", &LeftS, &RightS, ESearchCase::IgnoreCase, ESearchDir::FromEnd);
			RightS.Split(".pak", &LeftS, &RightS, ESearchCase::IgnoreCase, ESearchDir::FromStart);
			ModListPak.AddUnique(LeftS);
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("NotValidPak"));
		}
	}
}