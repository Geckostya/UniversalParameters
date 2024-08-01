#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_Wait.h"
#include "BTTask_Wait_UniversalParameter.generated.h"

class UUP_FloatProvider;

/**
 * The same task as Unreal's Wait, but uses float providers
 */
UCLASS(hidecategories=Wait)
class UNIVERSALPARAMETERS_API UBTTask_Wait_UniversalParameter : public UBTTask_Wait
{
	GENERATED_BODY()

public:

	UBTTask_Wait_UniversalParameter(const FObjectInitializer& ObjectInitializer);
	
	virtual void InitializeFromAsset(UBehaviorTree& Asset) override;
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	virtual FString GetStaticDescription() const override;
	
	UPROPERTY(EditAnywhere, Category="Universal Parameters", NoClear)
	UUP_FloatProvider* WaitTimeProvider;

	UPROPERTY(EditAnywhere, Category="Universal Parameters")
	UUP_FloatProvider* DeviationProvider = nullptr;
};
