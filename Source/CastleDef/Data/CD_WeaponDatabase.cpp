// Fill out your copyright notice in the Description page of Project Settings.


#include "CastleDef/Data/CD_WeaponDatabase.h"
#include <CastleDef/CD_Asset_Path.h>



UCD_WeaponDatabase::UCD_WeaponDatabase()
{
	
}

void UCD_WeaponDatabase::Initialize(FSubsystemCollectionBase& InCollection)
{
	Super::Initialize(InCollection);

	DataTableWeapon = LoadObject<UDataTable>(NULL, WEAPON_TABLE, NULL, LOAD_None, NULL);
	if (DataTableWeapon == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to load globes database"));
	}
}

UDataTable* UCD_WeaponDatabase::GetDatatableWeapon()
{
	return DataTableWeapon;
}

const FCD_WeaponType* UCD_WeaponDatabase::GetDataByClass(TSubclassOf<UCD_BaseWeaponID> inIdWeapon)
{
	for (auto RowName : DataTableWeapon->GetRowNames())
	{
		if (auto data = DataTableWeapon->FindRow<FCD_WeaponType>(RowName, ""))
		{
			if (data->ID_Weapon == inIdWeapon)
			{
				return data;
			}
		}
	}
	return nullptr;
}

FCD_WeaponType UCD_WeaponDatabase::GetDataByClassBP(TSubclassOf<UCD_BaseWeaponID> inIdWeapon)
{
	const FCD_WeaponType* data= GetDataByClass(inIdWeapon);

	if (data == nullptr) 
	return {};

	return *data;
}
