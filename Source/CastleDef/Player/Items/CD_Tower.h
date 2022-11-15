

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CastleDef/Player/CD_GameCreature.h"
#include "CD_Tower.generated.h"

class UStaticMeshComponent;
class ACD_Projectile;
class ACD_CombatBot;
class USphereComponent;
class UCD_HealthComponent;
class UReloadComponent;

UCLASS()
class CASTLEDEF_API ACD_Tower : public AActor, public ICD_GameCreature
{
	GENERATED_BODY()
	
public:	
	
	ACD_Tower();

	UFUNCTION()
	float GetRadiusSphere() const {return RadiusSphereInteraction;}

	UFUNCTION(Category="TowerComponent")
	void Shot();

	virtual ECD_Team GetTeam_Implementation() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower", meta = (ClampMin = "1", ClampMax = "3"))
	int CurrentLevel = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Units = s))
	float TimeReload = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DamageAmountTower = 0.0f;

	
protected:
	
	virtual void BeginPlay() override;
	
	UFUNCTION()
	void BotsForAttack(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
	void RemoveCombatBot(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<ACD_Projectile> Projectile;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="TowerComponent")
	UStaticMeshComponent* StaticMesh = nullptr;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite,Category = "TowerComponent")
	USphereComponent* SphereInteraction = nullptr;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite,Category = "TowerComponent")
	UReloadComponent* ReloadComponent = nullptr;	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerComponent")
	float RadiusSphereInteraction = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "TowerComponent")
	UCD_HealthComponent* HealthComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TowerComponent")
	float MaxHealthTower = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
	ECD_Team TeamTower;

	//CombatBots inside SphereInteraction
	UPROPERTY()
	TArray<ACD_CombatBot*> CombatBotsForFight;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tower")
	int MaxLevel = 3;
	
private:
	
	
	
};





