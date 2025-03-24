// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BBPlayerController.generated.h"

class UInGameWidget;
/**
 * 
 */
UCLASS()
class BASEBALLTASK9_API ABBPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;		//UI 위젯 생성

public:

	UFUNCTION(Client, Reliable)
	void SendMsgToClient_C(const FString& Msg);		//클라이언트 메시지 전송

	UFUNCTION(Server, Reliable)
	void SendMsgToServer_S(const FString& Msg, int32 Id);		//서버로 입력 전송


protected:

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UInGameWidget> WidgetClass;		//블루프린트에서 설정할 위젯 클래스

	UPROPERTY(EditAnywhere)
	TObjectPtr<class UInGameWidget> WidgetInstance;		//생성된 위젯 인스턴스
};
