// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BTNode.h"
#include "UObject/Object.h"
#include "UP_Accessor.generated.h"

USTRUCT()
struct FUP_EvaluationContext
{
	GENERATED_BODY()
};

USTRUCT()
struct FUP_EvaluationContext_Blackboard : public FUP_EvaluationContext
{
	GENERATED_BODY()

	FUP_EvaluationContext_Blackboard() = default;

	FUP_EvaluationContext_Blackboard(const UBehaviorTreeComponent& BTComponent);
	
	UPROPERTY()
	const UBlackboardComponent* Blackboard = nullptr;
};

/**
 * Base class for Providers, Functions and etc.
 */
UCLASS(Abstract)
class UNIVERSALPARAMETERS_API UUP_Accessor : public UObject
{
	GENERATED_BODY()

public:
	void InitializeWithBT(UBTNode* BehaviorNode);
	
	FORCEINLINE static void InitializeWithBTSafe(UUP_Accessor* Provider, UBTNode* BehaviorNode)
	{
		if (Provider != nullptr && BehaviorNode != nullptr)
		{
			Provider->InitializeWithBT(BehaviorNode);
		}
	}
	
protected:
	virtual void GetBBKeys(TArray<FBlackboardKeySelector*>& Keys);
	
	FORCEINLINE static void GetBBKeysSafe(UUP_Accessor* Provider, TArray<FBlackboardKeySelector*>& Keys)
	{
		if (Provider != nullptr)
		{
			Provider->GetBBKeys(Keys);
		}
	}

	template<typename TKeyType>
	FORCEINLINE static typename TKeyType::FDataType GetFromBB(const FBlackboardKeySelector& Key, const FUP_EvaluationContext* Context)
	{
		const FUP_EvaluationContext_Blackboard* BlackboardContext = static_cast<const FUP_EvaluationContext_Blackboard*>(Context);
		return BlackboardContext->Blackboard->GetValue<TKeyType>(Key.GetSelectedKeyID());
	}

	static TUniquePtr<FUP_EvaluationContext> TryGetContextFromObject(const UObject* Object);

private:
	FORCEINLINE static bool TryGetContextFromPawn(const class UObject* Object, FUP_EvaluationContext*& Context)
	{
		if (Object != nullptr && Object->IsA<APawn>())
		{
			const APawn* Pawn = Cast<APawn>(Object);
			return TryGetContextFromAIController(Pawn->GetController(), Context);
		}
		return false;
	}
	
	FORCEINLINE static bool TryGetContextFromAIController(const class UObject* Object, FUP_EvaluationContext*& Context)
	{
		if (Object != nullptr && Object->IsA<AAIController>())
		{
			const AAIController* Controller = Cast<AAIController>(Object);
			return TryGetContextFromBehaviorTreeComponent(Controller->GetBrainComponent(), Context);
		}
		return false;
	}

	FORCEINLINE static bool TryGetContextFromBehaviorTreeComponent(const class UObject* Object, FUP_EvaluationContext*& Context)
	{
		if (Object != nullptr && Object->IsA<UBehaviorTreeComponent>())
		{
			Context = new FUP_EvaluationContext_Blackboard(*Cast<UBehaviorTreeComponent>(Object));
			return true;
		}
		return false;
	}
};
