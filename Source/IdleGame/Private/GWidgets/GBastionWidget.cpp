// Fill out your copyright notice in the Description page of Project Settings.


#include "GWidgets/GBastionWidget.h"
#include "GSubsystems/GEventsSubsystem.h"
#include "Components/Button.h"

void UGBastionWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (ChampionsMenuButton)
	{
		ChampionsMenuButton->OnClicked.AddDynamic(this, &ThisClass::OnChampionsMenuButtonClicked);
	}

	if (SettingsMenuButton)
	{
		SettingsMenuButton->OnClicked.AddDynamic(this, &ThisClass::OnSettingsMenuButtonClicked);
	}
}

void UGBastionWidget::OnChampionsMenuButtonClicked()
{

	UGEventsSubsystem* Events = GetGameInstance()->GetSubsystem<UGEventsSubsystem>();
	if (Events)
	{
		Events->OnMenuRequested.Broadcast("ChampionsMenu");
	}
}

void UGBastionWidget::OnSettingsMenuButtonClicked()
{

	UGEventsSubsystem* Events = GetGameInstance()->GetSubsystem<UGEventsSubsystem>();
	if (Events)
	{
		Events->OnMenuRequested.Broadcast("SettingsMenu");
	}
}