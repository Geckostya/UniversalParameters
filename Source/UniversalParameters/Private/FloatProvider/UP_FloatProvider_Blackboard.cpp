// 


#include "FloatProvider/UP_FloatProvider_Blackboard.h"

#include "BehaviorTree/Blackboard/BlackboardKeyType_Float.h"

UUP_FloatProvider_Blackboard::UUP_FloatProvider_Blackboard(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	BlackboardKey.AddFloatFilter(this, GET_MEMBER_NAME_CHECKED(UUP_FloatProvider_Blackboard, BlackboardKey));
}

float UUP_FloatProvider_Blackboard::GetValue(const FUP_EvaluationContext* Context)
{
	return GetFromBB<UBlackboardKeyType_Float>(BlackboardKey, Context);
}

FString UUP_FloatProvider_Blackboard::GetPreviewName_Implementation() const
{
	return FString::Printf(TEXT("BBKey:%s"), *BlackboardKey.SelectedKeyName.ToString());
}

