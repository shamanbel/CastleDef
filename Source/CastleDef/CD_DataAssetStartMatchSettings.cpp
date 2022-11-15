// Fill out your copyright notice in the Description page of Project Settings.


#include "CD_DataAssetStartMatchSettings.h"
#include "CD_Asset_Path.h"


UCD_DataAssetStartMatchSettings* UCD_DataAssetStartMatchSettings::Load()
{
    return Cast<UCD_DataAssetStartMatchSettings>(StaticLoadObject(StaticClass(), nullptr, START_MATCH_SETTING));
}

// float UCD_DataAssetStartMatchSettings::GetMaxHealthCastle() const
// {
//     return MaxHealthCastle;
//}

float UCD_DataAssetStartMatchSettings::GetMatchTime() const
{
    return MatchTime;
}


