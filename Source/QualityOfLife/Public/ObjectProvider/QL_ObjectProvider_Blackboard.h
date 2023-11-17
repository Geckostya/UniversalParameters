// 

#pragma once

#include "CoreMinimal.h"
#include "QL_ObjectProvider.h"
#include "FloatProvider/QL_FloatProvider_Blackboard.h"
#include "UObject/Object.h"
#include "QL_ObjectProvider_Blackboard.generated.h"

/**
 * ObjectProvider that gets value from the blackboard key
 * It works only inside instanced BTNodes!
 */
UCLASS(DisplayName="Object Blackboard")
class QUALITYOFLIFE_API UQL_ObjectProvider_Blackboard : public UQL_ObjectProvider
{
	GENERATED_BODY()
public:
	
	UQL_ObjectProvider_Blackboard(const FObjectInitializer& ObjectInitializer);

	virtual UObject* GetObject_Implementation() override;

	UPROPERTY(EditAnywhere, Category="Object Provider")
	FBlackboardKeySelector BlackboardKey;
};
