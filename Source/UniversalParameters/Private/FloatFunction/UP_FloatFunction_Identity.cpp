#include "FloatFunction/UP_FloatFunction_Identity.h"

float UUP_FloatFunction_Identity::Eval(float Value, const FUP_EvaluationContext* Context)
{
	return Value;
}

FString UUP_FloatFunction_Identity::GetPreviewName_Implementation() const
{
	return "Id";
}
