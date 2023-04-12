// Fill out your copyright notice in the Description page of Project Settings.


#include "GWidgets/GSettingsMenuWidget.h"
#include "Engine/Engine.h"
#include "Components/ComboBoxString.h"
#include "Components/Slider.h"
#include "GameFramework/GameUserSettings.h"
#include "Kismet/GameplayStatics.h"

bool UGSettingsMenuWidget::Initialize()
{
	bool bResult = Super::Initialize();
	if (!bResult) return false;

	// Bind Screen Resolution ComboBox
	if (ScreenResolutionComboBox)
	{
		ScreenResolutionComboBox->OnSelectionChanged.AddDynamic(this, &ThisClass::UpdateScreenResolution);
	}

	// Bind Window Mode ComboBox
	if (WindowModeComboBox)
	{
		WindowModeComboBox->OnSelectionChanged.AddDynamic(this, &ThisClass::UpdateWindowMode);
	}

	// Bind Anti-Aliasing Slider
	if (AntiAliasingSlider)
	{
		AntiAliasingSlider->OnValueChanged.AddDynamic(this, &ThisClass::UpdateAntiAliasing);
	}

	return true;
}

void UGSettingsMenuWidget::UpdateScreenResolution(FString SelectedItem, ESelectInfo::Type SelectionType)
{
	if (SelectionType == ESelectInfo::Type::OnMouseClick)
	{
		FVector2D NewResolution;
		if (SelectedItem == "1920x1080")
		{
			NewResolution = FVector2D(1920, 1080);
		}
		else if (SelectedItem == "1280x720")
		{
			NewResolution = FVector2D(1280, 720);
		}
		// Add more resolutions as needed
		UGameUserSettings* GameUserSettings = GEngine->GetGameUserSettings();
		if (GameUserSettings && NewResolution != FVector2D::ZeroVector)
		{
			GameUserSettings->SetScreenResolution(FIntPoint(NewResolution.X, NewResolution.Y));
			GameUserSettings->ApplySettings(false);
		}
	}
}

void UGSettingsMenuWidget::UpdateWindowMode(FString SelectedItem, ESelectInfo::Type SelectionType)
{
	if (SelectionType == ESelectInfo::Type::OnMouseClick)
	{
		EWindowMode::Type WindowMode = EWindowMode::Fullscreen;
		if (SelectedItem == "Fullscreen")
		{
			WindowMode = EWindowMode::Fullscreen;
		}
		else if (SelectedItem == "Windowed")
		{
			WindowMode = EWindowMode::Windowed;
		}
		// Add more modes as needed
		UGameUserSettings* GameUserSettings = GEngine->GetGameUserSettings();
		if (GameUserSettings)
		{
			GameUserSettings->SetFullscreenMode(WindowMode);
			GameUserSettings->ApplySettings(false);
		}
	}
}


void UGSettingsMenuWidget::UpdateAntiAliasing(float Value)
{
	int32 AntiAliasingQuality = FMath::RoundToInt(Value * 3); // Assuming slider range is from 0 to 1 and there are 4 quality levels (0 to 3)
	UGameUserSettings* GameUserSettings = GEngine->GetGameUserSettings();
	if (GameUserSettings)
	{
		GameUserSettings->SetAntiAliasingQuality(AntiAliasingQuality);
		GameUserSettings->ApplySettings(false);
	}
}