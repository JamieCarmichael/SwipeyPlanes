// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"

// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();

	spawnTimer = 0.0f;
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsSpawningEnabled)
	{
		// Fire Projectiles
		spawnTimer += DeltaTime;
		if (spawnTimer > TimeBetweenEnemies)
		{
			FVector ALocation = FirstSpawnPosition->GetActorLocation();  // Location of the first object
			FVector BLocation = SecondsSpawnPosition->GetActorLocation();  // Location of the second object

			// Generate a random scalar value between 0 and 1
			float RandomAlpha = FMath::FRand();  // Random value between 0.0 and 1.0

			// Interpolate between the two positions using Lerp
			FVector RandomPosition = FMath::Lerp(ALocation, BLocation, RandomAlpha);


			GetWorld()->SpawnActor<AActor>(Enemy, RandomPosition, GetActorRotation());
			spawnTimer = 0.0f;
		}
	}
}

void AEnemySpawner::SetSpawningEnabled(bool enableSpawning)
{
	IsSpawningEnabled = enableSpawning;
}

