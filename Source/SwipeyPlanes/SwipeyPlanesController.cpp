// Fill out your copyright notice in the Description page of Project Settings.


#include "SwipeyPlanesController.h"
#include "EnhancedInputSubsystems.h"
#include "PlayerPawn.h"

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
	if (TouchAction)
	{
		EnhancedInputComponent->BindAction(TouchAction, ETriggerEvent::Started, this, &ASwipeyPlanesController::HandleStarted);
		EnhancedInputComponent->BindAction(TouchAction, ETriggerEvent::Completed, this, &ASwipeyPlanesController::HandleComplete);
		EnhancedInputComponent->BindAction(TouchAction, ETriggerEvent::Triggered, this, &ASwipeyPlanesController::HandleTriggered);
	}
}

void ASwipeyPlanesController::OnUnPossess()
{
	// Unbind things here...
	EnhancedInputComponent->ClearActionBindings();

	// Call parents method
	Super::OnUnPossess();
}

void ASwipeyPlanesController::HandleStarted(const FInputActionInstance& InputActionInstance)
{
	// Extract the Vector2D value from the InputActionValue
	FVector2D MoveValueStarted = InputActionInstance.GetValue().Get<FVector2D>();

	StartedPosition = FVector2D(MoveValueStarted.X, MoveValueStarted.Y);
}

void ASwipeyPlanesController::HandleComplete(const FInputActionInstance& InputActionInstance)
{
	// Extract the Vector2D value from the InputActionValue
	FVector2D MoveValue = StartedPosition - LastPosition;


	FVector MoveVector = FVector(MoveValue.Y, -MoveValue.X, 0.0f);
	float magnatude = MoveVector.Size();
	MoveVector.Normalize();

	if (PlayerPawn)
	{
		PlayerPawn->AddMovementInput(MoveVector, magnatude * speed);
	}
}

void ASwipeyPlanesController::HandleTriggered(const FInputActionInstance& InputActionInstance)
{
	// Extract the Vector2D value from the InputActionValue
	FVector2D MoveValueTriggered = InputActionInstance.GetValue().Get<FVector2D>();
	LastPosition = FVector2D(MoveValueTriggered.X, MoveValueTriggered.Y);

	FVector PawnLocation = PlayerPawn->GetActorLocation();

	// Vector2D to store the screen position
	//FVector2D ScreenPosition;

	// Convert to screen position
	//ProjectWorldLocationToScreen(PawnLocation, ScreenPosition);

	//FVector MoveVector = FVector(ScreenPosition.Y - MoveValueTriggered.Y, MoveValueTriggered.X - ScreenPosition.X, 0.0f);

	//MoveVector.Normalize();

	//if (PlayerPawn)
	//{
	//	PlayerPawn->AddMovementInput(MoveVector, speed);
	//}
}
