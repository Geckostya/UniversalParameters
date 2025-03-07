#include "FloatFunction/UP_FloatFunction_UnaryOperation.h"

float UUP_FloatFunction_UnaryOperation::Eval(float Value, const FUP_EvaluationContext* Context)
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

FString UUP_FloatFunction_UnaryOperation::GetPreviewName_Implementation() const
{
	switch (Operation)
	{
	case EUP_UnaryFunctionOperation::Negate:
		return TEXT("[-X]");

	case EUP_UnaryFunctionOperation::Abs:
		return TEXT("[|X|]");

	case EUP_UnaryFunctionOperation::Square:
		return TEXT("[X^2]");

	case EUP_UnaryFunctionOperation::Sqrt:
		return TEXT("Sqrt(X)");
	default: ;
	}
	return TEXT("??");
}
