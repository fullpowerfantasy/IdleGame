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
	void StartCombat(TArray<class UGChampion*> PlayerParty, TArray<UGChampion*> EnemyParty);

	UFUNCTION(BlueprintCallable, Category = "Combat")
	void NextTurn();

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Combat")
	TArray<UGChampion*> TurnOrder;

	UPROPERTY(BlueprintReadOnly, Category = "Combat")
	int32 CurrentTurn;

	UPROPERTY(BlueprintReadOnly, Category = "Combat")
	bool bIsCombatActive;

	void BuildTurnOrder(TArray<UGChampion*> PlayerParty, TArray<UGChampion*> EnemyParty);

	void ExecuteTurn(UGChampion* Champion);
};
