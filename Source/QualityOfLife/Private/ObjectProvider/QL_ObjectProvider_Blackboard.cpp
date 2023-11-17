// 


#include "ObjectProvider/QL_ObjectProvider_Blackboard.h"

#include "QualityOfLife.h"
#include "BehaviorTree/BTFunctionLibrary.h"
#include "BehaviorTree/BTNode.h"

UQL_ObjectProvider_Blackboard::UQL_ObjectProvider_Blackboard(const FObjectInitializer& ObjectInitializer)
{
	BlackboardKey.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UQL_FloatProvider_Blackboard, BlackboardKey), UObject::StaticClass());
}

UObject* UQL_ObjectProvider_Blackboard::GetObject_Implementation()
{
	if (UBTNode* NodeOwner = Cast<UBTNode>(GetOuter()))
	{
		return UBTFunctionLibrary::GetBlackboardValueAsObject(NodeOwner, BlackboardKey);
	}
	UE_LOG(LogQoL, Error, TEXT("Called GetObject from QL_ObjectProvider_Blackboard which do not belong to BTNode. Owner is %s"), *GetNameSafe(GetOuter()))
	return nullptr;
}
