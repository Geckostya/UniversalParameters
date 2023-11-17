#include "FloatProvider/QL_FloatProvider.h"

float UQL_FloatProvider::GetValue_Implementation() 
{
    return 0.0f;
}

float UQL_FloatProvider::GetValueSafe(UQL_FloatProvider* Provider)
{
    return Provider ? Provider->GetValue() : 0;
}
