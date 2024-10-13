// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyBasic.h"
#include "EnemyFollow.generated.h"

/**
 * 
 */
UCLASS()
class SWIPEYPLANES_API AEnemyFollow : public AEnemyBasic
{
	GENERATED_BODY()

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
