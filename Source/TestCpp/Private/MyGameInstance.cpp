// Fill out your copyright notice in the Description page of Project Settings.

#include <Kismet/GameplayStatics.h>
#include "MyGameInstance.h"

FSavedVariables UMyGameInstance::SavedVariablesCPP(UMyGameInstance* Test)
{
	/*UMyGameInstance* DyNamic_PureCast_Ret{};
	UGameInstance* GameInstance_Ret = UGameplayStatics::GetGameInstance(this);
	DyNamic_PureCast_Ret = Cast<UMyGameInstance>(GameInstance_Ret);*/

	//Test = DyNamic_PureCast_Ret;

	Test;
	return FSavedVariables();
}
