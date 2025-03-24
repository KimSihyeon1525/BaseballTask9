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

	if (IsLocalController() == false)
	{
		return;
	}

	check(WidgetClass);

	WidgetInstance = CreateWidget<UInGameWidget>(this, WidgetClass);
	check(WidgetInstance);

	WidgetInstance->AddToViewport();


}

void ABBPlayerController::SendMsgToClient_C_Implementation(const FString& Msg)
{
	UResultData* Data = NewObject<UResultData>();
	Data->ResultString = Msg;

	WidgetInstance->ResultView->AddItem(Data);
	WidgetInstance->ResultView->SetScrollOffset(9999);
}

void ABBPlayerController::SendMsgToServer_S_Implementation(const FString& Msg, int32 Id)
{
	ABBGameState* GS = CastChecked<ABBGameState>(UGameplayStatics::GetGameState(GetWorld()));

	GS->JudgeResult(Msg,Id);
}
