// 

#pragma once

#include "CoreMinimal.h"
#include "UP_Accessor.h"
#include "UObject/Object.h"
#include "UP_ObjectProvider.generated.h"

/**
 *  Blueprint instanceable wrapper around Object
 */
UCLASS(Abstract, Blueprintable, BlueprintType, DefaultToInstanced, EditInlineNew, CollapseCategories, Category=UniversalParameters)
class UNIVERSALPARAMETERS_API UUP_ObjectProvider : public UUP_Accessor
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category=UniversalParameters, DisplayName=GetObject)
	UObject* GetObject_BP();
	
	UFUNCTION(BlueprintCallable, Category=UniversalParameters, DisplayName=GetObjectWithContext)
	UObject* GetObjectWithContext_BP(const UObject* ContextObject);

	virtual UObject* GetObject(const FUP_EvaluationContext* Context);

	FORCEINLINE static UObject* GetObjectSafe(UUP_ObjectProvider* Provider, const FUP_EvaluationContext* Context)
	{
		return Provider ? Provider->GetObject(Context) : nullptr;
	}
};
