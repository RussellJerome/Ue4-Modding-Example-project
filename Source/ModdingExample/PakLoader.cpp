#include "PakLoader.h"
#include "Runtime/Core/Public/Serialization/ArrayReader.h"
#include "Runtime/AssetRegistry/Public/AssetRegistryModule.h"
#include "Misc/App.h"
#include "Misc/FileHelper.h"

FPakLoader *FPakLoader::Instance = nullptr;

FPakLoader *FPakLoader::Get()
{
	if (!Instance)
	{
		Instance = new FPakLoader();
	}

	return Instance;
}

UClass *FPakLoader::LoadClassFromPak(const FString &Filename)
{
	const FString Name = Filename + TEXT(".") + FPackageName::GetShortName(Filename) + TEXT("_C");
	return StaticLoadClass(UObject::StaticClass(), nullptr, *Name);
}

void FPakLoader::RegisterMountPoint(const FString& RootPath, const FString& ContentPath)
{
	FPackageName::RegisterMountPoint(RootPath, ContentPath);
}

void FPakLoader::UnRegisterMountPoint(const FString& RootPath, const FString& ContentPath)
{
	FPackageName::UnRegisterMountPoint(RootPath, ContentPath);
}