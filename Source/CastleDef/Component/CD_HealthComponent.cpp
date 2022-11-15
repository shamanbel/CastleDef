


#include "CD_HealthComponent.h"
#include <GameFramework/Actor.h>
#include "CastleDef/Player/Items/CD_BaseCastle.h"
#include <TimerManager.h>
#include <Engine/World.h>


UCD_HealthComponent::UCD_HealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	HealDelay = 10.0f;
	
}

void UCD_HealthComponent::BeginPlay()
{
	Super::BeginPlay();
	
	AActor* component_owner = GetOwner();
	if (component_owner != nullptr)
	{
		component_owner->OnTakeAnyDamage.AddDynamic(this,&UCD_HealthComponent::OnTakeAnyDamage);
	
	}
}

void UCD_HealthComponent::OnTakeAnyDamage( AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser )
{
	const float out_health = FMath::Clamp(Health - Damage, 0.0f,MaxHealth);
	SetHealth(out_health);
	GetWorld()->GetTimerManager().ClearTimer(HealTimerHandle);
	if (out_health == 0.0f)
	{
		ACD_CombatBot* obj = Cast<ACD_CombatBot>(GetOwner());
		if(obj != nullptr )
		{
			obj->OnCombatBotDeath.Broadcast(obj);
		}
		GetOwner()->Destroy();
	}
	else if (bAutoHeal)
	{
		GetWorld()->GetTimerManager().SetTimer(HealTimerHandle,this,&UCD_HealthComponent::HealUpdate, UpdateTime,true,HealDelay);
	}
}

void UCD_HealthComponent::HealUpdate()
{
	const float out_health = FMath::Min(Health+HealthModifier, MaxHealth);
	SetHealth(out_health);
	if(out_health == MaxHealth)
	{
		GetWorld()->GetTimerManager().ClearTimer(HealTimerHandle);
	}
}



