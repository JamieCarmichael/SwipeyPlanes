// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyFollow.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerPawn.h"


// Called every frame
void AEnemyFollow::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Rotate towards player
    // Get the player reference (APlayerPawn)
    APlayerPawn* PlayerPawn = Cast<APlayerPawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
    if (PlayerPawn)
    {

        // Get the enemy and player locations
        FVector EnemyLocation = GetActorLocation();
        FVector PlayerLocation = PlayerPawn->GetActorLocation();

        // Calculate the direction to look at (from enemy to player)
        FVector DirectionToPlayer = PlayerLocation - EnemyLocation;

        // Get the angle in radians and convert it to degrees
        float Angle = FMath::Atan2(DirectionToPlayer.X, DirectionToPlayer.Z) * (180.0f / PI);

        // Set the actor rotation around the Y-axis
        FRotator LookAtRotation(-Angle, 0.0f, 0.0f);
        SetActorRotation(LookAtRotation);
    }

    // Get the forward vector of the actor (the direction it's facing)
    FVector ForwardVector = GetActorUpVector();

    // Calculate the movement distance for this frame
    FVector Movement = ForwardVector * speed * DeltaTime;

    // Movs by the delta with collisions enabled.
    AddActorWorldOffset(Movement, true);


    // Accumulate the time elapsed since the actor began playing
    lifeTimer += DeltaTime;

    // Check if the elapsed time is greater than or equal to the time before destruction
    if (lifeTimer >= lifetime)
    {
        Destroy();
    }
}