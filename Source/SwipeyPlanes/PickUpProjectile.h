// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/BoxComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickUpProjectile.generated.h"

UCLASS()
class SWIPEYPLANES_API APickUpProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUpProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Correctly defined overlap function
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// Reference to the BoxComponent for collision detection
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBoxComponent* MyBoxComponent;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//How fast the enemy will move.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PickUp")
	float speed = 50.0f;

	// How long the enemy will exist before being destroyed.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PickUp")
	float lifetime = 10.0f;

private:
	float lifeTimer = 0;

};
