// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "Components/Button.h"
#include "MyButtonWidgetComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class HOWTO_API UMyButtonWidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()

public:
	UMyButtonWidgetComponent();

		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UButton* Button;

		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText ButtonText;
	
};
