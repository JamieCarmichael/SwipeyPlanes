// Fill out your copyright notice in the Description page of Project Settings.


#include "ExplosionEffect.h"

// Sets default values
AExplosionEffect::AExplosionEffect()
{
    PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AExplosionEffect::BeginPlay()
{
    Super::BeginPlay();

    lifeTimer = 0.0f;

}
void AExplosionEffect::Tick(float DeltaTime)
{
    lifeTimer += DeltaTime;

    if (lifeTimer > lifetime)
    {
        Destroy();
    }
}
