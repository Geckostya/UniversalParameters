#pragma once

#include "CoreMinimal.h"
#include "UP_FloatFunction.h"
#include "UP_FloatFunction_BinaryOperation.generated.h"

UENUM(BlueprintType)
enum class EUP_BinaryFunctionOperation : uint8
{
	Plus,
	Minus,
	Multiply,
	Divide,
};

class UUP_FloatProvider;

/**
 * FloatFunction which makes a math operation
 */
UCLASS(DisplayName="Binary Operation")
class UNIVERSALPARAMETERS_API UUP_FloatFunction_BinaryOperation : public UUP_FloatFunction
{
	GENERATED_BODY()

public:
	UUP_FloatFunction_BinaryOperation(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Float Function")
	EUP_BinaryFunctionOperation Operation;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, NoClear, Category="Float Function")
	UUP_FloatProvider* SecondParam;
	
	virtual float Eval_Implementation(float Value) override;
};
