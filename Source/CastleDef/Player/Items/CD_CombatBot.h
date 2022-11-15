// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <CoreMinimal.h>
#include <GameFramework/Pawn.h>
#include "CastleDef/CD_CoreType.h"
#include "CastleDef/Player/CD_GameCreature.h"
#include "GameFramework/Character.h"
#include "CD_CombatBot.generated.h"


class ACD_CombatBot;
class UCD_WeaponComponent;
class UCD_HealthComponent;
class USphereComponent;
class UReloadComponent;
class ACD_Projectile;


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCD_CombatBotDeath,ACD_CombatBot*, inCombatBot);
UCLASS()
class CASTLEDEF_API ACD_CombatBot : public APawn, public ICD_GameCreature
{
	GENERATED_BODY()
	
public:	
	ACD_CombatBot();
	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CombatBot")
	bool bIsCombatBotDestroy = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "CombatBot")
	float MaxHealthCombatBot = 100.0f;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	FCD_WeaponType WeaponClassID;

	UFUNCTION(BlueprintCallable)
	float GetReward();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CombatBot")
	TSubclassOf<UCD_BaseCombatBotID> BotID = nullptr;

	//Money to Castle for destroy combatBot
	UPROPERTY(BlueprintAssignable)
	FCD_CombatBotDeath OnCombatBotDeath;
	
protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	USceneComponent* DefaultRoot = nullptr;
	
	// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ComponentCombatBot")
	// UStaticMeshComponent* StaticMeshBot = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ComponentCombatBot")
	UCD_HealthComponent* HealthComponent = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ComponentCombatBot")
	USkeletalMeshComponent* SkeletalMesh = nullptr;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ComponentCombatBot")
	UReloadComponent* ReloadComponent = nullptr;
	
	UPROPERTY(VisibleAnywhere, Category = "ComponentCombatBot")
	USphereComponent* SphereInteraction = nullptr;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ComponentCombatBot")
	UCD_WeaponComponent* WeaponComponent = nullptr;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "CombatBot")
	bool bCanMoveCombatBot = true;

	 UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CombatBot")
	 float KillRewardCombatBot = 0.0f;

	//The range of collision CombatBot 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CombatBot")
	float RadiusSphereInteraction = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CombatBot")
	ECD_Team TeamCombatBot;

	virtual ECD_Team GetTeam_Implementation() override;


	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category = "CombatBot")
	bool bIsShootingProjectile =false;
	
	UFUNCTION()
	void ActorsForAttack(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	//Enemy actors inside SphereInteraction
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TArray<AActor*> ActorsTarget;

	UFUNCTION(BlueprintCallable, Category = "CombatBot")
	void ShotProjectile();
	
	UFUNCTION(Category = "CombatBot")
    void RemoveCombatBot(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<ACD_Projectile> Projectile;

};
