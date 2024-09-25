#include "BoolProvider/UP_BoolProvider.h"

bool UUP_BoolProvider::GetValue_BP()
{
    return GetValue(nullptr);
}

bool UUP_BoolProvider::GetValue(const FUP_EvaluationContext* Context)
{
    return false;
}
