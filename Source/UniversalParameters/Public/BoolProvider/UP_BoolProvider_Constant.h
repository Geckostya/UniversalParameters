#pragma once

#include "CoreMinimal.h"
#include "UP_BoolProvider.h"
#include "UP_BoolProvider_Constant.generated.h"

/**
 * Simple BoolProvider that only holds one value.
 */
UCLASS(DisplayName="Constant")
class UNIVERSALPARAMETERS_API UUP_BoolProvider_Constant : public UUP_BoolProvider
{
	GENERATED_BODY()

public:
	virtual bool GetValue_Implementation() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Bool Provider")
	bool bValue = false;
};
