// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <CoreMinimal.h>
#include <Components/ActorComponent.h>
#include "CD_HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )

class CASTLEDEF_API UCD_HealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCD_HealthComponent();
	
	UFUNCTION(BlueprintCallable)
	float GetHealth() const {return Health;}

	UFUNCTION(BlueprintCallable)
	void SetHealth(float inHealth) {Health = inHealth;}
	
	UFUNCTION(BlueprintCallable)
	void SetMaxHealth(float inHealth) {MaxHealth = inHealth;}

	UFUNCTION(BlueprintCallable)
	void OnTakeAnyDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser) ;
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Heal")
	bool bAutoHeal = true;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Heal")
	float UpdateTime = 0.0f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Heal")
	float HealDelay = 0.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Heal")
	float HealthModifier = 0.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HealthComponent")
	float MaxHealth = 0.0f;
	
private:
	
	float Health = 0.0f;

	FTimerHandle HealTimerHandle;

	UFUNCTION()
	void HealUpdate();
	
		
};
