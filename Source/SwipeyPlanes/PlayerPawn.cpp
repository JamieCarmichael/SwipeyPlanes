// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "ExplosionEffect.h"
#include "SwipeyPlanesController.h"
#include <Actions/PawnAction.h>
#include "PaperSpriteComponent.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Assuming the PaperSprite is already initialized or created
    PaperSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("PlayerSprite"));
    PaperSprite->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();

    health = StartHealth;
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    //score = GetWorld()->GetTimeSeconds();

    // Apply movement based on input
    FVector Movement = GetPendingMovementInputVector();
    if (!Movement.IsNearlyZero())
    {
        Destination = GetActorLocation() + Movement;
        ConsumeMovementInputVector();  // Clears the input after use
    }

    // Add movement
    FVector actorLocation = GetActorLocation();
    float Distance = FVector::Dist(actorLocation, Destination);
    if (!FMath::IsNearlyZero(Distance))
    {
        FVector direction = Destination - actorLocation;
        
        SetActorLocation(actorLocation + (direction * speed * DeltaTime));
    }

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void APlayerPawn::PlayerTakeDamage(int damage)
{

    health -= damage;

    if (health <= 0)
    {
        GetWorld()->SpawnActor<AActor>(Explosion, GetActorLocation(), GetActorRotation());

        OnPlayerDeath();
    }
}

void APlayerPawn::PlayerAddScore(int newScore)
{
    score += newScore;
}

void APlayerPawn::OnPlayerDeath()
{


    // Hide the player character
    SetActorHiddenInGame(true);

    // Disable collision
    SetActorEnableCollision(false);

    // Optionally disable tick
    PrimaryActorTick.SetTickFunctionEnable(false);

    // Need to disable spawner
    ProjectileSpawner -> StopSpawning();
}

