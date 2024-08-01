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

float UUP_FloatProvider_Select::GetValue_Implementation()
{
	return UUP_BoolProvider::GetValueSafe(If) ? GetValueSafe(Then) : GetValueSafe(Else);
}
