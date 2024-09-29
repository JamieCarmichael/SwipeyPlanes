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
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Pawn")
	float TimeToMove = 3.0f;

	// touch input Action
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Pawn")
	int StartHealth = 5;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Pawn")
	int health = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Pawn")
	int score = 0;


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
	UFUNCTION()
	void OnPlayerDeath();

	// The Explosion.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Health")
	TSubclassOf<class AActor> Explosion;

	// The projectile being spawned.
	UPROPERTY(EditAnywhere, Category = "Player Pawn")
	UPaperSpriteComponent* PaperSprite;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Pawn")
	APlayerProjectileSpawner* ProjectileSpawner;


private:

	FVector MovementVector = FVector(0, 0, 0);
	float MovementMagnatude = 0;

};
