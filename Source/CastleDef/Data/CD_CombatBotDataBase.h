// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <CoreMinimal.h>
#include <Engine/DataTable.h>
#include <Subsystems/GameInstanceSubsystem.h>
#include "CastleDef/CD_CoreType.h"
#include "CD_CombatBotDataBase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class CASTLEDEF_API UCD_CombatBotDataBase : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	UCD_CombatBotDataBase();

	virtual void Initialize(FSubsystemCollectionBase& InCollection) override;

public:
	UFUNCTION(BlueprintCallable)
	UDataTable* GetDatatableCombatBot();

	const FCD_DataCombatBot* GetDataByClass(TSubclassOf<UCD_BaseCombatBotID> inIdCombatBot);

	UFUNCTION(BlueprintCallable)
	FCD_DataCombatBot GetDataByClassBP(TSubclassOf<UCD_BaseCombatBotID> inIdCombatBot);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UDataTable* DataTableCombatBot = nullptr;
};

