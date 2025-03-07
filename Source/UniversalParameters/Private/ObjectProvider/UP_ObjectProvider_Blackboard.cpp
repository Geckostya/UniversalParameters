// 


#include "ObjectProvider/UP_ObjectProvider_Blackboard.h"

#include "BehaviorTree/BTFunctionLibrary.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"

UUP_ObjectProvider_Blackboard::UUP_ObjectProvider_Blackboard(const FObjectInitializer& ObjectInitializer)
{
	BlackboardKey.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UUP_FloatProvider_Blackboard, BlackboardKey), UObject::StaticClass());
}

UObject* UUP_ObjectProvider_Blackboard::GetObject(const FUP_EvaluationContext* Context)
{
	return GetFromBB<UBlackboardKeyType_Object>(BlackboardKey, Context);
}

FString UUP_ObjectProvider_Blackboard::GetPreviewName_Implementation() const
{
	return FString::Printf(TEXT("BBKey:%s"), *BlackboardKey.SelectedKeyName.ToString());
}
