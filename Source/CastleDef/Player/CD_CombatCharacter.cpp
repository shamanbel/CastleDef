// Fill out your copyright notice in the Description page of Project Settings.


#include "CastleDef/Player/CD_CombatCharacter.h"

// Sets default values
ACD_CombatCharacter::ACD_CombatCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACD_CombatCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACD_CombatCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACD_CombatCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

