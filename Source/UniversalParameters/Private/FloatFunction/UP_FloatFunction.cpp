#include "FloatFunction/UP_FloatFunction.h"

float UUP_FloatFunction::Eval_Implementation(float Value) 
{
	return 0.0f;
}

float UUP_FloatFunction::EvalSafe(UUP_FloatFunction* Function, float Value)
{
	return Function ? Function->Eval(Value) : 0;
}
