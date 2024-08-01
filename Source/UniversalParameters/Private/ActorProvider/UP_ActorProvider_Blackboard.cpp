// 


#include "ActorProvider/UP_ActorProvider_Blackboard.h"

#include "UniversalParameters.h"
#include "BehaviorTree/BTFunctionLibrary.h"
#include "BehaviorTree/BTNode.h"

UUP_ActorProvider_Blackboard::UUP_ActorProvider_Blackboard(const FObjectInitializer& ObjectInitializer)
{
	BlackboardKey.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UUP_FloatProvider_Blackboard, BlackboardKey), AActor::StaticClass());
}

AActor* UUP_ActorProvider_Blackboard::GetActor_Implementation()
{
	if (UBTNode* NodeOwner = Cast<UBTNode>(GetOuter()))
	{
		return UBTFunctionLibrary::GetBlackboardValueAsActor(NodeOwner, BlackboardKey);
	}
	UE_LOG(LogUniversalParameters, Error, TEXT("Called GetActor from UP_ActorProvider_Blackboard which do not belong to BTNode. Owner is %s"), *GetNameSafe(GetOuter()))
	return nullptr;
}
