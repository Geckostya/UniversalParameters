#include "FloatFunction/QL_FloatFunction_BinaryOperation.h"

#include "FloatProvider/QL_FloatProvier_Constant.h"

UQL_FloatFunction_BinaryOperation::UQL_FloatFunction_BinaryOperation(const FObjectInitializer& ObjectInitializer)
{
	SecondParam = ObjectInitializer.CreateDefaultSubobject<UQL_FloatProvier_Constant>(this, "SecondParam");
}

float UQL_FloatFunction_BinaryOperation::Eval_Implementation(float Value)
{
	switch (Operation)
	{
	case EQL_BinaryFunctionOperation::Plus:
		return Value + UQL_FloatProvider::GetValueSafe(SecondParam);
		
	case EQL_BinaryFunctionOperation::Minus:
		return Value - UQL_FloatProvider::GetValueSafe(SecondParam);
		
	case EQL_BinaryFunctionOperation::Multiply:
		return Value * UQL_FloatProvider::GetValueSafe(SecondParam);
		
	case EQL_BinaryFunctionOperation::Divide:
		return Value / UQL_FloatProvider::GetValueSafe(SecondParam);
	default: ;
	}
	return 0;
}
