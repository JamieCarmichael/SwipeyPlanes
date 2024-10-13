// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PickUpSingleton.generated.h"

UCLASS()
class SWIPEYPLANES_API UPickUpSingleton : public UObject
{
    GENERATED_BODY()

private:
    static UPickUpSingleton* SingletonInstance;

    // Private constructor so it can only be created internally
    UPickUpSingleton();

public:
    // Returns the singleton instance
    static UPickUpSingleton* Get();


    // The change of a pickup being spawned
    UFUNCTION(BlueprintCallable)
    float PickUpProjectileChance();

    // Called when the player spawns.
    UFUNCTION(BlueprintCallable)
    void EnemyDied();

    // Called when the player spawns.
    UFUNCTION(BlueprintCallable)
    void PickUpSpawned();
    
    // Called when the player spawns.
    UFUNCTION(BlueprintCallable)
    void AddActivePickUp();

    // Called when the player spawns.
    UFUNCTION(BlueprintCallable)
    void RemoveActivePickUp();

    // Called when the player spawns.
    UFUNCTION(BlueprintCallable)
    void ResetActivePickUp();

private:
    // The chance increase per enemy killed
    float PickUpProjectileChanceAdd = 0.05f;
    // The chance reduced per active pickup
    float ActivePickupReduction = 0.3f;

    float pickUpSpawnChance = 0;
    int activeProjectilePickUps= 0;
};
