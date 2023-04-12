// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GChampionsMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class IDLEGAME_API UGChampionsMenuWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UGChampionStatsWidget* ChampionStatsWidget;
};
