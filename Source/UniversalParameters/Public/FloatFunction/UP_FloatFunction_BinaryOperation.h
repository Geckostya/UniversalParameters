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

	virtual float Eval(float Value, const FUP_EvaluationContext* Context) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=UniversalParameters)
	EUP_BinaryFunctionOperation Operation;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, NoClear, Category=UniversalParameters)
	UUP_FloatProvider* SecondParam;	

protected:
	virtual void GetBBKeys(TArray<FBlackboardKeySelector*>& Keys) override;
};
