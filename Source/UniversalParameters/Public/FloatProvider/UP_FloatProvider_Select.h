// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UP_FloatProvider.h"
#include "UP_FloatProvider_Select.generated.h"

class UUP_BoolProvider;

/**
 * 
 */
UCLASS(DisplayName="Select")
class UNIVERSALPARAMETERS_API UUP_FloatProvider_Select : public UUP_FloatProvider
{
	GENERATED_BODY()
	
public:
	UUP_FloatProvider_Select(const FObjectInitializer& Initializer);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, NoClear, Category="Float Provider")
	UUP_BoolProvider* If;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, NoClear, Category="Float Provider")
	UUP_FloatProvider* Then;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, NoClear, Category="Float Provider")
	UUP_FloatProvider* Else;

	virtual float GetValue_Implementation() override;
};