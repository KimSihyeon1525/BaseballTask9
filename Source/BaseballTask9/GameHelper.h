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
	static FString GenerateRandomNumber();		//겹치지 안는 랜덤 3자리 숫자 생성
	static FString CheckGuess(const FString& Guess, const FString& Answer);		//입력 확인후 판정

};
