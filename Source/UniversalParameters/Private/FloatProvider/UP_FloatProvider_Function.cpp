#include "FloatProvider/UP_FloatProvider_Function.h"

#include "FloatFunction/UP_FloatFunction.h"
#include "FloatProvider/UP_FloatProvider_Constant.h"

UUP_FloatProvider_Function::UUP_FloatProvider_Function(const FObjectInitializer& Initializer)
{
	Value = Initializer.CreateDefaultSubobject<UUP_FloatProvider_Constant>(this, "Then");
	Function = Initializer.CreateDefaultSubobject<UUP_FloatFunction>(this, "Else");
}

float UUP_FloatProvider_Function::GetValue_Implementation()
{
	return UUP_FloatFunction::EvalSafe(Function, GetValueSafe(Value));
}
