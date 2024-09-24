// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
    MoveTimer = TimeToMove;
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


    // Apply movement based on input
    FVector Movement = GetPendingMovementInputVector();
    if (!Movement.IsNearlyZero())
    {
        // scale the movement vector by the time to move.
        MovementVector = Movement / TimeToMove;
        MoveTimer = 0;
        ConsumeMovementInputVector();  // Clears the input after use
    }

    // Move the player over time.
    if (MoveTimer < TimeToMove)
    {
        SetActorLocation(GetActorLocation() + (MovementVector * (1 - (MoveTimer/TimeToMove)) * DeltaTime));
        MoveTimer = MoveTimer + DeltaTime;
    }

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

