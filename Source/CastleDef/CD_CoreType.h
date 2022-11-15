#pragma once

#include <Engine/DataTable.h>
#include "CastleDef/Weapon/CD_BaseWeaponID.h"
#include "CastleDef/Player/CD_BaseCombatBotID.h"
#include "CD_CoreType.generated.h"


UENUM(BlueprintType)
enum class ECD_TypeCombatBot : uint8
{
	MeleeCombat		UMETA(DisplayName = "MeleeCombat"),
	RangeCombat		UMETA(DisplayName = "RangeCombat"),
	Vehicles 		UMETA(DisplayName = "Vehicles"),
	Artillery 		UMETA(DisplayName = "Artillery"),
};

USTRUCT(BlueprintType)
struct FCD_DataCombatBot : public FTableRowBase
{
	GENERATED_BODY();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<AActor> SpawnActorClass = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<UCD_BaseCombatBotID> CombatBot_ID = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<UCD_BaseWeaponID> Weapon_ID = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	ECD_TypeCombatBot  TypeCombatBot;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CombatBot", meta = (UIMin = "0", Min = "0"))
	float RatioCostCombatBot = 1.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "CombatBot")
	float VelocityCombatBot = 1.0f;



};

USTRUCT(BlueprintType, Category = "Weapon")
struct FCD_WeaponType : public FTableRowBase
{
	GENERATED_BODY();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<UCD_BaseWeaponID> ID_Weapon = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UTexture* IconsWeapon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,meta = (UIMin = "0", Min = "0"))
	float Damage = 0.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (UIMin = "1", Min = "1"))
	float ReloadTime = 1.0f;
};



UENUM(BlueprintType)
enum class ECD_Team : uint8
{
	None 		UMETA(DisplayName = "None"),
	Team1 		UMETA(DisplayName = "Team1"),
	Team2 		UMETA(DisplayName = "Team2"),
};