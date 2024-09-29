// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerProjectileSpawner.h"
#include "PlayerProjectile.h"

// Sets default values
APlayerProjectileSpawner::APlayerProjectileSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerProjectileSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	projectileTimer = 0.0f;
}

// Called every frame
void APlayerProjectileSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsSpawnerActive)
	{
		// Fire Projectiles
		projectileTimer += DeltaTime;
		if (projectileTimer > TimeBetweenProjectiles)
		{
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation(), GetActorRotation());
			projectileTimer = 0.0f;
		}
	}
}

void APlayerProjectileSpawner::StopSpawning()
{
	IsSpawnerActive = false;
	PrimaryActorTick.bCanEverTick = false;
}

void APlayerProjectileSpawner::StartSpawning()
{
	IsSpawnerActive = true;
	PrimaryActorTick.bCanEverTick = true;
}

