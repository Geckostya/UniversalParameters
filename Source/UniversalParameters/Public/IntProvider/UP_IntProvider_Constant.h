// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UP_IntProvider.h"
#include "UP_IntProvider_Constant.generated.h"

/**
 * 
 */
UCLASS(DisplayName="Constant")
class UNIVERSALPARAMETERS_API UUP_IntProvider_Constant : public UUP_IntProvider
{
	GENERATED_BODY()

public:
	virtual int32 GetValue(const FUP_EvaluationContext* Context) override;

	virtual FString GetPreviewName_Implementation() const override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=UniversalParameters)
	int32 Value = 0;
};
