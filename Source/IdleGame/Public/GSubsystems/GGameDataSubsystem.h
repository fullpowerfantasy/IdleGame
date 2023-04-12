// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GDataTypes/GDataTypes.h"
#include "GGameDataSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class IDLEGAME_API UGGameDataSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	// Initialize the subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	// Deinitialize the subsystem
	virtual void Deinitialize() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Champions")
	TMap<FName, class UGChampionData*> Champions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
	TArray<FName> Party;

	UPROPERTY(EditDefaultsOnly, Category = "Champions")
	TArray<UGChampionData*> ChampionDataAssets;

	UFUNCTION(BlueprintCallable, Category = "Champions")
	void LoadChampionsFromDataAssets();
	// TODO: Add functions to manage champions and party
};