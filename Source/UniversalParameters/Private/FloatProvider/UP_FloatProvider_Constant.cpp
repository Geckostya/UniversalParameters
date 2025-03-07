#include "FloatProvider/UP_FloatProvider_Constant.h"

float UUP_FloatProvider_Constant::GetValue(const FUP_EvaluationContext* Context)
{
	return Value;
}

FString UUP_FloatProvider_Constant::GetPreviewName_Implementation() const
{
	return FString::SanitizeFloat(Value);
}
