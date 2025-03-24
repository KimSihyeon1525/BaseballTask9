// Fill out your copyright notice in the Description page of Project Settings.


#include "BBGameState.h"

#include "GameHelper.h"
#include "BBPlayerController.h"

#include "EngineUtils.h"

void ABBGameState::BeginPlay()
{
	Super::BeginPlay();

	StartGame();
}

void ABBGameState::StartGame()
{
	Answer = UGameHelper::GenerateRandomNumber();
	HostChanceCount = InitalChanceCount;
	GuestChanceCount = InitalChanceCount;
}

void ABBGameState::JudgeResult(const FString& Msg, int32 Id)
{
	FString Result = UGameHelper::CheckGuess(Msg, Answer);
	FString Name = "";

	if(Id == 0 && HostChanceCount == 0 || Id != 0 && GuestChanceCount == 0)
	{
		for (ABBPlayerController* PC : TActorRange<ABBPlayerController>(GetWorld()))
		{
			PC->SendMsgToClient_C(TEXT("기회 모두 소진!"));
		}
		return;
	}

	if (Id == 0)
	{
		Name += "Host :";
	}
	else
	{
		Name += "Guest : ";
	}

	if (Id == 0)
	{
		HostChanceCount--;
	}
	else
	{
		GuestChanceCount--;
	}

	for (ABBPlayerController* PC : TActorRange<ABBPlayerController>(GetWorld()))
	{
		PC->SendMsgToClient_C(Name + Result);
	}

	if (Result[Result.Len()-1] == '!')
	{
		StartGame();
		return;
	}

	if (HostChanceCount == 0 && GuestChanceCount == 0)
	{
		for (ABBPlayerController* PC : TActorRange<ABBPlayerController>(GetWorld()))
		{
			PC->SendMsgToClient_C(TEXT("무승부!"));
		}
		StartGame();
	}
}
