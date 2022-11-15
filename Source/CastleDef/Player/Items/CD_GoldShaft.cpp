


#include "CD_GoldShaft.h"
#include "CD_BaseCastle.h"
#include <Components/StaticMeshComponent.h>




ACD_GoldShaft::ACD_GoldShaft()
{
	PrimaryActorTick.bCanEverTick = false;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	SetRootComponent(StaticMesh);
}
void ACD_GoldShaft::BeginPlay()
{
	Super::BeginPlay();

	//GetWorldTimerManager().SetTimer(TimerPassiveEarnCastle, this, &ACD_GoldShaft::AddPassiveEarnCastle, IntervalPassiveEarning, true);
	
}
void ACD_GoldShaft::AddPassiveEarnCastle()
{

	
}

ECD_Team ACD_GoldShaft::GetTeam_Implementation()
{
	return TeamShaft;
}





