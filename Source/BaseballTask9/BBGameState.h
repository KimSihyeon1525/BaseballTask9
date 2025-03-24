// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "BBGameState.generated.h"

/**
 * 
 */
UCLASS()
class BASEBALLTASK9_API ABBGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:

	virtual void BeginPlay() override;

	void StartGame();		//게임 초기화
	void JudgeResult(const FString& Msg, int32 Id);		//입력 처리 및 결과 전송

public:
	int32 InitalChanceCount = 3;		//플레이어의 초기 기회
	int32 HostChanceCount = 3;		//호스트 남은 기회
	int32 GuestChanceCount = 3;		//게스트 남은 기회

	FString Answer = "";		//정답

};
