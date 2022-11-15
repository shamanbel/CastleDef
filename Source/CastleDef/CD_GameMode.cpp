// Fill out your copyright notice in the Description page of Project Settings.


#include "CD_GameMode.h"
#include "Player/Items/CD_BaseCastle.h"
#include "CD_PlayerController.h"
#include "Enemy/CD_AIController.h"
#include "Player/CD_PlayerState.h"



ACD_GameMode::ACD_GameMode()
{
	DefaultPawnClass = ACD_BaseCastle::StaticClass();
	PlayerControllerClass = ACD_PlayerController::StaticClass();

	PlayerStateClass = ACD_PlayerState::StaticClass();
}

void ACD_GameMode::StartPlay()
{
	Super::StartPlay();

}



