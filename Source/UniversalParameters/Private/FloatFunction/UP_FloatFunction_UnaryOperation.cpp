#include "FloatFunction/UP_FloatFunction_UnaryOperation.h"

float UUP_FloatFunction_UnaryOperation::Eval_Implementation(float Value)
{
	switch (Operation)
	{
	case EUP_UnaryFunctionOperation::Negate:
		return -Value;
		
	case EUP_UnaryFunctionOperation::Abs:
		return FMath::Abs(Value);
		
	case EUP_UnaryFunctionOperation::Square:
		return FMath::Square(Value);
		
	case EUP_UnaryFunctionOperation::Sqrt:
		return FMath::Sqrt(Value);
	default: ;
	}
	return 0;
}
