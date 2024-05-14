// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerControllerBB.generated.h"

// Forward Declarations
class UEnhancedInputComponent;
class ACharacterBB;
class UInputMappingContext;
class AHudBB;

UCLASS(Abstract)
class TESTCPP_API AMyPlayerControllerBB : public APlayerController
{
	GENERATED_BODY()
	
public:
	// The Input Mapping Context to use.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Input|Character Movement")	//Category creates tabs
	TObjectPtr<UInputMappingContext> InputMappingContext = nullptr;

	// The Input Action to map to movement.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Input|Character Movement")
	TObjectPtr<UInputAction> ActionMove = nullptr;

	//The Input Action to map to looking around.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Input|Character Movement")
	TObjectPtr<UInputAction> ActionLook = nullptr;

	//The Input Action to map to jumping.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Input|Character Movement")
	TObjectPtr<UInputAction> ActionJump = nullptr;

	//The Input Action to map to Crouching.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Input|Character Movement")
	TObjectPtr<UInputAction> ActionCrouch = nullptr;

	//The Input Action to map to Sprinting.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Input|Character Movement")
	TObjectPtr<UInputAction> ActionSprint = nullptr;

	//The Input Action to map to Blasting.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Input|Character Movement")
	TObjectPtr<UInputAction> ActionBlast = nullptr;

	//The Input Action to map to Blasting.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Input|UI")
	TObjectPtr<UInputAction> ActionCycleUIMode = nullptr;

protected:
	virtual void OnPossess(APawn* aPawn) override;
	virtual void OnUnPossess() override;

	void HandleMove(const FInputActionValue& InputActionValue);
	void HandleLook(const FInputActionValue& InputActionValue);
	void HandleJump();
	void Crouching();
	void Sprint();
	void Blast();
	void CycleUIMode();

private:
	// Used to store a reference to the InputComponent cast to an EnhancedInputComponent.
	UPROPERTY()
	UEnhancedInputComponent* EnhancedInputComponent = nullptr;

	//Used to store a reference to the pawn we are controlling.
	UPROPERTY()
	ACharacterBB* PlayerCharacter = nullptr;

	UPROPERTY()
	TObjectPtr<AHudBB> PlayerHud = nullptr;
};
