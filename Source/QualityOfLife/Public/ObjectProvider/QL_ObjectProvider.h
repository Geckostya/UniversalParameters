// 

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "QL_ObjectProvider.generated.h"

/**
 *  Blueprint instanceable wrapper around Object
 */
UCLASS(Abstract, Blueprintable, BlueprintType, DefaultToInstanced, EditInlineNew, CollapseCategories)
class QUALITYOFLIFE_API UQL_ObjectProvider : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Object Provider")
	UObject* GetObject();

	static UObject* GetObjectSafe(UQL_ObjectProvider* Provider);
};
