// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EndlessRunnerGameMode.generated.h"

class ATile;

UCLASS()
class CENDLESSRUNNER_API AEndlessRunnerGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AEndlessRunnerGameMode();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Endless Runner")
	TSubclassOf<ATile> TileClass;

	UPROPERTY(EditDefaultsOnly, Category = "Endless Runner")
	int32 InitialTileCount = 10;

	UPROPERTY(EditDefaultsOnly, Category = "Endless Runner")
	float TileDestroyDelay = 2.0f;

	FTransform NextSpawnPoint;

public:

	UFUNCTION(BlueprintCallable, Category = "Endless Runner")
	ATile* AddTile();

	UFUNCTION()
	void OnTileExited(ATile* ExitedTile);
	void DestroyTile(ATile* TileToDestroy);
};
