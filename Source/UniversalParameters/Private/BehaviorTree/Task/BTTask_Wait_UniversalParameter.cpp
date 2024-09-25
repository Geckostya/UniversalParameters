#include "BehaviorTree/Task/BTTask_Wait_UniversalParameter.h"

#include "UP_Accessor.h"
#include "FloatProvider/UP_FloatProvider.h"
#include "FloatProvider/UP_FloatProvider_Constant.h"

UBTTask_Wait_UniversalParameter::UBTTask_Wait_UniversalParameter(const FObjectInitializer& ObjectInitializer)
{
	NodeName = "Wait (UP)";
	WaitTimeProvider = NewObject<UUP_FloatProvider_Constant>(this, "WaitTime");
}

void UBTTask_Wait_UniversalParameter::InitializeFromAsset(UBehaviorTree& Asset)
{
	Super::InitializeFromAsset(Asset);
	UUP_Accessor::InitializeWithBTSafe(WaitTimeProvider, this);
	UUP_Accessor::InitializeWithBTSafe(DeviationProvider, this);
}

EBTNodeResult::Type UBTTask_Wait_UniversalParameter::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	FUP_EvaluationContext_Blackboard BlackboardContext(OwnerComp);
	WaitTime = UUP_FloatProvider::GetValueSafe(WaitTimeProvider, &BlackboardContext);
	RandomDeviation = UUP_FloatProvider::GetValueSafe(DeviationProvider, &BlackboardContext);
	
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}

FString UBTTask_Wait_UniversalParameter::GetStaticDescription() const
{
#if WITH_EDITORONLY_DATA
	FString WaitProviderName = WaitTimeProvider->GetClass()->GetDisplayNameText().ToString();
	if (DeviationProvider != nullptr)
	{
		FString DeviationProviderName = DeviationProvider->GetClass()->GetDisplayNameText().ToString();
		return FString::Printf(TEXT("%s: %s +-%s"), *UBTNode::GetStaticDescription(), *WaitProviderName, *DeviationProviderName);
	}
	return FString::Printf(TEXT("%s: %s"), *UBTNode::GetStaticDescription(), *WaitProviderName);
#else
	return Super::GetStaticDescription();
#endif
}
