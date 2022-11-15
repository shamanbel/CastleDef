

#pragma once

#include <CoreMinimal.h>
#include <Components/SphereComponent.h>
#include <GameFramework/Actor.h>

#include "CD_CombatBot.h"
#include "CD_Projectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class ACD_CombatBot;

UCLASS(Abstract)
class CASTLEDEF_API ACD_Projectile : public APawn
{
	GENERATED_BODY()
	
public:	
	
	ACD_Projectile();

	void SetShotDirection(const FVector& inDirection) {ShotDirection = inDirection;}

	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	USphereComponent* CollisionComponent = nullptr;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UProjectileMovementComponent* MovementComponent;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	float DamageAmountProjectile = 0.0f;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, meta = (Units =s))
	float LifeSeconds = 2.0f;
	
	UFUNCTION(BlueprintCallable)
	void SetTarget(AActor* inTarget){Target = inTarget;}

	UFUNCTION(BlueprintCallable)
	AActor* GetTarget(){return Target;}
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY()
	AActor* Target;
private:
	 FVector ShotDirection = {0,0,0,};

	

	UFUNCTION()
	void OnProjectileHit(UPrimitiveComponent* HitComponent,//
						AActor* OtherActor,//
						UPrimitiveComponent* OtherComp,//
						FVector NormalImpulse,//
						const FHitResult& Hit );

};
