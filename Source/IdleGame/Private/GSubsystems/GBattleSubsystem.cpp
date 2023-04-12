// Fill out your copyright notice in the Description page of Project Settings.


#include "GSubsystems/GBattleSubsystem.h"
#include "GChampions/GChampionData.h"

void UGBattleSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	CurrentTurn = 0;
	bIsCombatActive = false;
}

void UGBattleSubsystem::StartCombat(TArray<UGChampionData*> PlayerParty, TArray<UGChampionData*> EnemyParty)
{
	CurrentTurn = 0;
	bIsCombatActive = true;
	BuildTurnOrder(PlayerParty, EnemyParty);
	NextTurn();
}

void UGBattleSubsystem::NextTurn()
{
	if (!bIsCombatActive)
	{
		return;
	}

	ExecuteTurn(TurnOrder[CurrentTurn]);

	CurrentTurn = (CurrentTurn + 1) % TurnOrder.Num();
}

void UGBattleSubsystem::BuildTurnOrder(TArray<UGChampionData*> PlayerParty, TArray<UGChampionData*> EnemyParty)
{
	TurnOrder.Empty();

	TArray<UGChampionData*> AllChampions;
	AllChampions.Append(PlayerParty);
	AllChampions.Append(EnemyParty);

	AllChampions.Sort([](const UGChampionData& A, const UGChampionData& B)
		{
			return A.Stats.FindChecked("SPD").CurrentValue > B.Stats.FindChecked("SPD").CurrentValue;
		});

	TurnOrder = AllChampions;
}

void UGBattleSubsystem::ExecuteTurn(UGChampionData* Champion)
{
	// Implement your ability activation logic here, based on the Champion's abilities and the state of the battle
}
