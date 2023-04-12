// Fill out your copyright notice in the Description page of Project Settings.


#include "GSubsystems/GGameDataSubsystem.h"
#include "GChampion/GChampion.h"


void UGGameDataSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	// TODO: Initialize champions and party, if needed
	LoadChampionsFromDataAssets(); // Load champions during initialization
}

void UGGameDataSubsystem::Deinitialize()
{
	// TODO: Deinitialize champions and party, if needed

	Super::Deinitialize();
}
// ...


void UGGameDataSubsystem::LoadChampionsFromDataAssets()
{
	for (UGChampion* ChampionData : ChampionDataAssets)
	{
		if (ChampionData)
		{
			//UGChampion* NewChampion = NewObject<UGChampion>(this);
			//NewChampion->ChampionName = ChampionData->ChampionName;
			//NewChampion->DisplayName = ChampionData->DisplayName;
			//NewChampion->Icon = ChampionData->Icon;
			//NewChampion->Stats = ChampionData->Stats;
			//// TODO: Assign other properties, such as equipment, skills, auras, and masteries

			//Champions.Add(ChampionData->ChampionName, NewChampion);
		}
	}
}
