#include "FloatFunction/UP_FloatFunction_BinaryOperation.h"

#include "FloatProvider/UP_FloatProvider_Constant.h"

UUP_FloatFunction_BinaryOperation::UUP_FloatFunction_BinaryOperation(const FObjectInitializer& ObjectInitializer)
{
	SecondParam = ObjectInitializer.CreateDefaultSubobject<UUP_FloatProvider_Constant>(this, "SecondParam");
}

float UUP_FloatFunction_BinaryOperation::Eval_Implementation(float Value)
{
	switch (Operation)
	{
	case EUP_BinaryFunctionOperation::Plus:
		return Value + UUP_FloatProvider::GetValueSafe(SecondParam);
		
	case EUP_BinaryFunctionOperation::Minus:
		return Value - UUP_FloatProvider::GetValueSafe(SecondParam);
		
	case EUP_BinaryFunctionOperation::Multiply:
		return Value * UUP_FloatProvider::GetValueSafe(SecondParam);
		
	case EUP_BinaryFunctionOperation::Divide:
		return Value / UUP_FloatProvider::GetValueSafe(SecondParam);
	default: ;
	}
	return 0;
}
