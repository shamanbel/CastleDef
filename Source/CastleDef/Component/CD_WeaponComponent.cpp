// Fill out your copyright notice in the Description page of Project Settings.


#include "CD_WeaponComponent.h"
#include "CastleDef/Data/CD_WeaponDatabase.h"

// Sets default values for this component's properties
UCD_WeaponComponent::UCD_WeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


void UCD_WeaponComponent::BeginPlay()
{
	Super::BeginPlay();
}

FCD_WeaponType UCD_WeaponComponent::GetWeaponData(bool& outSuccess)
{
	if (WeaponType != nullptr)
	{
		return *WeaponType;
	}
	return FCD_WeaponType{};
}

void UCD_WeaponComponent::InitializeWeaponType(TSubclassOf<UCD_BaseWeaponID> inWeaponID)
{
	UGameInstance* const GameInstance = nullptr;
	UCD_WeaponDatabase* weapon_database = GameInstance->GetSubsystem<UCD_WeaponDatabase>();
	WeaponType = weapon_database->GetDataByClass(ID_Weapon);
}


