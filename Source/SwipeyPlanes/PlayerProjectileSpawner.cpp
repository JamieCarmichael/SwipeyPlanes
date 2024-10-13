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
			SpawnProjectiles(ProjectileCount);
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

void APlayerProjectileSpawner::SpawnProjectiles(int num)
{
	switch (num)
	{
		case 1:
		{
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation(), GetActorRotation());
			break;
		}
		case 2:
		{
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(-1, 0, 0), GetActorRotation() + FRotator(-5, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(1, 0, 0), GetActorRotation() + FRotator(5, 0, 0));
			break;
		}
		case 3:
		{
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation(), GetActorRotation());
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(-1, 0, 0), GetActorRotation() + FRotator(-5, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(1, 0, 0), GetActorRotation() + FRotator(5, 0, 0));
			break;
		}
		case 4:
		{
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(-3, 0, 0), GetActorRotation() + FRotator(-15, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(-1, 0, 0), GetActorRotation() + FRotator(-5, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(1, 0, 0), GetActorRotation() + FRotator(5, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(3, 0, 0), GetActorRotation() + FRotator(15, 0, 0));
			break;
		}
		case 5:
		{
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation(), GetActorRotation());
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(-3, 0, 0), GetActorRotation() + FRotator(-15, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(-1, 0, 0), GetActorRotation() + FRotator(-5, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(1, 0, 0), GetActorRotation() + FRotator(5, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(3, 0, 0), GetActorRotation() + FRotator(15, 0, 0));
			break;
		}
		case 6:
		{
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(-5, 0, 0), GetActorRotation() + FRotator(-25, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(-3, 0, 0), GetActorRotation() + FRotator(-15, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(-1, 0, 0), GetActorRotation() + FRotator(-5, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(1, 0, 0), GetActorRotation() + FRotator(5, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(3, 0, 0), GetActorRotation() + FRotator(15, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(4, 0, 0), GetActorRotation() + FRotator(25, 0, 0));
			break;
		}
		case 7:
		{
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation(), GetActorRotation());
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(-5, 0, 0), GetActorRotation() + FRotator(-25, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(-3, 0, 0), GetActorRotation() + FRotator(-15, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(-1, 0, 0), GetActorRotation() + FRotator(-5, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(1, 0, 0), GetActorRotation() + FRotator(5, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(3, 0, 0), GetActorRotation() + FRotator(15, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(4, 0, 0), GetActorRotation() + FRotator(25, 0, 0));
			break;
		}
		case 8:
		{
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(-4, 0, 0), GetActorRotation() + FRotator(-35, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(-5, 0, 0), GetActorRotation() + FRotator(-25, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(-3, 0, 0), GetActorRotation() + FRotator(-15, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(-1, 0, 0), GetActorRotation() + FRotator(-5, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(1, 0, 0), GetActorRotation() + FRotator(5, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(3, 0, 0), GetActorRotation() + FRotator(15, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(4, 0, 0), GetActorRotation() + FRotator(25, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(5, 0, 0), GetActorRotation() + FRotator(35, 0, 0));
			break;
		}
		case 9:
		{
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation(), GetActorRotation());
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(-4, 0, 0), GetActorRotation() + FRotator(-35, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(-5, 0, 0), GetActorRotation() + FRotator(-25, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(-3, 0, 0), GetActorRotation() + FRotator(-15, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(-1, 0, 0), GetActorRotation() + FRotator(-5, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(1, 0, 0), GetActorRotation() + FRotator(5, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(3, 0, 0), GetActorRotation() + FRotator(15, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(4, 0, 0), GetActorRotation() + FRotator(25, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(5, 0, 0), GetActorRotation() + FRotator(35, 0, 0));
			break;
		}
		case 10:
		{
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(-6, 0, 0), GetActorRotation() + FRotator(-45, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(-4, 0, 0), GetActorRotation() + FRotator(-35, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(-5, 0, 0), GetActorRotation() + FRotator(-25, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(-3, 0, 0), GetActorRotation() + FRotator(-15, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(-1, 0, 0), GetActorRotation() + FRotator(-5, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(1, 0, 0), GetActorRotation() + FRotator(5, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(3, 0, 0), GetActorRotation() + FRotator(15, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(4, 0, 0), GetActorRotation() + FRotator(25, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(5, 0, 0), GetActorRotation() + FRotator(35, 0, 0));
			GetWorld()->SpawnActor<APlayerProjectile>(projectile, GetActorLocation() + FVector(6, 0, 0), GetActorRotation() + FRotator(45, 0, 0));
			break;
		}
		default:
		{
			break;
		}
	}
}



