#pragma once

#include "CoreMinimal.h"
#include "QL_FloatFunction.h"
#include "QL_FloatFunction_UnaryOperation.generated.h"

UENUM(BlueprintType)
enum class EQL_UnaryFunctionOperation : uint8
{
	Negate,
	Abs,
	Square,
	Sqrt,
};

/**
 * FloatFunction which makes a math operation
 */
UCLASS(DisplayName="Unary Operation")
class QUALITYOFLIFE_API UQL_FloatFunction_UnaryOperation : public UQL_FloatFunction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Float Function")
	EQL_UnaryFunctionOperation Operation;
	
	virtual float Eval_Implementation(float Value) override;
};
