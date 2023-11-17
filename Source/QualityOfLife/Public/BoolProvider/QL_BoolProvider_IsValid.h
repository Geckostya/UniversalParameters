#pragma once

#include "CoreMinimal.h"
#include "QL_BoolProvider.h"
#include "QL_BoolProvider_IsValid.generated.h"

class UQL_ObjectProvider;

/**
 * Checks object valid
 */
UCLASS(DisplayName="Is Valid")
class QUALITYOFLIFE_API UQL_BoolProvider_IsValid : public UQL_BoolProvider
{
	GENERATED_BODY()

public:
	virtual bool GetValue_Implementation() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, NoClear, Category="Object Provider")
	UQL_ObjectProvider* ObjectProvider;
};
