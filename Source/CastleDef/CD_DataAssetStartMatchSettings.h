// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <CoreMinimal.h>
#include <Engine/DataAsset.h>
#include "CastleDef/CD_CoreType.h"
#include "CD_DataAssetStartMatchSettings.generated.h"


UCLASS(BlueprintType)
class CASTLEDEF_API UCD_DataAssetStartMatchSettings : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	static UCD_DataAssetStartMatchSettings* Load();

	UFUNCTION(BlueprintPure)
	float GetMatchTime() const;
	
protected:

	UPROPERTY(EditDefaultsOnly)
	float MatchTime = 1.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,  Category = "CombatBot")
	float RewardRatioMin = 1.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,  Category = "CombatBot")
	float RewardRatioMax = 1.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CombatBot")
	float BaseCostCombatBot = 0.0f;
	
};


