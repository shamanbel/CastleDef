// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <CoreMinimal.h>
#include <GameFramework/GameMode.h>
#include "CastleDef/Player/Items/CD_CombatBot.h"
#include "CastleDef/Enemy/CD_AIController.h"
#include "CD_GameMode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCD_CombatBotSpawn,ACD_CombatBot*, inCombatBot);
UCLASS()
class CASTLEDEF_API ACD_GameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	ACD_GameMode();
	virtual void StartPlay() override;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FCD_CombatBotSpawn OnCombatBotSpawn;

private:

};
