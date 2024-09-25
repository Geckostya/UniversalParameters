#include "FloatFunction/UP_FloatFunction_BinaryOperation.h"

#include "FloatProvider/UP_FloatProvider_Constant.h"

UUP_FloatFunction_BinaryOperation::UUP_FloatFunction_BinaryOperation(const FObjectInitializer& ObjectInitializer)
{
	SecondParam = ObjectInitializer.CreateDefaultSubobject<UUP_FloatProvider_Constant>(this, "SecondParam");
}

float UUP_FloatFunction_BinaryOperation::Eval(float Value, const FUP_EvaluationContext* Context)
{
	float SecondValue = UUP_FloatProvider::GetValueSafe(SecondParam, Context);

	switch (Operation)
	{
	case EUP_BinaryFunctionOperation::Plus:
		return Value + SecondValue;
		
	case EUP_BinaryFunctionOperation::Minus:
		return Value - SecondValue;
		
	case EUP_BinaryFunctionOperation::Multiply:
		return Value * SecondValue;
		
	case EUP_BinaryFunctionOperation::Divide:
		return Value / SecondValue;
	default: ;
	}
	return 0;
}

void UUP_FloatFunction_BinaryOperation::GetBBKeys(TArray<FBlackboardKeySelector*>& Keys)
{
	GetBBKeysSafe(SecondParam, Keys);
}
