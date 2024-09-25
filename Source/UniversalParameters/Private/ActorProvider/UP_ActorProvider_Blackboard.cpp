// 


#include "ActorProvider/UP_ActorProvider_Blackboard.h"

#include "BehaviorTree/BTFunctionLibrary.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"

UUP_ActorProvider_Blackboard::UUP_ActorProvider_Blackboard(const FObjectInitializer& ObjectInitializer)
{
	BlackboardKey.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UUP_ActorProvider_Blackboard, BlackboardKey), AActor::StaticClass());
}

AActor* UUP_ActorProvider_Blackboard::GetActor(const FUP_EvaluationContext* Context)
{
	return Cast<AActor>(GetFromBB<UBlackboardKeyType_Object>(BlackboardKey, Context));
}

void UUP_ActorProvider_Blackboard::GetBBKeys(TArray<FBlackboardKeySelector*>& Keys)
{
	Keys.Add(&BlackboardKey);
}

