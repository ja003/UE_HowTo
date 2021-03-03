// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RaycastInfoUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class HOWTO_API URaycastInfoUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Info")
		FText ObjNameText;

	UFUNCTION(BlueprintCallable, Category = "Info")
	void SetName(FText name)
	{
		GLog->Log(name);
	}
	
};
