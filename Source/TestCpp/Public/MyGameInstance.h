// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include <Kismet/GameplayStatics.h>
#include "MyGameInstance.generated.h"

/**
 *	
 */

USTRUCT(BlueprintType)
struct FSavedVariables	//Struct named FAverages
{
	GENERATED_BODY()

	/* Create 3 Float Variables */
	UPROPERTY(BlueprintReadOnly)
	float Mean = 0.0f;

	UPROPERTY(BlueprintReadOnly)
	float Modal = 0.0f;

	UPROPERTY(BlueprintReadOnly)
	float Median = 0.0f;
};

UCLASS()
class TESTCPP_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static void SavedVariablesCPP(FSavedVariables& SavedVariables, UMyGameInstance*& MGI);

private:

};
