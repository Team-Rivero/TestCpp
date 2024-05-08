// Fill out your copyright notice in the Description page of Project Settings.


#include "BlueprintFunctionLibraryA.h"

FString UBlueprintFunctionLibraryA::GetPointlessMessage()
{
	return FString(TEXT("Restarting also updates it but is slower I guess."));
}