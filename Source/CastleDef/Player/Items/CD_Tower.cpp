

#include "CD_Tower.h"
#include "CD_Projectile.h"
#include <Components/SphereComponent.h>
#include <Components/StaticMeshComponent.h>
#include "CastleDef/Component/CD_HealthComponent.h"
#include <AIController.h>
#include <Math/Vector.h>
#include "CD_CombatBot.h"
#include "CastleDef/Component/CD_ReloadComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

ACD_Tower::ACD_Tower()
{
 	
	PrimaryActorTick.bCanEverTick = false;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("TowerMesh");
	SetRootComponent(StaticMesh);
		
	SphereInteraction = CreateDefaultSubobject<USphereComponent>("SphereInteraction");
	SphereInteraction->SetupAttachment(StaticMesh);
	SphereInteraction->InitSphereRadius(RadiusSphereInteraction);
	SphereInteraction->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SphereInteraction->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);

	HealthComponent = CreateDefaultSubobject<UCD_HealthComponent>("HealthComponent");
	HealthComponent->SetHealth(MaxHealthTower);

	ReloadComponent = CreateDefaultSubobject<UReloadComponent>("ReloadComponent");
}

void ACD_Tower::BeginPlay()
{
	Super::BeginPlay();
	check(StaticMesh);
	check(HealthComponent);
	
	SphereInteraction->OnComponentBeginOverlap.AddDynamic(this, &ACD_Tower::BotsForAttack);
	SphereInteraction->OnComponentEndOverlap.AddDynamic(this, &ACD_Tower::RemoveCombatBot);

	HealthComponent->SetHealth(MaxHealthTower);
	HealthComponent->SetMaxHealth(MaxHealthTower);
	
	ReloadComponent -> SetReloadTime(TimeReload, false);
	
	ReloadComponent -> OnReloadFinished.AddDynamic(this, &ACD_Tower::Shot);
}

void ACD_Tower::BotsForAttack(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	//Add Bots are crossing SphereInteraction
	ACD_CombatBot*  actor_obj = Cast<ACD_CombatBot>(OtherActor);
	
	if(actor_obj == nullptr) return;
	
	if (actor_obj->Execute_GetTeam(OtherActor) != TeamTower)
	{
		CombatBotsForFight.Add(actor_obj);
		ReloadComponent->FinishReload();
		
	}
	
}

void ACD_Tower::Shot() 
{
	FVector start_point = this->GetActorLocation();
	if(CombatBotsForFight.Num() == 0) return;

	const FVector current_target_location = CombatBotsForFight[0]->GetActorLocation();
	start_point.Z += 250.0f;
	
	const FTransform start_location(FRotator::ZeroRotator, start_point);
	
	auto*  projectile_obj = GetWorld()->SpawnActorDeferred<ACD_Projectile>(Projectile, start_location);
	if (projectile_obj != nullptr)
	{
		const FVector direction = (current_target_location - start_point);
		projectile_obj->SetTarget(CombatBotsForFight[0]);
		
		projectile_obj->SetShotDirection(direction);
		projectile_obj->FinishSpawning(start_location);
	}
	ReloadComponent->StartReload();
}

ECD_Team ACD_Tower::GetTeam_Implementation()
{
	return TeamTower;
}

void ACD_Tower::RemoveCombatBot(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	ACD_CombatBot*  actor_obj = Cast<ACD_CombatBot>(OtherActor);

	 CombatBotsForFight.Remove(actor_obj);
}


//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Black, ActorObj->GetName());
//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Black, TargetLocation.ToString());