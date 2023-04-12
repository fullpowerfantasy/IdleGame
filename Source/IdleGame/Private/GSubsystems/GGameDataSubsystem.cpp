// Fill out your copyright notice in the Description page of Project Settings.


#include "GSubsystems/GGameDataSubsystem.h"
#include "GChampions/GChampionData.h"


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
	for (UGChampionData* ChampionData : ChampionDataAssets)
	{
		if (ChampionData)
		{
			UGChampionData* NewChampion = NewObject<UGChampionData>(this);
			NewChampion->ChampionName = ChampionData->ChampionName;
			NewChampion->DisplayName = ChampionData->DisplayName;
			NewChampion->Icon = ChampionData->Icon;
			NewChampion->Stats = ChampionData->Stats;
			// TODO: Assign other properties, such as equipment, skills, auras, and masteries

			Champions.Add(ChampionData->ChampionName, NewChampion);
		}
	}
}
