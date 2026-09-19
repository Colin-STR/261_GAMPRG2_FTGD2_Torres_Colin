// Fill out your copyright notice in the Description page of Project Settings.


#include "EndlessRunnerGameMode.h"
#include "Tile.h"
#include "Components/ArrowComponent.h"

AEndlessRunnerGameMode::AEndlessRunnerGameMode()
{
	NextSpawnPoint = FTransform::Identity;
}

void AEndlessRunnerGameMode::BeginPlay()
{
	Super::BeginPlay();

	for (int32 i = 0; i < InitialTileCount; ++i)
	{
		AddTile();
	}
}

ATile* AEndlessRunnerGameMode::AddTile()
{
	UWorld* World = GetWorld();
	if (!World || !TileClass)
	{
		return nullptr;
	}

	ATile* SpawnedTile = World->SpawnActor<ATile>(TileClass, NextSpawnPoint);

	if (SpawnedTile)
	{
		SpawnedTile->OnTileExited.AddDynamic(this, &AEndlessRunnerGameMode::OnTileExited);

		UArrowComponent* AttachPoint = SpawnedTile->GetAttachPoint();
		if (AttachPoint)
		{
			NextSpawnPoint = AttachPoint->GetComponentTransform();
		}
	}

	return SpawnedTile;
}

void AEndlessRunnerGameMode::OnTileExited(ATile* ExitedTile)
{
	AddTile();
	if (ExitedTile)
	{
		FTimerHandle DestroyTimerHandle;
		FTimerDelegate DestroyDelegate;

		DestroyDelegate.BindUObject(this, &AEndlessRunnerGameMode::DestroyTile, ExitedTile);

		GetWorldTimerManager().SetTimer(DestroyTimerHandle, DestroyDelegate, TileDestroyDelay, false);
	}
}

void AEndlessRunnerGameMode::DestroyTile(ATile* TileToDestroy)
{
	if (TileToDestroy && IsValid(TileToDestroy))
	{
		TileToDestroy->Destroy();
	}
}
