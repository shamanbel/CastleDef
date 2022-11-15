// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <CoreMinimal.h> 
#include <UObject/Interface.h>
#include "CastleDef/CD_CoreType.h"
#include "CD_GameCreature.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCD_GameCreature : public UInterface
{
	GENERATED_BODY()
};
class CASTLEDEF_API ICD_GameCreature
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	ECD_Team GetTeam();

	// UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	// FCD_WeaponType GetWeaponID();
};
