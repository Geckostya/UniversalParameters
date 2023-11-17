#include "FloatProvider/QL_FloatProvider_Select.h"

#include "BoolProvider/QL_BoolProvider.h"
#include "BoolProvider/QL_BoolProvider_Constant.h"
#include "FloatProvider/QL_FloatProvier_Constant.h"

UQL_FloatProvider_Select::UQL_FloatProvider_Select(const FObjectInitializer& Initializer)
{
	If = Initializer.CreateDefaultSubobject<UQL_BoolProvider_Constant>(this, "If");
	Then = Initializer.CreateDefaultSubobject<UQL_FloatProvier_Constant>(this, "Then");
	Else = Initializer.CreateDefaultSubobject<UQL_FloatProvier_Constant>(this, "Else");
}

float UQL_FloatProvider_Select::GetValue_Implementation()
{
	return UQL_BoolProvider::GetValueSafe(If) ? GetValueSafe(Then) : GetValueSafe(Else);
}
