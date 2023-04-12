// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GEventsSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMenuRequested, FName, MenuName);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnNewGameStarted);

/**
 * 
 */
UCLASS()
class IDLEGAME_API UGEventsSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

public:
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnMenuRequested OnMenuRequested;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnNewGameStarted OnNewGameStarted;
};