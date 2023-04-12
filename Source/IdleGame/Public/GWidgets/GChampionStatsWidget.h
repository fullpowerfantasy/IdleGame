// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GChampionStatsWidget.generated.h"

/**
 * 
 */
UCLASS()
class IDLEGAME_API UGChampionStatsWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, Category = "Champion")
	class UGChampion* Champion;

	UPROPERTY(meta = (BindWidget), EditAnywhere, BlueprintReadOnly, Category = "Champion Stats")
	class UTextBlock* HPText;

	UPROPERTY(meta = (BindWidget), EditAnywhere, BlueprintReadOnly, Category = "Champion Stats")
	UTextBlock* ATKText;

	// Add other UTextBlock declarations for each stat here

protected:
	virtual void NativeConstruct() override;

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	void UpdateTextWidgets();

};
