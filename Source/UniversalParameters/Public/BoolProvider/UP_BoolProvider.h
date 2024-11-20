#pragma once

#include "CoreMinimal.h"
#include "UP_Accessor.h"
#include "UP_BoolProvider.generated.h"

/**
 *  Blueprint instanceable wrapper around bool
 */
UCLASS(Abstract, Blueprintable, BlueprintType, DefaultToInstanced, EditInlineNew, CollapseCategories, Category=UniversalParameters)
class UNIVERSALPARAMETERS_API UUP_BoolProvider : public UUP_Accessor
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable, Category=UniversalParameters)
    bool GetValue_BP();
	
	UFUNCTION(BlueprintCallable, Category=UniversalParameters, DisplayName=GetValueWithContext)
	bool GetValueWithContext_BP(const UObject* ContextObject);

	virtual bool GetValue(const FUP_EvaluationContext* Context);
	
	FORCEINLINE static bool GetValueSafe(UUP_BoolProvider* Provider, const FUP_EvaluationContext* Context)
	{
		return Provider ? Provider->GetValue(Context) : false; 
	}
};
