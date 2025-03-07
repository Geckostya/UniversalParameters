#pragma once

#include "CoreMinimal.h"
#include "UP_FloatFunction.h"
#include "UP_FloatFunction_Identity.generated.h"

/**
 * Basic FloatFunction that returns the same value
 */
UCLASS(DisplayName="Identity")
class UNIVERSALPARAMETERS_API UUP_FloatFunction_Identity : public UUP_FloatFunction
{
	GENERATED_BODY()

public:
	virtual float Eval(float Value, const FUP_EvaluationContext* Context) override;

	virtual FString GetPreviewName_Implementation() const override;
};
