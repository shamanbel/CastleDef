// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <CoreMinimal.h>
#include <GameFramework/Actor.h>
#include "CD_SplineMeshActor.generated.h"


UCLASS()
class CASTLEDEF_API ACD_SplineMeshActor : public AActor
{
	GENERATED_BODY()

public:

	ACD_SplineMeshActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spline")
	USceneComponent* Root = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Spline")
	class USplineComponent* Spline = nullptr;
	
	bool bCanMoveActor = true;

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
