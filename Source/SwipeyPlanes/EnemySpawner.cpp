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

	timeToSpawn = TimeBetweenEnemies;
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
		if (spawnTimer > timeToSpawn)
		{
			FVector ALocation = FirstSpawnPosition->GetActorLocation();  // Location of the first object
			FVector BLocation = SecondsSpawnPosition->GetActorLocation();  // Location of the second object

			// Generate a random scalar value between 0 and 1
			float RandomAlpha = FMath::FRand();  // Random value between 0.0 and 1.0

			// Interpolate between the two positions using Lerp
			FVector RandomPosition = FMath::Lerp(ALocation, BLocation, RandomAlpha);

			float RandomNumber = FMath::FRand();  // Random value between 0.0 and 1.0
			if (RandomNumber < 0.5)
			{
				GetWorld()->SpawnActor<AActor>(EnemyBasic, RandomPosition, GetActorRotation());
			}			
			else if (RandomNumber < 0.8)
			{
				GetWorld()->SpawnActor<AActor>(EnemyStrong, RandomPosition, GetActorRotation());
			}			
			else
			{
				GetWorld()->SpawnActor<AActor>(EnemyFollow, RandomPosition, GetActorRotation());
			}

			spawnTimer = 0.0f;
			if (timeToSpawn > 0.1f)
			{
				timeToSpawn -= TimeReduction;
			}
			if (timeToSpawn < 0.1f)
			{
				timeToSpawn = 0.1f;
			}
		}
	}
}

void AEnemySpawner::SetSpawningEnabled(bool enableSpawning)
{
	IsSpawningEnabled = enableSpawning;
}

