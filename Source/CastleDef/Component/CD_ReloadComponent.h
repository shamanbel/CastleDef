
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CD_ReloadComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCD_ReloadStarted, float, Duration);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCD_ReloadFinished);

DECLARE_DYNAMIC_MULTICAST_DELEGATE (FCD_CommandForAttack);

UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CASTLEDEF_API UReloadComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	
	UReloadComponent();
	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="GetReloadTime"), Category="ReloadComponent")
	float GetReloadTime();

	UFUNCTION(BlueprintCallable, Category="ReloadComponent")
	void SetReloadTime(float InReloadTime, bool InImmediateStart);

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="GetRemainingTime"), Category="ReloadComponent")
	float GetRemainingTime();

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="GetElapsedTime"), Category="ReloadComponent")
	float GetElapsedTime();

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="InReload"), Category="ReloadComponent")
	bool IsInCooldown();

	UFUNCTION(BlueprintCallable, Category="ReloadComponent")
	void StartReload();
	
	UFUNCTION(BlueprintCallable, Category="ReloadComponent")
	void FinishReload();

	UPROPERTY(BlueprintReadOnly, BlueprintCallable, BlueprintAssignable, Category="ReloadComponent")
	FCD_ReloadStarted OnReloadStarted;

	UPROPERTY(BlueprintReadOnly, BlueprintCallable, BlueprintAssignable, Category="ReloadComponent")
	FCD_ReloadFinished OnReloadFinished;
	
	UPROPERTY()
	float Timer =0.0f;

protected:
	
	virtual void BeginPlay() override;
	
private:
	
	// UFUNCTION()
	// void TimerFinish_Handler();

	
	float m_ReloadTime = 0.0f;

	UPROPERTY()
	FTimerHandle m_ReloadTimerHandle = FTimerHandle();
			
};
