// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GDataTypes/GDataTypes.h"
#include "GChampion.generated.h"

/**
 * 
 */
UCLASS()
class IDLEGAME_API UGChampion : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Champion Data")
	FGChampionData ChampionData;
};
