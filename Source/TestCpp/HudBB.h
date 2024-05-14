#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "HudBB.generated.h"

class ACharacterBB;
class UMinimalLayoutBase;
class UModerateLayoutBase;
class UOverloadLayoutBase;

UENUM(BlueprintType)
enum class EHudViewMode : uint8
{
	CleanAndPristine UMETA(Tooltip = "Get that mess outta my face!"),
	Minimal UMETA(Tooltip = "Just the facts, man."),
	Moderate UMETA(Tooltip = "Keep me well informed."),
	SensoryOverload UMETA(Tooltip = "My other UI is derivatives trading screen")
};

inline EHudViewMode& operator++(EHudViewMode& ViewMode)
{
	if (ViewMode == EHudViewMode::SensoryOverload)
	{
		ViewMode = EHudViewMode::CleanAndPristine;
	}
	else
	{
		ViewMode = static_cast<EHudViewMode>(static_cast<int>(ViewMode) + 1);
	}
	
	return ViewMode;
}

inline EHudViewMode& operator--(EHudViewMode& ViewMode)
{
	if (ViewMode == EHudViewMode::CleanAndPristine)
		ViewMode = EHudViewMode::SensoryOverload;
	else
		ViewMode = static_cast<EHudViewMode>(static_cast<int>(ViewMode) - 1);
	return ViewMode;
}

UCLASS()
class TESTCPP_API AHudBB : public AHUD
{
	GENERATED_BODY()

public:

	//Allow code and blueprints to put the hud in a specific viewmod directly
	//Possibly useful for cinematic cutscenes etc?
	UFUNCTION(BlueprintCallable)
	void SetCurrentViewMode(EHudViewMode NewViewMode);

	//Change to the next viewmode
	UFUNCTION(BlueprintCallable)
	void CycleToNextViewMode();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	//Determines what UI elements should be displayed
	UPROPERTY(EditAnywhere)
	EHudViewMode CurrentViewMode = EHudViewMode::Moderate;

	//Whenever we change the view mode, this private function is valled to show a
	void UpdateWidgets();

	//Release any delegate bindings.
	void ClearAllHandlers();
};
