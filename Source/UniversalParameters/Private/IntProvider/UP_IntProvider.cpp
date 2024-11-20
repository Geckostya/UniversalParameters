// Fill out your copyright notice in the Description page of Project Settings.


#include "IntProvider/UP_IntProvider.h"

int32 UUP_IntProvider::GetValue_BP()
{
	return GetValue(nullptr);
}

int32 UUP_IntProvider::GetValue(const FUP_EvaluationContext* Context)
{
	return 0;
}

int32 UUP_IntProvider::GetValueWithContext_BP(const UObject* ContextObject)
{
	const auto Context = TryGetContextFromObject(ContextObject);
	return GetValue(Context.Get());
}
