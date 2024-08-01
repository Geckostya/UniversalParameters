#pragma once

#include "CoreMinimal.h"
#include "UP_FloatFunction.generated.h"

/**
 * Blueprints instanceable wrapper around float to float function 
 */
UCLASS(Abstract, Blueprintable, BlueprintType, DefaultToInstanced, EditInlineNew, CollapseCategories)
class UNIVERSALPARAMETERS_API UUP_FloatFunction : public UObject
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Float Function")
    float Eval(float Value);

    virtual float Eval_Implementation(float Value);
	
	static float EvalSafe(UUP_FloatFunction* Function, float Value);
};
