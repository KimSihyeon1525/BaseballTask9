// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameHelper.generated.h"

/**
 * 
 */
UCLASS()
class BASEBALLTASK9_API UGameHelper : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	static FString GenerateRandomNumber();
	static FString CheckGuess(const FString& Guess, const FString& Answer);

};
