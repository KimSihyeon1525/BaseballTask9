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

	void StartGame();		//���� �ʱ�ȭ
	void JudgeResult(const FString& Msg, int32 Id);		//�Է� ó�� �� ��� ����

public:
	int32 InitalChanceCount = 3;		//�÷��̾��� �ʱ� ��ȸ
	int32 HostChanceCount = 3;		//ȣ��Ʈ ���� ��ȸ
	int32 GuestChanceCount = 3;		//�Խ�Ʈ ���� ��ȸ

	FString Answer = "";		//����

};
