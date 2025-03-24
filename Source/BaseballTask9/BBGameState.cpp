// Fill out your copyright notice in the Description page of Project Settings.


#include "BBGameState.h"

#include "GameHelper.h"
#include "BBPlayerController.h"

#include "EngineUtils.h"

void ABBGameState::BeginPlay()
{
	Super::BeginPlay();

	StartGame();		// 게임 시작 시 게임 초기화
}

void ABBGameState::StartGame()
{
	Answer = UGameHelper::GenerateRandomNumber();		//랜덤한 3자리 정답 생성
	HostChanceCount = InitalChanceCount;		// 호스트의 남은 기회 수 초기화
	GuestChanceCount = InitalChanceCount;		// 게스트의 남은 기회 수 초기화
}

void ABBGameState::JudgeResult(const FString& Msg, int32 Id)
{
	FString Result = UGameHelper::CheckGuess(Msg, Answer);		//입력 판정
	FString Name = "";

	//기회 없음 처리
	if(Id == 0 && HostChanceCount == 0 || Id != 0 && GuestChanceCount == 0)
	{
		for (ABBPlayerController* PC : TActorRange<ABBPlayerController>(GetWorld()))		//현재 월드 내 모든 PlayerController 순회
		{
			PC->SendMsgToClient_C(TEXT("기회 모두 소진!"));		//모든 클라이언트에게 메시지 전송
		}
		return;
	}

	//Id에 따라 이름 태그 설정
	if (Id == 0)
	{
		Name += "Host :";		//호스트
	}
	else
	{
		Name += "Guest : ";		//게스트
	}

	if (Id == 0)
	{
		HostChanceCount--;		//호스트 기회 감소
	}
	else
	{
		GuestChanceCount--;		//게스트 기회 감소
	}

	//모든 클라이언트에게 판정 결과 전송
	for (ABBPlayerController* PC : TActorRange<ABBPlayerController>(GetWorld()))
	{
		PC->SendMsgToClient_C(Name + Result);
	}

	//정답일때(마지막 문자가 '!'이면)
	if (Result[Result.Len()-1] == '!')
	{
		StartGame();		//게임 재시작
		return;
	}

	//두 플레이어 모두 기회를 모두 사용한 경우
	if (HostChanceCount == 0 && GuestChanceCount == 0)
	{
		for (ABBPlayerController* PC : TActorRange<ABBPlayerController>(GetWorld()))
		{
			PC->SendMsgToClient_C(TEXT("무승부!"));		//무승부 메시지 전송
		}
		StartGame();		//새로운 게임 시작
	}
}
