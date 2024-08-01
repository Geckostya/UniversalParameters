#pragma once

#include "CoreMinimal.h"
#include "UP_BoolProvider.h"
#include "UP_BoolProvider_FloatCompare.generated.h"

UENUM(BlueprintType)
enum class EUP_CompareOperation : uint8
{
	Less,
	LessOrEqual,
	More,
	MoreOrEqual,
	Equal,
	NotEqual,
};

class UUP_FloatProvider;

/**
 * Compares two floats
 */
UCLASS(DisplayName="Float Compare")
class UNIVERSALPARAMETERS_API UUP_BoolProvider_FloatCompare : public UUP_BoolProvider
{
	GENERATED_BODY()

public:
	UUP_BoolProvider_FloatCompare(const FObjectInitializer& ObjectInitializer);
	
	virtual bool GetValue_Implementation() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, NoClear, Category="Bool Provider")
	UUP_FloatProvider* FirstParam;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Bool Function")
	EUP_CompareOperation Operation;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, NoClear, Category="Bool Provider")
	UUP_FloatProvider* SecondParam;
};
