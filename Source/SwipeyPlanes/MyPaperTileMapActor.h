// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperTileMapActor.h"
#include "MyPaperTileMapActor.generated.h"

UCLASS()
class SWIPEYPLANES_API AMyPaperTileMapActor : public APaperTileMapActor
{
	GENERATED_BODY()

public:
	AMyPaperTileMapActor();

	// movement speed
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MovementAttributes")
	float speed = 1.0f;

	// How far too move when passing point. Half the map size.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MovementAttributes")
	float teleportMove = 640.0f;

	// The point that the teleport is done
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MovementAttributes")
	float movePoint = 300.0f;

	// The point that the teleport is done
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MovementAttributes")
	FVector moveDirection;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

};
