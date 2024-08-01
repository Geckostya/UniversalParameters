#pragma once

#include "CoreMinimal.h"
#include "UP_FloatFunction.h"
#include "UP_FloatFunction_CurveTable.generated.h"


/**
 * FloatFunction which makes a math operation
 */
UCLASS(DisplayName="Curve Table")
class UNIVERSALPARAMETERS_API UUP_FloatFunction_CurveTable : public UUP_FloatFunction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Float Function", meta=(ShowOnlyInnerProperties))
	FCurveTableRowHandle RowHandle;
	
	virtual float Eval_Implementation(float Value) override;
};
