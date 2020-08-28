#pragma once
#include "Styling/SlateColor.h"
#include "MainWeapon.h"
#include "StructsAndEnums.generated.h"
UENUM(BlueprintType)
enum EWeaponCategory
{
	WEP_Pistol	UMETA(Displayname = "Pistol"),
	WEP_ShotGun	UMETA(Displayname = "ShotGun"),
	WEP_AssaultRifle	UMETA(Displayname = "AssaultRifle"),
	WEP_Sniper	UMETA(Displayname = "Sniper")
};



USTRUCT(BlueprintType)
struct FWeaponData
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Data")
		FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Data")
		FString Desc;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Data")
		TEnumAsByte <EWeaponCategory> Category;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Data")
		int32 Damage;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Data")
		TSubclassOf<AMainWeapon> WeaponClass;
};