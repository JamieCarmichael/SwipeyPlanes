// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicEnemyMovement.h"

// Sets default values
ABasicEnemyMovement::ABasicEnemyMovement()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABasicEnemyMovement::BeginPlay()
{
	Super::BeginPlay();

	lifeTimer = 0.0f;
}

// Called every frame
void ABasicEnemyMovement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    // Get the forward vector of the actor (the direction it's facing)
    FVector ForwardVector = GetActorUpVector();

    // Calculate the movement distance for this frame
    FVector Movement = ForwardVector * speed * DeltaTime;

    // Movs by the delta with collisions enabled.
    AddActorWorldOffset(Movement, true);


    // Accumulate the time elapsed since the actor began playing
    lifeTimer += DeltaTime;

    // Check if the elapsed time is greater than or equal to the time before destruction
    if (lifeTimer >= liftime)
    {
        Destroy();
    }
}

