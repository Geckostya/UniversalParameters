#include "BoolProvider/UP_BoolProvider_IsValid.h"

#include "ObjectProvider/UP_ObjectProvider.h"


bool UUP_BoolProvider_IsValid::GetValue(const FUP_EvaluationContext* Context)
{
	return IsValid(UUP_ObjectProvider::GetObjectSafe(ObjectProvider, Context));
}

FString UUP_BoolProvider_IsValid::GetPreviewName_Implementation() const
{
	return FString::Printf(TEXT("IsValid(%s)"), *GetPreviewNameSafe(ObjectProvider));
}
