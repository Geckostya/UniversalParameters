#pragma once

#include "CoreMinimal.h"
#include "UP_FloatProvider.h"
#include "UP_FloatProvider_Constant.generated.h"

/**
 * Simple FloatProvider that only holds one value.
 */
UCLASS(DisplayName="Constant")
class UNIVERSALPARAMETERS_API UUP_FloatProvider_Constant : public UUP_FloatProvider
{
	GENERATED_BODY()

public:
	virtual float GetValue_Implementation() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Float Provider")
	float Value = 0.0f;
};
