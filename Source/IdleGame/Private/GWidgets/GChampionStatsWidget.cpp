// Fill out your copyright notice in the Description page of Project Settings.


#include "GWidgets/GChampionStatsWidget.h"
#include "GChampion/GChampion.h"
#include "Components/TextBlock.h"

void UGChampionStatsWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// Initialize HPText and set its binding function
	HPText = NewObject<UTextBlock>(this);
	HPText->SetText(FText::FromString("HP: "));
	HPText->SetColorAndOpacity(FSlateColor(FLinearColor::White));

	// Initialize ATKText and set its binding function
	ATKText = NewObject<UTextBlock>(this);
	ATKText->SetText(FText::FromString("ATK: "));
	ATKText->SetColorAndOpacity(FSlateColor(FLinearColor::White));

	// Add other text widget initializations and set their binding functions here
}

void UGChampionStatsWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	UpdateTextWidgets();
}

void UGChampionStatsWidget::UpdateTextWidgets()
{
	if (HPText && Champion)
	{
		//HPText->SetText(FText::FromString(FString::Printf(TEXT("HP: %d"), ChampionData->HP)));
	}

	if (ATKText && Champion)
	{
		//ATKText->SetText(FText::FromString(FString::Printf(TEXT("ATK: %d"), ChampionData->ATK)));
	}

	// Update other text widgets here
}