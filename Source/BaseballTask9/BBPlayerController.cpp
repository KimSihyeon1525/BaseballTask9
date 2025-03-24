// Fill out your copyright notice in the Description page of Project Settings.


#include "BBPlayerController.h"

#include "InGameWidget.h"
#include "ResultData.h"
#include "BBGameState.h"

#include "Components/ListView.h"
#include "Kismet/GameplayStatics.h"

void ABBPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (IsLocalController() == false)		//Ŭ���̾�Ʈ�� ���� ����
	{
		return;
	}
	check(WidgetClass);
	WidgetInstance = CreateWidget<UInGameWidget>(this, WidgetClass);		//���� �ν��Ͻ��� ���� (UInGameWidget Ŭ���� �������)
	check(WidgetInstance);

	WidgetInstance->AddToViewport();		//������ ȭ��(����Ʈ)�� �߰� �� ���� ȭ�鿡 ��µ�

}

//ü��â
void ABBPlayerController::SendMsgToClient_C_Implementation(const FString& Msg)
{
	UResultData* Data = NewObject<UResultData>();		//��� �����͸� ���� �� ������Ʈ ����
	Data->ResultString = Msg;		//���ڿ� �޽��� ����

	WidgetInstance->ResultView->AddItem(Data);		//������ �����͸� ListView�� �߰� (UI�� ǥ�õ�)
	WidgetInstance->ResultView->SetScrollOffset(9999);		//��ũ���� �� �Ʒ��� ���� (�ֱ� �޽��� ���� ����)
}

//�������� GameState�� ������ ���� ��û
void ABBPlayerController::SendMsgToServer_S_Implementation(const FString& Msg, int32 Id)
{
	ABBGameState* GS = CastChecked<ABBGameState>(UGameplayStatics::GetGameState(GetWorld()));		//���� ���忡�� GameState�� ������ ABBGameState Ÿ������ ĳ����

	GS->JudgeResult(Msg,Id);		//GameState�� �޽����� �÷��̾� ID ���� �� ���� ����
}
