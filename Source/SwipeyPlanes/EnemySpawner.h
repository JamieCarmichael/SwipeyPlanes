// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

UCLASS()
class SWIPEYPLANES_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// The projectile being spawned.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy Spawner")
	TSubclassOf<class AActor> Enemy;


	// How many seconds between projectiles spawning.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy Spawner")
	float TimeBetweenEnemies = 1.0f;

	// How many seconds between projectiles spawning.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemy Spawner")
	AActor* FirstSpawnPosition;

	// How many seconds between projectiles spawning.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemy Spawner")
	AActor* SecondsSpawnPosition;

private:
	float spawnTimer;

};
