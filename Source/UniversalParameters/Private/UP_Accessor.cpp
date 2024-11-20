// Fill out your copyright notice in the Description page of Project Settings.


#include "UP_Accessor.h"

#include "BehaviorTree/BTNode.h"

FUP_EvaluationContext_Blackboard::FUP_EvaluationContext_Blackboard(const UBehaviorTreeComponent& BTComponent)
{
	Blackboard = BTComponent.GetBlackboardComponent();
}

void UUP_Accessor::InitializeWithBT(UBTNode* BehaviorNode)
{
	if (UBlackboardData* BBAsset = BehaviorNode->GetBlackboardAsset())
	{
		TArray<FBlackboardKeySelector*> Keys;
		GetBBKeys(Keys);
		for (FBlackboardKeySelector* Key : Keys)
		{
			Key->ResolveSelectedKey(*BBAsset);            
		}
	}
}

void UUP_Accessor::GetBBKeys(TArray<FBlackboardKeySelector*>& Keys)
{
}

TUniquePtr<FUP_EvaluationContext> UUP_Accessor::TryGetContextFromObject(const UObject* Object)
{
	FUP_EvaluationContext* Context = nullptr;
		
	for (const UObject* ObjectHierarchy = Object; ObjectHierarchy != nullptr; ObjectHierarchy = ObjectHierarchy->GetOuter())
	{
		if (TryGetContextFromPawn(ObjectHierarchy, Context))
		{
			break;
		}
		if (TryGetContextFromAIController(ObjectHierarchy, Context))
		{
			break;
		}
		if (TryGetContextFromBehaviorTreeComponent(ObjectHierarchy, Context))
		{
			break;
		}
	}
	return TUniquePtr<FUP_EvaluationContext>(Context);
}
