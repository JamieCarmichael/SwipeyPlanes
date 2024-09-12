// Fill out your copyright notice in the Description page of Project Settings.


#include "SwipeyPlanesController.h"
#include "EnhancedInputSubsystems.h"

void ASwipeyPlanesController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	//// Store a reference to the player pawn
	PlayerPawn = Cast<APlayerPawn>(aPawn);
	checkf(PlayerPawn, TEXT("No Pawn Found"));

	// Get a reference to the input component
	EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	checkf(EnhancedInputComponent, TEXT("No Input Component"));

	// Get local player subsystem
	UEnhancedInputLocalPlayerSubsystem* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	checkf(InputSubsystem, TEXT("Unable to get EnhancedInputLocalPlayerSubsystem"));

	 //Wipe existing mappings
	checkf(InputMappingContext, TEXT("Input Mapping Context was not specified."));
	InputSubsystem->ClearAllMappings();
	InputSubsystem->AddMappingContext(InputMappingContext, 0);

	 //Bind inputs
	if (ActionDown)
	{
		EnhancedInputComponent->BindAction(ActionDown, ETriggerEvent::Triggered, this, &ASwipeyPlanesController::HandleDown);
	}

	if (ActionUp)
	{
		EnhancedInputComponent->BindAction(ActionUp, ETriggerEvent::Triggered, this, &ASwipeyPlanesController::HandleUp);
	}
}

void ASwipeyPlanesController::OnUnPossess()
{
	// Unbind things here...
	EnhancedInputComponent->ClearActionBindings();

	// Call parents method
	Super::OnUnPossess();
}

void ASwipeyPlanesController::HandleDown(const FInputActionValue& InputActionValue)
{
	// Extract the Vector2D value from the InputActionValue
	FVector2D MoveValue1 = InputActionValue.Get<FVector2D>();
	//FVector move = FVector(MoveValue.X, 0, MoveValue.Y);

	//PlayerPawn->AddMovementInput(move, 1.0, false);

	UE_LOG(LogTemp, Log, TEXT("Down Value: X = %f, Y = %f"), MoveValue1.X, MoveValue1.Y);
}

void ASwipeyPlanesController::HandleUp(const FInputActionValue& InputActionValue)
{
	// Extract the Vector2D value from the InputActionValue
	FVector2D MoveValue2 = InputActionValue.Get<FVector2D>();


	UE_LOG(LogTemp, Log, TEXT("Up Value: X = %f, Y = %f"), MoveValue2.X, MoveValue2.Y);
}
