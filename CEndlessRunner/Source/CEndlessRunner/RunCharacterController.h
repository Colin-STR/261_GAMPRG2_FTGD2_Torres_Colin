// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RunCharacterController.generated.h"

class UInputMappingContext;
class UInputAction;
class ARunCharacter;
struct FInputActionValue;

UCLASS()
class CENDLESSRUNNER_API ARunCharacterController : public APlayerController
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category = "Input", meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DeafaultMappingContext;

	UPROPERTY(EditAnywhere, Category = "Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* RunForward;

	UPROPERTY(EditAnywhere, Category = "Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* RunRight;

	ARunCharacter* playerCharacter;

protected:
	void BeginPlay() override;

	void SetupInputComponent() override;

	void MoveForward(const FInputActionValue& Value);

	void MoveRight(const FInputActionValue& Value);
};

