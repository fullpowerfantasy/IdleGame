// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class IDLEGAME_API AGPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AGPlayerController();

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UFUNCTION(BlueprintCallable, Category = "Widgets")
	void ShowBastionMenu();
	UFUNCTION()
	void HideBastionMenu();

protected:
	UFUNCTION()
		void OnMenuRequested(FName MenuName);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widgets")
	TSubclassOf<class UUserWidget> MainMenuWidgetClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widgets")
	TSubclassOf<class UUserWidget> ChampionsMenuClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widgets")
	TSubclassOf<class UUserWidget> SettingsMenuClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widgets")
	TSubclassOf<class UUserWidget> BastionMenuClass;

private:
	UPROPERTY()
	class UUserWidget* CurrentMenuWidget;
	
	UPROPERTY()
	class UUserWidget* BastionMenuWidget;
};