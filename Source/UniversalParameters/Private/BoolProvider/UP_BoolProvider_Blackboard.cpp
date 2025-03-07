// 


#include "BoolProvider/UP_BoolProvider_Blackboard.h"

#include "BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"

UUP_BoolProvider_Blackboard::UUP_BoolProvider_Blackboard(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	BlackboardKey.AddBoolFilter(this, GET_MEMBER_NAME_CHECKED(UUP_BoolProvider_Blackboard, BlackboardKey));
}

bool UUP_BoolProvider_Blackboard::GetValue(const FUP_EvaluationContext* Context)
{
	return GetFromBB<UBlackboardKeyType_Bool>(BlackboardKey, Context);
}
