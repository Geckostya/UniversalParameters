// 


#include "FloatProvider/UP_FloatProvider_Blackboard.h"

#include "BehaviorTree/BTFunctionLibrary.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Float.h"

UUP_FloatProvider_Blackboard::UUP_FloatProvider_Blackboard(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	BlackboardKey.AddFloatFilter(this, GET_MEMBER_NAME_CHECKED(UUP_FloatProvider_Blackboard, BlackboardKey));
}

float UUP_FloatProvider_Blackboard::GetValue(const FUP_EvaluationContext* Context)
{
	
	// [Rinzler] did that to make things work. is this correct? I hope so =)
	const FUP_EvaluationContext_Blackboard* BlackboardContext = static_cast<const FUP_EvaluationContext_Blackboard*>(Context);
	return BlackboardContext->Blackboard->GetValueAsFloat(BlackboardKey.SelectedKeyName);
	// ~ [Rinzler]
	// return GetFromBB<UBlackboardKeyType_Float>(BlackboardKey, Context);
}

void UUP_FloatProvider_Blackboard::GetBBKeys(TArray<FBlackboardKeySelector*>& Keys)
{
	Keys.Add(&BlackboardKey);
}
