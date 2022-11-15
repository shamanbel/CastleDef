// Fill out your copyright notice in the Description page of Project Settings.


#include "CastleDef/Data/CD_CombatBotDataBase.h"
#include <CastleDef/CD_Asset_Path.h>

UCD_CombatBotDataBase::UCD_CombatBotDataBase()
{

}

void UCD_CombatBotDataBase::Initialize(FSubsystemCollectionBase& InCollection)
{
	Super::Initialize(InCollection);

	DataTableCombatBot = LoadObject<UDataTable>(NULL, COMBAT_TABLE, NULL, LOAD_None, NULL);
	if (DataTableCombatBot == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to load globes database"));
	}
}

UDataTable* UCD_CombatBotDataBase::GetDatatableCombatBot()
{
	return DataTableCombatBot;
}

const FCD_DataCombatBot* UCD_CombatBotDataBase::GetDataByClass(TSubclassOf<UCD_BaseCombatBotID> inIdCombatBot)
{
	for (auto RowName : DataTableCombatBot->GetRowNames())
	{
		if (auto data = DataTableCombatBot->FindRow<FCD_DataCombatBot>(RowName, ""))
		{
			if (data->CombatBot_ID == inIdCombatBot)
			{
				return data;
			}
		}
	}
	return nullptr;
}

FCD_DataCombatBot UCD_CombatBotDataBase::GetDataByClassBP(TSubclassOf<UCD_BaseCombatBotID> inIdCombatBot)
{
	const FCD_DataCombatBot* data = GetDataByClass(inIdCombatBot);

	if (data == nullptr)
		return {};

	return *data;
}

