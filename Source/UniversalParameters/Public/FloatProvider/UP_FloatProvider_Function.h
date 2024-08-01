// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UP_FloatProvider.h"
#include "UP_FloatProvider_Function.generated.h"

class UUP_FloatFunction;
class UUP_BoolProvider;

/**
 * 
 */
UCLASS(DisplayName="Function")
class UNIVERSALPARAMETERS_API UUP_FloatProvider_Function : public UUP_FloatProvider
{
	GENERATED_BODY()
	
public:
	UUP_FloatProvider_Function(const FObjectInitializer& Initializer);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, NoClear, Category="Float Provider")
	UUP_FloatFunction* Function;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, NoClear, Category="Float Provider")
	UUP_FloatProvider* Value;

	virtual float GetValue_Implementation() override;
};
