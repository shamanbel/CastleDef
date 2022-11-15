// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <CoreMinimal.h>
#include <Engine/DataTable.h>
#include <Subsystems/GameInstanceSubsystem.h>
#include "CastleDef/CD_CoreType.h"
#include "CD_WeaponDatabase.generated.h"


UCLASS(Blueprintable, BlueprintType)
class CASTLEDEF_API UCD_WeaponDatabase : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
	UCD_WeaponDatabase();

	virtual void Initialize(FSubsystemCollectionBase& InCollection) override;
	
public:

	UFUNCTION(BlueprintCallable)
	UDataTable* GetDatatableWeapon();

	const FCD_WeaponType* GetDataByClass(TSubclassOf<UCD_BaseWeaponID> inIdWeapon);

	UFUNCTION(BlueprintCallable)
	FCD_WeaponType GetDataByClassBP(TSubclassOf<UCD_BaseWeaponID> inIdWeapon);

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UDataTable* DataTableWeapon = nullptr;
};
