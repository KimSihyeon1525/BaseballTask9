// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ResultData.generated.h"

/**
 * 
 */
UCLASS()
class BASEBALLTASK9_API UResultData : public UObject
{
	GENERATED_BODY()
	
public:
	FString ResultString;		//결과 메시지를 담는 문자열 변수

};
