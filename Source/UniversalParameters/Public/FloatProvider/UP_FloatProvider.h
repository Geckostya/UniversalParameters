#pragma once

#include "CoreMinimal.h"
#include "UP_FloatProvider.generated.h"

/**
 *  Blueprint instanceable wrapper around float
 */
UCLASS(Abstract, Blueprintable, BlueprintType, DefaultToInstanced, EditInlineNew, CollapseCategories)
class UNIVERSALPARAMETERS_API UUP_FloatProvider : public UObject
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Float Provider")
    float GetValue();

    virtual float GetValue_Implementation();

	FORCEINLINE static float GetValueSafe(UUP_FloatProvider* Provider)
	{
		return Provider ? Provider->GetValue() : 0;
	}
};
