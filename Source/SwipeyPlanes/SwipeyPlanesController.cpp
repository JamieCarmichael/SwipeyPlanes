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

	UE_LOG(LogTemp, Log, TEXT("Started Value: X = %f, Y = %f"), MoveValueStarted.X, MoveValueStarted.Y);

	StartedPosition = FVector(MoveValueStarted.X, MoveValueStarted.Y, 0.0f);
}

void ASwipeyPlanesController::HandleComplete(const FInputActionInstance& InputActionInstance)
{
	// Extract the Vector2D value from the InputActionValue
	FVector2D MoveValueComplete = InputActionInstance.GetValue().Get<FVector2D>();

	UE_LOG(LogTemp, Log, TEXT("Complete Value: X = %f, Y = %f"), MoveValueComplete.X, MoveValueComplete.Y);

	FVector MoveVector = FVector(MoveValueComplete.Y, MoveValueComplete.X, 0.0f);
	MoveVector = MoveVector - StartedPosition;
	MoveVector.Normalize();

	UE_LOG(LogTemp, Log, TEXT("Swipe Direction: X = %f, Y = %f"), MoveVector.X, MoveVector.Y);

}

void ASwipeyPlanesController::HandleTriggered(const FInputActionInstance& InputActionInstance)
{
	// Extract the Vector2D value from the InputActionValue
	FVector2D MoveValueTriggered = InputActionInstance.GetValue().Get<FVector2D>();

	UE_LOG(LogTemp, Log, TEXT("Triggered Value: X = %f, Y = %f"), MoveValueTriggered.X, MoveValueTriggered.Y);

	FVector PawnLocation = PlayerPawn->GetActorLocation();

	// Vector2D to store the screen position
	FVector2D ScreenPosition;

	// Convert to screen position
	ProjectWorldLocationToScreen(PawnLocation, ScreenPosition);

	UE_LOG(LogTemp, Log, TEXT("Screen Location: X = %f, Y = %f"), ScreenPosition.X, ScreenPosition.Y);
	UE_LOG(LogTemp, Log, TEXT("Pawn Location: X = %f, Y = %f"), PawnLocation.X, PawnLocation.Y);

	FVector MoveVector = FVector(ScreenPosition.Y - MoveValueTriggered.Y, MoveValueTriggered.X - ScreenPosition.X, 0.0f);
	UE_LOG(LogTemp, Log, TEXT("Move Vector UnNormal: X = %f, Y = %f, Z = %f"), MoveVector.X, MoveVector.Y, MoveVector.Z);
	MoveVector.Normalize();

	if (PlayerPawn)
	{
		PlayerPawn->AddMovementInput(MoveVector, speed);
		UE_LOG(LogTemp, Log, TEXT("MoveVector Normal: X = %f, Y = %f, Z = %f"), MoveVector.X, MoveVector.Y, MoveVector.Z);
	}
}
