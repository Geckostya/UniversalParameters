#pragma once

#include "CoreMinimal.h"
#include "QL_BoolProvider.h"
#include "QL_BoolProvider_Constant.generated.h"

/**
 * Simple BoolProvider that only holds one value.
 */
UCLASS(DisplayName="Constant")
class QUALITYOFLIFE_API UQL_BoolProvider_Constant : public UQL_BoolProvider
{
	GENERATED_BODY()

public:
	virtual bool GetValue_Implementation() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Bool Provider")
	bool bValue = false;
};
