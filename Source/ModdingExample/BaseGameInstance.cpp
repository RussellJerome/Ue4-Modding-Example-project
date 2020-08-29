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
		Ext = (Ext.Left(1) == ".") ? "*" + Ext : "*." + Ext;
	}
	FileManager.FindFilesRecursive(Files, *RootFolderFullPath, *Ext, true, false);
	return true;
}

void UBaseGameInstance::Init()
{
	Super::Init();

	//Rename ModdingExample to your project name, EX: If my project is called WhiteWolf, you would do ../../../WhiteWolf/Content/ 
	RegisterMountPoint("/BaseGame/", "../../../ModdingExample/Content/");
	TArray<FString> ModFilesArray;
	FString Path = FPaths::ConvertRelativePathToFull(FPaths::ProjectModsDir());
	GetFilesInRootAndAllSubFolders(ModFilesArray, Path, ".pak");
	for (int i = 0; i < ModFilesArray.Num(); i++)
	{
		FString SelectedString = ModFilesArray[i];
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, SelectedString);
		int64 OutSize;
		if (IsValidPakFile(SelectedString, OutSize, false))
		{
			if (MountPakFile(SelectedString, i, ""))
			{
				FString LeftS;
				FString RightS;
				SelectedString.Split("/", &LeftS, &RightS, ESearchCase::IgnoreCase, ESearchDir::FromEnd);
				RightS.Split(".pak", &LeftS, &RightS, ESearchCase::IgnoreCase, ESearchDir::FromStart);
				FString ClassInfo;
				ClassInfo = TEXT("/BaseGame/") + LeftS + TEXT("/ModInfo");
				UClass* CalledClass = LoadClassFromPak(ClassInfo);
				if (IsValid(CalledClass))
				{
					if (CalledClass->IsChildOf(UModInfo::StaticClass()))
					{
						UModInfo* NewModInfo = NewObject<UModInfo>(this, CalledClass);
						ModData.Add(NewModInfo->ModInfo);
						LevelList.Append(NewModInfo->Levels);
						GameModes.Append(NewModInfo->GameModes);
						WeaponData.Append(NewModInfo->Weapons);
						NewModInfo->ConditionalBeginDestroy();
						NewModInfo = NULL;
					}
				}
			}

		}
	}
}