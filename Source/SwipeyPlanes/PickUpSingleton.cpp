// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUpSingleton.h"

UPickUpSingleton* UPickUpSingleton::SingletonInstance = nullptr;

UPickUpSingleton::UPickUpSingleton() 
{
    pickUpSpawnChance = 0.0f;
    activeProjectilePickUps = 0;
    ActivePickupReduction = 0.3f;
    PickUpProjectileChanceAdd = 0.05f;
}

UPickUpSingleton* UPickUpSingleton::Get()
{
    if (!SingletonInstance)
    {
        // Create the singleton instance if it doesn't already exist
        SingletonInstance = NewObject<UPickUpSingleton>();
        // Prevent garbage collection
        SingletonInstance->AddToRoot();
    }

    return SingletonInstance;
}

float UPickUpSingleton::PickUpProjectileChance()
{
    if (ActivePickupReduction != 0.3f)
    {
        ActivePickupReduction = 0.3f;
    }
    if (PickUpProjectileChanceAdd != 0.5f)
    {
        PickUpProjectileChanceAdd = 0.05f;
    }

    float chance = pickUpSpawnChance - (ActivePickupReduction * activeProjectilePickUps);

	return chance;
}

void UPickUpSingleton::EnemyDied()
{
	pickUpSpawnChance = pickUpSpawnChance + PickUpProjectileChanceAdd;
}

void UPickUpSingleton::PickUpSpawned()
{
	pickUpSpawnChance = 0.0f;
}

void UPickUpSingleton::AddActivePickUp()
{
    activeProjectilePickUps = activeProjectilePickUps + 1;
}

void UPickUpSingleton::RemoveActivePickUp()
{
    if (activeProjectilePickUps > 0)
    {
        activeProjectilePickUps = activeProjectilePickUps - 1;
    }
    else
    {
        activeProjectilePickUps = 0;
    }
}

void UPickUpSingleton::ResetActivePickUp()
{
    pickUpSpawnChance = 0.0f;
    activeProjectilePickUps = 0;
    ActivePickupReduction = 0.3f;
    PickUpProjectileChanceAdd = 0.05f;
}
