// Fill out your copyright notice in the Description page of Project Settings.


#include "CD_CombatBot.h"
#include "CD_BaseCastle.h"
#include "CD_Projectile.h"
#include <Components/SphereComponent.h>
//#include <Components/StaticMeshComponent.h>
#include <Components/SkeletalMeshComponent.h>
#include "CastleDef/Component/CD_WeaponComponent.h"
#include "CastleDef/Component/CD_HealthComponent.h"
#include "CastleDef/Component/CD_ReloadComponent.h"
#include <Kismet/GameplayStatics.h>

#include "GameFramework/CharacterMovementComponent.h"


ACD_CombatBot::ACD_CombatBot()
{
	PrimaryActorTick.bCanEverTick = false;

	DefaultRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultRoot"));
	SetRootComponent(DefaultRoot);
	
	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>("SkeletalMesh");
	SkeletalMesh->SetupAttachment(DefaultRoot);
		
	SphereInteraction = CreateDefaultSubobject<USphereComponent>("SphereInteraction");
	SphereInteraction->SetupAttachment(SkeletalMesh);
	SphereInteraction->InitSphereRadius(RadiusSphereInteraction);
	SphereInteraction->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereInteraction->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	
	WeaponComponent = CreateDefaultSubobject<UCD_WeaponComponent>("WeaponComponent");
	
	HealthComponent = CreateDefaultSubobject<UCD_HealthComponent>("HealthComponent");
	HealthComponent->SetHealth(MaxHealthCombatBot);

	ReloadComponent = CreateDefaultSubobject<UReloadComponent>("ReloadComponent");
}

void ACD_CombatBot::BeginPlay()
{
	Super::BeginPlay();
	
	check(HealthComponent);
	
	HealthComponent->SetHealth(MaxHealthCombatBot);
	HealthComponent->SetMaxHealth(MaxHealthCombatBot);
	

}

void ACD_CombatBot::ActorsForAttack(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//Add Bots are crossing SphereInteraction
	auto*  combat_bot_obj = Cast<ACD_CombatBot>(OtherActor);
	
	if(combat_bot_obj == nullptr) return;
	
	if (combat_bot_obj->Execute_GetTeam(OtherActor) != TeamCombatBot)
	{
		ActorsTarget.Add(combat_bot_obj);
		
	}
}

void ACD_CombatBot::ShotProjectile()
{
	//Spawn Projectile for shot
	if(ActorsTarget.Num() == 0) return;
	const FVector current_target_location = ActorsTarget[0]->GetActorLocation();
	
    	FVector start_point = this->GetActorLocation();
    	start_point.Z += 250.0f;
	
	const FTransform start_location(FRotator::ZeroRotator, start_point);
	
	auto*  projectile_obj = GetWorld()->SpawnActorDeferred<ACD_Projectile>(Projectile, start_location);
	if (projectile_obj != nullptr)
	{
		const FVector direction = (current_target_location - start_point);
		
		projectile_obj->SetTarget(ActorsTarget[0]);
		projectile_obj->SetShotDirection(direction);
		projectile_obj->FinishSpawning(start_location);
	}

}

void ACD_CombatBot::RemoveCombatBot(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	ACD_CombatBot*  actor_obj = Cast<ACD_CombatBot>(OtherActor);
	
	ActorsTarget.Remove(actor_obj);
}

ECD_Team ACD_CombatBot::GetTeam_Implementation()
{
	return TeamCombatBot;
}

float ACD_CombatBot::GetReward()
{
	return KillRewardCombatBot;
}
