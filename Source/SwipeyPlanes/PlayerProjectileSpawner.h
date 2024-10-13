// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerProjectileSpawner.generated.h"

UCLASS()
class SWIPEYPLANES_API APlayerProjectileSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayerProjectileSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	// The projectile being spawned.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Projectile Spawner")
	TSubclassOf<class APlayerProjectile> projectile;


	// How many seconds between projectiles spawning.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Projectile Spawner")
	float TimeBetweenProjectiles = 0.5f;

	// Called when the player dies.
	UFUNCTION()
	void StopSpawning();

	// Called when the player spawns.
	UFUNCTION()
	void StartSpawning();

	// Spawn Multiple Projectiles.
	UFUNCTION()
	void SpawnProjectiles(int num);

	int ProjectileCount = 1;

private:
	float projectileTimer;

	// Controls whether the spawner is active or not
	bool IsSpawnerActive = true;


};
