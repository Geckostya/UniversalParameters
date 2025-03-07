// 

#pragma once

#include "CoreMinimal.h"
#include "UP_ActorProvider.h"
#include "FloatProvider/UP_FloatProvider_Blackboard.h"
#include "UObject/Object.h"
#include "UP_ActorProvider_Blackboard.generated.h"

/**
 * ActorProvider that gets value from the blackboard key
 * Needs FUP_EvaluationContext_Blackboard Context
 */
UCLASS(DisplayName="Actor Blackboard")
class UNIVERSALPARAMETERS_API UUP_ActorProvider_Blackboard : public UUP_ActorProvider
{
	GENERATED_BODY()
public:
	
	UUP_ActorProvider_Blackboard(const FObjectInitializer& ObjectInitializer);

	virtual AActor* GetActor(const FUP_EvaluationContext* Context) override;

	UPROPERTY(EditAnywhere, Category=UniversalParameters)
	FBlackboardKeySelector BlackboardKey;
};
