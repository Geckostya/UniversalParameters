#include "FloatFunction/QL_FloatFunction.h"

float UQL_FloatFunction::Eval_Implementation(float Value) 
{
	return 0.0f;
}

float UQL_FloatFunction::EvalSafe(UQL_FloatFunction* Function, float Value)
{
	return Function ? Function->Eval(Value) : 0;
}
