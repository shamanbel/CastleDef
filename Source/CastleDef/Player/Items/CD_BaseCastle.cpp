// Fill out your copyright notice in the Description page of Project Settings.


#include "CD_BaseCastle.h"
#include "CD_CombatBot.h"
#include <Components/StaticMeshComponent.h>
#include "CastleDef/Component/CD_HealthComponent.h"
#include <Engine.h>
#include "CastleDef/CD_GameMode.h"
#include "Kismet/GameplayStatics.h"


ACD_BaseCastle::ACD_BaseCastle()
{
	PrimaryActorTick.bCanEverTick = false;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMesh->SetupAttachment(GetRootComponent());

	HealthComponent = CreateDefaultSubobject<UCD_HealthComponent>("HealthComponent");
	
}

void ACD_BaseCastle::BeginPlay()
{
	Super::BeginPlay();

	MoneyCastle = 200.0f;
	HealthComponent->SetHealth(MaxHealthCastle);
	HealthComponent->SetMaxHealth(MaxHealthCastle);
	ACD_GameMode* game_mode = Cast <ACD_GameMode>(UGameplayStatics::GetGameMode(this));
	if (game_mode != nullptr)
	{
		game_mode->OnCombatBotSpawn.AddDynamic(this,&ACD_BaseCastle::OnCombatBotSpawn);
	}
}

void ACD_BaseCastle::OnCombatBotSpawn(ACD_CombatBot* inCombatBot)
{	
	if(ICD_GameCreature::Execute_GetTeam(this) != ICD_GameCreature::Execute_GetTeam(inCombatBot))
	{
		inCombatBot->OnCombatBotDeath.AddDynamic(this, &ACD_BaseCastle::OnCombatBotDeath);
	}
}

void ACD_BaseCastle::OnCombatBotDeath(ACD_CombatBot* inCombatBot)
{
		const float reward = inCombatBot->GetReward();
		ChangeMoney(reward);
}

bool ACD_BaseCastle::ChangeMoney(float inValue)
{
	if (inValue >= 0.0f)
	{
		inValue += MoneyCastle;
		SetMoney(inValue);
		return true;
	}
	if (MoneyCastle > abs(inValue))
	{
		const float value_change = MoneyCastle + inValue;
		SetMoney(value_change);
		return true;
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Your castle don_t have money");
		return false;
	}
}

ECD_Team ACD_BaseCastle::GetTeam_Implementation()
{
	return TeamCastle;
}

void ACD_BaseCastle::SetMoney(float inNewValue)
{
	MoneyCastle = inNewValue >= 0 ? inNewValue : 0;
	
	const float prev_money = MoneyCastle;

	OnMoneyChanged.Broadcast(TeamCastle, prev_money, MoneyCastle);
}

