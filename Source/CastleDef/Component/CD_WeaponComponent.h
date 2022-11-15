// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <CoreMinimal.h>
#include <Components/ActorComponent.h>
#include "CastleDef/CD_CoreType.h"
#include "CD_WeaponComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CASTLEDEF_API UCD_WeaponComponent : public UActorComponent
{
	GENERATED_BODY()
public:	
	UCD_WeaponComponent();

	UFUNCTION(BlueprintCallable)
	FCD_WeaponType GetWeaponData(bool& outSuccess);
	
	

	UFUNCTION(BlueprintCallable)
	void InitializeWeaponType(TSubclassOf<UCD_BaseWeaponID> inWeaponID);

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UCD_BaseWeaponID> ID_Weapon = nullptr;
	
	const FCD_WeaponType* WeaponType = nullptr;

};
