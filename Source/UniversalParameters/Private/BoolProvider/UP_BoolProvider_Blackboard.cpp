// 


#include "BoolProvider/UP_BoolProvider_Blackboard.h"

#include "UniversalParameters.h"
#include "BehaviorTree/BTFunctionLibrary.h"
#include "BehaviorTree/BTTaskNode.h"

UUP_BoolProvider_Blackboard::UUP_BoolProvider_Blackboard(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	BlackboardKey.AddBoolFilter(this, GET_MEMBER_NAME_CHECKED(UUP_BoolProvider_Blackboard, BlackboardKey));
}

bool UUP_BoolProvider_Blackboard::GetValue_Implementation()
{
	if (UBTNode* NodeOwner = Cast<UBTNode>(GetOuter()))
	{
		return UBTFunctionLibrary::GetBlackboardValueAsBool(NodeOwner, BlackboardKey);
	}
	UE_LOG(LogUniversalParameters, Error, TEXT("Called GetValue from UP_BoolProvider_BlackBoard which do not belong to BTNode. Owner is %s"), *GetNameSafe(GetOuter()))
	return false;
}
