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
	virtual void BeginPlay() override;

public:

	UFUNCTION(Client, Reliable)
	void SendMsgToClient_C(const FString& Msg);

	UFUNCTION(Server, Reliable)
	void SendMsgToServer_S(const FString& Msg, int32 Id);


protected:

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UInGameWidget> WidgetClass;

	UPROPERTY(EditAnywhere)
	TObjectPtr<class UInGameWidget> WidgetInstance;
};
