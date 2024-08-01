// 


#include "ObjectProvider/UP_ObjectProvider_Blackboard.h"

#include "UniversalParameters.h"
#include "BehaviorTree/BTFunctionLibrary.h"
#include "BehaviorTree/BTNode.h"

UUP_ObjectProvider_Blackboard::UUP_ObjectProvider_Blackboard(const FObjectInitializer& ObjectInitializer)
{
	BlackboardKey.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UUP_FloatProvider_Blackboard, BlackboardKey), UObject::StaticClass());
}

UObject* UUP_ObjectProvider_Blackboard::GetObject_Implementation()
{
	if (UBTNode* NodeOwner = Cast<UBTNode>(GetOuter()))
	{
		return UBTFunctionLibrary::GetBlackboardValueAsObject(NodeOwner, BlackboardKey);
	}
	UE_LOG(LogUniversalParameters, Error, TEXT("Called GetObject from UP_ObjectProvider_Blackboard which do not belong to BTNode. Owner is %s"), *GetNameSafe(GetOuter()))
	return nullptr;
}
