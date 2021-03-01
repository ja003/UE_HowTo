// Fill out your copyright notice in the Description page of Project Settings.


#include "CubePawn.h"
#include <Math/UnrealMathUtility.h>
#include <GameFramework/Pawn.h>

// Sets default values
ACubePawn::ACubePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACubePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACubePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ACubePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAction("Space", IE_Pressed, this, &ACubePawn::Space);

	InputComponent->BindAxis("MoveForward", this, &ACubePawn::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ACubePawn::MoveRight);
}

void ACubePawn::MoveRight(float Value)
{
	if (FMath::IsNearlyZero(Value))
		return;
	GLog->Log("MoveRight " + FString::FromInt(Value));
	AddMovementInput(GetActorRightVector(), Value);
}

void ACubePawn::MoveForward(float Value)
{
	if (FMath::IsNearlyZero(Value))
		return;
	GLog->Log("MoveForward " + FString::FromInt(Value));
	AddMovementInput(GetActorForwardVector(), Value);
}

void ACubePawn::Space()
{
	GLog->Log("Space");
}

