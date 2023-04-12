// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GSettingsMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class IDLEGAME_API UGSettingsMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual bool Initialize() override;

	UFUNCTION()
		void UpdateScreenResolution(FString SelectedItem, ESelectInfo::Type SelectionType);

	UFUNCTION()
		void UpdateWindowMode(FString SelectedItem, ESelectInfo::Type SelectionType);

	UFUNCTION()
		void UpdateAntiAliasing(float AntiAliasingLevel);

protected:
	UPROPERTY(meta = (BindWidget))
	class UComboBoxString* ScreenResolutionComboBox;

	UPROPERTY(meta = (BindWidget))
	class UComboBoxString* WindowModeComboBox;

	UPROPERTY(meta = (BindWidget))
	class USlider* AntiAliasingSlider;
};