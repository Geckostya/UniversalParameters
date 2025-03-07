// 

#pragma once

#include "CoreMinimal.h"
#include "UP_ObjectProvider.h"
#include "FloatProvider/UP_FloatProvider_Blackboard.h"
#include "UObject/Object.h"
#include "UP_ObjectProvider_Blackboard.generated.h"

/**
 * ObjectProvider that gets value from the blackboard key
 * It works only inside instanced BTNodes!
 */
UCLASS(DisplayName="Object Blackboard")
class UNIVERSALPARAMETERS_API UUP_ObjectProvider_Blackboard : public UUP_ObjectProvider
{
	GENERATED_BODY()
public:
	
	UUP_ObjectProvider_Blackboard(const FObjectInitializer& ObjectInitializer);

	virtual UObject* GetObject(const FUP_EvaluationContext* Context) override;

	UPROPERTY(EditAnywhere, Category=UniversalParameters)
	FBlackboardKeySelector BlackboardKey;
};
