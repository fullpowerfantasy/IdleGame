// Copyright (c) 2023 Full Power Fantasy LLC
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include "Engine/DataTable.h"
#include "GDataTypes.generated.h"


// Enumeration representing the different item slots
UENUM(BlueprintType)
enum class EGEquipmentSlot : uint8
{
	EGET_None UMETA(DisplayName = "None"),
	EGET_Head UMETA(DisplayName = "Head"),
	EGET_Chest UMETA(DisplayName = "Chest"),
	EGET_Legs UMETA(DisplayName = "Legs"),
	EGET_Feet UMETA(DisplayName = "Feet"),
	EGET_Hands UMETA(DisplayName = "Hands"),
	EGET_Offensive UMETA(DisplayName = "Offensive"),
	EGET_Defensive UMETA(DisplayName = "Defensive"),
	EGET_Trinket UMETA(DisplayName = "Trinket"),

	EGET_MAX UMETA(DisplayName = "DefaultMax")
};

// Enumeration representing the different types of stat modifiers
UENUM(BlueprintType)
enum class EGStatModifierType : uint8
{
	Additive,
	Multiplicative,
};


// Struct representing a single stat modifier
USTRUCT(BlueprintType)
struct FGStatModifier
{
	GENERATED_BODY()

	// The name of the stat to be modified
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stat Modifier")
	FName StatName;

	// The type of modifier: additive or multiplicative
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stat Modifier")
	EGStatModifierType ModifierType;

	// The value of the modifier
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stat Modifier")
	float Value;
};


// Struct representing a character stat, to be used in a data table
USTRUCT(BlueprintType)
struct FGCharacterStat : public FTableRowBase
{
	GENERATED_BODY()

	// The name of the stat to be modified
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName StatName;

	// The base value of the stat
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float BaseValue;

	// The modified base value of the stat after applying item modifiers
	UPROPERTY(BlueprintReadOnly)
	float ModifiedBaseValue;

	// The current value of the stat
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float CurrentValue;
};

USTRUCT(BlueprintType)
struct FGCurrency : public FTableRowBase
{
	GENERATED_BODY()

	// The name of the currency
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName CurrencyName;

	// The display name of the currency
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText DisplayName;

	// The icon representing the currency
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Icon;

	// The amount of the currency
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Amount;
};

UENUM(BlueprintType)
enum class EFaction : uint8
{
	FACTION_A,
	FACTION_B,
	FACTION_C
};

USTRUCT(BlueprintType)
struct FGChampionStatsRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName ChampionID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float HP;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float ATK;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float DEF;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float SPD;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float CRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float CDMG;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float RES;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float ACC;
};