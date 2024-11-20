#pragma once

#include "CoreMinimal.h"
#include "UP_Accessor.h"
#include "UP_FloatFunction.generated.h"

/**
 * Blueprints instanceable wrapper around float to float function 
 */
UCLASS(Abstract, Blueprintable, BlueprintType, DefaultToInstanced, EditInlineNew, CollapseCategories, Category=UniversalParameters)
class UNIVERSALPARAMETERS_API UUP_FloatFunction : public UUP_Accessor
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable, Category=UniversalParameters, DisplayName=Eval)
	float Eval_BP(float Value);
	
	UFUNCTION(BlueprintCallable, Category=UniversalParameters, DisplayName=EvalWithContext)
	float EvalWithContext_BP(float Value, const UObject* ContextObject);
	
	virtual float Eval(float Value, const FUP_EvaluationContext* Context);
	
	FORCEINLINE static float EvalSafe(UUP_FloatFunction* Function, float Value, const FUP_EvaluationContext* Context) 
	{
		return Function ? Function->Eval(Value, Context) : 0;
	}
};
