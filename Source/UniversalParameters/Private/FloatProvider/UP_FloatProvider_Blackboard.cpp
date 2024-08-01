// 


#include "FloatProvider/UP_FloatProvider_Blackboard.h"

#include "UniversalParameters.h"
#include "BehaviorTree/BTFunctionLibrary.h"
#include "BehaviorTree/BTTaskNode.h"

UUP_FloatProvider_Blackboard::UUP_FloatProvider_Blackboard(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	BlackboardKey.AddFloatFilter(this, GET_MEMBER_NAME_CHECKED(UUP_FloatProvider_Blackboard, BlackboardKey));
}

float UUP_FloatProvider_Blackboard::GetValue_Implementation()
{
	if (UBTNode* NodeOwner = Cast<UBTNode>(GetOuter()))
	{
		check(NodeOwner->IsInstanced());
		return UBTFunctionLibrary::GetBlackboardValueAsFloat(NodeOwner, BlackboardKey);
	}
	UE_LOG(LogUniversalParameters, Error, TEXT("Called GetValue from UP_FloatProvider_BlackBoard which do not belong to BTNode. Owner is %s"), *GetNameSafe(GetOuter()))
	return 0.0f;
}

void UUP_FloatProvider_Blackboard::ResolveSelectedKey(UBTNode* BehaviorNode)
{
	UBlackboardData* BBAsset = BehaviorNode->GetBlackboardAsset();
	if (ensure(BBAsset))
	{
		BlackboardKey.ResolveSelectedKey(*BBAsset);
	}
}