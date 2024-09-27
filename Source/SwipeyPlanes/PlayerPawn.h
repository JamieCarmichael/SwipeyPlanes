// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

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
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement")
	float TimeToMove = 3.0f;

	// touch input Action
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Health")
	int StartHealth = 5;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly)
	int health = 0;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Correctly defined overlap function
	UFUNCTION()
	void TakeDamage(int damage);

	// Called when the playuer dies.
	UFUNCTION()
	void OnPlayerDeath();

	// The Explosion.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Health")
	TSubclassOf<class AActor> Explosion;

	// The projectile being spawned.
	UPROPERTY(EditAnywhere, Category = "Player Health")
	UPaperSpriteComponent* PaperSprite;


private:

	FVector MovementVector = FVector(0, 0, 0);
	float MovementMagnatude = 0;

};
