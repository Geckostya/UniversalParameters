#include "FloatProvider/UP_FloatProvider_Select.h"

#include "BoolProvider/UP_BoolProvider.h"
#include "BoolProvider/UP_BoolProvider_Constant.h"
#include "FloatProvider/UP_FloatProvider_Constant.h"

UUP_FloatProvider_Select::UUP_FloatProvider_Select(const FObjectInitializer& Initializer)
{
	If = Initializer.CreateDefaultSubobject<UUP_BoolProvider_Constant>(this, "If");
	Then = Initializer.CreateDefaultSubobject<UUP_FloatProvider_Constant>(this, "Then");
	Else = Initializer.CreateDefaultSubobject<UUP_FloatProvider_Constant>(this, "Else");
}

float UUP_FloatProvider_Select::GetValue(const FUP_EvaluationContext* Context)
{
	return UUP_BoolProvider::GetValueSafe(If, Context) ? GetValueSafe(Then, Context) : GetValueSafe(Else, Context);
}

void UUP_FloatProvider_Select::GetBBKeys(TArray<FBlackboardKeySelector*>& Keys)
{
	GetBBKeysSafe(If, Keys);
	GetBBKeysSafe(Then, Keys);
	GetBBKeysSafe(Else, Keys);
}
