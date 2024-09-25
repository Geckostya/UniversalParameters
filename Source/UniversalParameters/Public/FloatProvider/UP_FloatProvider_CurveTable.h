// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UP_FloatProvider.h"
#include "UP_FloatProvider_CurveTable.generated.h"

/**
 * FloatProvider that gets first value from the curve table
 */
UCLASS(DisplayName="Curve Table")
class UNIVERSALPARAMETERS_API UUP_FloatProvider_CurveTable : public UUP_FloatProvider
{
	GENERATED_BODY()
public:
	virtual float GetValue(const FUP_EvaluationContext* Context) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=UniversalParameters, meta=(ShowOnlyInnerProperties))
	FCurveTableRowHandle RowHandle;
};
