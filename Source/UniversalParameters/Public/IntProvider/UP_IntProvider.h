// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UP_Accessor.h"
#include "UP_IntProvider.generated.h"

/**
 *  Blueprint instanceable wrapper around int
 */
UCLASS(Abstract, Blueprintable, BlueprintType, DefaultToInstanced, EditInlineNew, CollapseCategories, Category=UniversalParameters)
class UNIVERSALPARAMETERS_API UUP_IntProvider : public UUP_Accessor
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category=UniversalParameters, DisplayName=GetValue)
	int32 GetValue_BP();
	
	UFUNCTION(BlueprintCallable, Category=UniversalParameters, DisplayName=GetValueWithContext)
	int32 GetValueWithContext_BP(const UObject* ContextObject);

	virtual int32 GetValue(const FUP_EvaluationContext* Context);

	FORCEINLINE static int32 GetValueSafe(UUP_IntProvider* Provider, const FUP_EvaluationContext* Context)
	{
		return Provider ? Provider->GetValue(Context) : 0;
	}
};
