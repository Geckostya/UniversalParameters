#include "BoolProvider/UP_BoolProvider_IsValid.h"

#include "ObjectProvider/UP_ObjectProvider.h"


bool UUP_BoolProvider_IsValid::GetValue(const FUP_EvaluationContext* Context)
{
	return IsValid(UUP_ObjectProvider::GetObjectSafe(ObjectProvider, Context));
}

void UUP_BoolProvider_IsValid::GetBBKeys(TArray<FBlackboardKeySelector*>& Keys)
{
	GetBBKeysSafe(ObjectProvider, Keys);
}
