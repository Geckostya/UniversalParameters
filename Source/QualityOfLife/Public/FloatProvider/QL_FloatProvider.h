#pragma once

#include "CoreMinimal.h"
#include "QL_FloatProvider.generated.h"

/**
 *  Blueprint instanceable wrapper around float
 */
UCLASS(Abstract, Blueprintable, BlueprintType, DefaultToInstanced, EditInlineNew, CollapseCategories)
class QUALITYOFLIFE_API UQL_FloatProvider : public UObject
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Float Provider")
    float GetValue();

    virtual float GetValue_Implementation();

	static float GetValueSafe(UQL_FloatProvider* Provider);
};
