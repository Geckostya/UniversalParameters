#pragma once

#include "CoreMinimal.h"
#include "QL_FloatFunction.h"
#include "QL_FloatFunction_BinaryOperation.generated.h"

UENUM(BlueprintType)
enum class EQL_BinaryFunctionOperation : uint8
{
	Plus,
	Minus,
	Multiply,
	Divide,
};

class UQL_FloatProvider;

/**
 * FloatFunction which makes a math operation
 */
UCLASS(DisplayName="Binary Operation")
class QUALITYOFLIFE_API UQL_FloatFunction_BinaryOperation : public UQL_FloatFunction
{
	GENERATED_BODY()

public:
	UQL_FloatFunction_BinaryOperation(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Float Function")
	EQL_BinaryFunctionOperation Operation;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, NoClear, Category="Float Function")
	UQL_FloatProvider* SecondParam;
	
	virtual float Eval_Implementation(float Value) override;
};
