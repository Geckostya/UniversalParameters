// 

#pragma once

#include "CoreMinimal.h"
#include "UP_FloatProvider.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "UP_FloatProvider_Blackboard.generated.h"

/**
 * FloatProvider that gets value from the blackboard key
 * It works only inside instanced BTNodes! Otherwise, it should be called with UUP_FloatProvider::GetValueBTSafe
 */
UCLASS(DisplayName="Blackboard")
class UNIVERSALPARAMETERS_API UUP_FloatProvider_Blackboard : public UUP_FloatProvider
{
	GENERATED_BODY()

public:

	UUP_FloatProvider_Blackboard(const FObjectInitializer& ObjectInitializer);

	virtual float GetValue(const FUP_EvaluationContext* Context) override;
	
	UPROPERTY(EditAnywhere, Category=UniversalParameters)
	FBlackboardKeySelector BlackboardKey;

protected:
	virtual void GetBBKeys(TArray<FBlackboardKeySelector*>& Keys) override;
};
