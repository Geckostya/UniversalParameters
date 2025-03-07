#include "FloatFunction/UP_FloatFunction_CurveTable.h"

float UUP_FloatFunction_CurveTable::Eval(float Value, const FUP_EvaluationContext* Context)
{
	return RowHandle.Eval(Value, "FloatFunction_CurveTable");
}

FString UUP_FloatFunction_CurveTable::GetPreviewName_Implementation() const
{
	return GetNameSafe(RowHandle.CurveTable) + ":" + RowHandle.RowName.ToString();
}
