// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameWidget.h"

#include "BBPlayerController.h"

#include "Components/EditableTextBox.h"
#include "Components/ListView.h"
#include "Kismet/GameplayStatics.h"


void UInGameWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ChatBox->OnTextCommitted.AddDynamic(this, &UInGameWidget::OnCommitted);
}

void UInGameWidget::OnCommitted(const FText& Text, ETextCommit::Type CommitMethod)
{
	if (CommitMethod == ETextCommit::Type::OnEnter)
	{
		ABBPlayerController* PC = CastChecked<ABBPlayerController>(UGameplayStatics::GetPlayerController(this, 0));

		int32 Id = (PC->HasAuthority()) ? 0 : 1;
		//UE_LOG(LogTemp, Warnig, TEXT("%s (Committed)"), *Tect.ToString())
		PC->SendMsgToServer_S(Text.ToString(), Id);
	}
}
