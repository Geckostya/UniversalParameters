#include "FloatProvider/UP_FloatProvider.h"

float UUP_FloatProvider::GetValue_BP()
{
    return GetValue(nullptr);
}

float UUP_FloatProvider::GetValue(const FUP_EvaluationContext* Context)
{
    return 0;
}