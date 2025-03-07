#include "FloatProvider/UP_FloatProvider_Counter.h"

float UUP_FloatProvider_Counter::GetValue(const FUP_EvaluationContext* Context)
{
	return BaseValue += Delta;
}

FString UUP_FloatProvider_Counter::GetPreviewName_Implementation() const
{
	return FString::Printf(TEXT("[%.1f += %.1f]"), BaseValue, Delta);
}
