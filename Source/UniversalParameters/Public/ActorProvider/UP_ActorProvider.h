// 

#pragma once

#include "CoreMinimal.h"
#include "ObjectProvider/UP_ObjectProvider.h"
#include "UObject/Object.h"
#include "UP_ActorProvider.generated.h"

/**
 *  Blueprint instanceable wrapper around Actor
 */
UCLASS(Abstract, Blueprintable, BlueprintType, DefaultToInstanced, EditInlineNew, CollapseCategories, Category=UniversalParameters)
class UNIVERSALPARAMETERS_API UUP_ActorProvider : public UUP_ObjectProvider
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category=UniversalParameters, DisplayName=GetActor)
	AActor* GetActor_BP();
	
	UFUNCTION(BlueprintCallable, Category=UniversalParameters, DisplayName=GetActorWithContext)
	AActor* GetActorWithContext_BP(const UObject* ContextObject);

	virtual AActor* GetActor(const FUP_EvaluationContext* Context);

	virtual UObject* GetObject(const FUP_EvaluationContext* Context) override;
	
	FORCEINLINE static AActor* GetActorSafe(UUP_ActorProvider* Provider, const FUP_EvaluationContext* Context)
	{
		return Provider ? Provider->GetActor(Context) : nullptr;
	}
};