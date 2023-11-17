#pragma once

#include "CoreMinimal.h"
#include "QL_BoolProvider.h"
#include "QL_BoolProvider_FloatCompare.generated.h"

UENUM(BlueprintType)
enum class EQL_CompareOperation : uint8
{
	Less,
	LessOrEqual,
	More,
	MoreOrEqual,
	Equal,
	NotEqual,
};

class UQL_FloatProvider;

/**
 * Compares two floats
 */
UCLASS(DisplayName="Float Compare")
class QUALITYOFLIFE_API UQL_BoolProvider_FloatCompare : public UQL_BoolProvider
{
	GENERATED_BODY()

public:
	UQL_BoolProvider_FloatCompare(const FObjectInitializer& ObjectInitializer);
	
	virtual bool GetValue_Implementation() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, NoClear, Category="Bool Provider")
	UQL_FloatProvider* FirstParam;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Bool Function")
	EQL_CompareOperation Operation;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, NoClear, Category="Bool Provider")
	UQL_FloatProvider* SecondParam;
};
