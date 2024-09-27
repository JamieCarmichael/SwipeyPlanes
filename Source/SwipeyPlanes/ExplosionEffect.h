// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PaperFlipbookComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExplosionEffect.generated.h"

UCLASS()
class SWIPEYPLANES_API AExplosionEffect : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AExplosionEffect();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// How long the projectile will exist before being destroyed.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Explosion")
	float liftime = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Explosion")
	UPaperFlipbook* ExplosionFlipbook;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Explosion")
	UPaperFlipbookComponent* FlipbookComponent;

	// Function to clean up the explosion effect after it finishes
	void HandleDestruction();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
