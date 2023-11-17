// 

#pragma once

#include "CoreMinimal.h"
#include "ObjectProvider/QL_ObjectProvider.h"
#include "UObject/Object.h"
#include "QL_ActorProvider.generated.h"

/**
 *  Blueprint instanceable wrapper around Actor
 */
UCLASS(Abstract)
class QUALITYOFLIFE_API UQL_ActorProvider : public UQL_ObjectProvider
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Actor Provider")
	AActor* GetActor();

	virtual UObject* GetObject_Implementation() override;

	static AActor* GetActorSafe(UQL_ActorProvider* Provider);
};