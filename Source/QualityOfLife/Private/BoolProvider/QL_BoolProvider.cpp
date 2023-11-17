#include "BoolProvider/QL_BoolProvider.h"

bool UQL_BoolProvider::GetValue_Implementation() 
{
    return false;
}

bool UQL_BoolProvider::GetValueSafe(UQL_BoolProvider* Provider)
{
    return Provider ? Provider->GetValue() : false; 
}
