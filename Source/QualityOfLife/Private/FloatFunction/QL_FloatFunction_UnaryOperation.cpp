#include "FloatFunction/QL_FloatFunction_UnaryOperation.h"

float UQL_FloatFunction_UnaryOperation::Eval_Implementation(float Value)
{
	switch (Operation)
	{
	case EQL_UnaryFunctionOperation::Negate:
		return -Value;
		
	case EQL_UnaryFunctionOperation::Abs:
		return FMath::Abs(Value);
		
	case EQL_UnaryFunctionOperation::Square:
		return FMath::Square(Value);
		
	case EQL_UnaryFunctionOperation::Sqrt:
		return FMath::Sqrt(Value);
	default: ;
	}
	return 0;
}
