// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PlayerProjectileSpawner.h"
#include "PaperSpriteComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

UCLASS()
class SWIPEYPLANES_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

	// touch input Action
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Player Pawn")
	float TimeToMove = 3.0f;

	// touch input Action
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Player Pawn")
	int StartHealth = 5;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Player Pawn")
	int health = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Player Pawn")
	int score = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Pawn")
	FVector SpawnPosition = FVector(0, 0, 0);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Reduce player health
	UFUNCTION()
	void PlayerTakeDamage(int damage);

	// Add score to player
	UFUNCTION()
	void PlayerAddScore(int newScore);

	// Called when the player dies.
	UFUNCTION(BlueprintCallable)
	void OnPlayerDespawn();

	// Called when the player spawns.
	UFUNCTION(BlueprintCallable)
	void OnPlayerSpawn();

	// Add Projectiles.
	UFUNCTION(BlueprintCallable)
	void MoreProjectile();

	// Add Projectiles.
	UFUNCTION(BlueprintCallable)
	void RemoveProjectile();

	// Add Projectiles.
	UFUNCTION(BlueprintCallable)
	void ProjectilePowerUpTimer();

	// The Explosion.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Pawn")
	TSubclassOf<class AActor> Explosion;

	// The projectile being spawned.
	UPROPERTY(EditAnywhere, Category = "Player Pawn")
	UPaperSpriteComponent* PaperSprite;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Pawn")
	APlayerProjectileSpawner* ProjectileSpawner;

	// touch input Action
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Pawn")
	float speed = 2.0f;

	// touch input Action
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Pawn")
	float projectilePowerupTime = 10.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Pawn")
	int ProjectileCount = 1;


	// Sound when player hit.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Pawn")
	class USoundBase* PlayerDamageSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Pawn")
	float PlayerDamageVolume = 1.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Pawn")
	float PlayerDamagePitchMin = 0.95f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Pawn")
	float PlayerDamagePitchMax = 1.05f;


	// Sound when player killed.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Pawn")
	class USoundBase* PlayerDeathSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Pawn")
	float PlayerDeathVolume = 1.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Pawn")
	float PlayerDeathPitchMin = 0.95f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Pawn")
	float PlayerDeathPitchMax = 1.05f;

private:

	bool isActive = true;

	FVector Destination = FVector(0, 0, 0);
};
