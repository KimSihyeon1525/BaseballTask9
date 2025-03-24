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

	if (IsLocalController() == false)		//클라이언트만 위젯 생성
	{
		return;
	}
	check(WidgetClass);
	WidgetInstance = CreateWidget<UInGameWidget>(this, WidgetClass);		//위젯 인스턴스를 생성 (UInGameWidget 클래스 기반으로)
	check(WidgetInstance);

	WidgetInstance->AddToViewport();		//위젯을 화면(뷰포트)에 추가 → 게임 화면에 출력됨

}

//체팅창
void ABBPlayerController::SendMsgToClient_C_Implementation(const FString& Msg)
{
	UResultData* Data = NewObject<UResultData>();		//결과 데이터를 담을 새 오브젝트 생성
	Data->ResultString = Msg;		//문자열 메시지 저장

	WidgetInstance->ResultView->AddItem(Data);		//생성된 데이터를 ListView에 추가 (UI에 표시됨)
	WidgetInstance->ResultView->SetScrollOffset(9999);		//스크롤을 맨 아래로 내림 (최근 메시지 보기 위해)
}

//서버에서 GameState를 가져와 판정 요청
void ABBPlayerController::SendMsgToServer_S_Implementation(const FString& Msg, int32 Id)
{
	ABBGameState* GS = CastChecked<ABBGameState>(UGameplayStatics::GetGameState(GetWorld()));		//현재 월드에서 GameState를 가져와 ABBGameState 타입으로 캐스팅

	GS->JudgeResult(Msg,Id);		//GameState에 메시지와 플레이어 ID 전달 → 판정 실행
}
