
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CastleDef/Player/CD_GameCreature.h"
#include "CD_GoldShaft.generated.h"

class UStaticMeshComponent;

UCLASS()
class CASTLEDEF_API ACD_GoldShaft : public AActor,public ICD_GameCreature
{
	GENERATED_BODY()

public:

	ACD_GoldShaft();

	UFUNCTION(BlueprintCallable)
	void AddPassiveEarnCastle();

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category = "Shaft",Category = "Shaft",meta = (UIMin = "1", Min = "1"))
	float PassiveMoneyEarningCastle = 0.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Shaft",meta = (UIMin = "1", Min = "1"))
	float IntervalPassiveEarning = 0.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Shaft")
	bool bCanPassiveEarning = true;
	
	//To passive adding pointers to Player 
	FTimerHandle TimerPassiveEarnCastle;

	virtual ECD_Team GetTeam_Implementation() override;

protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shaft")
	ECD_Team TeamShaft;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="TowerComponent")
	UStaticMeshComponent* StaticMesh = nullptr;





};
