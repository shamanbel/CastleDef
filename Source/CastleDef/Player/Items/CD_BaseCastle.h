// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <CoreMinimal.h>
#include <GameFramework/Actor.h>
#include "CD_CombatBot.h"
#include "CastleDef/CD_DataAssetStartMatchSettings.h"
#include "CastleDef/Player/CD_GameCreature.h"
#include "CD_BaseCastle.generated.h"



class UCD_HealthComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FCD_MoneyChanged, ECD_Team, inTeam, float, inPrevValue, float, inCurrentValue);

UCLASS()
class CASTLEDEF_API ACD_BaseCastle : public AActor, public ICD_GameCreature
{
	GENERATED_BODY()
	
public:	
	
	ACD_BaseCastle();
	
	
	UFUNCTION(BlueprintPure)
	float GetMoney() const {return MoneyCastle;}
	
	UFUNCTION(BlueprintCallable)
	void SetMoney(float inNewValue);
	
	UFUNCTION(BlueprintCallable)
	bool ChangeMoney(float inValue);
	
	virtual ECD_Team GetTeam_Implementation() override;

	// UPROPERTY(BlueprintReadWrite, Category = "BaseCastle")
	// float PassiveMoneyEarningCastle = 1.0f;

	UPROPERTY(BlueprintAssignable)
	FCD_MoneyChanged OnMoneyChanged; 
	
protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "BaseCastle")
	USceneComponent* Root = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "BaseCastle")
	UStaticMeshComponent* StaticMesh = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "BaseCastle")
	UCD_HealthComponent* HealthComponent;

	UPROPERTY(BlueprintReadOnly, Category = "BaseCastle")
	bool bHasTakenDamage = false;

	UPROPERTY(BlueprintReadOnly, Category = "BaseCastle")
	bool bIsCastleDestroy = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseCastle")
	ECD_Team TeamCastle;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "BaseCastle")
	float MaxHealthCastle = 0.0f;

	UPROPERTY(BlueprintReadWrite, Category = "BaseCastle", meta = (UIMin = "0", Min = "0"))
	float MoneyCastle = 0.0f;

	//To passive adding pointers to Player 
	// FTimerHandle TimerPassiveEarnCastle;

	UFUNCTION()
	void OnCombatBotSpawn (ACD_CombatBot* inCombatBot);
	
	UFUNCTION()
	void OnCombatBotDeath (ACD_CombatBot* inCombatBot);

};


