// Fill out your copyright notice in the Description page of Project Settings.


#include "GSubsystems/GBattleSubsystem.h"
#include "GChampion/GChampion.h"

void UGBattleSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	CurrentTurn = 0;
	bIsCombatActive = false;
}

void UGBattleSubsystem::StartCombat(TArray<UGChampion*> PlayerParty, TArray<UGChampion*> EnemyParty)
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

void UGBattleSubsystem::BuildTurnOrder(TArray<UGChampion*> PlayerParty, TArray<UGChampion*> EnemyParty)
{
	TurnOrder.Empty();

	TArray<UGChampion*> AllChampions;
	AllChampions.Append(PlayerParty);
	AllChampions.Append(EnemyParty);

	AllChampions.Sort([](const UGChampion& A, const UGChampion& B)
		{
			return A.ChampionData.SPD > B.ChampionData.SPD;
		});

	TurnOrder = AllChampions;
}

void UGBattleSubsystem::ExecuteTurn(UGChampion* Champion)
{
	// Implement your ability activation logic here, based on the Champion's abilities and the state of the battle
}
