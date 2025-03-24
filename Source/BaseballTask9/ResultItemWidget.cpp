// Fill out your copyright notice in the Description page of Project Settings.


#include "ResultItemWidget.h"
#include "ResultData.h"

#include "Components/TextBlock.h"

void UResultItemWidget::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);

	UResultData* Data = CastChecked<UResultData>(ListItemObject);

	ItemText->SetText(FText::FromString(Data->ResultString));
}
