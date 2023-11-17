// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QL_FloatProvider.h"
#include "QL_FloatProvider_Select.generated.h"

class UQL_BoolProvider;

/**
 * 
 */
UCLASS(DisplayName="Select")
class QUALITYOFLIFE_API UQL_FloatProvider_Select : public UQL_FloatProvider
{
	GENERATED_BODY()
	
public:
	UQL_FloatProvider_Select(const FObjectInitializer& Initializer);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, NoClear, Category="Float Provider")
	UQL_BoolProvider* If;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, NoClear, Category="Float Provider")
	UQL_FloatProvider* Then;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, NoClear, Category="Float Provider")
	UQL_FloatProvider* Else;

	virtual float GetValue_Implementation() override;
};
