// Fill out your copyright notice in the Description page of Project Settings.


#include "UP_Accessor.h"

#include "BehaviorTree/BTNode.h"

FUP_EvaluationContext_Blackboard::FUP_EvaluationContext_Blackboard(UBehaviorTreeComponent& BTComponent)
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
