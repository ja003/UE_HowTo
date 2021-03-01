// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CubePawn.generated.h"

UCLASS()
class HOWTO_API ACubePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACubePawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected:
	UFUNCTION(BlueprintCallable, Category = "Movement")
	void MoveRight(float Value);
	
	UFUNCTION(BlueprintCallable, Category = "Movement")
	void MoveForward(float Value);
	
	void Space();

};
