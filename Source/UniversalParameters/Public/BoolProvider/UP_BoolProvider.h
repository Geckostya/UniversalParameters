#pragma once

#include "CoreMinimal.h"
#include "UP_BoolProvider.generated.h"

/**
 *  Blueprint instanceable wrapper around bool
 */
UCLASS(Abstract, Blueprintable, BlueprintType, DefaultToInstanced, EditInlineNew, CollapseCategories)
class UNIVERSALPARAMETERS_API UUP_BoolProvider : public UObject
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Bool Provider")
    bool GetValue();

    virtual bool GetValue_Implementation();
	
	static bool GetValueSafe(UUP_BoolProvider* Provider);
};
