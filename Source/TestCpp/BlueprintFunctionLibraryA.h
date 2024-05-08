// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BlueprintFunctionLibraryA.generated.h"

/* Getting Started with C++ practical examples. */
UCLASS()
class TESTCPP_API UBlueprintFunctionLibraryA : public UBlueprintFunctionLibrary
{
	public:
		/*A completely pointless function that just returns a canned string message. */
		UFUNCTION(BlueprintCallable)
		static FString GetPointlessMessage();
	
	protected:
	
	private:
		GENERATED_BODY()
};
