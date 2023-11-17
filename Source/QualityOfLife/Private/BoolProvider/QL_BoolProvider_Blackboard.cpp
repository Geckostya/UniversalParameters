// 


#include "BoolProvider/QL_BoolProvider_Blackboard.h"

#include "QualityOfLife.h"
#include "BehaviorTree/BTFunctionLibrary.h"
#include "BehaviorTree/BTTaskNode.h"

UQL_BoolProvider_Blackboard::UQL_BoolProvider_Blackboard(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	BlackboardKey.AddBoolFilter(this, GET_MEMBER_NAME_CHECKED(UQL_BoolProvider_Blackboard, BlackboardKey));
}

bool UQL_BoolProvider_Blackboard::GetValue_Implementation()
{
	if (UBTNode* NodeOwner = Cast<UBTNode>(GetOuter()))
	{
		return UBTFunctionLibrary::GetBlackboardValueAsBool(NodeOwner, BlackboardKey);
	}
	UE_LOG(LogQoL, Error, TEXT("Called GetValue from QL_BoolProvider_BlackBoard which do not belong to BTNode. Owner is %s"), *GetNameSafe(GetOuter()))
	return false;
}
