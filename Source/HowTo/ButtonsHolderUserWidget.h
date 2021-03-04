// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ButtonUserWidget.h"
#include "ButtonsHolderUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class HOWTO_API UButtonsHolderUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable)
	void AddButton(int index)
	{
		GLog->Log("CCC");
		AddButtonObject();
	}

	UFUNCTION(BlueprintCallable)
		void OnBtnClick(int index)
	{
		GLog->Log(FString::FromInt(index));
	}

	UFUNCTION(BlueprintImplementableEvent)
	UButtonUserWidget* AddButtonObject();
};
