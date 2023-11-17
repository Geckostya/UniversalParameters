#pragma once

#include "CoreMinimal.h"
#include "QL_BoolProvider.generated.h"

/**
 *  Blueprint instanceable wrapper around bool
 */
UCLASS(Abstract, Blueprintable, BlueprintType, DefaultToInstanced, EditInlineNew, CollapseCategories)
class QUALITYOFLIFE_API UQL_BoolProvider : public UObject
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Bool Provider")
    bool GetValue();

    virtual bool GetValue_Implementation();
	
	static bool GetValueSafe(UQL_BoolProvider* Provider);
};
