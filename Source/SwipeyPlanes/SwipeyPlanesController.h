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

	// Down Action
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PlayerInput|CharacterMovement")
	UInputAction* ActionDown = nullptr;

	// Up Action
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PlayerInput|CharacterMovement")
	UInputAction* ActionUp = nullptr;


protected:
	virtual void OnPossess(APawn* aPawn) override;
	virtual void OnUnPossess() override;

	void HandleDown(const FInputActionValue& InputActionValue);
	void HandleUp(const FInputActionValue& InputActionValue);

private:
	 //Used to store references for inputs
	UPROPERTY()
	UEnhancedInputComponent* EnhancedInputComponent = nullptr;

	UPROPERTY()
	APlayerPawn* PlayerPawn = nullptr;
};
