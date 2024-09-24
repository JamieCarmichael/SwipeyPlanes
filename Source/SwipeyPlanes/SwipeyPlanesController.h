// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputComponent.h"
#include "PlayerPawn.h"
#include "InputMappingContext.h"
#include "SwipeyPlanesController.generated.h"

UCLASS()
class SWIPEYPLANES_API ASwipeyPlanesController : public APlayerController
{
	GENERATED_BODY()
	

public:
	// Input mapping context
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PlayerInput|CharacterMovement")
	TObjectPtr<UInputMappingContext> InputMappingContext = nullptr;

	// touch input Action
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PlayerInput|CharacterMovement")
	UInputAction* TouchAction = nullptr;

	// touch input Action
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PlayerInput|CharacterMovement")
	float speed = 100.0f;



protected:
	virtual void OnPossess(APawn* aPawn) override;
	virtual void OnUnPossess() override;

	void HandleTriggered(const FInputActionInstance& InputActionValue);

private:
	 //Used to store references for inputs
	UPROPERTY()
	UEnhancedInputComponent* EnhancedInputComponent = nullptr;

	UPROPERTY()
	APlayerPawn* PlayerPawn = nullptr;

	UPROPERTY()
	FVector2D StartedPosition = FVector2D(0,0);
	FVector2D LastPosition = FVector2D(0,0);
};
