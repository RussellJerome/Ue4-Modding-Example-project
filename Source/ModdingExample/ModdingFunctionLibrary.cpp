// Fill out your copyright notice in the Description page of Project Settings.


#include "ModdingFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/Paths.h"
#include "Misc/ConfigCacheIni.h"
#include "Runtime/Core/Public/Serialization/ArrayReader.h"
#include "Runtime/AssetRegistry/Public/AssetRegistryModule.h"
#include "Misc/App.h"
#include "Misc/FileHelper.h"
#include "Core/Public/Misc/SecureHash.h"
#include "PakLoader.h"
#include "Runtime/Engine/Classes/Engine/Texture2D.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
#include "Runtime/Engine/Classes/Sound/SoundBase.h"
#include "Runtime/Engine/Classes/Materials/Material.h"
#include "Runtime/Engine/Classes/Materials/MaterialInstanceConstant.h"
#include "Runtime/Engine/Classes/Engine/SkeletalMesh.h"
#include "Runtime/Engine/Classes/Animation/AnimSequence.h"

UClass* UModdingFunctionLibrary::GetPakFileClass(const FString& Filename)
{
	return FPakLoader::Get()->LoadClassFromPak(Filename);
}

void UModdingFunctionLibrary::RegisterMountPoint(const FString& RootPath, const FString& ContentPath)
{
	FPakLoader::Get()->RegisterMountPoint(RootPath, ContentPath);
}

void UModdingFunctionLibrary::UnRegisterMountPoint(const FString& RootPath, const FString& ContentPath)
{
	FPakLoader::Get()->UnRegisterMountPoint(RootPath, ContentPath);
}

bool UModdingFunctionLibrary::GetFilesInRootAndAllSubFolders(TArray<FString>& Files, FString RootFolderFullPath, FString Ext)
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