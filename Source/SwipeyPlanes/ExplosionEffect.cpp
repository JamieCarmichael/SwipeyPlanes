// Fill out your copyright notice in the Description page of Project Settings.

#include "PaperFlipbook.h"
#include "ExplosionEffect.h"

// Sets default values
AExplosionEffect::AExplosionEffect()
{
    // Create the flipbook component
    FlipbookComponent = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("FlipbookComponent"));
    RootComponent = FlipbookComponent; // Set the flipbook as the root component

    // Set the flipbook to play automatically
    FlipbookComponent->SetAutoActivate(true);
}

// Called when the game starts or when spawned
void AExplosionEffect::BeginPlay()
{
	Super::BeginPlay();

    if (ExplosionFlipbook)
    {
        FlipbookComponent->SetFlipbook(ExplosionFlipbook);
        FlipbookComponent->SetLooping(false);
        FlipbookComponent->Play();

        // Set a timer to destroy the explosion actor after the flipbook duration
        FTimerHandle TimerHandle;
        GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AExplosionEffect::HandleDestruction, liftime, false);
    }
	
}
void AExplosionEffect::HandleDestruction()
{
    Destroy(); // Safely destroy the actor
}


