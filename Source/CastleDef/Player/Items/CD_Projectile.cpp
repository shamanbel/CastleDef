


#include "CD_Projectile.h"
#include "CD_Tower.h"
#include <Components/SphereComponent.h>
#include <GameFramework/ProjectileMovementComponent.h>
#include <kismet/GameplayStatics.h>
#include <AIController.h>

ACD_Projectile::ACD_Projectile()
{
 
	PrimaryActorTick.bCanEverTick = false;

	CollisionComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	CollisionComponent-> InitSphereRadius(10.0f);
	CollisionComponent-> SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CollisionComponent->SetCollisionResponseToChannels(ECollisionResponse::ECR_Block);
	SetRootComponent(CollisionComponent);

	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("MovementComponent");
	MovementComponent->InitialSpeed = 0.0f;
	MovementComponent->ProjectileGravityScale = 0.0f;
	
	DamageAmountProjectile = 30.0f;

}


void ACD_Projectile::BeginPlay()
{
	Super::BeginPlay();
	check(CollisionComponent);
	check(MovementComponent);
	
	MovementComponent->Velocity = ShotDirection * MovementComponent->InitialSpeed;
	MovementComponent->bIsHomingProjectile = true;
	MovementComponent->HomingTargetComponent = Target->GetRootComponent();
	
	CollisionComponent->OnComponentHit.AddDynamic(this, &ACD_Projectile::OnProjectileHit);
	SetLifeSpan(LifeSeconds);
	
}

void ACD_Projectile::OnProjectileHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
if(OtherActor == nullptr) return;
	MovementComponent->StopMovementImmediately();
	OtherActor->TakeDamage(DamageAmountProjectile, FDamageEvent{}, nullptr, this);
	Destroy();
}


