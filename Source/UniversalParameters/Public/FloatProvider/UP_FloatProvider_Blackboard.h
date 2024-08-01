// 

#pragma once

#include "CoreMinimal.h"
#include "UP_FloatProvider.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Float.h"
#include "UP_FloatProvider_Blackboard.generated.h"

/**
 * FloatProvider that gets value from the blackboard key
 * It works only inside instanced BTNodes! Otherwise it should be called with UUP_FloatProvider_Blackboard::GetValueSafe
 */
UCLASS(DisplayName="Blackboard")
class UNIVERSALPARAMETERS_API UUP_FloatProvider_Blackboard : public UUP_FloatProvider
{
	GENERATED_BODY()

public:

	UUP_FloatProvider_Blackboard(const FObjectInitializer& ObjectInitializer);
	
	virtual float GetValue_Implementation() override;
	
	void ResolveSelectedKey( UBTNode* BehaviorNode);
	
	FORCEINLINE static void ResolveSelectedKeySafe(UUP_FloatProvider* FloatProvider, UBTNode* BehaviorNode)
	{
		if (UUP_FloatProvider_Blackboard* BlackboardProvider = Cast<UUP_FloatProvider_Blackboard>(FloatProvider))
		{
			BlackboardProvider->ResolveSelectedKey(BehaviorNode);
		}
	}

	// Gets value for non-instanced BT nodes if it is a Blackboard float provider, and just the regular value otherwise
	FORCEINLINE static float GetValueSafe(UBehaviorTreeComponent& OwnerComp, UUP_FloatProvider* Provider)
	{
		if (UUP_FloatProvider_Blackboard* BlackboardProvider = Cast<UUP_FloatProvider_Blackboard>(Provider))
		{
			if (const UBlackboardComponent* MyBlackboard = OwnerComp.GetBlackboardComponent())
			{
				return MyBlackboard->GetValue<UBlackboardKeyType_Float>(BlackboardProvider->BlackboardKey.GetSelectedKeyID());
			}
		}
		return Provider ? Provider->GetValue() : 0;
	}

	UPROPERTY(EditAnywhere, Category="Float Provider")
	FBlackboardKeySelector BlackboardKey;
};
