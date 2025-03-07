// 

#pragma once

#include "CoreMinimal.h"
#include "UP_BoolProvider.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "UP_BoolProvider_Blackboard.generated.h"

/**
 * BoolProvider that gets value from the blackboard key
 * Needs FUP_EvaluationContext_Blackboard Context
 */
UCLASS(DisplayName="Blackboard")
class UNIVERSALPARAMETERS_API UUP_BoolProvider_Blackboard : public UUP_BoolProvider
{
	GENERATED_BODY()

public:
	UUP_BoolProvider_Blackboard(const FObjectInitializer& ObjectInitializer);
	
	virtual bool GetValue(const FUP_EvaluationContext* Context) override;

	UPROPERTY(EditAnywhere, Category=UniversalParameters)
	FBlackboardKeySelector BlackboardKey;
};
