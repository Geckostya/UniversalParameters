#include "FloatProvider/QL_FloatProvider_Function.h"

#include "FloatFunction/QL_FloatFunction.h"
#include "FloatProvider/QL_FloatProvier_Constant.h"

UQL_FloatProvider_Function::UQL_FloatProvider_Function(const FObjectInitializer& Initializer)
{
	Value = Initializer.CreateDefaultSubobject<UQL_FloatProvier_Constant>(this, "Then");
	Function = Initializer.CreateDefaultSubobject<UQL_FloatFunction>(this, "Else");
}

float UQL_FloatProvider_Function::GetValue_Implementation()
{
	return UQL_FloatFunction::EvalSafe(Function, GetValueSafe(Value));
}
