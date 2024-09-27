// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PaperSprite.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerProjectile.generated.h"

UCLASS()
class SWIPEYPLANES_API APlayerProjectile : public AActor
{
	GENERATED_BODY()


public:	
	// Sets default values for this actor's properties
	APlayerProjectile();

	//How fast the projectile will move.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "ProjectileMovement")
	float speed = 200.0f;

	// How long the projectile will exist before being destroyed.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "ProjectileMovement")
	float liftime = 3.0f;

	// How long the projectile will exist before being destroyed.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "ProjectileDamage")
	int Damage = 1;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	float lifeTimer = 0;

};
