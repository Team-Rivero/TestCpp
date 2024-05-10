// Fill out your copyright notice in the Description page of Project Settings.


#include "BlueprintFunctionLibraryA.h"

FString UBlueprintFunctionLibraryA::GetPointlessMessage()
{
	return FString(TEXT("Rename 2"));
}

double UBlueprintFunctionLibraryA::GetMyPi()
{
	return Pi;
}

int32 UBlueprintFunctionLibraryA::MyCoolFunction(const float input)
{
	float Printpi = input;

	return Printpi;
}

FAverages UBlueprintFunctionLibraryA::CalculateAverages(const TArray<int32>& InValues)
{
	/* Duplicate the array, as we don't want to mess with the original. */
	TArray<int32> TmpArray = InValues;
	TMap<int32, int32> ModalCount;

	float CalcMean = 0.0f;
	float CalcModal = 0.0f;
	float CalcMedian = 0.0f;
	float Sum = 0;
	const int32 Count = TmpArray.Num();

	/* Just in case some clown passed in an empty array! */
	if (Count == 0) return FAverages();

	/* Put the values in order */
	TmpArray.Sort();

	for (int i = 0; i < Count; ++i)
	{
		/* Add each value together, to calculate the 'mean'. */
		Sum += TmpArray[i];

		/* Count how many times specific values are represented, to calculate the 'mode'. */
		if (ModalCount.Contains(TmpArray[i]))
		{
			ModalCount[TmpArray[i]]++; //Value is already in there, add 1 to it.
		}
		else
		{
			ModalCount.Add(TmpArray[i], 1); //Value was not encountered before, add it.
		}
	}

	/* The overall total divided by the number of items is the mean */
	CalcMean = Sum / static_cast<float>(Count);

	/* The number in the middle of the ordered set is the median if the set contains an odd number of items,
	if the set has an even number of items, it is the arithmetic mean of the two in the middle. */
	CalcMedian = Count % 2 != 0
		? TmpArray[Count / 2]
		: static_cast<float>((TmpArray[(Count / 2) - 1] + TmpArray[Count / 2])) / 2;

	/*The modal number is the most frequent occurring number in the set.
	if several numbers occur equally more than the others, then it is the arithmetic mean of those numbers. */

	/* Sort values from high to low */
	ModalCount.ValueSort([](int32 A, int32 B) { return A > B; });

	/* Easier to deal with an array now
	each Tpair item is [Number, Frequency] */
	TArray<TPair<int32, int32>> Modals = ModalCount.Array();

	/* If the first key has a count (value) of 1, it means each key is unique, so just use the mean. */
	if (Modals[0].Value == 1)
	{
		CalcModal = CalcMean;
	}
	else
	{
		int32 ModalEntries = 1;
		int32 ModalSum = Modals[0].Key;

		/* As the array was sorted on the frequency of each item, element 0 is either the modal value,
		or the first in a group of values sharing the highest frequency. */
		for (int i = 1; i < Modals.Num(); ++i)
		{
			if (Modals[i].Value != Modals[0].Value) break;
			ModalSum += Modals[i].Key;
			ModalEntries++;
		}

		CalcModal = static_cast<float>(ModalSum) / static_cast<float>(ModalEntries);
	}

	return FAverages(CalcMean, CalcModal, CalcMedian);
}