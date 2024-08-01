#include "BoolProvider/UP_BoolProvider.h"

bool UUP_BoolProvider::GetValue_Implementation() 
{
    return false;
}

bool UUP_BoolProvider::GetValueSafe(UUP_BoolProvider* Provider)
{
    return Provider ? Provider->GetValue() : false; 
}
