#pragma once

#include "CoreMinimal.h"
#include "UP_FloatProvider.h"
#include "UP_FloatProvider_Counter.generated.h"

/**
 * FloatProvider that changes value by some delta every time GetValue is called
 */
UCLASS(DisplayName="Counter")
class UNIVERSALPARAMETERS_API UUP_FloatProvider_Counter : public UUP_FloatProvider
{
	GENERATED_BODY()
	
public:
	virtual float GetValue(const FUP_EvaluationContext* Context) override;

	virtual FString GetPreviewName_Implementation() const override;
	
	// Base value to count from
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=UniversalParameters)
	float BaseValue = 0.0f;

	// Delta value which will be added to the BaseValue every call
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=UniversalParameters)
	float Delta = 1.0f;
};
