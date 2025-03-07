// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UP_IntProvider.h"
#include "UP_IntProvider_RandomRange.generated.h"

/**
 * 
 */
UCLASS(DisplayName="Random Range")
class UNIVERSALPARAMETERS_API UUP_IntProvider_RandomRange : public UUP_IntProvider
{
	GENERATED_BODY()
public:
	UUP_IntProvider_RandomRange(const FObjectInitializer& Initializer);

	virtual int32 GetValue(const FUP_EvaluationContext* Context) override;

	virtual FString GetPreviewName_Implementation() const override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, NoClear, Category=UniversalParameters)
	UUP_IntProvider* From;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, NoClear, Category=UniversalParameters)
	UUP_IntProvider* To;
};
