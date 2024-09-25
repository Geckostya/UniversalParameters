#include "FloatFunction/UP_FloatFunction.h"

float UUP_FloatFunction::Eval_BP(float Value)
{
	return Eval(Value, nullptr);
}

float UUP_FloatFunction::Eval(float Value, const FUP_EvaluationContext* Context)
{
	return 0.0f;
}