// Fill out your copyright notice in the Description page of Project Settings.


#include "IntProvider/UP_IntProvider_RandomRange.h"

#include "IntProvider/UP_IntProvider_Constant.h"

UUP_IntProvider_RandomRange::UUP_IntProvider_RandomRange(const FObjectInitializer& Initializer)
{
	From = Initializer.CreateDefaultSubobject<UUP_IntProvider_Constant>(this, "From");
	To = Initializer.CreateDefaultSubobject<UUP_IntProvider_Constant>(this, "To");
}

int32 UUP_IntProvider_RandomRange::GetValue(const FUP_EvaluationContext* Context)
{
	return FMath::RandRange(GetValueSafe(From, Context), GetValueSafe(To, Context));
}

void UUP_IntProvider_RandomRange::GetBBKeys(TArray<FBlackboardKeySelector*>& Keys)
{
	GetBBKeysSafe(From, Keys);
	GetBBKeysSafe(To, Keys);
}
