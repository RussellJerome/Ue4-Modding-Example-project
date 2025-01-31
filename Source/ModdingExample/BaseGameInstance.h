// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "IPlatformFilePak.h"
#include "Runtime/Core/Public/HAL/PlatformFilemanager.h"
#include "AssetRegistryModule.h"
#include "Misc/App.h"
#include "Misc/FileHelper.h"
#include "ModInfo.h"
#include "StructsAndEnums.h"
#include "BaseGameInstance.generated.h"
/**
 * 
 */
/* Thank You Joseph for condensing this shit
   For Future Info, if you want to make any func Blueprintable add either
   UFUNCTION(BlueprintCallable, Category = "ModLoader")
   UFUNCTION(BlueprintPure)
   Depending on what it is
**/

UCLASS()
class MODDINGEXAMPLE_API UBaseGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	FPakPlatformFile* GetPakPlatformFile()
	{
		if (!PakPlatformFile)
		{
			IPlatformFile* CurrentPlatformFile = FPlatformFileManager::Get().FindPlatformFile(TEXT("PakFile"));
			if (CurrentPlatformFile)
			{
				PakPlatformFile = static_cast<FPakPlatformFile*>(CurrentPlatformFile);
			}
			else
			{
				PakPlatformFile = new FPakPlatformFile();
				ensure(PakPlatformFile != nullptr);
				IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
#if UE_BUILD_SHIPPING == 0
				OriginalPlatformFile = &PlatformFile;
#endif
				if (PakPlatformFile->Initialize(&PlatformFile, TEXT("")))
				{
					FPlatformFileManager::Get().SetPlatformFile(*PakPlatformFile);
				}
			}
		}
		ensure(PakPlatformFile != nullptr);
		return PakPlatformFile;
	}
	void ResetPlatformFile()
	{
#if UE_BUILD_SHIPPING == 0
		if (OriginalPlatformFile) { FPlatformFileManager::Get().SetPlatformFile(*OriginalPlatformFile); }
#endif
	}
		UFUNCTION(BlueprintCallable, Category = "ModLoader")
		bool IsValidPakFile(const FString& PakFilename, int64& OutPakSize, bool bSigned = false)
	{
		if (!FPaths::FileExists(PakFilename)) { return false; }
		FPakFile PakFile(GetPakPlatformFile(), *PakFilename, bSigned);
		if (!PakFile.IsValid()) { return false; }
		OutPakSize = PakFile.TotalSize();
		return true;
	}
	UFUNCTION(BlueprintCallable, Category = "ModLoader")
	bool MountPakFile(const FString& PakFilename, int32 PakOrder, const FString& MountPath)
	{
		bool bResult = false;
		if (MountPath.Len() > 0) { bResult = GetPakPlatformFile()->Mount(*PakFilename, PakOrder, *MountPath); }
		else { bResult = GetPakPlatformFile()->Mount(*PakFilename, PakOrder, NULL); }
		return bResult;
	}
	bool UnmountPakFile(const FString& PakFilename) { return GetPakPlatformFile()->Unmount(*PakFilename); }
	UFUNCTION(BlueprintPure)
		static UClass* LoadClassFromPak(const FString& Filename) {const FString Name = Filename + TEXT(".") + FPackageName::GetShortName(Filename) + TEXT("_C");return StaticLoadClass(UObject::StaticClass(), nullptr, *Name);}
	template<class T>
	T* LoadObjectFromPak(const FString& Filename)
	{
		const FString Name = T::StaticClass()->GetName() + TEXT("'") + Filename + TEXT(".") + FPackageName::GetShortName(Filename) + TEXT("'");
		return Cast<T>(StaticLoadObject(T::StaticClass(), nullptr, *Name));
	}

	UFUNCTION(BlueprintCallable, Category = "ModLoader")
		static bool GetFilesInRootAndAllSubFolders(TArray<FString>& Files, FString RootFolderFullPath, FString Ext);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Structs")
		TArray<FWeaponData> WeaponData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AssetRegistrySearchable, meta = (EditCondition = CustomLevels, HideEditConditionToggle), Category = "GameInfo")
		TArray <TSoftObjectPtr<UWorld>> LevelList;
	//List of all GameModes to be loaded
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameInfo")
		TArray<TSubclassOf<AGameModeBase>> GameModes;
	//List Of Loaded ModData
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameInfo")
		TArray<FModData> ModData;
	virtual void Init() override;
protected:
	FPakPlatformFile* PakPlatformFile = nullptr;
#if UE_BUILD_SHIPPING == 0
	IPlatformFile* OriginalPlatformFile = nullptr;
#endif
};