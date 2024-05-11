// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlayerControllerBB.h"
#include "CharacterBB.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

void AMyPlayerControllerBB::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	// Store a reference to the Player's Pawn
	PlayerCharacter = Cast<ACharacterBB>(aPawn);
	checkf(PlayerCharacter, TEXT("AMyPlayerControllerBB derived classes should only posess ACharacterBB derived pawns"));
	
	// Get a reference to the EnhancedInputComponent.
	EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	checkf(EnhancedInputComponent, TEXT("Unabled to get reference to the EnhancedInputComponent."));

	// Get the local player subsystem.
	UEnhancedInputLocalPlayerSubsystem* InputSubsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	checkf(InputSubsystem, TEXT("Unable to get reference to the EnhancedInputLocalPlayerSubsystem."));

	// Wipe existing mappings, and add our mapping.
	checkf(InputMappingContext, TEXT("InputMappingContent was not specified."));
	InputSubsystem->ClearAllMappings();
	InputSubsystem->AddMappingContext(InputMappingContext, 0);

	// Bind the input actions.
	// Only attempt to bind if a valid value was provided.
	if (ActionMove)
	{
		EnhancedInputComponent->BindAction(ActionMove, ETriggerEvent::Triggered, this,
			&AMyPlayerControllerBB::HandleMove);
	}
	if (ActionLook)
	{
		EnhancedInputComponent->BindAction(ActionLook, ETriggerEvent::Triggered, this,
			&AMyPlayerControllerBB::HandleLook);
	}
	if (ActionJump)
	{
		EnhancedInputComponent->BindAction(ActionJump, ETriggerEvent::Started, this,
			&AMyPlayerControllerBB::HandleJump);
	}
	if (ActionCrouch)
	{
		EnhancedInputComponent->BindAction(ActionCrouch, ETriggerEvent::Started, this,
			&AMyPlayerControllerBB::HandleCrouch);
	}
}

void AMyPlayerControllerBB::OnUnPossess()
{
	//Unbind things there...
	EnhancedInputComponent->ClearActionBindings();

	// Call the parent method, in case it needs to do anything.
	Super::OnUnPossess();
}

void AMyPlayerControllerBB::HandleMove(const FInputActionValue& InputActionValue)
{
	// Value is a vector2D
	const FVector2D MovementVector = InputActionValue.Get<FVector2D>();

	// Add movement to the player's character pawn
	if (PlayerCharacter)
	{
		PlayerCharacter->AddMovementInput(PlayerCharacter->GetActorForwardVector(), MovementVector.Y);
		PlayerCharacter->AddMovementInput(PlayerCharacter->GetActorRightVector(), MovementVector.X);
	}
}

void AMyPlayerControllerBB::HandleLook(const FInputActionValue& InputActionValue)
{
	// Input is a vector2D
	const FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();

	// Add yaw and pitch input to controller
	AddYawInput(LookAxisVector.X);
	AddPitchInput(LookAxisVector.Y);
}

void AMyPlayerControllerBB::HandleJump()
{
	// Input is 'Digital' (value not used here)

	// Make the Player's Character Pawn jump, disabling crouch if it was active
	if (PlayerCharacter)
	{
		PlayerCharacter->UnCrouch();
		PlayerCharacter->Jump();
	}
}

void AMyPlayerControllerBB::HandleCrouch()
{
	// Input is 'Digital' (value not used here)

	// Make the Player's Character Pawn crouch.
	if (PlayerCharacter)
	{
		PlayerCharacter->Crouch();
		// UE_LOG(LogTemp, Warning, TEXT("CROUCHING!!!"));
	}
}
