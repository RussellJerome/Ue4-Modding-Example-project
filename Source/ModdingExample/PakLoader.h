#pragma once

#include "CoreMinimal.h"
#include "Runtime/PakFile/Public/IPlatformFilePak.h"
#include "HAL/PlatformFilemanager.h"
#include "Misc/PackageName.h"

class MODDINGEXAMPLE_API FPakLoaderFileVisitor : public IPlatformFile::FDirectoryVisitor
{
public:
	virtual bool Visit(const TCHAR* FilenameOrDirectory, bool bIsDirectory) override
	{
		if (!bIsDirectory)
		{
			Files.Add(FilenameOrDirectory);
		}
		return true;
	}

	TArray<FString> Files;
};

class MODDINGEXAMPLE_API FPakLoader
{
public:
	FPakPlatformFile *GetPakPlatformFile();
	static FPakLoader *Get();
	template<class T>
	T *LoadObjectFromPak(const FString &Filename)
	{
		const FString Name = T::StaticClass()->GetName() + TEXT("'") + Filename + TEXT(".") + FPackageName::GetShortName(Filename) + TEXT("'");
		return Cast<T>(StaticLoadObject(T::StaticClass(), nullptr, *Name));
	}
	UClass *LoadClassFromPak(const FString &Filename);
	void RegisterMountPoint(const FString& RootPath, const FString& ContentPath);
	void UnRegisterMountPoint(const FString& RootPath, const FString& ContentPath);

private:
	static FPakLoader *Instance;

};