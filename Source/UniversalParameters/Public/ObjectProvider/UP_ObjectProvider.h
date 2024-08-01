// 

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UP_ObjectProvider.generated.h"

/**
 *  Blueprint instanceable wrapper around Object
 */
UCLASS(Abstract, Blueprintable, BlueprintType, DefaultToInstanced, EditInlineNew, CollapseCategories)
class UNIVERSALPARAMETERS_API UUP_ObjectProvider : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Object Provider")
	UObject* GetObject();

	static UObject* GetObjectSafe(UUP_ObjectProvider* Provider);
};
