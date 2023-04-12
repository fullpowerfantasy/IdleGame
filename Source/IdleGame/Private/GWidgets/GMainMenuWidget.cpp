// Fill out your copyright notice in the Description page of Project Settings.


#include "GWidgets/GMainMenuWidget.h"
#include "Components/Button.h"
#include "GSubsystems/GEventsSubsystem.h"

void UGMainMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();
	if (StartGameButton)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Binding button delegate")));
		}
		StartGameButton->OnClicked.AddDynamic(this, &UGMainMenuWidget::OnStartGameClicked);
	}
	if (LoadGameButton)
	{
		LoadGameButton->OnClicked.AddDynamic(this, &UGMainMenuWidget::OnLoadGameClicked);
	}
	if (SettingsButton)
	{
		SettingsButton->OnClicked.AddDynamic(this, &UGMainMenuWidget::OnSettingsClicked);
	}
	if (ExitGameButton)
	{
		ExitGameButton->OnClicked.AddDynamic(this, &UGMainMenuWidget::OnExitGameClicked);
	}
}

void UGMainMenuWidget::OnStartGameClicked()
{
	UGEventsSubsystem* Events = GetGameInstance()->GetSubsystem<UGEventsSubsystem>();
	if (Events)
	{
		Events->OnMenuRequested.Broadcast("None");
		Events->OnNewGameStarted.Broadcast();
	}
}

void UGMainMenuWidget::OnLoadGameClicked()
{
	// Implement logic for loading an old game
}

void UGMainMenuWidget::OnSettingsClicked()
{
	// Implement logic for opening the settings menu
}

void UGMainMenuWidget::OnExitGameClicked()
{
	if (APlayerController* PC = GetOwningPlayer())
	{
		PC->ConsoleCommand("quit");
	}
}
