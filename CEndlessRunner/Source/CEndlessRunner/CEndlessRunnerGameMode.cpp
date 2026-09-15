// Copyright Epic Games, Inc. All Rights Reserved.

#include "CEndlessRunnerGameMode.h"
#include "CEndlessRunnerCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACEndlessRunnerGameMode::ACEndlessRunnerGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
