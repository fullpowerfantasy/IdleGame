// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GBastionWidget.generated.h"

/**
 * 
 */
UCLASS()
class IDLEGAME_API UGBastionWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void OnChampionsMenuButtonClicked();

	UFUNCTION()
	void OnSettingsMenuButtonClicked();

	UPROPERTY(meta = (BindWidget))
	class UButton* ChampionsMenuButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* SettingsMenuButton;
};