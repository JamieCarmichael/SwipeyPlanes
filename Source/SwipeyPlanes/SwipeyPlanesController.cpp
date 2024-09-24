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

void ASwipeyPlanesController::HandleTriggered(const FInputActionInstance& InputActionInstance)
{
	// Extract the Vector2D value from the InputActionValue
	FVector2D MoveValueTriggered = InputActionInstance.GetValue().Get<FVector2D>();
	FVector2D NewPosition = FVector2D(MoveValueTriggered.X, MoveValueTriggered.Y);

	FVector PawnLocation = PlayerPawn->GetActorLocation();
	// Vector2D to store the screen position
	FVector2D ScreenPosition;

	 //Convert to screen position
	ProjectWorldLocationToScreen(PawnLocation, ScreenPosition);

	FVector2D MoveValue = ScreenPosition - NewPosition;

	FVector MoveVector = FVector(-MoveValue.X, 0.0f, MoveValue.Y);
	float magnatude = MoveVector.Size();
	MoveVector.Normalize();

	if (PlayerPawn)
	{
		PlayerPawn->AddMovementInput(MoveVector, magnatude * speed);
	}
}
