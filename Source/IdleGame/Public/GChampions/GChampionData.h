// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GDataTypes/GDataTypes.h"
#include "GChampionData.generated.h"

/**
 * 
 */
UCLASS()
class IDLEGAME_API UGChampionData : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Champion")
	FName ChampionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Champion")
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Champion")
	UTexture2D* Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	TMap<FName, FGCharacterStat> Stats;
};
