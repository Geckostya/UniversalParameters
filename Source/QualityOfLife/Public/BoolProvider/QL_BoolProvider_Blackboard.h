// 

#pragma once

#include "CoreMinimal.h"
#include "QL_BoolProvider.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "QL_BoolProvider_Blackboard.generated.h"

/**
 * BoolProvider that gets value from the blackboard key
 * It works only inside instanced BTNodes!
 */
UCLASS(DisplayName="Blackboard")
class QUALITYOFLIFE_API UQL_BoolProvider_Blackboard : public UQL_BoolProvider
{
	GENERATED_BODY()

public:

	UQL_BoolProvider_Blackboard(const FObjectInitializer& ObjectInitializer);
	
	virtual bool GetValue_Implementation() override;
	
	UPROPERTY(EditAnywhere, Category="Bool Provider")
	FBlackboardKeySelector BlackboardKey;
};
