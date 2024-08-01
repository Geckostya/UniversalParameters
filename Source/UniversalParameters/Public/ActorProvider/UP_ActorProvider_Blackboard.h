// 

#pragma once

#include "CoreMinimal.h"
#include "UP_ActorProvider.h"
#include "FloatProvider/UP_FloatProvider_Blackboard.h"
#include "UObject/Object.h"
#include "UP_ActorProvider_Blackboard.generated.h"

/**
 * ActorProvider that gets value from the blackboard key
 * It works only inside instanced BTNodes!
 */
UCLASS(DisplayName="Actor Blackboard")
class UNIVERSALPARAMETERS_API UUP_ActorProvider_Blackboard : public UUP_ActorProvider
{
	GENERATED_BODY()
public:
	
	UUP_ActorProvider_Blackboard(const FObjectInitializer& ObjectInitializer);

	virtual AActor* GetActor_Implementation() override;

	UPROPERTY(EditAnywhere, Category="Actor Provider")
	FBlackboardKeySelector BlackboardKey;
};
