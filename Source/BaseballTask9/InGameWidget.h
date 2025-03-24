// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InGameWidget.generated.h"

/**
 * 
 */
UCLASS()
class BASEBALLTASK9_API UInGameWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:

	virtual void NativeConstruct() override;

public:

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<class UEditableTextBox> ChatBox; 

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UListView> ResultView;

private:
	UFUNCTION()
	void OnCommitted(const FText& Text, ETextCommit::Type CommitMethod);

};
