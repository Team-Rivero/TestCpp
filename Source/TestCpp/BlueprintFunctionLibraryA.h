﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BlueprintFunctionLibraryA.generated.h"

USTRUCT(BlueprintType)
struct FAverages	//Struct named FAverages
{
	/* Create 3 Float Variables */
	UPROPERTY(BlueprintReadOnly)
	float Mean = 0.0f;

	UPROPERTY(BlueprintReadOnly)
	float Modal = 0.0f;

	UPROPERTY(BlueprintReadOnly)
	float Median = 0.0f;

	/* Define struct default values */
	FAverages() :
		Mean(0.0f),
		Modal(0.0f),
		Median(0.0f) {};

	/* Allows you to pass in 3 separate values */
	FAverages(float InMean, float InMode, float InMedian) :
		Mean(InMean),
		Modal(InMode),
		Median(InMedian) {};
	
	GENERATED_BODY()
};

/* Getting Started with C++ practical examples. */
UCLASS()
class TESTCPP_API UBlueprintFunctionLibraryA : public UBlueprintFunctionLibrary
{
	public:
		/*A completely pointless function that just returns a canned string message. */
		UFUNCTION(BlueprintCallable)	//Needed otherwise can't be called from blueprint graph
		static FString GetPointlessMessage();

		/*No different than the PI node blueprints already provide,
		but this one is better because it uses the π character! */
		UFUNCTION(BlueprintCallable,
			BlueprintPure,	//No execution pins
			meta = (ToolTip = "3.1415BlahBlahBlah ... ",	//Tooltip when hovered
				CompactNodeTitle = "π"))	//Main Node text
		static double GetMyPi();

		/*Calculates the three main types of statistical averages. */
		UFUNCTION(BlueprintCallable,
			meta = (ToolTip = "Calculates the mean, mode, and median for an array of integer values. "))
		static FAverages CalculateAverages(const TArray<int32>& InValues);
	
	protected:
	
	private:
		static constexpr double Pi = 3.1415926535897932384626433832795;	//constenxpr just means const? 

		GENERATED_BODY()
};
