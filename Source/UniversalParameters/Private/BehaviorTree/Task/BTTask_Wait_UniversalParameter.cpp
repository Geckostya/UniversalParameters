#include "BehaviorTree/Task/BTTask_Wait_UniversalParameter.h"

#include "FloatProvider/UP_FloatProvider.h"
#include "FloatProvider/UP_FloatProvider_Blackboard.h"
#include "FloatProvider/UP_FloatProvider_Constant.h"

UBTTask_Wait_UniversalParameter::UBTTask_Wait_UniversalParameter(const FObjectInitializer& ObjectInitializer)
{
	NodeName = "Wait (UP)";
	WaitTimeProvider = ObjectInitializer.CreateDefaultSubobject<UUP_FloatProvider_Constant>(this, "WaitTime");
}

void UBTTask_Wait_UniversalParameter::InitializeFromAsset(UBehaviorTree& Asset)
{
	Super::InitializeFromAsset(Asset);
	UUP_FloatProvider_Blackboard::ResolveSelectedKeySafe(WaitTimeProvider, this);
	UUP_FloatProvider_Blackboard::ResolveSelectedKeySafe(DeviationProvider, this);
}

EBTNodeResult::Type UBTTask_Wait_UniversalParameter::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	WaitTime = UUP_FloatProvider_Blackboard::GetValueSafe(OwnerComp, WaitTimeProvider);
	RandomDeviation = UUP_FloatProvider_Blackboard::GetValueSafe(OwnerComp, DeviationProvider);
	
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}

FString UBTTask_Wait_UniversalParameter::GetStaticDescription() const
{
	FString WaitProviderName = WaitTimeProvider->GetClass()->GetDisplayNameText().ToString();
	if (DeviationProvider != nullptr)
	{
		FString DeviationProviderName = DeviationProvider->GetClass()->GetDisplayNameText().ToString();
		return FString::Printf(TEXT("%s: %s +-%s"), *UBTNode::GetStaticDescription(), *WaitProviderName, *DeviationProviderName);
	}
	return FString::Printf(TEXT("%s: %s"), *UBTNode::GetStaticDescription(), *WaitProviderName);
}
