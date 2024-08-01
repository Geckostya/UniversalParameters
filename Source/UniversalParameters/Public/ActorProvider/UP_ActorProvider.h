// 

#pragma once

#include "CoreMinimal.h"
#include "ObjectProvider/UP_ObjectProvider.h"
#include "UObject/Object.h"
#include "UP_ActorProvider.generated.h"

/**
 *  Blueprint instanceable wrapper around Actor
 */
UCLASS(Abstract)
class UNIVERSALPARAMETERS_API UUP_ActorProvider : public UUP_ObjectProvider
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Actor Provider")
	AActor* GetActor();

	virtual UObject* GetObject_Implementation() override;

	static AActor* GetActorSafe(UUP_ActorProvider* Provider);
};