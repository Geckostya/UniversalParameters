#include "FloatProvider/UP_FloatProvider_Function.h"

#include "FloatFunction/UP_FloatFunction.h"
#include "FloatProvider/UP_FloatProvider_Constant.h"

UUP_FloatProvider_Function::UUP_FloatProvider_Function(const FObjectInitializer& Initializer)
{
	Value = Initializer.CreateDefaultSubobject<UUP_FloatProvider_Constant>(this, "Then");
	Function = Initializer.CreateDefaultSubobject<UUP_FloatFunction>(this, "Else");
}

float UUP_FloatProvider_Function::GetValue(const FUP_EvaluationContext* Context)
{
	return UUP_FloatFunction::EvalSafe(Function, GetValueSafe(Value, Context), Context);
}

void UUP_FloatProvider_Function::GetBBKeys(TArray<FBlackboardKeySelector*>& Keys)
{
	GetBBKeysSafe(Value, Keys);
	GetBBKeysSafe(Function, Keys);
}
