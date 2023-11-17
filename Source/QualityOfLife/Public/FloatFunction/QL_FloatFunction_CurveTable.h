#pragma once

#include "CoreMinimal.h"
#include "QL_FloatFunction.h"
#include "QL_FloatFunction_CurveTable.generated.h"


/**
 * FloatFunction which makes a math operation
 */
UCLASS(DisplayName="Curve Table")
class QUALITYOFLIFE_API UQL_FloatFunction_CurveTable : public UQL_FloatFunction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Float Function", meta=(ShowOnlyInnerProperties))
	FCurveTableRowHandle RowHandle;
	
	virtual float Eval_Implementation(float Value) override;
};
