#pragma once

#include "CoreMinimal.h"
#include "UP_BoolProvider.h"
#include "UP_BoolProvider_IsValid.generated.h"

class UUP_ObjectProvider;

/**
 * Checks object valid
 */
UCLASS(DisplayName="Is Valid")
class UNIVERSALPARAMETERS_API UUP_BoolProvider_IsValid : public UUP_BoolProvider
{
	GENERATED_BODY()

public:
	virtual bool GetValue_Implementation() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, NoClear, Category="Object Provider")
	UUP_ObjectProvider* ObjectProvider;
};