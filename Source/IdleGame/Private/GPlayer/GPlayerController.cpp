// Fill out your copyright notice in the Description page of Project Settings.


#include "GPlayer/GPlayerController.h"
#include "GSubsystems/GEventsSubsystem.h"
#include "Blueprint/UserWidget.h"

AGPlayerController::AGPlayerController()
{
	bShowMouseCursor = true;
}

void AGPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UGEventsSubsystem* Events = GetGameInstance()->GetSubsystem<UGEventsSubsystem>();
	if (Events)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, FString::Printf(TEXT("Binding Delegates")));
		}
		Events->OnMenuRequested.AddDynamic(this, &ThisClass::OnMenuRequested);
		Events->OnNewGameStarted.AddDynamic(this, &ThisClass::ShowBastionMenu);
	}
	OnMenuRequested("MainMenu");
}

void AGPlayerController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	UGEventsSubsystem* Events = GetGameInstance()->GetSubsystem<UGEventsSubsystem>();
	if (Events)
	{
		Events->OnMenuRequested.RemoveDynamic(this, &ThisClass::OnMenuRequested);
	}


	Super::EndPlay(EndPlayReason);
}

void AGPlayerController::OnMenuRequested(FName MenuName)
{
	if (CurrentMenuWidget)
	{
		CurrentMenuWidget->RemoveFromParent();
		CurrentMenuWidget = nullptr;
	}

	TSubclassOf<UUserWidget> WidgetToOpen;

	if (MenuName == "MainMenu")
	{
		WidgetToOpen = MainMenuWidgetClass;
	}
	else if (MenuName == "ChampionsMenu")
	{
		WidgetToOpen = ChampionsMenuClass;
	}
	else if (MenuName == "SettingsMenu")
	{
		WidgetToOpen = SettingsMenuClass;
	}
	else if (MenuName == "None")
	{
		return;
	}

	if (WidgetToOpen)
	{
		CurrentMenuWidget = CreateWidget<UUserWidget>(this, WidgetToOpen);
		if (CurrentMenuWidget)
		{
			CurrentMenuWidget->AddToViewport();
		}
	}
}

void AGPlayerController::ShowBastionMenu()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, FString::Printf(TEXT("Showing bastion menu")));
	}

	if (BastionMenuWidget)
	{
		BastionMenuWidget->RemoveFromParent();
		BastionMenuWidget = nullptr;
	}
	if (BastionMenuClass)
	{
		BastionMenuWidget = CreateWidget<UUserWidget>(this, BastionMenuClass);
		if (BastionMenuWidget)
		{
			BastionMenuWidget->AddToViewport();
		}
	}
}

void AGPlayerController::HideBastionMenu()
{
	if (BastionMenuWidget)
	{
		BastionMenuWidget->RemoveFromParent();
		BastionMenuWidget = nullptr;
	}
}
