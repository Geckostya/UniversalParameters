#include "BoolProvider/UP_BoolProvider.h"

bool UUP_BoolProvider::GetValue_BP()
{
    return GetValue(nullptr);
}

bool UUP_BoolProvider::GetValueWithContext_BP(const UObject* ContextObject)
{
    const auto Context = TryGetContextFromObject(ContextObject);
    return GetValue(Context.Get());
}

bool UUP_BoolProvider::GetValue(const FUP_EvaluationContext* Context)
{
    return false;
}
