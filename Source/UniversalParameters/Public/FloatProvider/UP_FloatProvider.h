#pragma once

#include "CoreMinimal.h"
#include "UP_Accessor.h"
#include "UP_FloatProvider.generated.h"

/**
 *  Blueprint instanceable wrapper around float
 */
UCLASS(Abstract, Blueprintable, BlueprintType, DefaultToInstanced, EditInlineNew, CollapseCategories, Category=UniversalParameters)
class UNIVERSALPARAMETERS_API UUP_FloatProvider : public UUP_Accessor
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable, Category=UniversalParameters, DisplayName=GetValue)
    float GetValue_BP();
	
    UFUNCTION(BlueprintCallable, Category=UniversalParameters, DisplayName=GetValueWithContext)
    float GetValueWithContext_BP(const UObject* ContextObject);

	virtual float GetValue(const FUP_EvaluationContext* Context);

	FORCEINLINE static float GetValueSafe(UUP_FloatProvider* Provider, const FUP_EvaluationContext* Context)
	{
		return Provider ? Provider->GetValue(Context) : 0;
	}
};
