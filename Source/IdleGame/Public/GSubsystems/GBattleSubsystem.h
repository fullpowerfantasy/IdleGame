// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GBattleSubsystem.generated.h"


/**
 * 
 */
UCLASS()
class IDLEGAME_API UGBattleSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "Combat")
	void StartCombat(TArray<class UGChampionData*> PlayerParty, TArray<UGChampionData*> EnemyParty);

	UFUNCTION(BlueprintCallable, Category = "Combat")
	void NextTurn();

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Combat")
	TArray<UGChampionData*> TurnOrder;

	UPROPERTY(BlueprintReadOnly, Category = "Combat")
	int32 CurrentTurn;

	UPROPERTY(BlueprintReadOnly, Category = "Combat")
	bool bIsCombatActive;

	void BuildTurnOrder(TArray<UGChampionData*> PlayerParty, TArray<UGChampionData*> EnemyParty);

	void ExecuteTurn(UGChampionData* Champion);
};
