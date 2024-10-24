// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "EnemyBasic.generated.h"

UCLASS()
class SWIPEYPLANES_API AEnemyBasic : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEnemyBasic();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Correctly defined overlap function
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// Reference to the BoxComponent for collision detection
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBoxComponent* MyBoxComponent;

	float lifeTimer = 0;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//How fast the enemy will move.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "EnemyMovement")
	float speed = 100;

	// How long the enemy will exist before being destroyed.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "EnemyMovement")
	float lifetime = 10.0f;

	// How long the enemy will exist before being destroyed.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "EnemyHealth")
	int health = 1;

	// The Explosion.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "EnemyHealth")
	TSubclassOf<class AActor> Explosion;

	// Damage done to player on collision.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "EnemyDamage")
	int damage = 1;

	// Damage done to player on collision.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "EnemyDamage")
	int pointsForKill = 10;

	// Sound played when projectile is fired.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "EnemyDamage")
	class USoundBase* EnemyDeathSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "EnemyDamage")
	float EnemyDeathVolume = 1.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "EnemyDamage")
	float EnemyDeathPitchMin = 0.95f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "EnemyDamage")
	float EnemyDeathPitchMax = 1.05f;

	// The Pick Up Spawned.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "EnemyPickUp")
	TSubclassOf<class AActor> PickUpProjectile;

};
