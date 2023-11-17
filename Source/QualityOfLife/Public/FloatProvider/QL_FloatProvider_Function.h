// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QL_FloatProvider.h"
#include "QL_FloatProvider_Function.generated.h"

class UQL_FloatFunction;
class UQL_BoolProvider;

/**
 * 
 */
UCLASS(DisplayName="Function")
class QUALITYOFLIFE_API UQL_FloatProvider_Function : public UQL_FloatProvider
{
	GENERATED_BODY()
	
public:
	UQL_FloatProvider_Function(const FObjectInitializer& Initializer);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, NoClear, Category="Float Provider")
	UQL_FloatFunction* Function;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, NoClear, Category="Float Provider")
	UQL_FloatProvider* Value;

	virtual float GetValue_Implementation() override;
};
