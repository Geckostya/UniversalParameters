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
	virtual float Eval(float Value, const FUP_EvaluationContext* Context) override;

	virtual FString GetPreviewName_Implementation() const override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=UniversalParameters, meta=(ShowOnlyInnerProperties))
	FCurveTableRowHandle RowHandle;
};
