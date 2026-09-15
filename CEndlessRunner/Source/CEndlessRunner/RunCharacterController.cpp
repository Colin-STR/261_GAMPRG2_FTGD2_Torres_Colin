// Fill out your copyright notice in the Description page of Project Settings.


#include "RunCharacterController.h"
#include "RunCharacter.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"

void ARunCharacterController::BeginPlay()
{
	Super::BeginPlay();

	playerCharacter = Cast<ARunCharacter>(GetPawn());

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(this->GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DeafaultMappingContext, 0);
	}
}

void ARunCharacterController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(RunForward, ETriggerEvent::Triggered, this, &ARunCharacterController::MoveForward);
		EnhancedInputComponent->BindAction(RunRight, ETriggerEvent::Triggered, this, &ARunCharacterController::MoveRight);
	}
}

void ARunCharacterController::MoveForward(const FInputActionValue& Value)
{
	float xValue = Value.Get<float>();
	playerCharacter->MoveForward(xValue);
}

void ARunCharacterController::MoveRight(const FInputActionValue& Value)
{
	float yValue = Value.Get<float>();
	playerCharacter->MoveRight(yValue);
}


