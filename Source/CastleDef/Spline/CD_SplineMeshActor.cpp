// Fill out your copyright notice in the Description page of Project Settings.

#include "CastleDef/Spline/CD_SplineMeshActor.h"
#include <Components/SplineComponent.h>




ACD_SplineMeshActor::ACD_SplineMeshActor()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	Spline = CreateDefaultSubobject<USplineComponent>(TEXT("Spline"));
	Spline->SetupAttachment(Root);
	Spline->bDrawDebug = true;
}

void ACD_SplineMeshActor::BeginPlay()
{
}

void ACD_SplineMeshActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

