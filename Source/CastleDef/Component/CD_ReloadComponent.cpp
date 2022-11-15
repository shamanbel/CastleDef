
#include "CastleDef/Component/CD_ReloadComponent.h"
#include "CastleDef/Player/Items/CD_Tower.h"
#include <TimerManager.h>

UReloadComponent::UReloadComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UReloadComponent::BeginPlay()
{
	
	Super::BeginPlay();
	
}

void UReloadComponent::SetReloadTime(float InReloadTime, bool InImmediateStart)
{
	if(InReloadTime == 0.0f) return;
	m_ReloadTime = InReloadTime;
	
	if(InImmediateStart)
	{
		StartReload();
	}
}
void UReloadComponent::StartReload()
{
	GetOwner()->GetWorldTimerManager().ClearTimer(m_ReloadTimerHandle);
	GetOwner()->GetWorldTimerManager().SetTimer(m_ReloadTimerHandle, this, &UReloadComponent::FinishReload, m_ReloadTime, false);
	OnReloadStarted.Broadcast(m_ReloadTime);
	
}

void UReloadComponent::FinishReload()
{
	GetOwner()->GetWorldTimerManager().ClearTimer(m_ReloadTimerHandle);
	
	OnReloadFinished.Broadcast();
	
}

float UReloadComponent::GetRemainingTime()
{
	return m_ReloadTimerHandle.IsValid() ? GetOwner()->GetWorldTimerManager().GetTimerRemaining(m_ReloadTimerHandle) : 0;
}

float UReloadComponent::GetElapsedTime()
{
	return m_ReloadTimerHandle.IsValid() ? GetOwner()->GetWorldTimerManager().GetTimerElapsed(m_ReloadTimerHandle) : 0;
}

bool UReloadComponent::IsInCooldown()
{
	return GetOwner()->GetWorldTimerManager().IsTimerActive(m_ReloadTimerHandle);
}
float UReloadComponent::GetReloadTime()
{
	return m_ReloadTime;
}










