// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatProvider/UP_FloatProvider_CurveTable.h"

float UUP_FloatProvider_CurveTable::GetValue(const FUP_EvaluationContext* Context)
{
	return RowHandle.Eval(1, "FloatProvider_CurveTable");
}

FString UUP_FloatProvider_CurveTable::GetPreviewName_Implementation() const
{
	return GetNameSafe(RowHandle.CurveTable) + ":" + RowHandle.RowName.ToString();
}
