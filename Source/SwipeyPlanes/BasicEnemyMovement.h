// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasicEnemyMovement.generated.h"

UCLASS()
class SWIPEYPLANES_API ABasicEnemyMovement : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABasicEnemyMovement();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//How fast the enemy will move.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "EnemyMovement")
	float speed = 100;

	// How long the enemy will exist before being destroyed.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "EnemyMovement")
	float liftime = 5.0f;



private:

private:
	float lifeTimer = 0;
};
