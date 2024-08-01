#pragma once

#include "CoreMinimal.h"
#include "UP_FloatFunction.h"
#include "UP_FloatFunction_UnaryOperation.generated.h"

UENUM(BlueprintType)
enum class EUP_UnaryFunctionOperation : uint8
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
class UNIVERSALPARAMETERS_API UUP_FloatFunction_UnaryOperation : public UUP_FloatFunction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Float Function")
	EUP_UnaryFunctionOperation Operation;
	
	virtual float Eval_Implementation(float Value) override;
};
