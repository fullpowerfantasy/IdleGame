// Fill out your copyright notice in the Description page of Project Settings.


#include "GWidgets/GChampionsMenuWidget.h"
#include "GWidgets/GChampionStatsWidget.h"
#include "Blueprint/WidgetTree.h"

void UGChampionsMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	//// Create the child widget
	//ChampionStatsWidget = CreateWidget<UGChampionStatsWidget>(GetOwningPlayer(), UGChampionStatsWidget::StaticClass());

	//// Add the child widget to the parent's widget tree
	//WidgetTree->RootWidget->AddChild(ChampionStatsWidget);

	// Perform any other setup here
}