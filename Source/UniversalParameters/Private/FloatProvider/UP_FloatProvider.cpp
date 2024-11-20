#include "FloatProvider/UP_FloatProvider.h"

float UUP_FloatProvider::GetValue_BP()
{
    return GetValue(nullptr);
}

float UUP_FloatProvider::GetValue(const FUP_EvaluationContext* Context)
{
    return 0;
}

float UUP_FloatProvider::GetValueWithContext_BP(const UObject* ContextObject)
{
    const auto Context = TryGetContextFromObject(ContextObject);
    return GetValue(Context.Get());
}
