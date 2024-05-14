#include "HudBB.h"

void AHudBB::BeginPlay()
{

}

void AHudBB::EndPlay(const EEndPlayReason::Type EndPlayReason)
{

}

void AHudBB::SetCurrentViewMode(EHudViewMode NewViewMode)
{

}

void AHudBB::CycleToNextViewMode()
{
	++CurrentViewMode;	//Operator Overloading?
	UE_LOG(LogTemp, Warning, TEXT("CycleToNextViewMode %s"), *UEnum::GetValueAsString(CurrentViewMode));
	UpdateWidgets();
}

void AHudBB::UpdateWidgets()
{

}

void AHudBB::ClearAllHandlers()
{

}